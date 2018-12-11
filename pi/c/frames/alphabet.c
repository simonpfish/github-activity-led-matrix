#include <stdint.h>

#define ALPHABET_FRAME_COUNT 37
#define ALPHABET_FRAME_WIDTH 5
#define ALPHABET_FRAME_HEIGHT 7

/* Piskel data for "alphabet" */
// 0-9, then a-z in order
static const uint32_t alphabet_data[37][35] = {
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0xffffff00, 0xffffff00, 
0xffffff00, 0x00000000, 0xffffff00, 0x00000000, 0xffffff00, 
0xffffff00, 0xffffff00, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0xffffff00, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0xffffff00, 0x00000000, 0x00000000, 0x00000000, 
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00
},
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0xffffff00, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0xffffff00, 0x00000000, 
0x00000000, 0xffffff00, 0x00000000, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0xffffff00, 0x00000000, 
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0xffffff00, 0x00000000
},
{
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0xffffff00, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffff00, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0xffffff00, 0x00000000, 0x00000000, 0x00000000, 0xffffff00, 
0x00000000, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000
},
{
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0x00000000
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00
},
{
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0xfff4ff00, 0x00000000, 0xfff4ff00, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000
},
{
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 
0x00000000, 0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 
0x00000000, 0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 
0x00000000, 0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00, 0xfff4ff00
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
}
};
