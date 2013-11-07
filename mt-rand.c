

#include "mt-rand.h"

#include <stdio.h>
#include <stdlib.h>


#define N             (624)               /* length of state vector */
#define M             (397)               /* a period parameter */
#define K             (0x9908B0DFU)       /* a magic constant */
#define hiBit(u)      ((u) & 0x80000000U) /* mask all but highest   bit of u */
#define loBit(u)      ((u) & 0x00000001U) /* mask all but lowest    bit of u */
#define loBits(u)     ((u) & 0x7FFFFFFFU) /* mask    the highest    bit of u */
#define mixBits(u, v) (hiBit(u)|loBits(v))/* move hi bit of u to hi bit of v */

static uint32   state[N+1];  /* state vector + 1 extra to not violate ANSI C */
static uint32   *next;       /* next random value is computed from here */
static int      left = -1;   /* can *next++ this many times before reloading */


void seedMT(uint32 seed)
 {

    register uint32 x = (seed | 1U) & 0xFFFFFFFFU, *s = state;
    register int    j;

    for(left=0, *s++=x, j=N; --j;
        *s++ = (x*=69069U) & 0xFFFFFFFFU);
 }


uint32 reloadMT(void)
 {
    register uint32 *p0=state, *p2=state+2, *pM=state+M, s0, s1;
    register int    j;

    if(left < -1)
        seedMT(4357U);

    left=N-1, next=state+1;

    for(s0=state[0], s1=state[1], j=N-M+1; --j; s0=s1, s1=*p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);

    for(pM=state, j=M; --j; s0=s1, s1=*p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);

    s1=state[0], *p0 = *pM ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
    s1 ^= (s1 >> 11);
    s1 ^= (s1 <<  7) & 0x9D2C5680U;
    s1 ^= (s1 << 15) & 0xEFC60000U;
    return(s1 ^ (s1 >> 18));
 }


uint32 randomMT(void)
 {
    uint32 y;

    if(--left < 0)
        return(reloadMT());

    y  = *next++;
    y ^= (y >> 11);
    y ^= (y <<  7) & 0x9D2C5680U;
    y ^= (y << 15) & 0xEFC60000U;
    return(y ^ (y >> 18));
 }

double MTrandDec(void) {
#ifdef MT_CLOSED_INTVL
  /* for reals with closed interval [0,1] */
  return ( (double) randomMT() * 2.3283064370807974e-10 );
#else
  /* for reals: [0,1)-interval */
  return ( (double) randomMT() * 2.3283064365386963e-10 );
#endif
}

/* returns a int [0, max] both-end  inclusive */
int MTrandInt(int max) {
  return ( (int) (MTrandDec() * (max + 1)) );
}

void dummyInit(long i) {
  /* do nothing */
  ;
}
#ifdef TEST
#define MAX 200000000UL
#define DM 10000

int main(void)
 {
    int j;
    unsigned long k;
    unsigned long dummy[DM];

    /* you can seed with any uint32, but the best are odds in 0..(2^32 - 1) */

    seedMT(4357U);

    /* print the first 2,002 random numbers seven to a line as an example */

    for(j=0; j<2002; j++)
        printf(" %10lu%s", (unsigned long) randomMT(), (j%7)==6 ? "\n" : "");

    /* added for bench mark */
    for(k=0; k<MAX; k++) {
      dummy[(k % DM)] = (unsigned long) MTrandInt(1000);
    }

    return(EXIT_SUCCESS);
 }
#endif
/* TEST */
