#include <Memory.h>
#include <Event.h>
#include <QuickDraw.h>
#include "src/keyboard.h"
#include "src/key.h"
#include "src/protocol.h"
#include "src/io.h"
#include "src/prompt.h"

extern EventRecord event;
extern unsigned char running;
extern Handle dpHandle;

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
      if (TTY)
	{
	  keyboard_out_tty(key);
	}
      else if ((event.modifiers & shiftKey) && (key==0x0D))
	{
	  keyboard_out(PKEY_NEXT1);
	}
      else if ((event.modifiers & shiftKey) && (key==0x20))
	{
	  keyboard_out(PKEY_BACKSPACE);
	}
      else if (((event.modifiers & appleKey) && (event.modifiers & shiftKey)) && ((key==0x48) || (key==0x68)))
	{
	  keyboard_out(PKEY_HELP1);
	}
      else if ((event.modifiers & appleKey) && ((key==0x48) || (key==0x68)))
	{
	  keyboard_out(PKEY_HELP);
	}
      else if (event.modifiers & appleKey)
	{
	  // Special keys
	  if (key=='x') // APPLE-X, exit
	    {
	      if (prompt_exit()==true)
		running=false;
	        io_done();
		touch_done();
		screen_done();
		EMShutDown();
		DisposeHandle(dpHandle);
		exit(0);
	    }
	  else
	    {
	      prompt_clr();
	    }
	}
      else if (event.modifiers & controlKey)
	{
	  if (event.modifiers & shiftKey)
	    {
	      keyboard_out(shift_key_to_pkey[key]);
	    }
	  else
	    {
	      keyboard_out(key_to_pkey[key]);
	    }
	}
      else
	{
	  keyboard_out(key_to_pkey[key]);
	}
    }
}

void keyboard_out_tty(char ch)
{
  io_send_byte(ch);
}
