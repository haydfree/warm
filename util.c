#include <util.h>

i8
rand_s256(char *out, u16 size)
{
	i8 ret = ERROR;
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	u16 i = 0, charset_size = sizeof(charset) - 1;

	GUARD_NULL(out);
	GUARD_NOT_EQUAL(size, 256);	

	ZERO_MEM(out, size);
	for (i = 0; i < size - 1; i++)
	{
		out[i] = (char) charset[rand() % charset_size];
	}

	ret = SUCCESS;
cleanup:
	return ret;
}
