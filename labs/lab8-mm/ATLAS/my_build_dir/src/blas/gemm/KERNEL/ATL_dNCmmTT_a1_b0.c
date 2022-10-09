#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_dJIK24x24x24TT0x0x0_a1_b0
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=24, NB=24, KB=24, 
 * lda=0, ldb=0, ldc=0, mu=4, nu=1, ku=24, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const double *stM = A + (((lda) << 4)+((lda) << 3));
   const double *stN = B + 24;
   const double *pfA = A + M;
   #define incAk 24
   const int incAm = ((((lda) << 2)) - 24), incAn = -(((lda) << 4)+((lda) << 3));
   const int incBk = (ldb), incBm = -(((ldb) << 4)+((ldb) << 3));
   #define incBn 1
   #define incCm 4
   const int incCn = (ldc) - 24;
   double *pC0=C;
   const double *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda), *pA3=pA2+(lda);
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+8);
      ATL_pfl1R(pfA+16);
      pfA += lda;
      do /* M-loop */
      {
/*
 *       Feeble prefetch of C
 */
         rC0_0 = *pC0;
         ATL_pfl1W(pC0);
         rA0 = *pA0;
         rB0 = *pB0;
         rC0_0 = rA0 * rB0;
         rA1 = *pA1;
         rA2 = *pA2;
         rC1_0 = rA1 * rB0;
         rA3 = *pA3;
         rC2_0 = rA2 * rB0;
         rC3_0 = rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[1];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[1];
         rA2 = pA2[1];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[1];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[2];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[2];
         rA2 = pA2[2];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[2];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[3];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[3];
         rA2 = pA2[3];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[3];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[4];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[4];
         rA2 = pA2[4];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[4];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[5];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[5];
         rA2 = pA2[5];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[5];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[6];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[6];
         rA2 = pA2[6];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[6];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[7];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[7];
         rA2 = pA2[7];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[7];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[8];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[8];
         rA2 = pA2[8];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[8];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[9];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[9];
         rA2 = pA2[9];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[9];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[10];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[10];
         rA2 = pA2[10];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[10];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[11];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[11];
         rA2 = pA2[11];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[11];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[12];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[12];
         rA2 = pA2[12];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[12];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[13];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[13];
         rA2 = pA2[13];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[13];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[14];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[14];
         rA2 = pA2[14];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[14];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[15];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[15];
         rA2 = pA2[15];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[15];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[16];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[16];
         rA2 = pA2[16];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[16];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[17];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[17];
         rA2 = pA2[17];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[17];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[18];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[18];
         rA2 = pA2[18];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[18];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[19];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[19];
         rA2 = pA2[19];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[19];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[20];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[20];
         rA2 = pA2[20];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[20];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[21];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[21];
         rA2 = pA2[21];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[21];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[22];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[22];
         rA2 = pA2[22];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[22];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         rA0 = pA0[23];
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA1 = pA1[23];
         rA2 = pA2[23];
         rC1_0 += rA1 * rB0;
         rA3 = pA3[23];
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         pB0 += incBk;
         pA0 += incAk;
         pA1 += incAk;
         pA2 += incAk;
         pA3 += incAk;
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
         pC0[2] = rC2_0;
         pC0[3] = rC3_0;
         pC0 += incCm;
         pA0 += incAm;
         pA1 += incAm;
         pA2 += incAm;
         pA3 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pA2 += incAn;
      pA3 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
