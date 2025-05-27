#include <warm.h>

i8
run(void)
{
	i8 ret = ERROR;
	Dot dot = {0};

	GUARD_ERROR(create_dot(&dot));

	ret = SUCCESS;
cleanup:
	return ret;
}
