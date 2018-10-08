#include "src/protocol.h"
#include "src/splash.h"
#include "src/screen.h"
#include "src/io.h"
#include "src/terminal.h"
#include "src/keyboard.h"

#define false 0
#define true 1

unsigned char already_started=false;

void main(void)
{
  screen_init();
  ShowPLATO(splash,1343);
  terminal_initial_position();
  io_init();
  for (;;)
    {
      keyboard_main();
      io_main();
    }
}
