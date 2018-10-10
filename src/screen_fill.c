/**
 * This program uses routines from the following library:
 *
 *  JoeyLib
 *  Copyright (C) 2018 Scott Duensing <scott@kangaroopunch.com>
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
*/


#include <string.h>
#include <quickdraw.h>
#include "src/screen_fill.h"

extern int foregroundColor;
extern int backgroundColor;

typedef struct
{
  int StartX;
  int EndX;
  int Y;
  signed char Dir;		// 'signed' needs to be specified for ORCA/C
  bool ScanLeft;
  bool ScanRight;
  bool padding;			// Aligns structure on x86
} _jlScanDataT;

static jlStackT *_jlFillStackTop = NULL;

_jlScanDataT *
_jlDrawFillNewSegment (int startX, int endX, int y, signed char dir,
		       bool scanLeft, bool scanRight)
{
  _jlScanDataT *s = (_jlScanDataT *) jlMalloc (sizeof (_jlScanDataT));
  s->StartX = startX;
  s->EndX = endX;
  s->Y = y;
  s->Dir = dir;
  s->ScanLeft = scanLeft;
  s->ScanRight = scanRight;
  return s;
}


void
_jlDrawFillAddLine (int startX, int endX, int y, int ignoreStart,
		    int ignoreEnd, char dir, bool isNextInDir, bool how)
{
  int regionStart = -1;
  int x;

  for (x = startX; x < endX; x++)
    {
      if (how)
	{
	  // Unrolled conents to reduce comparison complexity.
	  if ((isNextInDir || x < ignoreStart || x >= ignoreEnd)
	      && (GetPixel (x, y) == foregroundColor))
	    {
	      MoveTo (x, y);
	      Line(0,0);
	      if (regionStart < 0)
		regionStart = x;
	    }
	  else if (regionStart >= 0)
	    {
	      jlUtilStackPush (_jlFillStackTop,
			       _jlDrawFillNewSegment (regionStart, x, y, dir,
						      regionStart == startX,
						      false));
	      regionStart = -1;
	    }
	}
      else
	{
	  // Unrolled conents to reduce comparison complexity.
	  if ((isNextInDir || x < ignoreStart || x >= ignoreEnd)
	      && (GetPixel (x, y) != foregroundColor))
	    {
	      MoveTo (x, y);
	      Line(0,0);
	      if (regionStart < 0)
		regionStart = x;
	    }
	  else if (regionStart >= 0)
	    {
	      jlUtilStackPush (_jlFillStackTop,
			       _jlDrawFillNewSegment (regionStart, x, y, dir,
						      regionStart == startX,
						      false));
	      regionStart = -1;
	    }
	}
      if (!isNextInDir && x < ignoreEnd && x >= ignoreStart)
	x = ignoreEnd - 1;
    }
  if (regionStart >= 0)
    {
      jlUtilStackPush (_jlFillStackTop,
		       _jlDrawFillNewSegment (regionStart, x, y, dir,
					      regionStart == startX, true));
    }
}


// Stole this from http://www.adammil.net/blog/v126_A_More_Efficient_Flood_Fill.html
void
_jlDrawFill (int x, int y, bool how)
{
  int height = 200;
  int width = 320;
  _jlScanDataT *r;
  int startX;
  int endX;

  // how == true;   Fill on top of foregroundColor
  // how == false;  Fill on top of any color until we encounter foregroundColor

  MoveTo (x, y);
  Line(0,0);
  
  jlUtilStackPush (_jlFillStackTop,
		   _jlDrawFillNewSegment (x, x + 1, y, 0, true, true));
  while ((r = jlUtilStackPop (_jlFillStackTop)) != NULL)
    {
      startX = r->StartX;
      endX = r->EndX;
      if (r->ScanLeft)
	{
	  if (how)
	    {
	      while (startX > 0
		     && (GetPixel (startX - 1, r->Y) == foregroundColor))
		{
		  MoveTo (--startX, r->Y);
		  Line(0,0);
		}
	    }
	  else
	    {
	      while (startX > 0
		     && (GetPixel (startX - 1, r->Y) != foregroundColor))
		{
		  MoveTo (--startX, r->Y);
		  Line(0,0);
		}
	    }
	}
      if (r->ScanRight)
	{
	  if (how)
	    {
	      while (endX < width
		     && (GetPixel (endX, r->Y) == foregroundColor))
		{
		  MoveTo (endX++, r->Y);
		  Line(0,0);
		}
	    }
	  else
	    {
	      while (endX < width
		     && (GetPixel (endX, r->Y) == foregroundColor))
		{
		  MoveTo (endX++, r->Y);
		  Line(0,0);
		}
	    }
	}
      r->StartX--;
      r->EndX++;
      if (r->Y > 0)
	_jlDrawFillAddLine (startX, endX, r->Y - 1, r->StartX, r->EndX, -1,
			    r->Dir <= 0, how);
      if (r->Y < height - 1)
	_jlDrawFillAddLine (startX, endX, r->Y + 1, r->StartX, r->EndX, 1,
			    r->Dir >= 0, how);
      jlFree (r);
    }
}


void
jlDrawFill (int x, int y)
{
  foregroundColor = GetPixel (x, y);
  _jlDrawFill (x, y, true);
}


void
jlDrawFillTo (int x, int y, byte color)
{
  foregroundColor = color;
  _jlDrawFill (x, y, false);
}

void *
_jlUtilStackPop (jlStackT ** stack)
{
  void *d = NULL;
  jlStackT *s;
  if (*stack != NULL)
    {
      s = *stack;
      d = s->data;
      *stack = s->previous;
      jlFree (s);
    }
  return d;
}


void
_jlUtilStackPush (jlStackT ** stack, void *data)
{
  jlStackT *s = NULL;
  s = (jlStackT *) jlMalloc (sizeof (jlStackT));
  s->previous = *stack;
  s->data = data;
  *stack = s;
}
