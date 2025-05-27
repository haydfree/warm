#ifndef DOT_H
#define DOT_H

#include <defines.h>
#include <util.h>

#include <time.h>
#include <stdio.h>

typedef struct Dot
{
	char id[ID_SIZE];
	f32 lat;
	f32 lon;
	time_t expiry;
}
Dot;

i8 create_dot(Dot *dot);

#endif
