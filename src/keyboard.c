#include <Event.h>
#include <QuickDraw.h>
#include "src/keyboard.h"
#include "src/key.h"
#include "src/protocol.h"
#include "src/io.h"

extern EventRecord event;

void keyboard_out(unsigned char platoKey)
{
  if (platoKey==0xff)
    return;
  
  if (platoKey>0x7F)
    {
      Key(ACCESS);
      Key(ACCESS_KEYS[platoKey-0x80]);
      return;
    }
  Key(platoKey);
  return;
}

void keyboard_main(void)
{
  // Keyboard events already captured in main()
  if (event.what == keyDownEvt)
    {
      unsigned char key=event.message;
      unsigned char tmp[8];
      if (event.modifiers & appleKey)
	{
	  // Special keys
	}
      else if (event.modifiers & shiftKey)
	{
	  keyboard_out(shift_key_to_pkey[key]);
	}
      else if (TTY)
	{
	  keyboard_out_tty(key);
	}
      else
	{
	  keyboard_out(key_to_pkey[key]);
	}
    }
}

void keyboard_clear(void)
{
}

void keyboard_out_tty(char ch)
{
  io_send_byte(ch);
}
