#include <stdio.h>
#include <quickdraw.h>
#include <string.h>

extern unsigned char running;

/**
 * Clear prompt
 */
void prompt_clr(void)
{
  Rect clrRect;
  clrRect.h1=0;
  clrRect.v1=184;
  clrRect.h2=320;
  clrRect.v2=200;
  SetSolidBackPat(0);
  EraseRect(&clrRect);
}

/**
 * Delay a bit.
 */
void prompt_delay(void)
{
  /* int i; */
  /* for (i=0;i<1000;i++) */
  /*   { */
  /*   } */
}

/**
 * Show a connect prompt and ask for hostname
 */
void prompt_connect(char* hostname)
{
  prompt_clr();
  MoveTo(0,191);
  printf("Hostname or <ENTER> for IRATA.ONLINE\n> ");
  gets(hostname);

  if (hostname[0]=='\0') // empty string, use default.
    {
      strcpy(hostname,"IRATA.ONLINE:8005");
    }

  // Append port 8005 if a port isn't specified.
  if (strstr(hostname,":")==NULL)
    {
      strcat(hostname,":8005");
    }
  
}

/**
 * Display a prompt
 */
void prompt_display(char* text)
{
  prompt_clr();
  MoveTo(0,191);
  printf("%s",text);
  prompt_delay();
}

/**
 * Display an IP address
 */
void prompt_display_ipaddress(char* text)
{
  prompt_clr();
  MoveTo(0,191);
  printf("Address Resolved to:\n");
  printf("%s",text);
  prompt_delay();
}

/**
 * Display no Marinetti
 */
void prompt_display_no_marinetti(void)
{
  unsigned char ch;
  MoveTo(0,100);
  printf("  PLATOTerm Requires Marinetti 3.0b3 \n");
  printf("   to be loaded. Press any key to    \n");
  printf("       Return to the Finder.         \n");
  ch=getchar();
  running=false;
}

/**
 * Display exit prompt
 */
unsigned char prompt_exit(void)
{
  unsigned key;
  prompt_display("Exit PLATOTerm (Y/N)? ");
  return (key=='y' || key=='Y');
}
