#ifndef PROMPT_H
#define PROMPT_H

/**
 * Clear prompt
 */
void prompt_clr(void);

/**
 * Delay a bit.
 */
void prompt_delay(void);

/**
 * Show a connect prompt and ask for hostname
 */
void prompt_connect(char* hostname);

/**
 * Display an IP address
 */
void prompt_display_ipaddress(char* text);

/**
 * Clear prompt area
 */
void prompt_clear(void);

/**
 * Display no Marinetti
 */
void prompt_display_no_marinetti(void);

/**
 * Display exit prompt
 */
unsigned char prompt_exit(void);

#endif
