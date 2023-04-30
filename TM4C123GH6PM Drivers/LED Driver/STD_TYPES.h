/*
 * STD_TYPES.h
 *
 *  Created on: Mar 20, 2023
 *      Author: AL-NABAA
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_



/*  Unsigned Type  */

typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;
typedef unsigned long long  u64;


/* Signed Type */

typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;
typedef signed long long    s64;



/*  Unsigned Type  */

typedef unsigned char*       pu8;
typedef unsigned short int*  pu16;
typedef unsigned long int*   pu32;
typedef unsigned long long*  pu64;


/* Signed Type */

typedef signed char*         ps8;
typedef signed short int*    ps16;
typedef signed long int*     ps32;
typedef signed long long*    ps64;


/*  Float Type */

typedef float              f32;
typedef double             f64;
typedef long double        f128;

/*NULL MACRO */
#define NULL                 ((void *) 0x0)

/* u32 Register */
#define u32Bit_Reg           *(volatile u32*)

#endif /* STD_TYPES_H_ */
