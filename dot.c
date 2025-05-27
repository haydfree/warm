#include <dot.h>

i8 
create_dot(Dot *dot)
{
	i8 ret = ERROR;

	GUARD_NULL(dot);

	ret = SUCCESS;
cleanup:
	return ret;
}
