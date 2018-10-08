#include <Locator.h>
#include <tcpip.h>
#include <Event.h>
#include <gsos.h>
#include <Memory.h>
#include <texttool.h>

#include <quickdraw.h>

#include "src/io.h"
#include "src/protocol.h"

extern EventRecord event;
extern word mmID;

static cvtRec cvt;
static word ipid;
static int ok;
static int err;

static unsigned char buffer[2048];
static unsigned buffer_size;
static unsigned char out_buffer[4];

void io_init(void)
{
  StartUpTCP(NULL);
  ResolveHost("IRATA.ONLINE:8005",&cvt);
  ipid=TCPIPLogin(mmID,cvt.cvtIPAddress,cvt.cvtPort,0,0x0040);
  TCPIPOpenTCP(ipid);
  ok = WaitForStatus(ipid,1 << 0x0004); // TCPsESTABLISHED
}

void io_init_funcptrs(void)
{
}

void io_open(void)
{  
}

void io_send_byte(unsigned char b)
{
  out_buffer[0]=b;
  TCPIPWriteTCP(ipid,out_buffer,1,true,false);
}

void io_send(unsigned char* data, int size)
{
  TCPIPWriteTCP(ipid,data,size,true,false);
}

void io_main(void)
{
  static rrBuff rr;
  TCPIPPoll();
  rr.rrBuffCount=0;
  err=TCPIPReadTCP(ipid,0,(Ref)buffer,sizeof(buffer),&rr);
  buffer_size=rr.rrBuffCount;
  if (buffer_size)
    err=0;
  if (err)
    {
      // Something happened, kill it.
    }

  if (buffer_size)
    ShowPLATO((padByte*)buffer,buffer_size);
  
}

void io_recv_serial(void)
{  
}

void io_done()
{
}
