#ifndef __DSM_X86_H__
#define __DSM_X86_H__

#include <tchar.h>
#include <stdarg.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "dbgtool.h"

#define MAX_INSN_LENGTH 15
#define MAX_INSN_LEN    15

/* register classes */
#define T_NONE  0
#define T_GPR   1
#define T_MMX   2
#define T_CRG   3
#define T_DBG   4
#define T_SEG   5
#define T_XMM   6

/* itab prefix bits */
#define P_none          ( 0 )
#define P_c1            ( 1 << 0 )
#define P_C1(n)         ( ( n >> 0 ) & 1 )
#define P_rexb          ( 1 << 1 )
#define P_REXB(n)       ( ( n >> 1 ) & 1 )
#define P_depM          ( 1 << 2 )
#define P_DEPM(n)       ( ( n >> 2 ) & 1 )
#define P_c3            ( 1 << 3 )
#define P_C3(n)         ( ( n >> 3 ) & 1 )
#define P_inv64         ( 1 << 4 )
#define P_INV64(n)      ( ( n >> 4 ) & 1 )
#define P_rexw          ( 1 << 5 )
#define P_REXW(n)       ( ( n >> 5 ) & 1 )
#define P_c2            ( 1 << 6 )
#define P_C2(n)         ( ( n >> 6 ) & 1 )
#define P_def64         ( 1 << 7 )
#define P_DEF64(n)      ( ( n >> 7 ) & 1 )
#define P_rexr          ( 1 << 8 )
#define P_REXR(n)       ( ( n >> 8 ) & 1 )
#define P_oso           ( 1 << 9 )
#define P_OSO(n)        ( ( n >> 9 ) & 1 )
#define P_aso           ( 1 << 10 )
#define P_ASO(n)        ( ( n >> 10 ) & 1 )
#define P_rexx          ( 1 << 11 )
#define P_REXX(n)       ( ( n >> 11 ) & 1 )
#define P_ImpAddr       ( 1 << 12 )
#define P_IMPADDR(n)    ( ( n >> 12 ) & 1 )

/* rex prefix bits */
#define REX_W(r)        ( ( 0xF & ( r ) )  >> 3 )
#define REX_R(r)        ( ( 0x7 & ( r ) )  >> 2 )
#define REX_X(r)        ( ( 0x3 & ( r ) )  >> 1 )
#define REX_B(r)        ( ( 0x1 & ( r ) )  >> 0 )
#define REX_PFX_MASK(n) ( ( P_REXW(n) << 3 ) | \
	(P_REXR(n) << 2) | \
	(P_REXX(n) << 1) | \
	(P_REXB(n) << 0))

/* scable-index-base bits */
#define SIB_S(b)        ( ( b ) >> 6 )
#define SIB_I(b)        ( ( ( b ) >> 3 ) & 7 )
#define SIB_B(b)        ( ( b ) & 7 )

/* modrm bits */
#define MODRM_REG(b)    ( ( ( b ) >> 3 ) & 7 )
#define MODRM_NNN(b)    ( ( ( b ) >> 3 ) & 7 )
#define MODRM_MOD(b)    ( ( ( b ) >> 6 ) & 3 )
#define MODRM_RM(b)     ( ( b ) & 7 )


#define FMT64			"%ll"

#define SYN_ATNT		0
#define SYN_INTEL		1

typedef enum
{
	VENDOR_AMD,
	VENDOR_INTEL,
} VENDOR_IDX;

typedef enum
{
	DMOD_16,
	DMOD_32,
	DMOD_64,
} DEC_MODE_T;

typedef enum
{
	INDX_NOT_11,
	INDX_11,
} INST_MODE_T;

typedef enum
{
	INST__0F,
	INST__0F__OP_00__REG,
	INST__0F__OP_01__REG,
	INST__0F__OP_01__REG__OP_00__MOD,
	INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM,
	INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_01__VENDOR,
	INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_03__VENDOR,
	INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_04__VENDOR,
	INST__0F__OP_01__REG__OP_01__MOD,
	INST__0F__OP_01__REG__OP_01__MOD__OP_01__RM,
	INST__0F__OP_01__REG__OP_02__MOD,
	INST__0F__OP_01__REG__OP_03__MOD,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_00__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_01__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_02__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_03__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_04__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_05__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_06__VENDOR,
	INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_07__VENDOR,
	INST__0F__OP_01__REG__OP_04__MOD,
	INST__0F__OP_01__REG__OP_06__MOD,
	INST__0F__OP_01__REG__OP_07__MOD,
	INST__0F__OP_01__REG__OP_07__MOD__OP_01__RM,
	INST__0F__OP_01__REG__OP_07__MOD__OP_01__RM__OP_01__VENDOR,
	INST__0F__OP_0D__REG,
	INST__0F__OP_18__REG,
	INST__0F__OP_71__REG,
	INST__0F__OP_72__REG,
	INST__0F__OP_73__REG,
	INST__0F__OP_AE__REG,
	INST__0F__OP_AE__REG__OP_05__MOD,
	INST__0F__OP_AE__REG__OP_05__MOD__OP_01__RM,
	INST__0F__OP_AE__REG__OP_06__MOD,
	INST__0F__OP_AE__REG__OP_06__MOD__OP_01__RM,
	INST__0F__OP_AE__REG__OP_07__MOD,
	INST__0F__OP_AE__REG__OP_07__MOD__OP_01__RM,
	INST__0F__OP_BA__REG,
	INST__0F__OP_C7__REG,
	INST__0F__OP_C7__REG__OP_00__VENDOR,
	INST__0F__OP_C7__REG__OP_07__VENDOR,
	INST__0F__OP_D9__MOD,
	INST__0F__OP_D9__MOD__OP_01__X87,
	INST__1BYTE,
	INST__1BYTE__OP_60__OSIZE,
	INST__1BYTE__OP_61__OSIZE,
	INST__1BYTE__OP_63__MODE,
	INST__1BYTE__OP_6D__OSIZE,
	INST__1BYTE__OP_6F__OSIZE,
	INST__1BYTE__OP_80__REG,
	INST__1BYTE__OP_81__REG,
	INST__1BYTE__OP_82__REG,
	INST__1BYTE__OP_83__REG,
	INST__1BYTE__OP_8F__REG,
	INST__1BYTE__OP_98__OSIZE,
	INST__1BYTE__OP_99__OSIZE,
	INST__1BYTE__OP_9C__MODE,
	INST__1BYTE__OP_9C__MODE__OP_00__OSIZE,
	INST__1BYTE__OP_9C__MODE__OP_01__OSIZE,
	INST__1BYTE__OP_9D__MODE,
	INST__1BYTE__OP_9D__MODE__OP_00__OSIZE,
	INST__1BYTE__OP_9D__MODE__OP_01__OSIZE,
	INST__1BYTE__OP_A5__OSIZE,
	INST__1BYTE__OP_A7__OSIZE,
	INST__1BYTE__OP_AB__OSIZE,
	INST__1BYTE__OP_AD__OSIZE,
	INST__1BYTE__OP_AE__MOD,
	INST__1BYTE__OP_AE__MOD__OP_00__REG,
	INST__1BYTE__OP_AF__OSIZE,
	INST__1BYTE__OP_C0__REG,
	INST__1BYTE__OP_C1__REG,
	INST__1BYTE__OP_C6__REG,
	INST__1BYTE__OP_C7__REG,
	INST__1BYTE__OP_CF__OSIZE,
	INST__1BYTE__OP_D0__REG,
	INST__1BYTE__OP_D1__REG,
	INST__1BYTE__OP_D2__REG,
	INST__1BYTE__OP_D3__REG,
	INST__1BYTE__OP_D8__MOD,
	INST__1BYTE__OP_D8__MOD__OP_00__REG,
	INST__1BYTE__OP_D8__MOD__OP_01__X87,
	INST__1BYTE__OP_D9__MOD,
	INST__1BYTE__OP_D9__MOD__OP_00__REG,
	INST__1BYTE__OP_D9__MOD__OP_01__X87,
	INST__1BYTE__OP_DA__MOD,
	INST__1BYTE__OP_DA__MOD__OP_00__REG,
	INST__1BYTE__OP_DA__MOD__OP_01__X87,
	INST__1BYTE__OP_DB__MOD,
	INST__1BYTE__OP_DB__MOD__OP_00__REG,
	INST__1BYTE__OP_DB__MOD__OP_01__X87,
	INST__1BYTE__OP_DC__MOD,
	INST__1BYTE__OP_DC__MOD__OP_00__REG,
	INST__1BYTE__OP_DC__MOD__OP_01__X87,
	INST__1BYTE__OP_DD__MOD,
	INST__1BYTE__OP_DD__MOD__OP_00__REG,
	INST__1BYTE__OP_DD__MOD__OP_01__X87,
	INST__1BYTE__OP_DE__MOD,
	INST__1BYTE__OP_DE__MOD__OP_00__REG,
	INST__1BYTE__OP_DE__MOD__OP_01__X87,
	INST__1BYTE__OP_DF__MOD,
	INST__1BYTE__OP_DF__MOD__OP_00__REG,
	INST__1BYTE__OP_DF__MOD__OP_01__X87,
	INST__1BYTE__OP_E3__ASIZE,
	INST__1BYTE__OP_F6__REG,
	INST__1BYTE__OP_F7__REG,
	INST__1BYTE__OP_FE__REG,
	INST__1BYTE__OP_FF__REG,
	INST__3DNOW,
	INST__PFX_SSE66__0F,
	INST__PFX_SSE66__0F__OP_71__REG,
	INST__PFX_SSE66__0F__OP_72__REG,
	INST__PFX_SSE66__0F__OP_73__REG,
	INST__PFX_SSE66__0F__OP_C7__REG,
	INST__PFX_SSE66__0F__OP_C7__REG__OP_00__VENDOR,
	INST__PFX_SSEF2__0F,
	INST__PFX_SSEF3__0F,
	INST__PFX_SSEF3__0F__OP_C7__REG,
	INST__PFX_SSEF3__0F__OP_C7__REG__OP_07__VENDOR,
} INST_INDEX_T;

typedef enum
{
	INST_I3dnow,
	INST_Iaaa,
	INST_Iaad,
	INST_Iaam,
	INST_Iaas,
	INST_Iadc,
	INST_Iadd,
	INST_Iaddpd,
	INST_Iaddps,
	INST_Iaddsd,
	INST_Iaddss,
	INST_Iaddsubpd,
	INST_Iaddsubps,
	INST_Iand,
	INST_Iandpd,
	INST_Iandps,
	INST_Iandnpd,
	INST_Iandnps,
	INST_Iarpl,
	INST_Imovsxd,
	INST_Ibound,
	INST_Ibsf,
	INST_Ibsr,
	INST_Ibswap,
	INST_Ibt,
	INST_Ibtc,
	INST_Ibtr,
	INST_Ibts,
	INST_Icall,
	INST_Icbw,
	INST_Icwde,
	INST_Icdqe,
	INST_Iclc,
	INST_Icld,
	INST_Iclflush,
	INST_Iclgi,
	INST_Icli,
	INST_Iclts,
	INST_Icmc,
	INST_Icmovo,
	INST_Icmovno,
	INST_Icmovb,
	INST_Icmovae,
	INST_Icmovz,
	INST_Icmovnz,
	INST_Icmovbe,
	INST_Icmova,
	INST_Icmovs,
	INST_Icmovns,
	INST_Icmovp,
	INST_Icmovnp,
	INST_Icmovl,
	INST_Icmovge,
	INST_Icmovle,
	INST_Icmovg,
	INST_Icmp,
	INST_Icmppd,
	INST_Icmpps,
	INST_Icmpsb,
	INST_Icmpsw,
	INST_Icmpsd,
	INST_Icmpsq,
	INST_Icmpss,
	INST_Icmpxchg,
	INST_Icmpxchg8b,
	INST_Icomisd,
	INST_Icomiss,
	INST_Icpuid,
	INST_Icvtdq2pd,
	INST_Icvtdq2ps,
	INST_Icvtpd2dq,
	INST_Icvtpd2pi,
	INST_Icvtpd2ps,
	INST_Icvtpi2ps,
	INST_Icvtpi2pd,
	INST_Icvtps2dq,
	INST_Icvtps2pi,
	INST_Icvtps2pd,
	INST_Icvtsd2si,
	INST_Icvtsd2ss,
	INST_Icvtsi2ss,
	INST_Icvtss2si,
	INST_Icvtss2sd,
	INST_Icvttpd2pi,
	INST_Icvttpd2dq,
	INST_Icvttps2dq,
	INST_Icvttps2pi,
	INST_Icvttsd2si,
	INST_Icvtsi2sd,
	INST_Icvttss2si,
	INST_Icwd,
	INST_Icdq,
	INST_Icqo,
	INST_Idaa,
	INST_Idas,
	INST_Idec,
	INST_Idiv,
	INST_Idivpd,
	INST_Idivps,
	INST_Idivsd,
	INST_Idivss,
	INST_Iemms,
	INST_Ienter,
	INST_If2xm1,
	INST_Ifabs,
	INST_Ifadd,
	INST_Ifaddp,
	INST_Ifbld,
	INST_Ifbstp,
	INST_Ifchs,
	INST_Ifclex,
	INST_Ifcmovb,
	INST_Ifcmove,
	INST_Ifcmovbe,
	INST_Ifcmovu,
	INST_Ifcmovnb,
	INST_Ifcmovne,
	INST_Ifcmovnbe,
	INST_Ifcmovnu,
	INST_Ifucomi,
	INST_Ifcom,
	INST_Ifcom2,
	INST_Ifcomp3,
	INST_Ifcomi,
	INST_Ifucomip,
	INST_Ifcomip,
	INST_Ifcomp,
	INST_Ifcomp5,
	INST_Ifcompp,
	INST_Ifcos,
	INST_Ifdecstp,
	INST_Ifdiv,
	INST_Ifdivp,
	INST_Ifdivr,
	INST_Ifdivrp,
	INST_Ifemms,
	INST_Iffree,
	INST_Iffreep,
	INST_Ificom,
	INST_Ificomp,
	INST_Ifild,
	INST_Ifncstp,
	INST_Ifninit,
	INST_Ifiadd,
	INST_Ifidivr,
	INST_Ifidiv,
	INST_Ifisub,
	INST_Ifisubr,
	INST_Ifist,
	INST_Ifistp,
	INST_Ifisttp,
	INST_Ifld,
	INST_Ifld1,
	INST_Ifldl2t,
	INST_Ifldl2e,
	INST_Ifldlpi,
	INST_Ifldlg2,
	INST_Ifldln2,
	INST_Ifldz,
	INST_Ifldcw,
	INST_Ifldenv,
	INST_Ifmul,
	INST_Ifmulp,
	INST_Ifimul,
	INST_Ifnop,
	INST_Ifpatan,
	INST_Ifprem,
	INST_Ifprem1,
	INST_Ifptan,
	INST_Ifrndint,
	INST_Ifrstor,
	INST_Ifnsave,
	INST_Ifscale,
	INST_Ifsin,
	INST_Ifsincos,
	INST_Ifsqrt,
	INST_Ifstp,
	INST_Ifstp1,
	INST_Ifstp8,
	INST_Ifstp9,
	INST_Ifst,
	INST_Ifnstcw,
	INST_Ifnstenv,
	INST_Ifnstsw,
	INST_Ifsub,
	INST_Ifsubp,
	INST_Ifsubr,
	INST_Ifsubrp,
	INST_Iftst,
	INST_Ifucom,
	INST_Ifucomp,
	INST_Ifucompp,
	INST_Ifxam,
	INST_Ifxch,
	INST_Ifxch4,
	INST_Ifxch7,
	INST_Ifxrstor,
	INST_Ifxsave,
	INST_Ifpxtract,
	INST_Ifyl2x,
	INST_Ifyl2xp1,
	INST_Ihaddpd,
	INST_Ihaddps,
	INST_Ihlt,
	INST_Ihsubpd,
	INST_Ihsubps,
	INST_Iidiv,
	INST_Iin,
	INST_Iimul,
	INST_Iinc,
	INST_Iinsb,
	INST_Iinsw,
	INST_Iinsd,
	INST_Iint1,
	INST_Iint3,
	INST_Iint,
	INST_Iinto,
	INST_Iinvd,
	INST_Iinvlpg,
	INST_Iinvlpga,
	INST_Iiretw,
	INST_Iiretd,
	INST_Iiretq,
	INST_Ijo,
	INST_Ijno,
	INST_Ijb,
	INST_Ijae,
	INST_Ijz,
	INST_Ijnz,
	INST_Ijbe,
	INST_Ija,
	INST_Ijs,
	INST_Ijns,
	INST_Ijp,
	INST_Ijnp,
	INST_Ijl,
	INST_Ijge,
	INST_Ijle,
	INST_Ijg,
	INST_Ijcxz,
	INST_Ijecxz,
	INST_Ijrcxz,
	INST_Ijmp,
	INST_Ilahf,
	INST_Ilar,
	INST_Ilddqu,
	INST_Ildmxcsr,
	INST_Ilds,
	INST_Ilea,
	INST_Iles,
	INST_Ilfs,
	INST_Ilgs,
	INST_Ilidt,
	INST_Ilss,
	INST_Ileave,
	INST_Ilfence,
	INST_Ilgdt,
	INST_Illdt,
	INST_Ilmsw,
	INST_Ilock,
	INST_Ilodsb,
	INST_Ilodsw,
	INST_Ilodsd,
	INST_Ilodsq,
	INST_Iloopnz,
	INST_Iloope,
	INST_Iloop,
	INST_Ilsl,
	INST_Iltr,
	INST_Imaskmovq,
	INST_Imaxpd,
	INST_Imaxps,
	INST_Imaxsd,
	INST_Imaxss,
	INST_Imfence,
	INST_Iminpd,
	INST_Iminps,
	INST_Iminsd,
	INST_Iminss,
	INST_Imonitor,
	INST_Imov,
	INST_Imovapd,
	INST_Imovaps,
	INST_Imovd,
	INST_Imovddup,
	INST_Imovdqa,
	INST_Imovdqu,
	INST_Imovdq2q,
	INST_Imovhpd,
	INST_Imovhps,
	INST_Imovlhps,
	INST_Imovlpd,
	INST_Imovlps,
	INST_Imovhlps,
	INST_Imovmskpd,
	INST_Imovmskps,
	INST_Imovntdq,
	INST_Imovnti,
	INST_Imovntpd,
	INST_Imovntps,
	INST_Imovntq,
	INST_Imovq,
	INST_Imovqa,
	INST_Imovq2dq,
	INST_Imovsb,
	INST_Imovsw,
	INST_Imovsd,
	INST_Imovsq,
	INST_Imovsldup,
	INST_Imovshdup,
	INST_Imovss,
	INST_Imovsx,
	INST_Imovupd,
	INST_Imovups,
	INST_Imovzx,
	INST_Imul,
	INST_Imulpd,
	INST_Imulps,
	INST_Imulsd,
	INST_Imulss,
	INST_Imwait,
	INST_Ineg,
	INST_Inop,
	INST_Inot,
	INST_Ior,
	INST_Iorpd,
	INST_Iorps,
	INST_Iout,
	INST_Ioutsb,
	INST_Ioutsw,
	INST_Ioutsd,
	INST_Ioutsq,
	INST_Ipacksswb,
	INST_Ipackssdw,
	INST_Ipackuswb,
	INST_Ipaddb,
	INST_Ipaddw,
	INST_Ipaddq,
	INST_Ipaddsb,
	INST_Ipaddsw,
	INST_Ipaddusb,
	INST_Ipaddusw,
	INST_Ipand,
	INST_Ipandn,
	INST_Ipause,
	INST_Ipavgb,
	INST_Ipavgw,
	INST_Ipcmpeqb,
	INST_Ipcmpeqw,
	INST_Ipcmpeqd,
	INST_Ipcmpgtb,
	INST_Ipcmpgtw,
	INST_Ipcmpgtd,
	INST_Ipextrw,
	INST_Ipinsrw,
	INST_Ipmaddwd,
	INST_Ipmaxsw,
	INST_Ipmaxub,
	INST_Ipminsw,
	INST_Ipminub,
	INST_Ipmovmskb,
	INST_Ipmulhuw,
	INST_Ipmulhw,
	INST_Ipmullw,
	INST_Ipmuludq,
	INST_Ipop,
	INST_Ipopa,
	INST_Ipopad,
	INST_Ipopfw,
	INST_Ipopfd,
	INST_Ipopfq,
	INST_Ipor,
	INST_Iprefetch,
	INST_Iprefetchnta,
	INST_Iprefetcht0,
	INST_Iprefetcht1,
	INST_Iprefetcht2,
	INST_Ipsadbw,
	INST_Ipshufd,
	INST_Ipshufhw,
	INST_Ipshuflw,
	INST_Ipshufw,
	INST_Ipslldq,
	INST_Ipsllw,
	INST_Ipslld,
	INST_Ipsllq,
	INST_Ipsraw,
	INST_Ipsrad,
	INST_Ipsrlw,
	INST_Ipsrld,
	INST_Ipsrlq,
	INST_Ipsrldq,
	INST_Ipsubb,
	INST_Ipsubw,
	INST_Ipsubd,
	INST_Ipsubq,
	INST_Ipsubsb,
	INST_Ipsubsw,
	INST_Ipsubusb,
	INST_Ipsubusw,
	INST_Ipunpckhbw,
	INST_Ipunpckhwd,
	INST_Ipunpckhdq,
	INST_Ipunpckhqdq,
	INST_Ipunpcklbw,
	INST_Ipunpcklwd,
	INST_Ipunpckldq,
	INST_Ipunpcklqdq,
	INST_Ipi2fw,
	INST_Ipi2fd,
	INST_Ipf2iw,
	INST_Ipf2id,
	INST_Ipfnacc,
	INST_Ipfpnacc,
	INST_Ipfcmpge,
	INST_Ipfmin,
	INST_Ipfrcp,
	INST_Ipfrsqrt,
	INST_Ipfsub,
	INST_Ipfadd,
	INST_Ipfcmpgt,
	INST_Ipfmax,
	INST_Ipfrcpit1,
	INST_Ipfrspit1,
	INST_Ipfsubr,
	INST_Ipfacc,
	INST_Ipfcmpeq,
	INST_Ipfmul,
	INST_Ipfrcpit2,
	INST_Ipmulhrw,
	INST_Ipswapd,
	INST_Ipavgusb,
	INST_Ipush,
	INST_Ipusha,
	INST_Ipushad,
	INST_Ipushfw,
	INST_Ipushfd,
	INST_Ipushfq,
	INST_Ipxor,
	INST_Ircl,
	INST_Ircr,
	INST_Irol,
	INST_Iror,
	INST_Ircpps,
	INST_Ircpss,
	INST_Irdmsr,
	INST_Irdpmc,
	INST_Irdtsc,
	INST_Irdtscp,
	INST_Irepne,
	INST_Irep,
	INST_Iret,
	INST_Iretf,
	INST_Irsm,
	INST_Irsqrtps,
	INST_Irsqrtss,
	INST_Isahf,
	INST_Isal,
	INST_Isalc,
	INST_Isar,
	INST_Ishl,
	INST_Ishr,
	INST_Isbb,
	INST_Iscasb,
	INST_Iscasw,
	INST_Iscasd,
	INST_Iscasq,
	INST_Iseto,
	INST_Isetno,
	INST_Isetb,
	INST_Isetnb,
	INST_Isetz,
	INST_Isetnz,
	INST_Isetbe,
	INST_Iseta,
	INST_Isets,
	INST_Isetns,
	INST_Isetp,
	INST_Isetnp,
	INST_Isetl,
	INST_Isetge,
	INST_Isetle,
	INST_Isetg,
	INST_Isfence,
	INST_Isgdt,
	INST_Ishld,
	INST_Ishrd,
	INST_Ishufpd,
	INST_Ishufps,
	INST_Isidt,
	INST_Isldt,
	INST_Ismsw,
	INST_Isqrtps,
	INST_Isqrtpd,
	INST_Isqrtsd,
	INST_Isqrtss,
	INST_Istc,
	INST_Istd,
	INST_Istgi,
	INST_Isti,
	INST_Iskinit,
	INST_Istmxcsr,
	INST_Istosb,
	INST_Istosw,
	INST_Istosd,
	INST_Istosq,
	INST_Istr,
	INST_Isub,
	INST_Isubpd,
	INST_Isubps,
	INST_Isubsd,
	INST_Isubss,
	INST_Iswapgs,
	INST_Isyscall,
	INST_Isysenter,
	INST_Isysexit,
	INST_Isysret,
	INST_Itest,
	INST_Iucomisd,
	INST_Iucomiss,
	INST_Iud2,
	INST_Iunpckhpd,
	INST_Iunpckhps,
	INST_Iunpcklps,
	INST_Iunpcklpd,
	INST_Iverr,
	INST_Iverw,
	INST_Ivmcall,
	INST_Ivmclear,
	INST_Ivmxon,
	INST_Ivmptrld,
	INST_Ivmptrst,
	INST_Ivmresume,
	INST_Ivmxoff,
	INST_Ivmrun,
	INST_Ivmmcall,
	INST_Ivmload,
	INST_Ivmsave,
	INST_Iwait,
	INST_Iwbinvd,
	INST_Iwrmsr,
	INST_Ixadd,
	INST_Ixchg,
	INST_Ixlatb,
	INST_Ixor,
	INST_Ixorpd,
	INST_Ixorps,
	INST_Idb,
	INST_Iinvalid,
	INST_Id3vil,
	INST_Ina,
	INST_Igrp_reg,
	INST_Igrp_rm,
	INST_Igrp_vendor,
	INST_Igrp_x87,
	INST_Igrp_mode,
	INST_Igrp_osize,
	INST_Igrp_asize,
	INST_Igrp_mod,
	INST_Inone,
} INST_MNEMONIC_T;

typedef enum
{
	OP_NONE,

	OP_A, OP_E, OP_M, OP_G,
	OP_I,

	OP_AL, OP_CL, OP_DL, OP_BL,
	OP_AH, OP_CH, OP_DH, OP_BH,

	OP_ALr8b, OP_CLr9b, OP_DLr10b, OP_BLr11b,
	OP_AHr12b, OP_CHr13b, OP_DHr14b, OP_BHr15b,

	OP_AX, OP_CX, OP_DX, OP_BX,
	OP_SI, OP_DI, OP_SP, OP_BP,

	OP_rAX, OP_rCX, OP_rDX, OP_rBX,
	OP_rSP, OP_rBP, OP_rSI, OP_rDI,

	OP_rAXr8, OP_rCXr9, OP_rDXr10, OP_rBXr11,
	OP_rSPr12, OP_rBPr13, OP_rSIr14, OP_rDIr15,

	OP_eAX, OP_eCX, OP_eDX, OP_eBX,
	OP_eSP, OP_eBP, OP_eSI, OP_eDI,

	OP_ES, OP_CS, OP_SS, OP_DS,
	OP_FS, OP_GS,

	OP_ST0, OP_ST1, OP_ST2, OP_ST3,
	OP_ST4, OP_ST5, OP_ST6, OP_ST7,

	OP_J, OP_S, OP_O,
	OP_I1, OP_I3,

	OP_V, OP_W, OP_Q, OP_P,

	OP_R, OP_C, OP_D, OP_VR, OP_PR
} OPERAND_CODE_T;

typedef enum
{
	SZ_NA = 0,
	SZ_Z = 1,
	SZ_V = 2,
	SZ_P = 3,
	SZ_WP = 4,
	SZ_DP = 5,
	SZ_MDQ = 6,
	SZ_RDQ = 7,

	/* the following values are used as is,
	* and thus hard-coded. changing them
	* will break internals
	*/
	SZ_B = 8,
	SZ_W = 16,
	SZ_D = 32,
	SZ_Q = 64,
	SZ_T = 80,
} OPERAND_SIZE_T;

#define O_rSPr12  { OP_rSPr12,   SZ_NA    }
#define O_BL      { OP_BL,       SZ_NA    }
#define O_BH      { OP_BH,       SZ_NA    }
#define O_BP      { OP_BP,       SZ_NA    }
#define O_AHr12b  { OP_AHr12b,   SZ_NA    }
#define O_BX      { OP_BX,       SZ_NA    }
#define O_Jz      { OP_J,        SZ_Z     }
#define O_Jv      { OP_J,        SZ_V     }
#define O_Jb      { OP_J,        SZ_B     }
#define O_rSIr14  { OP_rSIr14,   SZ_NA    }
#define O_GS      { OP_GS,       SZ_NA    }
#define O_D       { OP_D,        SZ_NA    }
#define O_rBPr13  { OP_rBPr13,   SZ_NA    }
#define O_Ob      { OP_O,        SZ_B     }
#define O_P       { OP_P,        SZ_NA    }
#define O_Ow      { OP_O,        SZ_W     }
#define O_Ov      { OP_O,        SZ_V     }
#define O_Gw      { OP_G,        SZ_W     }
#define O_Gv      { OP_G,        SZ_V     }
#define O_rDX     { OP_rDX,      SZ_NA    }
#define O_Gx      { OP_G,        SZ_MDQ   }
#define O_Gd      { OP_G,        SZ_D     }
#define O_Gb      { OP_G,        SZ_B     }
#define O_rBXr11  { OP_rBXr11,   SZ_NA    }
#define O_rDI     { OP_rDI,      SZ_NA    }
#define O_rSI     { OP_rSI,      SZ_NA    }
#define O_ALr8b   { OP_ALr8b,    SZ_NA    }
#define O_eDI     { OP_eDI,      SZ_NA    }
#define O_Gz      { OP_G,        SZ_Z     }
#define O_eDX     { OP_eDX,      SZ_NA    }
#define O_DHr14b  { OP_DHr14b,   SZ_NA    }
#define O_rSP     { OP_rSP,      SZ_NA    }
#define O_PR      { OP_PR,       SZ_NA    }
#define O_NONE    { OP_NONE,     SZ_NA    }
#define O_rCX     { OP_rCX,      SZ_NA    }
#define O_jWP     { OP_J,        SZ_WP    }
#define O_rDXr10  { OP_rDXr10,   SZ_NA    }
#define O_Md      { OP_M,        SZ_D     }
#define O_C       { OP_C,        SZ_NA    }
#define O_G       { OP_G,        SZ_NA    }
#define O_Mb      { OP_M,        SZ_B     }
#define O_Mt      { OP_M,        SZ_T     }
#define O_S       { OP_S,        SZ_NA    }
#define O_Mq      { OP_M,        SZ_Q     }
#define O_W       { OP_W,        SZ_NA    }
#define O_ES      { OP_ES,       SZ_NA    }
#define O_rBX     { OP_rBX,      SZ_NA    }
#define O_Ed      { OP_E,        SZ_D     }
#define O_DLr10b  { OP_DLr10b,   SZ_NA    }
#define O_Mw      { OP_M,        SZ_W     }
#define O_Eb      { OP_E,        SZ_B     }
#define O_Ex      { OP_E,        SZ_MDQ   }
#define O_Ez      { OP_E,        SZ_Z     }
#define O_Ew      { OP_E,        SZ_W     }
#define O_Ev      { OP_E,        SZ_V     }
#define O_Ep      { OP_E,        SZ_P     }
#define O_FS      { OP_FS,       SZ_NA    }
#define O_Ms      { OP_M,        SZ_W     }
#define O_rAXr8   { OP_rAXr8,    SZ_NA    }
#define O_eBP     { OP_eBP,      SZ_NA    }
#define O_Isb     { OP_I,        SZ_SB    }
#define O_eBX     { OP_eBX,      SZ_NA    }
#define O_rCXr9   { OP_rCXr9,    SZ_NA    }
#define O_jDP     { OP_J,        SZ_DP    }
#define O_CH      { OP_CH,       SZ_NA    }
#define O_CL      { OP_CL,       SZ_NA    }
#define O_R       { OP_R,        SZ_RDQ   }
#define O_V       { OP_V,        SZ_NA    }
#define O_CS      { OP_CS,       SZ_NA    }
#define O_CHr13b  { OP_CHr13b,   SZ_NA    }
#define O_eCX     { OP_eCX,      SZ_NA    }
#define O_eSP     { OP_eSP,      SZ_NA    }
#define O_SS      { OP_SS,       SZ_NA    }
#define O_SP      { OP_SP,       SZ_NA    }
#define O_BLr11b  { OP_BLr11b,   SZ_NA    }
#define O_SI      { OP_SI,       SZ_NA    }
#define O_eSI     { OP_eSI,      SZ_NA    }
#define O_DL      { OP_DL,       SZ_NA    }
#define O_DH      { OP_DH,       SZ_NA    }
#define O_DI      { OP_DI,       SZ_NA    }
#define O_DX      { OP_DX,       SZ_NA    }
#define O_rBP     { OP_rBP,      SZ_NA    }
#define O_Gvw     { OP_G,        SZ_MDQ   }
#define O_I1      { OP_I1,       SZ_NA    }
#define O_I3      { OP_I3,       SZ_NA    }
#define O_DS      { OP_DS,       SZ_NA    }
#define O_ST4     { OP_ST4,      SZ_NA    }
#define O_ST5     { OP_ST5,      SZ_NA    }
#define O_ST6     { OP_ST6,      SZ_NA    }
#define O_ST7     { OP_ST7,      SZ_NA    }
#define O_ST0     { OP_ST0,      SZ_NA    }
#define O_ST1     { OP_ST1,      SZ_NA    }
#define O_ST2     { OP_ST2,      SZ_NA    }
#define O_ST3     { OP_ST3,      SZ_NA    }
#define O_E       { OP_E,        SZ_NA    }
#define O_AH      { OP_AH,       SZ_NA    }
#define O_M       { OP_M,        SZ_NA    }
#define O_AL      { OP_AL,       SZ_NA    }
#define O_CLr9b   { OP_CLr9b,    SZ_NA    }
#define O_Q       { OP_Q,        SZ_NA    }
#define O_eAX     { OP_eAX,      SZ_NA    }
#define O_VR      { OP_VR,       SZ_NA    }
#define O_AX      { OP_AX,       SZ_NA    }
#define O_rAX     { OP_rAX,      SZ_NA    }
#define O_Iz      { OP_I,        SZ_Z     }
#define O_rDIr15  { OP_rDIr15,   SZ_NA    }
#define O_Iw      { OP_I,        SZ_W     }
#define O_Iv      { OP_I,        SZ_V     }
#define O_Ap      { OP_A,        SZ_P     }
#define O_CX      { OP_CX,       SZ_NA    }
#define O_Ib      { OP_I,        SZ_B     }
#define O_BHr15b  { OP_BHr15b,   SZ_NA    }

typedef struct __entry_operand__
{
	OPERAND_CODE_T	type;
	OPERAND_SIZE_T	size;
} ENTRY_OPERAND_T;

typedef struct __inst_entry__
{
	INST_MNEMONIC_T		mnemonic;
	ENTRY_OPERAND_T		operand1;
	ENTRY_OPERAND_T		operand2;
	ENTRY_OPERAND_T		operand3;
	UINT32				prefix;
} INST_ENTRY_T;

typedef enum
{
	_NONE,

	/* 8 bit GPRs */
	_R_AL, _R_CL, _R_DL, _R_BL,
	_R_AH, _R_CH, _R_DH, _R_BH,
	_R_SPL, _R_BPL, _R_SIL, _R_DIL,
	_R_R8B, _R_R9B, _R_R10B, _R_R11B,
	_R_R12B, _R_R13B, _R_R14B, _R_R15B,

	/* 16 bit GPRs */
	_R_AX, _R_CX, _R_DX, _R_BX,
	_R_SP, _R_BP, _R_SI, _R_DI,
	_R_R8W, _R_R9W, _R_R10W, _R_R11W,
	_R_R12W, _R_R13W, _R_R14W, _R_R15W,

	/* 32 bit GPRs */
	_R_EAX, _R_ECX, _R_EDX, _R_EBX,
	_R_ESP, _R_EBP, _R_ESI, _R_EDI,
	_R_R8D, _R_R9D, _R_R10D, _R_R11D,
	_R_R12D, _R_R13D, _R_R14D, _R_R15D,

	/* 64 bit GPRs */
	_R_RAX, _R_RCX, _R_RDX, _R_RBX,
	_R_RSP, _R_RBP, _R_RSI, _R_RDI,
	_R_R8, _R_R9, _R_R10, _R_R11,
	_R_R12, _R_R13, _R_R14, _R_R15,

	/* segment registers */
	_R_ES, _R_CS, _R_SS, _R_DS,
	_R_FS, _R_GS,

	/* control registers*/
	_R_CR0, _R_CR1, _R_CR2, _R_CR3,
	_R_CR4, _R_CR5, _R_CR6, _R_CR7,
	_R_CR8, _R_CR9, _R_CR10, _R_CR11,
	_R_CR12, _R_CR13, _R_CR14, _R_CR15,

	/* debug registers */
	_R_DR0, _R_DR1, _R_DR2, _R_DR3,
	_R_DR4, _R_DR5, _R_DR6, _R_DR7,
	_R_DR8, _R_DR9, _R_DR10, _R_DR11,
	_R_DR12, _R_DR13, _R_DR14, _R_DR15,

	/* mmx registers */
	_R_MM0, _R_MM1, _R_MM2, _R_MM3,
	_R_MM4, _R_MM5, _R_MM6, _R_MM7,

	/* x87 registers */
	_R_ST0, _R_ST1, _R_ST2, _R_ST3,
	_R_ST4, _R_ST5, _R_ST6, _R_ST7,

	/* extended multimedia registers */
	_R_XMM0, _R_XMM1, _R_XMM2, _R_XMM3,
	_R_XMM4, _R_XMM5, _R_XMM6, _R_XMM7,
	_R_XMM8, _R_XMM9, _R_XMM10, _R_XMM11,
	_R_XMM12, _R_XMM13, _R_XMM14, _R_XMM15,

	_R_RIP,

	/* Operand Types */
	_OP_REG, _OP_MEM, _OP_PTR, _OP_IMM,
	_OP_JIMM, _OP_CONST
} DSM_TYPE_T;

struct operand_t
{
	DSM_TYPE_T	type;
	UINT08		size;
	union
	{
		SINT08	sbyte;
		UINT08	ubyte;
		SINT16	sword;
		UINT16	uword;
		SINT32	sdword;
		UINT32	udword;
		SINT64	sqword;
		UINT64	uqword;
		struct
		{
			UINT16	seg;
			UINT32	off;
		} ptr;
	} lval;

	DSM_TYPE_T	base;
	DSM_TYPE_T	index;
	UINT08		offset;
	UINT08		scale;
};

typedef struct __dsm_operation__
{
#define HEX_CODE_SZ		32
#define BUF_INST_SZ		64
#define MAX_OPERAND		3
	int(*pfnHook)(struct __dsm_operation__ *);
	UINT08				p_curr;
	UINT08				p_fill;
	UINT08				p_ctr;
	UINT08*				pBuff;
	UINT08*				pBuffEnd;
	UINT08				p_end;
	void(*pfnTrans)(struct __dsm_operation__ *);
	UINT64				n_offset;
	char				n_hexcode[HEX_CODE_SZ];
	char				n_buffer[BUF_INST_SZ];
	UINT32				n_fill;
	UINT08				dsmMode;
	UINT64				pc;
	UINT64				baseAddr;
	UINT08				vendor;
	INST_MNEMONIC_T		opcode;
	struct operand_t	operand[MAX_OPERAND];
	UINT08				error;
	UINT08				pfx_rex;
	UINT08				pfx_seg;
	UINT08				pfx_opr;
	UINT08				pfx_adr;
	UINT08				pfx_lock;
	UINT08				pfx_rep;
	UINT08				pfx_repe;
	UINT08				pfx_repne;
	UINT08				pfx_insn;
	UINT08				default64;
	UINT08				opr_mode;
	UINT08				adr_mode;
	UINT08				br_far;
	UINT08				br_near;
	UINT08				implicit_addr;
	UINT08				c1;
	UINT08				c2;
	UINT08				c3;
	UINT08				p_cache[256];
	UINT08				p_sess[64];
	INST_ENTRY_T*		pEntry;
} DSM_OP_T;
#endif/*__DSM_X86_H__*/