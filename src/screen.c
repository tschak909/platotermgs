#include <Control.h>
#include <Dialog.h>
#include <Memory.h>
#include <quickdraw.h>
#include <qdaux.h>
#include <orca.h>
#include <types.h>
#include "src/protocol.h"
#include "src/font.h"
#include "src/fontuser.h"
#include "src/scale.h"
#include "src/fontbold.h"

unsigned char CharWide=8;
unsigned char CharHigh=16;
padPt TTYLoc;

int foregroundColor=white;
int backgroundColor=black;
padRGB background_rgb={0,0,0};
padRGB foreground_rgb={255,255,255};
unsigned char highestColorIndex;
padRGB palette[16];

Handle fontHandle;
Font* fontPtr;

Handle boldfontHandle;
Font* boldfontPtr;

Handle userfontHandle;
Font* userfontPtr;

extern padBool FastText; /* protocol.c */
extern Word mmID; /* main.c */
extern Handle dpHandle; /* main.c */

unsigned char* fontData;

/**
 * screen_init() - Set up the screen
 */
void screen_init(void)
{
  int i;
  startgraph(320);
  SetPenMode(0);
  SetPenSize(1,1);
  SetPenMode(0);
  QDAuxStartUp();

  // Initialize font handle and copy font into it.
  fontHandle=NewHandle(2575,mmID,0,NULL);
  PtrToHand((Pointer)font,fontHandle,2575);
  fontPtr=*(FontHndl)fontHandle;

  // Initialize the bold font handle.
  boldfontHandle=NewHandle(2746,mmID,0,NULL);
  PtrToHand((Pointer)boldfont,boldfontHandle,2746);
  boldfontPtr=*(FontHndl)boldfontHandle;
  
  // Initialize user font handle
  userfontHandle=NewHandle(2274,mmID,0,NULL);
  PtrToHand((Pointer)userfont,userfontHandle,2274);
  userfontPtr=*(FontHndl)userfontHandle;  
}

/**
 * screen_write_font(charnum,chardata)
 * Write font data from terminal to screen font
 * This is put here due to header collision in terminal.c
 *
 * Yes, I know these are absolute data offsets, but I 
 * don't expect the placeholder font data to change...
 */
void screen_font_write(unsigned char charnum,
		       unsigned char c0,
		       unsigned char c1,
		       unsigned char c2,
		       unsigned char c3,
		       unsigned char c4,
		       unsigned char c5)
{
  HLock(userfontHandle);

  fontData=*(userfontHandle);

  fontData[0x1b2+charnum+0x0000]=c0;
  fontData[0x1b2+charnum+0x0084]=c1;
  fontData[0x1b2+charnum+0x0108]=c2;
  fontData[0x1b2+charnum+0x018c]=c3;
  fontData[0x1b2+charnum+0x0210]=c4;
  fontData[0x1b2+charnum+0x0294]=c5;
  
  HUnlock(userfontHandle);
}

/**
 * screen_font_clear_glyph(charnum)
 * Clear a glyph from the M2/M3 font
 */
void screen_font_clear_glyph(unsigned char charnum)
{
  HLock(userfontHandle);

  fontData=*(userfontHandle);

  fontData[0x1b2+charnum+0x0000]=0x00;
  fontData[0x1b2+charnum+0x0084]=0x00;
  fontData[0x1b2+charnum+0x0108]=0x00;
  fontData[0x1b2+charnum+0x018c]=0x00;
  fontData[0x1b2+charnum+0x0210]=0x00;
  fontData[0x1b2+charnum+0x0294]=0x00;
  
  HUnlock(userfontHandle);
}

/**
 * Screen_wait(void) - Sleep for approx 16.67ms
 */
void screen_wait(void)
{
}

/**
 * screen_beep(void) - Beep the terminal
 */
void screen_beep(void)
{
}

/**
 * screen_remap_palette(void)
 * Remap the screen palette
 */
void screen_remap_palette(void)
{
  int i=0;
  for (i=0;i<16;++i)
    {
      int new_red=palette[i]._red>>4;     //
      int new_green=palette[i]._green>>4; // quantise to 4-bit
      int new_blue=palette[i]._blue>>4;   //
      int new_color=(new_blue)|(new_green<<4)|(new_red<<8);
      SetColorEntry(0,i,new_color);
    }
}

/**
 * Set foreground color
 */
void screen_foreground(padRGB* theColor)
{
  short index;
  foreground_rgb._red=theColor->_red;
  foreground_rgb._green=theColor->_green;
  foreground_rgb._blue=theColor->_blue;
  foregroundColor=screen_color_matching(theColor);
  SetSolidPenPat(foregroundColor);
  SetForeColor(foregroundColor);
  screen_remap_palette();
}

/**
 * Set background color
 */
void screen_background(padRGB* theColor)
{
  short index;
  background_rgb._red=theColor->_red;
  background_rgb._green=theColor->_green;
  background_rgb._blue=theColor->_blue;
  backgroundColor=screen_color_matching(theColor);
  SetSolidBackPat(backgroundColor);
  SetBackColor(backgroundColor);
  screen_remap_palette();
}

/**
 * screen_color_matching(theColor)
 */
short screen_color_matching(padRGB* theColor)
{
  unsigned char i;
  for (i=0;i<8;i++)
    {
      if (i>highestColorIndex)
	{
	  palette[i]._red=theColor->_red;
	  palette[i]._green=theColor->_green;
	  palette[i]._blue=theColor->_blue;
	  highestColorIndex++;
	  return i;
	}
      else
	{
	  if ((palette[i]._red==theColor->_red) && 
	      (palette[i]._green==theColor->_green) && 
	      (palette[i]._blue==theColor->_blue))
	    {
	      return i;
	    }
	}
    }  
}

/**
 * Set pen mode for drawing operations
 */
void screen_set_pen_mode(void)
{
  if (CurMode==ModeErase || CurMode==ModeInverse)
    {
      SetPenMode(modeBIC);
    }
  else
    {
      SetPenMode(modeCopy);
    }

  SetSolidPenPat(foregroundColor);
}

/**
 * screen_clear_palette - Clear the palette
 */
void screen_clear_palette(void)
{
  int i;
  for (i=0;i<16;i++)
    {
      palette[i]._red=0;
      palette[i]._green=0;
      palette[i]._blue=0;
    }
}

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void)
{
  highestColorIndex=0;
  screen_clear_palette();

  foregroundColor=backgroundColor=0;
  
  palette[0]._red=background_rgb._red;
  palette[0]._green=background_rgb._green;
  palette[0]._blue=background_rgb._blue;

  if ((background_rgb._red   != foreground_rgb._red) &&
      (background_rgb._green != foreground_rgb._green) &&
      (background_rgb._blue  != foreground_rgb._blue))
    {
      palette[1]._red=foreground_rgb._red;
      palette[1]._green=foreground_rgb._green;
      palette[1]._blue=foreground_rgb._blue;
      highestColorIndex++;
      foregroundColor=1;
    }

  // Finally, a fall back, if somehow, color 0 and color 1 are black, fix it.
  if ((palette[1]._red==0) &&
      (palette[1]._green==0) &&
      (palette[1]._blue==0) &&
      (palette[0]._red==0) &&
      (palette[0]._green==0) &&
      (palette[0]._blue==0))
    {
      palette[0]._red=palette[0]._green=palette[0]._blue=0;
      palette[1]._red=palette[1]._green=palette[1]._blue=255;
      foregroundColor=1;
      backgroundColor=0;
      foreground_rgb._red=foreground_rgb._green=foreground_rgb._blue=255;
      background_rgb._red=background_rgb._green=background_rgb._blue=0;
    }
  
  screen_remap_palette();
  
  ClearScreen(0); // 0 is always the new remapped background color.
  SetSolidPenPat(foregroundColor);
}

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt* Coord1, padPt* Coord2)
{
  Rect rect;

  rect.v1=scaley[Coord1->y];
  rect.h1=scalex[Coord1->x];
  rect.v2=scaley[Coord2->y];
  rect.h2=scalex[Coord2->x];

  /* screen_set_pen_mode(); */
  SetPenMode(modeCopy);
  SetSolidPenPat(backgroundColor);
  PaintRect(&rect);
}

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord)
{
  screen_set_pen_mode();
  MoveTo(scalex[Coord->x],scaley[Coord->y]);
  Line(0,0);
}

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2)
{
  screen_set_pen_mode();
  MoveTo(scalex[Coord1->x],scaley[Coord1->y]);
  LineTo(scalex[Coord2->x],scaley[Coord2->y]);
}

/**
 * screen_char_draw(Coord, ch, count) - Output buffer from ch* of length count as PLATO characters
 */
void screen_char_draw(padPt* Coord, unsigned char* ch, unsigned char count)
{
  short offset;
  int i;

  SetPenMode(0);
  SetTextMode(0);
  
  // TODO: Set font for M2/M3
  switch(CurMem)
    {
    case M0:
      if (ModeBold==padT)
	SetFont((FontHndl)boldfontHandle);
      else
	SetFont((FontHndl)fontHandle);
      offset=0;
      break;
    case M1:
      if (ModeBold==padT)
	SetFont((FontHndl)boldfontHandle);
      else
	SetFont((FontHndl)fontHandle);
      offset=96;
      break;
    case M2:
      SetFont((FontHndl)userfontHandle);
      offset=-32;
      break;
    case M3:
      SetFont((FontHndl)userfontHandle);
      offset=32;
      break;
    }

  if (CurMode==ModeRewrite)
    {
      Rect r;
      r.h1=scalex[Coord->x];
      r.v1=scaley[Coord->y]-6;
      r.h2=r.h1+(count*5);
      r.v2=scaley[Coord->y];
      SetSolidPenPat(0);
      SetPenMode(modeCopy);
      PaintRect(&r);
    }
  
  SetFontFlags(1);
  SetForeColor(foregroundColor);
  SetBackColor(backgroundColor);
  
  switch(CurMode)
    {
    case ModeWrite:
      SetTextMode(modeForeOR);
      SetPenMode(modeOR);
      break;
    case ModeRewrite:
      SetTextMode(modeForeOR);
      SetPenMode(modeOR);
      break;
    case ModeErase:
      SetTextMode(modeForeBIC);
      SetPenMode(modeBIC);
      break;
    case ModeInverse:
      SetTextMode(notForeCOPY);
      SetPenMode(notCopy);
      break;
    }
  
  for (i=0;i<count;++i)
    {
      ch[i]+=offset;
    }
  
  MoveTo(scalex[Coord->x],scaley[Coord->y]);
  DrawText(ch,count);
}

/**
 * screen_tty_char - Called to plot chars when in tty mode
 */
void screen_tty_char(padByte theChar)
{
  if ((theChar >= 0x20) && (theChar < 0x7F)) {
    screen_char_draw(&TTYLoc, &theChar, 1);
    TTYLoc.x += CharWide;
  }
  else if ((theChar == 0x0b)) /* Vertical Tab */
    {
      TTYLoc.y += CharHigh;
    }
  else if ((theChar == 0x08) && (TTYLoc.x > 7))	/* backspace */
    {
      TTYLoc.x -= CharWide;
      // screen_block_draw(&scalex[TTYLoc.x],&scaley[TTYLoc.y],&scalex[TTYLoc.x+CharWide],&scaley[TTYLoc.y+CharHigh]);
    }
  else if (theChar == 0x0A)			/* line feed */
    TTYLoc.y -= CharHigh;
  else if (theChar == 0x0D)			/* carriage return */
    TTYLoc.x = 0;
  
  if (TTYLoc.x + CharWide > 511) {	/* wrap at right side */
    TTYLoc.x = 0;
    TTYLoc.y -= CharHigh;
  }
  
  if (TTYLoc.y < 0) {
    screen_clear();
    TTYLoc.y=495;
  }
}

void _screen_paint(unsigned short x, unsigned short y)
{
  static unsigned short xStack[320];
  static unsigned char yStack[192];
  unsigned char stackentry = 1;
  unsigned char spanAbove, spanBelow;

  unsigned char oldColor = GetPixel(x,y);

  SetSolidPenPat(foregroundColor);

  if (oldColor == foregroundColor)
    return;

  do
    {
      unsigned short startx;
      while (x > 0 && GetPixel(x-1,y) == oldColor)
        --x;

      spanAbove = spanBelow = false;
      startx=x;

      while(GetPixel(x,y) == oldColor)
        {
          /* tgi_setpixel(x,y); */

          if (y < (191))
            {
              unsigned char belowColor = GetPixel(x, y+1);
              if (!spanBelow  && belowColor == oldColor)
                {
                  xStack[stackentry]  = x;
                  yStack[stackentry]  = y+1;
                  ++stackentry;
                  spanBelow = true;
                }
              else if (spanBelow && belowColor != oldColor)
                spanBelow = false;
            }

          if (y > 0)
            {
              unsigned char aboveColor = GetPixel(x, y-1);
              if (!spanAbove  && aboveColor == oldColor)
                {
                  xStack[stackentry]  = x;
                  yStack[stackentry]  = y-1;
                  ++stackentry;
                  spanAbove = true;
                }
              else if (spanAbove && aboveColor != oldColor)
                spanAbove = false;
            }

          ++x;
        }
      MoveTo(startx,y);
      LineTo(x-1,y);
      --stackentry;
      x = xStack[stackentry];
      y = yStack[stackentry];
    }
  while (stackentry);
}

void _screen_paint_seedfill(unsigned short x, unsigned short y)
{
  LocInfo loc;
  Rect rect;
  LeakTable leakTable={1,{GetPixel(x,y)}};
  Pattern pattern;
  SetSolidPenPat(foregroundColor);
  GetPenPat(&pattern);
  GetPortLoc(&loc);
  GetPortRect(&rect);
  SeedFill(&loc,&rect,&loc,&rect,x,y,0x1002,(PatternPtr)pattern,(Pointer)&leakTable);
}

void screen_paint(padPt* Coord)
{
  _screen_paint(scalex[Coord->x],scaley[Coord->y]);
}

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void)
{
  endgraph();
}
