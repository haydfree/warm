#include <dot.h>

i8 
create_dot(Dot *dot)
{
	i8 ret = ERROR;
	time_t expiry = 0;
	char id[ID_SIZE] = {0};

	GUARD_NULL(dot);
	GUARD_ERROR(rand_s256((char*)&id, ID_SIZE));
	time(&expiry);
	printf("id: %s, size: %lu\n", id, sizeof(id));

	ret = SUCCESS;
cleanup:
	return ret;
}
