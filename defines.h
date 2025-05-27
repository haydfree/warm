#ifndef DEFINES_H
#define DEFINES_H

#include <string.h>

#define GUARD_OOB(val, min, max)                do { if ((val) < (min) || (val) > (max)) { goto cleanup; } } while (0)
#define GUARD_NULL(ptr)                         do { if (!(ptr)) { goto cleanup; } } while (0)
#define GUARD_TRUE(expr)                        do { if ((expr)) { goto cleanup; } } while (0)
#define GUARD_FALSE(expr)                       do { if (!(expr)) { goto cleanup; } } while (0)
#define GUARD_POS(val)                          do { if ((val) > 0) { goto cleanup; } } while (0)
#define GUARD_NEG(val)                          do { if ((val) < 0) { goto cleanup; } } while (0)
#define GUARD_ZERO(val)                         do { if ((val) == 0) { goto cleanup; } } while (0)
#define GUARD_NON_POS(val)                      do { if ((val) <= 0) { goto cleanup; } } while (0)
#define GUARD_NON_NEG(val)                      do { if ((val) >= 0) { goto cleanup; } } while (0)
#define GUARD_NON_ZERO(val)                     do { if ((val) != 0) { goto cleanup; } } while (0)
#define GUARD_ERROR(expr)                       GUARD_TRUE(expr)
#define GUARD_EQUAL(val1, val2)					do { if (val1 == val2) { goto cleanup; } } while (0)
#define GUARD_NOT_EQUAL(val1, val2)				do { if (val1 != val2) { goto cleanup; } } while (0)

#define ZERO_MEM(ptr, size)						memset(ptr, 0, size)	
#define FREE(ptr)								if ((ptr)) { free(ptr); ptr = NULL; }

typedef unsigned char u8; 
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char i8; 
typedef signed short i16;
typedef signed int i32;
typedef signed long i64;

typedef float f32;
typedef double f64;

typedef int b32;
typedef char b8;

#define STATIC_ASSERT(expr, msg) typedef char static_assertion_##msg[(expr) ? 1 : -1]

STATIC_ASSERT(sizeof(u8) == 1, u8_must_be_1_byte);
STATIC_ASSERT(sizeof(u16) == 2, u16_must_be_2_bytes);
STATIC_ASSERT(sizeof(u32) == 4, u32_must_be_4_bytes);
STATIC_ASSERT(sizeof(u64) == 8, u64_must_be_8_bytes);

STATIC_ASSERT(sizeof(i8) == 1, i8_must_be_1_byte);
STATIC_ASSERT(sizeof(i16) == 2, i16_must_be_2_bytes);
STATIC_ASSERT(sizeof(i32) == 4, i32_must_be_4_bytes);
STATIC_ASSERT(sizeof(i64) == 8, i64_must_be_8_bytes);

STATIC_ASSERT(sizeof(f32) == 4, f32_must_be_4_bytes);
STATIC_ASSERT(sizeof(f64) == 8, f64_must_be_8_bytes);

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define ERROR -1

#define ID_SIZE 256

#endif
