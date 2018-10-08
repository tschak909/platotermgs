#include "src/io.h"
#include "src/protocol.h"
#include "src/tcpip.h"

void io_init(void)
{
  word status;
  status=TCPIPStatus();
  if (_toolErr)
    {
      LoadOneTool(54,0x200);
    }
}

void io_init_funcptrs(void)
{
}

void io_open(void)
{  
}

void io_send_byte(unsigned char b)
{
}

void io_main(void)
{
}

void io_recv_serial(void)
{  
}

void io_done()
{
}
