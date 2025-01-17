/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * FROM ../alpha-emulator/ifunlist.as. ANY CHANGES MADE TO THIS FILE WILL BE LOST
 ************************************************************************/

  /* List Operations. */
/* start DoSetToCar */

  /* Halfword operand from stack instruction - DoSetToCar */
  /* arg2 has the preloaded 8 bit operand. */

dosettocar:
  if (_trace) printf("dosettocar:\n");
#ifdef TRACING
#endif

DoSetToCarSP:
  if (_trace) printf("DoSetToCarSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
    iSP = arg4;
#ifdef TRACING
  goto begindosettocar;
#endif

DoSetToCarLP:
  if (_trace) printf("DoSetToCarLP:\n");
#ifdef TRACING
  goto begindosettocar;
#endif

DoSetToCarFP:
  if (_trace) printf("DoSetToCarFP:\n");

begindosettocar:
  if (_trace) printf("begindosettocar:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  t12 = *(s32 *)&processor->scovlimit;
  /* Get the operand from the stack. */
  arg5 = *(s32 *)(arg1 + 4);
  arg6 = *(s32 *)arg1;
  /* Save the old CDR code */
  t2 = arg5 & 192;
  r0 = (u64)&&return0040;
  goto carinternal;
return0040:
  /* TagType. */
  arg5 = arg5 & 63;
  /* Put back the original CDR codes */
  arg5 = arg5 | t2;
  *(u32 *)arg1 = arg6;
  /* write the stack cache */
  *(u32 *)(arg1 + 4) = arg5;
  goto NEXTINSTRUCTION;
#ifdef TRACING
#endif

DoSetToCarIM:
  goto doistageerror;

/* end DoSetToCar */
  /* End of Halfword operand from stack instruction - DoSetToCar */
/* start DoSetToCdr */

  /* Halfword operand from stack instruction - DoSetToCdr */
  /* arg2 has the preloaded 8 bit operand. */

dosettocdr:
  if (_trace) printf("dosettocdr:\n");
#ifdef TRACING
#endif

DoSetToCdrSP:
  if (_trace) printf("DoSetToCdrSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
    iSP = arg4;
#ifdef TRACING
  goto begindosettocdr;
#endif

DoSetToCdrLP:
  if (_trace) printf("DoSetToCdrLP:\n");
#ifdef TRACING
  goto begindosettocdr;
#endif

DoSetToCdrFP:
  if (_trace) printf("DoSetToCdrFP:\n");

begindosettocdr:
  if (_trace) printf("begindosettocdr:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  t12 = *(s32 *)&processor->scovlimit;
  /* Get the operand from the stack. */
  arg5 = *(s32 *)(arg1 + 4);
  arg6 = *(s32 *)arg1;
  /* Save the old CDR code */
  t2 = arg5 & 192;
  r0 = (u64)&&return0041;
  goto cdrinternal;
return0041:
  /* TagType. */
  arg5 = arg5 & 63;
  /* Put back the original CDR codes */
  arg5 = arg5 | t2;
  *(u32 *)arg1 = arg6;
  /* write the stack cache */
  *(u32 *)(arg1 + 4) = arg5;
  goto NEXTINSTRUCTION;
#ifdef TRACING
#endif

DoSetToCdrIM:
  goto doistageerror;

/* end DoSetToCdr */
  /* End of Halfword operand from stack instruction - DoSetToCdr */
/* start SetToCdrPushCarLocative */


SetToCdrPushCarLocative:
  if (_trace) printf("SetToCdrPushCarLocative:\n");

settocdrpushcarlocative:
  if (_trace) printf("settocdrpushcarlocative:\n");
  arg2 = t2;
  /* Memory Read Internal */

g7185:
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
    goto g7187;

g7186:
  t7 = zero + 240;
  t8 = t8 >> (arg5 & 63);
  t7 = t7 >> (arg5 & 63);
  if (t8 & 1)
    goto g7189;

g7196:
  /* TagType. */
  t1 = t1 & 63;
  *(u32 *)(iSP + 8) = arg6;
  /* write the stack cache */
  *(u32 *)(iSP + 12) = arg5;
  iSP = iSP + 8;
  /* Put back the original CDR codes */
  t1 = t1 | t3;
  *(u32 *)arg1 = arg6;
  /* write the stack cache */
  *(u32 *)(arg1 + 4) = arg5;
  goto NEXTINSTRUCTION;

g7189:
  if (_trace) printf("g7189:\n");
  if ((t7 & 1) == 0)
    goto g7188;
  /* Do the indirect thing */
  arg2 = (u32)arg6;
  goto g7185;

g7188:
  if (_trace) printf("g7188:\n");

g7187:
  if (_trace) printf("g7187:\n");
  r0 = (u64)&&return0042;
  goto memoryreaddatadecode;
return0042:
  goto g7196;

/* end SetToCdrPushCarLocative */
/* start DoAssoc */

  /* Halfword operand from stack instruction - DoAssoc */
  /* arg2 has the preloaded 8 bit operand. */

doassoc:
  if (_trace) printf("doassoc:\n");
#ifdef TRACING
#endif

DoAssocSP:
  if (_trace) printf("DoAssocSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  if (arg2 != 0)
    goto begindoassoc;
  /* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  /* SP-pop mode */
  arg1 = iSP;
  /* Adjust SP */
  iSP = arg4;
#ifdef TRACING
  goto begindoassoc;
#endif

DoAssocLP:
  if (_trace) printf("DoAssocLP:\n");
#ifdef TRACING
  goto begindoassoc;
#endif

DoAssocFP:
  if (_trace) printf("DoAssocFP:\n");

begindoassoc:
  if (_trace) printf("begindoassoc:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  t12 = *(s32 *)&processor->scovlimit;
  t5 = zero + -2048;
  t5 = t5 + ((1) << 16);
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg4 = (u32)arg6;
  t1 = *(s32 *)(arg1 + 4);
  t2 = *(s32 *)arg1;
  /* TagType. */
  /* Get the object type bits */
  arg3 = arg3 & 63;
  /* Low bit will set iff EQ-NOT-EQL */
  t5 = t5 >> (arg3 & 63);
  /* TagType. */
  /* Strip cdr code */
  t1 = t1 & 63;
  /* Remove sign-extension */
  t2 = (u32)t2;
  if (t5 & 1)
    goto assocexc;
  t6 = zero;
  goto g7198;

assoccdr:
  if (_trace) printf("assoccdr:\n");
  /* Have we been asked to stop or trap? */
  t6 = *(u64 *)&(processor->stop_interpreter);
  /* Move cdr to car for next carcdr-internal */
  /* TagType. */
  t1 = arg5 & 63;
  t2 = arg6;

g7198:
  if (_trace) printf("g7198:\n");
  t5 = t1 - Type_NIL;
  /* Asked to stop, check for sequence break */
  if (t6 != 0)
    goto g7197;
  if (t5 == 0)
    goto g7199;
  r0 = (u64)&&return0043;
  goto carcdrinternal;
return0043:
  /* Strip off any CDR code bits. */
  t7 = t1 & 63;
  t8 = (t7 == Type_List) ? 1 : 0;

g7217:
  if (_trace) printf("g7217:\n");
  if (t8 == 0)
    goto g7201;
  /* Here if argument TypeList */
  arg2 = t2;
  t3 = arg5;
  arg1 = arg6;
  /* Memory Read Internal */

g7202:
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
    goto g7204;

g7203:
  t7 = zero + 240;
  t8 = t8 >> (arg5 & 63);
  t7 = t7 >> (arg5 & 63);
  if (t8 & 1)
    goto g7206;

g7213:
  /* TagType. */
  t5 = arg5 & 63;
  arg5 = t3;
  /* t6=0 if data same */
  t6 = (s32)arg4 - (s32)arg6;
  arg6 = arg1;
  /* J. if different */
  if (t6 != 0)
    goto assoccdr;
  /* t5 zero if same tag */
  t5 = arg3 - t5;
  /* J. if tags different */
  if (t5 != 0)
    goto assoccdr;
  /* we found a match! */
  /* TagType. */
  t1 = t1 & 63;
  *(u32 *)iSP = t2;
  /* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto NEXTINSTRUCTION;

g7201:
  if (_trace) printf("g7201:\n");
  t8 = (t7 == Type_NIL) ? 1 : 0;

g7218:
  if (_trace) printf("g7218:\n");
  if (t8 == 0)
    goto g7214;
  /* Here if argument TypeNIL */
  goto assoccdr;

g7214:
  if (_trace) printf("g7214:\n");
  /* Here for all other cases */
  /* SetTag. */
  t1 = arg4 << 32;
  t1 = arg5 | t1;
  arg5 = t1;
  arg2 = 14;
  goto illegaloperand;

g7200:
  if (_trace) printf("g7200:\n");

g7199:
  if (_trace) printf("g7199:\n");
  /* Return NIL */
  t1 = *(u64 *)&(processor->niladdress);
  /* push the data */
  *(u64 *)iSP = t1;
  goto NEXTINSTRUCTION;

assocexc:
  if (_trace) printf("assocexc:\n");
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 0;
  goto exception;

g7206:
  if (_trace) printf("g7206:\n");
  if ((t7 & 1) == 0)
    goto g7205;
  /* Do the indirect thing */
  arg2 = (u32)arg6;
  goto g7202;

g7205:
  if (_trace) printf("g7205:\n");

g7204:
  if (_trace) printf("g7204:\n");
  r0 = (u64)&&return0044;
  goto memoryreaddatadecode;
return0044:
  goto g7213;

g7197:
  if (_trace) printf("g7197:\n");
  iSP = *(u64 *)&(processor->restartsp);
  goto INTERPRETINSTRUCTION;
#ifdef TRACING
#endif

DoAssocIM:
  goto doistageerror;

/* end DoAssoc */
  /* End of Halfword operand from stack instruction - DoAssoc */
/* start DoMember */

  /* Halfword operand from stack instruction - DoMember */
  /* arg2 has the preloaded 8 bit operand. */

domember:
  if (_trace) printf("domember:\n");
#ifdef TRACING
#endif

DoMemberSP:
  if (_trace) printf("DoMemberSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  if (arg2 != 0)
    goto begindomember;
  /* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  /* SP-pop mode */
  arg1 = iSP;
  /* Adjust SP */
  iSP = arg4;
#ifdef TRACING
  goto begindomember;
#endif

DoMemberLP:
  if (_trace) printf("DoMemberLP:\n");
#ifdef TRACING
  goto begindomember;
#endif

DoMemberFP:
  if (_trace) printf("DoMemberFP:\n");

begindomember:
  if (_trace) printf("begindomember:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  t12 = *(s32 *)&processor->scovlimit;
  t5 = zero + -2048;
  t5 = t5 + ((1) << 16);
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg4 = (u32)arg6;
  t1 = *(s32 *)(arg1 + 4);
  t2 = *(s32 *)arg1;
  /* TagType. */
  /* Get the object type bits */
  arg3 = arg3 & 63;
  /* Low bit will set iff EQ-NOT-EQL */
  t5 = t5 >> (arg3 & 63);
  /* TagType. */
  /* Strip cdr code */
  t1 = t1 & 63;
  /* Remove sign-extension */
  t2 = (u32)t2;
  if (t5 & 1)
    goto memberexc;
  t6 = zero;
  goto g7220;

membercdr:
  if (_trace) printf("membercdr:\n");
  /* Have we been asked to stop or trap? */
  t6 = *(u64 *)&(processor->stop_interpreter);
  /* Move cdr to car for next carcdr-internal */
  /* TagType. */
  t1 = arg5 & 63;
  t2 = arg6;

g7220:
  if (_trace) printf("g7220:\n");
  /* TagType. */
  t3 = t1 & 63;
  arg1 = t2;
  t5 = t1 - Type_NIL;
  /* Asked to stop, check for sequence break */
  if (t6 != 0)
    goto g7219;
  if (t5 == 0)
    goto g7221;
  r0 = (u64)&&return0045;
  goto carcdrinternal;
return0045:
  /* TagType. */
  t5 = t1 & 63;
  /* t7=0 if data same */
  t7 = arg4 - t2;
  /* J. if different */
  if (t7 != 0)
    goto membercdr;
  /* t6 zero if same tag */
  t6 = arg3 - t5;
  /* J. if tags different */
  if (t6 != 0)
    goto membercdr;
  /* we found a match! */
  *(u32 *)iSP = arg1;
  /* write the stack cache */
  *(u32 *)(iSP + 4) = t3;
  goto NEXTINSTRUCTION;

g7221:
  if (_trace) printf("g7221:\n");
  /* Return NIL */
  t1 = *(u64 *)&(processor->niladdress);
  /* push the data */
  *(u64 *)iSP = t1;
  goto NEXTINSTRUCTION;

memberexc:
  if (_trace) printf("memberexc:\n");
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 0;
  goto exception;

g7219:
  if (_trace) printf("g7219:\n");
  iSP = *(u64 *)&(processor->restartsp);
  goto INTERPRETINSTRUCTION;
#ifdef TRACING
#endif

DoMemberIM:
  goto doistageerror;

/* end DoMember */
  /* End of Halfword operand from stack instruction - DoMember */
/* start DoRgetf */

  /* Halfword operand from stack instruction - DoRgetf */
  /* arg2 has the preloaded 8 bit operand. */

dorgetf:
  if (_trace) printf("dorgetf:\n");
#ifdef TRACING
#endif

DoRgetfSP:
  if (_trace) printf("DoRgetfSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  if (arg2 != 0)
    goto begindorgetf;
  /* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  /* SP-pop mode */
  arg1 = iSP;
  /* Adjust SP */
  iSP = arg4;
#ifdef TRACING
  goto begindorgetf;
#endif

DoRgetfLP:
  if (_trace) printf("DoRgetfLP:\n");
#ifdef TRACING
  goto begindorgetf;
#endif

DoRgetfFP:
  if (_trace) printf("DoRgetfFP:\n");

begindorgetf:
  if (_trace) printf("begindorgetf:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  t12 = *(s32 *)&processor->scovlimit;
  t5 = zero + -2048;
  t5 = t5 + ((1) << 16);
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg4 = (u32)arg6;
  t1 = *(s32 *)(arg1 + 4);
  t2 = *(s32 *)arg1;
  /* TagType. */
  /* Get the object type bits */
  arg3 = arg3 & 63;
  /* Low bit will set iff EQ-NOT-EQL */
  t5 = t5 >> (arg3 & 63);
  /* TagType. */
  /* Strip cdr code */
  t1 = t1 & 63;
  /* Remove sign-extension */
  t2 = (u32)t2;
  if (t5 & 1)
    goto rgetfexc;
  t6 = zero;
  goto g7223;

rgetfcdr:
  if (_trace) printf("rgetfcdr:\n");
  r0 = (u64)&&return0046;
  goto cdrinternal;
return0046:
  /* Have we been asked to stop or trap? */
  t6 = *(u64 *)&(processor->stop_interpreter);
  /* Move cdr to car for next carcdr-internal */
  /* TagType. */
  t1 = arg5 & 63;
  t2 = arg6;

g7223:
  if (_trace) printf("g7223:\n");
  t5 = t1 - Type_NIL;
  /* Asked to stop, check for sequence break */
  if (t6 != 0)
    goto g7222;
  if (t5 == 0)
    goto g7224;
  r0 = (u64)&&return0047;
  goto carcdrinternal;
return0047:
  /* TagType. */
  t5 = t1 & 63;
  /* t7=0 if data same */
  t7 = arg4 - t2;
  /* J. if different */
  if (t7 != 0)
    goto rgetfcdr;
  /* t6 zero if same tag */
  t6 = arg3 - t5;
  /* J. if tags different */
  if (t6 != 0)
    goto rgetfcdr;
  /* we found a match! */
  /* TagType. */
  /* Strip CDR code */
  t1 = arg5 & 63;
  /* t5=0 if end of list */
  t5 = t1 - Type_NIL;
  /* after all this effort we lose! */
  if (t5 == 0)
    goto rgetfexc;
  t2 = arg6;
  r0 = (u64)&&return0048;
  goto carinternal;
return0048:
  /* TagType. */
  /* Strip the CDR code */
  arg5 = arg5 & 63;
  *(u32 *)iSP = arg6;
  /* write the stack cache */
  *(u32 *)(iSP + 4) = arg5;
  /* set CDR-NEXT */
  arg2 = t1 & 63;
  /* Push the second result */
  *(u32 *)(iSP + 8) = t2;
  /* write the stack cache */
  *(u32 *)(iSP + 12) = arg2;
  iSP = iSP + 8;
  goto NEXTINSTRUCTION;

g7224:
  if (_trace) printf("g7224:\n");
  /* Return NIL */
  arg2 = *(u64 *)&(processor->niladdress);
  *(u64 *)iSP = arg2;
  /* push the data */
  *(u64 *)(iSP + 8) = arg2;
  iSP = iSP + 8;
  goto NEXTINSTRUCTION;

rgetfexc:
  if (_trace) printf("rgetfexc:\n");
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 0;
  goto exception;

g7222:
  if (_trace) printf("g7222:\n");
  iSP = *(u64 *)&(processor->restartsp);
  goto INTERPRETINSTRUCTION;
#ifdef TRACING
#endif

DoRgetfIM:
  goto doistageerror;

/* end DoRgetf */
  /* End of Halfword operand from stack instruction - DoRgetf */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/ifunlist.as */
