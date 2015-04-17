#include "dsm_x86.h"
#include <stdio.h>
#include <stdexcept>
#include <tchar.h>

namespace DBGTOOL {
	static INST_ENTRY_T	__inst__0f[256] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_00__REG },
		/* 01 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG },
		/* 02 */{ INST_Ilar, O_Gv, O_Ew, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ilsl, O_Gv, O_Ew, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Isyscall, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iclts, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Isysret, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvd, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iwbinvd, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iud2, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_0D__REG },
		/* 0E */{ INST_Ifemms, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Imovups, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 11 */{ INST_Imovups, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 12 */{ INST_Imovlps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 13 */{ INST_Imovlps, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 14 */{ INST_Iunpcklps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 15 */{ INST_Iunpckhps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 16 */{ INST_Imovhps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 17 */{ INST_Imovhps, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 18 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_18__REG },
		/* 19 */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1A */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1B */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1C */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1D */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1E */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1F */{ INST_Inop, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 20 */{ INST_Imov, O_R, O_C, O_NONE, P_rexr },
		/* 21 */{ INST_Imov, O_R, O_D, O_NONE, P_rexr },
		/* 22 */{ INST_Imov, O_C, O_R, O_NONE, P_rexr },
		/* 23 */{ INST_Imov, O_D, O_R, O_NONE, P_rexr },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Imovaps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 29 */{ INST_Imovaps, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2A */{ INST_Icvtpi2ps, O_V, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2B */{ INST_Imovntps, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2C */{ INST_Icvttps2pi, O_P, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2D */{ INST_Icvtps2pi, O_P, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2E */{ INST_Iucomiss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2F */{ INST_Icomiss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 30 */{ INST_Iwrmsr, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Irdtsc, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Irdmsr, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Irdpmc, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Isysenter, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* 35 */{ INST_Isysexit, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 40 */{ INST_Icmovo, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 41 */{ INST_Icmovno, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 42 */{ INST_Icmovb, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 43 */{ INST_Icmovae, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 44 */{ INST_Icmovz, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 45 */{ INST_Icmovnz, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 46 */{ INST_Icmovbe, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 47 */{ INST_Icmova, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 48 */{ INST_Icmovs, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 49 */{ INST_Icmovns, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4A */{ INST_Icmovp, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4B */{ INST_Icmovnp, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4C */{ INST_Icmovl, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4D */{ INST_Icmovge, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4E */{ INST_Icmovle, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 4F */{ INST_Icmovg, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 50 */{ INST_Imovmskps, O_Gd, O_VR, O_NONE, P_oso | P_rexr | P_rexb },
		/* 51 */{ INST_Isqrtps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 52 */{ INST_Irsqrtps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 53 */{ INST_Ircpps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 54 */{ INST_Iandps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 55 */{ INST_Iandnps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 56 */{ INST_Iorps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 57 */{ INST_Ixorps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 58 */{ INST_Iaddps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 59 */{ INST_Imulps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5A */{ INST_Icvtps2pd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5B */{ INST_Icvtdq2ps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5C */{ INST_Isubps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5D */{ INST_Iminps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5E */{ INST_Idivps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5F */{ INST_Imaxps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 60 */{ INST_Ipunpcklbw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 61 */{ INST_Ipunpcklwd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 62 */{ INST_Ipunpckldq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 63 */{ INST_Ipacksswb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 64 */{ INST_Ipcmpgtb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 65 */{ INST_Ipcmpgtw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 66 */{ INST_Ipcmpgtd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 67 */{ INST_Ipackuswb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 68 */{ INST_Ipunpckhbw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 69 */{ INST_Ipunpckhwd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6A */{ INST_Ipunpckhdq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6B */{ INST_Ipackssdw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6E */{ INST_Imovd, O_P, O_Ex, O_NONE, P_c2 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 6F */{ INST_Imovq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 70 */{ INST_Ipshufw, O_P, O_Q, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* 71 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_71__REG },
		/* 72 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_72__REG },
		/* 73 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_73__REG },
		/* 74 */{ INST_Ipcmpeqb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 75 */{ INST_Ipcmpeqw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 76 */{ INST_Ipcmpeqd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 77 */{ INST_Iemms, O_NONE, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7E */{ INST_Imovd, O_Ex, O_P, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 7F */{ INST_Imovq, O_Q, O_P, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 80 */{ INST_Ijo, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 81 */{ INST_Ijno, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 82 */{ INST_Ijb, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 83 */{ INST_Ijae, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 84 */{ INST_Ijz, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 85 */{ INST_Ijnz, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 86 */{ INST_Ijbe, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 87 */{ INST_Ija, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 88 */{ INST_Ijs, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 89 */{ INST_Ijns, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8A */{ INST_Ijp, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8B */{ INST_Ijnp, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8C */{ INST_Ijl, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8D */{ INST_Ijge, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8E */{ INST_Ijle, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 8F */{ INST_Ijg, O_Jz, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_oso },
		/* 90 */{ INST_Iseto, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 91 */{ INST_Isetno, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 92 */{ INST_Isetb, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 93 */{ INST_Isetnb, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 94 */{ INST_Isetz, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 95 */{ INST_Isetnz, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 96 */{ INST_Isetbe, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 97 */{ INST_Iseta, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 98 */{ INST_Isets, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 99 */{ INST_Isetns, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9A */{ INST_Isetp, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9B */{ INST_Isetnp, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9C */{ INST_Isetl, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9D */{ INST_Isetge, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9E */{ INST_Isetle, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 9F */{ INST_Isetg, O_Eb, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* A0 */{ INST_Ipush, O_FS, O_NONE, O_NONE, P_none },
		/* A1 */{ INST_Ipop, O_FS, O_NONE, O_NONE, P_none },
		/* A2 */{ INST_Icpuid, O_NONE, O_NONE, O_NONE, P_none },
		/* A3 */{ INST_Ibt, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* A4 */{ INST_Ishld, O_Ev, O_Gv, O_Ib, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* A5 */{ INST_Ishld, O_Ev, O_Gv, O_CL, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* A6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A8 */{ INST_Ipush, O_GS, O_NONE, O_NONE, P_none },
		/* A9 */{ INST_Ipop, O_GS, O_NONE, O_NONE, P_none },
		/* AA */{ INST_Irsm, O_NONE, O_NONE, O_NONE, P_none },
		/* AB */{ INST_Ibts, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* AC */{ INST_Ishrd, O_Ev, O_Gv, O_Ib, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* AD */{ INST_Ishrd, O_Ev, O_Gv, O_CL, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* AE */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG },
		/* AF */{ INST_Iimul, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B0 */{ INST_Icmpxchg, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* B1 */{ INST_Icmpxchg, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B2 */{ INST_Ilss, O_Gz, O_M, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B3 */{ INST_Ibtr, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B4 */{ INST_Ilfs, O_Gz, O_M, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B5 */{ INST_Ilgs, O_Gz, O_M, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B6 */{ INST_Imovzx, O_Gv, O_Eb, O_NONE, P_c2 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B7 */{ INST_Imovzx, O_Gv, O_Ew, O_NONE, P_c2 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* B8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BA */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_BA__REG },
		/* BB */{ INST_Ibtc, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* BC */{ INST_Ibsf, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* BD */{ INST_Ibsr, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* BE */{ INST_Imovsx, O_Gv, O_Eb, O_NONE, P_c2 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* BF */{ INST_Imovsx, O_Gv, O_Ew, O_NONE, P_c2 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C0 */{ INST_Ixadd, O_Eb, O_Gb, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* C1 */{ INST_Ixadd, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C2 */{ INST_Icmpps, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C3 */{ INST_Imovnti, O_M, O_Gvw, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C4 */{ INST_Ipinsrw, O_P, O_Ew, O_Ib, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C5 */{ INST_Ipextrw, O_Gd, O_PR, O_Ib, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C6 */{ INST_Ishufps, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C7 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__0F__OP_C7__REG },
		/* C8 */{ INST_Ibswap, O_rAXr8, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* C9 */{ INST_Ibswap, O_rCXr9, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CA */{ INST_Ibswap, O_rDXr10, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CB */{ INST_Ibswap, O_rBXr11, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CC */{ INST_Ibswap, O_rSPr12, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CD */{ INST_Ibswap, O_rBPr13, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CE */{ INST_Ibswap, O_rSIr14, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* CF */{ INST_Ibswap, O_rDIr15, O_NONE, O_NONE, P_oso | P_rexw | P_rexb },
		/* D0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D1 */{ INST_Ipsrlw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D2 */{ INST_Ipsrld, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D3 */{ INST_Ipsrlq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D4 */{ INST_Ipaddq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D5 */{ INST_Ipmullw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D7 */{ INST_Ipmovmskb, O_Gd, O_PR, O_NONE, P_oso | P_rexr | P_rexb },
		/* D8 */{ INST_Ipsubusb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D9 */{ INST_Ipsubusw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DA */{ INST_Ipminub, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DB */{ INST_Ipand, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DC */{ INST_Ipaddusb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DD */{ INST_Ipaddusw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DE */{ INST_Ipmaxub, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DF */{ INST_Ipandn, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E0 */{ INST_Ipavgb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E1 */{ INST_Ipsraw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E2 */{ INST_Ipsrad, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E3 */{ INST_Ipavgw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E4 */{ INST_Ipmulhuw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E5 */{ INST_Ipmulhw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E7 */{ INST_Imovntq, O_M, O_P, O_NONE, P_none },
		/* E8 */{ INST_Ipsubsb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E9 */{ INST_Ipsubsw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EA */{ INST_Ipminsw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EB */{ INST_Ipor, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EC */{ INST_Ipaddsb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* ED */{ INST_Ipaddsw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EE */{ INST_Ipmaxsw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EF */{ INST_Ipxor, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F1 */{ INST_Ipsllw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F2 */{ INST_Ipslld, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F3 */{ INST_Ipsllq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F4 */{ INST_Ipmuludq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F5 */{ INST_Ipmaddwd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F6 */{ INST_Ipsadbw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F7 */{ INST_Imaskmovq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F8 */{ INST_Ipsubb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F9 */{ INST_Ipsubw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FA */{ INST_Ipsubd, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FB */{ INST_Ipsubq, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FC */{ INST_Ipaddb, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FD */{ INST_Ipaddw, O_P, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_00__reg[8] =
	{
		/* 00 */{ INST_Isldt, O_Ev, O_NONE, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Istr, O_Ev, O_NONE, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Illdt, O_Ew, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Iltr, O_Ew, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iverr, O_Ew, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Iverw, O_Ew, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg[8] =
	{
		/* 00 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_00__MOD },
		/* 01 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_01__MOD },
		/* 02 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_02__MOD },
		/* 03 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD },
		/* 04 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_04__MOD },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_06__MOD },
		/* 07 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_07__MOD },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_00__mod[2] =
	{
		/* 00 */{ INST_Isgdt, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_00__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_01__VENDOR },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_03__VENDOR },
		/* 04 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_00__MOD__OP_01__RM__OP_04__VENDOR },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_01__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmcall, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_03__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmresume, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_04__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmxoff, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_01__mod[2] =
	{
		/* 00 */{ INST_Isidt, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_01__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_01__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Imonitor, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Imwait, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_02__mod[2] =
	{
		/* 00 */{ INST_Ilgdt, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod[2] =
	{
		/* 00 */{ INST_Ilidt, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_00__VENDOR },
		/* 01 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_01__VENDOR },
		/* 02 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_02__VENDOR },
		/* 03 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_03__VENDOR },
		/* 04 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_04__VENDOR },
		/* 05 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_05__VENDOR },
		/* 06 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_06__VENDOR },
		/* 07 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_03__MOD__OP_01__RM__OP_07__VENDOR },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_00__vendor[2] =
	{
		/* 00 */{ INST_Ivmrun, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_01__vendor[2] =
	{
		/* 00 */{ INST_Ivmmcall, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_02__vendor[2] =
	{
		/* 00 */{ INST_Ivmload, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_03__vendor[2] =
	{
		/* 00 */{ INST_Ivmsave, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_04__vendor[2] =
	{
		/* 00 */{ INST_Istgi, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_05__vendor[2] =
	{
		/* 00 */{ INST_Iclgi, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_06__vendor[2] =
	{
		/* 00 */{ INST_Iskinit, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_07__vendor[2] =
	{
		/* 00 */{ INST_Iinvlpga, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_04__mod[2] =
	{
		/* 00 */{ INST_Ismsw, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_06__mod[2] =
	{
		/* 00 */{ INST_Ilmsw, O_Ew, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_07__mod[2] =
	{
		/* 00 */{ INST_Iinvlpg, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_07__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_07__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Iswapgs, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_01__REG__OP_07__MOD__OP_01__RM__OP_01__VENDOR },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_01__reg__op_07__mod__op_01__rm__op_01__vendor[2] =
	{
		/* 00 */{ INST_Irdtscp, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_0d__reg[8] =
	{
		/* 00 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Iprefetch, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T	__inst__0f__op_18__reg[8] =
	{
		/* 00 */{ INST_Iprefetchnta, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iprefetcht0, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iprefetcht1, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Iprefetcht2, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_71__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrlw, O_PR, O_Ib, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ipsraw, O_PR, O_Ib, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipsllw, O_PR, O_Ib, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_72__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrld, O_PR, O_Ib, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ipsrad, O_PR, O_Ib, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipslld, O_PR, O_Ib, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_73__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrlq, O_PR, O_Ib, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipsllq, O_PR, O_Ib, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_ae__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ildmxcsr, O_Md, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Istmxcsr, O_Md, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_05__MOD },
		/* 06 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_06__MOD },
		/* 07 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_07__MOD },
	};

	static INST_ENTRY_T	__inst__0f__op_ae__reg__op_05__mod[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_05__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_ae__reg__op_05__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Ilfence, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T	__inst__0f__op_ae__reg__op_06__mod[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_06__MOD__OP_01__RM },
	};

	static INST_ENTRY_T	__inst__0f__op_ae__reg__op_06__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Imfence, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__0f__op_ae__reg__op_07__mod[2] =
	{
		/* 00 */{ INST_Iclflush, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Igrp_rm, O_NONE, O_NONE, O_NONE, INST__0F__OP_AE__REG__OP_07__MOD__OP_01__RM },
	};

	static INST_ENTRY_T    __inst__0f__op_ae__reg__op_07__mod__op_01__rm[8] =
	{
		/* 00 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Isfence, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__0f__op_ba__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ibt, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ibts, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ibtr, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ibtc, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__0f__op_c7__reg[8] =
	{
		/* 00 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_C7__REG__OP_00__VENDOR },
		/* 01 */{ INST_Icmpxchg8b, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__0F__OP_C7__REG__OP_07__VENDOR },
	};

	static INST_ENTRY_T    __inst__0f__op_c7__reg__op_00__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmptrld, O_Mq, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__0f__op_c7__reg__op_07__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmptrst, O_Mq, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__0f__op_d9__mod[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__0F__OP_D9__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__0f__op_d9__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Ifabs, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_If2xm1, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte[256] =
	{
		/* 00 */{ INST_Iadd, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iadd, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iadd, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Iadd, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iadd, O_AL, O_Ib, O_NONE, P_none },
		/* 05 */{ INST_Iadd, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 06 */{ INST_Ipush, O_ES, O_NONE, O_NONE, P_inv64 | P_none },
		/* 07 */{ INST_Ipop, O_ES, O_NONE, O_NONE, P_inv64 | P_none },
		/* 08 */{ INST_Ior, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 09 */{ INST_Ior, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 0A */{ INST_Ior, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 0B */{ INST_Ior, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 0C */{ INST_Ior, O_AL, O_Ib, O_NONE, P_none },
		/* 0D */{ INST_Ior, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 0E */{ INST_Ipush, O_CS, O_NONE, O_NONE, P_inv64 | P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Iadc, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 11 */{ INST_Iadc, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 12 */{ INST_Iadc, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 13 */{ INST_Iadc, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 14 */{ INST_Iadc, O_AL, O_Ib, O_NONE, P_none },
		/* 15 */{ INST_Iadc, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 16 */{ INST_Ipush, O_SS, O_NONE, O_NONE, P_inv64 | P_none },
		/* 17 */{ INST_Ipop, O_SS, O_NONE, O_NONE, P_inv64 | P_none },
		/* 18 */{ INST_Isbb, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 19 */{ INST_Isbb, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 1A */{ INST_Isbb, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 1B */{ INST_Isbb, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 1C */{ INST_Isbb, O_AL, O_Ib, O_NONE, P_none },
		/* 1D */{ INST_Isbb, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 1E */{ INST_Ipush, O_DS, O_NONE, O_NONE, P_inv64 | P_none },
		/* 1F */{ INST_Ipop, O_DS, O_NONE, O_NONE, P_inv64 | P_none },
		/* 20 */{ INST_Iand, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 21 */{ INST_Iand, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 22 */{ INST_Iand, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 23 */{ INST_Iand, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 24 */{ INST_Iand, O_AL, O_Ib, O_NONE, P_none },
		/* 25 */{ INST_Iand, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Idaa, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* 28 */{ INST_Isub, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 29 */{ INST_Isub, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 2A */{ INST_Isub, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2B */{ INST_Isub, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 2C */{ INST_Isub, O_AL, O_Ib, O_NONE, P_none },
		/* 2D */{ INST_Isub, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Idas, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* 30 */{ INST_Ixor, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 31 */{ INST_Ixor, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 32 */{ INST_Ixor, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 33 */{ INST_Ixor, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 34 */{ INST_Ixor, O_AL, O_Ib, O_NONE, P_none },
		/* 35 */{ INST_Ixor, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iaaa, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* 38 */{ INST_Icmp, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 39 */{ INST_Icmp, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 3A */{ INST_Icmp, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 3B */{ INST_Icmp, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 3C */{ INST_Icmp, O_AL, O_Ib, O_NONE, P_none },
		/* 3D */{ INST_Icmp, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iaas, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* 40 */{ INST_Iinc, O_eAX, O_NONE, O_NONE, P_oso },
		/* 41 */{ INST_Iinc, O_eCX, O_NONE, O_NONE, P_oso },
		/* 42 */{ INST_Iinc, O_eDX, O_NONE, O_NONE, P_oso },
		/* 43 */{ INST_Iinc, O_eBX, O_NONE, O_NONE, P_oso },
		/* 44 */{ INST_Iinc, O_eSP, O_NONE, O_NONE, P_oso },
		/* 45 */{ INST_Iinc, O_eBP, O_NONE, O_NONE, P_oso },
		/* 46 */{ INST_Iinc, O_eSI, O_NONE, O_NONE, P_oso },
		/* 47 */{ INST_Iinc, O_eDI, O_NONE, O_NONE, P_oso },
		/* 48 */{ INST_Idec, O_eAX, O_NONE, O_NONE, P_oso },
		/* 49 */{ INST_Idec, O_eCX, O_NONE, O_NONE, P_oso },
		/* 4A */{ INST_Idec, O_eDX, O_NONE, O_NONE, P_oso },
		/* 4B */{ INST_Idec, O_eBX, O_NONE, O_NONE, P_oso },
		/* 4C */{ INST_Idec, O_eSP, O_NONE, O_NONE, P_oso },
		/* 4D */{ INST_Idec, O_eBP, O_NONE, O_NONE, P_oso },
		/* 4E */{ INST_Idec, O_eSI, O_NONE, O_NONE, P_oso },
		/* 4F */{ INST_Idec, O_eDI, O_NONE, O_NONE, P_oso },
		/* 50 */{ INST_Ipush, O_rAXr8, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 51 */{ INST_Ipush, O_rCXr9, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 52 */{ INST_Ipush, O_rDXr10, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 53 */{ INST_Ipush, O_rBXr11, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 54 */{ INST_Ipush, O_rSPr12, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 55 */{ INST_Ipush, O_rBPr13, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 56 */{ INST_Ipush, O_rSIr14, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 57 */{ INST_Ipush, O_rDIr15, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 58 */{ INST_Ipop, O_rAXr8, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 59 */{ INST_Ipop, O_rCXr9, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5A */{ INST_Ipop, O_rDXr10, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5B */{ INST_Ipop, O_rBXr11, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5C */{ INST_Ipop, O_rSPr12, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5D */{ INST_Ipop, O_rBPr13, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5E */{ INST_Ipop, O_rSIr14, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 5F */{ INST_Ipop, O_rDIr15, O_NONE, O_NONE, P_def64 | P_depM | P_oso | P_rexb },
		/* 60 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_60__OSIZE },
		/* 61 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_61__OSIZE },
		/* 62 */{ INST_Ibound, O_Gv, O_M, O_NONE, P_inv64 | P_aso | P_oso },
		/* 63 */{ INST_Igrp_mode, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_63__MODE },
		/* 64 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 65 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 66 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 67 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 68 */{ INST_Ipush, O_Iz, O_NONE, O_NONE, P_c1 | P_oso },
		/* 69 */{ INST_Iimul, O_Gv, O_Ev, O_Iz, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 6A */{ INST_Ipush, O_Ib, O_NONE, O_NONE, P_none },
		/* 6B */{ INST_Iimul, O_Gv, O_Ev, O_Ib, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 6C */{ INST_Iinsb, O_NONE, O_NONE, O_NONE, P_none },
		/* 6D */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_6D__OSIZE },
		/* 6E */{ INST_Ioutsb, O_NONE, O_NONE, O_NONE, P_none },
		/* 6F */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_6F__OSIZE },
		/* 70 */{ INST_Ijo, O_Jb, O_NONE, O_NONE, P_none },
		/* 71 */{ INST_Ijno, O_Jb, O_NONE, O_NONE, P_none },
		/* 72 */{ INST_Ijb, O_Jb, O_NONE, O_NONE, P_none },
		/* 73 */{ INST_Ijae, O_Jb, O_NONE, O_NONE, P_none },
		/* 74 */{ INST_Ijz, O_Jb, O_NONE, O_NONE, P_none },
		/* 75 */{ INST_Ijnz, O_Jb, O_NONE, O_NONE, P_none },
		/* 76 */{ INST_Ijbe, O_Jb, O_NONE, O_NONE, P_none },
		/* 77 */{ INST_Ija, O_Jb, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Ijs, O_Jb, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Ijns, O_Jb, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Ijp, O_Jb, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Ijnp, O_Jb, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Ijl, O_Jb, O_NONE, O_NONE, P_none },
		/* 7D */{ INST_Ijge, O_Jb, O_NONE, O_NONE, P_none },
		/* 7E */{ INST_Ijle, O_Jb, O_NONE, O_NONE, P_none },
		/* 7F */{ INST_Ijg, O_Jb, O_NONE, O_NONE, P_none },
		/* 80 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_80__REG },
		/* 81 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_81__REG },
		/* 82 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_82__REG },
		/* 83 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_83__REG },
		/* 84 */{ INST_Itest, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 85 */{ INST_Itest, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 86 */{ INST_Ixchg, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 87 */{ INST_Ixchg, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 88 */{ INST_Imov, O_Eb, O_Gb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 89 */{ INST_Imov, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 8A */{ INST_Imov, O_Gb, O_Eb, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 8B */{ INST_Imov, O_Gv, O_Ev, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 8C */{ INST_Imov, O_Ev, O_S, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* 8D */{ INST_Ilea, O_Gv, O_M, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 8E */{ INST_Imov, O_S, O_Ev, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* 8F */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_8F__REG },
		/* 90 */{ INST_Ixchg, O_rAXr8, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 91 */{ INST_Ixchg, O_rCXr9, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 92 */{ INST_Ixchg, O_rDXr10, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 93 */{ INST_Ixchg, O_rBXr11, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 94 */{ INST_Ixchg, O_rSPr12, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 95 */{ INST_Ixchg, O_rBPr13, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 96 */{ INST_Ixchg, O_rSIr14, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 97 */{ INST_Ixchg, O_rDIr15, O_rAX, O_NONE, P_oso | P_rexw | P_rexb },
		/* 98 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_98__OSIZE },
		/* 99 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_99__OSIZE },
		/* 9A */{ INST_Icall, O_Ap, O_NONE, O_NONE, P_inv64 | P_oso },
		/* 9B */{ INST_Iwait, O_NONE, O_NONE, O_NONE, P_none },
		/* 9C */{ INST_Igrp_mode, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9C__MODE },
		/* 9D */{ INST_Igrp_mode, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9D__MODE },
		/* 9E */{ INST_Isahf, O_NONE, O_NONE, O_NONE, P_none },
		/* 9F */{ INST_Ilahf, O_NONE, O_NONE, O_NONE, P_none },
		/* A0 */{ INST_Imov, O_AL, O_Ob, O_NONE, P_none },
		/* A1 */{ INST_Imov, O_rAX, O_Ov, O_NONE, P_aso | P_oso | P_rexw },
		/* A2 */{ INST_Imov, O_Ob, O_AL, O_NONE, P_none },
		/* A3 */{ INST_Imov, O_Ov, O_rAX, O_NONE, P_aso | P_oso | P_rexw },
		/* A4 */{ INST_Imovsb, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_none },
		/* A5 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_A5__OSIZE },
		/* A6 */{ INST_Icmpsb, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_A7__OSIZE },
		/* A8 */{ INST_Itest, O_AL, O_Ib, O_NONE, P_none },
		/* A9 */{ INST_Itest, O_rAX, O_Iz, O_NONE, P_oso | P_rexw },
		/* AA */{ INST_Istosb, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_none },
		/* AB */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_AB__OSIZE },
		/* AC */{ INST_Ilodsb, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_none },
		/* AD */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_AD__OSIZE },
		/* AE */{ INST_Iscasb, O_NONE, O_NONE, O_NONE, P_none },
		/* AF */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_AF__OSIZE },
		/* B0 */{ INST_Imov, O_ALr8b, O_Ib, O_NONE, P_rexb },
		/* B1 */{ INST_Imov, O_CLr9b, O_Ib, O_NONE, P_rexb },
		/* B2 */{ INST_Imov, O_DLr10b, O_Ib, O_NONE, P_rexb },
		/* B3 */{ INST_Imov, O_BLr11b, O_Ib, O_NONE, P_rexb },
		/* B4 */{ INST_Imov, O_AHr12b, O_Ib, O_NONE, P_rexb },
		/* B5 */{ INST_Imov, O_CHr13b, O_Ib, O_NONE, P_rexb },
		/* B6 */{ INST_Imov, O_DHr14b, O_Ib, O_NONE, P_rexb },
		/* B7 */{ INST_Imov, O_BHr15b, O_Ib, O_NONE, P_rexb },
		/* B8 */{ INST_Imov, O_rAXr8, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* B9 */{ INST_Imov, O_rCXr9, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BA */{ INST_Imov, O_rDXr10, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BB */{ INST_Imov, O_rBXr11, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BC */{ INST_Imov, O_rSPr12, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BD */{ INST_Imov, O_rBPr13, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BE */{ INST_Imov, O_rSIr14, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* BF */{ INST_Imov, O_rDIr15, O_Iv, O_NONE, P_oso | P_rexw | P_rexb },
		/* C0 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_C0__REG },
		/* C1 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_C1__REG },
		/* C2 */{ INST_Iret, O_Iw, O_NONE, O_NONE, P_none },
		/* C3 */{ INST_Iret, O_NONE, O_NONE, O_NONE, P_none },
		/* C4 */{ INST_Iles, O_Gv, O_M, O_NONE, P_inv64 | P_aso | P_oso },
		/* C5 */{ INST_Ilds, O_Gv, O_M, O_NONE, P_inv64 | P_aso | P_oso },
		/* C6 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_C6__REG },
		/* C7 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_C7__REG },
		/* C8 */{ INST_Ienter, O_Iw, O_Ib, O_NONE, P_def64 | P_depM | P_none },
		/* C9 */{ INST_Ileave, O_NONE, O_NONE, O_NONE, P_none },
		/* CA */{ INST_Iretf, O_Iw, O_NONE, O_NONE, P_none },
		/* CB */{ INST_Iretf, O_NONE, O_NONE, O_NONE, P_none },
		/* CC */{ INST_Iint3, O_NONE, O_NONE, O_NONE, P_none },
		/* CD */{ INST_Iint, O_Ib, O_NONE, O_NONE, P_none },
		/* CE */{ INST_Iinto, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* CF */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_CF__OSIZE },
		/* D0 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D0__REG },
		/* D1 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D1__REG },
		/* D2 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D2__REG },
		/* D3 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D3__REG },
		/* D4 */{ INST_Iaam, O_Ib, O_NONE, O_NONE, P_inv64 | P_none },
		/* D5 */{ INST_Iaad, O_Ib, O_NONE, O_NONE, P_inv64 | P_none },
		/* D6 */{ INST_Isalc, O_NONE, O_NONE, O_NONE, P_inv64 | P_none },
		/* D7 */{ INST_Ixlatb, O_NONE, O_NONE, O_NONE, P_rexw },
		/* D8 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D8__MOD },
		/* D9 */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D9__MOD },
		/* DA */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DA__MOD },
		/* DB */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DB__MOD },
		/* DC */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DC__MOD },
		/* DD */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DD__MOD },
		/* DE */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DE__MOD },
		/* DF */{ INST_Igrp_mod, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DF__MOD },
		/* E0 */{ INST_Iloopnz, O_Jb, O_NONE, O_NONE, P_none },
		/* E1 */{ INST_Iloope, O_Jb, O_NONE, O_NONE, P_none },
		/* E2 */{ INST_Iloop, O_Jb, O_NONE, O_NONE, P_none },
		/* E3 */{ INST_Igrp_asize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_E3__ASIZE },
		/* E4 */{ INST_Iin, O_AL, O_Ib, O_NONE, P_none },
		/* E5 */{ INST_Iin, O_eAX, O_Ib, O_NONE, P_oso },
		/* E6 */{ INST_Iout, O_Ib, O_AL, O_NONE, P_none },
		/* E7 */{ INST_Iout, O_Ib, O_eAX, O_NONE, P_oso },
		/* E8 */{ INST_Icall, O_Jz, O_NONE, O_NONE, P_def64 | P_oso },
		/* E9 */{ INST_Ijmp, O_Jz, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
		/* EA */{ INST_Ijmp, O_Ap, O_NONE, O_NONE, P_inv64 | P_none },
		/* EB */{ INST_Ijmp, O_Jb, O_NONE, O_NONE, P_none },
		/* EC */{ INST_Iin, O_AL, O_DX, O_NONE, P_none },
		/* ED */{ INST_Iin, O_eAX, O_DX, O_NONE, P_oso },
		/* EE */{ INST_Iout, O_DX, O_AL, O_NONE, P_none },
		/* EF */{ INST_Iout, O_DX, O_eAX, O_NONE, P_oso },
		/* F0 */{ INST_Ilock, O_NONE, O_NONE, O_NONE, P_none },
		/* F1 */{ INST_Iint1, O_NONE, O_NONE, O_NONE, P_none },
		/* F2 */{ INST_Irepne, O_NONE, O_NONE, O_NONE, P_none },
		/* F3 */{ INST_Irep, O_NONE, O_NONE, O_NONE, P_none },
		/* F4 */{ INST_Ihlt, O_NONE, O_NONE, O_NONE, P_none },
		/* F5 */{ INST_Icmc, O_NONE, O_NONE, O_NONE, P_none },
		/* F6 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_F6__REG },
		/* F7 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_F7__REG },
		/* F8 */{ INST_Iclc, O_NONE, O_NONE, O_NONE, P_none },
		/* F9 */{ INST_Istc, O_NONE, O_NONE, O_NONE, P_none },
		/* FA */{ INST_Icli, O_NONE, O_NONE, O_NONE, P_none },
		/* FB */{ INST_Isti, O_NONE, O_NONE, O_NONE, P_none },
		/* FC */{ INST_Icld, O_NONE, O_NONE, O_NONE, P_none },
		/* FD */{ INST_Istd, O_NONE, O_NONE, O_NONE, P_none },
		/* FE */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_FE__REG },
		/* FF */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_FF__REG },
	};

	static INST_ENTRY_T    __inst__1byte__op_60__osize[3] =
	{
		/* 00 */{ INST_Ipusha, O_NONE, O_NONE, O_NONE, P_inv64 | P_oso },
		/* 01 */{ INST_Ipushad, O_NONE, O_NONE, O_NONE, P_inv64 | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_61__osize[3] =
	{
		/* 00 */{ INST_Ipopa, O_NONE, O_NONE, O_NONE, P_inv64 | P_oso },
		/* 01 */{ INST_Ipopad, O_NONE, O_NONE, O_NONE, P_inv64 | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_63__mode[3] =
	{
		/* 00 */{ INST_Iarpl, O_Ew, O_Gw, O_NONE, P_inv64 | P_aso },
		/* 01 */{ INST_Iarpl, O_Ew, O_Gw, O_NONE, P_inv64 | P_aso },
		/* 02 */{ INST_Imovsxd, O_Gv, O_Ed, O_NONE, P_c2 | P_aso | P_oso | P_rexw | P_rexx | P_rexr | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_6d__osize[3] =
	{
		/* 00 */{ INST_Iinsw, O_NONE, O_NONE, O_NONE, P_oso },
		/* 01 */{ INST_Iinsd, O_NONE, O_NONE, O_NONE, P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_6f__osize[3] =
	{
		/* 00 */{ INST_Ioutsw, O_NONE, O_NONE, O_NONE, P_oso },
		/* 01 */{ INST_Ioutsd, O_NONE, O_NONE, O_NONE, P_oso },
		/* 02 */{ INST_Ioutsq, O_NONE, O_NONE, O_NONE, P_oso },
	};

	static INST_ENTRY_T    __inst__1byte__op_80__reg[8] =
	{
		/* 00 */{ INST_Iadd, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ior, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iadc, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Isbb, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iand, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Isub, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ixor, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Icmp, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_81__reg[8] =
	{
		/* 00 */{ INST_Iadd, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ior, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iadc, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Isbb, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iand, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Isub, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ixor, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Icmp, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_82__reg[8] =
	{
		/* 00 */{ INST_Iadd, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ior, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iadc, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Isbb, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iand, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Isub, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ixor, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Icmp, O_Eb, O_Ib, O_NONE, P_c1 | P_inv64 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_83__reg[8] =
	{
		/* 00 */{ INST_Iadd, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ior, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iadc, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Isbb, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iand, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Isub, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ixor, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Icmp, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_8f__reg[8] =
	{
		/* 00 */{ INST_Ipop, O_Ev, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_98__osize[3] =
	{
		/* 00 */{ INST_Icbw, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 01 */{ INST_Icwde, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 02 */{ INST_Icdqe, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_99__osize[3] =
	{
		/* 00 */{ INST_Icwd, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 01 */{ INST_Icdq, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 02 */{ INST_Icqo, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_9c__mode[3] =
	{
		/* 00 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9C__MODE__OP_00__OSIZE },
		/* 01 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9C__MODE__OP_01__OSIZE },
		/* 02 */{ INST_Ipushfq, O_NONE, O_NONE, O_NONE, P_def64 | P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_9c__mode__op_00__osize[3] =
	{
		/* 00 */{ INST_Ipushfw, O_NONE, O_NONE, O_NONE, P_def64 | P_oso },
		/* 01 */{ INST_Ipushfd, O_NONE, O_NONE, O_NONE, P_def64 | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_9c__mode__op_01__osize[3] =
	{
		/* 00 */{ INST_Ipushfw, O_NONE, O_NONE, O_NONE, P_def64 | P_oso },
		/* 01 */{ INST_Ipushfd, O_NONE, O_NONE, O_NONE, P_def64 | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_9d__mode[3] =
	{
		/* 00 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9D__MODE__OP_00__OSIZE },
		/* 01 */{ INST_Igrp_osize, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_9D__MODE__OP_01__OSIZE },
		/* 02 */{ INST_Ipopfq, O_NONE, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
	};

	static INST_ENTRY_T    __inst__1byte__op_9d__mode__op_00__osize[3] =
	{
		/* 00 */{ INST_Ipopfw, O_NONE, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
		/* 01 */{ INST_Ipopfd, O_NONE, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_9d__mode__op_01__osize[3] =
	{
		/* 00 */{ INST_Ipopfw, O_NONE, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
		/* 01 */{ INST_Ipopfd, O_NONE, O_NONE, O_NONE, P_def64 | P_depM | P_oso },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_a5__osize[3] =
	{
		/* 00 */{ INST_Imovsw, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 01 */{ INST_Imovsd, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 02 */{ INST_Imovsq, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_a7__osize[3] =
	{
		/* 00 */{ INST_Icmpsw, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 01 */{ INST_Icmpsd, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 02 */{ INST_Icmpsq, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_ab__osize[3] =
	{
		/* 00 */{ INST_Istosw, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 01 */{ INST_Istosd, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 02 */{ INST_Istosq, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_ad__osize[3] =
	{
		/* 00 */{ INST_Ilodsw, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 01 */{ INST_Ilodsd, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
		/* 02 */{ INST_Ilodsq, O_NONE, O_NONE, O_NONE, P_ImpAddr | P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_ae__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_AE__MOD__OP_00__REG },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_ae__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifxsave, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifxrstor, O_M, O_NONE, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_af__osize[3] =
	{
		/* 00 */{ INST_Iscasw, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 01 */{ INST_Iscasd, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 02 */{ INST_Iscasq, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_c0__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_c1__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Ev, O_Ib, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_c6__reg[8] =
	{
		/* 00 */{ INST_Imov, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_c7__reg[8] =
	{
		/* 00 */{ INST_Imov, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_cf__osize[3] =
	{
		/* 00 */{ INST_Iiretw, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 01 */{ INST_Iiretd, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
		/* 02 */{ INST_Iiretq, O_NONE, O_NONE, O_NONE, P_oso | P_rexw },
	};

	static INST_ENTRY_T    __inst__1byte__op_d0__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Eb, O_I1, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d1__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Ev, O_I1, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d2__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Eb, O_CL, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Eb, O_CL, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Eb, O_CL, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Eb, O_CL, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Eb, O_CL, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Eb, O_CL, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Eb, O_CL, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Eb, O_CL, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d3__reg[8] =
	{
		/* 00 */{ INST_Irol, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iror, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ircl, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ircr, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ishl, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ishr, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ishl, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Isar, O_Ev, O_CL, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d8__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D8__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D8__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_d8__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifadd, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifmul, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ifcom, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifcomp, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifsub, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifsubr, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifdiv, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifdivr, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d8__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifadd, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifadd, O_ST0, O_ST1, O_NONE, P_none },
		/* 02 */{ INST_Ifadd, O_ST0, O_ST2, O_NONE, P_none },
		/* 03 */{ INST_Ifadd, O_ST0, O_ST3, O_NONE, P_none },
		/* 04 */{ INST_Ifadd, O_ST0, O_ST4, O_NONE, P_none },
		/* 05 */{ INST_Ifadd, O_ST0, O_ST5, O_NONE, P_none },
		/* 06 */{ INST_Ifadd, O_ST0, O_ST6, O_NONE, P_none },
		/* 07 */{ INST_Ifadd, O_ST0, O_ST7, O_NONE, P_none },
		/* 08 */{ INST_Ifmul, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifmul, O_ST0, O_ST1, O_NONE, P_none },
		/* 0A */{ INST_Ifmul, O_ST0, O_ST2, O_NONE, P_none },
		/* 0B */{ INST_Ifmul, O_ST0, O_ST3, O_NONE, P_none },
		/* 0C */{ INST_Ifmul, O_ST0, O_ST4, O_NONE, P_none },
		/* 0D */{ INST_Ifmul, O_ST0, O_ST5, O_NONE, P_none },
		/* 0E */{ INST_Ifmul, O_ST0, O_ST6, O_NONE, P_none },
		/* 0F */{ INST_Ifmul, O_ST0, O_ST7, O_NONE, P_none },
		/* 10 */{ INST_Ifcom, O_ST0, O_ST0, O_NONE, P_none },
		/* 11 */{ INST_Ifcom, O_ST0, O_ST1, O_NONE, P_none },
		/* 12 */{ INST_Ifcom, O_ST0, O_ST2, O_NONE, P_none },
		/* 13 */{ INST_Ifcom, O_ST0, O_ST3, O_NONE, P_none },
		/* 14 */{ INST_Ifcom, O_ST0, O_ST4, O_NONE, P_none },
		/* 15 */{ INST_Ifcom, O_ST0, O_ST5, O_NONE, P_none },
		/* 16 */{ INST_Ifcom, O_ST0, O_ST6, O_NONE, P_none },
		/* 17 */{ INST_Ifcom, O_ST0, O_ST7, O_NONE, P_none },
		/* 18 */{ INST_Ifcomp, O_ST0, O_ST0, O_NONE, P_none },
		/* 19 */{ INST_Ifcomp, O_ST0, O_ST1, O_NONE, P_none },
		/* 1A */{ INST_Ifcomp, O_ST0, O_ST2, O_NONE, P_none },
		/* 1B */{ INST_Ifcomp, O_ST0, O_ST3, O_NONE, P_none },
		/* 1C */{ INST_Ifcomp, O_ST0, O_ST4, O_NONE, P_none },
		/* 1D */{ INST_Ifcomp, O_ST0, O_ST5, O_NONE, P_none },
		/* 1E */{ INST_Ifcomp, O_ST0, O_ST6, O_NONE, P_none },
		/* 1F */{ INST_Ifcomp, O_ST0, O_ST7, O_NONE, P_none },
		/* 20 */{ INST_Ifsub, O_ST0, O_ST0, O_NONE, P_none },
		/* 21 */{ INST_Ifsub, O_ST0, O_ST1, O_NONE, P_none },
		/* 22 */{ INST_Ifsub, O_ST0, O_ST2, O_NONE, P_none },
		/* 23 */{ INST_Ifsub, O_ST0, O_ST3, O_NONE, P_none },
		/* 24 */{ INST_Ifsub, O_ST0, O_ST4, O_NONE, P_none },
		/* 25 */{ INST_Ifsub, O_ST0, O_ST5, O_NONE, P_none },
		/* 26 */{ INST_Ifsub, O_ST0, O_ST6, O_NONE, P_none },
		/* 27 */{ INST_Ifsub, O_ST0, O_ST7, O_NONE, P_none },
		/* 28 */{ INST_Ifsubr, O_ST0, O_ST0, O_NONE, P_none },
		/* 29 */{ INST_Ifsubr, O_ST0, O_ST1, O_NONE, P_none },
		/* 2A */{ INST_Ifsubr, O_ST0, O_ST2, O_NONE, P_none },
		/* 2B */{ INST_Ifsubr, O_ST0, O_ST3, O_NONE, P_none },
		/* 2C */{ INST_Ifsubr, O_ST0, O_ST4, O_NONE, P_none },
		/* 2D */{ INST_Ifsubr, O_ST0, O_ST5, O_NONE, P_none },
		/* 2E */{ INST_Ifsubr, O_ST0, O_ST6, O_NONE, P_none },
		/* 2F */{ INST_Ifsubr, O_ST0, O_ST7, O_NONE, P_none },
		/* 30 */{ INST_Ifdiv, O_ST0, O_ST0, O_NONE, P_none },
		/* 31 */{ INST_Ifdiv, O_ST0, O_ST1, O_NONE, P_none },
		/* 32 */{ INST_Ifdiv, O_ST0, O_ST2, O_NONE, P_none },
		/* 33 */{ INST_Ifdiv, O_ST0, O_ST3, O_NONE, P_none },
		/* 34 */{ INST_Ifdiv, O_ST0, O_ST4, O_NONE, P_none },
		/* 35 */{ INST_Ifdiv, O_ST0, O_ST5, O_NONE, P_none },
		/* 36 */{ INST_Ifdiv, O_ST0, O_ST6, O_NONE, P_none },
		/* 37 */{ INST_Ifdiv, O_ST0, O_ST7, O_NONE, P_none },
		/* 38 */{ INST_Ifdivr, O_ST0, O_ST0, O_NONE, P_none },
		/* 39 */{ INST_Ifdivr, O_ST0, O_ST1, O_NONE, P_none },
		/* 3A */{ INST_Ifdivr, O_ST0, O_ST2, O_NONE, P_none },
		/* 3B */{ INST_Ifdivr, O_ST0, O_ST3, O_NONE, P_none },
		/* 3C */{ INST_Ifdivr, O_ST0, O_ST4, O_NONE, P_none },
		/* 3D */{ INST_Ifdivr, O_ST0, O_ST5, O_NONE, P_none },
		/* 3E */{ INST_Ifdivr, O_ST0, O_ST6, O_NONE, P_none },
		/* 3F */{ INST_Ifdivr, O_ST0, O_ST7, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_d9__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D9__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_D9__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_d9__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifld, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ifst, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifstp, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifldenv, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifldcw, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifnstenv, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifnstcw, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_d9__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifld, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifld, O_ST0, O_ST1, O_NONE, P_none },
		/* 02 */{ INST_Ifld, O_ST0, O_ST2, O_NONE, P_none },
		/* 03 */{ INST_Ifld, O_ST0, O_ST3, O_NONE, P_none },
		/* 04 */{ INST_Ifld, O_ST0, O_ST4, O_NONE, P_none },
		/* 05 */{ INST_Ifld, O_ST0, O_ST5, O_NONE, P_none },
		/* 06 */{ INST_Ifld, O_ST0, O_ST6, O_NONE, P_none },
		/* 07 */{ INST_Ifld, O_ST0, O_ST7, O_NONE, P_none },
		/* 08 */{ INST_Ifxch, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifxch, O_ST0, O_ST1, O_NONE, P_none },
		/* 0A */{ INST_Ifxch, O_ST0, O_ST2, O_NONE, P_none },
		/* 0B */{ INST_Ifxch, O_ST0, O_ST3, O_NONE, P_none },
		/* 0C */{ INST_Ifxch, O_ST0, O_ST4, O_NONE, P_none },
		/* 0D */{ INST_Ifxch, O_ST0, O_ST5, O_NONE, P_none },
		/* 0E */{ INST_Ifxch, O_ST0, O_ST6, O_NONE, P_none },
		/* 0F */{ INST_Ifxch, O_ST0, O_ST7, O_NONE, P_none },
		/* 10 */{ INST_Ifnop, O_NONE, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Ifstp1, O_ST0, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Ifstp1, O_ST1, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Ifstp1, O_ST2, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Ifstp1, O_ST3, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Ifstp1, O_ST4, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Ifstp1, O_ST5, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Ifstp1, O_ST6, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Ifstp1, O_ST7, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Ifchs, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iftst, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Ifxam, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Ifld1, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Ifldl2t, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Ifldl2e, O_NONE, O_NONE, O_NONE, P_none },
		/* 2B */{ INST_Ifldlpi, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Ifldlg2, O_NONE, O_NONE, O_NONE, P_none },
		/* 2D */{ INST_Ifldln2, O_NONE, O_NONE, O_NONE, P_none },
		/* 2E */{ INST_Ifldz, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Ifyl2x, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Ifptan, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Ifpatan, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Ifpxtract, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Ifprem1, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Ifdecstp, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Ifncstp, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Ifprem, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Ifyl2xp1, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Ifsqrt, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Ifsincos, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Ifrndint, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Ifscale, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Ifsin, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Ifcos, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_da__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DA__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DA__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_da__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifiadd, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifimul, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ificom, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ificomp, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifisub, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifisubr, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifidiv, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifidivr, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_da__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifcmovb, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifcmovb, O_ST0, O_ST1, O_NONE, P_none },
		/* 02 */{ INST_Ifcmovb, O_ST0, O_ST2, O_NONE, P_none },
		/* 03 */{ INST_Ifcmovb, O_ST0, O_ST3, O_NONE, P_none },
		/* 04 */{ INST_Ifcmovb, O_ST0, O_ST4, O_NONE, P_none },
		/* 05 */{ INST_Ifcmovb, O_ST0, O_ST5, O_NONE, P_none },
		/* 06 */{ INST_Ifcmovb, O_ST0, O_ST6, O_NONE, P_none },
		/* 07 */{ INST_Ifcmovb, O_ST0, O_ST7, O_NONE, P_none },
		/* 08 */{ INST_Ifcmove, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifcmove, O_ST0, O_ST1, O_NONE, P_none },
		/* 0A */{ INST_Ifcmove, O_ST0, O_ST2, O_NONE, P_none },
		/* 0B */{ INST_Ifcmove, O_ST0, O_ST3, O_NONE, P_none },
		/* 0C */{ INST_Ifcmove, O_ST0, O_ST4, O_NONE, P_none },
		/* 0D */{ INST_Ifcmove, O_ST0, O_ST5, O_NONE, P_none },
		/* 0E */{ INST_Ifcmove, O_ST0, O_ST6, O_NONE, P_none },
		/* 0F */{ INST_Ifcmove, O_ST0, O_ST7, O_NONE, P_none },
		/* 10 */{ INST_Ifcmovbe, O_ST0, O_ST0, O_NONE, P_none },
		/* 11 */{ INST_Ifcmovbe, O_ST0, O_ST1, O_NONE, P_none },
		/* 12 */{ INST_Ifcmovbe, O_ST0, O_ST2, O_NONE, P_none },
		/* 13 */{ INST_Ifcmovbe, O_ST0, O_ST3, O_NONE, P_none },
		/* 14 */{ INST_Ifcmovbe, O_ST0, O_ST4, O_NONE, P_none },
		/* 15 */{ INST_Ifcmovbe, O_ST0, O_ST5, O_NONE, P_none },
		/* 16 */{ INST_Ifcmovbe, O_ST0, O_ST6, O_NONE, P_none },
		/* 17 */{ INST_Ifcmovbe, O_ST0, O_ST7, O_NONE, P_none },
		/* 18 */{ INST_Ifcmovu, O_ST0, O_ST0, O_NONE, P_none },
		/* 19 */{ INST_Ifcmovu, O_ST0, O_ST1, O_NONE, P_none },
		/* 1A */{ INST_Ifcmovu, O_ST0, O_ST2, O_NONE, P_none },
		/* 1B */{ INST_Ifcmovu, O_ST0, O_ST3, O_NONE, P_none },
		/* 1C */{ INST_Ifcmovu, O_ST0, O_ST4, O_NONE, P_none },
		/* 1D */{ INST_Ifcmovu, O_ST0, O_ST5, O_NONE, P_none },
		/* 1E */{ INST_Ifcmovu, O_ST0, O_ST6, O_NONE, P_none },
		/* 1F */{ INST_Ifcmovu, O_ST0, O_ST7, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Ifucompp, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_db__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DB__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DB__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_db__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifild, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifisttp, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ifist, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifistp, O_Md, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Ifld, O_Mt, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Ifstp, O_Mt, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_db__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifcmovnb, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifcmovnb, O_ST0, O_ST1, O_NONE, P_none },
		/* 02 */{ INST_Ifcmovnb, O_ST0, O_ST2, O_NONE, P_none },
		/* 03 */{ INST_Ifcmovnb, O_ST0, O_ST3, O_NONE, P_none },
		/* 04 */{ INST_Ifcmovnb, O_ST0, O_ST4, O_NONE, P_none },
		/* 05 */{ INST_Ifcmovnb, O_ST0, O_ST5, O_NONE, P_none },
		/* 06 */{ INST_Ifcmovnb, O_ST0, O_ST6, O_NONE, P_none },
		/* 07 */{ INST_Ifcmovnb, O_ST0, O_ST7, O_NONE, P_none },
		/* 08 */{ INST_Ifcmovne, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifcmovne, O_ST0, O_ST1, O_NONE, P_none },
		/* 0A */{ INST_Ifcmovne, O_ST0, O_ST2, O_NONE, P_none },
		/* 0B */{ INST_Ifcmovne, O_ST0, O_ST3, O_NONE, P_none },
		/* 0C */{ INST_Ifcmovne, O_ST0, O_ST4, O_NONE, P_none },
		/* 0D */{ INST_Ifcmovne, O_ST0, O_ST5, O_NONE, P_none },
		/* 0E */{ INST_Ifcmovne, O_ST0, O_ST6, O_NONE, P_none },
		/* 0F */{ INST_Ifcmovne, O_ST0, O_ST7, O_NONE, P_none },
		/* 10 */{ INST_Ifcmovnbe, O_ST0, O_ST0, O_NONE, P_none },
		/* 11 */{ INST_Ifcmovnbe, O_ST0, O_ST1, O_NONE, P_none },
		/* 12 */{ INST_Ifcmovnbe, O_ST0, O_ST2, O_NONE, P_none },
		/* 13 */{ INST_Ifcmovnbe, O_ST0, O_ST3, O_NONE, P_none },
		/* 14 */{ INST_Ifcmovnbe, O_ST0, O_ST4, O_NONE, P_none },
		/* 15 */{ INST_Ifcmovnbe, O_ST0, O_ST5, O_NONE, P_none },
		/* 16 */{ INST_Ifcmovnbe, O_ST0, O_ST6, O_NONE, P_none },
		/* 17 */{ INST_Ifcmovnbe, O_ST0, O_ST7, O_NONE, P_none },
		/* 18 */{ INST_Ifcmovnu, O_ST0, O_ST0, O_NONE, P_none },
		/* 19 */{ INST_Ifcmovnu, O_ST0, O_ST1, O_NONE, P_none },
		/* 1A */{ INST_Ifcmovnu, O_ST0, O_ST2, O_NONE, P_none },
		/* 1B */{ INST_Ifcmovnu, O_ST0, O_ST3, O_NONE, P_none },
		/* 1C */{ INST_Ifcmovnu, O_ST0, O_ST4, O_NONE, P_none },
		/* 1D */{ INST_Ifcmovnu, O_ST0, O_ST5, O_NONE, P_none },
		/* 1E */{ INST_Ifcmovnu, O_ST0, O_ST6, O_NONE, P_none },
		/* 1F */{ INST_Ifcmovnu, O_ST0, O_ST7, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Ifclex, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Ifninit, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Ifucomi, O_ST0, O_ST0, O_NONE, P_none },
		/* 29 */{ INST_Ifucomi, O_ST0, O_ST1, O_NONE, P_none },
		/* 2A */{ INST_Ifucomi, O_ST0, O_ST2, O_NONE, P_none },
		/* 2B */{ INST_Ifucomi, O_ST0, O_ST3, O_NONE, P_none },
		/* 2C */{ INST_Ifucomi, O_ST0, O_ST4, O_NONE, P_none },
		/* 2D */{ INST_Ifucomi, O_ST0, O_ST5, O_NONE, P_none },
		/* 2E */{ INST_Ifucomi, O_ST0, O_ST6, O_NONE, P_none },
		/* 2F */{ INST_Ifucomi, O_ST0, O_ST7, O_NONE, P_none },
		/* 30 */{ INST_Ifcomi, O_ST0, O_ST0, O_NONE, P_none },
		/* 31 */{ INST_Ifcomi, O_ST0, O_ST1, O_NONE, P_none },
		/* 32 */{ INST_Ifcomi, O_ST0, O_ST2, O_NONE, P_none },
		/* 33 */{ INST_Ifcomi, O_ST0, O_ST3, O_NONE, P_none },
		/* 34 */{ INST_Ifcomi, O_ST0, O_ST4, O_NONE, P_none },
		/* 35 */{ INST_Ifcomi, O_ST0, O_ST5, O_NONE, P_none },
		/* 36 */{ INST_Ifcomi, O_ST0, O_ST6, O_NONE, P_none },
		/* 37 */{ INST_Ifcomi, O_ST0, O_ST7, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_dc__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DC__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DC__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_dc__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifadd, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifmul, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ifcom, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifcomp, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifsub, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifsubr, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifdiv, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifdivr, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_dc__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifadd, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifadd, O_ST1, O_ST0, O_NONE, P_none },
		/* 02 */{ INST_Ifadd, O_ST2, O_ST0, O_NONE, P_none },
		/* 03 */{ INST_Ifadd, O_ST3, O_ST0, O_NONE, P_none },
		/* 04 */{ INST_Ifadd, O_ST4, O_ST0, O_NONE, P_none },
		/* 05 */{ INST_Ifadd, O_ST5, O_ST0, O_NONE, P_none },
		/* 06 */{ INST_Ifadd, O_ST6, O_ST0, O_NONE, P_none },
		/* 07 */{ INST_Ifadd, O_ST7, O_ST0, O_NONE, P_none },
		/* 08 */{ INST_Ifmul, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifmul, O_ST1, O_ST0, O_NONE, P_none },
		/* 0A */{ INST_Ifmul, O_ST2, O_ST0, O_NONE, P_none },
		/* 0B */{ INST_Ifmul, O_ST3, O_ST0, O_NONE, P_none },
		/* 0C */{ INST_Ifmul, O_ST4, O_ST0, O_NONE, P_none },
		/* 0D */{ INST_Ifmul, O_ST5, O_ST0, O_NONE, P_none },
		/* 0E */{ INST_Ifmul, O_ST6, O_ST0, O_NONE, P_none },
		/* 0F */{ INST_Ifmul, O_ST7, O_ST0, O_NONE, P_none },
		/* 10 */{ INST_Ifcom2, O_ST0, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Ifcom2, O_ST1, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Ifcom2, O_ST2, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Ifcom2, O_ST3, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Ifcom2, O_ST4, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Ifcom2, O_ST5, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Ifcom2, O_ST6, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Ifcom2, O_ST7, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Ifcomp3, O_ST0, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Ifcomp3, O_ST1, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Ifcomp3, O_ST2, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Ifcomp3, O_ST3, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Ifcomp3, O_ST4, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Ifcomp3, O_ST5, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Ifcomp3, O_ST6, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Ifcomp3, O_ST7, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Ifsubr, O_ST0, O_ST0, O_NONE, P_none },
		/* 21 */{ INST_Ifsubr, O_ST1, O_ST0, O_NONE, P_none },
		/* 22 */{ INST_Ifsubr, O_ST2, O_ST0, O_NONE, P_none },
		/* 23 */{ INST_Ifsubr, O_ST3, O_ST0, O_NONE, P_none },
		/* 24 */{ INST_Ifsubr, O_ST4, O_ST0, O_NONE, P_none },
		/* 25 */{ INST_Ifsubr, O_ST5, O_ST0, O_NONE, P_none },
		/* 26 */{ INST_Ifsubr, O_ST6, O_ST0, O_NONE, P_none },
		/* 27 */{ INST_Ifsubr, O_ST7, O_ST0, O_NONE, P_none },
		/* 28 */{ INST_Ifsub, O_ST0, O_ST0, O_NONE, P_none },
		/* 29 */{ INST_Ifsub, O_ST1, O_ST0, O_NONE, P_none },
		/* 2A */{ INST_Ifsub, O_ST2, O_ST0, O_NONE, P_none },
		/* 2B */{ INST_Ifsub, O_ST3, O_ST0, O_NONE, P_none },
		/* 2C */{ INST_Ifsub, O_ST4, O_ST0, O_NONE, P_none },
		/* 2D */{ INST_Ifsub, O_ST5, O_ST0, O_NONE, P_none },
		/* 2E */{ INST_Ifsub, O_ST6, O_ST0, O_NONE, P_none },
		/* 2F */{ INST_Ifsub, O_ST7, O_ST0, O_NONE, P_none },
		/* 30 */{ INST_Ifdivr, O_ST0, O_ST0, O_NONE, P_none },
		/* 31 */{ INST_Ifdivr, O_ST1, O_ST0, O_NONE, P_none },
		/* 32 */{ INST_Ifdivr, O_ST2, O_ST0, O_NONE, P_none },
		/* 33 */{ INST_Ifdivr, O_ST3, O_ST0, O_NONE, P_none },
		/* 34 */{ INST_Ifdivr, O_ST4, O_ST0, O_NONE, P_none },
		/* 35 */{ INST_Ifdivr, O_ST5, O_ST0, O_NONE, P_none },
		/* 36 */{ INST_Ifdivr, O_ST6, O_ST0, O_NONE, P_none },
		/* 37 */{ INST_Ifdivr, O_ST7, O_ST0, O_NONE, P_none },
		/* 38 */{ INST_Ifdiv, O_ST0, O_ST0, O_NONE, P_none },
		/* 39 */{ INST_Ifdiv, O_ST1, O_ST0, O_NONE, P_none },
		/* 3A */{ INST_Ifdiv, O_ST2, O_ST0, O_NONE, P_none },
		/* 3B */{ INST_Ifdiv, O_ST3, O_ST0, O_NONE, P_none },
		/* 3C */{ INST_Ifdiv, O_ST4, O_ST0, O_NONE, P_none },
		/* 3D */{ INST_Ifdiv, O_ST5, O_ST0, O_NONE, P_none },
		/* 3E */{ INST_Ifdiv, O_ST6, O_ST0, O_NONE, P_none },
		/* 3F */{ INST_Ifdiv, O_ST7, O_ST0, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_dd__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DD__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DD__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_dd__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifld, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifisttp, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ifst, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifstp, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifrstor, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ifnsave, O_M, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifnstsw, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_dd__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Iffree, O_ST0, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iffree, O_ST1, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iffree, O_ST2, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iffree, O_ST3, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iffree, O_ST4, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iffree, O_ST5, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iffree, O_ST6, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iffree, O_ST7, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Ifxch4, O_ST0, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Ifxch4, O_ST1, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Ifxch4, O_ST2, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Ifxch4, O_ST3, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Ifxch4, O_ST4, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Ifxch4, O_ST5, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Ifxch4, O_ST6, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Ifxch4, O_ST7, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Ifst, O_ST0, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Ifst, O_ST1, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Ifst, O_ST2, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Ifst, O_ST3, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Ifst, O_ST4, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Ifst, O_ST5, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Ifst, O_ST6, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Ifst, O_ST7, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Ifstp, O_ST0, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Ifstp, O_ST1, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Ifstp, O_ST2, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Ifstp, O_ST3, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Ifstp, O_ST4, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Ifstp, O_ST5, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Ifstp, O_ST6, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Ifstp, O_ST7, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Ifucom, O_ST0, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Ifucom, O_ST1, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Ifucom, O_ST2, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Ifucom, O_ST3, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Ifucom, O_ST4, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Ifucom, O_ST5, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Ifucom, O_ST6, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Ifucom, O_ST7, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Ifucomp, O_ST0, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Ifucomp, O_ST1, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Ifucomp, O_ST2, O_NONE, O_NONE, P_none },
		/* 2B */{ INST_Ifucomp, O_ST3, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Ifucomp, O_ST4, O_NONE, O_NONE, P_none },
		/* 2D */{ INST_Ifucomp, O_ST5, O_NONE, O_NONE, P_none },
		/* 2E */{ INST_Ifucomp, O_ST6, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Ifucomp, O_ST7, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_de__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DE__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DE__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_de__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifiadd, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifimul, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ificom, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ificomp, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifisub, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifisubr, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifidiv, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifidivr, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_de__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Ifaddp, O_ST0, O_ST0, O_NONE, P_none },
		/* 01 */{ INST_Ifaddp, O_ST1, O_ST0, O_NONE, P_none },
		/* 02 */{ INST_Ifaddp, O_ST2, O_ST0, O_NONE, P_none },
		/* 03 */{ INST_Ifaddp, O_ST3, O_ST0, O_NONE, P_none },
		/* 04 */{ INST_Ifaddp, O_ST4, O_ST0, O_NONE, P_none },
		/* 05 */{ INST_Ifaddp, O_ST5, O_ST0, O_NONE, P_none },
		/* 06 */{ INST_Ifaddp, O_ST6, O_ST0, O_NONE, P_none },
		/* 07 */{ INST_Ifaddp, O_ST7, O_ST0, O_NONE, P_none },
		/* 08 */{ INST_Ifmulp, O_ST0, O_ST0, O_NONE, P_none },
		/* 09 */{ INST_Ifmulp, O_ST1, O_ST0, O_NONE, P_none },
		/* 0A */{ INST_Ifmulp, O_ST2, O_ST0, O_NONE, P_none },
		/* 0B */{ INST_Ifmulp, O_ST3, O_ST0, O_NONE, P_none },
		/* 0C */{ INST_Ifmulp, O_ST4, O_ST0, O_NONE, P_none },
		/* 0D */{ INST_Ifmulp, O_ST5, O_ST0, O_NONE, P_none },
		/* 0E */{ INST_Ifmulp, O_ST6, O_ST0, O_NONE, P_none },
		/* 0F */{ INST_Ifmulp, O_ST7, O_ST0, O_NONE, P_none },
		/* 10 */{ INST_Ifcomp5, O_ST0, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Ifcomp5, O_ST1, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Ifcomp5, O_ST2, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Ifcomp5, O_ST3, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Ifcomp5, O_ST4, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Ifcomp5, O_ST5, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Ifcomp5, O_ST6, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Ifcomp5, O_ST7, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Ifcompp, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Ifsubrp, O_ST0, O_ST0, O_NONE, P_none },
		/* 21 */{ INST_Ifsubrp, O_ST1, O_ST0, O_NONE, P_none },
		/* 22 */{ INST_Ifsubrp, O_ST2, O_ST0, O_NONE, P_none },
		/* 23 */{ INST_Ifsubrp, O_ST3, O_ST0, O_NONE, P_none },
		/* 24 */{ INST_Ifsubrp, O_ST4, O_ST0, O_NONE, P_none },
		/* 25 */{ INST_Ifsubrp, O_ST5, O_ST0, O_NONE, P_none },
		/* 26 */{ INST_Ifsubrp, O_ST6, O_ST0, O_NONE, P_none },
		/* 27 */{ INST_Ifsubrp, O_ST7, O_ST0, O_NONE, P_none },
		/* 28 */{ INST_Ifsubp, O_ST0, O_ST0, O_NONE, P_none },
		/* 29 */{ INST_Ifsubp, O_ST1, O_ST0, O_NONE, P_none },
		/* 2A */{ INST_Ifsubp, O_ST2, O_ST0, O_NONE, P_none },
		/* 2B */{ INST_Ifsubp, O_ST3, O_ST0, O_NONE, P_none },
		/* 2C */{ INST_Ifsubp, O_ST4, O_ST0, O_NONE, P_none },
		/* 2D */{ INST_Ifsubp, O_ST5, O_ST0, O_NONE, P_none },
		/* 2E */{ INST_Ifsubp, O_ST6, O_ST0, O_NONE, P_none },
		/* 2F */{ INST_Ifsubp, O_ST7, O_ST0, O_NONE, P_none },
		/* 30 */{ INST_Ifdivrp, O_ST0, O_ST0, O_NONE, P_none },
		/* 31 */{ INST_Ifdivrp, O_ST1, O_ST0, O_NONE, P_none },
		/* 32 */{ INST_Ifdivrp, O_ST2, O_ST0, O_NONE, P_none },
		/* 33 */{ INST_Ifdivrp, O_ST3, O_ST0, O_NONE, P_none },
		/* 34 */{ INST_Ifdivrp, O_ST4, O_ST0, O_NONE, P_none },
		/* 35 */{ INST_Ifdivrp, O_ST5, O_ST0, O_NONE, P_none },
		/* 36 */{ INST_Ifdivrp, O_ST6, O_ST0, O_NONE, P_none },
		/* 37 */{ INST_Ifdivrp, O_ST7, O_ST0, O_NONE, P_none },
		/* 38 */{ INST_Ifdivp, O_ST0, O_ST0, O_NONE, P_none },
		/* 39 */{ INST_Ifdivp, O_ST1, O_ST0, O_NONE, P_none },
		/* 3A */{ INST_Ifdivp, O_ST2, O_ST0, O_NONE, P_none },
		/* 3B */{ INST_Ifdivp, O_ST3, O_ST0, O_NONE, P_none },
		/* 3C */{ INST_Ifdivp, O_ST4, O_ST0, O_NONE, P_none },
		/* 3D */{ INST_Ifdivp, O_ST5, O_ST0, O_NONE, P_none },
		/* 3E */{ INST_Ifdivp, O_ST6, O_ST0, O_NONE, P_none },
		/* 3F */{ INST_Ifdivp, O_ST7, O_ST0, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_df__mod[2] =
	{
		/* 00 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DF__MOD__OP_00__REG },
		/* 01 */{ INST_Igrp_x87, O_NONE, O_NONE, O_NONE, INST__1BYTE__OP_DF__MOD__OP_01__X87 },
	};

	static INST_ENTRY_T    __inst__1byte__op_df__mod__op_00__reg[8] =
	{
		/* 00 */{ INST_Ifild, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Ifisttp, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Ifist, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ifistp, O_Mw, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ifbld, O_Mt, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ifild, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ifbstp, O_Mt, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Ifistp, O_Mq, O_NONE, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_df__mod__op_01__x87[64] =
	{
		/* 00 */{ INST_Iffreep, O_ST0, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iffreep, O_ST1, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iffreep, O_ST2, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iffreep, O_ST3, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iffreep, O_ST4, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iffreep, O_ST5, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iffreep, O_ST6, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iffreep, O_ST7, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Ifxch7, O_ST0, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Ifxch7, O_ST1, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Ifxch7, O_ST2, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Ifxch7, O_ST3, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Ifxch7, O_ST4, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Ifxch7, O_ST5, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Ifxch7, O_ST6, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Ifxch7, O_ST7, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Ifstp8, O_ST0, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Ifstp8, O_ST1, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Ifstp8, O_ST2, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Ifstp8, O_ST3, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Ifstp8, O_ST4, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Ifstp8, O_ST5, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Ifstp8, O_ST6, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Ifstp8, O_ST7, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Ifstp9, O_ST0, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Ifstp9, O_ST1, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Ifstp9, O_ST2, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Ifstp9, O_ST3, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Ifstp9, O_ST4, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Ifstp9, O_ST5, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Ifstp9, O_ST6, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Ifstp9, O_ST7, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Ifnstsw, O_AX, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Ifucomip, O_ST0, O_ST0, O_NONE, P_none },
		/* 29 */{ INST_Ifucomip, O_ST0, O_ST1, O_NONE, P_none },
		/* 2A */{ INST_Ifucomip, O_ST0, O_ST2, O_NONE, P_none },
		/* 2B */{ INST_Ifucomip, O_ST0, O_ST3, O_NONE, P_none },
		/* 2C */{ INST_Ifucomip, O_ST0, O_ST4, O_NONE, P_none },
		/* 2D */{ INST_Ifucomip, O_ST0, O_ST5, O_NONE, P_none },
		/* 2E */{ INST_Ifucomip, O_ST0, O_ST6, O_NONE, P_none },
		/* 2F */{ INST_Ifucomip, O_ST0, O_ST7, O_NONE, P_none },
		/* 30 */{ INST_Ifcomip, O_ST0, O_ST0, O_NONE, P_none },
		/* 31 */{ INST_Ifcomip, O_ST0, O_ST1, O_NONE, P_none },
		/* 32 */{ INST_Ifcomip, O_ST0, O_ST2, O_NONE, P_none },
		/* 33 */{ INST_Ifcomip, O_ST0, O_ST3, O_NONE, P_none },
		/* 34 */{ INST_Ifcomip, O_ST0, O_ST4, O_NONE, P_none },
		/* 35 */{ INST_Ifcomip, O_ST0, O_ST5, O_NONE, P_none },
		/* 36 */{ INST_Ifcomip, O_ST0, O_ST6, O_NONE, P_none },
		/* 37 */{ INST_Ifcomip, O_ST0, O_ST7, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_e3__asize[3] =
	{
		/* 00 */{ INST_Ijcxz, O_Jb, O_NONE, O_NONE, P_aso },
		/* 01 */{ INST_Ijecxz, O_Jb, O_NONE, O_NONE, P_aso },
		/* 02 */{ INST_Ijrcxz, O_Jb, O_NONE, O_NONE, P_aso },
	};

	static INST_ENTRY_T    __inst__1byte__op_f6__reg[8] =
	{
		/* 00 */{ INST_Itest, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Itest, O_Eb, O_Ib, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Inot, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ineg, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Imul, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Iimul, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Idiv, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Iidiv, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_f7__reg[8] =
	{
		/* 00 */{ INST_Itest, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Itest, O_Ev, O_Iz, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Inot, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Ineg, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Imul, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Iimul, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Idiv, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Iidiv, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__1byte__op_fe__reg[8] =
	{
		/* 00 */{ INST_Iinc, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Idec, O_Eb, O_NONE, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__1byte__op_ff__reg[8] =
	{
		/* 00 */{ INST_Iinc, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 01 */{ INST_Idec, O_Ev, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 02 */{ INST_Icall, O_Ev, O_NONE, O_NONE, P_c1 | P_def64 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 03 */{ INST_Icall, O_Ep, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 04 */{ INST_Ijmp, O_Ev, O_NONE, O_NONE, P_c1 | P_def64 | P_depM | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 05 */{ INST_Ijmp, O_Ep, O_NONE, O_NONE, P_c1 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 06 */{ INST_Ipush, O_Ev, O_NONE, O_NONE, P_c1 | P_def64 | P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__3dnow[256] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 11 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 12 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 13 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 40 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 41 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 42 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 43 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 44 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 45 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 46 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 47 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 48 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 49 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 50 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 51 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 52 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 53 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 54 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 55 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 56 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 57 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 58 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 59 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 60 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 61 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 62 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 63 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 64 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 65 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 66 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 67 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 68 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 69 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 70 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 71 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 72 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 73 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 74 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 75 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 76 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 77 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 80 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 81 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 82 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 83 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 84 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 85 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 86 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 87 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 88 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 89 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 90 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 91 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 92 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 93 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 94 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 95 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 96 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 97 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 98 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 99 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* ED */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f[256] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Imovupd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 11 */{ INST_Imovupd, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 12 */{ INST_Imovlpd, O_V, O_M, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 13 */{ INST_Imovlpd, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 14 */{ INST_Iunpcklpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 15 */{ INST_Iunpckhpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 16 */{ INST_Imovhpd, O_V, O_M, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 17 */{ INST_Imovhpd, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Imovapd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 29 */{ INST_Imovapd, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2A */{ INST_Icvtpi2pd, O_V, O_Q, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2B */{ INST_Imovntpd, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2C */{ INST_Icvttpd2pi, O_P, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2D */{ INST_Icvtpd2pi, O_P, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2E */{ INST_Iucomisd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 2F */{ INST_Icomisd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 40 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 41 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 42 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 43 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 44 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 45 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 46 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 47 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 48 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 49 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 50 */{ INST_Imovmskpd, O_Gd, O_VR, O_NONE, P_oso | P_rexr | P_rexb },
		/* 51 */{ INST_Isqrtpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 52 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 53 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 54 */{ INST_Iandpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 55 */{ INST_Iandnpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 56 */{ INST_Iorpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 57 */{ INST_Ixorpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 58 */{ INST_Iaddpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 59 */{ INST_Imulpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5A */{ INST_Icvtpd2ps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5B */{ INST_Icvtps2dq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5C */{ INST_Isubpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5D */{ INST_Iminpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5E */{ INST_Idivpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5F */{ INST_Imaxpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 60 */{ INST_Ipunpcklbw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 61 */{ INST_Ipunpcklwd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 62 */{ INST_Ipunpckldq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 63 */{ INST_Ipacksswb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 64 */{ INST_Ipcmpgtb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 65 */{ INST_Ipcmpgtw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 66 */{ INST_Ipcmpgtd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 67 */{ INST_Ipackuswb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 68 */{ INST_Ipunpckhbw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 69 */{ INST_Ipunpckhwd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6A */{ INST_Ipunpckhdq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6B */{ INST_Ipackssdw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6C */{ INST_Ipunpcklqdq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6D */{ INST_Ipunpckhqdq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 6E */{ INST_Imovd, O_V, O_Ex, O_NONE, P_c2 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 6F */{ INST_Imovqa, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 70 */{ INST_Ipshufd, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* 71 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__PFX_SSE66__0F__OP_71__REG },
		/* 72 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__PFX_SSE66__0F__OP_72__REG },
		/* 73 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__PFX_SSE66__0F__OP_73__REG },
		/* 74 */{ INST_Ipcmpeqb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 75 */{ INST_Ipcmpeqw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 76 */{ INST_Ipcmpeqd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 77 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Ihaddpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 7D */{ INST_Ihsubpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 7E */{ INST_Imovd, O_Ex, O_V, O_NONE, P_c1 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 7F */{ INST_Imovdqa, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 80 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 81 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 82 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 83 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 84 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 85 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 86 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 87 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 88 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 89 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 90 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 91 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 92 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 93 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 94 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 95 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 96 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 97 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 98 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 99 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C0 */{ INST_Ixadd, O_Eb, O_Gb, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C1 */{ INST_Ixadd, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C2 */{ INST_Icmppd, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C4 */{ INST_Ipinsrw, O_V, O_Ew, O_Ib, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C5 */{ INST_Ipextrw, O_Gd, O_VR, O_Ib, P_aso | P_rexr | P_rexb },
		/* C6 */{ INST_Ishufpd, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C7 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__PFX_SSE66__0F__OP_C7__REG },
		/* C8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D0 */{ INST_Iaddsubpd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D1 */{ INST_Ipsrlw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D2 */{ INST_Ipsrld, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D3 */{ INST_Ipsrlq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D4 */{ INST_Ipaddq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D5 */{ INST_Ipmullw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D6 */{ INST_Imovq, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D7 */{ INST_Ipmovmskb, O_Gd, O_VR, O_NONE, P_rexr | P_rexb },
		/* D8 */{ INST_Ipsubusb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D9 */{ INST_Ipsubusw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DA */{ INST_Ipminub, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DB */{ INST_Ipand, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DC */{ INST_Ipsubusb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DD */{ INST_Ipunpckhbw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DE */{ INST_Ipmaxub, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* DF */{ INST_Ipandn, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E0 */{ INST_Ipavgb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E1 */{ INST_Ipsraw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E2 */{ INST_Ipsrad, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E3 */{ INST_Ipavgw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E4 */{ INST_Ipmulhuw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E5 */{ INST_Ipmulhw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E6 */{ INST_Icvttpd2dq, O_V, O_W, O_NONE, P_none },
		/* E7 */{ INST_Imovntdq, O_M, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E8 */{ INST_Ipsubsb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E9 */{ INST_Ipsubsw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EA */{ INST_Ipminsw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EB */{ INST_Ipor, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EC */{ INST_Ipaddsb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* ED */{ INST_Ipaddsw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EE */{ INST_Ipmaxsw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* EF */{ INST_Ipxor, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F1 */{ INST_Ipsllw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F2 */{ INST_Ipslld, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F3 */{ INST_Ipsllq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F4 */{ INST_Ipmuludq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F5 */{ INST_Ipmaddwd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F6 */{ INST_Ipsadbw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F7 */{ INST_Imaskmovq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F8 */{ INST_Ipsubb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F9 */{ INST_Ipsubw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FA */{ INST_Ipsubd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FB */{ INST_Ipsubq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FC */{ INST_Ipaddb, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FD */{ INST_Ipaddw, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* FE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f__op_71__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrlw, O_VR, O_Ib, O_NONE, P_rexb },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ipsraw, O_VR, O_Ib, O_NONE, P_rexb },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipsllw, O_VR, O_Ib, O_NONE, P_rexb },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f__op_72__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrld, O_VR, O_Ib, O_NONE, P_rexb },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Ipsrad, O_VR, O_Ib, O_NONE, P_rexb },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipslld, O_VR, O_Ib, O_NONE, P_rexb },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f__op_73__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Ipsrlq, O_VR, O_Ib, O_NONE, P_rexb },
		/* 03 */{ INST_Ipsrldq, O_VR, O_Ib, O_NONE, P_rexb },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Ipsllq, O_VR, O_Ib, O_NONE, P_rexb },
		/* 07 */{ INST_Ipslldq, O_VR, O_Ib, O_NONE, P_rexb },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f__op_c7__reg[8] =
	{
		/* 00 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__PFX_SSE66__0F__OP_C7__REG__OP_00__VENDOR },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_sse66__0f__op_c7__reg__op_00__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmclear, O_Mq, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
	};

	static INST_ENTRY_T    __inst__pfx_ssef2__0f[256] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Imovsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 11 */{ INST_Imovsd, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 12 */{ INST_Imovddup, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 13 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 17 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Icvtsi2sd, O_V, O_Ex, O_NONE, P_c2 | P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* 2B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Icvttsd2si, O_Gvw, O_W, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 2D */{ INST_Icvtsd2si, O_Gvw, O_W, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 40 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 41 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 42 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 43 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 44 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 45 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 46 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 47 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 48 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 49 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 50 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 51 */{ INST_Isqrtsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 52 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 53 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 54 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 55 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 56 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 57 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 58 */{ INST_Iaddsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 59 */{ INST_Imulsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5A */{ INST_Icvtsd2ss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 5C */{ INST_Isubsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5D */{ INST_Iminsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5E */{ INST_Idivsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5F */{ INST_Imaxsd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 60 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 61 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 62 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 63 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 64 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 65 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 66 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 67 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 68 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 69 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 70 */{ INST_Ipshuflw, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* 71 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 72 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 73 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 74 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 75 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 76 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 77 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Ihaddps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 7D */{ INST_Ihsubps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 7E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 80 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 81 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 82 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 83 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 84 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 85 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 86 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 87 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 88 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 89 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 90 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 91 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 92 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 93 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 94 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 95 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 96 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 97 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 98 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 99 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C0 */{ INST_Ixadd, O_Eb, O_Gb, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C1 */{ INST_Ixadd, O_Ev, O_Gv, O_NONE, P_aso | P_oso | P_rexr | P_rexx | P_rexb },
		/* C2 */{ INST_Icmpsd, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D0 */{ INST_Iaddsubps, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* D1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D6 */{ INST_Imovdq2q, O_P, O_VR, O_NONE, P_aso | P_rexb },
		/* D7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E6 */{ INST_Icvtpd2dq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* ED */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F0 */{ INST_Ilddqu, O_V, O_M, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* F1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_ssef3__0f[256] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 08 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 09 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 0F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 10 */{ INST_Imovss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 11 */{ INST_Imovss, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 12 */{ INST_Imovsldup, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 13 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 14 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 15 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 16 */{ INST_Imovshdup, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 17 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 18 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 19 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 1F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 20 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 21 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 22 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 23 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 24 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 25 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 26 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 27 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 28 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 29 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2A */{ INST_Icvtsi2ss, O_V, O_Ex, O_NONE, P_c2 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 2B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2C */{ INST_Icvttss2si, O_Gvw, O_W, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 2D */{ INST_Icvtss2si, O_Gvw, O_W, O_NONE, P_c1 | P_aso | P_rexr | P_rexx | P_rexb },
		/* 2E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 2F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 30 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 31 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 32 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 33 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 34 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 35 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 36 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 37 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 38 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 39 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 3F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 40 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 41 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 42 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 43 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 44 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 45 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 46 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 47 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 48 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 49 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 4F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 50 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 51 */{ INST_Isqrtss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 52 */{ INST_Irsqrtss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 53 */{ INST_Ircpss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 54 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 55 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 56 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 57 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 58 */{ INST_Iaddss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 59 */{ INST_Imulss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5A */{ INST_Icvtss2sd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5B */{ INST_Icvttps2dq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5C */{ INST_Isubss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5D */{ INST_Iminss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5E */{ INST_Idivss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 5F */{ INST_Imaxss, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 60 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 61 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 62 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 63 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 64 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 65 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 66 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 67 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 68 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 69 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 6F */{ INST_Imovdqu, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 70 */{ INST_Ipshufhw, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* 71 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 72 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 73 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 74 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 75 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 76 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 77 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 78 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 79 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 7E */{ INST_Imovq, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 7F */{ INST_Imovdqu, O_W, O_V, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* 80 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 81 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 82 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 83 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 84 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 85 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 86 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 87 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 88 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 89 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 8F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 90 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 91 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 92 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 93 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 94 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 95 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 96 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 97 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 98 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 99 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9A */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9B */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9C */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9D */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9E */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 9F */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* A9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* AF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* B9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* BF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C0 */{ INST_Ixadd, O_Eb, O_Gb, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C1 */{ INST_Ixadd, O_Ev, O_Gv, O_NONE, P_aso | P_rexw | P_rexr | P_rexx | P_rexb },
		/* C2 */{ INST_Icmpss, O_V, O_W, O_Ib, P_aso | P_rexr | P_rexx | P_rexb },
		/* C3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C7 */{ INST_Igrp_reg, O_NONE, O_NONE, O_NONE, INST__PFX_SSEF3__0F__OP_C7__REG },
		/* C8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* C9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* CF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D6 */{ INST_Imovq2dq, O_V, O_PR, O_NONE, P_aso },
		/* D7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* D9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* DF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E6 */{ INST_Icvtdq2pd, O_V, O_W, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
		/* E7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* E9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* ED */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* EF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F0 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F1 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F2 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F3 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F4 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F5 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F6 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F7 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F8 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* F9 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FA */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FB */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FC */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FD */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FE */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* FF */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
	};

	static INST_ENTRY_T    __inst__pfx_ssef3__0f__op_c7__reg[8] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 02 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 03 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 04 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 05 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 06 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 07 */{ INST_Igrp_vendor, O_NONE, O_NONE, O_NONE, INST__PFX_SSEF3__0F__OP_C7__REG__OP_07__VENDOR },
	};

	static INST_ENTRY_T    __inst__pfx_ssef3__0f__op_c7__reg__op_07__vendor[2] =
	{
		/* 00 */{ INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none },
		/* 01 */{ INST_Ivmxon, O_Mq, O_NONE, O_NONE, P_aso | P_rexr | P_rexx | P_rexb },
	};

	INST_ENTRY_T * INST_list[] =
	{
		__inst__0f,
		__inst__0f__op_00__reg,
		__inst__0f__op_01__reg,
		__inst__0f__op_01__reg__op_00__mod,
		__inst__0f__op_01__reg__op_00__mod__op_01__rm,
		__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_01__vendor,
		__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_03__vendor,
		__inst__0f__op_01__reg__op_00__mod__op_01__rm__op_04__vendor,
		__inst__0f__op_01__reg__op_01__mod,
		__inst__0f__op_01__reg__op_01__mod__op_01__rm,
		__inst__0f__op_01__reg__op_02__mod,
		__inst__0f__op_01__reg__op_03__mod,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_00__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_01__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_02__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_03__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_04__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_05__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_06__vendor,
		__inst__0f__op_01__reg__op_03__mod__op_01__rm__op_07__vendor,
		__inst__0f__op_01__reg__op_04__mod,
		__inst__0f__op_01__reg__op_06__mod,
		__inst__0f__op_01__reg__op_07__mod,
		__inst__0f__op_01__reg__op_07__mod__op_01__rm,
		__inst__0f__op_01__reg__op_07__mod__op_01__rm__op_01__vendor,
		__inst__0f__op_0d__reg,
		__inst__0f__op_18__reg,
		__inst__0f__op_71__reg,
		__inst__0f__op_72__reg,
		__inst__0f__op_73__reg,
		__inst__0f__op_ae__reg,
		__inst__0f__op_ae__reg__op_05__mod,
		__inst__0f__op_ae__reg__op_05__mod__op_01__rm,
		__inst__0f__op_ae__reg__op_06__mod,
		__inst__0f__op_ae__reg__op_06__mod__op_01__rm,
		__inst__0f__op_ae__reg__op_07__mod,
		__inst__0f__op_ae__reg__op_07__mod__op_01__rm,
		__inst__0f__op_ba__reg,
		__inst__0f__op_c7__reg,
		__inst__0f__op_c7__reg__op_00__vendor,
		__inst__0f__op_c7__reg__op_07__vendor,
		__inst__0f__op_d9__mod,
		__inst__0f__op_d9__mod__op_01__x87,
		__inst__1byte,
		__inst__1byte__op_60__osize,
		__inst__1byte__op_61__osize,
		__inst__1byte__op_63__mode,
		__inst__1byte__op_6d__osize,
		__inst__1byte__op_6f__osize,
		__inst__1byte__op_80__reg,
		__inst__1byte__op_81__reg,
		__inst__1byte__op_82__reg,
		__inst__1byte__op_83__reg,
		__inst__1byte__op_8f__reg,
		__inst__1byte__op_98__osize,
		__inst__1byte__op_99__osize,
		__inst__1byte__op_9c__mode,
		__inst__1byte__op_9c__mode__op_00__osize,
		__inst__1byte__op_9c__mode__op_01__osize,
		__inst__1byte__op_9d__mode,
		__inst__1byte__op_9d__mode__op_00__osize,
		__inst__1byte__op_9d__mode__op_01__osize,
		__inst__1byte__op_a5__osize,
		__inst__1byte__op_a7__osize,
		__inst__1byte__op_ab__osize,
		__inst__1byte__op_ad__osize,
		__inst__1byte__op_ae__mod,
		__inst__1byte__op_ae__mod__op_00__reg,
		__inst__1byte__op_af__osize,
		__inst__1byte__op_c0__reg,
		__inst__1byte__op_c1__reg,
		__inst__1byte__op_c6__reg,
		__inst__1byte__op_c7__reg,
		__inst__1byte__op_cf__osize,
		__inst__1byte__op_d0__reg,
		__inst__1byte__op_d1__reg,
		__inst__1byte__op_d2__reg,
		__inst__1byte__op_d3__reg,
		__inst__1byte__op_d8__mod,
		__inst__1byte__op_d8__mod__op_00__reg,
		__inst__1byte__op_d8__mod__op_01__x87,
		__inst__1byte__op_d9__mod,
		__inst__1byte__op_d9__mod__op_00__reg,
		__inst__1byte__op_d9__mod__op_01__x87,
		__inst__1byte__op_da__mod,
		__inst__1byte__op_da__mod__op_00__reg,
		__inst__1byte__op_da__mod__op_01__x87,
		__inst__1byte__op_db__mod,
		__inst__1byte__op_db__mod__op_00__reg,
		__inst__1byte__op_db__mod__op_01__x87,
		__inst__1byte__op_dc__mod,
		__inst__1byte__op_dc__mod__op_00__reg,
		__inst__1byte__op_dc__mod__op_01__x87,
		__inst__1byte__op_dd__mod,
		__inst__1byte__op_dd__mod__op_00__reg,
		__inst__1byte__op_dd__mod__op_01__x87,
		__inst__1byte__op_de__mod,
		__inst__1byte__op_de__mod__op_00__reg,
		__inst__1byte__op_de__mod__op_01__x87,
		__inst__1byte__op_df__mod,
		__inst__1byte__op_df__mod__op_00__reg,
		__inst__1byte__op_df__mod__op_01__x87,
		__inst__1byte__op_e3__asize,
		__inst__1byte__op_f6__reg,
		__inst__1byte__op_f7__reg,
		__inst__1byte__op_fe__reg,
		__inst__1byte__op_ff__reg,
		__inst__3dnow,
		__inst__pfx_sse66__0f,
		__inst__pfx_sse66__0f__op_71__reg,
		__inst__pfx_sse66__0f__op_72__reg,
		__inst__pfx_sse66__0f__op_73__reg,
		__inst__pfx_sse66__0f__op_c7__reg,
		__inst__pfx_sse66__0f__op_c7__reg__op_00__vendor,
		__inst__pfx_ssef2__0f,
		__inst__pfx_ssef3__0f,
		__inst__pfx_ssef3__0f__op_c7__reg,
		__inst__pfx_ssef3__0f__op_c7__reg__op_07__vendor,
	};
	typedef int(*pPRINT_FUNC)(char *fmt, ...);

	/**
	* Dis-assembler action control variables
	*/
	UINT08	dsm_mode = 32;
	UINT08	dsm_vendor = VENDOR_AMD;
	UINT08	dsm_syn = SYN_INTEL;

	const char* _x86_reg_tbl[] =
	{
		"al", "cl", "dl", "bl",
		"ah", "ch", "dh", "bh",
		"spl", "bpl", "sil", "dil",
		"r8b", "r9b", "r10b", "r11b",
		"r12b", "r13b", "r14b", "r15b",

		"ax", "cx", "dx", "bx",
		"sp", "bp", "si", "di",
		"r8w", "r9w", "r10w", "r11w",
		"r12w", "r13W", "r14w", "r15w",

		"eax", "ecx", "edx", "ebx",
		"esp", "ebp", "esi", "edi",
		"r8d", "r9d", "r10d", "r11d",
		"r12d", "r13d", "r14d", "r15d",

		"rax", "rcx", "rdx", "rbx",
		"rsp", "rbp", "rsi", "rdi",
		"r8", "r9", "r10", "r11",
		"r12", "r13", "r14", "r15",

		"es", "cs", "ss", "ds",
		"fs", "gs",

		"cr0", "cr1", "cr2", "cr3",
		"cr4", "cr5", "cr6", "cr7",
		"cr8", "cr9", "cr10", "cr11",
		"cr12", "cr13", "cr14", "cr15",

		"dr0", "dr1", "dr2", "dr3",
		"dr4", "dr5", "dr6", "dr7",
		"dr8", "dr9", "dr10", "dr11",
		"dr12", "dr13", "dr14", "dr15",

		"mm0", "mm1", "mm2", "mm3",
		"mm4", "mm5", "mm6", "mm7",

		"st0", "st1", "st2", "st3",
		"st4", "st5", "st6", "st7",

		"xmm0", "xmm1", "xmm2", "xmm3",
		"xmm4", "xmm5", "xmm6", "xmm7",
		"xmm8", "xmm9", "xmm10", "xmm11",
		"xmm12", "xmm13", "xmm14", "xmm15",

		"rip"
	};

	const char* _x86_opcode_tbl[] =
	{
		"3dnow",
		"aaa",
		"aad",
		"aam",
		"aas",
		"adc",
		"add",
		"addpd",
		"addps",
		"addsd",
		"addss",
		"addsubpd",
		"addsubps",
		"and",
		"andpd",
		"andps",
		"andnpd",
		"andnps",
		"arpl",
		"movsxd",
		"bound",
		"bsf",
		"bsr",
		"bswap",
		"bt",
		"btc",
		"btr",
		"bts",
		"call",
		"cbw",
		"cwde",
		"cdqe",
		"clc",
		"cld",
		"clflush",
		"clgi",
		"cli",
		"clts",
		"cmc",
		"cmovo",
		"cmovno",
		"cmovb",
		"cmovae",
		"cmovz",
		"cmovnz",
		"cmovbe",
		"cmova",
		"cmovs",
		"cmovns",
		"cmovp",
		"cmovnp",
		"cmovl",
		"cmovge",
		"cmovle",
		"cmovg",
		"cmp",
		"cmppd",
		"cmpps",
		"cmpsb",
		"cmpsw",
		"cmpsd",
		"cmpsq",
		"cmpss",
		"cmpxchg",
		"cmpxchg8b",
		"comisd",
		"comiss",
		"cpuid",
		"cvtdq2pd",
		"cvtdq2ps",
		"cvtpd2dq",
		"cvtpd2pi",
		"cvtpd2ps",
		"cvtpi2ps",
		"cvtpi2pd",
		"cvtps2dq",
		"cvtps2pi",
		"cvtps2pd",
		"cvtsd2si",
		"cvtsd2ss",
		"cvtsi2ss",
		"cvtss2si",
		"cvtss2sd",
		"cvttpd2pi",
		"cvttpd2dq",
		"cvttps2dq",
		"cvttps2pi",
		"cvttsd2si",
		"cvtsi2sd",
		"cvttss2si",
		"cwd",
		"cdq",
		"cqo",
		"daa",
		"das",
		"dec",
		"div",
		"divpd",
		"divps",
		"divsd",
		"divss",
		"emms",
		"enter",
		"f2xm1",
		"fabs",
		"fadd",
		"faddp",
		"fbld",
		"fbstp",
		"fchs",
		"fclex",
		"fcmovb",
		"fcmove",
		"fcmovbe",
		"fcmovu",
		"fcmovnb",
		"fcmovne",
		"fcmovnbe",
		"fcmovnu",
		"fucomi",
		"fcom",
		"fcom2",
		"fcomp3",
		"fcomi",
		"fucomip",
		"fcomip",
		"fcomp",
		"fcomp5",
		"fcompp",
		"fcos",
		"fdecstp",
		"fdiv",
		"fdivp",
		"fdivr",
		"fdivrp",
		"femms",
		"ffree",
		"ffreep",
		"ficom",
		"ficomp",
		"fild",
		"fncstp",
		"fninit",
		"fiadd",
		"fidivr",
		"fidiv",
		"fisub",
		"fisubr",
		"fist",
		"fistp",
		"fisttp",
		"fld",
		"fld1",
		"fldl2t",
		"fldl2e",
		"fldlpi",
		"fldlg2",
		"fldln2",
		"fldz",
		"fldcw",
		"fldenv",
		"fmul",
		"fmulp",
		"fimul",
		"fnop",
		"fpatan",
		"fprem",
		"fprem1",
		"fptan",
		"frndint",
		"frstor",
		"fnsave",
		"fscale",
		"fsin",
		"fsincos",
		"fsqrt",
		"fstp",
		"fstp1",
		"fstp8",
		"fstp9",
		"fst",
		"fnstcw",
		"fnstenv",
		"fnstsw",
		"fsub",
		"fsubp",
		"fsubr",
		"fsubrp",
		"ftst",
		"fucom",
		"fucomp",
		"fucompp",
		"fxam",
		"fxch",
		"fxch4",
		"fxch7",
		"fxrstor",
		"fxsave",
		"fpxtract",
		"fyl2x",
		"fyl2xp1",
		"haddpd",
		"haddps",
		"hlt",
		"hsubpd",
		"hsubps",
		"idiv",
		"in",
		"imul",
		"inc",
		"insb",
		"insw",
		"insd",
		"int1",
		"int3",
		"int",
		"into",
		"invd",
		"invlpg",
		"invlpga",
		"iretw",
		"iretd",
		"iretq",
		"jo",
		"jno",
		"jb",
		"jae",
		"jz",
		"jnz",
		"jbe",
		"ja",
		"js",
		"jns",
		"jp",
		"jnp",
		"jl",
		"jge",
		"jle",
		"jg",
		"jcxz",
		"jecxz",
		"jrcxz",
		"jmp",
		"lahf",
		"lar",
		"lddqu",
		"ldmxcsr",
		"lds",
		"lea",
		"les",
		"lfs",
		"lgs",
		"lidt",
		"lss",
		"leave",
		"lfence",
		"lgdt",
		"lldt",
		"lmsw",
		"lock",
		"lodsb",
		"lodsw",
		"lodsd",
		"lodsq",
		"loopnz",
		"loope",
		"loop",
		"lsl",
		"ltr",
		"maskmovq",
		"maxpd",
		"maxps",
		"maxsd",
		"maxss",
		"mfence",
		"minpd",
		"minps",
		"minsd",
		"minss",
		"monitor",
		"mov",
		"movapd",
		"movaps",
		"movd",
		"movddup",
		"movdqa",
		"movdqu",
		"movdq2q",
		"movhpd",
		"movhps",
		"movlhps",
		"movlpd",
		"movlps",
		"movhlps",
		"movmskpd",
		"movmskps",
		"movntdq",
		"movnti",
		"movntpd",
		"movntps",
		"movntq",
		"movq",
		"movqa",
		"movq2dq",
		"movsb",
		"movsw",
		"movsd",
		"movsq",
		"movsldup",
		"movshdup",
		"movss",
		"movsx",
		"movupd",
		"movups",
		"movzx",
		"mul",
		"mulpd",
		"mulps",
		"mulsd",
		"mulss",
		"mwait",
		"neg",
		"nop",
		"not",
		"or",
		"orpd",
		"orps",
		"out",
		"outsb",
		"outsw",
		"outsd",
		"outsq",
		"packsswb",
		"packssdw",
		"packuswb",
		"paddb",
		"paddw",
		"paddq",
		"paddsb",
		"paddsw",
		"paddusb",
		"paddusw",
		"pand",
		"pandn",
		"pause",
		"pavgb",
		"pavgw",
		"pcmpeqb",
		"pcmpeqw",
		"pcmpeqd",
		"pcmpgtb",
		"pcmpgtw",
		"pcmpgtd",
		"pextrw",
		"pinsrw",
		"pmaddwd",
		"pmaxsw",
		"pmaxub",
		"pminsw",
		"pminub",
		"pmovmskb",
		"pmulhuw",
		"pmulhw",
		"pmullw",
		"pmuludq",
		"pop",
		"popa",
		"popad",
		"popfw",
		"popfd",
		"popfq",
		"por",
		"prefetch",
		"prefetchnta",
		"prefetcht0",
		"prefetcht1",
		"prefetcht2",
		"psadbw",
		"pshufd",
		"pshufhw",
		"pshuflw",
		"pshufw",
		"pslldq",
		"psllw",
		"pslld",
		"psllq",
		"psraw",
		"psrad",
		"psrlw",
		"psrld",
		"psrlq",
		"psrldq",
		"psubb",
		"psubw",
		"psubd",
		"psubq",
		"psubsb",
		"psubsw",
		"psubusb",
		"psubusw",
		"punpckhbw",
		"punpckhwd",
		"punpckhdq",
		"punpckhqdq",
		"punpcklbw",
		"punpcklwd",
		"punpckldq",
		"punpcklqdq",
		"pi2fw",
		"pi2fd",
		"pf2iw",
		"pf2id",
		"pfnacc",
		"pfpnacc",
		"pfcmpge",
		"pfmin",
		"pfrcp",
		"pfrsqrt",
		"pfsub",
		"pfadd",
		"pfcmpgt",
		"pfmax",
		"pfrcpit1",
		"pfrspit1",
		"pfsubr",
		"pfacc",
		"pfcmpeq",
		"pfmul",
		"pfrcpit2",
		"pmulhrw",
		"pswapd",
		"pavgusb",
		"push",
		"pusha",
		"pushad",
		"pushfw",
		"pushfd",
		"pushfq",
		"pxor",
		"rcl",
		"rcr",
		"rol",
		"ror",
		"rcpps",
		"rcpss",
		"rdmsr",
		"rdpmc",
		"rdtsc",
		"rdtscp",
		"repne",
		"rep",
		"ret",
		"retf",
		"rsm",
		"rsqrtps",
		"rsqrtss",
		"sahf",
		"sal",
		"salc",
		"sar",
		"shl",
		"shr",
		"sbb",
		"scasb",
		"scasw",
		"scasd",
		"scasq",
		"seto",
		"setno",
		"setb",
		"setnb",
		"setz",
		"setnz",
		"setbe",
		"seta",
		"sets",
		"setns",
		"setp",
		"setnp",
		"setl",
		"setge",
		"setle",
		"setg",
		"sfence",
		"sgdt",
		"shld",
		"shrd",
		"shufpd",
		"shufps",
		"sidt",
		"sldt",
		"smsw",
		"sqrtps",
		"sqrtpd",
		"sqrtsd",
		"sqrtss",
		"stc",
		"std",
		"stgi",
		"sti",
		"skinit",
		"stmxcsr",
		"stosb",
		"stosw",
		"stosd",
		"stosq",
		"str",
		"sub",
		"subpd",
		"subps",
		"subsd",
		"subss",
		"swapgs",
		"syscall",
		"sysenter",
		"sysexit",
		"sysret",
		"test",
		"ucomisd",
		"ucomiss",
		"ud2",
		"unpckhpd",
		"unpckhps",
		"unpcklps",
		"unpcklpd",
		"verr",
		"verw",
		"vmcall",
		"vmclear",
		"vmxon",
		"vmptrld",
		"vmptrst",
		"vmresume",
		"vmxoff",
		"vmrun",
		"vmmcall",
		"vmload",
		"vmsave",
		"wait",
		"wbinvd",
		"wrmsr",
		"xadd",
		"xchg",
		"xlatb",
		"xor",
		"xorpd",
		"xorps",
		"db",
		"invalid",
	};

	static INST_ENTRY_T ie_invalid = { INST_Iinvalid, O_NONE, O_NONE, O_NONE, P_none };
	static INST_ENTRY_T ie_pause = { INST_Ipause, O_NONE, O_NONE, O_NONE, P_none };
	static INST_ENTRY_T ie_nop = { INST_Inop, O_NONE, O_NONE, O_NONE, P_none };

	static int input_buff_hook(DSM_OP_T *pDsmOp)
	{
		int c;

		if (pDsmOp->pBuff < pDsmOp->pBuffEnd)
		{
			c = *pDsmOp->pBuff;
			pDsmOp->pBuff++;

			return c;
		}
		return -1;
	}

	static void _setInputHook(DSM_OP_T *pDsmOp, UINT08 *pBuf, size_t len)
	{
		pDsmOp->pfnHook = input_buff_hook;
		pDsmOp->pBuff = pBuf;
		pDsmOp->pBuffEnd = pBuf + len;

		pDsmOp->p_curr = 0;
		pDsmOp->p_fill = 0;
		pDsmOp->p_ctr = 0;
		pDsmOp->p_end = 0;
	}

	static UINT08 input_next(DSM_OP_T *pDsmOp)
	{
		int		c = -1;

		if (pDsmOp->p_curr != pDsmOp->p_fill)
		{
			c = pDsmOp->p_cache[++pDsmOp->p_curr];
		}
		else if (pDsmOp->p_end || ((c = pDsmOp->pfnHook(pDsmOp)) == -1))
		{
			pDsmOp->error = 1;
			pDsmOp->p_end = 1;
			return 0;
		}
		else
		{
			pDsmOp->p_curr = ++pDsmOp->p_fill;
			pDsmOp->p_cache[pDsmOp->p_fill] = c;
		}

		pDsmOp->p_sess[pDsmOp->p_ctr++] = c;

		return (UINT08)c;
	}

	static void input_back(DSM_OP_T *pDsmOp)
	{
		if (pDsmOp->p_ctr > 0)
		{
			--pDsmOp->p_curr;
			--pDsmOp->p_ctr;
		}
	}

	static UINT08 input_peek(DSM_OP_T *pDsmOp)
	{
		UINT08 r = input_next(pDsmOp);

		if (!pDsmOp->error)
			input_back(pDsmOp); /* Don't backup if there was an error */

		return r;
	}

	#if 0
	/* -----------------------------------------------------------------------------
	* input_move() - Move ahead n input bytes.
	* -----------------------------------------------------------------------------
	*/
	static void input_move(DSM_OP_T *pDsmOp, size_t n)
	{
		while (n--)
			input_next(pDsmOp);
	}
	#endif

	/*------------------------------------------------------------------------------
	*  input_uintN() - return uintN from source.
	*------------------------------------------------------------------------------
	*/
	static UINT08 input_uint8(DSM_OP_T *pDsmOp)
	{
		return input_next(pDsmOp);
	}

	static UINT16 input_uint16(DSM_OP_T *pDsmOp)
	{
		UINT16 r, ret;

		ret = input_next(pDsmOp);
		r = input_next(pDsmOp);

		return ret | (r << 8);
	}

	static UINT32 input_uint32(DSM_OP_T *pDsmOp)
	{
		UINT32 r, ret;

		ret = input_next(pDsmOp);
		r = input_next(pDsmOp);
		ret = ret | (r << 8);
		r = input_next(pDsmOp);
		ret = ret | (r << 16);
		r = input_next(pDsmOp);

		return ret | (r << 24);
	}

	static UINT64 input_uint64(DSM_OP_T *pDsmOp)
	{
		UINT64 r, ret;

		ret = input_next(pDsmOp);
		r = input_next(pDsmOp);
		ret = ret | (r << 8);
		r = input_next(pDsmOp);
		ret = ret | (r << 16);
		r = input_next(pDsmOp);
		ret = ret | (r << 24);
		r = input_next(pDsmOp);
		ret = ret | (r << 32);
		r = input_next(pDsmOp);
		ret = ret | (r << 40);
		r = input_next(pDsmOp);
		ret = ret | (r << 48);
		r = input_next(pDsmOp);

		return ret | (r << 56);
	}

	static int input_end(DSM_OP_T *pDsmOp)
	{
		return ((pDsmOp->p_curr == pDsmOp->p_fill) && pDsmOp->p_end);
	}

	static const char* dsm_lookup_opcode(INST_MNEMONIC_T code)
	{
		if (code < INST_Id3vil)
			return _x86_opcode_tbl[code];

		return NULL;
	}

	static int _getPrefix(DSM_OP_T *pDsmOp)
	{
		UINT32	havePfx = 1;
		UINT32	i;
		UINT08	curr;

		if (pDsmOp->error)
			return -1;

		for (i = 0; havePfx; i++)
		{
			input_next(pDsmOp);
			if (pDsmOp->error)
			{
				return -1;
			}
			curr = pDsmOp->p_cache[pDsmOp->p_curr];
			if (pDsmOp->dsmMode == 64/*64bit mode*/ && (curr & 0xF0) == 0x40)
			{
				pDsmOp->pfx_rex = curr;
			}
			else
			{
				switch (curr)
				{
				case 0x2E: {pDsmOp->pfx_seg = _R_CS; pDsmOp->pfx_rex = 0; } break;
				case 0x36: {pDsmOp->pfx_seg = _R_SS; pDsmOp->pfx_rex = 0; } break;
				case 0x3E: {pDsmOp->pfx_seg = _R_DS; pDsmOp->pfx_rex = 0; } break;
				case 0x26: {pDsmOp->pfx_seg = _R_ES; pDsmOp->pfx_rex = 0; } break;
				case 0x64: {pDsmOp->pfx_seg = _R_FS; pDsmOp->pfx_rex = 0; } break;
				case 0x65: {pDsmOp->pfx_seg = _R_GS; pDsmOp->pfx_rex = 0; } break;
				case 0x67: {pDsmOp->pfx_adr = 0x67; pDsmOp->pfx_rex = 0; } break;
				case 0xF0: {pDsmOp->pfx_lock = 0xF0; pDsmOp->pfx_rex = 0; } break;
				case 0x66:
					if (pDsmOp->pfx_insn)
						pDsmOp->pfx_insn = 0x66;
					pDsmOp->pfx_opr = 0x66;
					pDsmOp->pfx_rex = 0;
					break;
				case 0xF2:
					pDsmOp->pfx_insn = 0xF2;
					pDsmOp->pfx_repne = 0xF2;
					pDsmOp->pfx_rex = 0;
					break;
				case 0xF3:
					pDsmOp->pfx_insn = 0xF3;
					pDsmOp->pfx_rep = 0xF3;
					pDsmOp->pfx_repe = 0xF3;
					pDsmOp->pfx_rex = 0;
					break;
				default:
					havePfx = 0;
					break;
				}
			}
			if (MAX_INSN_LEN == (i + 1))
			{
				pDsmOp->error = 1;
				break;
			}
		}

		if (pDsmOp->error)
			return -1;

		input_back(pDsmOp);

		if (pDsmOp->dsmMode == 64)
		{
			pDsmOp->opr_mode = REX_W(pDsmOp->pfx_rex) ? 64 : ((pDsmOp->pfx_opr) ? 16 : 32);
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 32 : 64;
		}
		else if (pDsmOp->dsmMode == 32)
		{
			pDsmOp->opr_mode = (pDsmOp->pfx_opr) ? 16 : 32;
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 16 : 32;
		}
		else if (pDsmOp->dsmMode == 16)
		{
			pDsmOp->opr_mode = (pDsmOp->pfx_opr) ? 32 : 16;
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 32 : 16;
		}

		return 0;
	}

	static int _search_instruntion(DSM_OP_T *pDsmOp)
	{
		INST_ENTRY_T*	pEntry = NULL;
		INST_INDEX_T	tbl = INST__1BYTE;
		UINT08			peek;
		UINT08			did_peek = 0;
		UINT08			curr;
		UINT08			index;

		if (pDsmOp->error)
			return -1;

		input_next(pDsmOp);

		if (pDsmOp->error)
			return -1;

		curr = pDsmOp->p_cache[pDsmOp->p_curr];;


		/* resolve xchg, nop, pause crazyness */
		if (0x90 == curr)
		{
			if (!(pDsmOp->dsmMode == 64 && REX_B(pDsmOp->pfx_rex)))
			{
				if (pDsmOp->pfx_rep)
				{
					pDsmOp->pfx_rep = 0;
					pEntry = &ie_pause;
				}
				else
				{
					pEntry = &ie_nop;
				}
				goto FoundEntry;
			}
		}
		else
		{
			tbl = INST__1BYTE;
		}

		index = curr;

SearchEntry:
		pEntry = &INST_list[tbl][index];

		/* if mnemonic constant is a standard instruction constant
		* our search is over.
		*/

		if (pEntry->mnemonic < INST_Id3vil)
		{
			if (pEntry->mnemonic == INST_Iinvalid)
			{
				if (did_peek)
				{
					input_next(pDsmOp);
					if (pDsmOp->error)
						return -1;
				}
				goto FoundEntry;
			}
			goto FoundEntry;
		}

		tbl = static_cast<INST_INDEX_T>(pEntry->prefix);

		switch (pEntry->mnemonic)
		{
		case INST_Igrp_reg:
			peek = input_peek(pDsmOp);
			did_peek = 1;
			index = MODRM_REG(peek);
			break;

		case INST_Igrp_mod:
			peek = input_peek(pDsmOp);
			did_peek = 1;
			index = MODRM_MOD(peek);
			if (index == 3)
				index = INDX_11;
			else
				index = INDX_NOT_11;
			break;

		case INST_Igrp_rm:
			curr = input_next(pDsmOp);
			did_peek = 0;
			if (pDsmOp->error)
				return -1;
			index = MODRM_RM(curr);
			break;

		case INST_Igrp_x87:
			curr = input_next(pDsmOp);
			did_peek = 0;
			if (pDsmOp->error)
				return -1;
			index = curr - 0xC0;
			break;

		case INST_Igrp_osize:
			if (pDsmOp->opr_mode == 64)
				index = DMOD_64;
			else if (pDsmOp->opr_mode == 32)
				index = DMOD_32;
			else
				index = DMOD_16;
			break;

		case INST_Igrp_asize:
			if (pDsmOp->adr_mode == 64)
				index = DMOD_64;
			else if (pDsmOp->adr_mode == 32)
				index = DMOD_32;
			else
				index = DMOD_16;
			break;

		case INST_Igrp_mode:
			if (pDsmOp->dsmMode == 64)
				index = DMOD_64;
			else if (pDsmOp->dsmMode == 32)
				index = DMOD_32;
			else
				index = DMOD_16;
			break;

		case INST_Igrp_vendor:
			if (pDsmOp->vendor == VENDOR_INTEL)
				index = VENDOR_INTEL;
			else if (pDsmOp->vendor == VENDOR_AMD)
				index = VENDOR_AMD;
			else
			{
				printf("unrecognized vendor id\n");
				return -1;
			}
			break;

		case INST_Id3vil:
			printf("invalid instruction mnemonic constant Id3vil\n");
			return -1;

		default:
			printf("invalid instruction mnemonic constant\n");
			return -1;
		}

		goto SearchEntry;

FoundEntry:
		pDsmOp->pEntry = pEntry;
		pDsmOp->opcode = pDsmOp->pEntry->mnemonic;
		return 0;
	}

	static UINT32 resolve_operand_size(DSM_OP_T *pDsmOp, UINT32 sz)
	{
		switch (sz)
		{
		case SZ_V:   return (pDsmOp->opr_mode);
		case SZ_Z:   return (pDsmOp->opr_mode == 16) ? 16 : 32;
		case SZ_P:   return (pDsmOp->opr_mode == 16) ? SZ_WP : SZ_DP;
		case SZ_MDQ: return (pDsmOp->opr_mode == 16) ? 32 : pDsmOp->opr_mode;
		case SZ_RDQ: return (pDsmOp->opr_mode == 64) ? 64 : 32;
		}

		return sz;
	}

	static int resolve_mnemonic(DSM_OP_T *pDsmOp)
	{
		/* far/near flags */
		pDsmOp->br_far = 0;
		pDsmOp->br_near = 0;
		/* readjust operand sizes for call/jmp instrcutions */
		if (pDsmOp->opcode == INST_Icall || pDsmOp->opcode == INST_Ijmp)
		{
			/* WP: 16bit pointer */
			if (pDsmOp->operand[0].size == SZ_WP)
			{
				pDsmOp->operand[0].size = 16;
				pDsmOp->br_far = 1;
				pDsmOp->br_near = 0;
				/* DP: 32bit pointer */
			}
			else if (pDsmOp->operand[0].size == SZ_DP)
			{
				pDsmOp->operand[0].size = 32;
				pDsmOp->br_far = 1;
				pDsmOp->br_near = 0;
			}
			else
			{
				pDsmOp->br_far = 0;
				pDsmOp->br_near = 1;
			}
			/* resolve 3dnow weirdness. */
		}
		else if (pDsmOp->opcode == INST_I3dnow)
		{
			pDsmOp->opcode = INST_list[INST__3DNOW][pDsmOp->p_cache[pDsmOp->p_curr]].mnemonic;
		}

		/* SWAPGS is only valid in 64bits mode */
		if (pDsmOp->opcode == INST_Iswapgs && pDsmOp->dsmMode != 64)
		{
			pDsmOp->error = 1;
			return -1;
		}

		return 0;
	}

	/* -----------------------------------------------------------------------------
	* decode_a()- Decodes operands of the type seg:offset
	* -----------------------------------------------------------------------------
	*/
	static void decode_a(DSM_OP_T *pDsmOp, struct operand_t *op)
	{
		if (pDsmOp->opr_mode == 16)
		{
			/* seg16:off16 */
			op->type = _OP_PTR;
			op->size = 32;
			op->lval.ptr.off = input_uint16(pDsmOp);
			op->lval.ptr.seg = input_uint16(pDsmOp);
		}
		else
		{
			/* seg16:off32 */
			op->type = _OP_PTR;
			op->size = 48;
			op->lval.ptr.off = input_uint32(pDsmOp);
			op->lval.ptr.seg = input_uint16(pDsmOp);
		}
	}

	/* -----------------------------------------------------------------------------
	* decode_gpr() - Returns decoded General Purpose Register
	* -----------------------------------------------------------------------------
	*/
	static DSM_TYPE_T decode_gpr(register DSM_OP_T *pDsmOp, UINT32 sz, UINT08 rm)
	{
		sz = resolve_operand_size(pDsmOp, sz);

		switch (sz)
		{
		case 64:
			return static_cast<DSM_TYPE_T>(_R_RAX + rm);
		case SZ_DP:
		case 32:
			return static_cast<DSM_TYPE_T>(_R_EAX + rm);
		case SZ_WP:
		case 16:
			return static_cast<DSM_TYPE_T>(_R_AX + rm);
		case  8:
			if (pDsmOp->dsmMode == 64 && pDsmOp->pfx_rex)
			{
				if (rm >= 4)
					return static_cast<DSM_TYPE_T>(_R_SPL + (rm - 4));
				return static_cast<DSM_TYPE_T>(_R_AL + rm);
			}
			else
			{
				return static_cast<DSM_TYPE_T>(_R_AL + rm);
			}
		}
		return static_cast<DSM_TYPE_T>(0);
	}

	/* -----------------------------------------------------------------------------
	* resolve_gpr64() - 64bit General Purpose Register-Selection.
	* -----------------------------------------------------------------------------
	*/
	static DSM_TYPE_T resolve_gpr64(DSM_OP_T *pDsmOp, OPERAND_CODE_T gpr_op)
	{
		if (gpr_op >= OP_rAXr8 && gpr_op <= OP_rDIr15)
			gpr_op = static_cast<OPERAND_CODE_T>((gpr_op - OP_rAXr8) | (REX_B(pDsmOp->pfx_rex) << 3));
		else
			gpr_op = static_cast<OPERAND_CODE_T>(gpr_op - OP_rAX);

		if (pDsmOp->opr_mode == 16)
			return static_cast<DSM_TYPE_T>(gpr_op + _R_AX);
		if (pDsmOp->dsmMode == 32 ||
			(pDsmOp->opr_mode == 32 &&
			!(REX_W(pDsmOp->pfx_rex) || pDsmOp->default64)))
		{
			return static_cast<DSM_TYPE_T>(gpr_op + _R_EAX);
		}

		return static_cast<DSM_TYPE_T>(gpr_op + _R_RAX);
	}

	/* -----------------------------------------------------------------------------
	* resolve_gpr32 () - 32bit General Purpose Register-Selection.
	* -----------------------------------------------------------------------------
	*/
	static DSM_TYPE_T resolve_gpr32(DSM_OP_T *pDsmOp, OPERAND_CODE_T gpr_op)
	{
		gpr_op = static_cast<OPERAND_CODE_T>(gpr_op - OP_eAX);

		if (pDsmOp->opr_mode == 16)
			return static_cast<DSM_TYPE_T>(gpr_op + _R_AX);

		return static_cast<DSM_TYPE_T>(gpr_op + _R_EAX);
	}

	/* -----------------------------------------------------------------------------
	* resolve_reg() - Resolves the register type
	* -----------------------------------------------------------------------------
	*/
	static DSM_TYPE_T resolve_reg(DSM_OP_T *pDsmOp, UINT32 type, UINT08 i)
	{
		switch (type)
		{
		case T_MMX:		return static_cast<DSM_TYPE_T>(_R_MM0 + (i & 7));
		case T_XMM:		return static_cast<DSM_TYPE_T>(_R_XMM0 + i);
		case T_CRG:		return static_cast<DSM_TYPE_T>(_R_CR0 + i);
		case T_DBG:		return static_cast<DSM_TYPE_T>(_R_DR0 + i);
		case T_SEG:		return static_cast<DSM_TYPE_T>(_R_ES + (i & 7));
		case T_NONE:	return static_cast<DSM_TYPE_T>(_NONE);
		}
		return _NONE;
	}

	/* -----------------------------------------------------------------------------
	* decode_imm() - Decodes Immediate values.
	* -----------------------------------------------------------------------------
	*/
	static void decode_imm(DSM_OP_T *pDsmOp, UINT32 sz, struct operand_t *op)
	{
		op->size = resolve_operand_size(pDsmOp, sz);
		op->type = _OP_IMM;

		switch (op->size)
		{
		case  8: op->lval.sbyte = input_uint8(pDsmOp);  break;
		case 16: op->lval.uword = input_uint16(pDsmOp); break;
		case 32: op->lval.udword = input_uint32(pDsmOp); break;
		case 64: op->lval.uqword = input_uint64(pDsmOp); break;
		}

		return;
	}

	/* -----------------------------------------------------------------------------
	* decode_modrm() - Decodes ModRM Byte
	* -----------------------------------------------------------------------------
	*/
	static void decode_modrm(DSM_OP_T *pDsmOp, struct operand_t *op, UINT32 sz,
		UINT08 rm_type, struct operand_t *opreg,
		UINT08 reg_size, UINT08 reg_type)
	{
		UINT08 mod, rm, reg;

		input_next(pDsmOp);

		/* get mod, r/m and reg fields */
		mod = MODRM_MOD(pDsmOp->p_cache[pDsmOp->p_curr]);
		rm = (REX_B(pDsmOp->pfx_rex) << 3) | MODRM_RM(pDsmOp->p_cache[pDsmOp->p_curr]);
		reg = (REX_R(pDsmOp->pfx_rex) << 3) | MODRM_REG(pDsmOp->p_cache[pDsmOp->p_curr]);

		op->size = resolve_operand_size(pDsmOp, sz);

		/* if mod is 11b, then the _R_m specifies a gpr/mmx/sse/control/debug */
		if (mod == 3)
		{
			op->type = _OP_REG;
			if (rm_type == T_GPR)
				op->base = decode_gpr(pDsmOp, op->size, rm);
			else
				op->base = resolve_reg(pDsmOp, rm_type, (REX_B(pDsmOp->pfx_rex) << 3) | (rm & 7));
		}
		/* else its memory addressing */
		else
		{
			op->type = _OP_MEM;

			/* 64bit addressing */
			if (pDsmOp->adr_mode == 64)
			{
				op->base = static_cast<DSM_TYPE_T>(_R_RAX + rm);

				/* get offset type */
				if (mod == 1)
				{
					op->offset = 8;
				}
				else if (mod == 2)
				{
					op->offset = 32;
				}
				else if (mod == 0 && (rm & 7) == 5)
				{
					op->base = _R_RIP;
					op->offset = 32;
				}
				else
					op->offset = 0;

				/* Scale-Index-Base (SIB) */
				if ((rm & 7) == 4)
				{
					input_next(pDsmOp);

					op->scale = (1 << SIB_S(pDsmOp->p_cache[pDsmOp->p_curr])) & ~1;
					op->index = static_cast<DSM_TYPE_T>(_R_RAX + (SIB_I(pDsmOp->p_cache[pDsmOp->p_curr]) | (REX_X(pDsmOp->pfx_rex) << 3)));
					op->base = static_cast<DSM_TYPE_T>(_R_RAX + (SIB_B(pDsmOp->p_cache[pDsmOp->p_curr]) | (REX_B(pDsmOp->pfx_rex) << 3)));

					/* special conditions for base reference */
					if (op->index == _R_RSP)
					{
						op->index = _NONE;
						op->scale = _NONE;
					}

					if (op->base == _R_RBP || op->base == _R_R13)
					{
						if (mod == 0)
							op->base = _NONE;

						if (mod == 1)
							op->offset = 8;
						else
							op->offset = 32;
					}
				}
			}

			/* 32-Bit addressing mode */
			else if (pDsmOp->adr_mode == 32)
			{

				/* get base */
				op->base = static_cast<DSM_TYPE_T>(_R_EAX + rm);

				/* get offset type */
				if (mod == 1)
					op->offset = 8;
				else if (mod == 2)
					op->offset = 32;
				else if (mod == 0 && rm == 5)
				{
					op->base = _NONE;
					op->offset = 32;
				}
				else
					op->offset = 0;

				/* Scale-Index-Base (SIB) */
				if ((rm & 7) == 4)
				{
					input_next(pDsmOp);

					op->scale = (1 << SIB_S(pDsmOp->p_cache[pDsmOp->p_curr])) & ~1;
					op->index = static_cast<DSM_TYPE_T>(_R_EAX + (SIB_I(pDsmOp->p_cache[pDsmOp->p_curr]) | (REX_X(pDsmOp->pfx_rex) << 3)));
					op->base = static_cast<DSM_TYPE_T>(_R_EAX + (SIB_B(pDsmOp->p_cache[pDsmOp->p_curr]) | (REX_B(pDsmOp->pfx_rex) << 3)));

					if (op->index == _R_ESP)
					{
						op->index = _NONE;
						op->scale = _NONE;
					}

					/* special condition for base reference */
					if (op->base == _R_EBP)
					{
						if (mod == 0)
							op->base = _NONE;

						if (mod == 1)
							op->offset = 8;
						else
							op->offset = 32;
					}
				}
			}
			/* 16bit addressing mode */
			else
			{
				switch (rm)
				{
				case 0: op->base = _R_BX; op->index = _R_SI; break;
				case 1: op->base = _R_BX; op->index = _R_DI; break;
				case 2: op->base = _R_BP; op->index = _R_SI; break;
				case 3: op->base = _R_BP; op->index = _R_DI; break;
				case 4: op->base = _R_SI; break;
				case 5: op->base = _R_DI; break;
				case 6: op->base = _R_BP; break;
				case 7: op->base = _R_BX; break;
				}

				if (mod == 0 && rm == 6)
				{
					op->offset = 16;
					op->base = _NONE;
				}
				else if (mod == 1)
					op->offset = 8;
				else if (mod == 2)
					op->offset = 16;
			}
		}

		/* extract offset, if any */
		switch (op->offset)
		{
		case  8: op->lval.ubyte = input_uint8(pDsmOp); break;
		case 16: op->lval.uword = input_uint16(pDsmOp); break;
		case 32: op->lval.udword = input_uint32(pDsmOp); break;
		case 64: op->lval.uqword = input_uint64(pDsmOp); break;
		}

		/* resolve register encoded in reg field */
		if (opreg)
		{
			opreg->type = _OP_REG;
			opreg->size = resolve_operand_size(pDsmOp, reg_size);

			if (reg_type == T_GPR)
				opreg->base = decode_gpr(pDsmOp, opreg->size, reg);
			else
				opreg->base = resolve_reg(pDsmOp, reg_type, reg);
		}
	}

	/* -----------------------------------------------------------------------------
	* decode_o() - Decodes offset
	* -----------------------------------------------------------------------------
	*/
	static void decode_o(DSM_OP_T *pDsmOp, UINT32 sz, struct operand_t *op)
	{
		switch (pDsmOp->adr_mode)
		{
		case 64:
			op->offset = 64;
			op->lval.uqword = input_uint64(pDsmOp);
			break;
		case 32:
			op->offset = 32;
			op->lval.udword = input_uint32(pDsmOp);
			break;
		case 16:
			op->offset = 16;
			op->lval.uword = input_uint16(pDsmOp);
			break;
		default:
			return;
		}
		op->type = _OP_MEM;
		op->size = resolve_operand_size(pDsmOp, sz);
	}

	/* -----------------------------------------------------------------------------
	* disasm_operands() - Disassembles Operands.
	* -----------------------------------------------------------------------------
	*/
	static int disasm_operands(register DSM_OP_T *pDsmOp)
	{
		/* mopXt = map entry, operand X, type; */
		OPERAND_CODE_T mop1t = pDsmOp->pEntry->operand1.type;
		OPERAND_CODE_T mop2t = pDsmOp->pEntry->operand2.type;
		OPERAND_CODE_T mop3t = pDsmOp->pEntry->operand3.type;

		/* mopXs = map entry, operand X, size */
		UINT32 mop1s = pDsmOp->pEntry->operand1.size;
		UINT32 mop2s = pDsmOp->pEntry->operand2.size;
		UINT32 mop3s = pDsmOp->pEntry->operand3.size;

		/* iop = instruction operand */
		register struct operand_t* iop = pDsmOp->operand;

		switch (mop1t)
		{
		case OP_A:
			decode_a(pDsmOp, &(iop[0]));
			break;
			/* M[b] ... */
		case OP_M:
			if (MODRM_MOD(input_peek(pDsmOp)) == 3)
				pDsmOp->error = 1;
			/* E, G/P/V/I/CL/1/S */
		case OP_E:
			if (mop2t == OP_G)
			{
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_GPR);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
				else if (mop3t == OP_CL)
				{
					iop[2].type = _OP_REG;
					iop[2].base = _R_CL;
					iop[2].size = 8;
				}
			}
			else if (mop2t == OP_P)
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_MMX);
			else if (mop2t == OP_V)
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_XMM);
			else if (mop2t == OP_S)
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_SEG);
			else
			{
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, NULL, 0, T_NONE);
				if (mop2t == OP_CL)
				{
					iop[1].type = _OP_REG;
					iop[1].base = _R_CL;
					iop[1].size = 8;
				}
				else if (mop2t == OP_I1)
				{
					iop[1].type = _OP_CONST;
					pDsmOp->operand[1].lval.udword = 1;
				}
				else if (mop2t == OP_I)
				{
					decode_imm(pDsmOp, mop2s, &(iop[1]));
				}
			}
			break;

			/* G, E/PR[,I]/VR */
		case OP_G:
			if (mop2t == OP_M)
			{
				if (MODRM_MOD(input_peek(pDsmOp)) == 3)
					pDsmOp->error = 1;
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_GPR);
			}
			else if (mop2t == OP_E) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_GPR);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
			}
			else if (mop2t == OP_PR) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_MMX, &(iop[0]), mop1s, T_GPR);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
			}
			else if (mop2t == OP_VR) {
				if (MODRM_MOD(input_peek(pDsmOp)) != 3)
					pDsmOp->error = 1;
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_XMM, &(iop[0]), mop1s, T_GPR);
			}
			else if (mop2t == OP_W)
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_XMM, &(iop[0]), mop1s, T_GPR);
			break;

			/* AL..BH, I/O/DX */
		case OP_AL: case OP_CL: case OP_DL: case OP_BL:
		case OP_AH: case OP_CH: case OP_DH: case OP_BH:

			iop[0].type = _OP_REG;
			iop[0].base = static_cast<DSM_TYPE_T>(_R_AL + (mop1t - OP_AL));
			iop[0].size = 8;

			if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			else if (mop2t == OP_DX) {
				iop[1].type = _OP_REG;
				iop[1].base = _R_DX;
				iop[1].size = 16;
			}
			else if (mop2t == OP_O)
				decode_o(pDsmOp, mop2s, &(iop[1]));
			break;

			/* rAX[r8]..rDI[r15], I/rAX..rDI/O */
		case OP_rAXr8: case OP_rCXr9: case OP_rDXr10: case OP_rBXr11:
		case OP_rSPr12: case OP_rBPr13: case OP_rSIr14: case OP_rDIr15:
		case OP_rAX: case OP_rCX: case OP_rDX: case OP_rBX:
		case OP_rSP: case OP_rBP: case OP_rSI: case OP_rDI:

			iop[0].type = _OP_REG;
			iop[0].base = resolve_gpr64(pDsmOp, mop1t);

			if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			else if (mop2t >= OP_rAX && mop2t <= OP_rDI) {
				iop[1].type = _OP_REG;
				iop[1].base = resolve_gpr64(pDsmOp, mop2t);
			}
			else if (mop2t == OP_O) {
				decode_o(pDsmOp, mop2s, &(iop[1]));
				iop[0].size = resolve_operand_size(pDsmOp, mop2s);
			}
			break;

			/* AL[r8b]..BH[r15b], I */
		case OP_ALr8b: case OP_CLr9b: case OP_DLr10b: case OP_BLr11b:
		case OP_AHr12b: case OP_CHr13b: case OP_DHr14b: case OP_BHr15b:
		{
							DSM_TYPE_T gpr = static_cast<DSM_TYPE_T>((mop1t - OP_ALr8b) + _R_AL + (REX_B(pDsmOp->pfx_rex) << 3));
							if (_R_AH <= gpr && pDsmOp->pfx_rex)
								gpr = static_cast<DSM_TYPE_T>(gpr + 4);
							iop[0].type = _OP_REG;
							iop[0].base = gpr;
							if (mop2t == OP_I)
								decode_imm(pDsmOp, mop2s, &(iop[1]));
							break;
		}

			/* eAX..eDX, DX/I */
		case OP_eAX: case OP_eCX: case OP_eDX: case OP_eBX:
		case OP_eSP: case OP_eBP: case OP_eSI: case OP_eDI:
			iop[0].type = _OP_REG;
			iop[0].base = resolve_gpr32(pDsmOp, mop1t);
			if (mop2t == OP_DX) {
				iop[1].type = _OP_REG;
				iop[1].base = _R_DX;
				iop[1].size = 16;
			}
			else if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			break;

			/* ES..GS */
		case OP_ES: case OP_CS: case OP_DS:
		case OP_SS: case OP_FS: case OP_GS:

			/* in 64bits mode, only fs and gs are allowed */
			if (pDsmOp->dsmMode == 64)
			if (mop1t != OP_FS && mop1t != OP_GS)
				pDsmOp->error = 1;
			iop[0].type = _OP_REG;
			iop[0].base = static_cast<DSM_TYPE_T>((mop1t - OP_ES) + _R_ES);
			iop[0].size = 16;

			break;

			/* J */
		case OP_J:
			decode_imm(pDsmOp, mop1s, &(iop[0]));
			iop[0].type = _OP_JIMM;
			break;

			/* PR, I */
		case OP_PR:
			if (MODRM_MOD(input_peek(pDsmOp)) != 3)
				pDsmOp->error = 1;
			decode_modrm(pDsmOp, &(iop[0]), mop1s, T_MMX, NULL, 0, T_NONE);
			if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			break;

			/* VR, I */
		case OP_VR:
			if (MODRM_MOD(input_peek(pDsmOp)) != 3)
				pDsmOp->error = 1;
			decode_modrm(pDsmOp, &(iop[0]), mop1s, T_XMM, NULL, 0, T_NONE);
			if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			break;

			/* P, Q[,I]/W/E[,I],VR */
		case OP_P:
			if (mop2t == OP_Q) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_MMX, &(iop[0]), mop1s, T_MMX);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
			}
			else if (mop2t == OP_W) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_XMM, &(iop[0]), mop1s, T_MMX);
			}
			else if (mop2t == OP_VR) {
				if (MODRM_MOD(input_peek(pDsmOp)) != 3)
					pDsmOp->error = 1;
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_XMM, &(iop[0]), mop1s, T_MMX);
			}
			else if (mop2t == OP_E) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_MMX);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
			}
			break;

			/* R, C/D */
		case OP_R:
			if (mop2t == OP_C)
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_CRG);
			else if (mop2t == OP_D)
				decode_modrm(pDsmOp, &(iop[0]), mop1s, T_GPR, &(iop[1]), mop2s, T_DBG);
			break;

			/* C, R */
		case OP_C:
			decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_CRG);
			break;

			/* D, R */
		case OP_D:
			decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_DBG);
			break;

			/* Q, P */
		case OP_Q:
			decode_modrm(pDsmOp, &(iop[0]), mop1s, T_MMX, &(iop[1]), mop2s, T_MMX);
			break;

			/* S, E */
		case OP_S:
			decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_SEG);
			break;

			/* W, V */
		case OP_W:
			decode_modrm(pDsmOp, &(iop[0]), mop1s, T_XMM, &(iop[1]), mop2s, T_XMM);
			break;

			/* V, W[,I]/Q/M/E */
		case OP_V:
			if (mop2t == OP_W) {
				/* special cases for movlps and movhps */
				if (MODRM_MOD(input_peek(pDsmOp)) == 3) {
					if (pDsmOp->opcode == INST_Imovlps)
						pDsmOp->opcode = INST_Imovhlps;
					else
					if (pDsmOp->opcode == INST_Imovhps)
						pDsmOp->opcode = INST_Imovlhps;
				}
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_XMM, &(iop[0]), mop1s, T_XMM);
				if (mop3t == OP_I)
					decode_imm(pDsmOp, mop3s, &(iop[2]));
			}
			else if (mop2t == OP_Q)
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_MMX, &(iop[0]), mop1s, T_XMM);
			else if (mop2t == OP_M) {
				if (MODRM_MOD(input_peek(pDsmOp)) == 3)
					pDsmOp->error = 1;
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_XMM);
			}
			else if (mop2t == OP_E) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_GPR, &(iop[0]), mop1s, T_XMM);
			}
			else if (mop2t == OP_PR) {
				decode_modrm(pDsmOp, &(iop[1]), mop2s, T_MMX, &(iop[0]), mop1s, T_XMM);
			}
			break;

			/* DX, eAX/AL */
		case OP_DX:
			iop[0].type = _OP_REG;
			iop[0].base = _R_DX;
			iop[0].size = 16;

			if (mop2t == OP_eAX) {
				iop[1].type = _OP_REG;
				iop[1].base = resolve_gpr32(pDsmOp, mop2t);
			}
			else if (mop2t == OP_AL) {
				iop[1].type = _OP_REG;
				iop[1].base = _R_AL;
				iop[1].size = 8;
			}

			break;

			/* I, I/AL/eAX */
		case OP_I:
			decode_imm(pDsmOp, mop1s, &(iop[0]));
			if (mop2t == OP_I)
				decode_imm(pDsmOp, mop2s, &(iop[1]));
			else if (mop2t == OP_AL) {
				iop[1].type = _OP_REG;
				iop[1].base = _R_AL;
				iop[1].size = 16;
			}
			else if (mop2t == OP_eAX) {
				iop[1].type = _OP_REG;
				iop[1].base = resolve_gpr32(pDsmOp, mop2t);
			}
			break;

			/* O, AL/eAX */
		case OP_O:
			decode_o(pDsmOp, mop1s, &(iop[0]));
			iop[1].type = _OP_REG;
			iop[1].size = resolve_operand_size(pDsmOp, mop1s);
			if (mop2t == OP_AL)
				iop[1].base = _R_AL;
			else if (mop2t == OP_eAX)
				iop[1].base = resolve_gpr32(pDsmOp, mop2t);
			else if (mop2t == OP_rAX)
				iop[1].base = resolve_gpr64(pDsmOp, mop2t);
			break;

			/* 3 */
		case OP_I3:
			iop[0].type = _OP_CONST;
			iop[0].lval.sbyte = 3;
			break;

			/* ST(n), ST(n) */
		case OP_ST0: case OP_ST1: case OP_ST2: case OP_ST3:
		case OP_ST4: case OP_ST5: case OP_ST6: case OP_ST7:

			iop[0].type = _OP_REG;
			iop[0].base = static_cast<DSM_TYPE_T>((mop1t - OP_ST0) + _R_ST0);
			iop[0].size = 0;

			if (mop2t >= OP_ST0 && mop2t <= OP_ST7) {
				iop[1].type = _OP_REG;
				iop[1].base = static_cast<DSM_TYPE_T>((mop2t - OP_ST0) + _R_ST0);
				iop[1].size = 0;
			}
			break;

			/* AX */
		case OP_AX:
			iop[0].type = _OP_REG;
			iop[0].base = _R_AX;
			iop[0].size = 16;
			break;

			/* none */
		default:
			iop[0].type = iop[1].type = iop[2].type = _NONE;
		}

		return 0;
	}

	static void _setDsmMode(DSM_OP_T *pDsmOp, UINT08 mode)
	{
		pDsmOp->dsmMode = 16;

		switch (mode)
		{
		case 16:case 32:case 64:
			pDsmOp->dsmMode = mode; break;
		}
	}

	/* -----------------------------------------------------------------------------
	* clear_insn() - clear instruction pointer
	* -----------------------------------------------------------------------------
	*/
	static int clear_insn(register DSM_OP_T *pDsmOp)
	{
		pDsmOp->error = 0;
		pDsmOp->pfx_seg = 0;
		pDsmOp->pfx_opr = 0;
		pDsmOp->pfx_adr = 0;
		pDsmOp->pfx_lock = 0;
		pDsmOp->pfx_repne = 0;
		pDsmOp->pfx_rep = 0;
		pDsmOp->pfx_repe = 0;
		pDsmOp->pfx_seg = 0;
		pDsmOp->pfx_rex = 0;
		pDsmOp->pfx_insn = 0;
		pDsmOp->opcode = INST_Inone;
		pDsmOp->pEntry = NULL;

		memset(&pDsmOp->operand[0], 0, sizeof(struct operand_t));
		memset(&pDsmOp->operand[1], 0, sizeof(struct operand_t));
		memset(&pDsmOp->operand[2], 0, sizeof(struct operand_t));

		return 0;
	}

	static int do_mode(DSM_OP_T *pDsmOp)
	{
		/* if in error state, bail out */
		if (pDsmOp->error)
			return -1;

		/* propagate perfix effects */
		if (pDsmOp->dsmMode == 64)
		{  /* set 64bit-mode flags */

			/* Check validity of  instruction m64 */
			if (P_INV64(pDsmOp->pEntry->prefix))
			{
				pDsmOp->error = 1;
				return -1;
			}

			/* effective rex prefix is the  effective mask for the
			* instruction hard-coded in the opcode map.
			*/
			pDsmOp->pfx_rex = (pDsmOp->pfx_rex & 0x40) |
				(pDsmOp->pfx_rex & REX_PFX_MASK(pDsmOp->pEntry->prefix));

			/* whether this instruction has a default operand size of
			* 64bit, also hardcoded into the opcode map.
			*/
			pDsmOp->default64 = P_DEF64(pDsmOp->pEntry->prefix);
			/* calculate effective operand size */
			if (REX_W(pDsmOp->pfx_rex))
			{
				pDsmOp->opr_mode = 64;
			}
			else if (pDsmOp->pfx_opr)
			{
				pDsmOp->opr_mode = 16;
			}
			else
			{
				/* unless the default opr size of instruction is 64,
				* the effective operand size in the absence of rex.w
				* prefix is 32.
				*/
				pDsmOp->opr_mode = (pDsmOp->default64) ? 64 : 32;
			}

			/* calculate effective address size */
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 32 : 64;
		}
		else if (pDsmOp->dsmMode == 32)
		{ /* set 32bit-mode flags */
			pDsmOp->opr_mode = (pDsmOp->pfx_opr) ? 16 : 32;
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 16 : 32;
		}
		else if (pDsmOp->dsmMode == 16)
		{ /* set 16bit-mode flags */
			pDsmOp->opr_mode = (pDsmOp->pfx_opr) ? 32 : 16;
			pDsmOp->adr_mode = (pDsmOp->pfx_adr) ? 32 : 16;
		}

		/* These flags determine which operand to apply the operand size
		* cast to.
		*/
		pDsmOp->c1 = (P_C1(pDsmOp->pEntry->prefix)) ? 1 : 0;
		pDsmOp->c2 = (P_C2(pDsmOp->pEntry->prefix)) ? 1 : 0;
		pDsmOp->c3 = (P_C3(pDsmOp->pEntry->prefix)) ? 1 : 0;

		/* set flags for implicit addressing */
		pDsmOp->implicit_addr = P_IMPADDR(pDsmOp->pEntry->prefix);

		return 0;
	}

	static int gen_hex(DSM_OP_T *pDsmOp)
	{
		UINT32	i;
		UINT08	*src_ptr = pDsmOp->p_sess;
		char*		src_hex;

		/* bail out if in error stat. */
		if (pDsmOp->error)
			return -1;

		/* output buffer pointe */
		src_hex = (char*)pDsmOp->n_hexcode;

		/* for each byte used to decode instruction */
		for (i = 0; i < pDsmOp->p_ctr; ++i, ++src_ptr)
		{
			sprintf(src_hex, "%02x", *src_ptr & 0xFF);
			src_hex += 2;
		}
		return 0;
	}

	static void mkasm(DSM_OP_T *pDsmOp, const char *fmt, ...)
	{
		va_list ap;

		va_start(ap, fmt);

		pDsmOp->n_fill += vsprintf((char*)&pDsmOp->n_buffer[0] + pDsmOp->n_fill, fmt, ap);

		va_end(ap);
	}

	/**
	* AT & T assembly style decoding.
	*/
	static void opr_cast_atNt(DSM_OP_T *pDsmOp, struct operand_t *op)
	{
		if (op->size == 16 || op->size == 32)
		{
			mkasm(pDsmOp, "*");
		}
	}

	static void gen_operand_atNt(DSM_OP_T *pDsmOp, struct operand_t *op)
	{
		switch (op->type)
		{
		case _OP_REG:
			mkasm(pDsmOp, "%%%s", _x86_reg_tbl[op->base - _R_AL]);
			break;
		case _OP_MEM:
			if (pDsmOp->br_far) opr_cast_atNt(pDsmOp, op);
			if (pDsmOp->pfx_seg)
				mkasm(pDsmOp, "%%%s:", _x86_reg_tbl[pDsmOp->pfx_seg - _R_AL]);
			if (op->offset == 8) {
				if (op->lval.sbyte < 0)
					mkasm(pDsmOp, "-0x%x", (-op->lval.sbyte) & 0xff);
				else	mkasm(pDsmOp, "0x%x", op->lval.sbyte);
			}
			else if (op->offset == 16)
				mkasm(pDsmOp, "0x%x", op->lval.uword);
			else if (op->offset == 32)
				mkasm(pDsmOp, "0x%lx", op->lval.udword);
			else if (op->offset == 64)
				mkasm(pDsmOp, "0x" FMT64 "x", op->lval.uqword);

			if (op->base)
				mkasm(pDsmOp, "(%%%s", _x86_reg_tbl[op->base - _R_AL]);
			if (op->index) {
				if (op->base)
					mkasm(pDsmOp, ",");
				else mkasm(pDsmOp, "(");
				mkasm(pDsmOp, "%%%s", _x86_reg_tbl[op->index - _R_AL]);
			}
			if (op->scale)
				mkasm(pDsmOp, ",%d", op->scale);
			if (op->base || op->index)
				mkasm(pDsmOp, ")");
			break;
		case _OP_IMM:
			switch (op->size) {
			case  8: mkasm(pDsmOp, "$0x%x", op->lval.ubyte);    break;
			case 16: mkasm(pDsmOp, "$0x%x", op->lval.uword);    break;
			case 32: mkasm(pDsmOp, "$0x%lx", op->lval.udword);  break;
			case 64: mkasm(pDsmOp, "$0x" FMT64 "x", op->lval.uqword); break;
			default: break;
			}
			break;
		case _OP_JIMM:
		{
						 UINT64	addr = 0;
						 char *	sym = NULL;

						 switch (op->size)
						 {
						 case  8: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sbyte;  break;
						 case 16: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sword;  break;
						 case 32: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sdword; break;
						 default: break;
						 }
						#if 1//def _DEBUG
						 if (0 != dbgtool::findSymByAddr((UINT32)addr, &sym))
						 {
							 mkasm(pDsmOp, "0x" FMT64 "x (=%s)", addr, sym);
						 }
						 else
						#endif
						 {
							 mkasm(pDsmOp, "0x" FMT64 "x", addr);
						 }
						 break;
		}
		case _OP_PTR:
			switch (op->size) {
			case 32:
				mkasm(pDsmOp, "$0x%x, $0x%x", op->lval.ptr.seg,
					op->lval.ptr.off & 0xFFFF);
				break;
			case 48:
				mkasm(pDsmOp, "$0x%x, $0x%lx", op->lval.ptr.seg,
					op->lval.ptr.off);
				break;
			}
			break;
		default:
			break;
		}

		return;
	}

	static void translate_atNt(DSM_OP_T *pDsmOp)
	{
		int size = 0;

		/* check if P_OSO prefix is used */
		if (!P_OSO(pDsmOp->pEntry->prefix) && pDsmOp->pfx_opr)
		{
			switch (pDsmOp->dsmMode)
			{
			case 16:mkasm(pDsmOp, "o32 "); break;
			case 32:
			case 64:mkasm(pDsmOp, "o16 "); break;
			}
		}

		/* check if P_ASO prefix was used */
		if (!P_ASO(pDsmOp->pEntry->prefix) && pDsmOp->pfx_adr)
		{
			switch (pDsmOp->dsmMode)
			{
			case 16: mkasm(pDsmOp, "a32 "); break;
			case 32: mkasm(pDsmOp, "a16 "); break;
			case 64: mkasm(pDsmOp, "a32 "); break;
			}
		}

		if (pDsmOp->pfx_lock)
			mkasm(pDsmOp, "lock ");

		if (pDsmOp->pfx_rep)
			mkasm(pDsmOp, "rep ");

		if (pDsmOp->pfx_repne)
			mkasm(pDsmOp, "repne ");

		/* special instructions */
		switch (pDsmOp->opcode)
		{
		case INST_Iretf:
			mkasm(pDsmOp, "lret ");
			break;
		case INST_Iinsb:
			mkasm(pDsmOp, "insb %s %s %s", "(%dx)", "%es", "(%edi)");
			break;
		case INST_Idb:
			mkasm(pDsmOp, ".byte 0x%x", pDsmOp->operand[0].lval.ubyte);
			return;
		case INST_Ijmp:
		case INST_Icall:
			if (pDsmOp->br_far) mkasm(pDsmOp, "l");
			mkasm(pDsmOp, "%s", dsm_lookup_opcode(pDsmOp->opcode));
			break;
		case INST_Ibound:
		case INST_Ienter:
			if (pDsmOp->operand[0].type != _NONE)
				gen_operand_atNt(pDsmOp, &pDsmOp->operand[0]);
			if (pDsmOp->operand[1].type != _NONE) {
				mkasm(pDsmOp, ",");
				gen_operand_atNt(pDsmOp, &pDsmOp->operand[1]);
			}
			return;
		default:
			mkasm(pDsmOp, "%s", dsm_lookup_opcode(pDsmOp->opcode));
		}

		if (pDsmOp->c1)
			size = pDsmOp->operand[0].size;
		else if (pDsmOp->c2)
			size = pDsmOp->operand[1].size;
		else if (pDsmOp->c3)
			size = pDsmOp->operand[2].size;

		if (size == 8)
			mkasm(pDsmOp, "b");
		else if (size == 16)
			mkasm(pDsmOp, "w");
		else if (size == 64)
			mkasm(pDsmOp, "q");

		mkasm(pDsmOp, " ");

		if (pDsmOp->operand[2].type != _NONE)
		{
			gen_operand_atNt(pDsmOp, &pDsmOp->operand[2]);
			mkasm(pDsmOp, ", ");
		}

		if (pDsmOp->operand[1].type != _NONE)
		{
			gen_operand_atNt(pDsmOp, &pDsmOp->operand[1]);
			mkasm(pDsmOp, ", ");
		}

		if (pDsmOp->operand[0].type != _NONE)
			gen_operand_atNt(pDsmOp, &pDsmOp->operand[0]);
	}

	/**
	* Intel assembly style decoding.
	*/
	static void opr_cast_Intel(DSM_OP_T *pDsmOp, struct operand_t *op)
	{
		switch (op->size)
		{
		case  8: mkasm(pDsmOp, "byte "); break;
		case 16: mkasm(pDsmOp, "word "); break;
		case 32: mkasm(pDsmOp, "dword "); break;
		case 64: mkasm(pDsmOp, "dword "); break;
		case 80: mkasm(pDsmOp, "tword "); break;
		default: break;
		}
		if (pDsmOp->br_far)
			mkasm(pDsmOp, "far ");
		else if (pDsmOp->br_near)
			mkasm(pDsmOp, "near ");
	}

	static void gen_operand_Intel(DSM_OP_T *pDsmOp, struct operand_t* op, int syn_cast)
	{
		switch (op->type) {
		case _OP_REG:
			mkasm(pDsmOp, _x86_reg_tbl[op->base - _R_AL]);
			break;

		case _OP_MEM: {

						  int op_f = 0;

						  if (syn_cast)
							  opr_cast_Intel(pDsmOp, op);

						  mkasm(pDsmOp, "[");

						  if (pDsmOp->pfx_seg)
							  mkasm(pDsmOp, "%s:", _x86_reg_tbl[pDsmOp->pfx_seg - _R_AL]);

						  if (op->base) {
							  mkasm(pDsmOp, "%s", _x86_reg_tbl[op->base - _R_AL]);
							  op_f = 1;
						  }

						  if (op->index) {
							  if (op_f)
								  mkasm(pDsmOp, "+");
							  mkasm(pDsmOp, "%s", _x86_reg_tbl[op->index - _R_AL]);
							  op_f = 1;
						  }

						  if (op->scale)
							  mkasm(pDsmOp, "*%d", op->scale);

						  if (op->offset == 8) {
							  if (op->lval.sbyte < 0)
								  mkasm(pDsmOp, "-0x%x", -op->lval.sbyte);
							  else
								  mkasm(pDsmOp, "%s0x%x", (op_f) ? "+" : "", op->lval.sbyte);
						  }
						  else if (op->offset == 16)
							  mkasm(pDsmOp, "%s0x%x", (op_f) ? "+" : "", op->lval.uword);
						  else if (op->offset == 32) {
							  if (pDsmOp->adr_mode == 64) {
								  if (op->lval.sdword < 0)
									  mkasm(pDsmOp, "-0x%x", -op->lval.sdword);
								  else	mkasm(pDsmOp, "%s0x%x", (op_f) ? "+" : "", op->lval.sdword);
							  }
							  else	mkasm(pDsmOp, "%s0x%lx", (op_f) ? "+" : "", op->lval.udword);
						  }
						  else if (op->offset == 64)
							  mkasm(pDsmOp, "%s0x" FMT64 "x", (op_f) ? "+" : "", op->lval.uqword);

						  mkasm(pDsmOp, "]");
						  break;
		}

		case _OP_IMM:
			if (syn_cast) opr_cast_Intel(pDsmOp, op);
			switch (op->size)
			{
			case  8: mkasm(pDsmOp, "0x%x", op->lval.ubyte);    break;
			case 16: mkasm(pDsmOp, "0x%x", op->lval.uword);    break;
			case 32: mkasm(pDsmOp, "0x%lx", op->lval.udword);  break;
			case 64: mkasm(pDsmOp, "0x" FMT64 "x", op->lval.uqword); break;
			default: break;
			}
			break;

		case _OP_JIMM:
		{
						 UINT64	addr = 0;
						 char *	sym = NULL;

						 if (syn_cast)
							 opr_cast_Intel(pDsmOp, op);

						 switch (op->size)
						 {
						 case  8: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sbyte;  break;
						 case 16: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sword;  break;
						 case 32: addr = pDsmOp->baseAddr + pDsmOp->pc + op->lval.sdword; break;
						 default: break;
						 }
						#if 1//def _DEBUG
						 if (0 != dbgtool::findSymByAddr((UINT32)addr, &sym))
						 {
							 mkasm(pDsmOp, "0x" FMT64 "x (=%s)", addr, sym);
						 }
						 else
						#endif
						 {
							 mkasm(pDsmOp, "0x" FMT64 "x", addr);
						 }
						 break;
		}

		case _OP_PTR:
			switch (op->size) {
			case 32:
				mkasm(pDsmOp, "word 0x%x:0x%x", op->lval.ptr.seg,
					op->lval.ptr.off & 0xFFFF);
				break;
			case 48:
				mkasm(pDsmOp, "dword 0x%x:0x%lx", op->lval.ptr.seg,
					op->lval.ptr.off);
				break;
			}
			break;

		case _OP_CONST:
			if (syn_cast) opr_cast_Intel(pDsmOp, op);
			mkasm(pDsmOp, "%d", op->lval.udword);
			break;

		default: return;
		}
	}

	static void translate_intel(DSM_OP_T *pDsmOp)
	{
		/* -- prefixes -- */

		/* check if P_OSO prefix is used */
		if (!P_OSO(pDsmOp->pEntry->prefix) && pDsmOp->pfx_opr)
		{
			switch (pDsmOp->dsmMode)
			{
			case 16: mkasm(pDsmOp, "o32 "); break;
			case 32:
			case 64: mkasm(pDsmOp, "o16 "); break;
			}
		}

		/* check if P_ASO prefix was used */
		if (!P_ASO(pDsmOp->pEntry->prefix) && pDsmOp->pfx_adr)
		{
			switch (pDsmOp->dsmMode)
			{
			case 16: mkasm(pDsmOp, "a32 "); break;
			case 32: mkasm(pDsmOp, "a16 "); break;
			case 64: mkasm(pDsmOp, "a32 "); break;
			}
		}

		if (pDsmOp->pfx_lock)
			mkasm(pDsmOp, "lock ");
		if (pDsmOp->pfx_rep)
			mkasm(pDsmOp, "rep ");
		if (pDsmOp->pfx_repne)
			mkasm(pDsmOp, "repne ");
		if (pDsmOp->implicit_addr && pDsmOp->pfx_seg)
			mkasm(pDsmOp, "%s ", _x86_reg_tbl[pDsmOp->pfx_seg - _R_AL]);

		/* print the instruction mnemonic */
		mkasm(pDsmOp, "%s ", dsm_lookup_opcode(pDsmOp->opcode));

		/* operand 1 */
		if (pDsmOp->operand[0].type != _NONE)
		{
			gen_operand_Intel(pDsmOp, &pDsmOp->operand[0], pDsmOp->c1);
		}
		/* operand 2 */
		if (pDsmOp->operand[1].type != _NONE)
		{
			mkasm(pDsmOp, ", ");
			gen_operand_Intel(pDsmOp, &pDsmOp->operand[1], pDsmOp->c2);
		}

		/* operand 3 */
		if (pDsmOp->operand[2].type != _NONE)
		{
			mkasm(pDsmOp, ", ");
			gen_operand_Intel(pDsmOp, &pDsmOp->operand[2], pDsmOp->c3);
		}
	}

	/* =============================================================================
	* decode() - Instruction decoder. Returns the number of bytes decoded.
	* =============================================================================
	*/
	static UINT32 decode(DSM_OP_T *pDsmOp)
	{
		pDsmOp->p_ctr = 0;

		if (clear_insn(pDsmOp))
		{
			; /* error */
		}
		else if (_getPrefix(pDsmOp) != 0)
		{
			; /* error */
		}
		else if (_search_instruntion(pDsmOp) != 0)
		{
			; /* error */
		}
		else if (do_mode(pDsmOp) != 0)
		{
			; /* error */
		}
		else if (disasm_operands(pDsmOp) != 0)
		{
			; /* error */
		}
		else if (resolve_mnemonic(pDsmOp) != 0)
		{
			; /* error */
		}

		/* Handle decode error. */
		if (pDsmOp->error)
		{
			/* clear out the decode data. */
			clear_insn(pDsmOp);
			/* mark the sequence of bytes as invalid. */
			pDsmOp->pEntry = &ie_invalid;
			pDsmOp->opcode = pDsmOp->pEntry->mnemonic;
		}

		pDsmOp->n_offset = pDsmOp->pc;		/* set offset of instruction */
		pDsmOp->n_fill = 0; 				/* set translation buffer index to 0 */
		pDsmOp->pc += pDsmOp->p_ctr;		/* move program counter by bytes decoded */
		gen_hex(pDsmOp);       				/* generate hex code */

		/* return number of bytes disassembled. */
		return pDsmOp->p_ctr;
	}

	void dsm_init(DSM_OP_T *pDsmOp, UINT08 dsmMode, UINT08 vendor, UINT08 *pBuf, size_t size, UINT64 base)
	{
		memset((void*)pDsmOp, 0, sizeof(DSM_OP_T));

		_setDsmMode(pDsmOp, dsmMode);

		if (vendor != VENDOR_AMD && vendor != VENDOR_INTEL)
			vendor = VENDOR_AMD;

		pDsmOp->baseAddr = base;
		pDsmOp->vendor = vendor;
		pDsmOp->opcode = INST_Iinvalid;
		pDsmOp->pc = 0;

		//input structure init.
		pDsmOp->p_curr = 0;
		pDsmOp->p_fill = 0;
		pDsmOp->p_ctr = 0;
		pDsmOp->p_end = 0;

		_setInputHook(pDsmOp, pBuf, size);
	}


	UINT32 disassem(DSM_OP_T *pDsmOp)
	{
		if (input_end(pDsmOp))
			return 0;

		pDsmOp->n_buffer[0] = pDsmOp->n_hexcode[0] = 0;

		if (0 == decode(pDsmOp))
			return 0;

		if (dsm_syn == SYN_ATNT) pDsmOp->pfnTrans = translate_atNt;
		else if (dsm_syn == SYN_INTEL) pDsmOp->pfnTrans = translate_intel;
		pDsmOp->pfnTrans(pDsmOp);

		return pDsmOp->p_ctr;
	}

	static pPRINT_FUNC dsmPrint = NULL;

	int dbgtool::dsmInst
	(
	register UINT32	*binInst,
	UINT32          address,
	void			*prtAddress
	)
	{
		UINT32		baseAddr = 0;
		DSM_OP_T	dsmOp;
		UINT64		offs1, offs2, offsDiff;

		baseAddr = address;
		dsm_init(&dsmOp, dsm_mode, dsm_vendor, (UINT08*)&binInst[0], 100, baseAddr);
		disassem(&dsmOp);
		offs1 = dsmOp.n_offset;
		if (NULL != dsmPrint)
			dsmPrint(" %08x %-16s %s\n", (UINT32)address, &dsmOp.n_hexcode[0], &dsmOp.n_buffer[0]);
		disassem(&dsmOp);
		offs2 = dsmOp.n_offset;

		offsDiff = offs2 - offs1;

		return (int)offsDiff;
	}

	int dbgtool::regPrintDsmMode(UINT32 print_func)
	{
		dsmPrint = (pPRINT_FUNC)print_func;

		return 0;
	}
}
