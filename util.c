#include <util.h>


i8
rand_u64(u64 *out)
{
	i8 ret = ERROR;

	GUARD_NULL(out);

	*out = rand();

	ret = SUCCESS;
cleanup:
	return ret;
}
