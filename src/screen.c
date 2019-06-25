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

Handle userfontHandle;
Font* userfontPtr;

static char textBuf[128];

extern padBool FastText; /* protocol.c */
extern Word mmID; /* main.c */
extern Handle dpHandle; /* main.c */

/**
 * screen_init() - Set up the screen
 */
void screen_init(void)
{
  startgraph(320);
  SetPenMode(0);
  SetPenSize(1,1);
  SetPenMode(0);
  QDAuxStartUp();

  // Initialize font handle and copy font into it.
  fontHandle=NewHandle(2575,mmID,0,NULL);
  PtrToHand((Pointer)font,fontHandle,2575);
  fontPtr=*(FontHndl)fontHandle;

  // Initialize user font handle
  userfontHandle=NewHandle(1657,mmID,0,NULL);
  PtrToHand((Pointer)userfont,userfontHandle,1657);
  userfontPtr=*(FontHndl)userfontHandle;
}

/**
 * screen_wait(void) - Sleep for approx 16.67ms
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
  index=screen_color(theColor);
  foregroundColor=index;
  foreground_rgb._red=theColor->_red;
  foreground_rgb._green=theColor->_green;
  foreground_rgb._blue=theColor->_blue;
}

/**
 * Set background color
 */
void screen_background(padRGB* theColor)
{
  short index;
  index=screen_color(theColor);
  backgroundColor=index;
  background_rgb._red=theColor->_red;
  background_rgb._green=theColor->_green;
  background_rgb._blue=theColor->_blue;
}

/**
 * screen_color_matching(theColor)
 */
short screen_color_matching(padRGB* theColor)
{
  int i=0;
  for (i=0;i<16;++i)
    {
      if ((palette[i]._red  ==(theColor->_red)) &&
	  (palette[i]._green==(theColor->_green)) &&
	  (palette[i]._blue ==(theColor->_blue)))
        return i;
      else if (i>highestColorIndex)
        return ++highestColorIndex;
    }
  return -1;
}

/**
 * Set selected screen color (fg/bg)
 */
short screen_color(padRGB* theColor)
{
  short index=screen_color_matching(theColor);
  palette[index]._red=theColor->_red;
  palette[index]._green=theColor->_green;
  palette[index]._blue=theColor->_blue;
  screen_remap_palette();
  return index;
}

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void)
{
  memset(palette,-1,sizeof(palette));
  highestColorIndex=0;
  palette[0]=background_rgb;
  ++highestColorIndex;

  if ((background_rgb._red   != foreground_rgb._red) &&
      (background_rgb._green != foreground_rgb._green) &&
      (background_rgb._blue  != foreground_rgb._blue))
    {
      palette[1]=foreground_rgb;
      ++highestColorIndex;
    }

  screen_remap_palette();
  ClearScreen(0); // 0 is always the new remapped background color.
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
  
  if (CurMode==ModeErase || CurMode==ModeInverse)
    SetSolidPenPat(backgroundColor);
  else
    SetSolidPenPat(foregroundColor);

  PaintRect(&rect);
}

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord)
{
  if (CurMode==ModeErase || CurMode==ModeInverse)
    {
      SetSolidPenPat(backgroundColor);
    }
  else
    {
      SetSolidPenPat(foregroundColor);
    }

  MoveTo(scalex[Coord->x],scaley[Coord->y]);
  Line(0,0);
}

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2)
{
  if (CurMode==ModeErase || CurMode==ModeInverse)
    SetSolidPenPat(backgroundColor);
  else
    SetSolidPenPat(foregroundColor);

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

  // TODO: Set font for M2/M3
  switch(CurMem)
    {
    case M0:
      SetFont((FontHndl)fontHandle);
      offset=0;
      break;
    case M1:
      SetFont((FontHndl)fontHandle);
      offset=96;
      break;
    case M2:
      offset=-32;
      break;
    case M3:
      offset=32;
      break;
    }

  SetForeColor(foregroundColor);
  SetBackColor(backgroundColor);
  
  switch(CurMode)
    {
    case ModeWrite:
      /* SetPenMode(modeOR); */
      SetTextMode(modeForeOR);
      break;
    case ModeRewrite:
      /* SetPenMode(modeCopy); */
      SetTextMode(modeForeCopy);
      break;
    case ModeErase:
      /* SetPenMode(modeBIC); */
      SetTextMode(modeForeBIC);
      break;
    case ModeInverse:
      /* SetPenMode(notBIC); */
      SetTextMode(notForeBIC);
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
