#ifndef SCREEN_FILL_H
#define SCREEN_FILL_H

#ifndef bool
#define bool unsigned char
/* #define true  1 */
/* #define false 0 */
#endif

#define byte unsigned char

typedef struct _jlStackS
{
  struct _jlStackS *previous;
  void *data;
} jlStackT;

#define jlFree free
#define jlMalloc malloc

void jlDrawFill (int x, int y);
void jlDrawFillTo (int x, int y, byte color);
#define       jlUtilStackPop(stack) _jlUtilStackPop((jlStackT **)&(stack))	// Syntatic Sugar
void *_jlUtilStackPop (jlStackT ** stack);
#define       jlUtilStackPush(stack, data) _jlUtilStackPush((jlStackT **)&(stack), data)	// Syntatic Sugar
void _jlUtilStackPush (jlStackT ** stack, void *data);

#endif
