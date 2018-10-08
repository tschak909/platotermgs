
#include "src/keyboard.h"
#include "src/key.h"
#include "src/protocol.h"
#include "src/io.h"

unsigned char ch;

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
  /* if (kbhit()) */
  /*   { */
  /*     ch=cgetc(); */
  /*     ShowPLATO(&ch,1); // temporary half duplex echo. */
  /*     if (TTY) */
  /* 	{ */
  /* 	  keyboard_out_tty(ch); */
  /* 	} */
  /*     else */
  /* 	{ */
  /* 	  keyboard_out(key_to_pkey[ch]); */
  /* 	}  */
  /*   } */
}

void keyboard_clear(void)
{
}

void keyboard_out_tty(char ch)
{
  io_send_byte(ch);
}
