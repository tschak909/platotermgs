#include <Memory.h>
#include <Event.h>
#include <MiscTool.h>
#include "src/protocol.h"
#include "src/splash.h"
#include "src/screen.h"
#include "src/io.h"
#include "src/terminal.h"
#include "src/keyboard.h"
#include "src/prompt.h"

unsigned char already_started=false;
unsigned char running=false;
EventRecord event;
word mmID;
Handle dpHandle=NULL;

int main(void)
{
  mmID=MMStartUp();

  dpHandle = NewHandle(0x0600, mmID,
  		       attrBank | attrPage |attrNoCross | attrFixed | attrLocked,
  		       0x000000);

  EMStartUp((Word)*dpHandle, 0x14, 0, 320, 0, 200, mmID);

  MTStartUp();
  
  screen_init();
  ShowPLATO(splash,sizeof(splash));
  terminal_initial_position();
  if (io_init()==false)
    {
      screen_done();
    }
  else
    {
      running=true;
      while (running==true)
	{
	  GetNextEvent(everyEvent,&event);
	  keyboard_main();
	  io_main();
	  touch_main();
	}
    }

  io_done();
  touch_done();
  screen_done();

  io_done();
  touch_done();
  screen_done();
  MTShutDown();
  EMShutDown();
  DisposeHandle(dpHandle);
  return 0;  
}
