#include <Memory.h>
#include <Event.h>
#include "src/protocol.h"
#include "src/splash.h"
#include "src/screen.h"
#include "src/io.h"
#include "src/terminal.h"
#include "src/keyboard.h"

unsigned char already_started=false;
EventRecord event;
word mmID;
Handle dpHandle=NULL;

void main(void)
{
  mmID=MMStartUp();

  dpHandle = NewHandle(0x0100, mmID,
		       attrBank | attrPage |attrNoCross | attrFixed | attrLocked,
		       0x000000);

  EMStartUp((Word)*dpHandle, 0x14, 0, 0, 0, 0, mmID);

  screen_init();
  ShowPLATO(splash,sizeof(splash));
  terminal_initial_position();
  io_init();
  for (;;)
    {
      GetNextEvent(everyEvent,&event);
      keyboard_main();
      io_main();
      touch_main();
    }
}
