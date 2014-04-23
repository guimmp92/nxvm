/* This file is a part of NXVM project. */

/* Type Definitions */

#ifndef NXVM_VGLOBAL_H
#define NXVM_VGLOBAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

#define VGLOBAL_SIZE_INTEGER 32

typedef char     *t_string;
typedef uint8_t   t_nubit1;
typedef uint8_t   t_nubit4;
typedef uint8_t   t_nubit6;
typedef uint8_t   t_nubit8;
typedef int8_t    t_nsbit8;
typedef uint16_t  t_nubit16;
typedef int16_t   t_nsbit16;
typedef uint32_t  t_nubit32;
typedef int32_t   t_nsbit32;
#if VGLOBAL_SIZE_INTEGER == 64
typedef uint64_t  t_nubit64;
typedef int64_t   t_nsbit64;
#endif
typedef float     t_float32;
typedef double    t_float64;
#if VGLOBAL_SIZE_INTEGER == 64
typedef t_nubit64 t_nubitcc;
typedef t_nsbit64 t_nsbitcc;
#else
typedef t_nubit32 t_nubitcc;
typedef t_nsbit32 t_nsbitcc;
#endif
typedef t_nubit1  t_bool;
typedef t_nubitcc t_vaddrcc;
typedef t_nubitcc t_faddrcc;

#define d_nubit1(n)  (*(t_nubit1 *)(n))
#define d_nubit4(n)  (*(t_nubit4 *)(n))
#define d_nubit6(n)  (*(t_nubit6 *)(n))
#define d_nubit8(n)  (*(t_nubit8 *)(n))
#define d_nsbit8(n)  (*(t_nsbit8 *)(n))
#define d_nubit16(n) (*(t_nubit16 *)(n))
#define d_nsbit16(n) (*(t_nsbit16 *)(n))
#define d_nubit32(n) (*(t_nubit32 *)(n))
#define d_nsbit32(n) (*(t_nsbit32 *)(n))
#if VGLOBAL_SIZE_INTEGER == 64
#define d_nubit64(n) (*(t_nubit64 *)(n))
#define d_nsbit64(n) (*(t_nsbit64 *)(n))
#endif
#define d_float32(n) (*(t_float32 *)(n))
#define d_float64(n) (*(t_float64 *)(n))
#define d_nubitcc(n) (*(t_nubitcc *)(n))
#define d_nsbitcc(n) (*(t_nsbitcc *)(n))
#define d_bool(n)    (*(t_bool *)(n))

#define GetBit(s, f) (!!((s) & (f)))
#define SetBit(d, s) ((d) |= (s))
#define ClrBit(d, s) ((d) &= ~(s))
#define MakeBit(d, s, f)  ((f) ? SetBit((d), (s)) : ClrBit((d), (s)))
#define GetMSB(n, b) (GetBit((n), (1 << ((b) - 1))))
#define GetLSB(n, b) (GetBit((n), 1))

#define ExecFun(faddr) (*(void (*)(void))(faddr))()

#define _ax    (vcpu.ax)
#define _bx    (vcpu.bx)
#define _cx    (vcpu.cx)
#define _dx    (vcpu.dx)
#define _ah    (vcpu.ah)
#define _bh    (vcpu.bh)
#define _ch    (vcpu.ch)
#define _dh    (vcpu.dh)
#define _al    (vcpu.al)
#define _bl    (vcpu.bl)
#define _cl    (vcpu.cl)
#define _dl    (vcpu.dl)
#define _sp    (vcpu.sp)
#define _bp    (vcpu.bp)
#define _si    (vcpu.si)
#define _di    (vcpu.di)
#define _ip    (vcpu.ip)
#define _ds    (vcpu.ds)
#define _cs    (vcpu.cs)
#define _es    (vcpu.es)
#define _ss    (vcpu.ss)
#define _flags (vcpu.flags)
#define _of    (GetBit(vcpu.flags, VCPU_FLAG_OF))
#define _sf    (GetBit(vcpu.flags, VCPU_FLAG_SF))
#define _zf    (GetBit(vcpu.flags, VCPU_FLAG_ZF))
#define _cf    (GetBit(vcpu.flags, VCPU_FLAG_CF))
#define _af    (GetBit(vcpu.flags, VCPU_FLAG_AF))
#define _pf    (GetBit(vcpu.flags, VCPU_FLAG_PF))
#define _df    (GetBit(vcpu.flags, VCPU_FLAG_DF))
#define _tf    (GetBit(vcpu.flags, VCPU_FLAG_TF))
#define _if    (GetBit(vcpu.flags, VCPU_FLAG_IF))

#ifdef __cplusplus
}
#endif

#endif