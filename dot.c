#include <dot.h>

i8 
create_dot(Dot *dot)
{
	i8 ret = ERROR;
	time_t expiry = 0;
	u64 id = 0;

	GUARD_NULL(dot);
	GUARD_ERROR(rand_u64(&id));
	time(&expiry);
	printf("time: %s\n", ctime(&expiry));

	ret = SUCCESS;
cleanup:
	return ret;
}
