/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * FROM ../alpha-emulator/idouble.as. ANY CHANGES MADE TO THIS FILE WILL BE LOST
 ************************************************************************/

  /* Support for double precision floating point. */
/* start FetchDoubleFloat */


fetchdoublefloat:
  if (_trace) printf("fetchdoublefloat:\n");
  sp = sp + -8;
  /* Memory Read Internal */

g8872:
  t7 = arg2 + ivory;
  arg6 = (t7 * 4);
  arg5 = LDQ_U(t7);
  /* Stack cache offset */
  t5 = arg2 - t11;
  t8 = *(u64 *)&(processor->dataread_mask);
  /* In range? */
  t6 = ((u64)t5 < (u64)t12) ? 1 : 0;
  arg6 = *(s32 *)arg6;
  arg5 = (u8)(arg5 >> ((t7&7)*8));
  if (t6 != 0)
    goto g8874;

g8873:
  t7 = zero + 240;
  t8 = t8 >> (arg5 & 63);
  t7 = t7 >> (arg5 & 63);
  if (t8 & 1)
    goto g8876;

g8883:
  t5 = arg5 - Type_Fixnum;
  /* Strip CDR code */
  t5 = t5 & 63;
  if (t5 != 0)
    goto g8871;
  *((u32 *)(&processor->fp0)+1) = arg6;
  arg2 = arg2 + 1;
  /* Memory Read Internal */

g8884:
  t7 = arg2 + ivory;
  arg6 = (t7 * 4);
  arg5 = LDQ_U(t7);
  /* Stack cache offset */
  t5 = arg2 - t11;
  t8 = *(u64 *)&(processor->dataread_mask);
  /* In range? */
  t6 = ((u64)t5 < (u64)t12) ? 1 : 0;
  arg6 = *(s32 *)arg6;
  arg5 = (u8)(arg5 >> ((t7&7)*8));
  if (t6 != 0)
    goto g8886;

g8885:
  t7 = zero + 240;
  t8 = t8 >> (arg5 & 63);
  t7 = t7 >> (arg5 & 63);
  if (t8 & 1)
    goto g8888;

g8895:
  t5 = arg5 - Type_Fixnum;
  /* Strip CDR code */
  t5 = t5 & 63;
  if (t5 != 0)
    goto g8871;
  *(u32 *)&processor->fp0 = arg6;
  sp = sp + 8;
  goto *((u64* )r0); /* ret */

g8888:
  if (_trace) printf("g8888:\n");
  if ((t7 & 1) == 0)
    goto g8887;
  /* Do the indirect thing */
  arg2 = (u32)arg6;
  goto g8884;

g8887:
  if (_trace) printf("g8887:\n");

g8886:
  if (_trace) printf("g8886:\n");
  *(u64 *)sp = r0;
  r0 = (u64)&&return0091;
  goto memoryreaddatadecode;
return0091:
  r0 = *(u64 *)sp;
  goto g8895;

g8876:
  if (_trace) printf("g8876:\n");
  if ((t7 & 1) == 0)
    goto g8875;
  /* Do the indirect thing */
  arg2 = (u32)arg6;
  goto g8872;

g8875:
  if (_trace) printf("g8875:\n");

g8874:
  if (_trace) printf("g8874:\n");
  *(u64 *)sp = r0;
  r0 = (u64)&&return0092;
  goto memoryreaddatadecode;
return0092:
  r0 = *(u64 *)sp;
  goto g8883;

g8871:
  if (_trace) printf("g8871:\n");
  /* arg6 = tag to dispatch on */
  arg6 = Type_DoubleFloat;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

/* end FetchDoubleFloat */
/* start ConsDoubleFloat */


consdoublefloat:
  if (_trace) printf("consdoublefloat:\n");
  sp = sp + -8;
  arg6 = *(s32 *)&processor->fp0;
  arg5 = *((s32 *)(&processor->fp0)+1);
  t5 = *(u64 *)&(processor->lcarea);
  t8 = *(u64 *)&(processor->niladdress);
  t6 = *(s32 *)&processor->lclength;
  /* Fetch address */
  arg2 = *(u64 *)&(processor->lcaddress);
  t7 = (t5 == t8) ? 1 : 0;
  /* Decached area */
  if (t7 != 0)
    goto g8896;
  /* Effectively an unsigned 32-bit compare */
  t7 = t6 - 2;
  /* Insufficient cache */
  if ((s64)t7 < 0)
    goto g8896;
  /* Force the trap to occur here */
  /* trapb force the trap to occur here */
  /* Store remaining length */
  *(u32 *)&processor->lclength = t7;
  t8 = (u32)arg2;
  /* Increment address */
  t8 = t8 + 2;
  /* Store updated address */
  *(u32 *)&processor->lcaddress = t8;
  arg2 = (u32)arg2;
  t9 = Type_Fixnum;
  t9 = t9 | 128;
  t5 = arg2 + ivory;
  t8 = (t5 * 4);
  t7 = LDQ_U(t5);
  t6 = (t9 & 0xff) << ((t5&7)*8);
  t7 = t7 & ~(0xffL << (t5&7)*8);

g8897:
  if (_trace) printf("g8897:\n");
  t7 = t7 | t6;
  STQ_U(t5, t7);
  *(u32 *)t8 = arg5;
  t10 = arg2 + 1;
  t9 = Type_Fixnum;
  t9 = t9 | 64;
  t5 = t10 + ivory;
  t8 = (t5 * 4);
  t7 = LDQ_U(t5);
  t6 = (t9 & 0xff) << ((t5&7)*8);
  t7 = t7 & ~(0xffL << (t5&7)*8);

g8898:
  if (_trace) printf("g8898:\n");
  t7 = t7 | t6;
  STQ_U(t5, t7);
  *(u32 *)t8 = arg6;
  sp = sp + 8;
  goto *((u64* )r0); /* ret */

g8896:
  if (_trace) printf("g8896:\n");
  /* arg6 = tag to dispatch on */
  arg6 = Type_DoubleFloat;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

/* end ConsDoubleFloat */
/* start DoDoubleFloatOp */

  /* Halfword operand from stack instruction - DoDoubleFloatOp */
  /* arg2 has the preloaded 8 bit operand. */

dodoublefloatop:
  if (_trace) printf("dodoublefloatop:\n");
#ifdef TRACING
#endif

DoDoubleFloatOpIM:
  if (_trace) printf("DoDoubleFloatOpIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);
  goto begindodoublefloatop;
#ifdef TRACING
#endif

DoDoubleFloatOpSP:
  if (_trace) printf("DoDoubleFloatOpSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
    iSP = arg4;
#ifdef TRACING
  goto headdodoublefloatop;
#endif

DoDoubleFloatOpLP:
  if (_trace) printf("DoDoubleFloatOpLP:\n");
#ifdef TRACING
  goto headdodoublefloatop;
#endif

DoDoubleFloatOpFP:
  if (_trace) printf("DoDoubleFloatOpFP:\n");

headdodoublefloatop:
  if (_trace) printf("headdodoublefloatop:\n");
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  /* Get the operand */
  arg1 = *(u64 *)arg1;

begindodoublefloatop:
  if (_trace) printf("begindodoublefloatop:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  /* X high */
  arg3 = *(s32 *)(iSP + -24);
  /* X low */
  arg4 = *(s32 *)(iSP + -16);
  /* Y high */
  arg5 = *(s32 *)(iSP + -8);
  /* Y low */
  arg6 = *(s32 *)iSP;
  /* Get high part up top */
  arg3 = arg3 << 32;
  arg4 = (u32)arg4;
  /* Get high part up top */
  arg5 = arg5 << 32;
  arg6 = (u32)arg6;
  /* ARG3 is now X */
  arg3 = arg3 | arg4;
  /* ARG5 is now Y */
  arg5 = arg5 | arg6;
  *(u64 *)&processor->fp0 = arg3;
  *(u64 *)&processor->fp1 = arg5;
  /* Immediate tag */
  t2 = arg1 >> 32;
  /* Immediate data */
  t1 = (u32)arg1;
  t3 = t2 - Type_Fixnum;
  /* Strip CDR code */
  t3 = t3 & 63;
  if (t3 != 0)
    goto doublefloatiop;
  LDT(1, f1, processor->fp0);
  LDT(2, f2, processor->fp1);
  /* NIL */
  t3 = zero + DoubleFloatOp_Add;
  t3 = t1 - t3;
  if (t3 != 0)
    goto g8900;
  /* Here if argument DoubleFloatOpAdd */
  ADDT(1, f1, 1, f1, 2, f2); /* addt */
  goto g8899;

g8900:
  if (_trace) printf("g8900:\n");
  t3 = zero + DoubleFloatOp_Sub;
  t3 = t1 - t3;
  if (t3 != 0)
    goto g8901;
  /* Here if argument DoubleFloatOpSub */
  SUBT(1, f1, 1, f1, 2, f2);
  goto g8899;

g8901:
  if (_trace) printf("g8901:\n");
  t3 = zero + DoubleFloatOp_Multiply;
  t3 = t1 - t3;
  if (t3 != 0)
    goto g8902;
  /* Here if argument DoubleFloatOpMultiply */
  MULT(1, f1, 1, f1, 2, f2);
  goto g8899;

g8902:
  if (_trace) printf("g8902:\n");
  t3 = zero + DoubleFloatOp_Divide;
  t3 = t1 - t3;
  if (t3 != 0)
    goto g8903;
  /* Here if argument DoubleFloatOpDivide */
  DIVT(1, f1, 1, f1, 2, f2);
  goto g8899;

g8903:
  if (_trace) printf("g8903:\n");

g8899:
  if (_trace) printf("g8899:\n");
  /* Force the trap to occur here */
  /* trapb force the trap to occur here */
  /* There was no FP exception */
  t3 = *(u64 *)&(processor->niladdress);

doublefloatmerge:
  STT( (u64 *)&processor->fp0, 1, f1 );
  t1 = *(s32 *)&processor->fp0;
  t2 = *((s32 *)(&processor->fp0)+1);
  /* Pop all the operands */
  iSP = iSP - 32;
  t4 = Type_Fixnum;
  /* Push high result */
  *(u32 *)(iSP + 8) = t2;
  /* write the stack cache */
  *(u32 *)(iSP + 12) = t4;
  iSP = iSP + 8;
  t4 = Type_Fixnum;
  /* Push low result */
  *(u32 *)(iSP + 8) = t1;
  /* write the stack cache */
  *(u32 *)(iSP + 12) = t4;
  iSP = iSP + 8;
  iSP = iSP + 8;
  t4 = t3 << 26;
  t4 = t4 >> 26;
  /* Push the exception predicate */
  *(u64 *)iSP = t4;
  goto NEXTINSTRUCTION;

doublefloatexc:
  if (_trace) printf("doublefloatexc:\n");
  /* Indicate an FP exception occurred */
  t3 = *(u64 *)&(processor->taddress);
  goto doublefloatmerge;

doublefloatiop:
  if (_trace) printf("doublefloatiop:\n");
  arg5 = 0;
  arg2 = 85;
  goto illegaloperand;

/* end DoDoubleFloatOp */
  /* End of Halfword operand from stack instruction - DoDoubleFloatOp */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/idouble.as */
