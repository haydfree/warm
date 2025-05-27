#include <defines.h>
#include <time.h>

typedef struct Dot
{
	u64 id;
	f32 lat;
	f32 lon;
	time_t expiry;
}
Dot;

i8 create_dot(Dot *dot);
