#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_dJIK0x0x38TN1x1x38_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=38, 
 * lda=38, ldb=38, ldc=0, mu=1, nu=1, ku=38, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const double *stM = A + (38*(Mb));
   const double *stN = B + (38*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 38
   const int incAm = 0, incAn = -(38*(Mb));
   #define incBk 38
   const int incBm = -38, incBn = 38;
   #define incCm 1
   const int incCn = (ldc) - (Mb);
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0;
   register double rB0;
   register double rC0_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         ATL_pfl1R(pfA);
         pfA += incPFA;
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         rA0 = *pA0;
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[5];
         rB0 = pB0[5];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[11];
         rB0 = pB0[11];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[12];
         rB0 = pB0[12];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[13];
         rB0 = pB0[13];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[14];
         rB0 = pB0[14];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[15];
         rB0 = pB0[15];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[16];
         rB0 = pB0[16];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[17];
         rB0 = pB0[17];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[18];
         rB0 = pB0[18];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[19];
         rB0 = pB0[19];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[20];
         rB0 = pB0[20];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[21];
         rB0 = pB0[21];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[22];
         rB0 = pB0[22];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[23];
         rB0 = pB0[23];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[24];
         rB0 = pB0[24];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[25];
         rB0 = pB0[25];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[26];
         rB0 = pB0[26];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[27];
         rB0 = pB0[27];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[28];
         rB0 = pB0[28];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[29];
         rB0 = pB0[29];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[30];
         rB0 = pB0[30];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[31];
         rB0 = pB0[31];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[32];
         rB0 = pB0[32];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[33];
         rB0 = pB0[33];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[34];
         rB0 = pB0[34];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[35];
         rB0 = pB0[35];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[36];
         rB0 = pB0[36];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[37];
         rB0 = pB0[37];
         rC0_0 += rA0 * rB0;
         pA0 += incAk;
         pB0 += incBk;
         *pC0 = rC0_0;
         pC0 += incCm;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
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
void ATL_dJIK0x0x38TN38x38x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=38, 
 * lda=38, ldb=38, ldc=0, mu=4, nu=1, ku=38, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M>>2)<<2;
   #define Nb N
   const double *ca=A, *cb=B;
   double *cc=C;
   const double *stM = A + (38*(Mb));
   const double *stN = B + (38*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*4*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 38
   const int incAm = 114, incAn = -(38*(Mb));
   #define incBk 38
   const int incBm = -38, incBn = 38;
   #define incCm 4
   const int incCn = (ldc) - (Mb);
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         do /* M-loop */
         {
            ATL_pfl1R(pfA);
            pfA += incPFA;
            rA0 = beta;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[1];
            rC1_0 *= rA0;
            rC2_0 = pC0[2];
            rC2_0 *= rA0;
            rC3_0 = pC0[3];
            rC3_0 *= rA0;
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[38];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[76];
            rA3 = pA0[114];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA0[39];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[77];
            rA3 = pA0[115];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA0[40];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[78];
            rA3 = pA0[116];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA0[41];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[79];
            rA3 = pA0[117];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[42];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[80];
            rA3 = pA0[118];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rA1 = pA0[43];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[81];
            rA3 = pA0[119];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[44];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[82];
            rA3 = pA0[120];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[45];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[83];
            rA3 = pA0[121];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[46];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[84];
            rA3 = pA0[122];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[47];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[85];
            rA3 = pA0[123];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[48];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[86];
            rA3 = pA0[124];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[11];
            rB0 = pB0[11];
            rA1 = pA0[49];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[87];
            rA3 = pA0[125];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[12];
            rB0 = pB0[12];
            rA1 = pA0[50];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[88];
            rA3 = pA0[126];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[13];
            rB0 = pB0[13];
            rA1 = pA0[51];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[89];
            rA3 = pA0[127];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[14];
            rB0 = pB0[14];
            rA1 = pA0[52];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[90];
            rA3 = pA0[128];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[15];
            rB0 = pB0[15];
            rA1 = pA0[53];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[91];
            rA3 = pA0[129];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[16];
            rB0 = pB0[16];
            rA1 = pA0[54];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[92];
            rA3 = pA0[130];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[17];
            rB0 = pB0[17];
            rA1 = pA0[55];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[93];
            rA3 = pA0[131];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[18];
            rB0 = pB0[18];
            rA1 = pA0[56];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[94];
            rA3 = pA0[132];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[19];
            rB0 = pB0[19];
            rA1 = pA0[57];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[95];
            rA3 = pA0[133];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[20];
            rB0 = pB0[20];
            rA1 = pA0[58];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[96];
            rA3 = pA0[134];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[21];
            rB0 = pB0[21];
            rA1 = pA0[59];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[97];
            rA3 = pA0[135];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[22];
            rB0 = pB0[22];
            rA1 = pA0[60];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[98];
            rA3 = pA0[136];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[23];
            rB0 = pB0[23];
            rA1 = pA0[61];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[99];
            rA3 = pA0[137];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[24];
            rB0 = pB0[24];
            rA1 = pA0[62];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[100];
            rA3 = pA0[138];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[25];
            rB0 = pB0[25];
            rA1 = pA0[63];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[101];
            rA3 = pA0[139];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[26];
            rB0 = pB0[26];
            rA1 = pA0[64];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[102];
            rA3 = pA0[140];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[27];
            rB0 = pB0[27];
            rA1 = pA0[65];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[103];
            rA3 = pA0[141];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[28];
            rB0 = pB0[28];
            rA1 = pA0[66];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[104];
            rA3 = pA0[142];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[29];
            rB0 = pB0[29];
            rA1 = pA0[67];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[105];
            rA3 = pA0[143];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[30];
            rB0 = pB0[30];
            rA1 = pA0[68];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[106];
            rA3 = pA0[144];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[31];
            rB0 = pB0[31];
            rA1 = pA0[69];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[107];
            rA3 = pA0[145];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[32];
            rB0 = pB0[32];
            rA1 = pA0[70];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[108];
            rA3 = pA0[146];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[33];
            rB0 = pB0[33];
            rA1 = pA0[71];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[109];
            rA3 = pA0[147];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[34];
            rB0 = pB0[34];
            rA1 = pA0[72];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[110];
            rA3 = pA0[148];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[35];
            rB0 = pB0[35];
            rA1 = pA0[73];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[111];
            rA3 = pA0[149];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[36];
            rB0 = pB0[36];
            rA1 = pA0[74];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[112];
            rA3 = pA0[150];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rA0 = pA0[37];
            rB0 = pB0[37];
            rA1 = pA0[75];
            rC0_0 += rA0 * rB0;
            rA2 = pA0[113];
            rA3 = pA0[151];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            *pC0 = rC0_0;
            pC0[1] = rC1_0;
            pC0[2] = rC2_0;
            pC0[3] = rC3_0;
            pC0 += incCm;
            pA0 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pA0 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=M-Mb)
      ATL_dJIK0x0x38TN1x1x38_a1_bX(k, N, 38, alpha, ca + (38*(Mb)), lda, cb, ldb, beta, cc + (Mb), ldc);
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
