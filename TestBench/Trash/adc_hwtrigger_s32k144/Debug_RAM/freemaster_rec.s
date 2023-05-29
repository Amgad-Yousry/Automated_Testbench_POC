	.syntax unified
	.cpu cortex-m4
	.eabi_attribute 27, 1
	.eabi_attribute 28, 1
	.fpu fpv4-sp-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 1
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"freemaster_rec.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.FMSTR_Compare8S,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare8S, %function
FMSTR_Compare8S:
.LFB11:
	.file 1 "../FreeMASTER/src_common/freemaster_rec.c"
	.loc 1 695 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 696 0
	ldr	r3, .L2
	ldr	r3, [r3]
	ldrsb	r0, [r3]
	ldr	r3, .L2+4
	ldrsb	r3, [r3]
	.loc 1 697 0
	cmp	r0, r3
	ite	lt
	movlt	r0, #0
	movge	r0, #1
	bx	lr
.L3:
	.align	2
.L2:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE11:
	.size	FMSTR_Compare8S, .-FMSTR_Compare8S
	.section	.text.FMSTR_Compare8U,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare8U, %function
FMSTR_Compare8U:
.LFB12:
	.loc 1 700 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 701 0
	ldr	r3, .L5
	ldr	r3, [r3]
	ldrb	r0, [r3]	@ zero_extendqisi2
	ldr	r3, .L5+4
	ldrb	r3, [r3]	@ zero_extendqisi2
	.loc 1 702 0
	cmp	r0, r3
	ite	cc
	movcc	r0, #0
	movcs	r0, #1
	bx	lr
.L6:
	.align	2
.L5:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE12:
	.size	FMSTR_Compare8U, .-FMSTR_Compare8U
	.section	.text.FMSTR_Compare16S,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare16S, %function
FMSTR_Compare16S:
.LFB13:
	.loc 1 707 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 708 0
	ldr	r3, .L8
	ldr	r3, [r3]
	ldrsh	r0, [r3]
	ldr	r3, .L8+4
	ldrsh	r3, [r3]
	.loc 1 709 0
	cmp	r0, r3
	ite	lt
	movlt	r0, #0
	movge	r0, #1
	bx	lr
.L9:
	.align	2
.L8:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE13:
	.size	FMSTR_Compare16S, .-FMSTR_Compare16S
	.section	.text.FMSTR_Compare16U,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare16U, %function
FMSTR_Compare16U:
.LFB14:
	.loc 1 712 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 713 0
	ldr	r3, .L11
	ldr	r3, [r3]
	ldrh	r0, [r3]
	ldr	r3, .L11+4
	ldrh	r3, [r3]
	.loc 1 714 0
	cmp	r0, r3
	ite	cc
	movcc	r0, #0
	movcs	r0, #1
	bx	lr
.L12:
	.align	2
.L11:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE14:
	.size	FMSTR_Compare16U, .-FMSTR_Compare16U
	.section	.text.FMSTR_Compare32S,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare32S, %function
FMSTR_Compare32S:
.LFB15:
	.loc 1 717 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 718 0
	ldr	r3, .L14
	ldr	r3, [r3]
	ldr	r0, [r3]
	ldr	r3, .L14+4
	ldr	r3, [r3]
	.loc 1 719 0
	cmp	r0, r3
	ite	lt
	movlt	r0, #0
	movge	r0, #1
	bx	lr
.L15:
	.align	2
.L14:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE15:
	.size	FMSTR_Compare32S, .-FMSTR_Compare32S
	.section	.text.FMSTR_Compare32U,"ax",%progbits
	.align	2
	.thumb
	.thumb_func
	.type	FMSTR_Compare32U, %function
FMSTR_Compare32U:
.LFB16:
	.loc 1 722 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 723 0
	ldr	r3, .L17
	ldr	r3, [r3]
	ldr	r0, [r3]
	ldr	r3, .L17+4
	ldr	r3, [r3]
	.loc 1 724 0
	cmp	r0, r3
	ite	cc
	movcc	r0, #0
	movcs	r0, #1
	bx	lr
.L18:
	.align	2
.L17:
	.word	.LANCHOR0
	.word	.LANCHOR1
	.cfi_endproc
.LFE16:
	.size	FMSTR_Compare32U, .-FMSTR_Compare32U
	.section	.text.FMSTR_InitRec,"ax",%progbits
	.align	2
	.global	FMSTR_InitRec
	.thumb
	.thumb_func
	.type	FMSTR_InitRec, %function
FMSTR_InitRec:
.LFB0:
	.loc 1 139 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 141 0
	movs	r2, #0
	ldr	r3, .L20
	strb	r2, [r3]
	.loc 1 155 0
	ldr	r2, .L20+4
	ldr	r3, .L20+8
	str	r2, [r3]
	bx	lr
.L21:
	.align	2
.L20:
	.word	pcm_wRecFlags
	.word	.LANCHOR3
	.word	.LANCHOR2
	.cfi_endproc
.LFE0:
	.size	FMSTR_InitRec, .-FMSTR_InitRec
	.section	.text.FMSTR_SetUpRecBuff,"ax",%progbits
	.align	2
	.global	FMSTR_SetUpRecBuff
	.thumb
	.thumb_func
	.type	FMSTR_SetUpRecBuff, %function
FMSTR_SetUpRecBuff:
.LFB2:
	.loc 1 186 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.LVL0:
	bx	lr
	.cfi_endproc
.LFE2:
	.size	FMSTR_SetUpRecBuff, .-FMSTR_SetUpRecBuff
	.section	.text.FMSTR_SetUpRec,"ax",%progbits
	.align	2
	.global	FMSTR_SetUpRec
	.thumb
	.thumb_func
	.type	FMSTR_SetUpRec, %function
FMSTR_SetUpRec:
.LFB3:
	.loc 1 208 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
.LVL1:
	.loc 1 208 0
	push	{r4, r5, r6, r7, r8, r9, r10, lr}
	.cfi_def_cfa_offset 32
	.cfi_offset 4, -32
	.cfi_offset 5, -28
	.cfi_offset 6, -24
	.cfi_offset 7, -20
	.cfi_offset 8, -16
	.cfi_offset 9, -12
	.cfi_offset 10, -8
	.cfi_offset 14, -4
	mov	r7, r0
.LVL2:
.LBB6:
.LBB7:
	.loc 1 171 0
	movs	r2, #0
	ldr	r3, .L49
	strb	r2, [r3]
.LBE7:
.LBE6:
	.loc 1 226 0
	ldr	r2, .L49+4
	ldr	r3, .L49+8
	str	r2, [r3]
.LVL3:
	.loc 1 232 0
	ldrb	r2, [r0, #2]	@ zero_extendqisi2
	ldr	r3, .L49+12
	strb	r2, [r3]
.LVL4:
	.loc 1 237 0
	ldr	r0, .L49+16
.LVL5:
	adds	r1, r7, #3
.LVL6:
	bl	FMSTR_ValueFromBuffer16
.LVL7:
	mov	r1, r0
.LVL8:
	.loc 1 240 0
	ldr	r0, .L49+20
.LVL9:
	bl	FMSTR_ValueFromBuffer16
.LVL10:
	mov	r1, r0
.LVL11:
	.loc 1 246 0
	ldr	r0, .L49+24
.LVL12:
	bl	FMSTR_ValueFromBuffer16
.LVL13:
	mov	r1, r0
.LVL14:
	.loc 1 253 0
	ldr	r0, .L49+28
.LVL15:
	bl	FMSTR_AddressFromBuffer
.LVL16:
	mov	r1, r0
.LVL17:
	.loc 1 254 0
	ldrb	r2, [r0]	@ zero_extendqisi2
	ldr	r3, .L49+32
	strb	r2, [r3]
.LVL18:
	.loc 1 257 0
	ldrb	r2, [r0, #1]	@ zero_extendqisi2
	ldr	r3, .L49+36
	strb	r2, [r3]
.LVL19:
	.loc 1 260 0
	ldr	r0, .L49+40
.LVL20:
	adds	r1, r1, #2
.LVL21:
	bl	FMSTR_ValueFromBuffer32
.LVL22:
	.loc 1 266 0
	ldrb	r2, [r0]	@ zero_extendqisi2
	ldr	r3, .L49+44
	strb	r2, [r3]
.LVL23:
	.loc 1 269 0
	subs	r3, r2, #1
	uxtb	r3, r3
	cmp	r3, #7
	bhi	.L36
.LVL24:
	.loc 1 283 0 discriminator 1
	cmp	r2, #0
	beq	.L25
	.loc 1 266 0
	adds	r0, r0, #1
.LVL25:
	movs	r5, #0
	mov	r6, r5
	.loc 1 288 0
	ldr	r9, .L49+80
	.loc 1 292 0
	ldr	r8, .L49+84
	.loc 1 283 0
	ldr	r10, .L49+44
.LVL26:
.L26:
	.loc 1 286 0
	mov	r1, r0
	ldrb	r4, [r1], #1	@ zero_extendqisi2
.LVL27:
	.loc 1 288 0
	strb	r4, [r9, r5]
	.loc 1 289 0
	add	r6, r6, r4
.LVL28:
	uxtb	r6, r6
.LVL29:
	.loc 1 292 0
	add	r0, r8, r5, lsl #2
	bl	FMSTR_AddressFromBuffer
.LVL30:
	.loc 1 295 0
	subs	r4, r4, #1
.LVL31:
	uxtb	r4, r4
.LVL32:
	cmp	r4, #7
	bhi	.L37
	.loc 1 283 0 discriminator 2
	adds	r5, r5, #1
.LVL33:
	uxtb	r5, r5
.LVL34:
	ldrb	r3, [r10]	@ zero_extendqisi2
	cmp	r3, r5
	bhi	.L26
	.loc 1 334 0
	movs	r2, #0
	ldr	r3, .L49+48
	str	r2, [r3]
	.loc 1 335 0
	ldr	r3, .L49+12
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #0
	beq	.L27
	b	.L34
.LVL35:
.L44:
	movs	r6, #0
.LVL36:
.L34:
	.loc 1 358 0
	ldr	r3, .L49+36
	ldrb	r3, [r3]	@ zero_extendqisi2
	tst	r3, #2
	bne	.L38
	.loc 1 369 0
	ldr	r2, .L49+32
	ldrb	r2, [r2]	@ zero_extendqisi2
	cmp	r2, #2
	beq	.L28
	cmp	r2, #4
	beq	.L29
	cmp	r2, #1
	bne	.L46
	.loc 1 372 0
	ldr	r1, .L49+52
	ldr	r2, .L49+56
	cmp	r3, #0
	ite	ne
	movne	r3, r2
	moveq	r3, r1
	ldr	r2, .L49+48
	str	r3, [r2]
	b	.L27
.L28:
	.loc 1 374 0
	ldr	r1, .L49+60
	ldr	r2, .L49+64
	cmp	r3, #0
	ite	ne
	movne	r3, r2
	moveq	r3, r1
	ldr	r2, .L49+48
	str	r3, [r2]
	b	.L27
.L29:
	.loc 1 375 0
	ldr	r1, .L49+68
	ldr	r2, .L49+72
	cmp	r3, #0
	ite	ne
	movne	r3, r2
	moveq	r3, r1
	ldr	r2, .L49+48
	str	r3, [r2]
.L27:
	.loc 1 391 0
	ldr	r3, .L49+16
	ldrh	r3, [r3]
	smulbb	r6, r3, r6
	uxth	r6, r6
.LVL37:
	.loc 1 394 0
	cmp	r6, #512
	bhi	.L43
.LVL38:
.L35:
	.loc 1 406 0
	ldr	r3, .L49+8
	ldr	r3, [r3]
	add	r6, r6, r3
.LVL39:
	ldr	r3, .L49+76
	str	r6, [r3]
	.loc 1 422 0
	ldr	r2, .L49
	ldrb	r3, [r2]	@ zero_extendqisi2
	orr	r3, r3, #1
	strb	r3, [r2]
.LVL40:
	.loc 1 423 0
	movs	r3, #0
	b	.L24
.LVL41:
.L36:
	.loc 1 274 0
	movs	r3, #133
	b	.L24
.LVL42:
.L37:
	.loc 1 300 0
	movs	r3, #134
	b	.L24
.LVL43:
.L38:
	.loc 1 363 0
	movs	r3, #144
	b	.L24
.L46:
	.loc 1 382 0
	movs	r3, #134
	b	.L24
.LVL44:
.L43:
	.loc 1 399 0
	movs	r3, #134
	b	.L24
.LVL45:
.L25:
	.loc 1 334 0
	movs	r2, #0
	ldr	r3, .L49+48
	str	r2, [r3]
	.loc 1 335 0
	ldr	r3, .L49+12
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L44
	.loc 1 391 0
	mov	r6, r2
	b	.L35
.LVL46:
.L24:
	.loc 1 430 0
	mov	r0, r7
	strb	r3, [r0], #1
	.loc 1 431 0
	pop	{r4, r5, r6, r7, r8, r9, r10, pc}
.LVL47:
.L50:
	.align	2
.L49:
	.word	pcm_wRecFlags
	.word	.LANCHOR3
	.word	.LANCHOR2
	.word	pcm_nRecTriggerMode
	.word	pcm_wRecTotalSmps
	.word	pcm_wRecPostTrigger
	.word	pcm_wRecTimeDiv
	.word	.LANCHOR0
	.word	.LANCHOR4
	.word	.LANCHOR5
	.word	.LANCHOR1
	.word	pcm_nRecVarCount
	.word	.LANCHOR6
	.word	FMSTR_Compare8U
	.word	FMSTR_Compare8S
	.word	FMSTR_Compare16U
	.word	FMSTR_Compare16S
	.word	FMSTR_Compare32U
	.word	FMSTR_Compare32S
	.word	pcm_dwRecEndBuffPtr
	.word	pcm_pRecVarSize
	.word	pcm_pRecVarAddr
	.cfi_endproc
.LFE3:
	.size	FMSTR_SetUpRec, .-FMSTR_SetUpRec
	.section	.text.FMSTR_TriggerRec,"ax",%progbits
	.align	2
	.global	FMSTR_TriggerRec
	.thumb
	.thumb_func
	.type	FMSTR_TriggerRec, %function
FMSTR_TriggerRec:
.LFB4:
	.loc 1 442 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 443 0
	ldr	r3, .L53
	ldr	r3, [r3]
	tst	r3, #4
	bne	.L51
	.loc 1 445 0
	ldr	r2, .L53
	ldrb	r3, [r2]	@ zero_extendqisi2
	orr	r3, r3, #4
	strb	r3, [r2]
	.loc 1 447 0
	ldr	r3, .L53+4
	ldrh	r2, [r3]
	ldr	r3, .L53+8
	strh	r2, [r3]	@ movhi
.L51:
	bx	lr
.L54:
	.align	2
.L53:
	.word	pcm_wRecFlags
	.word	pcm_wRecPostTrigger
	.word	pcm_wStoprecCountDown
	.cfi_endproc
.LFE4:
	.size	FMSTR_TriggerRec, .-FMSTR_TriggerRec
	.section	.text.FMSTR_StartRec,"ax",%progbits
	.align	2
	.global	FMSTR_StartRec
	.thumb
	.thumb_func
	.type	FMSTR_StartRec, %function
FMSTR_StartRec:
.LFB5:
	.loc 1 469 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.LVL48:
	.loc 1 472 0
	ldr	r3, .L59
	ldr	r3, [r3]
	tst	r3, #1
	beq	.L57
	.loc 1 483 0
	ldr	r3, .L59
	ldr	r3, [r3]
	tst	r3, #2
	bne	.L58
	.loc 1 495 0
	ldr	r3, .L59+4
	ldr	r2, [r3]
	ldr	r3, .L59+8
	str	r2, [r3]
	.loc 1 498 0
	movs	r3, #0
	ldr	r2, .L59+12
	strh	r3, [r2]	@ movhi
	.loc 1 503 0
	ldr	r2, .L59+16
	strh	r3, [r2]	@ movhi
	.loc 1 507 0
	ldr	r2, .L59
	ldrb	r1, [r2]	@ zero_extendqisi2
	bfi	r1, r3, #2, #1
	strb	r1, [r2]
	.loc 1 508 0
	ldrb	r1, [r2]	@ zero_extendqisi2
	bfi	r1, r3, #4, #1
	strb	r1, [r2]
	.loc 1 509 0
	ldrb	r1, [r2]	@ zero_extendqisi2
	orr	r1, r1, #8
	strb	r1, [r2]
	.loc 1 518 0
	ldrb	r1, [r2]	@ zero_extendqisi2
	orr	r1, r1, #2
	strb	r1, [r2]
.LVL49:
	b	.L56
.LVL50:
.L57:
	.loc 1 477 0
	movs	r3, #136
	b	.L56
.L58:
	.loc 1 488 0
	movs	r3, #1
.L56:
.LVL51:
	.loc 1 528 0
	strb	r3, [r0], #1
.LVL52:
	.loc 1 529 0
	bx	lr
.L60:
	.align	2
.L59:
	.word	pcm_wRecFlags
	.word	.LANCHOR2
	.word	pcm_dwRecWritePtr
	.word	pcm_wRecBuffStartIx
	.word	pcm_wRecTimeDivCtr
	.cfi_endproc
.LFE5:
	.size	FMSTR_StartRec, .-FMSTR_StartRec
	.section	.text.FMSTR_StopRec,"ax",%progbits
	.align	2
	.global	FMSTR_StopRec
	.thumb
	.thumb_func
	.type	FMSTR_StopRec, %function
FMSTR_StopRec:
.LFB6:
	.loc 1 545 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
.LVL53:
	push	{r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	mov	r4, r0
	.loc 1 548 0
	ldr	r3, .L66
	ldr	r3, [r3]
	tst	r3, #1
	beq	.L63
	.loc 1 555 0
	ldr	r3, .L66
	ldr	r3, [r3]
	tst	r3, #2
	beq	.L64
	.loc 1 562 0
	bl	FMSTR_TriggerRec
.LVL54:
	.loc 1 563 0
	movs	r3, #0
	b	.L62
.LVL55:
.L63:
	.loc 1 550 0
	movs	r3, #136
	b	.L62
.L64:
	.loc 1 557 0
	movs	r3, #2
.LVL56:
.L62:
	.loc 1 566 0
	mov	r0, r4
	strb	r3, [r0], #1
	.loc 1 567 0
	pop	{r4, pc}
.LVL57:
.L67:
	.align	2
.L66:
	.word	pcm_wRecFlags
	.cfi_endproc
.LFE6:
	.size	FMSTR_StopRec, .-FMSTR_StopRec
	.section	.text.FMSTR_GetRecStatus,"ax",%progbits
	.align	2
	.global	FMSTR_GetRecStatus
	.thumb
	.thumb_func
	.type	FMSTR_GetRecStatus, %function
FMSTR_GetRecStatus:
.LFB7:
	.loc 1 583 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.LVL58:
	.loc 1 584 0
	ldr	r3, .L72
	ldr	r3, [r3]
	ubfx	r3, r3, #1, #1
	cmp	r3, #0
	ite	ne
	movne	r3, #1
	moveq	r3, #2
.LVL59:
	.loc 1 588 0
	ldr	r2, .L72
	ldr	r2, [r2]
	and	r2, r2, #1
	.loc 1 590 0
	cmp	r2, #0
	it	eq
	moveq	r3, #136
.LVL60:
	.loc 1 594 0
	strb	r3, [r0], #1
.LVL61:
	.loc 1 595 0
	bx	lr
.L73:
	.align	2
.L72:
	.word	pcm_wRecFlags
	.cfi_endproc
.LFE7:
	.size	FMSTR_GetRecStatus, .-FMSTR_GetRecStatus
	.section	.text.FMSTR_GetRecBuffSize,"ax",%progbits
	.align	2
	.global	FMSTR_GetRecBuffSize
	.thumb
	.thumb_func
	.type	FMSTR_GetRecBuffSize, %function
FMSTR_GetRecBuffSize:
.LFB8:
	.loc 1 609 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 1 615 0
	mov	r0, #512
	bx	lr
	.cfi_endproc
.LFE8:
	.size	FMSTR_GetRecBuffSize, .-FMSTR_GetRecBuffSize
	.section	.text.FMSTR_IsInRecBuffer,"ax",%progbits
	.align	2
	.global	FMSTR_IsInRecBuffer
	.thumb
	.thumb_func
	.type	FMSTR_IsInRecBuffer, %function
FMSTR_IsInRecBuffer:
.LFB9:
	.loc 1 632 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
.LVL62:
	.loc 1 635 0
	ldr	r3, .L78
	ldr	r3, [r3]
	cmp	r3, r0
	bhi	.L77
	.loc 1 637 0
	add	r0, r0, r1
.LVL63:
	add	r3, r3, #512
	.loc 1 633 0
	cmp	r3, r0
	ite	cc
	movcc	r0, #0
	movcs	r0, #1
	bx	lr
.LVL64:
.L77:
	movs	r0, #0
.LVL65:
	.loc 1 641 0
	bx	lr
.L79:
	.align	2
.L78:
	.word	.LANCHOR2
	.cfi_endproc
.LFE9:
	.size	FMSTR_IsInRecBuffer, .-FMSTR_IsInRecBuffer
	.section	.text.FMSTR_GetRecBuff,"ax",%progbits
	.align	2
	.global	FMSTR_GetRecBuff
	.thumb
	.thumb_func
	.type	FMSTR_GetRecBuff, %function
FMSTR_GetRecBuff:
.LFB10:
	.loc 1 658 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
.LVL66:
	.loc 1 661 0
	ldr	r3, .L86
	ldr	r3, [r3]
	tst	r3, #1
	bne	.L81
	.loc 1 663 0
	movs	r3, #136
	strb	r3, [r0], #1
.LVL67:
	.loc 1 676 0
	bx	lr
.LVL68:
.L81:
	.loc 1 667 0
	ldr	r3, .L86
	ldr	r3, [r3]
	tst	r3, #2
	beq	.L83
	.loc 1 669 0
	movs	r3, #135
	strb	r3, [r0], #1
.LVL69:
	bx	lr
.LVL70:
.L83:
	.loc 1 658 0
	push	{lr}
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	.loc 1 673 0
	movs	r3, #0
	strb	r3, [r0], #1
.LVL71:
	str	r0, [sp, #4]
	.loc 1 674 0
	ldr	r0, [sp, #4]
.LVL72:
	ldr	r3, .L86+4
	ldr	r1, [r3]
	bl	FMSTR_AddressToBuffer
.LVL73:
	str	r0, [sp, #4]
.LVL74:
	.loc 1 675 0
	ldr	r0, [sp, #4]
	ldr	r3, .L86+8
	ldrh	r1, [r3]
	bl	FMSTR_ValueToBuffer16
.LVL75:
	.loc 1 676 0
	add	sp, sp, #12
	.cfi_def_cfa_offset 4
	@ sp needed
	ldr	pc, [sp], #4
.L87:
	.align	2
.L86:
	.word	pcm_wRecFlags
	.word	.LANCHOR2
	.word	pcm_wRecBuffStartIx
	.cfi_endproc
.LFE10:
	.size	FMSTR_GetRecBuff, .-FMSTR_GetRecBuff
	.section	.text.FMSTR_Recorder,"ax",%progbits
	.align	2
	.global	FMSTR_Recorder
	.thumb
	.thumb_func
	.type	FMSTR_Recorder, %function
FMSTR_Recorder:
.LFB17:
	.loc 1 748 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 1 750 0
	ldr	r3, .L101
	ldr	r3, [r3]
	tst	r3, #2
	beq	.L100
.LBB12:
.LBB13:
	.loc 1 777 0
	ldr	r3, .L101+4
	ldrh	r3, [r3]
	cbz	r3, .L90
	.loc 1 780 0
	subs	r3, r3, #1
	ldr	r2, .L101+4
	strh	r3, [r2]	@ movhi
.L100:
	bx	lr
.L90:
.LBE13:
.LBE12:
	.loc 1 748 0
	push	{r4, r5, r6, r7, r8, lr}
	.cfi_def_cfa_offset 24
	.cfi_offset 4, -24
	.cfi_offset 5, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	.cfi_offset 8, -8
	.cfi_offset 14, -4
.LBB15:
.LBB14:
	.loc 1 786 0
	ldr	r3, .L101+8
	ldrh	r2, [r3]
	ldr	r3, .L101+4
	strh	r2, [r3]	@ movhi
.LVL76:
	.loc 1 793 0
	ldr	r3, .L101+12
	ldrb	r3, [r3]	@ zero_extendqisi2
	cbz	r3, .L91
	movs	r4, #0
	.loc 1 795 0
	ldr	r8, .L101+48
	.loc 1 796 0
	ldr	r6, .L101+16
	ldr	r7, .L101+20
.LVL77:
.L92:
	.loc 1 795 0
	ldrb	r5, [r8, r4]	@ zero_extendqisi2
.LVL78:
	.loc 1 796 0
	ldr	r0, [r6]
	ldr	r1, [r7, r4, lsl #2]
	mov	r2, r5
	bl	FMSTR_CopyMemory
.LVL79:
	.loc 1 798 0
	ldr	r3, [r6]
	add	r5, r5, r3
.LVL80:
	str	r5, [r6]
	.loc 1 793 0
	adds	r4, r4, #1
.LVL81:
	uxtb	r4, r4
.LVL82:
	ldr	r3, .L101+12
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, r4
	bhi	.L92
.LVL83:
.L91:
	.loc 1 803 0
	ldr	r2, .L101+24
	ldrh	r3, [r2]
	adds	r3, r3, #1
	strh	r3, [r2]	@ movhi
	.loc 1 806 0
	ldr	r3, .L101+16
	ldr	r2, [r3]
	ldr	r3, .L101+28
	ldr	r3, [r3]
	cmp	r2, r3
	bcc	.L93
	.loc 1 808 0
	ldr	r3, .L101+32
	ldr	r2, [r3]
	ldr	r3, .L101+16
	str	r2, [r3]
	.loc 1 809 0
	ldr	r2, .L101
	ldrb	r3, [r2]	@ zero_extendqisi2
	bfc	r3, #3, #1
	strb	r3, [r2]
	.loc 1 810 0
	movs	r2, #0
	ldr	r3, .L101+24
	strh	r2, [r3]	@ movhi
.L93:
	.loc 1 814 0
	ldr	r3, .L101
	ldr	r3, [r3]
	tst	r3, #8
	bne	.L88
	.loc 1 820 0
	ldr	r3, .L101
	ldr	r3, [r3]
	tst	r3, #4
	bne	.L94
	ldr	r3, .L101+36
	ldr	r3, [r3]
	cbz	r3, .L94
	.loc 1 823 0
	blx	r3
.LVL84:
	.loc 1 826 0
	ldr	r3, .L101+40
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #2
	.loc 1 828 0
	itt	eq
	clzeq	r0, r0
.LVL85:
	lsreq	r0, r0, #5
.LVL86:
	.loc 1 832 0
	cbz	r0, .L96
	.loc 1 835 0
	ldr	r3, .L101
	ldr	r3, [r3]
	tst	r3, #16
	beq	.L94
	.loc 1 838 0
	bl	FMSTR_TriggerRec
.LVL87:
	b	.L94
.LVL88:
.L96:
	.loc 1 844 0
	ldr	r2, .L101
	ldrb	r3, [r2]	@ zero_extendqisi2
	orr	r3, r3, #16
	strb	r3, [r2]
.LVL89:
.L94:
	.loc 1 849 0
	ldr	r3, .L101
	ldr	r3, [r3]
	tst	r3, #4
	beq	.L88
	.loc 1 852 0
	ldr	r3, .L101+44
	ldrh	r3, [r3]
	cbnz	r3, .L97
	.loc 1 855 0
	ldr	r2, .L101
	ldrb	r3, [r2]	@ zero_extendqisi2
	bfc	r3, #1, #1
	strb	r3, [r2]
	pop	{r4, r5, r6, r7, r8, pc}
.L97:
	.loc 1 860 0
	subs	r3, r3, #1
	ldr	r2, .L101+44
	strh	r3, [r2]	@ movhi
.L88:
	pop	{r4, r5, r6, r7, r8, pc}
.L102:
	.align	2
.L101:
	.word	pcm_wRecFlags
	.word	pcm_wRecTimeDivCtr
	.word	pcm_wRecTimeDiv
	.word	pcm_nRecVarCount
	.word	pcm_dwRecWritePtr
	.word	pcm_pRecVarAddr
	.word	pcm_wRecBuffStartIx
	.word	pcm_dwRecEndBuffPtr
	.word	.LANCHOR2
	.word	.LANCHOR6
	.word	pcm_nRecTriggerMode
	.word	pcm_wStoprecCountDown
	.word	pcm_pRecVarSize
.LBE14:
.LBE15:
	.cfi_endproc
.LFE17:
	.size	FMSTR_Recorder, .-FMSTR_Recorder
	.comm	pcm_dwRecEndBuffPtr,4,4
	.comm	pcm_dwRecWritePtr,4,4
	.comm	pcm_wRecBuffStartIx,2,2
	.comm	pcm_wRecFlags,4,4
	.comm	pcm_wStoprecCountDown,2,2
	.comm	pcm_wRecTimeDivCtr,2,2
	.comm	pcm_pRecVarSize,8,4
	.comm	pcm_pRecVarAddr,32,4
	.comm	pcm_nRecVarCount,1,1
	.comm	pcm_wRecTimeDiv,2,2
	.comm	pcm_nRecTriggerMode,1,1
	.comm	pcm_wRecPostTrigger,2,2
	.comm	pcm_wRecTotalSmps,2,2
	.section	.bss.pcm_pCompareFunc,"aw",%nobits
	.align	2
	.set	.LANCHOR6,. + 0
	.type	pcm_pCompareFunc, %object
	.size	pcm_pCompareFunc, 4
pcm_pCompareFunc:
	.space	4
	.section	.bss.pcm_uTrgThreshold,"aw",%nobits
	.align	2
	.set	.LANCHOR1,. + 0
	.type	pcm_uTrgThreshold, %object
	.size	pcm_uTrgThreshold, 4
pcm_uTrgThreshold:
	.space	4
	.section	.bss.pcm_bTrgVarSigned,"aw",%nobits
	.set	.LANCHOR5,. + 0
	.type	pcm_bTrgVarSigned, %object
	.size	pcm_bTrgVarSigned, 1
pcm_bTrgVarSigned:
	.space	1
	.section	.bss.pcm_nTrgVarAddr,"aw",%nobits
	.align	2
	.set	.LANCHOR0,. + 0
	.type	pcm_nTrgVarAddr, %object
	.size	pcm_nTrgVarAddr, 4
pcm_nTrgVarAddr:
	.space	4
	.section	.bss.pcm_nRecBuffAddr,"aw",%nobits
	.align	2
	.set	.LANCHOR2,. + 0
	.type	pcm_nRecBuffAddr, %object
	.size	pcm_nRecBuffAddr, 4
pcm_nRecBuffAddr:
	.space	4
	.section	.bss.pcm_pOwnRecBuffer,"aw",%nobits
	.align	2
	.set	.LANCHOR3,. + 0
	.type	pcm_pOwnRecBuffer, %object
	.size	pcm_pOwnRecBuffer, 512
pcm_pOwnRecBuffer:
	.space	512
	.section	.bss.pcm_nTrgVarSize,"aw",%nobits
	.set	.LANCHOR4,. + 0
	.type	pcm_nTrgVarSize, %object
	.size	pcm_nTrgVarSize, 1
pcm_nTrgVarSize:
	.space	1
	.text
.Letext0:
	.file 2 "C:/NXP/S32DS_ARM_v2.0/S32DS/FreeMASTER_Serial_Communication_Driver_V2_0/src_platforms/S32xx/freemaster.h"
	.file 3 "C:/NXP/S32DS_ARM_v2.0/S32DS/FreeMASTER_Serial_Communication_Driver_V2_0/src_platforms/S32xx/freemaster_S32xx.h"
	.file 4 "../FreeMASTER/src_common/freemaster_rec.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x824
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF849
	.byte	0x1
	.4byte	.LASF850
	.4byte	.LASF851
	.4byte	.Ldebug_ranges0+0x18
	.4byte	0
	.4byte	.Ldebug_line0
	.4byte	.Ldebug_macro0
	.uleb128 0x2
	.4byte	.LASF770
	.byte	0x2
	.byte	0x21
	.4byte	0x34
	.uleb128 0x3
	.byte	0x4
	.4byte	0x3a
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF767
	.uleb128 0x4
	.byte	0x2
	.byte	0x7
	.4byte	.LASF768
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF769
	.uleb128 0x2
	.4byte	.LASF771
	.byte	0x2
	.byte	0x24
	.4byte	0x3a
	.uleb128 0x2
	.4byte	.LASF772
	.byte	0x2
	.byte	0x28
	.4byte	0x41
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.4byte	.LASF773
	.uleb128 0x2
	.4byte	.LASF774
	.byte	0x3
	.byte	0x45
	.4byte	0x3a
	.uleb128 0x2
	.4byte	.LASF775
	.byte	0x3
	.byte	0x46
	.4byte	0x41
	.uleb128 0x2
	.4byte	.LASF776
	.byte	0x3
	.byte	0x47
	.4byte	0x48
	.uleb128 0x2
	.4byte	.LASF777
	.byte	0x3
	.byte	0x49
	.4byte	0x98
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.4byte	.LASF778
	.uleb128 0x2
	.4byte	.LASF779
	.byte	0x3
	.byte	0x4a
	.4byte	0xaa
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.4byte	.LASF780
	.uleb128 0x2
	.4byte	.LASF781
	.byte	0x3
	.byte	0x4b
	.4byte	0xbc
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.4byte	.LASF782
	.uleb128 0x2
	.4byte	.LASF783
	.byte	0x3
	.byte	0x51
	.4byte	0x3a
	.uleb128 0x2
	.4byte	.LASF784
	.byte	0x3
	.byte	0x52
	.4byte	0x3a
	.uleb128 0x2
	.4byte	.LASF785
	.byte	0x3
	.byte	0x56
	.4byte	0x34
	.uleb128 0x5
	.byte	0x4
	.byte	0x4
	.byte	0x23
	.4byte	0x138
	.uleb128 0x6
	.4byte	.LASF786
	.byte	0x4
	.byte	0x25
	.4byte	0x138
	.byte	0x4
	.byte	0x1
	.byte	0x1f
	.byte	0
	.uleb128 0x6
	.4byte	.LASF787
	.byte	0x4
	.byte	0x26
	.4byte	0x138
	.byte	0x4
	.byte	0x1
	.byte	0x1e
	.byte	0
	.uleb128 0x6
	.4byte	.LASF788
	.byte	0x4
	.byte	0x27
	.4byte	0x138
	.byte	0x4
	.byte	0x1
	.byte	0x1d
	.byte	0
	.uleb128 0x6
	.4byte	.LASF789
	.byte	0x4
	.byte	0x28
	.4byte	0x138
	.byte	0x4
	.byte	0x1
	.byte	0x1c
	.byte	0
	.uleb128 0x6
	.4byte	.LASF790
	.byte	0x4
	.byte	0x29
	.4byte	0x138
	.byte	0x4
	.byte	0x1
	.byte	0x1b
	.byte	0
	.byte	0
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF791
	.uleb128 0x7
	.byte	0x4
	.byte	0x4
	.byte	0x1f
	.4byte	0x15e
	.uleb128 0x8
	.ascii	"all\000"
	.byte	0x4
	.byte	0x21
	.4byte	0xc3
	.uleb128 0x8
	.ascii	"flg\000"
	.byte	0x4
	.byte	0x2a
	.4byte	0xe4
	.byte	0
	.uleb128 0x2
	.4byte	.LASF792
	.byte	0x4
	.byte	0x2c
	.4byte	0x169
	.uleb128 0x9
	.4byte	0x13f
	.uleb128 0x7
	.byte	0x4
	.byte	0x1
	.byte	0x4e
	.4byte	0x1b7
	.uleb128 0x8
	.ascii	"u8\000"
	.byte	0x1
	.byte	0x51
	.4byte	0x6c
	.uleb128 0x8
	.ascii	"s8\000"
	.byte	0x1
	.byte	0x52
	.4byte	0x8d
	.uleb128 0x8
	.ascii	"u16\000"
	.byte	0x1
	.byte	0x54
	.4byte	0x77
	.uleb128 0x8
	.ascii	"s16\000"
	.byte	0x1
	.byte	0x55
	.4byte	0x9f
	.uleb128 0x8
	.ascii	"u32\000"
	.byte	0x1
	.byte	0x56
	.4byte	0x82
	.uleb128 0x8
	.ascii	"s32\000"
	.byte	0x1
	.byte	0x57
	.4byte	0xb1
	.byte	0
	.uleb128 0x2
	.4byte	.LASF793
	.byte	0x1
	.byte	0x63
	.4byte	0x1c2
	.uleb128 0x3
	.byte	0x4
	.4byte	0x1c8
	.uleb128 0xa
	.4byte	0x4f
	.uleb128 0xb
	.4byte	.LASF794
	.byte	0x1
	.2byte	0x2b6
	.4byte	0x4f
	.4byte	.LFB11
	.4byte	.LFE11-.LFB11
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.4byte	.LASF795
	.byte	0x1
	.2byte	0x2bb
	.4byte	0x4f
	.4byte	.LFB12
	.4byte	.LFE12-.LFB12
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.4byte	.LASF796
	.byte	0x1
	.2byte	0x2c2
	.4byte	0x4f
	.4byte	.LFB13
	.4byte	.LFE13-.LFB13
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.4byte	.LASF797
	.byte	0x1
	.2byte	0x2c7
	.4byte	0x4f
	.4byte	.LFB14
	.4byte	.LFE14-.LFB14
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.4byte	.LASF798
	.byte	0x1
	.2byte	0x2cc
	.4byte	0x4f
	.4byte	.LFB15
	.4byte	.LFE15-.LFB15
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.4byte	.LASF799
	.byte	0x1
	.2byte	0x2d1
	.4byte	0x4f
	.4byte	.LFB16
	.4byte	.LFE16-.LFB16
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xc
	.4byte	.LASF807
	.byte	0x1
	.byte	0x8a
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF821
	.byte	0x1
	.byte	0xb9
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x292
	.uleb128 0xe
	.4byte	.LASF800
	.byte	0x1
	.byte	0xb9
	.4byte	0x29
	.uleb128 0x1
	.byte	0x50
	.uleb128 0xe
	.4byte	.LASF801
	.byte	0x1
	.byte	0xb9
	.4byte	0x5a
	.uleb128 0x1
	.byte	0x51
	.byte	0
	.uleb128 0xf
	.4byte	.LASF852
	.byte	0x1
	.byte	0xa8
	.byte	0x1
	.uleb128 0x10
	.4byte	.LASF853
	.byte	0x1
	.2byte	0x260
	.4byte	0x5a
	.byte	0x1
	.uleb128 0x11
	.4byte	.LASF809
	.byte	0x1
	.byte	0xcf
	.4byte	0xd9
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x3d0
	.uleb128 0x12
	.4byte	.LASF802
	.byte	0x1
	.byte	0xcf
	.4byte	0xd9
	.4byte	.LLST0
	.uleb128 0x13
	.4byte	.LASF803
	.byte	0x1
	.byte	0xd1
	.4byte	0xd9
	.4byte	.LLST1
	.uleb128 0x13
	.4byte	.LASF804
	.byte	0x1
	.byte	0xd2
	.4byte	0xce
	.4byte	.LLST2
	.uleb128 0x13
	.4byte	.LASF805
	.byte	0x1
	.byte	0xd3
	.4byte	0x5a
	.4byte	.LLST3
	.uleb128 0x14
	.ascii	"i\000"
	.byte	0x1
	.byte	0xd4
	.4byte	0x6c
	.4byte	.LLST4
	.uleb128 0x14
	.ascii	"sz\000"
	.byte	0x1
	.byte	0xd4
	.4byte	0x6c
	.4byte	.LLST5
	.uleb128 0x13
	.4byte	.LASF806
	.byte	0x1
	.byte	0xd5
	.4byte	0x6c
	.4byte	.LLST6
	.uleb128 0x15
	.4byte	.LASF811
	.byte	0x1
	.2byte	0x1ad
	.4byte	.L24
	.uleb128 0x16
	.4byte	0x292
	.4byte	.LBB6
	.4byte	.LBE6-.LBB6
	.byte	0x1
	.byte	0xd8
	.uleb128 0x17
	.4byte	.LVL7
	.4byte	0x77c
	.4byte	0x35e
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x77
	.sleb128 3
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecTotalSmps
	.byte	0
	.uleb128 0x17
	.4byte	.LVL10
	.4byte	0x77c
	.4byte	0x375
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecPostTrigger
	.byte	0
	.uleb128 0x17
	.4byte	.LVL13
	.4byte	0x77c
	.4byte	0x38c
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecTimeDiv
	.byte	0
	.uleb128 0x17
	.4byte	.LVL16
	.4byte	0x79c
	.4byte	0x3a3
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x5
	.byte	0x3
	.4byte	.LANCHOR0
	.byte	0
	.uleb128 0x17
	.4byte	.LVL22
	.4byte	0x7bc
	.4byte	0x3ba
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x5
	.byte	0x3
	.4byte	.LANCHOR1
	.byte	0
	.uleb128 0x19
	.4byte	.LVL30
	.4byte	0x79c
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x7
	.byte	0x75
	.sleb128 0
	.byte	0x32
	.byte	0x24
	.byte	0x78
	.sleb128 0
	.byte	0x22
	.byte	0
	.byte	0
	.uleb128 0x1a
	.4byte	.LASF808
	.byte	0x1
	.2byte	0x1b9
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1b
	.4byte	.LASF810
	.byte	0x1
	.2byte	0x1d4
	.4byte	0xd9
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x429
	.uleb128 0x1c
	.4byte	.LASF802
	.byte	0x1
	.2byte	0x1d4
	.4byte	0xd9
	.4byte	.LLST7
	.uleb128 0x1d
	.4byte	.LASF806
	.byte	0x1
	.2byte	0x1d6
	.4byte	0x6c
	.4byte	.LLST8
	.uleb128 0x15
	.4byte	.LASF812
	.byte	0x1
	.2byte	0x20f
	.4byte	.L56
	.byte	0
	.uleb128 0x1b
	.4byte	.LASF813
	.byte	0x1
	.2byte	0x220
	.4byte	0xd9
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x479
	.uleb128 0x1c
	.4byte	.LASF802
	.byte	0x1
	.2byte	0x220
	.4byte	0xd9
	.4byte	.LLST9
	.uleb128 0x1d
	.4byte	.LASF806
	.byte	0x1
	.2byte	0x222
	.4byte	0x6c
	.4byte	.LLST10
	.uleb128 0x15
	.4byte	.LASF814
	.byte	0x1
	.2byte	0x235
	.4byte	.L62
	.uleb128 0x1e
	.4byte	.LVL54
	.4byte	0x3d0
	.byte	0
	.uleb128 0x1b
	.4byte	.LASF815
	.byte	0x1
	.2byte	0x246
	.4byte	0xd9
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x4b2
	.uleb128 0x1c
	.4byte	.LASF802
	.byte	0x1
	.2byte	0x246
	.4byte	0xd9
	.4byte	.LLST11
	.uleb128 0x1f
	.4byte	.LASF806
	.byte	0x1
	.2byte	0x248
	.4byte	0x77
	.uleb128 0x1
	.byte	0x53
	.byte	0
	.uleb128 0x20
	.4byte	0x29a
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1b
	.4byte	.LASF816
	.byte	0x1
	.2byte	0x277
	.4byte	0x4f
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x50a
	.uleb128 0x1c
	.4byte	.LASF817
	.byte	0x1
	.2byte	0x277
	.4byte	0x29
	.4byte	.LLST12
	.uleb128 0x21
	.4byte	.LASF818
	.byte	0x1
	.2byte	0x277
	.4byte	0xce
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1d
	.4byte	.LASF819
	.byte	0x1
	.2byte	0x279
	.4byte	0x4f
	.4byte	.LLST13
	.byte	0
	.uleb128 0x1b
	.4byte	.LASF820
	.byte	0x1
	.2byte	0x291
	.4byte	0xd9
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x556
	.uleb128 0x1c
	.4byte	.LASF802
	.byte	0x1
	.2byte	0x291
	.4byte	0xd9
	.4byte	.LLST14
	.uleb128 0x1f
	.4byte	.LASF803
	.byte	0x1
	.2byte	0x293
	.4byte	0x556
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x1e
	.4byte	.LVL73
	.4byte	0x7dc
	.uleb128 0x1e
	.4byte	.LVL75
	.4byte	0x7f6
	.byte	0
	.uleb128 0x9
	.4byte	0xd9
	.uleb128 0x22
	.4byte	.LASF854
	.byte	0x1
	.2byte	0x301
	.byte	0x1
	.4byte	0x58a
	.uleb128 0x23
	.ascii	"sz\000"
	.byte	0x1
	.2byte	0x303
	.4byte	0xce
	.uleb128 0x23
	.ascii	"cmp\000"
	.byte	0x1
	.2byte	0x304
	.4byte	0x4f
	.uleb128 0x23
	.ascii	"i\000"
	.byte	0x1
	.2byte	0x305
	.4byte	0x6c
	.byte	0
	.uleb128 0x24
	.4byte	.LASF822
	.byte	0x1
	.2byte	0x2eb
	.4byte	.LFB17
	.4byte	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x5f0
	.uleb128 0x25
	.4byte	0x55b
	.4byte	.LBB12
	.4byte	.Ldebug_ranges0+0
	.byte	0x1
	.2byte	0x2f4
	.uleb128 0x26
	.4byte	.Ldebug_ranges0+0
	.uleb128 0x27
	.4byte	0x568
	.4byte	.LLST15
	.uleb128 0x27
	.4byte	0x573
	.4byte	.LLST16
	.uleb128 0x27
	.4byte	0x57f
	.4byte	.LLST17
	.uleb128 0x17
	.4byte	.LVL79
	.4byte	0x810
	.4byte	0x5e4
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x75
	.sleb128 0
	.byte	0
	.uleb128 0x1e
	.4byte	.LVL87
	.4byte	0x3d0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x28
	.4byte	.LASF823
	.byte	0x1
	.byte	0x49
	.4byte	0x29
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_nTrgVarAddr
	.uleb128 0x28
	.4byte	.LASF824
	.byte	0x1
	.byte	0x4a
	.4byte	0x6c
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_nTrgVarSize
	.uleb128 0x28
	.4byte	.LASF825
	.byte	0x1
	.byte	0x4b
	.4byte	0x6c
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_bTrgVarSigned
	.uleb128 0x28
	.4byte	.LASF826
	.byte	0x1
	.byte	0x5b
	.4byte	0x16e
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_uTrgThreshold
	.uleb128 0x28
	.4byte	.LASF827
	.byte	0x1
	.byte	0x5e
	.4byte	0x29
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_nRecBuffAddr
	.uleb128 0x28
	.4byte	.LASF828
	.byte	0x1
	.byte	0x66
	.4byte	0x1b7
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_pCompareFunc
	.uleb128 0x29
	.4byte	0x6c
	.4byte	0x667
	.uleb128 0x2a
	.4byte	0x667
	.2byte	0x1ff
	.byte	0
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF829
	.uleb128 0x28
	.4byte	.LASF830
	.byte	0x1
	.byte	0x6e
	.4byte	0x656
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_pOwnRecBuffer
	.uleb128 0x2b
	.4byte	.LASF831
	.byte	0x1
	.byte	0x21
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecTotalSmps
	.uleb128 0x2b
	.4byte	.LASF832
	.byte	0x1
	.byte	0x24
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecPostTrigger
	.uleb128 0x2b
	.4byte	.LASF833
	.byte	0x1
	.byte	0x28
	.4byte	0x6c
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_nRecTriggerMode
	.uleb128 0x2b
	.4byte	.LASF834
	.byte	0x1
	.byte	0x2c
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecTimeDiv
	.uleb128 0x2b
	.4byte	.LASF835
	.byte	0x1
	.byte	0x2f
	.4byte	0x6c
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_nRecVarCount
	.uleb128 0x29
	.4byte	0x29
	.4byte	0x6e4
	.uleb128 0x2c
	.4byte	0x667
	.byte	0x7
	.byte	0
	.uleb128 0x2b
	.4byte	.LASF836
	.byte	0x1
	.byte	0x30
	.4byte	0x6d4
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_pRecVarAddr
	.uleb128 0x29
	.4byte	0xce
	.4byte	0x705
	.uleb128 0x2c
	.4byte	0x667
	.byte	0x7
	.byte	0
	.uleb128 0x2b
	.4byte	.LASF837
	.byte	0x1
	.byte	0x31
	.4byte	0x6f5
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_pRecVarSize
	.uleb128 0x2b
	.4byte	.LASF838
	.byte	0x1
	.byte	0x42
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecBuffStartIx
	.uleb128 0x2b
	.4byte	.LASF839
	.byte	0x1
	.byte	0x45
	.4byte	0x29
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_dwRecWritePtr
	.uleb128 0x2b
	.4byte	.LASF840
	.byte	0x1
	.byte	0x46
	.4byte	0x29
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_dwRecEndBuffPtr
	.uleb128 0x2b
	.4byte	.LASF841
	.byte	0x1
	.byte	0x35
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecTimeDivCtr
	.uleb128 0x2b
	.4byte	.LASF842
	.byte	0x1
	.byte	0x38
	.4byte	0x77
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wStoprecCountDown
	.uleb128 0x2b
	.4byte	.LASF843
	.byte	0x1
	.byte	0x3b
	.4byte	0x15e
	.uleb128 0x5
	.byte	0x3
	.4byte	pcm_wRecFlags
	.uleb128 0x2d
	.4byte	.LASF844
	.byte	0x3
	.byte	0x6c
	.4byte	0xd9
	.4byte	0x796
	.uleb128 0x2e
	.4byte	0x796
	.uleb128 0x2e
	.4byte	0xd9
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.4byte	0x77
	.uleb128 0x2d
	.4byte	.LASF845
	.byte	0x3
	.byte	0xa2
	.4byte	0xd9
	.4byte	0x7b6
	.uleb128 0x2e
	.4byte	0x7b6
	.uleb128 0x2e
	.4byte	0xd9
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.4byte	0x29
	.uleb128 0x2d
	.4byte	.LASF846
	.byte	0x3
	.byte	0x6d
	.4byte	0xd9
	.4byte	0x7d6
	.uleb128 0x2e
	.4byte	0x7d6
	.uleb128 0x2e
	.4byte	0xd9
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.4byte	0x82
	.uleb128 0x2d
	.4byte	.LASF847
	.byte	0x3
	.byte	0xa3
	.4byte	0xd9
	.4byte	0x7f6
	.uleb128 0x2e
	.4byte	0xd9
	.uleb128 0x2e
	.4byte	0x29
	.byte	0
	.uleb128 0x2d
	.4byte	.LASF848
	.byte	0x3
	.byte	0x6e
	.4byte	0xd9
	.4byte	0x810
	.uleb128 0x2e
	.4byte	0xd9
	.uleb128 0x2e
	.4byte	0x77
	.byte	0
	.uleb128 0x2f
	.4byte	.LASF855
	.byte	0x3
	.byte	0x5e
	.uleb128 0x2e
	.4byte	0x29
	.uleb128 0x2e
	.4byte	0x29
	.uleb128 0x2e
	.4byte	0xce
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.uleb128 0x2119
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xd
	.uleb128 0xb
	.uleb128 0xc
	.uleb128 0xb
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x17
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x1d
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x2e
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2e
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2f
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST0:
	.4byte	.LVL1
	.4byte	.LVL3
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL3
	.4byte	.LVL4
	.2byte	0x3
	.byte	0x70
	.sleb128 2
	.byte	0x9f
	.4byte	.LVL4
	.4byte	.LVL5
	.2byte	0x3
	.byte	0x70
	.sleb128 3
	.byte	0x9f
	.4byte	.LVL5
	.4byte	.LVL6
	.2byte	0x3
	.byte	0x77
	.sleb128 3
	.byte	0x9f
	.4byte	.LVL6
	.4byte	.LVL7-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL7-1
	.4byte	.LVL8
	.2byte	0x3
	.byte	0x77
	.sleb128 3
	.byte	0x9f
	.4byte	.LVL8
	.4byte	.LVL9
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL9
	.4byte	.LVL10-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL11
	.4byte	.LVL12
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL12
	.4byte	.LVL13-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL14
	.4byte	.LVL15
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL15
	.4byte	.LVL16-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL17
	.4byte	.LVL18
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL18
	.4byte	.LVL19
	.2byte	0x3
	.byte	0x70
	.sleb128 1
	.byte	0x9f
	.4byte	.LVL19
	.4byte	.LVL20
	.2byte	0x3
	.byte	0x70
	.sleb128 2
	.byte	0x9f
	.4byte	.LVL20
	.4byte	.LVL21
	.2byte	0x3
	.byte	0x71
	.sleb128 2
	.byte	0x9f
	.4byte	.LVL21
	.4byte	.LVL22-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL22
	.4byte	.LVL23
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL23
	.4byte	.LVL25
	.2byte	0x3
	.byte	0x70
	.sleb128 1
	.byte	0x9f
	.4byte	.LVL25
	.4byte	.LVL27
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL27
	.4byte	.LVL30-1
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL30
	.4byte	.LVL35
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL35
	.4byte	.LVL36
	.2byte	0x3
	.byte	0x70
	.sleb128 1
	.byte	0x9f
	.4byte	.LVL41
	.4byte	.LVL42
	.2byte	0x3
	.byte	0x70
	.sleb128 1
	.byte	0x9f
	.4byte	.LVL42
	.4byte	.LVL43
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL45
	.4byte	.LVL46
	.2byte	0x3
	.byte	0x70
	.sleb128 1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST1:
	.4byte	.LVL2
	.4byte	.LVL5
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL5
	.4byte	.LVL47
	.2byte	0x1
	.byte	0x57
	.4byte	.LVL47
	.4byte	.LFE3
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST2:
	.4byte	.LVL24
	.4byte	.LVL26
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL26
	.4byte	.LVL28
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL29
	.4byte	.LVL35
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL35
	.4byte	.LVL36
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL42
	.4byte	.LVL43
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL45
	.4byte	.LVL46
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST3:
	.4byte	.LVL37
	.4byte	.LVL39
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL44
	.4byte	.LVL45
	.2byte	0x1
	.byte	0x56
	.4byte	0
	.4byte	0
.LLST4:
	.4byte	.LVL24
	.4byte	.LVL26
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL26
	.4byte	.LVL33
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL34
	.4byte	.LVL35
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL35
	.4byte	.LVL36
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL42
	.4byte	.LVL43
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL45
	.4byte	.LVL46
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST5:
	.4byte	.LVL27
	.4byte	.LVL31
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL31
	.4byte	.LVL32
	.2byte	0x3
	.byte	0x74
	.sleb128 1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST6:
	.4byte	.LVL40
	.4byte	.LVL41
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL46
	.4byte	.LFE3
	.2byte	0x1
	.byte	0x53
	.4byte	0
	.4byte	0
.LLST7:
	.4byte	.LVL48
	.4byte	.LVL52
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL52
	.4byte	.LFE5
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST8:
	.4byte	.LVL49
	.4byte	.LVL50
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL51
	.4byte	.LFE5
	.2byte	0x1
	.byte	0x53
	.4byte	0
	.4byte	0
.LLST9:
	.4byte	.LVL53
	.4byte	.LVL54-1
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL54-1
	.4byte	.LVL55
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL55
	.4byte	.LVL56
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL56
	.4byte	.LVL57
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL57
	.4byte	.LFE6
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST10:
	.4byte	.LVL54
	.4byte	.LVL55
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL56
	.4byte	.LFE6
	.2byte	0x1
	.byte	0x53
	.4byte	0
	.4byte	0
.LLST11:
	.4byte	.LVL58
	.4byte	.LVL61
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL61
	.4byte	.LFE7
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST12:
	.4byte	.LVL62
	.4byte	.LVL63
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL63
	.4byte	.LVL64
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL64
	.4byte	.LVL65
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL65
	.4byte	.LFE9
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST13:
	.4byte	.LVL62
	.4byte	.LVL65
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL65
	.4byte	.LFE9
	.2byte	0x1
	.byte	0x50
	.4byte	0
	.4byte	0
.LLST14:
	.4byte	.LVL66
	.4byte	.LVL67
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL67
	.4byte	.LVL68
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL68
	.4byte	.LVL69
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL69
	.4byte	.LVL70
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL70
	.4byte	.LVL71
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL71
	.4byte	.LVL72
	.2byte	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.4byte	.LVL72
	.4byte	.LVL74
	.2byte	0x6
	.byte	0x91
	.sleb128 -12
	.byte	0x6
	.byte	0x31
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL74
	.4byte	.LFE10
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST15:
	.4byte	.LVL78
	.4byte	.LVL80
	.2byte	0x1
	.byte	0x55
	.4byte	0
	.4byte	0
.LLST16:
	.4byte	.LVL84
	.4byte	.LVL85
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL86
	.4byte	.LVL87-1
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL88
	.4byte	.LVL89
	.2byte	0x1
	.byte	0x50
	.4byte	0
	.4byte	0
.LLST17:
	.4byte	.LVL76
	.4byte	.LVL77
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL77
	.4byte	.LVL81
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL82
	.4byte	.LVL83
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x9c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB11
	.4byte	.LFE11-.LFB11
	.4byte	.LFB12
	.4byte	.LFE12-.LFB12
	.4byte	.LFB13
	.4byte	.LFE13-.LFB13
	.4byte	.LFB14
	.4byte	.LFE14-.LFB14
	.4byte	.LFB15
	.4byte	.LFE15-.LFB15
	.4byte	.LFB16
	.4byte	.LFE16-.LFB16
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.4byte	.LFB17
	.4byte	.LFE17-.LFB17
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LBB12
	.4byte	.LBE12
	.4byte	.LBB15
	.4byte	.LBE15
	.4byte	0
	.4byte	0
	.4byte	.LFB11
	.4byte	.LFE11
	.4byte	.LFB12
	.4byte	.LFE12
	.4byte	.LFB13
	.4byte	.LFE13
	.4byte	.LFB14
	.4byte	.LFE14
	.4byte	.LFB15
	.4byte	.LFE15
	.4byte	.LFB16
	.4byte	.LFE16
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LFB2
	.4byte	.LFE2
	.4byte	.LFB3
	.4byte	.LFE3
	.4byte	.LFB4
	.4byte	.LFE4
	.4byte	.LFB5
	.4byte	.LFE5
	.4byte	.LFB6
	.4byte	.LFE6
	.4byte	.LFB7
	.4byte	.LFE7
	.4byte	.LFB8
	.4byte	.LFE8
	.4byte	.LFB9
	.4byte	.LFE9
	.4byte	.LFB10
	.4byte	.LFE10
	.4byte	.LFB17
	.4byte	.LFE17
	.4byte	0
	.4byte	0
	.section	.debug_macro,"",%progbits
.Ldebug_macro0:
	.2byte	0x4
	.byte	0x2
	.4byte	.Ldebug_line0
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.byte	0x5
	.uleb128 0x1
	.4byte	.LASF0
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF1
	.byte	0x5
	.uleb128 0x3
	.4byte	.LASF2
	.byte	0x5
	.uleb128 0x4
	.4byte	.LASF3
	.byte	0x5
	.uleb128 0x5
	.4byte	.LASF4
	.byte	0x5
	.uleb128 0x6
	.4byte	.LASF5
	.byte	0x5
	.uleb128 0x7
	.4byte	.LASF6
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF7
	.byte	0x5
	.uleb128 0x9
	.4byte	.LASF8
	.byte	0x5
	.uleb128 0xa
	.4byte	.LASF9
	.byte	0x5
	.uleb128 0xb
	.4byte	.LASF10
	.byte	0x5
	.uleb128 0xc
	.4byte	.LASF11
	.byte	0x5
	.uleb128 0xd
	.4byte	.LASF12
	.byte	0x5
	.uleb128 0xe
	.4byte	.LASF13
	.byte	0x5
	.uleb128 0xf
	.4byte	.LASF14
	.byte	0x5
	.uleb128 0x10
	.4byte	.LASF15
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF16
	.byte	0x5
	.uleb128 0x12
	.4byte	.LASF17
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF18
	.byte	0x5
	.uleb128 0x14
	.4byte	.LASF19
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF20
	.byte	0x5
	.uleb128 0x16
	.4byte	.LASF21
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF22
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF23
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF24
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF25
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF26
	.byte	0x5
	.uleb128 0x1c
	.4byte	.LASF27
	.byte	0x5
	.uleb128 0x1d
	.4byte	.LASF28
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF29
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF30
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF31
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF32
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF33
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF34
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF35
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF36
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF37
	.byte	0x5
	.uleb128 0x27
	.4byte	.LASF38
	.byte	0x5
	.uleb128 0x28
	.4byte	.LASF39
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF40
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF41
	.byte	0x5
	.uleb128 0x2b
	.4byte	.LASF42
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF43
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF44
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF45
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF46
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF47
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF48
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF49
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF50
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF51
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF52
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF53
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF54
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF55
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF56
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF57
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF58
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF59
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF60
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF61
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF62
	.byte	0x5
	.uleb128 0x40
	.4byte	.LASF63
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF64
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF65
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF66
	.byte	0x5
	.uleb128 0x44
	.4byte	.LASF67
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF68
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF69
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF70
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF71
	.byte	0x5
	.uleb128 0x49
	.4byte	.LASF72
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF73
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF74
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF75
	.byte	0x5
	.uleb128 0x4d
	.4byte	.LASF76
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF77
	.byte	0x5
	.uleb128 0x4f
	.4byte	.LASF78
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF79
	.byte	0x5
	.uleb128 0x51
	.4byte	.LASF80
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF81
	.byte	0x5
	.uleb128 0x53
	.4byte	.LASF82
	.byte	0x5
	.uleb128 0x54
	.4byte	.LASF83
	.byte	0x5
	.uleb128 0x55
	.4byte	.LASF84
	.byte	0x5
	.uleb128 0x56
	.4byte	.LASF85
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF86
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF87
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF88
	.byte	0x5
	.uleb128 0x5a
	.4byte	.LASF89
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF90
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF91
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF92
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF93
	.byte	0x5
	.uleb128 0x5f
	.4byte	.LASF94
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF95
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF96
	.byte	0x5
	.uleb128 0x62
	.4byte	.LASF97
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF98
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF99
	.byte	0x5
	.uleb128 0x65
	.4byte	.LASF100
	.byte	0x5
	.uleb128 0x66
	.4byte	.LASF101
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF102
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF103
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF104
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF105
	.byte	0x5
	.uleb128 0x6b
	.4byte	.LASF106
	.byte	0x5
	.uleb128 0x6c
	.4byte	.LASF107
	.byte	0x5
	.uleb128 0x6d
	.4byte	.LASF108
	.byte	0x5
	.uleb128 0x6e
	.4byte	.LASF109
	.byte	0x5
	.uleb128 0x6f
	.4byte	.LASF110
	.byte	0x5
	.uleb128 0x70
	.4byte	.LASF111
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF112
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF113
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF114
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF115
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF116
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF117
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF118
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF119
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF120
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF121
	.byte	0x5
	.uleb128 0x7b
	.4byte	.LASF122
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF123
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF124
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF125
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF126
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF127
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF128
	.byte	0x5
	.uleb128 0x82
	.4byte	.LASF129
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF130
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF131
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF132
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF133
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF134
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF135
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF136
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF137
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF138
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF139
	.byte	0x5
	.uleb128 0x8d
	.4byte	.LASF140
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF141
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF142
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF143
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF144
	.byte	0x5
	.uleb128 0x92
	.4byte	.LASF145
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF146
	.byte	0x5
	.uleb128 0x94
	.4byte	.LASF147
	.byte	0x5
	.uleb128 0x95
	.4byte	.LASF148
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF149
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF150
	.byte	0x5
	.uleb128 0x98
	.4byte	.LASF151
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF152
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF153
	.byte	0x5
	.uleb128 0x9b
	.4byte	.LASF154
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF155
	.byte	0x5
	.uleb128 0x9d
	.4byte	.LASF156
	.byte	0x5
	.uleb128 0x9e
	.4byte	.LASF157
	.byte	0x5
	.uleb128 0x9f
	.4byte	.LASF158
	.byte	0x5
	.uleb128 0xa0
	.4byte	.LASF159
	.byte	0x5
	.uleb128 0xa1
	.4byte	.LASF160
	.byte	0x5
	.uleb128 0xa2
	.4byte	.LASF161
	.byte	0x5
	.uleb128 0xa3
	.4byte	.LASF162
	.byte	0x5
	.uleb128 0xa4
	.4byte	.LASF163
	.byte	0x5
	.uleb128 0xa5
	.4byte	.LASF164
	.byte	0x5
	.uleb128 0xa6
	.4byte	.LASF165
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF166
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF167
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF168
	.byte	0x5
	.uleb128 0xaa
	.4byte	.LASF169
	.byte	0x5
	.uleb128 0xab
	.4byte	.LASF170
	.byte	0x5
	.uleb128 0xac
	.4byte	.LASF171
	.byte	0x5
	.uleb128 0xad
	.4byte	.LASF172
	.byte	0x5
	.uleb128 0xae
	.4byte	.LASF173
	.byte	0x5
	.uleb128 0xaf
	.4byte	.LASF174
	.byte	0x5
	.uleb128 0xb0
	.4byte	.LASF175
	.byte	0x5
	.uleb128 0xb1
	.4byte	.LASF176
	.byte	0x5
	.uleb128 0xb2
	.4byte	.LASF177
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF178
	.byte	0x5
	.uleb128 0xb4
	.4byte	.LASF179
	.byte	0x5
	.uleb128 0xb5
	.4byte	.LASF180
	.byte	0x5
	.uleb128 0xb6
	.4byte	.LASF181
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF182
	.byte	0x5
	.uleb128 0xb8
	.4byte	.LASF183
	.byte	0x5
	.uleb128 0xb9
	.4byte	.LASF184
	.byte	0x5
	.uleb128 0xba
	.4byte	.LASF185
	.byte	0x5
	.uleb128 0xbb
	.4byte	.LASF186
	.byte	0x5
	.uleb128 0xbc
	.4byte	.LASF187
	.byte	0x5
	.uleb128 0xbd
	.4byte	.LASF188
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF189
	.byte	0x5
	.uleb128 0xbf
	.4byte	.LASF190
	.byte	0x5
	.uleb128 0xc0
	.4byte	.LASF191
	.byte	0x5
	.uleb128 0xc1
	.4byte	.LASF192
	.byte	0x5
	.uleb128 0xc2
	.4byte	.LASF193
	.byte	0x5
	.uleb128 0xc3
	.4byte	.LASF194
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF195
	.byte	0x5
	.uleb128 0xc5
	.4byte	.LASF196
	.byte	0x5
	.uleb128 0xc6
	.4byte	.LASF197
	.byte	0x5
	.uleb128 0xc7
	.4byte	.LASF198
	.byte	0x5
	.uleb128 0xc8
	.4byte	.LASF199
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF200
	.byte	0x5
	.uleb128 0xca
	.4byte	.LASF201
	.byte	0x5
	.uleb128 0xcb
	.4byte	.LASF202
	.byte	0x5
	.uleb128 0xcc
	.4byte	.LASF203
	.byte	0x5
	.uleb128 0xcd
	.4byte	.LASF204
	.byte	0x5
	.uleb128 0xce
	.4byte	.LASF205
	.byte	0x5
	.uleb128 0xcf
	.4byte	.LASF206
	.byte	0x5
	.uleb128 0xd0
	.4byte	.LASF207
	.byte	0x5
	.uleb128 0xd1
	.4byte	.LASF208
	.byte	0x5
	.uleb128 0xd2
	.4byte	.LASF209
	.byte	0x5
	.uleb128 0xd3
	.4byte	.LASF210
	.byte	0x5
	.uleb128 0xd4
	.4byte	.LASF211
	.byte	0x5
	.uleb128 0xd5
	.4byte	.LASF212
	.byte	0x5
	.uleb128 0xd6
	.4byte	.LASF213
	.byte	0x5
	.uleb128 0xd7
	.4byte	.LASF214
	.byte	0x5
	.uleb128 0xd8
	.4byte	.LASF215
	.byte	0x5
	.uleb128 0xd9
	.4byte	.LASF216
	.byte	0x5
	.uleb128 0xda
	.4byte	.LASF217
	.byte	0x5
	.uleb128 0xdb
	.4byte	.LASF218
	.byte	0x5
	.uleb128 0xdc
	.4byte	.LASF219
	.byte	0x5
	.uleb128 0xdd
	.4byte	.LASF220
	.byte	0x5
	.uleb128 0xde
	.4byte	.LASF221
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF222
	.byte	0x5
	.uleb128 0xe0
	.4byte	.LASF223
	.byte	0x5
	.uleb128 0xe1
	.4byte	.LASF224
	.byte	0x5
	.uleb128 0xe2
	.4byte	.LASF225
	.byte	0x5
	.uleb128 0xe3
	.4byte	.LASF226
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF227
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF228
	.byte	0x5
	.uleb128 0xe6
	.4byte	.LASF229
	.byte	0x5
	.uleb128 0xe7
	.4byte	.LASF230
	.byte	0x5
	.uleb128 0xe8
	.4byte	.LASF231
	.byte	0x5
	.uleb128 0xe9
	.4byte	.LASF232
	.byte	0x5
	.uleb128 0xea
	.4byte	.LASF233
	.byte	0x5
	.uleb128 0xeb
	.4byte	.LASF234
	.byte	0x5
	.uleb128 0xec
	.4byte	.LASF235
	.byte	0x5
	.uleb128 0xed
	.4byte	.LASF236
	.byte	0x5
	.uleb128 0xee
	.4byte	.LASF237
	.byte	0x5
	.uleb128 0xef
	.4byte	.LASF238
	.byte	0x5
	.uleb128 0xf0
	.4byte	.LASF239
	.byte	0x5
	.uleb128 0xf1
	.4byte	.LASF240
	.byte	0x5
	.uleb128 0xf2
	.4byte	.LASF241
	.byte	0x5
	.uleb128 0xf3
	.4byte	.LASF242
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF243
	.byte	0x5
	.uleb128 0xf5
	.4byte	.LASF244
	.byte	0x5
	.uleb128 0xf6
	.4byte	.LASF245
	.byte	0x5
	.uleb128 0xf7
	.4byte	.LASF246
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF247
	.byte	0x5
	.uleb128 0xf9
	.4byte	.LASF248
	.byte	0x5
	.uleb128 0xfa
	.4byte	.LASF249
	.byte	0x5
	.uleb128 0xfb
	.4byte	.LASF250
	.byte	0x5
	.uleb128 0xfc
	.4byte	.LASF251
	.byte	0x5
	.uleb128 0xfd
	.4byte	.LASF252
	.byte	0x5
	.uleb128 0xfe
	.4byte	.LASF253
	.byte	0x5
	.uleb128 0xff
	.4byte	.LASF254
	.byte	0x5
	.uleb128 0x100
	.4byte	.LASF255
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF256
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF257
	.byte	0x5
	.uleb128 0x103
	.4byte	.LASF258
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF259
	.byte	0x5
	.uleb128 0x105
	.4byte	.LASF260
	.byte	0x5
	.uleb128 0x106
	.4byte	.LASF261
	.byte	0x5
	.uleb128 0x107
	.4byte	.LASF262
	.byte	0x5
	.uleb128 0x108
	.4byte	.LASF263
	.byte	0x5
	.uleb128 0x109
	.4byte	.LASF264
	.byte	0x5
	.uleb128 0x10a
	.4byte	.LASF265
	.byte	0x5
	.uleb128 0x10b
	.4byte	.LASF266
	.byte	0x5
	.uleb128 0x10c
	.4byte	.LASF267
	.byte	0x5
	.uleb128 0x10d
	.4byte	.LASF268
	.byte	0x5
	.uleb128 0x10e
	.4byte	.LASF269
	.byte	0x5
	.uleb128 0x10f
	.4byte	.LASF270
	.byte	0x5
	.uleb128 0x110
	.4byte	.LASF271
	.byte	0x5
	.uleb128 0x111
	.4byte	.LASF272
	.byte	0x5
	.uleb128 0x112
	.4byte	.LASF273
	.byte	0x5
	.uleb128 0x113
	.4byte	.LASF274
	.byte	0x5
	.uleb128 0x114
	.4byte	.LASF275
	.byte	0x5
	.uleb128 0x115
	.4byte	.LASF276
	.byte	0x5
	.uleb128 0x116
	.4byte	.LASF277
	.byte	0x5
	.uleb128 0x117
	.4byte	.LASF278
	.byte	0x5
	.uleb128 0x118
	.4byte	.LASF279
	.byte	0x5
	.uleb128 0x119
	.4byte	.LASF280
	.byte	0x5
	.uleb128 0x11a
	.4byte	.LASF281
	.byte	0x5
	.uleb128 0x11b
	.4byte	.LASF282
	.byte	0x5
	.uleb128 0x11c
	.4byte	.LASF283
	.byte	0x5
	.uleb128 0x11d
	.4byte	.LASF284
	.byte	0x5
	.uleb128 0x11e
	.4byte	.LASF285
	.byte	0x5
	.uleb128 0x11f
	.4byte	.LASF286
	.byte	0x5
	.uleb128 0x120
	.4byte	.LASF287
	.byte	0x5
	.uleb128 0x121
	.4byte	.LASF288
	.byte	0x5
	.uleb128 0x122
	.4byte	.LASF289
	.byte	0x5
	.uleb128 0x123
	.4byte	.LASF290
	.byte	0x5
	.uleb128 0x124
	.4byte	.LASF291
	.byte	0x5
	.uleb128 0x125
	.4byte	.LASF292
	.byte	0x5
	.uleb128 0x126
	.4byte	.LASF293
	.byte	0x5
	.uleb128 0x127
	.4byte	.LASF294
	.byte	0x5
	.uleb128 0x128
	.4byte	.LASF295
	.byte	0x5
	.uleb128 0x129
	.4byte	.LASF296
	.byte	0x5
	.uleb128 0x12a
	.4byte	.LASF297
	.byte	0x5
	.uleb128 0x12b
	.4byte	.LASF298
	.byte	0x5
	.uleb128 0x12c
	.4byte	.LASF299
	.byte	0x5
	.uleb128 0x12d
	.4byte	.LASF300
	.byte	0x5
	.uleb128 0x12e
	.4byte	.LASF301
	.byte	0x5
	.uleb128 0x12f
	.4byte	.LASF302
	.byte	0x5
	.uleb128 0x130
	.4byte	.LASF303
	.byte	0x5
	.uleb128 0x131
	.4byte	.LASF304
	.byte	0x5
	.uleb128 0x132
	.4byte	.LASF305
	.byte	0x5
	.uleb128 0x133
	.4byte	.LASF306
	.byte	0x5
	.uleb128 0x134
	.4byte	.LASF307
	.byte	0x5
	.uleb128 0x135
	.4byte	.LASF308
	.byte	0x5
	.uleb128 0x136
	.4byte	.LASF309
	.byte	0x5
	.uleb128 0x137
	.4byte	.LASF310
	.byte	0x5
	.uleb128 0x138
	.4byte	.LASF311
	.byte	0x5
	.uleb128 0x139
	.4byte	.LASF312
	.byte	0x5
	.uleb128 0x13a
	.4byte	.LASF313
	.byte	0x5
	.uleb128 0x13b
	.4byte	.LASF314
	.byte	0x5
	.uleb128 0x13c
	.4byte	.LASF315
	.byte	0x5
	.uleb128 0x13d
	.4byte	.LASF316
	.byte	0x5
	.uleb128 0x13e
	.4byte	.LASF317
	.byte	0x5
	.uleb128 0x13f
	.4byte	.LASF318
	.byte	0x5
	.uleb128 0x140
	.4byte	.LASF319
	.byte	0x5
	.uleb128 0x141
	.4byte	.LASF320
	.byte	0x5
	.uleb128 0x142
	.4byte	.LASF321
	.byte	0x5
	.uleb128 0x143
	.4byte	.LASF322
	.byte	0x5
	.uleb128 0x144
	.4byte	.LASF323
	.byte	0x5
	.uleb128 0x145
	.4byte	.LASF324
	.byte	0x5
	.uleb128 0x146
	.4byte	.LASF325
	.byte	0x5
	.uleb128 0x147
	.4byte	.LASF326
	.byte	0x5
	.uleb128 0x148
	.4byte	.LASF327
	.byte	0x5
	.uleb128 0x149
	.4byte	.LASF328
	.byte	0x5
	.uleb128 0x14a
	.4byte	.LASF329
	.byte	0x5
	.uleb128 0x14b
	.4byte	.LASF330
	.byte	0x5
	.uleb128 0x14c
	.4byte	.LASF331
	.byte	0x5
	.uleb128 0x14d
	.4byte	.LASF332
	.byte	0x5
	.uleb128 0x14e
	.4byte	.LASF333
	.byte	0x5
	.uleb128 0x14f
	.4byte	.LASF334
	.byte	0x5
	.uleb128 0x150
	.4byte	.LASF335
	.byte	0x5
	.uleb128 0x151
	.4byte	.LASF336
	.byte	0x5
	.uleb128 0x152
	.4byte	.LASF337
	.byte	0x5
	.uleb128 0x153
	.4byte	.LASF338
	.byte	0x5
	.uleb128 0x154
	.4byte	.LASF339
	.byte	0x5
	.uleb128 0x155
	.4byte	.LASF340
	.byte	0x5
	.uleb128 0x156
	.4byte	.LASF341
	.byte	0x5
	.uleb128 0x157
	.4byte	.LASF342
	.byte	0x5
	.uleb128 0x158
	.4byte	.LASF343
	.byte	0x5
	.uleb128 0x159
	.4byte	.LASF344
	.byte	0x5
	.uleb128 0x15a
	.4byte	.LASF345
	.byte	0x5
	.uleb128 0x15b
	.4byte	.LASF346
	.byte	0x5
	.uleb128 0x15c
	.4byte	.LASF347
	.byte	0x5
	.uleb128 0x15d
	.4byte	.LASF348
	.byte	0x5
	.uleb128 0x15e
	.4byte	.LASF349
	.byte	0x5
	.uleb128 0x15f
	.4byte	.LASF350
	.byte	0x5
	.uleb128 0x160
	.4byte	.LASF351
	.byte	0x5
	.uleb128 0x161
	.4byte	.LASF352
	.byte	0x5
	.uleb128 0x162
	.4byte	.LASF353
	.byte	0x5
	.uleb128 0x163
	.4byte	.LASF354
	.byte	0x5
	.uleb128 0x164
	.4byte	.LASF355
	.byte	0x5
	.uleb128 0x165
	.4byte	.LASF356
	.byte	0x5
	.uleb128 0x166
	.4byte	.LASF357
	.byte	0x5
	.uleb128 0x1
	.4byte	.LASF358
	.byte	0x5
	.uleb128 0x2
	.4byte	.LASF359
	.byte	0x3
	.uleb128 0x10
	.uleb128 0x2
	.byte	0x7
	.4byte	.Ldebug_macro1
	.file 5 "C:/NXP/S32DS_ARM_v2.0/S32DS/FreeMASTER_Serial_Communication_Driver_V2_0/src_common/freemaster_defcfg.h"
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x5
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF362
	.file 6 "C:/Users/kamil/OneDrive/Documents/GitHub/Internship/TestBench/adc_hwtrigger_s32k144/Sources/freemaster_cfg.h"
	.byte	0x3
	.uleb128 0x14
	.uleb128 0x6
	.byte	0x7
	.4byte	.Ldebug_macro2
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro3
	.byte	0x4
	.file 7 "C:/NXP/S32DS_ARM_v2.0/S32DS/FreeMASTER_Serial_Communication_Driver_V2_0/src_common/freemaster_tsa.h"
	.byte	0x3
	.uleb128 0x3f
	.uleb128 0x7
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF444
	.byte	0x3
	.uleb128 0x13
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro4
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro5
	.byte	0x4
	.file 8 "../FreeMASTER/src_common/freemaster_private.h"
	.byte	0x3
	.uleb128 0x11
	.uleb128 0x8
	.byte	0x7
	.4byte	.Ldebug_macro6
	.byte	0x3
	.uleb128 0x8d
	.uleb128 0x3
	.byte	0x7
	.4byte	.Ldebug_macro7
	.byte	0x4
	.byte	0x7
	.4byte	.Ldebug_macro8
	.byte	0x4
	.file 9 "../FreeMASTER/src_common/freemaster_protocol.h"
	.byte	0x3
	.uleb128 0x12
	.uleb128 0x9
	.byte	0x7
	.4byte	.Ldebug_macro9
	.byte	0x4
	.byte	0x3
	.uleb128 0x16
	.uleb128 0x4
	.byte	0x7
	.4byte	.Ldebug_macro10
	.byte	0x4
	.byte	0x5
	.uleb128 0x2b2
	.4byte	.LASF766
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster.h.21.56c6bdc4929914166963ef7d4e8deca8,comdat
.Ldebug_macro1:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x15
	.4byte	.LASF360
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF361
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_cfg.h.27.969a256e9ad610351f32881d8f607f40,comdat
.Ldebug_macro2:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF363
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF364
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF365
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF366
	.byte	0x5
	.uleb128 0x29
	.4byte	.LASF367
	.byte	0x5
	.uleb128 0x2a
	.4byte	.LASF368
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF369
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF370
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF371
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF372
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF373
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF374
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF375
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF376
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF377
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF378
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF379
	.byte	0x5
	.uleb128 0x50
	.4byte	.LASF380
	.byte	0x5
	.uleb128 0x51
	.4byte	.LASF381
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF382
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF383
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF384
	.byte	0x5
	.uleb128 0x5a
	.4byte	.LASF385
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF386
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF387
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF388
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF389
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF390
	.byte	0x5
	.uleb128 0x6c
	.4byte	.LASF391
	.byte	0x5
	.uleb128 0x6f
	.4byte	.LASF392
	.byte	0x5
	.uleb128 0x71
	.4byte	.LASF393
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF394
	.byte	0x5
	.uleb128 0x78
	.4byte	.LASF395
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF396
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF397
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF398
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF399
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF400
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF401
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF402
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF403
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF404
	.byte	0x5
	.uleb128 0x91
	.4byte	.LASF405
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_defcfg.h.23.28a3d7e2acdca8c57137ae98954506e5,comdat
.Ldebug_macro3:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF406
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF407
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF408
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF409
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF410
	.byte	0x5
	.uleb128 0x51
	.4byte	.LASF411
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF412
	.byte	0x5
	.uleb128 0x5b
	.4byte	.LASF413
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF414
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF415
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF416
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF417
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF418
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF419
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF420
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF421
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF422
	.byte	0x5
	.uleb128 0x135
	.4byte	.LASF423
	.byte	0x5
	.uleb128 0x13d
	.4byte	.LASF424
	.byte	0x5
	.uleb128 0x142
	.4byte	.LASF425
	.byte	0x5
	.uleb128 0x147
	.4byte	.LASF426
	.byte	0x5
	.uleb128 0x14c
	.4byte	.LASF427
	.byte	0x5
	.uleb128 0x151
	.4byte	.LASF428
	.byte	0x5
	.uleb128 0x156
	.4byte	.LASF429
	.byte	0x5
	.uleb128 0x160
	.4byte	.LASF430
	.byte	0x5
	.uleb128 0x166
	.4byte	.LASF431
	.byte	0x5
	.uleb128 0x16f
	.4byte	.LASF432
	.byte	0x5
	.uleb128 0x1a2
	.4byte	.LASF433
	.byte	0x5
	.uleb128 0x1ad
	.4byte	.LASF434
	.byte	0x5
	.uleb128 0x1b7
	.4byte	.LASF435
	.byte	0x5
	.uleb128 0x1bc
	.4byte	.LASF436
	.byte	0x5
	.uleb128 0x1c7
	.4byte	.LASF437
	.byte	0x5
	.uleb128 0x1cf
	.4byte	.LASF438
	.byte	0x6
	.uleb128 0x1de
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0x1df
	.4byte	.LASF440
	.byte	0x6
	.uleb128 0x1e3
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0x1e4
	.4byte	.LASF441
	.byte	0x6
	.uleb128 0x1ef
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0x1f0
	.4byte	.LASF442
	.byte	0x6
	.uleb128 0x1f5
	.4byte	.LASF439
	.byte	0x5
	.uleb128 0x1f6
	.4byte	.LASF443
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_tsa.h.26.4e5e5d3886d6b6e67bb3d443a654b847,comdat
.Ldebug_macro4:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF445
	.byte	0x5
	.uleb128 0x1d
	.4byte	.LASF446
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF447
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF448
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF449
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF450
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF451
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF452
	.byte	0x5
	.uleb128 0x2c
	.4byte	.LASF453
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF454
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF455
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF456
	.byte	0x5
	.uleb128 0x38
	.4byte	.LASF457
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF458
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF459
	.byte	0x5
	.uleb128 0x5a
	.4byte	.LASF460
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF461
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF462
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF463
	.byte	0x5
	.uleb128 0x66
	.4byte	.LASF464
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF465
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF466
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF467
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF468
	.byte	0x5
	.uleb128 0x77
	.4byte	.LASF469
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF470
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF471
	.byte	0x5
	.uleb128 0x7b
	.4byte	.LASF472
	.byte	0x5
	.uleb128 0x7c
	.4byte	.LASF473
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF474
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF475
	.byte	0x5
	.uleb128 0x80
	.4byte	.LASF476
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF477
	.byte	0x5
	.uleb128 0x83
	.4byte	.LASF478
	.byte	0x5
	.uleb128 0x84
	.4byte	.LASF479
	.byte	0x5
	.uleb128 0x85
	.4byte	.LASF480
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF481
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF482
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF483
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF484
	.byte	0x5
	.uleb128 0x93
	.4byte	.LASF485
	.byte	0x5
	.uleb128 0x97
	.4byte	.LASF486
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF487
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF488
	.byte	0x5
	.uleb128 0xe0
	.4byte	.LASF489
	.byte	0x5
	.uleb128 0xe1
	.4byte	.LASF490
	.byte	0x5
	.uleb128 0xe2
	.4byte	.LASF491
	.byte	0x5
	.uleb128 0xe3
	.4byte	.LASF492
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF493
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF494
	.byte	0x5
	.uleb128 0xe6
	.4byte	.LASF495
	.byte	0x5
	.uleb128 0xe7
	.4byte	.LASF496
	.byte	0x5
	.uleb128 0xe8
	.4byte	.LASF497
	.byte	0x5
	.uleb128 0xe9
	.4byte	.LASF498
	.byte	0x5
	.uleb128 0xea
	.4byte	.LASF499
	.byte	0x5
	.uleb128 0xeb
	.4byte	.LASF500
	.byte	0x5
	.uleb128 0xec
	.4byte	.LASF501
	.byte	0x5
	.uleb128 0x118
	.4byte	.LASF502
	.byte	0x5
	.uleb128 0x119
	.4byte	.LASF503
	.byte	0x5
	.uleb128 0x11a
	.4byte	.LASF504
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster.h.70.48a2e7f58bb7983b3f96b16d727289ff,comdat
.Ldebug_macro5:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF505
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF506
	.byte	0x5
	.uleb128 0x48
	.4byte	.LASF507
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF508
	.byte	0x5
	.uleb128 0x4c
	.4byte	.LASF509
	.byte	0x5
	.uleb128 0x4d
	.4byte	.LASF510
	.byte	0x5
	.uleb128 0x4e
	.4byte	.LASF511
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF512
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_private.h.17.07a34b78d08881aee229fc85c1b5b679,comdat
.Ldebug_macro6:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF513
	.byte	0x6
	.uleb128 0x23
	.4byte	.LASF514
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_S32xx.h.17.6d5d6f6ddac51d2588684e7e1fee0212,comdat
.Ldebug_macro7:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF515
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF516
	.byte	0x5
	.uleb128 0x2b
	.4byte	.LASF517
	.byte	0x5
	.uleb128 0x39
	.4byte	.LASF518
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF519
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF520
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF521
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF522
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF523
	.byte	0x5
	.uleb128 0x3f
	.4byte	.LASF524
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF525
	.byte	0x5
	.uleb128 0x81
	.4byte	.LASF526
	.byte	0x5
	.uleb128 0x8c
	.4byte	.LASF527
	.byte	0x5
	.uleb128 0x8f
	.4byte	.LASF528
	.byte	0x5
	.uleb128 0x90
	.4byte	.LASF529
	.byte	0x5
	.uleb128 0xa6
	.4byte	.LASF530
	.byte	0x5
	.uleb128 0xa7
	.4byte	.LASF531
	.byte	0x5
	.uleb128 0xa8
	.4byte	.LASF532
	.byte	0x5
	.uleb128 0xa9
	.4byte	.LASF533
	.byte	0x5
	.uleb128 0xaa
	.4byte	.LASF534
	.byte	0x5
	.uleb128 0xab
	.4byte	.LASF535
	.byte	0x5
	.uleb128 0xb6
	.4byte	.LASF536
	.byte	0x5
	.uleb128 0xb7
	.4byte	.LASF537
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF538
	.byte	0x5
	.uleb128 0xc4
	.4byte	.LASF539
	.byte	0x5
	.uleb128 0xc5
	.4byte	.LASF540
	.byte	0x5
	.uleb128 0xc6
	.4byte	.LASF541
	.byte	0x5
	.uleb128 0xc7
	.4byte	.LASF542
	.byte	0x5
	.uleb128 0xc8
	.4byte	.LASF543
	.byte	0x5
	.uleb128 0xc9
	.4byte	.LASF544
	.byte	0x5
	.uleb128 0xca
	.4byte	.LASF545
	.byte	0x5
	.uleb128 0xcb
	.4byte	.LASF546
	.byte	0x5
	.uleb128 0xcc
	.4byte	.LASF547
	.byte	0x5
	.uleb128 0xcd
	.4byte	.LASF548
	.byte	0x5
	.uleb128 0xce
	.4byte	.LASF549
	.byte	0x5
	.uleb128 0xcf
	.4byte	.LASF550
	.byte	0x5
	.uleb128 0xd0
	.4byte	.LASF551
	.byte	0x5
	.uleb128 0xd1
	.4byte	.LASF552
	.byte	0x5
	.uleb128 0xd8
	.4byte	.LASF553
	.byte	0x5
	.uleb128 0xd9
	.4byte	.LASF554
	.byte	0x5
	.uleb128 0xda
	.4byte	.LASF555
	.byte	0x5
	.uleb128 0xdb
	.4byte	.LASF556
	.byte	0x5
	.uleb128 0xdc
	.4byte	.LASF557
	.byte	0x5
	.uleb128 0xdd
	.4byte	.LASF558
	.byte	0x5
	.uleb128 0xde
	.4byte	.LASF559
	.byte	0x5
	.uleb128 0xdf
	.4byte	.LASF560
	.byte	0x5
	.uleb128 0xe2
	.4byte	.LASF561
	.byte	0x5
	.uleb128 0xe3
	.4byte	.LASF562
	.byte	0x5
	.uleb128 0xe4
	.4byte	.LASF563
	.byte	0x5
	.uleb128 0xe5
	.4byte	.LASF564
	.byte	0x5
	.uleb128 0xe6
	.4byte	.LASF565
	.byte	0x5
	.uleb128 0xe7
	.4byte	.LASF566
	.byte	0x5
	.uleb128 0xe8
	.4byte	.LASF567
	.byte	0x5
	.uleb128 0xe9
	.4byte	.LASF568
	.byte	0x5
	.uleb128 0xea
	.4byte	.LASF569
	.byte	0x5
	.uleb128 0xeb
	.4byte	.LASF570
	.byte	0x5
	.uleb128 0xec
	.4byte	.LASF571
	.byte	0x5
	.uleb128 0xed
	.4byte	.LASF572
	.byte	0x5
	.uleb128 0xee
	.4byte	.LASF573
	.byte	0x5
	.uleb128 0xef
	.4byte	.LASF574
	.byte	0x5
	.uleb128 0xf0
	.4byte	.LASF575
	.byte	0x5
	.uleb128 0xf1
	.4byte	.LASF576
	.byte	0x5
	.uleb128 0xf4
	.4byte	.LASF577
	.byte	0x5
	.uleb128 0xf5
	.4byte	.LASF578
	.byte	0x5
	.uleb128 0xf6
	.4byte	.LASF579
	.byte	0x5
	.uleb128 0xf7
	.4byte	.LASF580
	.byte	0x5
	.uleb128 0xf8
	.4byte	.LASF581
	.byte	0x5
	.uleb128 0xf9
	.4byte	.LASF582
	.byte	0x5
	.uleb128 0xfa
	.4byte	.LASF583
	.byte	0x5
	.uleb128 0xfb
	.4byte	.LASF584
	.byte	0x5
	.uleb128 0xfc
	.4byte	.LASF585
	.byte	0x5
	.uleb128 0xfd
	.4byte	.LASF586
	.byte	0x5
	.uleb128 0xfe
	.4byte	.LASF587
	.byte	0x5
	.uleb128 0x101
	.4byte	.LASF588
	.byte	0x5
	.uleb128 0x102
	.4byte	.LASF589
	.byte	0x5
	.uleb128 0x103
	.4byte	.LASF590
	.byte	0x5
	.uleb128 0x104
	.4byte	.LASF591
	.byte	0x5
	.uleb128 0x107
	.4byte	.LASF592
	.byte	0x5
	.uleb128 0x108
	.4byte	.LASF593
	.byte	0x5
	.uleb128 0x109
	.4byte	.LASF594
	.byte	0x5
	.uleb128 0x10a
	.4byte	.LASF595
	.byte	0x5
	.uleb128 0x10b
	.4byte	.LASF596
	.byte	0x5
	.uleb128 0x115
	.4byte	.LASF597
	.byte	0x5
	.uleb128 0x116
	.4byte	.LASF598
	.byte	0x5
	.uleb128 0x119
	.4byte	.LASF599
	.byte	0x5
	.uleb128 0x11a
	.4byte	.LASF600
	.byte	0x5
	.uleb128 0x11c
	.4byte	.LASF601
	.byte	0x5
	.uleb128 0x11f
	.4byte	.LASF602
	.byte	0x5
	.uleb128 0x120
	.4byte	.LASF603
	.byte	0x5
	.uleb128 0x123
	.4byte	.LASF604
	.byte	0x5
	.uleb128 0x124
	.4byte	.LASF605
	.byte	0x5
	.uleb128 0x127
	.4byte	.LASF606
	.byte	0x5
	.uleb128 0x12a
	.4byte	.LASF607
	.byte	0x5
	.uleb128 0x12d
	.4byte	.LASF608
	.byte	0x5
	.uleb128 0x130
	.4byte	.LASF609
	.byte	0x5
	.uleb128 0x15e
	.4byte	.LASF610
	.byte	0x5
	.uleb128 0x160
	.4byte	.LASF611
	.byte	0x5
	.uleb128 0x161
	.4byte	.LASF612
	.byte	0x5
	.uleb128 0x163
	.4byte	.LASF613
	.byte	0x5
	.uleb128 0x164
	.4byte	.LASF614
	.byte	0x5
	.uleb128 0x167
	.4byte	.LASF615
	.byte	0x5
	.uleb128 0x168
	.4byte	.LASF616
	.byte	0x5
	.uleb128 0x169
	.4byte	.LASF617
	.byte	0x5
	.uleb128 0x16a
	.4byte	.LASF618
	.byte	0x5
	.uleb128 0x16b
	.4byte	.LASF619
	.byte	0x5
	.uleb128 0x16c
	.4byte	.LASF620
	.byte	0x5
	.uleb128 0x16d
	.4byte	.LASF621
	.byte	0x5
	.uleb128 0x170
	.4byte	.LASF622
	.byte	0x5
	.uleb128 0x171
	.4byte	.LASF623
	.byte	0x5
	.uleb128 0x172
	.4byte	.LASF624
	.byte	0x5
	.uleb128 0x173
	.4byte	.LASF625
	.byte	0x5
	.uleb128 0x174
	.4byte	.LASF626
	.byte	0x5
	.uleb128 0x175
	.4byte	.LASF627
	.byte	0x5
	.uleb128 0x176
	.4byte	.LASF628
	.byte	0x5
	.uleb128 0x177
	.4byte	.LASF629
	.byte	0x5
	.uleb128 0x178
	.4byte	.LASF630
	.byte	0x5
	.uleb128 0x179
	.4byte	.LASF631
	.byte	0x5
	.uleb128 0x17a
	.4byte	.LASF632
	.byte	0x5
	.uleb128 0x17b
	.4byte	.LASF633
	.byte	0x5
	.uleb128 0x17c
	.4byte	.LASF634
	.byte	0x5
	.uleb128 0x17f
	.4byte	.LASF635
	.byte	0x5
	.uleb128 0x180
	.4byte	.LASF636
	.byte	0x5
	.uleb128 0x181
	.4byte	.LASF637
	.byte	0x5
	.uleb128 0x182
	.4byte	.LASF638
	.byte	0x5
	.uleb128 0x185
	.4byte	.LASF639
	.byte	0x5
	.uleb128 0x188
	.4byte	.LASF640
	.byte	0x5
	.uleb128 0x18b
	.4byte	.LASF641
	.byte	0x5
	.uleb128 0x18e
	.4byte	.LASF642
	.byte	0x5
	.uleb128 0x191
	.4byte	.LASF643
	.byte	0x5
	.uleb128 0x196
	.4byte	.LASF644
	.byte	0x5
	.uleb128 0x199
	.4byte	.LASF645
	.byte	0x5
	.uleb128 0x19e
	.4byte	.LASF646
	.byte	0x5
	.uleb128 0x1a3
	.4byte	.LASF647
	.byte	0x5
	.uleb128 0x1a6
	.4byte	.LASF648
	.byte	0x5
	.uleb128 0x1a7
	.4byte	.LASF649
	.byte	0x5
	.uleb128 0x1a8
	.4byte	.LASF650
	.byte	0x5
	.uleb128 0x1a9
	.4byte	.LASF651
	.byte	0x5
	.uleb128 0x1ac
	.4byte	.LASF652
	.byte	0x5
	.uleb128 0x1b5
	.4byte	.LASF653
	.byte	0x5
	.uleb128 0x1bd
	.4byte	.LASF654
	.byte	0x5
	.uleb128 0x1c7
	.4byte	.LASF655
	.byte	0x5
	.uleb128 0x1cc
	.4byte	.LASF656
	.byte	0x5
	.uleb128 0x1d3
	.4byte	.LASF657
	.byte	0x5
	.uleb128 0x1d9
	.4byte	.LASF658
	.byte	0x5
	.uleb128 0x1df
	.4byte	.LASF659
	.byte	0x5
	.uleb128 0x1e2
	.4byte	.LASF660
	.byte	0x5
	.uleb128 0x1ec
	.4byte	.LASF661
	.byte	0x5
	.uleb128 0x1f0
	.4byte	.LASF662
	.byte	0x5
	.uleb128 0x1f8
	.4byte	.LASF663
	.byte	0x5
	.uleb128 0x1fc
	.4byte	.LASF664
	.byte	0x5
	.uleb128 0x201
	.4byte	.LASF665
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_private.h.142.92ba5e12407321b7284fb769c2bdf534,comdat
.Ldebug_macro8:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF666
	.byte	0x5
	.uleb128 0xaf
	.4byte	.LASF667
	.byte	0x5
	.uleb128 0xb3
	.4byte	.LASF668
	.byte	0x5
	.uleb128 0xbe
	.4byte	.LASF669
	.byte	0x5
	.uleb128 0xc2
	.4byte	.LASF670
	.byte	0x5
	.uleb128 0xc3
	.4byte	.LASF671
	.byte	0x5
	.uleb128 0x10e
	.4byte	.LASF672
	.byte	0x5
	.uleb128 0x123
	.4byte	.LASF673
	.byte	0x5
	.uleb128 0x187
	.4byte	.LASF674
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_protocol.h.17.60944746259c025cd7741be15b21d723,comdat
.Ldebug_macro9:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF675
	.byte	0x5
	.uleb128 0x17
	.4byte	.LASF676
	.byte	0x5
	.uleb128 0x18
	.4byte	.LASF677
	.byte	0x5
	.uleb128 0x19
	.4byte	.LASF678
	.byte	0x5
	.uleb128 0x1a
	.4byte	.LASF679
	.byte	0x5
	.uleb128 0x1b
	.4byte	.LASF680
	.byte	0x5
	.uleb128 0x1c
	.4byte	.LASF681
	.byte	0x5
	.uleb128 0x1d
	.4byte	.LASF682
	.byte	0x5
	.uleb128 0x1e
	.4byte	.LASF683
	.byte	0x5
	.uleb128 0x1f
	.4byte	.LASF684
	.byte	0x5
	.uleb128 0x20
	.4byte	.LASF685
	.byte	0x5
	.uleb128 0x21
	.4byte	.LASF686
	.byte	0x5
	.uleb128 0x22
	.4byte	.LASF687
	.byte	0x5
	.uleb128 0x23
	.4byte	.LASF688
	.byte	0x5
	.uleb128 0x24
	.4byte	.LASF689
	.byte	0x5
	.uleb128 0x25
	.4byte	.LASF690
	.byte	0x5
	.uleb128 0x26
	.4byte	.LASF691
	.byte	0x5
	.uleb128 0x2d
	.4byte	.LASF692
	.byte	0x5
	.uleb128 0x2e
	.4byte	.LASF693
	.byte	0x5
	.uleb128 0x2f
	.4byte	.LASF694
	.byte	0x5
	.uleb128 0x30
	.4byte	.LASF695
	.byte	0x5
	.uleb128 0x31
	.4byte	.LASF696
	.byte	0x5
	.uleb128 0x32
	.4byte	.LASF697
	.byte	0x5
	.uleb128 0x33
	.4byte	.LASF698
	.byte	0x5
	.uleb128 0x34
	.4byte	.LASF699
	.byte	0x5
	.uleb128 0x35
	.4byte	.LASF700
	.byte	0x5
	.uleb128 0x36
	.4byte	.LASF701
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF702
	.byte	0x5
	.uleb128 0x3a
	.4byte	.LASF703
	.byte	0x5
	.uleb128 0x3b
	.4byte	.LASF704
	.byte	0x5
	.uleb128 0x3c
	.4byte	.LASF705
	.byte	0x5
	.uleb128 0x3d
	.4byte	.LASF706
	.byte	0x5
	.uleb128 0x3e
	.4byte	.LASF707
	.byte	0x5
	.uleb128 0x41
	.4byte	.LASF708
	.byte	0x5
	.uleb128 0x42
	.4byte	.LASF709
	.byte	0x5
	.uleb128 0x43
	.4byte	.LASF710
	.byte	0x5
	.uleb128 0x44
	.4byte	.LASF711
	.byte	0x5
	.uleb128 0x45
	.4byte	.LASF712
	.byte	0x5
	.uleb128 0x46
	.4byte	.LASF713
	.byte	0x5
	.uleb128 0x47
	.4byte	.LASF714
	.byte	0x5
	.uleb128 0x4a
	.4byte	.LASF715
	.byte	0x5
	.uleb128 0x4b
	.4byte	.LASF716
	.byte	0x5
	.uleb128 0x52
	.4byte	.LASF717
	.byte	0x5
	.uleb128 0x53
	.4byte	.LASF718
	.byte	0x5
	.uleb128 0x54
	.4byte	.LASF719
	.byte	0x5
	.uleb128 0x57
	.4byte	.LASF720
	.byte	0x5
	.uleb128 0x58
	.4byte	.LASF721
	.byte	0x5
	.uleb128 0x59
	.4byte	.LASF722
	.byte	0x5
	.uleb128 0x5c
	.4byte	.LASF723
	.byte	0x5
	.uleb128 0x5d
	.4byte	.LASF724
	.byte	0x5
	.uleb128 0x5e
	.4byte	.LASF725
	.byte	0x5
	.uleb128 0x5f
	.4byte	.LASF726
	.byte	0x5
	.uleb128 0x60
	.4byte	.LASF727
	.byte	0x5
	.uleb128 0x61
	.4byte	.LASF728
	.byte	0x5
	.uleb128 0x62
	.4byte	.LASF729
	.byte	0x5
	.uleb128 0x63
	.4byte	.LASF730
	.byte	0x5
	.uleb128 0x64
	.4byte	.LASF731
	.byte	0x5
	.uleb128 0x65
	.4byte	.LASF732
	.byte	0x5
	.uleb128 0x66
	.4byte	.LASF733
	.byte	0x5
	.uleb128 0x67
	.4byte	.LASF734
	.byte	0x5
	.uleb128 0x68
	.4byte	.LASF735
	.byte	0x5
	.uleb128 0x69
	.4byte	.LASF736
	.byte	0x5
	.uleb128 0x6a
	.4byte	.LASF737
	.byte	0x5
	.uleb128 0x6b
	.4byte	.LASF738
	.byte	0x5
	.uleb128 0x6c
	.4byte	.LASF739
	.byte	0x5
	.uleb128 0x72
	.4byte	.LASF740
	.byte	0x5
	.uleb128 0x73
	.4byte	.LASF741
	.byte	0x5
	.uleb128 0x74
	.4byte	.LASF742
	.byte	0x5
	.uleb128 0x75
	.4byte	.LASF743
	.byte	0x5
	.uleb128 0x76
	.4byte	.LASF744
	.byte	0x5
	.uleb128 0x79
	.4byte	.LASF745
	.byte	0x5
	.uleb128 0x7a
	.4byte	.LASF746
	.byte	0x5
	.uleb128 0x7d
	.4byte	.LASF747
	.byte	0x5
	.uleb128 0x7e
	.4byte	.LASF748
	.byte	0x5
	.uleb128 0x7f
	.4byte	.LASF749
	.byte	0x5
	.uleb128 0x86
	.4byte	.LASF750
	.byte	0x5
	.uleb128 0x87
	.4byte	.LASF751
	.byte	0x5
	.uleb128 0x88
	.4byte	.LASF752
	.byte	0x5
	.uleb128 0x89
	.4byte	.LASF753
	.byte	0x5
	.uleb128 0x8a
	.4byte	.LASF754
	.byte	0x5
	.uleb128 0x8b
	.4byte	.LASF755
	.byte	0x5
	.uleb128 0x8e
	.4byte	.LASF756
	.byte	0x5
	.uleb128 0x95
	.4byte	.LASF757
	.byte	0x5
	.uleb128 0x96
	.4byte	.LASF758
	.byte	0x5
	.uleb128 0x99
	.4byte	.LASF759
	.byte	0x5
	.uleb128 0x9a
	.4byte	.LASF760
	.byte	0x5
	.uleb128 0x9b
	.4byte	.LASF761
	.byte	0x5
	.uleb128 0x9c
	.4byte	.LASF762
	.byte	0x5
	.uleb128 0x9d
	.4byte	.LASF763
	.byte	0
	.section	.debug_macro,"G",%progbits,wm4.freemaster_rec.h.17.d110d387018f0f1227dc16d8dc20259b,comdat
.Ldebug_macro10:
	.2byte	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x11
	.4byte	.LASF764
	.byte	0x5
	.uleb128 0x37
	.4byte	.LASF765
	.byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF500:
	.ascii	"FMSTR_TSA_HREF(linkname,link_uri) \000"
.LASF160:
	.ascii	"__DECIMAL_DIG__ 17\000"
.LASF297:
	.ascii	"__UHA_FBIT__ 8\000"
.LASF548:
	.ascii	"FMSTR_SETREG32(base,offset,value) (*(volatile FMSTR"
	.ascii	"_U32*)(((FMSTR_U32)(base))+(offset)) = value)\000"
.LASF396:
	.ascii	"FMSTR_USE_TSA_SAFETY FMSTR_DEMO_ENOUGH_RAM\000"
.LASF112:
	.ascii	"__INT_FAST32_MAX__ 2147483647\000"
.LASF75:
	.ascii	"__WCHAR_MIN__ 0U\000"
.LASF316:
	.ascii	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2\000"
.LASF265:
	.ascii	"__ULLACCUM_IBIT__ 32\000"
.LASF189:
	.ascii	"__SFRACT_FBIT__ 7\000"
.LASF829:
	.ascii	"sizetype\000"
.LASF73:
	.ascii	"__LONG_LONG_MAX__ 9223372036854775807LL\000"
.LASF535:
	.ascii	"FMSTR_GetU32(addr) ( *(FMSTR_U32*)(addr) )\000"
.LASF261:
	.ascii	"__LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)\000"
.LASF599:
	.ascii	"FMSTR_SCI_RE() FMSTR_SETBIT32(FMSTR_SCI_BASE, FMSTR"
	.ascii	"_SCICTRL_OFFSET, FMSTR_SCICTRL_RE)\000"
.LASF253:
	.ascii	"__LACCUM_EPSILON__ 0x1P-31LK\000"
.LASF186:
	.ascii	"__DEC128_MAX__ 9.999999999999999999999999999999999E"
	.ascii	"6144DL\000"
.LASF116:
	.ascii	"__UINT_FAST32_MAX__ 4294967295U\000"
.LASF663:
	.ascii	"FMSTR_FCAN_RLEN(pctx) (FMSTR_GETREG8(FMSTR_CAN_BASE"
	.ascii	", FMSTR_FCANRXFG_OFFSET+FMSTR_FCMBCSR+2) & 0x0f)\000"
.LASF487:
	.ascii	"FMSTR_TSA_MEMORY NULL\000"
.LASF729:
	.ascii	"FMSTR_STC_SERVBUSY 0x87U\000"
.LASF174:
	.ascii	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF\000"
.LASF278:
	.ascii	"__TQ_IBIT__ 0\000"
.LASF685:
	.ascii	"FMSTR_CMD_SETUPREC_EX 0x0bU\000"
.LASF639:
	.ascii	"FMSTR_FCANID0_EXT_FLG 0x80\000"
.LASF12:
	.ascii	"__ATOMIC_CONSUME 1\000"
.LASF211:
	.ascii	"__LFRACT_MIN__ (-0.5LR-0.5LR)\000"
.LASF616:
	.ascii	"FMSTR_FCANIER2_OFFSET 0x24\000"
.LASF403:
	.ascii	"FMSTR_USE_READVAR 1\000"
.LASF506:
	.ascii	"FMSTR_APPCMDRESULT_RUNNING 0xfeU\000"
.LASF558:
	.ascii	"FMSTR_SCIS2_OFFSET 5\000"
.LASF17:
	.ascii	"__SIZEOF_LONG_LONG__ 8\000"
.LASF201:
	.ascii	"__FRACT_MIN__ (-0.5R-0.5R)\000"
.LASF608:
	.ascii	"FMSTR_SCI_GETSR() FMSTR_GETREG32(FMSTR_SCI_BASE, FM"
	.ascii	"STR_SCISTATUS_OFFSET)\000"
.LASF267:
	.ascii	"__ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK\000"
.LASF237:
	.ascii	"__USACCUM_MAX__ 0XFFFFP-8UHK\000"
.LASF171:
	.ascii	"__DEC32_MIN__ 1E-95DF\000"
.LASF594:
	.ascii	"FMSTR_SCICTRL_TIE 0x800000\000"
.LASF377:
	.ascii	"FMSTR_DEMO_ENOUGH_RAM 1\000"
.LASF27:
	.ascii	"__ORDER_PDP_ENDIAN__ 3412\000"
.LASF215:
	.ascii	"__ULFRACT_IBIT__ 0\000"
.LASF177:
	.ascii	"__DEC64_MAX_EXP__ 385\000"
.LASF439:
	.ascii	"FMSTR_COMM_BUFFER_SIZE\000"
.LASF850:
	.ascii	"../FreeMASTER/src_common/freemaster_rec.c\000"
.LASF136:
	.ascii	"__FLT_HAS_DENORM__ 1\000"
.LASF419:
	.ascii	"FMSTR_SCI_BASE_DYNAMIC 0\000"
.LASF338:
	.ascii	"__ARM_ARCH_PROFILE 77\000"
.LASF236:
	.ascii	"__USACCUM_MIN__ 0.0UHK\000"
.LASF670:
	.ascii	"FMSTR_MACROCODE_BEGIN() do{\000"
.LASF33:
	.ascii	"__WCHAR_TYPE__ unsigned int\000"
.LASF756:
	.ascii	"FMSTR_CANSPC_PING 0xc0\000"
.LASF156:
	.ascii	"__LDBL_MIN_EXP__ (-1021)\000"
.LASF776:
	.ascii	"FMSTR_U32\000"
.LASF526:
	.ascii	"FMSTR_ValueToBuffer8(pDest,src) ( (*((FMSTR_U8*)(pD"
	.ascii	"est)) = (FMSTR_U8)(src)), (((FMSTR_BPTR)(pDest))+1)"
	.ascii	" )\000"
.LASF547:
	.ascii	"FMSTR_TSTBIT16(base,offset,bit) (*(volatile FMSTR_U"
	.ascii	"16*)(((FMSTR_U32)(base))+(offset)) & (bit))\000"
.LASF449:
	.ascii	"FMSTR_TSA_INFO_MEMBER 0x0002U\000"
.LASF103:
	.ascii	"__UINT8_C(c) c\000"
.LASF34:
	.ascii	"__WINT_TYPE__ unsigned int\000"
.LASF379:
	.ascii	"FMSTR_DEMO_LARGE_ROM 1\000"
.LASF252:
	.ascii	"__LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK\000"
.LASF567:
	.ascii	"FMSTR_SCIC1_PE 0x02\000"
.LASF735:
	.ascii	"FMSTR_STC_FASTRECERR 0x8DU\000"
.LASF777:
	.ascii	"FMSTR_S8\000"
.LASF731:
	.ascii	"FMSTR_STC_EACCESS 0x89U\000"
.LASF466:
	.ascii	"FMSTR_TSA_UINT8 \"\\xE0\"\000"
.LASF514:
	.ascii	"FMSTR_PLATFORM\000"
.LASF44:
	.ascii	"__UINT8_TYPE__ unsigned char\000"
.LASF309:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1\000"
.LASF620:
	.ascii	"FMSTR_FCANRXFG_OFFSET (0x80 + ((FMSTR_FLEXCAN_RXMB)"
	.ascii	" * 0x10))\000"
.LASF375:
	.ascii	"FMSTR_COMM_BUFFER_SIZE 0\000"
.LASF224:
	.ascii	"__ULLFRACT_FBIT__ 64\000"
.LASF605:
	.ascii	"FMSTR_SCI_DRXI() FMSTR_CLRBIT32(FMSTR_SCI_BASE, FMS"
	.ascii	"TR_SCICTRL_OFFSET, FMSTR_SCICTRL_RIE)\000"
.LASF59:
	.ascii	"__INT_FAST64_TYPE__ long long int\000"
.LASF630:
	.ascii	"FMSTR_FCMBDSR3 0x08\000"
.LASF734:
	.ascii	"FMSTR_STC_PIPEERR 0x8CU\000"
.LASF717:
	.ascii	"FMSTR_STSF_ERROR 0x80U\000"
.LASF93:
	.ascii	"__UINT64_MAX__ 18446744073709551615ULL\000"
.LASF460:
	.ascii	"FMSTR_TSA_MEMBER_CFG(parenttype,name,type) FMSTR_TS"
	.ascii	"ATBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY"
	.ascii	"(type), FMSTR_TSATBL_VOIDPTR_ENTRY(&((parenttype*)0"
	.ascii	")->name), FMSTR_TSATBL_VOIDPTR_ENTRY(FMSTR_TSA_INFO"
	.ascii	"1(((parenttype*)0)->name, FMSTR_TSA_INFO_MEMBER)),\000"
.LASF197:
	.ascii	"__USFRACT_MAX__ 0XFFP-8UHR\000"
.LASF758:
	.ascii	"FMSTR_PDBDM_BUFFBORDER_CODE2 0xf81f\000"
.LASF676:
	.ascii	"FMSTR_CMD_READMEM 0x01U\000"
.LASF477:
	.ascii	"FMSTR_TSA_UFRAC64 \"\\xE7\"\000"
.LASF669:
	.ascii	"FMSTR_INLINE static\000"
.LASF505:
	.ascii	"FMSTR_APPCMDRESULT_NOCMD 0xffU\000"
.LASF656:
	.ascii	"FMSTR_FCAN_PUTBYTE(pctx,dataByte) FMSTR_MACROCODE_B"
	.ascii	"EGIN() FMSTR_SETREG8(FMSTR_CAN_BASE, (FMSTR_FCANTXF"
	.ascii	"G_OFFSET + FMSTR_FCMBDSR0) - (0x3&((pctx)->nDataIx)"
	.ascii	") + (0x4&((pctx)->nDataIx)), (dataByte) ); (pctx)->"
	.ascii	"nDataIx++; FMSTR_MACROCODE_END()\000"
.LASF673:
	.ascii	"FMSTR_COUNT_INTERFACES ( ((FMSTR_DISABLE)?1:0) + (("
	.ascii	"FMSTR_USE_SCI)?1:0) + ((FMSTR_USE_ESCI)?1:0) + ((FM"
	.ascii	"STR_USE_LPUART)?1:0) + ((FMSTR_USE_PDBDM)?1:0) + (("
	.ascii	"FMSTR_USE_JTAG)?1:0) + ((FMSTR_USE_CAN)?1:0) + ((FM"
	.ascii	"STR_USE_LINTL)?1:0) + ((FMSTR_USE_MQX_IO)?1:0) + (("
	.ascii	"FMSTR_USE_USB_CDC)?1:0) + ((FMSTR_USE_MBED)?1:0) )\000"
.LASF572:
	.ascii	"FMSTR_SCIC2_ILIE 0x10\000"
.LASF593:
	.ascii	"FMSTR_SCICTRL_RE 0x040000\000"
.LASF214:
	.ascii	"__ULFRACT_FBIT__ 32\000"
.LASF448:
	.ascii	"FMSTR_TSA_INFO_RO_VAR 0x0001U\000"
.LASF457:
	.ascii	"FMSTR_TSATBL_VOIDPTR_CAST(x) ((FMSTR_TSATBL_VOIDPTR"
	.ascii	")(x))\000"
.LASF492:
	.ascii	"FMSTR_TSA_MEMBER(parenttype,name,type) \000"
.LASF386:
	.ascii	"FMSTR_USE_SCOPE FMSTR_DEMO_ENOUGH_RAM\000"
.LASF350:
	.ascii	"__ARM_NEON_FP 4\000"
.LASF1:
	.ascii	"__STDC_VERSION__ 199901L\000"
.LASF393:
	.ascii	"FMSTR_REC_FLOAT_TRIG 0\000"
.LASF193:
	.ascii	"__SFRACT_EPSILON__ 0x1P-7HR\000"
.LASF855:
	.ascii	"FMSTR_CopyMemory\000"
.LASF99:
	.ascii	"__INT32_C(c) c ## L\000"
.LASF283:
	.ascii	"__USQ_FBIT__ 32\000"
.LASF26:
	.ascii	"__ORDER_BIG_ENDIAN__ 4321\000"
.LASF234:
	.ascii	"__USACCUM_FBIT__ 8\000"
.LASF273:
	.ascii	"__SQ_FBIT__ 31\000"
.LASF117:
	.ascii	"__UINT_FAST64_MAX__ 18446744073709551615ULL\000"
.LASF652:
	.ascii	"FMSTR_FCAN_RINIT(idr0,idr1,idr2,idr3) FMSTR_MACROCO"
	.ascii	"DE_BEGIN() (((idr0)&FMSTR_FCANID0_EXT_FLG) ? (FMSTR"
	.ascii	"_SETREG16(FMSTR_CAN_BASE, FMSTR_FCANRXFG_OFFSET + F"
	.ascii	"MSTR_FCMBCSR + 2, (FMSTR_FCANMB_CRXVOID<<8 | FMSTR_"
	.ascii	"FCANCTRL_IDE | FMSTR_FCANCTRL_EXT_SRR))) : (FMSTR_S"
	.ascii	"ETREG16(FMSTR_CAN_BASE, FMSTR_FCANRXFG_OFFSET + FMS"
	.ascii	"TR_FCMBCSR + 2, (FMSTR_FCANMB_CRXVOID<<8 | FMSTR_FC"
	.ascii	"ANCTRL_EXT_SRR)))); FMSTR_SETREG32(FMSTR_CAN_BASE, "
	.ascii	"FMSTR_FCANRXFG_OFFSET + FMSTR_FCMBIDR0, ((idr0)<<24"
	.ascii	") | ((idr1)<<16) | ((idr2)<<8) | (idr3) ); FMSTR_MA"
	.ascii	"CROCODE_END()\000"
.LASF281:
	.ascii	"__UHQ_FBIT__ 16\000"
.LASF378:
	.ascii	"FMSTR_DEMO_ENOUGH_ROM 1\000"
.LASF476:
	.ascii	"FMSTR_TSA_UFRAC32 \"\\xE6\"\000"
.LASF69:
	.ascii	"__SCHAR_MAX__ 127\000"
.LASF173:
	.ascii	"__DEC32_EPSILON__ 1E-6DF\000"
.LASF250:
	.ascii	"__LACCUM_IBIT__ 32\000"
.LASF71:
	.ascii	"__INT_MAX__ 2147483647\000"
.LASF837:
	.ascii	"pcm_pRecVarSize\000"
.LASF87:
	.ascii	"__INT16_MAX__ 32767\000"
.LASF406:
	.ascii	"FMSTR_VERSION 0x00020000\000"
.LASF689:
	.ascii	"FMSTR_CMD_SFIOFRAME_1 0x13U\000"
.LASF347:
	.ascii	"__VFP_FP__ 1\000"
.LASF221:
	.ascii	"__LLFRACT_MIN__ (-0.5LLR-0.5LLR)\000"
.LASF774:
	.ascii	"FMSTR_U8\000"
.LASF154:
	.ascii	"__LDBL_MANT_DIG__ 53\000"
.LASF766:
	.ascii	"CMP(v,t) ((FMSTR_BOOL)(((v) < (t)) ? 0 : 1))\000"
.LASF631:
	.ascii	"FMSTR_FCMBDSR4 0x0F\000"
.LASF697:
	.ascii	"FMSTR_CMD_READSCOPE 0xc5U\000"
.LASF796:
	.ascii	"FMSTR_Compare16S\000"
.LASF525:
	.ascii	"FMSTR_ValueFromBuffer8(pDest,pSrc) ( (*((FMSTR_U8*)"
	.ascii	"(pDest)) = *(FMSTR_U8*)(pSrc)), (((FMSTR_BPTR)(pSrc"
	.ascii	"))+1) )\000"
.LASF797:
	.ascii	"FMSTR_Compare16U\000"
.LASF172:
	.ascii	"__DEC32_MAX__ 9.999999E96DF\000"
.LASF206:
	.ascii	"__UFRACT_MIN__ 0.0UR\000"
.LASF167:
	.ascii	"__LDBL_HAS_QUIET_NAN__ 1\000"
.LASF629:
	.ascii	"FMSTR_FCMBDSR2 0x09\000"
.LASF586:
	.ascii	"FMSTR_SCISR2_TXDIR 0x02\000"
.LASF831:
	.ascii	"pcm_wRecTotalSmps\000"
.LASF52:
	.ascii	"__UINT_LEAST8_TYPE__ unsigned char\000"
.LASF845:
	.ascii	"FMSTR_AddressFromBuffer\000"
.LASF367:
	.ascii	"FMSTR_SCI_BASE 0x4006B000UL\000"
.LASF239:
	.ascii	"__ACCUM_FBIT__ 15\000"
.LASF245:
	.ascii	"__UACCUM_IBIT__ 16\000"
.LASF782:
	.ascii	"long int\000"
.LASF772:
	.ascii	"FMSTR_SIZE_RECBUFF\000"
.LASF609:
	.ascii	"FMSTR_SCI_RDCLRSR() (FMSTR_GETREG32(FMSTR_SCI_BASE,"
	.ascii	" FMSTR_SCISTATUS_OFFSET)>>16); FMSTR_SETREG32(FMSTR"
	.ascii	"_SCI_BASE, FMSTR_SCISTATUS_OFFSET, FMSTR_GETREG32(F"
	.ascii	"MSTR_SCI_BASE, FMSTR_SCISTATUS_OFFSET));\000"
.LASF148:
	.ascii	"__DBL_MIN__ ((double)2.2250738585072014e-308L)\000"
.LASF667:
	.ascii	"FMSTR_TRUE (1U)\000"
.LASF74:
	.ascii	"__WCHAR_MAX__ 4294967295U\000"
.LASF183:
	.ascii	"__DEC128_MIN_EXP__ (-6142)\000"
.LASF56:
	.ascii	"__INT_FAST8_TYPE__ int\000"
.LASF553:
	.ascii	"FMSTR_SCIBDH_OFFSET 0\000"
.LASF816:
	.ascii	"FMSTR_IsInRecBuffer\000"
.LASF527:
	.ascii	"FMSTR_SkipInBuffer(pDest,nSize) ( ((FMSTR_BPTR)(pDe"
	.ascii	"st)) + (nSize) )\000"
.LASF695:
	.ascii	"FMSTR_CMD_GETRECSTS 0xc3U\000"
.LASF747:
	.ascii	"FMSTR_TSA_INFO_VERSION_MASK 0x000fU\000"
.LASF83:
	.ascii	"__UINTMAX_C(c) c ## ULL\000"
.LASF30:
	.ascii	"__SIZEOF_POINTER__ 4\000"
.LASF48:
	.ascii	"__INT_LEAST8_TYPE__ signed char\000"
.LASF595:
	.ascii	"FMSTR_SCICTRL_TCIE 0x400000\000"
.LASF841:
	.ascii	"pcm_wRecTimeDivCtr\000"
.LASF291:
	.ascii	"__SA_FBIT__ 15\000"
.LASF399:
	.ascii	"FMSTR_MAX_PIPES_COUNT 3\000"
.LASF111:
	.ascii	"__INT_FAST16_MAX__ 2147483647\000"
.LASF351:
	.ascii	"__THUMB_INTERWORK__ 1\000"
.LASF227:
	.ascii	"__ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR\000"
.LASF86:
	.ascii	"__INT8_MAX__ 127\000"
.LASF801:
	.ascii	"nBuffSize\000"
.LASF840:
	.ascii	"pcm_dwRecEndBuffPtr\000"
.LASF790:
	.ascii	"bTrgCrossActive\000"
.LASF38:
	.ascii	"__CHAR32_TYPE__ long unsigned int\000"
.LASF382:
	.ascii	"FMSTR_DEMO_SUPPORT_DBL 1\000"
.LASF713:
	.ascii	"FMSTR_CMD_WRITEVAR8MASK 0xe5U\000"
.LASF716:
	.ascii	"FMSTR_CMD_WRITEVAR16MASK 0xf1U\000"
.LASF129:
	.ascii	"__FLT_MAX_EXP__ 128\000"
.LASF16:
	.ascii	"__SIZEOF_LONG__ 4\000"
.LASF600:
	.ascii	"FMSTR_SCI_RD() FMSTR_CLRBIT32(FMSTR_SCI_BASE, FMSTR"
	.ascii	"_SCICTRL_OFFSET, FMSTR_SCICTRL_RE)\000"
.LASF726:
	.ascii	"FMSTR_STC_RSPBUFFOVF 0x84U\000"
.LASF537:
	.ascii	"FMSTR_ARR2ADDR FMSTR_PTR2ADDR\000"
.LASF20:
	.ascii	"__SIZEOF_DOUBLE__ 8\000"
.LASF753:
	.ascii	"FMSTR_CANCTL_LST 0x10\000"
.LASF814:
	.ascii	"FMSTR_StopRec_exit\000"
.LASF540:
	.ascii	"FMSTR_GETREG8(base,offset) (*(volatile FMSTR_U8*)(("
	.ascii	"(FMSTR_U32)(base))+(offset)))\000"
.LASF179:
	.ascii	"__DEC64_MAX__ 9.999999999999999E384DD\000"
.LASF561:
	.ascii	"FMSTR_SCIC1_LOOPS 0x80\000"
.LASF383:
	.ascii	"FMSTR_USE_APPCMD FMSTR_DEMO_ENOUGH_ROM\000"
.LASF303:
	.ascii	"__UTA_FBIT__ 64\000"
.LASF606:
	.ascii	"FMSTR_SCI_PUTCHAR(ch) FMSTR_SETREG8(FMSTR_SCI_BASE,"
	.ascii	" FMSTR_SCIDATA_OFFSET, ch)\000"
.LASF131:
	.ascii	"__FLT_DECIMAL_DIG__ 9\000"
.LASF621:
	.ascii	"FMSTR_FCANTXFG_OFFSET (0x80 + ((FMSTR_FLEXCAN_TXMB)"
	.ascii	" * 0x10))\000"
.LASF778:
	.ascii	"signed char\000"
.LASF370:
	.ascii	"FMSTR_USE_LPUART 1\000"
.LASF207:
	.ascii	"__UFRACT_MAX__ 0XFFFFP-16UR\000"
.LASF349:
	.ascii	"__ARM_FEATURE_FMA 1\000"
.LASF307:
	.ascii	"__GNUC_STDC_INLINE__ 1\000"
.LASF708:
	.ascii	"FMSTR_CMD_READVAR8_EX 0xe0U\000"
.LASF82:
	.ascii	"__UINTMAX_MAX__ 18446744073709551615ULL\000"
.LASF849:
	.ascii	"GNU C 4.9.3 20150529 (release) [ARM/embedded-4_9-br"
	.ascii	"anch revision 227977] -mcpu=cortex-m4 -mthumb -mflo"
	.ascii	"at-abi=hard -mfpu=fpv4-sp-d16 -g3 -O1 -std=c99 -fun"
	.ascii	"signed-bitfields -fshort-enums -fno-jump-tables -fm"
	.ascii	"essage-length=0 -fsigned-char -ffunction-sections -"
	.ascii	"fdata-sections\000"
.LASF199:
	.ascii	"__FRACT_FBIT__ 15\000"
.LASF263:
	.ascii	"__LLACCUM_EPSILON__ 0x1P-31LLK\000"
.LASF315:
	.ascii	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2\000"
.LASF5:
	.ascii	"__GNUC_PATCHLEVEL__ 3\000"
.LASF557:
	.ascii	"FMSTR_SCIS1_OFFSET 4\000"
.LASF109:
	.ascii	"__UINT64_C(c) c ## ULL\000"
.LASF786:
	.ascii	"bIsConfigured\000"
.LASF817:
	.ascii	"dwAddr\000"
.LASF298:
	.ascii	"__UHA_IBIT__ 8\000"
.LASF825:
	.ascii	"pcm_bTrgVarSigned\000"
.LASF812:
	.ascii	"FMSTR_StartRec_exit\000"
.LASF824:
	.ascii	"pcm_nTrgVarSize\000"
.LASF513:
	.ascii	"__FREEMASTER_PRIVATE_H \000"
.LASF62:
	.ascii	"__UINT_FAST32_TYPE__ unsigned int\000"
.LASF767:
	.ascii	"unsigned char\000"
.LASF618:
	.ascii	"FMSTR_FCANIFR2_OFFSET 0x2C\000"
.LASF19:
	.ascii	"__SIZEOF_FLOAT__ 4\000"
.LASF230:
	.ascii	"__SACCUM_IBIT__ 8\000"
.LASF130:
	.ascii	"__FLT_MAX_10_EXP__ 38\000"
.LASF202:
	.ascii	"__FRACT_MAX__ 0X7FFFP-15R\000"
.LASF120:
	.ascii	"__GCC_IEC_559 0\000"
.LASF658:
	.ascii	"FMSTR_FCAN_TID(pctx,idr0,idr1,idr2,idr3) FMSTR_MACR"
	.ascii	"OCODE_BEGIN() FMSTR_SETREG32(FMSTR_CAN_BASE, FMSTR_"
	.ascii	"FCANTXFG_OFFSET+FMSTR_FCMBIDR0, ((idr0)<<24) | ((id"
	.ascii	"r1)<<16) | ((idr2)<<8) | (idr3) ); FMSTR_MACROCODE_"
	.ascii	"END()\000"
.LASF89:
	.ascii	"__INT64_MAX__ 9223372036854775807LL\000"
.LASF659:
	.ascii	"FMSTR_FCAN_TPRI(pctx,txPri) \000"
.LASF703:
	.ascii	"FMSTR_CMD_READVAR8 0xD0U\000"
.LASF402:
	.ascii	"FMSTR_USE_WRITEMEMMASK 1\000"
.LASF691:
	.ascii	"FMSTR_CMD_PIPE 0x15U\000"
.LASF842:
	.ascii	"pcm_wStoprecCountDown\000"
.LASF635:
	.ascii	"FMSTR_FCANCTRL_IDE 0x20\000"
.LASF144:
	.ascii	"__DBL_MAX_EXP__ 1024\000"
.LASF114:
	.ascii	"__UINT_FAST8_MAX__ 4294967295U\000"
.LASF485:
	.ascii	"FMSTR_TSA_POINTER \"\"\000"
.LASF277:
	.ascii	"__TQ_FBIT__ 127\000"
.LASF158:
	.ascii	"__LDBL_MAX_EXP__ 1024\000"
.LASF690:
	.ascii	"FMSTR_CMD_SFIOFRAME_0 0x14U\000"
.LASF495:
	.ascii	"FMSTR_TSA_RO_MEM(name,type,addr,size) \000"
.LASF454:
	.ascii	"FMSTR_TSATBL_STRPTR_CAST(x) ((FMSTR_TSATBL_STRPTR)("
	.ascii	"x))\000"
.LASF760:
	.ascii	"FMSTR_PDBDM_IDLE 0x01\000"
.LASF751:
	.ascii	"FMSTR_CANCTL_M2S 0x40\000"
.LASF633:
	.ascii	"FMSTR_FCMBDSR6 0x0D\000"
.LASF792:
	.ascii	"FMSTR_REC_FLAGS\000"
.LASF308:
	.ascii	"__STRICT_ANSI__ 1\000"
.LASF517:
	.ascii	"FMSTR_USE_NOEX_CMDS 0\000"
.LASF603:
	.ascii	"FMSTR_SCI_DTXI() FMSTR_CLRBIT32(FMSTR_SCI_BASE, FMS"
	.ascii	"TR_SCICTRL_OFFSET, FMSTR_SCICTRL_TIE)\000"
.LASF638:
	.ascii	"FMSTR_FCANCTRL_EXT_SRR 0x40\000"
.LASF770:
	.ascii	"FMSTR_ADDR\000"
.LASF21:
	.ascii	"__SIZEOF_LONG_DOUBLE__ 8\000"
.LASF374:
	.ascii	"FMSTR_FLEXCAN_RXMB 1\000"
.LASF324:
	.ascii	"__PRAGMA_REDEFINE_EXTNAME 1\000"
.LASF552:
	.ascii	"FMSTR_TSTBIT32(base,offset,bit) (*(volatile FMSTR_U"
	.ascii	"32*)(((FMSTR_U32)(base))+(offset)) & (bit))\000"
.LASF546:
	.ascii	"FMSTR_CLRBIT16(base,offset,bit) (*(volatile FMSTR_U"
	.ascii	"16*)(((FMSTR_U32)(base))+(offset)) &= (FMSTR_U16)~("
	.ascii	"(FMSTR_U16)(bit)))\000"
.LASF421:
	.ascii	"FMSTR_CAN_BASE_DYNAMIC 0\000"
.LASF773:
	.ascii	"char\000"
.LASF300:
	.ascii	"__USA_IBIT__ 16\000"
.LASF310:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1\000"
.LASF364:
	.ascii	"FMSTR_LONG_INTR 0\000"
.LASF68:
	.ascii	"__GXX_ABI_VERSION 1002\000"
.LASF63:
	.ascii	"__UINT_FAST64_TYPE__ long long unsigned int\000"
.LASF362:
	.ascii	"__FREEMASTER_DEFCFG_H \000"
.LASF853:
	.ascii	"FMSTR_GetRecBuffSize\000"
.LASF133:
	.ascii	"__FLT_MIN__ 1.1754943508222875e-38F\000"
.LASF289:
	.ascii	"__HA_FBIT__ 7\000"
.LASF29:
	.ascii	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF787:
	.ascii	"bIsRunning\000"
.LASF834:
	.ascii	"pcm_wRecTimeDiv\000"
.LASF195:
	.ascii	"__USFRACT_IBIT__ 0\000"
.LASF532:
	.ascii	"FMSTR_GetS16(addr) ( *(FMSTR_S16*)(addr) )\000"
.LASF196:
	.ascii	"__USFRACT_MIN__ 0.0UHR\000"
.LASF579:
	.ascii	"FMSTR_SCISR_RDRF 0x20\000"
.LASF416:
	.ascii	"FMSTR_USE_MBED 0\000"
.LASF644:
	.ascii	"FMSTR_FCAN_TEST_RXFLG() ( ((FMSTR_FLEXCAN_RXMB)&0x2"
	.ascii	"0) ? FMSTR_TSTBIT32(FMSTR_CAN_BASE, FMSTR_FCANIFR2_"
	.ascii	"OFFSET, (1<<((FMSTR_FLEXCAN_RXMB)-32))): FMSTR_TSTB"
	.ascii	"IT32(FMSTR_CAN_BASE, FMSTR_FCANIFR1_OFFSET, (1<<(FM"
	.ascii	"STR_FLEXCAN_RXMB))) )\000"
.LASF489:
	.ascii	"FMSTR_TSA_INFO1(elem,flags) \000"
.LASF151:
	.ascii	"__DBL_HAS_DENORM__ 1\000"
.LASF852:
	.ascii	"FMSTR_AbortRec\000"
.LASF469:
	.ascii	"FMSTR_TSA_UINT64 \"\\xE3\"\000"
.LASF493:
	.ascii	"FMSTR_TSA_RO_VAR(name,type) \000"
.LASF293:
	.ascii	"__DA_FBIT__ 31\000"
.LASF720:
	.ascii	"FMSTR_STS_OK 0x00U\000"
.LASF836:
	.ascii	"pcm_pRecVarAddr\000"
.LASF545:
	.ascii	"FMSTR_SETBIT16(base,offset,bit) (*(volatile FMSTR_U"
	.ascii	"16*)(((FMSTR_U32)(base))+(offset)) |= bit)\000"
.LASF135:
	.ascii	"__FLT_DENORM_MIN__ 1.4012984643248171e-45F\000"
.LASF530:
	.ascii	"FMSTR_GetS8(addr) ( *(FMSTR_S8*)(addr) )\000"
.LASF96:
	.ascii	"__INT_LEAST16_MAX__ 32767\000"
.LASF496:
	.ascii	"FMSTR_TSA_RW_MEM(name,type,addr,size) \000"
.LASF655:
	.ascii	"FMSTR_FCAN_TLEN(pctx,len) FMSTR_SETREG8(FMSTR_CAN_B"
	.ascii	"ASE, FMSTR_FCANTXFG_OFFSET+FMSTR_FCMBCSR+2, (FMSTR_"
	.ascii	"U8)((len & 0x0f) | (FMSTR_GETREG8(FMSTR_CAN_BASE, F"
	.ascii	"MSTR_FCANTXFG_OFFSET+FMSTR_FCMBCSR+2)&(FMSTR_FCANCT"
	.ascii	"RL_IDE | FMSTR_FCANCTRL_EXT_SRR | FMSTR_FCANCTRL_EX"
	.ascii	"T_RTR))))\000"
.LASF438:
	.ascii	"FMSTR_USE_BRIEFINFO 0\000"
.LASF317:
	.ascii	"__GCC_ATOMIC_SHORT_LOCK_FREE 2\000"
.LASF67:
	.ascii	"__has_include_next(STR) __has_include_next__(STR)\000"
.LASF577:
	.ascii	"FMSTR_SCISR_TDRE 0x80\000"
.LASF765:
	.ascii	"FMSTR_REC_FLOAT_TRIG_MASK 0x02\000"
.LASF107:
	.ascii	"__UINT32_C(c) c ## UL\000"
.LASF585:
	.ascii	"FMSTR_SCISR2_BRK13 0x04\000"
.LASF484:
	.ascii	"FMSTR_TSA_SPECIAL \"\\xEC\"\000"
.LASF531:
	.ascii	"FMSTR_GetU8(addr) ( *(FMSTR_U8*)(addr) )\000"
.LASF134:
	.ascii	"__FLT_EPSILON__ 1.1920928955078125e-7F\000"
.LASF510:
	.ascii	"FMSTR_REC_BASE_MICROSEC(x) (((x) & 0x3fffU) | 0x800"
	.ascii	"0U)\000"
.LASF822:
	.ascii	"FMSTR_Recorder\000"
.LASF411:
	.ascii	"FMSTR_USE_FLEXCAN32 0\000"
.LASF417:
	.ascii	"FMSTR_USE_SCI 0\000"
.LASF750:
	.ascii	"FMSTR_CANCTL_TGL 0x80\000"
.LASF851:
	.ascii	"C:\\\\Users\\\\kamil\\\\OneDrive\\\\Documents\\\\Gi"
	.ascii	"tHub\\\\Internship\\\\TestBench\\\\adc_hwtrigger_s3"
	.ascii	"2k144\\\\Debug_RAM\000"
.LASF486:
	.ascii	"FMSTR_TSA_USERTYPE(type) #type\000"
.LASF757:
	.ascii	"FMSTR_PDBDM_BUFFBORDER_CODE1 0x07e0\000"
.LASF571:
	.ascii	"FMSTR_SCIC2_RIE 0x20\000"
.LASF583:
	.ascii	"FMSTR_SCISR_FE 0x02\000"
.LASF468:
	.ascii	"FMSTR_TSA_UINT32 \"\\xE2\"\000"
.LASF692:
	.ascii	"FMSTR_CMD_GETINFO 0xc0U\000"
.LASF704:
	.ascii	"FMSTR_CMD_READVAR16 0xD1U\000"
.LASF821:
	.ascii	"FMSTR_SetUpRecBuff\000"
.LASF321:
	.ascii	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1\000"
.LASF249:
	.ascii	"__LACCUM_FBIT__ 31\000"
.LASF754:
	.ascii	"FMSTR_CANCTL_SPC 0x08\000"
.LASF771:
	.ascii	"FMSTR_BOOL\000"
.LASF488:
	.ascii	"FMSTR_TSA_TABLE_BEGIN(id) \000"
.LASF473:
	.ascii	"FMSTR_TSA_SINT64 \"\\xF3\"\000"
.LASF166:
	.ascii	"__LDBL_HAS_INFINITY__ 1\000"
.LASF451:
	.ascii	"FMSTR_TSA_INFO_VAR_FLAG 0x0001U\000"
.LASF295:
	.ascii	"__TA_FBIT__ 63\000"
.LASF481:
	.ascii	"FMSTR_TSA_FRAC64 \"\\xF7\"\000"
.LASF830:
	.ascii	"pcm_pOwnRecBuffer\000"
.LASF657:
	.ascii	"FMSTR_FCAN_TCFG(pctx) FMSTR_MACROCODE_BEGIN() (pctx"
	.ascii	")->nDataIx = 0; FMSTR_MACROCODE_END()\000"
.LASF435:
	.ascii	"FMSTR_USE_PIPE_PRINTF 1\000"
.LASF355:
	.ascii	"__ARM_ARCH_EXT_IDIV__ 1\000"
.LASF523:
	.ascii	"FMSTR_IDT_STRING \"S32xx FreeMASTER\"\000"
.LASF752:
	.ascii	"FMSTR_CANCTL_FST 0x20\000"
.LASF497:
	.ascii	"FMSTR_TSA_DIRECTORY(dirname) \000"
.LASF511:
	.ascii	"FMSTR_REC_BASE_NANOSEC(x) (((x) & 0x3fffU) | 0xc000"
	.ascii	"U)\000"
.LASF85:
	.ascii	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)\000"
.LASF246:
	.ascii	"__UACCUM_MIN__ 0.0UK\000"
.LASF681:
	.ascii	"FMSTR_CMD_WRITEMEMMASK_EX 0x06U\000"
.LASF671:
	.ascii	"FMSTR_MACROCODE_END() }while(0)\000"
.LASF805:
	.ascii	"blen\000"
.LASF139:
	.ascii	"__FP_FAST_FMAF 1\000"
.LASF462:
	.ascii	"FMSTR_TSA_RW_VAR_CFG(name,type) FMSTR_TSATBL_STRPTR"
	.ascii	"_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMS"
	.ascii	"TR_TSATBL_VOIDPTR_ENTRY(&(name)), FMSTR_TSATBL_VOID"
	.ascii	"PTR_ENTRY(FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_RW_V"
	.ascii	"AR)),\000"
.LASF843:
	.ascii	"pcm_wRecFlags\000"
.LASF736:
	.ascii	"FMSTR_STC_CANTGLERR 0x8EU\000"
.LASF654:
	.ascii	"FMSTR_FCAN_RCFG() FMSTR_SETREG8(FMSTR_CAN_BASE, FMS"
	.ascii	"TR_FCANRXFG_OFFSET + FMSTR_FCMBCSR + 3, FMSTR_FCANM"
	.ascii	"B_CRXEMPTY)\000"
.LASF800:
	.ascii	"pBuffer\000"
.LASF502:
	.ascii	"FMSTR_TSA_TABLE_LIST_BEGIN() \000"
.LASF591:
	.ascii	"FMSTR_SCIDATA_OFFSET 0x1C\000"
.LASF472:
	.ascii	"FMSTR_TSA_SINT32 \"\\xF2\"\000"
.LASF388:
	.ascii	"FMSTR_USE_RECORDER FMSTR_DEMO_ENOUGH_RAM\000"
.LASF181:
	.ascii	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD\000"
.LASF198:
	.ascii	"__USFRACT_EPSILON__ 0x1P-8UHR\000"
.LASF480:
	.ascii	"FMSTR_TSA_FRAC32 \"\\xF6\"\000"
.LASF274:
	.ascii	"__SQ_IBIT__ 0\000"
.LASF113:
	.ascii	"__INT_FAST64_MAX__ 9223372036854775807LL\000"
.LASF194:
	.ascii	"__USFRACT_FBIT__ 8\000"
.LASF262:
	.ascii	"__LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK\000"
.LASF389:
	.ascii	"FMSTR_MAX_REC_VARS 8\000"
.LASF574:
	.ascii	"FMSTR_SCIC2_RE 0x04\000"
.LASF306:
	.ascii	"__USER_LABEL_PREFIX__ \000"
.LASF679:
	.ascii	"FMSTR_CMD_READMEM_EX 0x04U\000"
.LASF241:
	.ascii	"__ACCUM_MIN__ (-0X1P15K-0X1P15K)\000"
.LASF833:
	.ascii	"pcm_nRecTriggerMode\000"
.LASF463:
	.ascii	"FMSTR_TSA_RO_MEM_CFG(name,type,addr,size) FMSTR_TSA"
	.ascii	"TBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY("
	.ascii	"type), FMSTR_TSATBL_VOIDPTR_ENTRY(addr), FMSTR_TSAT"
	.ascii	"BL_VOIDPTR_ENTRY(FMSTR_TSA_INFO2(size, FMSTR_TSA_IN"
	.ascii	"FO_RO_VAR)),\000"
.LASF322:
	.ascii	"__GCC_ATOMIC_POINTER_LOCK_FREE 2\000"
.LASF329:
	.ascii	"__ARM_FEATURE_QBIT 1\000"
.LASF334:
	.ascii	"__ARM_FEATURE_CLZ 1\000"
.LASF9:
	.ascii	"__ATOMIC_ACQUIRE 2\000"
.LASF544:
	.ascii	"FMSTR_GETREG16(base,offset) (*(volatile FMSTR_U16*)"
	.ascii	"(((FMSTR_U32)(base))+(offset)))\000"
.LASF533:
	.ascii	"FMSTR_GetU16(addr) ( *(FMSTR_U16*)(addr) )\000"
.LASF566:
	.ascii	"FMSTR_SCIC1_ILT 0x04\000"
.LASF353:
	.ascii	"__ARM_PCS_VFP 1\000"
.LASF47:
	.ascii	"__UINT64_TYPE__ long long unsigned int\000"
.LASF337:
	.ascii	"__ARM_SIZEOF_WCHAR_T 4\000"
.LASF66:
	.ascii	"__has_include(STR) __has_include__(STR)\000"
.LASF440:
	.ascii	"FMSTR_COMM_BUFFER_SIZE 11\000"
.LASF662:
	.ascii	"FMSTR_FCAN_TEST_RIDR(pctx,idr0,idr1,idr2,idr3) ( (i"
	.ascii	"dr0 & FMSTR_FCANID0_EXT_FLG) ? ( ((((idr0)<<24) | ("
	.ascii	"(idr1)<<16) | ((idr2)<<8) | (idr3))&0x1f000000)==(("
	.ascii	"FMSTR_GETREG32(FMSTR_CAN_BASE, FMSTR_FCANRXFG_OFFSE"
	.ascii	"T+FMSTR_FCMBIDR0))&0x1f000000) ) : ( (((idr0)<<8) |"
	.ascii	" (idr1))==((FMSTR_GETREG16(FMSTR_CAN_BASE, FMSTR_FC"
	.ascii	"ANRXFG_OFFSET+FMSTR_FCMBIDR0+2))&0x1ffc) ) )\000"
.LASF470:
	.ascii	"FMSTR_TSA_SINT8 \"\\xF0\"\000"
.LASF149:
	.ascii	"__DBL_EPSILON__ ((double)2.2204460492503131e-16L)\000"
.LASF798:
	.ascii	"FMSTR_Compare32S\000"
.LASF823:
	.ascii	"pcm_nTrgVarAddr\000"
.LASF242:
	.ascii	"__ACCUM_MAX__ 0X7FFFFFFFP-15K\000"
.LASF157:
	.ascii	"__LDBL_MIN_10_EXP__ (-307)\000"
.LASF80:
	.ascii	"__INTMAX_MAX__ 9223372036854775807LL\000"
.LASF323:
	.ascii	"__GCC_HAVE_DWARF2_CFI_ASM 1\000"
.LASF431:
	.ascii	"FMSTR_CFG_REC_LARGE_MODE 0\000"
.LASF191:
	.ascii	"__SFRACT_MIN__ (-0.5HR-0.5HR)\000"
.LASF769:
	.ascii	"long unsigned int\000"
.LASF292:
	.ascii	"__SA_IBIT__ 16\000"
.LASF3:
	.ascii	"__GNUC__ 4\000"
.LASF835:
	.ascii	"pcm_nRecVarCount\000"
.LASF45:
	.ascii	"__UINT16_TYPE__ short unsigned int\000"
.LASF461:
	.ascii	"FMSTR_TSA_RO_VAR_CFG(name,type) FMSTR_TSATBL_STRPTR"
	.ascii	"_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY(type), FMS"
	.ascii	"TR_TSATBL_VOIDPTR_ENTRY(&(name)), FMSTR_TSATBL_VOID"
	.ascii	"PTR_ENTRY(FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_RO_V"
	.ascii	"AR)),\000"
.LASF712:
	.ascii	"FMSTR_CMD_WRITEVAR16 0xe4U\000"
.LASF392:
	.ascii	"FMSTR_REC_TIMEBASE FMSTR_REC_BASE_MILLISEC(0)\000"
.LASF743:
	.ascii	"FMSTR_FASTCMD_DATALEN_SHIFT 3\000"
.LASF170:
	.ascii	"__DEC32_MAX_EXP__ 97\000"
.LASF684:
	.ascii	"FMSTR_CMD_SETUPSCOPE_EX 0x0aU\000"
.LASF723:
	.ascii	"FMSTR_STC_INVCMD 0x81U\000"
.LASF60:
	.ascii	"__UINT_FAST8_TYPE__ unsigned int\000"
.LASF260:
	.ascii	"__LLACCUM_IBIT__ 32\000"
.LASF203:
	.ascii	"__FRACT_EPSILON__ 0x1P-15R\000"
.LASF783:
	.ascii	"FMSTR_FLAGS\000"
.LASF666:
	.ascii	"FMSTR_PLATFORM S32xx\000"
.LASF624:
	.ascii	"FMSTR_FCMBIDR1 0x05\000"
.LASF554:
	.ascii	"FMSTR_SCIBDL_OFFSET 1\000"
.LASF90:
	.ascii	"__UINT8_MAX__ 255\000"
.LASF400:
	.ascii	"FMSTR_USE_READMEM 1\000"
.LASF705:
	.ascii	"FMSTR_CMD_READVAR32 0xD2U\000"
.LASF539:
	.ascii	"FMSTR_SETREG8(base,offset,value) (*(volatile FMSTR_"
	.ascii	"U8*)(((FMSTR_U32)(base))+(offset)) = value)\000"
.LASF542:
	.ascii	"FMSTR_CLRBIT8(base,offset,bit) (*(volatile FMSTR_U8"
	.ascii	"*)(((FMSTR_U32)(base))+(offset)) &= (FMSTR_U16)~((F"
	.ascii	"MSTR_U16)(bit)))\000"
.LASF471:
	.ascii	"FMSTR_TSA_SINT16 \"\\xF1\"\000"
.LASF55:
	.ascii	"__UINT_LEAST64_TYPE__ long long unsigned int\000"
.LASF187:
	.ascii	"__DEC128_EPSILON__ 1E-33DL\000"
.LASF163:
	.ascii	"__LDBL_EPSILON__ 2.2204460492503131e-16L\000"
.LASF479:
	.ascii	"FMSTR_TSA_FRAC16 \"\\xF5\"\000"
.LASF76:
	.ascii	"__WINT_MAX__ 4294967295U\000"
.LASF314:
	.ascii	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2\000"
.LASF804:
	.ascii	"nRecVarsetSize\000"
.LASF10:
	.ascii	"__ATOMIC_RELEASE 3\000"
.LASF428:
	.ascii	"FMSTR_REC_STATIC_POSTTRIG 0\000"
.LASF125:
	.ascii	"__FLT_MANT_DIG__ 24\000"
.LASF286:
	.ascii	"__UDQ_IBIT__ 0\000"
.LASF413:
	.ascii	"FMSTR_USE_LINTL 0\000"
.LASF819:
	.ascii	"bRet\000"
.LASF441:
	.ascii	"FMSTR_COMM_BUFFER_SIZE (35+1)\000"
.LASF529:
	.ascii	"FMSTR_ConstToBuffer16 FMSTR_ValueToBuffer16\000"
.LASF251:
	.ascii	"__LACCUM_MIN__ (-0X1P31LK-0X1P31LK)\000"
.LASF164:
	.ascii	"__LDBL_DENORM_MIN__ 4.9406564584124654e-324L\000"
.LASF409:
	.ascii	"FMSTR_USE_MSCAN 0\000"
.LASF807:
	.ascii	"FMSTR_InitRec\000"
.LASF225:
	.ascii	"__ULLFRACT_IBIT__ 0\000"
.LASF677:
	.ascii	"FMSTR_CMD_WRITEMEM 0x02U\000"
.LASF401:
	.ascii	"FMSTR_USE_WRITEMEM 1\000"
.LASF450:
	.ascii	"FMSTR_TSA_INFO_RW_VAR 0x0003U\000"
.LASF453:
	.ascii	"FMSTR_TSATBL_STRPTR const char*\000"
.LASF700:
	.ascii	"FMSTR_CMD_GETRECBUFF_EX 0xc9U\000"
.LASF722:
	.ascii	"FMSTR_STS_RECDONE 0x02U\000"
.LASF832:
	.ascii	"pcm_wRecPostTrigger\000"
.LASF590:
	.ascii	"FMSTR_SCICTRL_OFFSET 0x18\000"
.LASF518:
	.ascii	"FMSTR_PROT_VER 3\000"
.LASF132:
	.ascii	"__FLT_MAX__ 3.4028234663852886e+38F\000"
.LASF763:
	.ascii	"FMSTR_PDBDM_FRAME_TO_SEND 0x08\000"
.LASF244:
	.ascii	"__UACCUM_FBIT__ 16\000"
.LASF208:
	.ascii	"__UFRACT_EPSILON__ 0x1P-16UR\000"
.LASF445:
	.ascii	"FMSTR_TSA_VERSION 2U\000"
.LASF92:
	.ascii	"__UINT32_MAX__ 4294967295UL\000"
.LASF280:
	.ascii	"__UQQ_IBIT__ 0\000"
.LASF672:
	.ascii	"FMSTR_UNUSED(x) (void)(x)\000"
.LASF632:
	.ascii	"FMSTR_FCMBDSR5 0x0E\000"
.LASF319:
	.ascii	"__GCC_ATOMIC_LONG_LOCK_FREE 2\000"
.LASF256:
	.ascii	"__ULACCUM_MIN__ 0.0ULK\000"
.LASF161:
	.ascii	"__LDBL_MAX__ 1.7976931348623157e+308L\000"
.LASF340:
	.ascii	"__ARM_ARCH 7\000"
.LASF748:
	.ascii	"FMSTR_TSA_INFO_32BIT 0x0100U\000"
.LASF366:
	.ascii	"FMSTR_POLL_DRIVEN 0\000"
.LASF13:
	.ascii	"__OPTIMIZE__ 1\000"
.LASF124:
	.ascii	"__FLT_RADIX__ 2\000"
.LASF524:
	.ascii	"FMSTR_TSA_FLAGS 0\000"
.LASF686:
	.ascii	"FMSTR_CMD_SENDAPPCMD 0x10U\000"
.LASF443:
	.ascii	"FMSTR_COMM_BUFFER_SIZE (((FMSTR_MAX_REC_VARS)*5)+18"
	.ascii	"+2)\000"
.LASF464:
	.ascii	"FMSTR_TSA_RW_MEM_CFG(name,type,addr,size) FMSTR_TSA"
	.ascii	"TBL_STRPTR_ENTRY(#name), FMSTR_TSATBL_STRPTR_ENTRY("
	.ascii	"type), FMSTR_TSATBL_VOIDPTR_ENTRY(addr), FMSTR_TSAT"
	.ascii	"BL_VOIDPTR_ENTRY(FMSTR_TSA_INFO2(size, FMSTR_TSA_IN"
	.ascii	"FO_RW_VAR)),\000"
.LASF674:
	.ascii	"FMSTR_USE_SERIAL 1\000"
.LASF360:
	.ascii	"__FREEMASTER_H \000"
.LASF380:
	.ascii	"FMSTR_DEMO_SUPPORT_I64 1\000"
.LASF398:
	.ascii	"FMSTR_USE_PIPES 1\000"
.LASF715:
	.ascii	"FMSTR_CMD_WRITEVAR32 0xf0U\000"
.LASF58:
	.ascii	"__INT_FAST32_TYPE__ int\000"
.LASF709:
	.ascii	"FMSTR_CMD_READVAR16_EX 0xe1U\000"
.LASF290:
	.ascii	"__HA_IBIT__ 8\000"
.LASF475:
	.ascii	"FMSTR_TSA_UFRAC16 \"\\xE5\"\000"
.LASF320:
	.ascii	"__GCC_ATOMIC_LLONG_LOCK_FREE 1\000"
.LASF81:
	.ascii	"__INTMAX_C(c) c ## LL\000"
.LASF43:
	.ascii	"__INT64_TYPE__ long long int\000"
.LASF209:
	.ascii	"__LFRACT_FBIT__ 31\000"
.LASF23:
	.ascii	"__CHAR_BIT__ 8\000"
.LASF325:
	.ascii	"__SIZEOF_WCHAR_T__ 4\000"
.LASF755:
	.ascii	"FMSTR_CANCTL_LEN_MASK 0x07\000"
.LASF794:
	.ascii	"FMSTR_Compare8S\000"
.LASF795:
	.ascii	"FMSTR_Compare8U\000"
.LASF395:
	.ascii	"FMSTR_USE_TSA_INROM 1\000"
.LASF719:
	.ascii	"FMSTR_STSF_EVENT 0x20U\000"
.LASF381:
	.ascii	"FMSTR_DEMO_SUPPORT_FLT 1\000"
.LASF749:
	.ascii	"FMSTR_TSA_INFO_HV2BA 0x0200U\000"
.LASF653:
	.ascii	"FMSTR_FCAN_TINIT(idr0,idr1,idr2,idr3) FMSTR_MACROCO"
	.ascii	"DE_BEGIN() (((idr0)&FMSTR_FCANID0_EXT_FLG) ? (FMSTR"
	.ascii	"_SETREG16(FMSTR_CAN_BASE, FMSTR_FCANTXFG_OFFSET + F"
	.ascii	"MSTR_FCMBCSR + 2, (FMSTR_FCANMB_CTXREADY<<8 | FMSTR"
	.ascii	"_FCANCTRL_IDE))) : (FMSTR_SETREG16(FMSTR_CAN_BASE, "
	.ascii	"FMSTR_FCANTXFG_OFFSET + FMSTR_FCMBCSR + 2, (FMSTR_F"
	.ascii	"CANMB_CTXREADY<<8 )))); FMSTR_MACROCODE_END()\000"
.LASF702:
	.ascii	"FMSTR_CMD_SFIOGETRESP_1 0xcbU\000"
.LASF555:
	.ascii	"FMSTR_SCIC1_OFFSET 2\000"
.LASF408:
	.ascii	"FMSTR_USE_JTAG 0\000"
.LASF28:
	.ascii	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__\000"
.LASF738:
	.ascii	"FMSTR_STC_FLOATDISABLED 0x90U\000"
.LASF467:
	.ascii	"FMSTR_TSA_UINT16 \"\\xE1\"\000"
.LASF268:
	.ascii	"__ULLACCUM_EPSILON__ 0x1P-32ULLK\000"
.LASF429:
	.ascii	"FMSTR_REC_STATIC_DIVISOR 0\000"
.LASF588:
	.ascii	"FMSTR_SCIBAUD_OFFSET 0x10\000"
.LASF363:
	.ascii	"__FREEMASTER_CFG_H \000"
.LASF204:
	.ascii	"__UFRACT_FBIT__ 16\000"
.LASF285:
	.ascii	"__UDQ_FBIT__ 64\000"
.LASF701:
	.ascii	"FMSTR_CMD_SFIOGETRESP_0 0xcaU\000"
.LASF159:
	.ascii	"__LDBL_MAX_10_EXP__ 308\000"
.LASF556:
	.ascii	"FMSTR_SCIC2_OFFSET 3\000"
.LASF710:
	.ascii	"FMSTR_CMD_READVAR32_EX 0xe2U\000"
.LASF150:
	.ascii	"__DBL_DENORM_MIN__ ((double)4.9406564584124654e-324"
	.ascii	"L)\000"
.LASF8:
	.ascii	"__ATOMIC_SEQ_CST 5\000"
.LASF536:
	.ascii	"FMSTR_PTR2ADDR(tmpAddr,ptr) ( tmpAddr = (FMSTR_ADDR"
	.ascii	") (FMSTR_U8*) ptr )\000"
.LASF820:
	.ascii	"FMSTR_GetRecBuff\000"
.LASF127:
	.ascii	"__FLT_MIN_EXP__ (-125)\000"
.LASF123:
	.ascii	"__DEC_EVAL_METHOD__ 2\000"
.LASF559:
	.ascii	"FMSTR_SCIC3_OFFSET 6\000"
.LASF458:
	.ascii	"FMSTR_TSATBL_VOIDPTR_ENTRY(x) {FMSTR_TSATBL_VOIDPTR"
	.ascii	"_CAST(x)}\000"
.LASF628:
	.ascii	"FMSTR_FCMBDSR1 0x0A\000"
.LASF436:
	.ascii	"FMSTR_USE_PIPE_PRINTF_VARG FMSTR_USE_PIPE_PRINTF\000"
.LASF235:
	.ascii	"__USACCUM_IBIT__ 8\000"
.LASF369:
	.ascii	"FMSTR_DISABLE 0\000"
.LASF718:
	.ascii	"FMSTR_STSF_VARLEN 0x40U\000"
.LASF352:
	.ascii	"__ARM_ARCH_7EM__ 1\000"
.LASF592:
	.ascii	"FMSTR_SCICTRL_TE 0x080000\000"
.LASF119:
	.ascii	"__UINTPTR_MAX__ 4294967295U\000"
.LASF301:
	.ascii	"__UDA_FBIT__ 32\000"
.LASF576:
	.ascii	"FMSTR_SCIC2_SBK 0x01\000"
.LASF126:
	.ascii	"__FLT_DIG__ 6\000"
.LASF248:
	.ascii	"__UACCUM_EPSILON__ 0x1P-16UK\000"
.LASF570:
	.ascii	"FMSTR_SCIC2_TCIE 0x40\000"
.LASF668:
	.ascii	"FMSTR_FALSE (0U)\000"
.LASF432:
	.ascii	"FMSTR_DEBUG_TX 0\000"
.LASF648:
	.ascii	"FMSTR_FCAN_MAKEIDR0(id) ((FMSTR_U8)( ((id)&FMSTR_CA"
	.ascii	"N_EXTID) ? ((((id)>>24)&0x1f) | FMSTR_FCANID0_EXT_F"
	.ascii	"LG) : (((id)>>6)&0x1f) ))\000"
.LASF122:
	.ascii	"__FLT_EVAL_METHOD__ 0\000"
.LASF791:
	.ascii	"unsigned int\000"
.LASF507:
	.ascii	"MFSTR_APPCMDRESULT_LASTVALID 0xf7U\000"
.LASF118:
	.ascii	"__INTPTR_MAX__ 2147483647\000"
.LASF854:
	.ascii	"FMSTR_Recorder2\000"
.LASF828:
	.ascii	"pcm_pCompareFunc\000"
.LASF789:
	.ascii	"bInvirginCycle\000"
.LASF279:
	.ascii	"__UQQ_FBIT__ 8\000"
.LASF534:
	.ascii	"FMSTR_GetS32(addr) ( *(FMSTR_S32*)(addr) )\000"
.LASF176:
	.ascii	"__DEC64_MIN_EXP__ (-382)\000"
.LASF247:
	.ascii	"__UACCUM_MAX__ 0XFFFFFFFFP-16UK\000"
.LASF779:
	.ascii	"FMSTR_S16\000"
.LASF212:
	.ascii	"__LFRACT_MAX__ 0X7FFFFFFFP-31LR\000"
.LASF327:
	.ascii	"__SIZEOF_PTRDIFF_T__ 4\000"
.LASF0:
	.ascii	"__STDC__ 1\000"
.LASF423:
	.ascii	"FMSTR_REC_FARBUFF 0\000"
.LASF509:
	.ascii	"FMSTR_REC_BASE_MILLISEC(x) (((x) & 0x3fffU) | 0x400"
	.ascii	"0U)\000"
.LASF491:
	.ascii	"FMSTR_TSA_STRUCT(name) \000"
.LASF361:
	.ascii	"FMSTR_PLATFORM_S32xx 1\000"
.LASF761:
	.ascii	"FMSTR_PDBDM_RECEIVED_FRAME 0x02\000"
.LASF739:
	.ascii	"FMSTR_STC_DEBUGTX_TEST 0xA9U\000"
.LASF39:
	.ascii	"__SIG_ATOMIC_TYPE__ int\000"
.LASF264:
	.ascii	"__ULLACCUM_FBIT__ 32\000"
.LASF182:
	.ascii	"__DEC128_MANT_DIG__ 34\000"
.LASF494:
	.ascii	"FMSTR_TSA_RW_VAR(name,type) \000"
.LASF727:
	.ascii	"FMSTR_STC_INVBUFF 0x85U\000"
.LASF815:
	.ascii	"FMSTR_GetRecStatus\000"
.LASF737:
	.ascii	"FMSTR_STC_CANMSGERR 0x8FU\000"
.LASF299:
	.ascii	"__USA_FBIT__ 16\000"
.LASF521:
	.ascii	"FMSTR_GLOB_VERSION_MAJOR 2\000"
.LASF827:
	.ascii	"pcm_nRecBuffAddr\000"
.LASF728:
	.ascii	"FMSTR_STC_INVSIZE 0x86U\000"
.LASF138:
	.ascii	"__FLT_HAS_QUIET_NAN__ 1\000"
.LASF313:
	.ascii	"__GCC_ATOMIC_CHAR_LOCK_FREE 2\000"
.LASF145:
	.ascii	"__DBL_MAX_10_EXP__ 308\000"
.LASF213:
	.ascii	"__LFRACT_EPSILON__ 0x1P-31LR\000"
.LASF678:
	.ascii	"FMSTR_CMD_WRITEMEMMASK 0x03U\000"
.LASF617:
	.ascii	"FMSTR_FCANIER1_OFFSET 0x28\000"
.LASF336:
	.ascii	"__ARM_SIZEOF_MINIMAL_ENUM 1\000"
.LASF613:
	.ascii	"FMSTR_FCANMB_CTXTRANS_ONCE 0x0C\000"
.LASF94:
	.ascii	"__INT_LEAST8_MAX__ 127\000"
.LASF339:
	.ascii	"__arm__ 1\000"
.LASF40:
	.ascii	"__INT8_TYPE__ signed char\000"
.LASF483:
	.ascii	"FMSTR_TSA_DOUBLE \"\\xFB\"\000"
.LASF649:
	.ascii	"FMSTR_FCAN_MAKEIDR1(id) ((FMSTR_U8)( ((id)&FMSTR_CA"
	.ascii	"N_EXTID) ? ((id)>>16) : ((id)<<2) ))\000"
.LASF682:
	.ascii	"FMSTR_CMD_SETUPSCOPE 0x08U\000"
.LASF637:
	.ascii	"FMSTR_FCANCTRL_EXT_RTR 0x10\000"
.LASF622:
	.ascii	"FMSTR_FCMBCSR 0x00\000"
.LASF168:
	.ascii	"__DEC32_MANT_DIG__ 7\000"
.LASF24:
	.ascii	"__BIGGEST_ALIGNMENT__ 8\000"
.LASF565:
	.ascii	"FMSTR_SCIC1_WAKE 0x08\000"
.LASF688:
	.ascii	"FMSTR_CMD_GETTSAINFO_EX 0x12U\000"
.LASF296:
	.ascii	"__TA_IBIT__ 64\000"
.LASF793:
	.ascii	"FMSTR_PCOMPAREFUNC\000"
.LASF115:
	.ascii	"__UINT_FAST16_MAX__ 4294967295U\000"
.LASF838:
	.ascii	"pcm_wRecBuffStartIx\000"
.LASF650:
	.ascii	"FMSTR_FCAN_MAKEIDR2(id) ((FMSTR_U8)( ((id)&FMSTR_CA"
	.ascii	"N_EXTID) ? ((id)>>8) : 0 ))\000"
.LASF394:
	.ascii	"FMSTR_USE_TSA 0\000"
.LASF699:
	.ascii	"FMSTR_CMD_GETINFOBRIEF 0xc8U\000"
.LASF344:
	.ascii	"__ARM_ARCH_ISA_THUMB 2\000"
.LASF108:
	.ascii	"__UINT_LEAST64_MAX__ 18446744073709551615ULL\000"
.LASF465:
	.ascii	"FMSTR_TSA_RO_ENTRY(name_string,type_string,addr,siz"
	.ascii	"e) FMSTR_TSATBL_STRPTR_ENTRY(name_string), FMSTR_TS"
	.ascii	"ATBL_STRPTR_ENTRY(type_string), FMSTR_TSATBL_VOIDPT"
	.ascii	"R_ENTRY(addr), FMSTR_TSATBL_VOIDPTR_ENTRY(FMSTR_TSA"
	.ascii	"_INFO2(size, FMSTR_TSA_INFO_RW_VAR)),\000"
.LASF110:
	.ascii	"__INT_FAST8_MAX__ 2147483647\000"
.LASF781:
	.ascii	"FMSTR_S32\000"
.LASF205:
	.ascii	"__UFRACT_IBIT__ 0\000"
.LASF332:
	.ascii	"__ARM_32BIT_STATE 1\000"
.LASF95:
	.ascii	"__INT8_C(c) c\000"
.LASF210:
	.ascii	"__LFRACT_IBIT__ 0\000"
.LASF420:
	.ascii	"FMSTR_SCI_STATUS_W1C 1\000"
.LASF768:
	.ascii	"short unsigned int\000"
.LASF376:
	.ascii	"FMSTR_COMM_RQUEUE_SIZE 32\000"
.LASF142:
	.ascii	"__DBL_MIN_EXP__ (-1021)\000"
.LASF512:
	.ascii	"NULL ((void *) 0)\000"
.LASF520:
	.ascii	"FMSTR_CFG_BUS_WIDTH 1\000"
.LASF88:
	.ascii	"__INT32_MAX__ 2147483647L\000"
.LASF802:
	.ascii	"pMessageIO\000"
.LASF847:
	.ascii	"FMSTR_AddressToBuffer\000"
.LASF683:
	.ascii	"FMSTR_CMD_SETUPREC 0x09U\000"
.LASF178:
	.ascii	"__DEC64_MIN__ 1E-383DD\000"
.LASF818:
	.ascii	"nSize\000"
.LASF582:
	.ascii	"FMSTR_SCISR_NF 0x04\000"
.LASF696:
	.ascii	"FMSTR_CMD_GETRECBUFF 0xc4U\000"
.LASF693:
	.ascii	"FMSTR_CMD_STARTREC 0xc1U\000"
.LASF165:
	.ascii	"__LDBL_HAS_DENORM__ 1\000"
.LASF636:
	.ascii	"FMSTR_FCANCTRL_STD_RTR 0x10\000"
.LASF311:
	.ascii	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1\000"
.LASF478:
	.ascii	"FMSTR_TSA_FRAC_Q(m,n) \"\\xF4:\" #m \".\" #n\000"
.LASF598:
	.ascii	"FMSTR_SCI_TD() FMSTR_CLRBIT32(FMSTR_SCI_BASE, FMSTR"
	.ascii	"_SCICTRL_OFFSET, FMSTR_SCICTRL_TE)\000"
.LASF50:
	.ascii	"__INT_LEAST32_TYPE__ long int\000"
.LASF759:
	.ascii	"FMSTR_PDBDM_NOT_INIT 0x00\000"
.LASF508:
	.ascii	"FMSTR_REC_BASE_SECONDS(x) ((x) & 0x3fffU)\000"
.LASF596:
	.ascii	"FMSTR_SCICTRL_RIE 0x200000\000"
.LASF740:
	.ascii	"FMSTR_SOB 0x2bU\000"
.LASF813:
	.ascii	"FMSTR_StopRec\000"
.LASF601:
	.ascii	"FMSTR_SCI_TE_RE() FMSTR_SETBIT32(FMSTR_SCI_BASE, FM"
	.ascii	"STR_SCICTRL_OFFSET, FMSTR_SCICTRL_RE | FMSTR_SCICTR"
	.ascii	"L_TE)\000"
.LASF200:
	.ascii	"__FRACT_IBIT__ 0\000"
.LASF745:
	.ascii	"FMSTR_CFGFLAG_BIGENDIAN 0x01U\000"
.LASF25:
	.ascii	"__ORDER_LITTLE_ENDIAN__ 1234\000"
.LASF175:
	.ascii	"__DEC64_MANT_DIG__ 16\000"
.LASF128:
	.ascii	"__FLT_MIN_10_EXP__ (-37)\000"
.LASF255:
	.ascii	"__ULACCUM_IBIT__ 32\000"
.LASF442:
	.ascii	"FMSTR_COMM_BUFFER_SIZE (((FMSTR_MAX_SCOPE_VARS)*5)+"
	.ascii	"1+2)\000"
.LASF455:
	.ascii	"FMSTR_TSATBL_STRPTR_ENTRY(x) {FMSTR_TSATBL_STRPTR_C"
	.ascii	"AST(x)}\000"
.LASF32:
	.ascii	"__PTRDIFF_TYPE__ int\000"
.LASF341:
	.ascii	"__APCS_32__ 1\000"
.LASF848:
	.ascii	"FMSTR_ValueToBuffer16\000"
.LASF569:
	.ascii	"FMSTR_SCIC2_TIE 0x80\000"
.LASF498:
	.ascii	"FMSTR_TSA_MEMFILE(filename,filemem,filesize) \000"
.LASF275:
	.ascii	"__DQ_FBIT__ 63\000"
.LASF651:
	.ascii	"FMSTR_FCAN_MAKEIDR3(id) ((FMSTR_U8)( ((id)&FMSTR_CA"
	.ascii	"N_EXTID) ? (id) : 0 ))\000"
.LASF282:
	.ascii	"__UHQ_IBIT__ 0\000"
.LASF647:
	.ascii	"FMSTR_FCAN_GET_MBSTATUS() (FMSTR_GETREG8(FMSTR_CAN_"
	.ascii	"BASE, FMSTR_FCANTXFG_OFFSET + FMSTR_FCMBCSR + 3)&FM"
	.ascii	"STR_FCANMB_CODE_MASK)\000"
.LASF725:
	.ascii	"FMSTR_STC_CMDTOOLONG 0x83U\000"
.LASF447:
	.ascii	"FMSTR_TSA_INFO_STRUCT 0x0000U\000"
.LASF385:
	.ascii	"FMSTR_MAX_APPCMD_CALLS 4\000"
.LASF57:
	.ascii	"__INT_FAST16_TYPE__ int\000"
.LASF359:
	.ascii	"CPU_S32K144HFT0VLLT 1\000"
.LASF407:
	.ascii	"FMSTR_USE_ESCI 0\000"
.LASF231:
	.ascii	"__SACCUM_MIN__ (-0X1P7HK-0X1P7HK)\000"
.LASF217:
	.ascii	"__ULFRACT_MAX__ 0XFFFFFFFFP-32ULR\000"
.LASF53:
	.ascii	"__UINT_LEAST16_TYPE__ short unsigned int\000"
.LASF810:
	.ascii	"FMSTR_StartRec\000"
.LASF37:
	.ascii	"__CHAR16_TYPE__ short unsigned int\000"
.LASF785:
	.ascii	"FMSTR_BPTR\000"
.LASF425:
	.ascii	"FMSTR_LIGHT_VERSION 0\000"
.LASF104:
	.ascii	"__UINT_LEAST16_MAX__ 65535\000"
.LASF499:
	.ascii	"FMSTR_TSA_PROJECT(projectname,project_uri) \000"
.LASF287:
	.ascii	"__UTQ_FBIT__ 128\000"
.LASF14:
	.ascii	"__FINITE_MATH_ONLY__ 0\000"
.LASF550:
	.ascii	"FMSTR_SETBIT32(base,offset,bit) ((*(volatile FMSTR_"
	.ascii	"U32*)(((FMSTR_U32)(base))+(offset))) |= bit)\000"
.LASF18:
	.ascii	"__SIZEOF_SHORT__ 2\000"
.LASF799:
	.ascii	"FMSTR_Compare32U\000"
.LASF661:
	.ascii	"FMSTR_FCAN_RX(pctx) (pctx)->nDataIx = 0;\000"
.LASF257:
	.ascii	"__ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK\000"
.LASF764:
	.ascii	"__FREEMASTER_REC_H \000"
.LASF216:
	.ascii	"__ULFRACT_MIN__ 0.0ULR\000"
.LASF675:
	.ascii	"__FREEMASTER_PROTOCOL_H \000"
.LASF276:
	.ascii	"__DQ_IBIT__ 0\000"
.LASF427:
	.ascii	"FMSTR_SCI_TWOWIRE_ONLY FMSTR_LIGHT_VERSION\000"
.LASF42:
	.ascii	"__INT32_TYPE__ long int\000"
.LASF433:
	.ascii	"FMSTR_TSA_CDECL const\000"
.LASF100:
	.ascii	"__INT_LEAST64_MAX__ 9223372036854775807LL\000"
.LASF446:
	.ascii	"FMSTR_TSA_INFO_ENTRYTYPE_MASK 0x0003U\000"
.LASF503:
	.ascii	"FMSTR_TSA_TABLE(id) \000"
.LASF614:
	.ascii	"FMSTR_FCANMB_CTXREADY 0x08\000"
.LASF79:
	.ascii	"__SIZE_MAX__ 4294967295U\000"
.LASF371:
	.ascii	"FMSTR_USE_FLEXCAN 0\000"
.LASF288:
	.ascii	"__UTQ_IBIT__ 0\000"
.LASF809:
	.ascii	"FMSTR_SetUpRec\000"
.LASF839:
	.ascii	"pcm_dwRecWritePtr\000"
.LASF643:
	.ascii	"FMSTR_FCAN_DRXI() ( ((FMSTR_FLEXCAN_RXMB)&0x20) ? F"
	.ascii	"MSTR_CLRBIT32(FMSTR_CAN_BASE, FMSTR_FCANIER2_OFFSET"
	.ascii	", (1<<((FMSTR_FLEXCAN_RXMB)-32))): FMSTR_CLRBIT32(F"
	.ascii	"MSTR_CAN_BASE, FMSTR_FCANIER1_OFFSET, (1<<(FMSTR_FL"
	.ascii	"EXCAN_RXMB))) )\000"
.LASF687:
	.ascii	"FMSTR_CMD_GETTSAINFO 0x11U\000"
.LASF575:
	.ascii	"FMSTR_SCIC2_RWU 0x02\000"
.LASF410:
	.ascii	"FMSTR_USE_MCAN 0\000"
.LASF357:
	.ascii	"__ELF__ 1\000"
.LASF346:
	.ascii	"__THUMBEL__ 1\000"
.LASF641:
	.ascii	"FMSTR_FCAN_DTXI() ( ((FMSTR_FLEXCAN_TXMB)&0x20) ? F"
	.ascii	"MSTR_CLRBIT32(FMSTR_CAN_BASE, FMSTR_FCANIER2_OFFSET"
	.ascii	", (1<<((FMSTR_FLEXCAN_TXMB)-32))): FMSTR_CLRBIT32(F"
	.ascii	"MSTR_CAN_BASE, FMSTR_FCANIER1_OFFSET, (1<<(FMSTR_FL"
	.ascii	"EXCAN_TXMB))) )\000"
.LASF328:
	.ascii	"__ARM_FEATURE_DSP 1\000"
.LASF694:
	.ascii	"FMSTR_CMD_STOPREC 0xc2U\000"
.LASF270:
	.ascii	"__QQ_IBIT__ 0\000"
.LASF611:
	.ascii	"FMSTR_FCANMB_CRXVOID 0x00\000"
.LASF806:
	.ascii	"nResponseCode\000"
.LASF259:
	.ascii	"__LLACCUM_FBIT__ 31\000"
.LASF584:
	.ascii	"FMSTR_SCISR_PF 0x01\000"
.LASF36:
	.ascii	"__UINTMAX_TYPE__ long long unsigned int\000"
.LASF456:
	.ascii	"FMSTR_TSATBL_VOIDPTR volatile const void*\000"
.LASF284:
	.ascii	"__USQ_IBIT__ 0\000"
.LASF775:
	.ascii	"FMSTR_U16\000"
.LASF54:
	.ascii	"__UINT_LEAST32_TYPE__ long unsigned int\000"
.LASF4:
	.ascii	"__GNUC_MINOR__ 9\000"
.LASF35:
	.ascii	"__INTMAX_TYPE__ long long int\000"
.LASF318:
	.ascii	"__GCC_ATOMIC_INT_LOCK_FREE 2\000"
.LASF519:
	.ascii	"FMSTR_CFG_FLAGS FMSTR_CFG_REC_LARGE_MODE\000"
.LASF680:
	.ascii	"FMSTR_CMD_WRITEMEM_EX 0x05U\000"
.LASF604:
	.ascii	"FMSTR_SCI_ERXI() FMSTR_SETBIT32(FMSTR_SCI_BASE, FMS"
	.ascii	"TR_SCICTRL_OFFSET, FMSTR_SCICTRL_RIE)\000"
.LASF660:
	.ascii	"FMSTR_FCAN_TX(pctx) FMSTR_SETREG8(FMSTR_CAN_BASE, F"
	.ascii	"MSTR_FCANTXFG_OFFSET + FMSTR_FCMBCSR + 3, (FMSTR_FC"
	.ascii	"ANMB_CTXTRANS_ONCE & 0x0f) )\000"
.LASF788:
	.ascii	"bIsStopping\000"
.LASF238:
	.ascii	"__USACCUM_EPSILON__ 0x1P-8UHK\000"
.LASF153:
	.ascii	"__DBL_HAS_QUIET_NAN__ 1\000"
.LASF404:
	.ascii	"FMSTR_USE_WRITEVAR 1\000"
.LASF711:
	.ascii	"FMSTR_CMD_WRITEVAR8 0xe3U\000"
.LASF222:
	.ascii	"__LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR\000"
.LASF642:
	.ascii	"FMSTR_FCAN_ERXI() ( ((FMSTR_FLEXCAN_RXMB)&0x20) ? F"
	.ascii	"MSTR_SETBIT32(FMSTR_CAN_BASE, FMSTR_FCANIER2_OFFSET"
	.ascii	", (1<<((FMSTR_FLEXCAN_RXMB)-32))): FMSTR_SETBIT32(F"
	.ascii	"MSTR_CAN_BASE, FMSTR_FCANIER1_OFFSET, (1<<(FMSTR_FL"
	.ascii	"EXCAN_RXMB))) )\000"
.LASF733:
	.ascii	"FMSTR_STC_SFIOUNMATCH 0x8BU\000"
.LASF78:
	.ascii	"__PTRDIFF_MAX__ 2147483647\000"
.LASF232:
	.ascii	"__SACCUM_MAX__ 0X7FFFP-7HK\000"
.LASF64:
	.ascii	"__INTPTR_TYPE__ int\000"
.LASF65:
	.ascii	"__UINTPTR_TYPE__ unsigned int\000"
.LASF640:
	.ascii	"FMSTR_FCAN_ETXI() ( ((FMSTR_FLEXCAN_TXMB)&0x20) ? F"
	.ascii	"MSTR_SETBIT32(FMSTR_CAN_BASE, FMSTR_FCANIER2_OFFSET"
	.ascii	", (1<<((FMSTR_FLEXCAN_TXMB)-32))): FMSTR_SETBIT32(F"
	.ascii	"MSTR_CAN_BASE, FMSTR_FCANIER1_OFFSET, (1<<(FMSTR_FL"
	.ascii	"EXCAN_TXMB))) )\000"
.LASF646:
	.ascii	"FMSTR_FCAN_TEST_TXFLG() ( ((FMSTR_FLEXCAN_TXMB)&0x2"
	.ascii	"0) ? FMSTR_TSTBIT32(FMSTR_CAN_BASE, FMSTR_FCANIFR2_"
	.ascii	"OFFSET, (1<<((FMSTR_FLEXCAN_TXMB)-32))): FMSTR_TSTB"
	.ascii	"IT32(FMSTR_CAN_BASE, FMSTR_FCANIFR1_OFFSET, (1<<(FM"
	.ascii	"STR_FLEXCAN_TXMB))) )\000"
.LASF305:
	.ascii	"__REGISTER_PREFIX__ \000"
.LASF188:
	.ascii	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000"
	.ascii	"000000001E-6143DL\000"
.LASF141:
	.ascii	"__DBL_DIG__ 15\000"
.LASF218:
	.ascii	"__ULFRACT_EPSILON__ 0x1P-32ULR\000"
.LASF698:
	.ascii	"FMSTR_CMD_GETAPPCMDSTS 0xc6U\000"
.LASF665:
	.ascii	"FMSTR_FCAN_RFINISH(pctx) FMSTR_SETBIT16(FMSTR_CAN_B"
	.ascii	"ASE, FMSTR_FCANTMR_OFFSET, 0)\000"
.LASF22:
	.ascii	"__SIZEOF_SIZE_T__ 4\000"
.LASF412:
	.ascii	"FMSTR_USE_CAN 0\000"
.LASF185:
	.ascii	"__DEC128_MIN__ 1E-6143DL\000"
.LASF101:
	.ascii	"__INT64_C(c) c ## LL\000"
.LASF98:
	.ascii	"__INT_LEAST32_MAX__ 2147483647L\000"
.LASF563:
	.ascii	"FMSTR_SCIC1_RSRC 0x20\000"
.LASF162:
	.ascii	"__LDBL_MIN__ 2.2250738585072014e-308L\000"
.LASF562:
	.ascii	"FMSTR_SCIC1_SWAI 0x40\000"
.LASF240:
	.ascii	"__ACCUM_IBIT__ 16\000"
.LASF91:
	.ascii	"__UINT16_MAX__ 65535\000"
.LASF741:
	.ascii	"FMSTR_FASTCMD 0xc0U\000"
.LASF780:
	.ascii	"short int\000"
.LASF424:
	.ascii	"FMSTR_USE_FASTREC 0\000"
.LASF623:
	.ascii	"FMSTR_FCMBIDR0 0x04\000"
.LASF105:
	.ascii	"__UINT16_C(c) c\000"
.LASF551:
	.ascii	"FMSTR_CLRBIT32(base,offset,bit) ((*(volatile FMSTR_"
	.ascii	"U32*)(((FMSTR_U32)(base))+(offset))) &= ~(bit))\000"
.LASF302:
	.ascii	"__UDA_IBIT__ 32\000"
.LASF137:
	.ascii	"__FLT_HAS_INFINITY__ 1\000"
.LASF516:
	.ascii	"FMSTR_USE_EX_CMDS 1\000"
.LASF7:
	.ascii	"__ATOMIC_RELAXED 0\000"
.LASF610:
	.ascii	"FMSTR_FCANMB_CODE_MASK 0x0F\000"
.LASF152:
	.ascii	"__DBL_HAS_INFINITY__ 1\000"
.LASF312:
	.ascii	"__GCC_ATOMIC_BOOL_LOCK_FREE 2\000"
.LASF619:
	.ascii	"FMSTR_FCANIFR1_OFFSET 0x30\000"
.LASF501:
	.ascii	"FMSTR_TSA_TABLE_END() \000"
.LASF390:
	.ascii	"FMSTR_REC_OWNBUFF 0\000"
.LASF358:
	.ascii	"__USES_INITFINI__ 1\000"
.LASF70:
	.ascii	"__SHRT_MAX__ 32767\000"
.LASF146:
	.ascii	"__DBL_DECIMAL_DIG__ 17\000"
.LASF528:
	.ascii	"FMSTR_ConstToBuffer8 FMSTR_ValueToBuffer8\000"
.LASF330:
	.ascii	"__ARM_FEATURE_SAT 1\000"
.LASF106:
	.ascii	"__UINT_LEAST32_MAX__ 4294967295UL\000"
.LASF254:
	.ascii	"__ULACCUM_FBIT__ 32\000"
.LASF573:
	.ascii	"FMSTR_SCIC2_TE 0x08\000"
.LASF335:
	.ascii	"__ARM_FEATURE_SIMD32 1\000"
.LASF826:
	.ascii	"pcm_uTrgThreshold\000"
.LASF72:
	.ascii	"__LONG_MAX__ 2147483647L\000"
.LASF121:
	.ascii	"__GCC_IEC_559_COMPLEX 0\000"
.LASF269:
	.ascii	"__QQ_FBIT__ 7\000"
.LASF706:
	.ascii	"FMSTR_CMD_GETAPPCMDDATA 0xD3U\000"
.LASF414:
	.ascii	"FMSTR_USE_MQX_IO 0\000"
.LASF721:
	.ascii	"FMSTR_STS_RECRUN 0x01U\000"
.LASF304:
	.ascii	"__UTA_IBIT__ 64\000"
.LASF784:
	.ascii	"FMSTR_SIZE8\000"
.LASF625:
	.ascii	"FMSTR_FCMBIDR2 0x06\000"
.LASF846:
	.ascii	"FMSTR_ValueFromBuffer32\000"
.LASF228:
	.ascii	"__ULLFRACT_EPSILON__ 0x1P-64ULLR\000"
.LASF744:
	.ascii	"FMSTR_DESCR_SIZE 25U\000"
.LASF2:
	.ascii	"__STDC_HOSTED__ 1\000"
.LASF326:
	.ascii	"__SIZEOF_WINT_T__ 4\000"
.LASF634:
	.ascii	"FMSTR_FCMBDSR7 0x0C\000"
.LASF331:
	.ascii	"__ARM_FEATURE_UNALIGNED 1\000"
.LASF356:
	.ascii	"__GXX_TYPEINFO_EQUALITY_INLINE 0\000"
.LASF515:
	.ascii	"__FREEMASTER_S32XX_H \000"
.LASF538:
	.ascii	"FMSTR_CANHW_FLEXCAN 1\000"
.LASF664:
	.ascii	"FMSTR_FCAN_GETBYTE(pctx) ((FMSTR_U8) (FMSTR_GETREG8"
	.ascii	"(FMSTR_CAN_BASE, (FMSTR_FCANRXFG_OFFSET + FMSTR_FCM"
	.ascii	"BDSR0) - (0x3&((pctx)->nDataIx)) + (0x4&((pctx)->nD"
	.ascii	"ataIx)) ))); (pctx)->nDataIx++\000"
.LASF474:
	.ascii	"FMSTR_TSA_UFRAC_UQ(m,n) \"\\xE4:\" #m \".\" #n\000"
.LASF434:
	.ascii	"FMSTR_USE_SFIO 0\000"
.LASF169:
	.ascii	"__DEC32_MIN_EXP__ (-94)\000"
.LASF391:
	.ascii	"FMSTR_REC_BUFF_SIZE 512\000"
.LASF266:
	.ascii	"__ULLACCUM_MIN__ 0.0ULLK\000"
.LASF522:
	.ascii	"FMSTR_GLOB_VERSION_MINOR 0\000"
.LASF762:
	.ascii	"FMSTR_PDBDM_DECODING_FRAME 0x04\000"
.LASF714:
	.ascii	"FMSTR_CMD_GETSTRLEN_EX 0xe6U\000"
.LASF452:
	.ascii	"FMSTR_TSA_INFO_RWV_FLAG 0x0002U\000"
.LASF46:
	.ascii	"__UINT32_TYPE__ long unsigned int\000"
.LASF490:
	.ascii	"FMSTR_TSA_INFO2(size,flags) \000"
.LASF343:
	.ascii	"__thumb2__ 1\000"
.LASF587:
	.ascii	"FMSTR_SCISR2_RAF 0x01\000"
.LASF707:
	.ascii	"FMSTR_CMD_GETSTRLEN 0xD4U\000"
.LASF746:
	.ascii	"FMSTR_CFGFLAG_REC_LARGE_MODE 0x10U\000"
.LASF226:
	.ascii	"__ULLFRACT_MIN__ 0.0ULLR\000"
.LASF808:
	.ascii	"FMSTR_TriggerRec\000"
.LASF15:
	.ascii	"__SIZEOF_INT__ 4\000"
.LASF220:
	.ascii	"__LLFRACT_IBIT__ 0\000"
.LASF372:
	.ascii	"FMSTR_USE_PDBDM 0\000"
.LASF645:
	.ascii	"FMSTR_FCAN_CLEAR_RXFLG() ( ((FMSTR_FLEXCAN_RXMB)&0x"
	.ascii	"20) ? FMSTR_SETREG32(FMSTR_CAN_BASE, FMSTR_FCANIFR2"
	.ascii	"_OFFSET, (1<<((FMSTR_FLEXCAN_RXMB)-32))): FMSTR_SET"
	.ascii	"REG32(FMSTR_CAN_BASE, FMSTR_FCANIFR1_OFFSET, (1<<(F"
	.ascii	"MSTR_FLEXCAN_RXMB))) )\000"
.LASF742:
	.ascii	"FMSTR_FASTCMD_DATALEN_MASK 0x30U\000"
.LASF444:
	.ascii	"__FREEMASTER_TSA_H \000"
.LASF607:
	.ascii	"FMSTR_SCI_GETCHAR() FMSTR_GETREG8(FMSTR_SCI_BASE, F"
	.ascii	"MSTR_SCIDATA_OFFSET)\000"
.LASF348:
	.ascii	"__ARM_FP 4\000"
.LASF627:
	.ascii	"FMSTR_FCMBDSR0 0x0B\000"
.LASF84:
	.ascii	"__SIG_ATOMIC_MAX__ 2147483647\000"
.LASF543:
	.ascii	"FMSTR_SETREG16(base,offset,value) (*(volatile FMSTR"
	.ascii	"_U16*)(((FMSTR_U32)(base))+(offset)) = value)\000"
.LASF61:
	.ascii	"__UINT_FAST16_TYPE__ unsigned int\000"
.LASF564:
	.ascii	"FMSTR_SCIC1_M 0x10\000"
.LASF568:
	.ascii	"FMSTR_SCIC1_PT 0x01\000"
.LASF243:
	.ascii	"__ACCUM_EPSILON__ 0x1P-15K\000"
.LASF258:
	.ascii	"__ULACCUM_EPSILON__ 0x1P-32ULK\000"
.LASF155:
	.ascii	"__LDBL_DIG__ 15\000"
.LASF615:
	.ascii	"FMSTR_FCANTMR_OFFSET 0x08\000"
.LASF77:
	.ascii	"__WINT_MIN__ 0U\000"
.LASF549:
	.ascii	"FMSTR_GETREG32(base,offset) (*(volatile FMSTR_U32*)"
	.ascii	"(((FMSTR_U32)(base))+(offset)))\000"
.LASF368:
	.ascii	"FMSTR_CAN_BASE 0x40024000UL\000"
.LASF180:
	.ascii	"__DEC64_EPSILON__ 1E-15DD\000"
.LASF397:
	.ascii	"FMSTR_USE_TSA_DYNAMIC FMSTR_DEMO_ENOUGH_RAM\000"
.LASF724:
	.ascii	"FMSTR_STC_CMDCSERR 0x82U\000"
.LASF437:
	.ascii	"FMSTR_PIPES_PRINTF_BUFF_SIZE 48\000"
.LASF49:
	.ascii	"__INT_LEAST16_TYPE__ short int\000"
.LASF578:
	.ascii	"FMSTR_SCISR_TC 0x40\000"
.LASF147:
	.ascii	"__DBL_MAX__ ((double)1.7976931348623157e+308L)\000"
.LASF597:
	.ascii	"FMSTR_SCI_TE() FMSTR_SETBIT32(FMSTR_SCI_BASE, FMSTR"
	.ascii	"_SCICTRL_OFFSET, FMSTR_SCICTRL_TE)\000"
.LASF219:
	.ascii	"__LLFRACT_FBIT__ 63\000"
.LASF342:
	.ascii	"__thumb__ 1\000"
.LASF405:
	.ascii	"FMSTR_USE_WRITEVARMASK 1\000"
.LASF345:
	.ascii	"__ARMEL__ 1\000"
.LASF422:
	.ascii	"FMSTR_BYTE_BUFFER_ACCESS 1\000"
.LASF426:
	.ascii	"FMSTR_REC_COMMON_ERR_CODES FMSTR_LIGHT_VERSION\000"
.LASF271:
	.ascii	"__HQ_FBIT__ 15\000"
.LASF589:
	.ascii	"FMSTR_SCISTATUS_OFFSET 0x14\000"
.LASF844:
	.ascii	"FMSTR_ValueFromBuffer16\000"
.LASF6:
	.ascii	"__VERSION__ \"4.9.3 20150529 (release) [ARM/embedde"
	.ascii	"d-4_9-branch revision 227977]\"\000"
.LASF541:
	.ascii	"FMSTR_SETBIT8(base,offset,bit) (*(volatile FMSTR_U8"
	.ascii	"*)(((FMSTR_U32)(base))+(offset)) |= bit)\000"
.LASF430:
	.ascii	"FMSTR_REC_LARGE_MODE 0\000"
.LASF459:
	.ascii	"FMSTR_TSA_STRUCT_CFG(name) FMSTR_TSATBL_STRPTR_ENTR"
	.ascii	"Y(#name), FMSTR_TSATBL_STRPTR_ENTRY(NULL), FMSTR_TS"
	.ascii	"ATBL_VOIDPTR_ENTRY(NULL), FMSTR_TSATBL_VOIDPTR_ENTR"
	.ascii	"Y(FMSTR_TSA_INFO1(name, FMSTR_TSA_INFO_STRUCT)),\000"
.LASF190:
	.ascii	"__SFRACT_IBIT__ 0\000"
.LASF415:
	.ascii	"FMSTR_USE_USB_CDC 0\000"
.LASF384:
	.ascii	"FMSTR_APPCMD_BUFF_SIZE 32\000"
.LASF612:
	.ascii	"FMSTR_FCANMB_CRXEMPTY 0x04\000"
.LASF504:
	.ascii	"FMSTR_TSA_TABLE_LIST_END() \000"
.LASF333:
	.ascii	"__ARM_FEATURE_LDREX 7\000"
.LASF31:
	.ascii	"__SIZE_TYPE__ unsigned int\000"
.LASF580:
	.ascii	"FMSTR_SCISR_IDLE 0x10\000"
.LASF223:
	.ascii	"__LLFRACT_EPSILON__ 0x1P-63LLR\000"
.LASF192:
	.ascii	"__SFRACT_MAX__ 0X7FP-7HR\000"
.LASF602:
	.ascii	"FMSTR_SCI_ETXI() FMSTR_SETBIT32(FMSTR_SCI_BASE, FMS"
	.ascii	"TR_SCICTRL_OFFSET, FMSTR_SCICTRL_TIE)\000"
.LASF97:
	.ascii	"__INT16_C(c) c\000"
.LASF418:
	.ascii	"FMSTR_SCI_HAS_TXQUEUE 0\000"
.LASF294:
	.ascii	"__DA_IBIT__ 32\000"
.LASF184:
	.ascii	"__DEC128_MAX_EXP__ 6145\000"
.LASF11:
	.ascii	"__ATOMIC_ACQ_REL 4\000"
.LASF272:
	.ascii	"__HQ_IBIT__ 0\000"
.LASF143:
	.ascii	"__DBL_MIN_10_EXP__ (-307)\000"
.LASF41:
	.ascii	"__INT16_TYPE__ short int\000"
.LASF581:
	.ascii	"FMSTR_SCISR_OR 0x08\000"
.LASF482:
	.ascii	"FMSTR_TSA_FLOAT \"\\xFA\"\000"
.LASF373:
	.ascii	"FMSTR_FLEXCAN_TXMB 0\000"
.LASF732:
	.ascii	"FMSTR_STC_SFIOERR 0x8AU\000"
.LASF233:
	.ascii	"__SACCUM_EPSILON__ 0x1P-7HK\000"
.LASF102:
	.ascii	"__UINT_LEAST8_MAX__ 255\000"
.LASF560:
	.ascii	"FMSTR_SCIDR_OFFSET 7\000"
.LASF365:
	.ascii	"FMSTR_SHORT_INTR 1\000"
.LASF811:
	.ascii	"FMSTR_SetUpRec_exit\000"
.LASF140:
	.ascii	"__DBL_MANT_DIG__ 53\000"
.LASF626:
	.ascii	"FMSTR_FCMBIDR3 0x07\000"
.LASF803:
	.ascii	"pResponse\000"
.LASF354:
	.ascii	"__ARM_EABI__ 1\000"
.LASF51:
	.ascii	"__INT_LEAST64_TYPE__ long long int\000"
.LASF229:
	.ascii	"__SACCUM_FBIT__ 7\000"
.LASF730:
	.ascii	"FMSTR_STC_NOTINIT 0x88U\000"
.LASF387:
	.ascii	"FMSTR_MAX_SCOPE_VARS 8\000"
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 4.9.3 20150529 (release) [ARM/embedded-4_9-branch revision 227977]"
