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
  clrRect.v1=192;
  clrRect.h2=319;
  clrRect.v2=199;
  EraseRect(&clrRect);
}

/**
 * Delay a bit.
 */
void prompt_delay(void)
{
  int i;
  for (i=0;i<1000;i++)
    {
    }
}

/**
 * Show a connect prompt and ask for hostname
 */
void prompt_connect(char* hostname)
{
  prompt_clr();
  MoveTo(0,192);
  printf("Hostname or <ENTER> for IRATA.ONLINE\n> ");
  scanf("%s",hostname);
  if (strcmp(hostname,"")==0)
    {
      strcpy(hostname,"IRATA.ONLINE");
    }
}

/**
 * Display a prompt
 */
void prompt_display(char* text)
{
  prompt_clr();
  MoveTo(0,192);
  printf("%s",text);
  prompt_delay();
}

/**
 * Display an IP address
 */
void prompt_display_ipaddress(char* text)
{
  prompt_clr();
  MoveTo(0,192);
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
