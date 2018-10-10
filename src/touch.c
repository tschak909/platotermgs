#include <quickdraw.h>
#include "src/touch.h"

static unsigned char touch_cursor_visible=0;

/**
 * touch_init() - Set up touch screen
 */
void touch_init(void)
{
}

/**
 * touch_main() - Main loop for touch screen
 */
void touch_main(void)
{
}

/**
 * touch_allow - Set whether touchpanel is active or not.
 */
void touch_allow(padBool allow)
{
  if (allow==true && touch_cursor_visible==false)
    {
      touch_cursor_visible=true;
      ShowCursor();
    }
  else if (allow==false && touch_cursor_visible==true)
    {
      touch_cursor_visible=false;
      HideCursor();
    }
}

/**
 * handle_mouse - Process mouse events and turn into scaled touch events
 */
void handle_mouse(void)
{
}

/**
 * touch_hide() - hide the mouse cursor
 */
void touch_hide(void)
{
}

/**
 * touch_done() - Stop the mouse driver
 */
void touch_done(void)
{
}
