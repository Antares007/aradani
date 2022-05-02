.ident	"clang version 13.0.1"
empty:                                  # @empty
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

term:                                   # @term
  mov	r10, qword ptr [rcx + 8*rsi - 24]
  cmp	r10, qword ptr [rcx + 8*rsi - 32]
  jae	.LBB23_3
  mov	r8, qword ptr [rcx + 8*rsi - 40]
  mov	r9, qword ptr [rcx + 8*rsi - 8]
  mov	al, byte ptr [r8 + r10]
  cmp	al, byte ptr [r9]
  jne	.LBB23_3
  add	r10, 1
  mov	qword ptr [rcx + 8*rsi - 24], r10
  mov	qword ptr [rcx + 8*rsi - 8], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB23_3:
  add	rsi, -5
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL

orelse_n_n:                             # @orelse_n_n
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  mov	rax, qword ptr [rcx]
  mov	qword ptr [rcx + 8*rsi - 8], rax
  mov	rax, qword ptr [rcx + 8]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rcx + 16]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rcx + 24]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	qword ptr [rcx + 8*rsi + 24], r8
  lea	rax, [rip + run]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	qword ptr [rcx + 8*rsi + 40], 6
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	qword ptr [rcx + 8*rsi + 56], rdi
  mov	rax, qword ptr [rip + os_queue_soll]
  mov	qword ptr [rcx + 8*rsi + 64], rax
  mov	rax, qword ptr [rip + and2]
  mov	qword ptr [rcx + 8*rsi + 72], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 11]
  mov	qword ptr [rcx + 8*rsi + 80], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 88], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

orelse_n:                               # @orelse_n
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	r8, [rsi + 2]
  lea	rax, [rip + orelse_n_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

thenS_n_n:                              # @thenS_n_n
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  lea	rax, [rip + is_true_pith]
  mov	qword ptr [rcx + 8*rsi - 8], rax
  mov	qword ptr [rcx + 8*rsi], 4
  lea	rax, [rip + drop_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	qword ptr [rcx + 8*rsi + 16], r8
  mov	qword ptr [rcx + 8*rsi + 24], rdi
  lea	rax, [rip + cont_eval]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	rax, qword ptr [rip + and2or3]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  mov	qword ptr [rcx + 8*rsi + 48], 7
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 56], rax
  lea	rax, [rip + depth_pp]
  mov	qword ptr [rcx + 8*rsi + 64], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 72], rax
  lea	r8, [rsi + 11]
  lea	rax, [rip + coll]
  mov	qword ptr [rcx + 8*rsi + 80], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 88], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

thenS_n:                                # @thenS_n
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	r8, [rsi + 2]
  lea	rax, [rip + thenS_n_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

var:                                    # @var
  mov	qword ptr [rcx + 976], rdi
  lea	rax, [rip + drop]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL



Sa:                                     # @Sa
  lea	rax, [rip + b]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	r8, [rip + Sa]
  mov	qword ptr [rcx + 8*rsi + 8], r8
  lea	rax, [rip + a]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  lea	rax, [rip + thenS]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  lea	rax, [rip + orelse3]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	qword ptr [rcx + 8*rsi + 40], r8
  mov	qword ptr [rcx + 976], rdi
  lea	rax, [rip + drop]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 8]
  mov	qword ptr [rcx + 8*rsi + 56], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 64], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL

Exp:                                    # @Exp
  lea	rax, [rip + a]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + opr]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	r8, [rip + Exp]
  mov	qword ptr [rcx + 8*rsi + 16], r8
  lea	r9, [rip + thenS]
  mov	qword ptr [rcx + 8*rsi + 24], r9
  lea	rax, [rip + cpr]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	qword ptr [rcx + 8*rsi + 40], r9
  lea	r10, [rip + orelse5]
  mov	qword ptr [rcx + 8*rsi + 48], r10
  mov	qword ptr [rcx + 8*rsi + 56], r8
  lea	rax, [rip + pls]
  mov	qword ptr [rcx + 8*rsi + 64], rax
  mov	qword ptr [rcx + 8*rsi + 72], r9
  mov	qword ptr [rcx + 8*rsi + 80], r8
  mov	qword ptr [rcx + 8*rsi + 88], r9
  mov	qword ptr [rcx + 8*rsi + 96], r10
  mov	qword ptr [rcx + 8*rsi + 104], r8
  mov	qword ptr [rcx + 976], rdi
  lea	rax, [rip + drop]
  mov	qword ptr [rcx + 8*rsi + 112], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 16]
  mov	qword ptr [rcx + 8*rsi + 120], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 128], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL



  .section	.text.end,"ax",@progbits
tail:                                   # @tail
  ret
  .section	.text.begin,"ax",@progbits
head:                                   # @head
  cmp	byte ptr [rip + "ιmported"], 1
  jne	.LBB1_2
  lea	rax, [rip + .L.str.94]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + "მთავარი"]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + tail]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
.LBB1_2:
  lea	rax, [rip + imports]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + exports]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + tail]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  lea	rax, [rip + "δc"]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  lea	r8, [rip + "αnd"]
  mov	qword ptr [rcx + 8*rsi + 32], r8
  lea	rax, [rip + "αndor3"]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  mov	qword ptr [rcx + 8*rdx - 8], r8
  mov	rax, qword ptr [rcx + 8*rsi + 24]
  mov	qword ptr [rcx + 8*rdx - 16], rax
  mov	rax, qword ptr [rcx + 8*rsi + 16]
  mov	qword ptr [rcx + 8*rdx - 24], rax
  mov	rax, qword ptr [rcx + 8*rsi + 8]
  mov	qword ptr [rcx + 8*rdx - 32], rax
  lea	rax, [rip + "Δ7_C2"]
  mov	qword ptr [rcx + 8*rdx - 40], rax
  lea	rax, [rip + "Δ3_SO1_D3_O"]
  mov	qword ptr [rcx + 8*rdx - 48], rax
  lea	rax, [rip + "Δ4_SO3_O"]
  mov	qword ptr [rcx + 8*rdx - 56], rax
  add	rdx, -7
  mov	rax, qword ptr [rcx + 8*rsi]
  jmp	rax                             # TAILCALL
exports:                                # @exports
  lea	rax, [rip + .L.str.94]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + "მთავარი"]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + tail]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
imports:                                # @imports
  lea	rax, [rip + .L.str.42]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + or5]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_54]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
"δc":                                   # @"\CE\B4c"
  push	r15
  push	r14
  push	r13
  push	r12
  push	rbx
  mov	r15, qword ptr [rcx + 8*rsi - 8]
  mov	r10, qword ptr [rcx + 8*rsi - 16]
  lea	r9, [rsi - 3]
  mov	r12, qword ptr [rcx + 8*rsi - 24]
  mov	r11, qword ptr [rcx + 8*rsi - 32]
  mov	r13, qword ptr [rcx + 8*rsi - 48]
  mov	r14, qword ptr [rcx + 8*rsi - 40]
  lea	r8, [rsi - 6]
  xor	ebx, ebx
.LBB4_1:                                # =>This Inner Loop Header: Depth=1
  movzx	eax, byte ptr [r12 + rbx]
  cmp	al, byte ptr [r13 + rbx]
  jne	.LBB4_4
  add	rbx, 1
  test	al, al
  jne	.LBB4_1
  mov	qword ptr [r14], r10
  mov	qword ptr [rcx + 8*rsi - 48], r11
  lea	rax, [rip + exports]
  mov	qword ptr [rcx + 8*rsi - 40], rax
  mov	qword ptr [rcx + 8*rsi - 32], r15
  lea	rax, [rip + "δc"]
  mov	qword ptr [rcx + 8*rsi - 24], rax
  lea	rax, [rip + "αnd"]
  mov	qword ptr [rcx + 8*rsi - 16], rax
  lea	rbx, [rip + "αndor3"]
  mov	qword ptr [rcx + 8*rsi - 8], rbx
  mov	qword ptr [rcx + 8*rdx - 8], rax
  mov	rax, qword ptr [rcx + 8*rsi - 24]
  mov	qword ptr [rcx + 8*rdx - 16], rax
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  mov	qword ptr [rcx + 8*rdx - 24], rax
  mov	rax, qword ptr [rcx + 8*rsi - 40]
  mov	qword ptr [rcx + 8*rdx - 32], rax
  lea	rax, [rip + "Δ7_C2"]
  mov	qword ptr [rcx + 8*rdx - 40], rax
  lea	rax, [rip + "Δ3_SO1_D3_O"]
  mov	qword ptr [rcx + 8*rdx - 48], rax
  lea	rax, [rip + "Δ4_SO3_O"]
  mov	qword ptr [rcx + 8*rdx - 56], rax
  add	rdx, -7
  mov	rax, qword ptr [rcx + 8*rsi - 48]
  mov	rsi, r8
  jmp	.LBB4_5
.LBB4_4:
  mov	qword ptr [rcx + 8*rsi - 24], r15
  lea	rax, [rip + "δc"]
  mov	qword ptr [rcx + 8*rsi - 16], rax
  lea	rbx, [rip + "αnd"]
  mov	qword ptr [rcx + 8*rsi - 8], rbx
  mov	qword ptr [rcx + 8*rdx - 8], rax
  lea	rax, [rip + "Δ4_C2"]
  mov	qword ptr [rcx + 8*rdx - 16], rax
  lea	rax, [rip + "Δ3_SO1_O"]
  mov	qword ptr [rcx + 8*rdx - 24], rax
  lea	rax, [rip + "Δ4_C0"]
  mov	qword ptr [rcx + 8*rdx - 32], rax
  add	rdx, -4
  mov	rax, qword ptr [rcx + 8*rsi - 24]
  mov	rsi, r9
.LBB4_5:
  pop	rbx
  pop	r12
  pop	r13
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
"αnd":                                  # @"\CE\B1nd"
  mov	rax, qword ptr [rcx + 8*rsi - 8]
  mov	qword ptr [rcx + 8*rdx - 8], rax
  lea	rax, [rip + "Δ4_C2"]
  mov	qword ptr [rcx + 8*rdx - 16], rax
  lea	rax, [rip + "Δ3_SO1_O"]
  mov	qword ptr [rcx + 8*rdx - 24], rax
  lea	rax, [rip + "Δ4_C0"]
  mov	qword ptr [rcx + 8*rdx - 32], rax
  add	rdx, -4
  mov	rax, qword ptr [rcx + 8*rsi - 16]
  add	rsi, -2
  jmp	rax                             # TAILCALL
"αndor3":                               # @"\CE\B1ndor3"
  mov	rax, qword ptr [rcx + 8*rsi - 8]
  mov	qword ptr [rcx + 8*rdx - 8], rax
  mov	rax, qword ptr [rcx + 8*rsi - 16]
  mov	qword ptr [rcx + 8*rdx - 16], rax
  mov	rax, qword ptr [rcx + 8*rsi - 24]
  mov	qword ptr [rcx + 8*rdx - 24], rax
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  mov	qword ptr [rcx + 8*rdx - 32], rax
  lea	rax, [rip + "Δ7_C2"]
  mov	qword ptr [rcx + 8*rdx - 40], rax
  lea	rax, [rip + "Δ3_SO1_D3_O"]
  mov	qword ptr [rcx + 8*rdx - 48], rax
  lea	rax, [rip + "Δ4_SO3_O"]
  mov	qword ptr [rcx + 8*rdx - 56], rax
  add	rdx, -7
  mov	rax, qword ptr [rcx + 8*rsi - 40]
  add	rsi, -5
  jmp	rax                             # TAILCALL
soll_pop:                               # @soll_pop
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  mov	r9, qword ptr [r8 - 8]
  test	r9, r9
  je	.LBB7_1
  lea	rax, [r9 - 1]
  mov	qword ptr [r8 - 8], rax
  mov	rax, qword ptr [r8 + 8*r9 - 8]
  mov	qword ptr [rcx + 8*rsi - 8], rax
  lea	rax, [rdx + 1]
  mov	rax, qword ptr [rcx + 8*rax]
  jmp	rax                             # TAILCALL
.LBB7_1:
  add	rsi, -1
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
soll_push:                              # @soll_push
  mov	r8, rsi
  mov	rax, qword ptr [rcx + 8*rsi - 8]
  add	rsi, -2
  mov	r9, qword ptr [rax - 8]
  lea	r10, [r9 + 1]
  mov	r11, rdx
  cmp	r10, qword ptr [rax - 16]
  jae	.LBB8_2
  mov	r8, qword ptr [rcx + 8*r8 - 16]
  mov	qword ptr [rax - 8], r10
  mov	qword ptr [rax + 8*r9], r8
  lea	r11, [rdx + 1]
.LBB8_2:
  mov	rax, qword ptr [rcx + 8*r11]
  jmp	rax                             # TAILCALL
soll_contains:                          # @soll_contains
  mov	r8, rsi
  mov	r9, qword ptr [rcx + 8*rsi - 8]
  add	rsi, -2
  mov	r10, qword ptr [r9 - 8]
  mov	rax, rdx
  test	r10, r10
  je	.LBB9_6
  mov	r8, qword ptr [rcx + 8*r8 - 16]
  xor	eax, eax
.LBB9_2:                                # =>This Inner Loop Header: Depth=1
  cmp	qword ptr [r9 + 8*rax], r8
  je	.LBB9_5
  add	rax, 1
  cmp	r10, rax
  jne	.LBB9_2
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
.LBB9_5:
  lea	rax, [rdx + 1]
.LBB9_6:
  mov	rax, qword ptr [rcx + 8*rax]
  jmp	rax                             # TAILCALL
ps:                                     # @ps
  push	r15
  push	r14
  push	r12
  push	rbx
  push	rax
  mov	r15, rcx
  mov	r14, rdx
  mov	rbx, rsi
  mov	r12, rdi
  mov	rsi, qword ptr [rcx + 8*rsi - 8]
  add	rbx, -1
  lea	rdi, [rip + .L.str]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rax, qword ptr [r15 + 8*r14 + 8]
  mov	rdi, r12
  mov	rsi, rbx
  mov	rdx, r14
  mov	rcx, r15
  add	rsp, 8
  pop	rbx
  pop	r12
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
pld:                                    # @pld
  push	r15
  push	r14
  push	r12
  push	rbx
  push	rax
  mov	r15, rcx
  mov	r14, rdx
  mov	rbx, rsi
  mov	r12, rdi
  mov	rsi, qword ptr [rcx + 8*rsi - 8]
  add	rbx, -1
  lea	rdi, [rip + .L.str.1]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rax, qword ptr [r15 + 8*r14 + 8]
  mov	rdi, r12
  mov	rsi, rbx
  mov	rdx, r14
  mov	rcx, r15
  add	rsp, 8
  pop	rbx
  pop	r12
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
pnl:                                    # @pnl
  push	r15
  push	r14
  push	r12
  push	rbx
  push	rax
  mov	r14, rcx
  mov	rbx, rdx
  mov	r15, rsi
  mov	r12, rdi
  lea	rdi, [rip + .L.str.2]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rax, qword ptr [r14 + 8*rbx + 8]
  mov	rdi, r12
  mov	rsi, r15
  mov	rdx, rbx
  mov	rcx, r14
  add	rsp, 8
  pop	rbx
  pop	r12
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
plu:                                    # @plu
  push	r15
  push	r14
  push	r12
  push	rbx
  push	rax
  mov	r15, rcx
  mov	r14, rdx
  mov	rbx, rsi
  mov	r12, rdi
  mov	rsi, qword ptr [rcx + 8*rsi - 8]
  add	rbx, -1
  lea	rdi, [rip + .L.str.3]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rax, qword ptr [r15 + 8*r14 + 8]
  mov	rdi, r12
  mov	rsi, rbx
  mov	rdx, r14
  mov	rcx, r15
  add	rsp, 8
  pop	rbx
  pop	r12
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
psoll:                                  # @psoll
  push	rbp
  push	r15
  push	r14
  push	r13
  push	r12
  push	rbx
  sub	rsp, 24
  mov	r13, rcx
  mov	qword ptr [rsp + 16], rdx       # 8-byte Spill
  mov	qword ptr [rsp], rdi            # 8-byte Spill
  mov	qword ptr [rsp + 8], rsi        # 8-byte Spill
  mov	rbp, qword ptr [rcx + 8*rsi - 8]
  cmp	qword ptr [rbp - 8], 0
  je	.LBB14_9
  lea	r12, [rip + .L.str.18]
  lea	rbx, [rip + .L.str.4]
  lea	r14, [rip + names+8]
  xor	r15d, r15d
  jmp	.LBB14_2
.LBB14_5:                               #   in Loop: Header=BB14_2 Depth=1
  mov	rsi, qword ptr [rsi]
.LBB14_8:                               #   in Loop: Header=BB14_2 Depth=1
  mov	rdi, rbx
  xor	eax, eax
  call	rcx
  add	r15, 1
  cmp	r15, qword ptr [rbp - 8]
  jae	.LBB14_9
.LBB14_2:                               # =>This Loop Header: Depth=1
  mov	rcx, qword ptr [rip + print]
  mov	rax, qword ptr [rip + names_i]
  mov	rsi, r12
  test	rax, rax
  je	.LBB14_8
  mov	rdx, qword ptr [rbp + 8*r15]
  mov	rsi, r14
.LBB14_4:                               #   Parent Loop BB14_2 Depth=1
  cmp	qword ptr [rsi - 8], rdx
  je	.LBB14_5
  add	rsi, 16
  add	rax, -1
  jne	.LBB14_4
  mov	rsi, r12
  jmp	.LBB14_8
.LBB14_9:
  lea	rdi, [rip + .L.str.2]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rsi, qword ptr [rsp + 8]        # 8-byte Reload
  mov	qword ptr [r13 + 8*rsi - 8], rbp
  mov	rdx, qword ptr [rsp + 16]       # 8-byte Reload
  mov	rax, qword ptr [r13 + 8*rdx + 8]
  mov	rdi, qword ptr [rsp]            # 8-byte Reload
  mov	rcx, r13
  add	rsp, 24
  pop	rbx
  pop	r12
  pop	r13
  pop	r14
  pop	r15
  pop	rbp
  jmp	rax                             # TAILCALL
name:                                   # @name
  mov	rcx, qword ptr [rip + names_i]
  lea	rax, [rip + .L.str.18]
  test	rcx, rcx
  je	.LBB15_5
  lea	rdx, [rip + names+8]
.LBB15_2:                               # =>This Inner Loop Header: Depth=1
  cmp	qword ptr [rdx - 8], rdi
  je	.LBB15_3
  add	rdx, 16
  add	rcx, -1
  jne	.LBB15_2
.LBB15_5:
  ret
.LBB15_3:
  mov	rax, qword ptr [rdx]
  ret
"pσ":                                   # @"p\CF\83"
  push	rbp
  push	r15
  push	r14
  push	r13
  push	r12
  push	rbx
  sub	rsp, 24
  mov	r15, rcx
  mov	qword ptr [rsp + 16], rdx       # 8-byte Spill
  mov	rbx, rsi
  mov	qword ptr [rsp + 8], rdi        # 8-byte Spill
  test	rsi, rsi
  je	.LBB16_9
  lea	rbp, [rip + .L.str.18]
  lea	r13, [rip + .L.str.4]
  lea	r12, [rip + names+8]
  xor	r14d, r14d
  jmp	.LBB16_2
.LBB16_5:                               #   in Loop: Header=BB16_2 Depth=1
  mov	rsi, qword ptr [rsi]
.LBB16_8:                               #   in Loop: Header=BB16_2 Depth=1
  mov	rdi, r13
  xor	eax, eax
  call	rcx
  add	r14, 1
  cmp	r14, rbx
  je	.LBB16_9
.LBB16_2:                               # =>This Loop Header: Depth=1
  mov	rcx, qword ptr [rip + print]
  mov	rax, qword ptr [rip + names_i]
  mov	rsi, rbp
  test	rax, rax
  je	.LBB16_8
  mov	rdx, qword ptr [r15 + 8*r14]
  mov	rsi, r12
.LBB16_4:                               #   Parent Loop BB16_2 Depth=1
  cmp	qword ptr [rsi - 8], rdx
  je	.LBB16_5
  add	rsi, 16
  add	rax, -1
  jne	.LBB16_4
  mov	rsi, rbp
  jmp	.LBB16_8
.LBB16_9:
  lea	rdi, [rip + .L.str.2]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rdx, qword ptr [rsp + 16]       # 8-byte Reload
  mov	rax, qword ptr [r15 + 8*rdx + 8]
  mov	rdi, qword ptr [rsp + 8]        # 8-byte Reload
  mov	rsi, rbx
  mov	rcx, r15
  add	rsp, 24
  pop	rbx
  pop	r12
  pop	r13
  pop	r14
  pop	r15
  pop	rbp
  jmp	rax                             # TAILCALL
drop:                                   # @drop
  add	rsi, -1
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
drop_n:                                 # @drop_n
  lea	rax, [rsi - 1]
  sub	rax, qword ptr [rcx + 8*rsi - 8]
  mov	r8, qword ptr [rcx + 8*rdx + 8]
  mov	rsi, rax
  jmp	r8                              # TAILCALL
eval_pith:                              # @eval_pith
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
depth_pp:                               # @depth_pp
  add	qword ptr [rcx + 24], 1
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
depth_mm:                               # @depth_mm
  add	qword ptr [rcx + 24], -1
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
run:                                    # @run
  cmp	qword ptr [rdi - 24], 1146048069
  jne	.LBB24_2
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  xor	esi, esi
  jmp	rax                             # TAILCALL
.LBB24_2:
  mov	rax, qword ptr [rip + os_unsoll_free]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
cont_eval:                              # @cont_eval
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi - 8], rax
  mov	qword ptr [rcx + 8*rsi], r8
  lea	rax, [rip + depth_mm]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + and2]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  lea	r8, [rsi + 4]
  lea	rax, [rip + coll]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
coll:                                   # @coll
  mov	rax, qword ptr [rcx + 8*rsi - 16]
  mov	rdi, qword ptr [rcx + 8*rsi - 8]
  add	rsi, -2
  jmp	rax                             # TAILCALL
is_true_pith:                           # @is_true_pith
  push	r15
  push	r14
  push	r13
  push	r12
  push	rbx
  mov	r14, rcx
  mov	rbx, rdi
  mov	rax, qword ptr [rdi - 16]
  sub	rax, qword ptr [rcx + 16]
  mov	r15, rdx
  mov	r12, rsi
  mov	r13, qword ptr [rdi + 8*rax]
  mov	qword ptr [rdi + 8*rax], 1970632053
  cmp	r13, 1970632053
  jne	.LBB29_2
  lea	rdi, [rip + .L.str.5]
  xor	eax, eax
  call	qword ptr [rip + print]
.LBB29_2:
  xor	eax, eax
  cmp	r13, 1970632053
  sete	al
  add	rax, r15
  mov	rax, qword ptr [r14 + 8*rax]
  mov	rdi, rbx
  mov	rsi, r12
  mov	rdx, r15
  mov	rcx, r14
  pop	rbx
  pop	r12
  pop	r13
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
thenS:                                  # @thenS
  mov	qword ptr [rcx + 8*rsi], 1
  lea	rax, [rip + thenS_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	r8, [rsi + 3]
  lea	rax, [rip + thenS_n_n]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
orelse:                                 # @orelse
  mov	qword ptr [rcx + 8*rsi], 1
  lea	rax, [rip + orelse_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	r8, [rsi + 3]
  lea	rax, [rip + orelse_n_n]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
orelse3:                                # @orelse3
  mov	qword ptr [rcx + 8*rsi], 3
  lea	rax, [rip + orelse_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	r8, [rsi + 3]
  lea	rax, [rip + orelse_n_n]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
orelse5:                                # @orelse5
  mov	qword ptr [rcx + 8*rsi], 5
  lea	rax, [rip + orelse_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	r8, [rsi + 3]
  lea	rax, [rip + orelse_n_n]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
term_a:                                 # @term_a
  lea	rax, [rip + .L.str.6]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB37_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 97
  jne	.LBB37_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB37_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
term_b:                                 # @term_b
  lea	rax, [rip + .L.str.7]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB38_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 98
  jne	.LBB38_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB38_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
term_s:                                 # @term_s
  lea	rax, [rip + .L.str.8]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB39_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 115
  jne	.LBB39_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB39_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
sS:                                     # @sS
  lea	rax, [rip + term_s]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	r9, [rip + sS]
  mov	qword ptr [rcx + 8*rsi + 8], r9
  lea	r8, [rip + thenS]
  mov	qword ptr [rcx + 8*rsi + 16], r8
  mov	qword ptr [rcx + 8*rsi + 24], r9
  mov	qword ptr [rcx + 8*rsi + 32], r8
  lea	rax, [rip + empty]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  lea	rax, [rip + orelse]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	qword ptr [rcx + 8*rsi + 56], r9
  mov	qword ptr [rcx + 976], rdi
  lea	rax, [rip + drop]
  mov	qword ptr [rcx + 8*rsi + 64], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 10]
  mov	qword ptr [rcx + 8*rsi + 72], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 80], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
a:                                      # @a
  lea	rax, [rip + .L.str.6]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB41_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 97
  jne	.LBB41_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB41_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
b:                                      # @b
  lea	rax, [rip + .L.str.7]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB42_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 98
  jne	.LBB42_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB42_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
c:                                      # @c
  lea	rax, [rip + .L.str.9]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB43_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 99
  jne	.LBB43_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB43_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
pls:                                    # @pls
  lea	rax, [rip + .L.str.10]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB45_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 43
  jne	.LBB45_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB45_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
mns:                                    # @mns
  lea	rax, [rip + .L.str.11]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB46_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 45
  jne	.LBB46_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB46_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
mul:                                    # @mul
  lea	rax, [rip + .L.str.12]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB47_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 42
  jne	.LBB47_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB47_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
div:                                    # @div
  lea	rax, [rip + .L.str.13]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB48_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 47
  jne	.LBB48_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB48_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
opr:                                    # @opr
  lea	rax, [rip + .L.str.14]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB49_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 40
  jne	.LBB49_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB49_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
cpr:                                    # @cpr
  lea	rax, [rip + .L.str.15]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	r8, qword ptr [rcx + 8*rsi - 16]
  cmp	r8, qword ptr [rcx + 8*rsi - 24]
  jae	.LBB50_3
  mov	rax, qword ptr [rcx + 8*rsi - 32]
  cmp	byte ptr [rax + r8], 41
  jne	.LBB50_3
  add	r8, 1
  mov	qword ptr [rcx + 8*rsi - 16], r8
  mov	qword ptr [rcx + 8*rsi], rdi
  lea	rax, [rip + eval_pith]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
.LBB50_3:
  add	rsi, -4
  mov	rax, qword ptr [rcx + 976]
  mov	qword ptr [rax - 24], 1146048069
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
aTs:                                    # @aTs
  lea	rax, [rip + term_a]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term_s]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	qword ptr [rcx + 8*rsi + 16], 1
  lea	rax, [rip + thenS_n]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  lea	r8, [rsi + 5]
  lea	rax, [rip + thenS_n_n]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
sOs:                                    # @sOs
  lea	rax, [rip + empty]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + term_s]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + orelse]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  lea	rax, [rip + sOs]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  mov	qword ptr [rcx + 976], rdi
  lea	rax, [rip + drop]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	rax, qword ptr [rip + dot]
  lea	r8, [rsi + 6]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
example:                                # @example
  lea	rax, [rip + .L.str.16]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	qword ptr [rcx + 8*rsi + 8], 5
  xorps	xmm0, xmm0
  movups	xmmword ptr [rcx + 8*rsi + 16], xmm0
  lea	rax, [rip + Sa]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  lea	rax, [rip + s_pith]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  lea	r8, [rsi + 7]
  lea	rax, [rip + coll]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 56], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
parse:                                  # @parse
  mov	r9, qword ptr [rcx + 8*rsi - 16]
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  mov	rax, -1
.LBB55_1:                               # =>This Inner Loop Header: Depth=1
  cmp	byte ptr [r9 + rax + 1], 0
  lea	rax, [rax + 1]
  jne	.LBB55_1
  mov	qword ptr [rcx + 8*rsi - 8], rax
  xorps	xmm0, xmm0
  movups	xmmword ptr [rcx + 8*rsi], xmm0
  mov	qword ptr [rcx + 8*rsi + 16], r8
  lea	rax, [rip + s_pith]
  mov	qword ptr [rcx + 8*rsi + 24], rax
  lea	r8, [rsi + 5]
  lea	rax, [rip + coll]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
"მთავარი":                              # @"\E1\83\9B\E1\83\97\E1\83\90\E1\83\95\E1\83\90\E1\83\A0\E1\83\98"
  lea	rax, [rip + .L.str.16]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	qword ptr [rcx + 8*rsi + 8], 5
  xorps	xmm0, xmm0
  movups	xmmword ptr [rcx + 8*rsi + 16], xmm0
  lea	rax, [rip + Sa]
  mov	qword ptr [rcx + 8*rsi + 32], rax
  lea	rax, [rip + s_pith]
  mov	qword ptr [rcx + 8*rsi + 40], rax
  lea	r8, [rsi + 7]
  lea	rax, [rip + coll]
  mov	qword ptr [rcx + 8*rsi + 48], rax
  mov	rax, qword ptr [rip + and]
  mov	qword ptr [rcx + 8*rsi + 56], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
phead:                                  # @phead
  push	r15
  push	r14
  push	r12
  push	rbx
  push	rax
  mov	r15, rcx
  mov	r14, rdx
  mov	rbx, rsi
  mov	r12, rdi
  mov	r8, qword ptr [rcx + 8*rsi - 8]
  mov	rcx, qword ptr [rcx + 8*rsi - 16]
  mov	rsi, qword ptr [r15 + 8*rsi - 32]
  mov	rdx, qword ptr [r15 + 8*rbx - 24]
  add	rbx, -4
  lea	rdi, [rip + .L.str.17]
  xor	eax, eax
  call	qword ptr [rip + print]
  mov	rax, qword ptr [r15 + 8*r14 + 8]
  mov	rdi, r12
  mov	rsi, rbx
  mov	rdx, r14
  mov	rcx, r15
  add	rsp, 8
  pop	rbx
  pop	r12
  pop	r14
  pop	r15
  jmp	rax                             # TAILCALL
cslen:                                  # @cslen
  mov	rax, -1
.LBB58_1:                               # =>This Inner Loop Header: Depth=1
  cmp	byte ptr [rdi + rax + 1], 0
  lea	rax, [rax + 1]
  jne	.LBB58_1
  ret
s_pith:                                 # @s_pith
  lea	rax, [rip + phead]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], 1
  mov	rax, qword ptr [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
init_names:                             # @init_names
  mov	r8, qword ptr [rip + names_i]
  mov	r10, r8
  shl	r10, 4
  lea	r9, [rip + names]
  lea	rax, [rip + empty]
  mov	qword ptr [r10 + r9], rax
  lea	rax, [rip + .L.str.19]
  mov	qword ptr [r10 + r9 + 8], rax
  lea	rax, [rip + term]
  mov	qword ptr [r10 + r9 + 16], rax
  lea	rax, [rip + .L.str.20]
  mov	qword ptr [r10 + r9 + 24], rax
  lea	rax, [rip + orelse_n]
  mov	qword ptr [r10 + r9 + 32], rax
  lea	rax, [rip + .L.str.21]
  mov	qword ptr [r10 + r9 + 40], rax
  lea	rax, [rip + thenS_n]
  mov	qword ptr [r10 + r9 + 48], rax
  lea	rax, [rip + .L.str.22]
  mov	qword ptr [r10 + r9 + 56], rax
  lea	rax, [rip + var]
  mov	qword ptr [r10 + r9 + 64], rax
  lea	rax, [rip + .L.str.23]
  mov	qword ptr [r10 + r9 + 72], rax
  lea	rax, [rip + thenS]
  mov	qword ptr [r10 + r9 + 80], rax
  lea	rax, [rip + .L.str.24]
  mov	qword ptr [r10 + r9 + 88], rax
  lea	rax, [rip + orelse]
  mov	qword ptr [r10 + r9 + 96], rax
  lea	rax, [rip + .L.str.25]
  mov	qword ptr [r10 + r9 + 104], rax
  lea	rax, [rip + orelse3]
  mov	qword ptr [r10 + r9 + 112], rax
  lea	rax, [rip + .L.str.26]
  mov	qword ptr [r10 + r9 + 120], rax
  lea	rax, [rip + orelse5]
  mov	qword ptr [r10 + r9 + 128], rax
  lea	rax, [rip + .L.str.27]
  mov	qword ptr [r10 + r9 + 136], rax
  lea	rax, [rip + a]
  mov	qword ptr [r10 + r9 + 144], rax
  lea	rax, [rip + .L.str.6]
  mov	qword ptr [r10 + r9 + 152], rax
  lea	rax, [rip + b]
  mov	qword ptr [r10 + r9 + 160], rax
  lea	rax, [rip + .L.str.7]
  mov	qword ptr [r10 + r9 + 168], rax
  lea	rax, [rip + Sa]
  mov	qword ptr [r10 + r9 + 176], rax
  lea	rax, [rip + .L.str.28]
  mov	qword ptr [r10 + r9 + 184], rax
  lea	rax, [rip + pls]
  mov	qword ptr [r10 + r9 + 192], rax
  lea	rax, [rip + .L.str.29]
  mov	qword ptr [r10 + r9 + 200], rax
  lea	rax, [rip + mns]
  mov	qword ptr [r10 + r9 + 208], rax
  lea	rax, [rip + .L.str.30]
  mov	qword ptr [r10 + r9 + 216], rax
  lea	rax, [rip + mul]
  mov	qword ptr [r10 + r9 + 224], rax
  lea	rax, [rip + .L.str.31]
  mov	qword ptr [r10 + r9 + 232], rax
  lea	rax, [rip + div]
  mov	qword ptr [r10 + r9 + 240], rax
  lea	rax, [rip + .L.str.32]
  mov	qword ptr [r10 + r9 + 248], rax
  lea	rax, [rip + opr]
  mov	qword ptr [r10 + r9 + 256], rax
  lea	rax, [rip + .L.str.33]
  mov	qword ptr [r10 + r9 + 264], rax
  lea	rax, [rip + cpr]
  mov	qword ptr [r10 + r9 + 272], rax
  lea	rax, [rip + .L.str.34]
  mov	qword ptr [r10 + r9 + 280], rax
  lea	rax, [rip + Exp]
  mov	qword ptr [r10 + r9 + 288], rax
  lea	rax, [rip + .L.str.35]
  mov	qword ptr [r10 + r9 + 296], rax
  lea	rax, [rip + term_a]
  mov	qword ptr [r10 + r9 + 304], rax
  lea	rax, [rip + .L.str.36]
  mov	qword ptr [r10 + r9 + 312], rax
  lea	rax, [rip + term_b]
  mov	qword ptr [r10 + r9 + 320], rax
  lea	rax, [rip + .L.str.37]
  mov	qword ptr [r10 + r9 + 328], rax
  lea	rax, [rip + term_s]
  mov	qword ptr [r10 + r9 + 336], rax
  lea	rax, [rip + .L.str.38]
  mov	qword ptr [r10 + r9 + 344], rax
  lea	rax, [rip + sS]
  mov	qword ptr [r10 + r9 + 352], rax
  lea	rax, [rip + .L.str.39]
  mov	qword ptr [r10 + r9 + 360], rax
  lea	rax, [rip + aTs]
  mov	qword ptr [r10 + r9 + 368], rax
  lea	rax, [rip + .L.str.40]
  mov	qword ptr [r10 + r9 + 376], rax
  lea	rax, [rip + sOs]
  mov	qword ptr [r10 + r9 + 384], rax
  lea	rax, [rip + .L.str.41]
  mov	qword ptr [r10 + r9 + 392], rax
  add	r8, 25
  mov	qword ptr [rip + names_i], r8
  mov	rax, qword ptr [rcx + 8*rdx + 8]
  jmp	rax                             # TAILCALL
"Δ4_C2":                                # @"\CE\944_C2"
  mov	rax, qword ptr [rcx + 8*rdx + 48]
  add	rdx, 4
  jmp	rax                             # TAILCALL
"Δ3_SO1_O":                             # @"\CE\943_SO1_O"
  mov	rax, qword ptr [rcx + 8*rdx + 24]
  add	rdx, 4
  mov	qword ptr [rcx + 8*rsi], rax
  jmp	rax                             # TAILCALL
"Δ4_C0":                                # @"\CE\944_C0"
  mov	rax, qword ptr [rcx + 8*rdx + 32]
  add	rdx, 4
  jmp	rax                             # TAILCALL
"Δ7_C2":                                # @"\CE\947_C2"
  mov	rax, qword ptr [rcx + 8*rdx + 72]
  add	rdx, 7
  jmp	rax                             # TAILCALL
"Δ3_SO1_D3_O":                          # @"\CE\943_SO1_D3_O"
  mov	rax, qword ptr [rcx + 8*rdx + 24]
  mov	qword ptr [rcx + 8*rsi], rax
  add	rdx, 7
  jmp	rax                             # TAILCALL
"Δ4_SO3_O":                             # @"\CE\944_SO3_O"
  mov	rax, qword ptr [rcx + 8*rdx + 32]
  mov	qword ptr [rcx + 8*rsi], rax
  mov	rax, qword ptr [rcx + 8*rdx + 40]
  lea	r8, [rsi + 2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  mov	rax, qword ptr [rcx + 8*rdx + 48]
  add	rdx, 7
  mov	qword ptr [rcx + 8*rsi + 16], rax
  mov	rsi, r8
  jmp	rax                             # TAILCALL
expimp_54:                              # @expimp_54
  lea	rax, [rip + .L.str.43]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + or4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_53]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_53:                              # @expimp_53
  lea	rax, [rip + .L.str.44]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + or3]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_52]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_52:                              # @expimp_52
  lea	rax, [rip + .L.str.45]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + or2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_51]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_51:                              # @expimp_51
  lea	rax, [rip + .L.str.46]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_50]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_50:                              # @expimp_50
  lea	rax, [rip + .L.str.47]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + andor5]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_49]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_49:                              # @expimp_49
  lea	rax, [rip + .L.str.48]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + andor4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_48]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_48:                              # @expimp_48
  lea	rax, [rip + .L.str.49]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + andor2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_47]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_47:                              # @expimp_47
  lea	rax, [rip + .L.str.50]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + andor]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_46]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_46:                              # @expimp_46
  lea	rax, [rip + .L.str.51]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and7or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_45]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_45:                              # @expimp_45
  lea	rax, [rip + .L.str.52]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and7]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_44]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_44:                              # @expimp_44
  lea	rax, [rip + .L.str.53]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and6or4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_43]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_43:                              # @expimp_43
  lea	rax, [rip + .L.str.54]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and5or4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_42]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_42:                              # @expimp_42
  lea	rax, [rip + .L.str.55]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and5or3]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_41]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_41:                              # @expimp_41
  lea	rax, [rip + .L.str.56]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and5or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_40]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_40:                              # @expimp_40
  lea	rax, [rip + .L.str.57]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and5]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_39]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_39:                              # @expimp_39
  lea	rax, [rip + .L.str.58]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and4or2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_38]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_38:                              # @expimp_38
  lea	rax, [rip + .L.str.59]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and4or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_37]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_37:                              # @expimp_37
  lea	rax, [rip + .L.str.60]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_36]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_36:                              # @expimp_36
  lea	rax, [rip + .L.str.61]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and3or4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_35]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_35:                              # @expimp_35
  lea	rax, [rip + .L.str.62]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and3or3]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_34]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_34:                              # @expimp_34
  lea	rax, [rip + .L.str.63]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and3or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_33]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_33:                              # @expimp_33
  lea	rax, [rip + .L.str.64]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and3]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_32]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_32:                              # @expimp_32
  lea	rax, [rip + .L.str.65]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or7]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_31]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_31:                              # @expimp_31
  lea	rax, [rip + .L.str.66]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or5]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_30]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_30:                              # @expimp_30
  lea	rax, [rip + .L.str.67]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or4]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_29]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_29:                              # @expimp_29
  lea	rax, [rip + .L.str.68]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or3]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_28]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_28:                              # @expimp_28
  lea	rax, [rip + .L.str.69]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_27]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_27:                              # @expimp_27
  lea	rax, [rip + .L.str.70]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2or]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_26]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_26:                              # @expimp_26
  lea	rax, [rip + .L.str.71]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_25]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_25:                              # @expimp_25
  lea	rax, [rip + .L.str.72]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + and]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_23]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_23:                              # @expimp_23
  lea	rax, [rip + .L.str.73]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_wordump]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_22]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_22:                              # @expimp_22
  lea	rax, [rip + .L.str.74]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_unsoll_free]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_21]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_21:                              # @expimp_21
  lea	rax, [rip + .L.str.75]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_unsoll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_20]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_20:                              # @expimp_20
  lea	rax, [rip + .L.str.76]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_soll_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_19]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_19:                              # @expimp_19
  lea	rax, [rip + .L.str.77]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_soll_free]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_18]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_18:                              # @expimp_18
  lea	rax, [rip + .L.str.78]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_soll_dup]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_17]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_17:                              # @expimp_17
  lea	rax, [rip + .L.str.79]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_soll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_16]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_16:                              # @expimp_16
  lea	rax, [rip + .L.str.80]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_queue_soll]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_15]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_15:                              # @expimp_15
  lea	rax, [rip + .L.str.81]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_queue_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_14]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_14:                              # @expimp_14
  lea	rax, [rip + .L.str.82]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_queue_clear]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_13]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_13:                              # @expimp_13
  lea	rax, [rip + .L.str.83]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + os_call_n]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_12]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_12:                              # @expimp_12
  lea	rax, [rip + .L.str.84]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + nar]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_11]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_11:                              # @expimp_11
  lea	rax, [rip + .L.str.85]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + got]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_10]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_10:                              # @expimp_10
  lea	rax, [rip + .L.str.86]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + gor]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_9]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_9:                               # @expimp_9
  lea	rax, [rip + .L.str.87]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + god]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_8]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_8:                               # @expimp_8
  lea	rax, [rip + .L.str.88]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + dot]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_7]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_7:                               # @expimp_7
  lea	rax, [rip + .L.str.89]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + debugger]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_6]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_6:                               # @expimp_6
  lea	rax, [rip + .L.str.90]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + co2]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_5]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_5:                               # @expimp_5
  lea	rax, [rip + .L.str.91]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + co1]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_4]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_4:                               # @expimp_4
  lea	rax, [rip + .L.str.92]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + co0]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + expimp_3]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
expimp_3:                               # @expimp_3
  lea	rax, [rip + .L.str.93]
  mov	qword ptr [rcx + 8*rsi], rax
  lea	rax, [rip + print]
  mov	qword ptr [rcx + 8*rsi + 8], rax
  lea	rax, [rip + "πrn"]
  mov	qword ptr [rcx + 8*rsi + 16], rax
  add	rsi, 3
  mov	rax, qword ptr [rcx + 8*rdx]
  jmp	rax                             # TAILCALL
"πrn":                                  # @"\CF\80rn"
  mov	byte ptr [rip + "ιmported"], 1
  lea	rax, [rip + init_names]
  mov	qword ptr [rcx + 8*rsi], rax
  jmp	init_names                      # TAILCALL
  .local	"ιmported"
  .comm	"ιmported",1,4
  .local	print
  .comm	print,8,8
  .section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
  .asciz	"%s"

.L.str.1:
  .asciz	"%ld"

.L.str.2:
  .asciz	"\n"

.L.str.3:
  .asciz	"%lu"

.L.str.4:
  .asciz	"%s "

  .local	os_unsoll
  .comm	os_unsoll,8,8
  .local	dot
  .comm	dot,8,8
  .local	and
  .comm	and,8,8
  .local	os_unsoll_free
  .comm	os_unsoll_free,8,8
  .local	os_soll_n
  .comm	os_soll_n,8,8
  .local	os_queue_soll
  .comm	os_queue_soll,8,8
  .local	and2
  .comm	and2,8,8
.L.str.5:
  .asciz	"true pith\n"

  .local	and2or3
  .comm	and2or3,8,8
.L.str.6:
  .asciz	"a"

.L.str.7:
  .asciz	"b"

.L.str.8:
  .asciz	"s"

.L.str.9:
  .asciz	"c"

.L.str.10:
  .asciz	"+"

.L.str.11:
  .asciz	"-"

.L.str.12:
  .asciz	"*"

.L.str.13:
  .asciz	"/"

.L.str.14:
  .asciz	"("

.L.str.15:
  .asciz	")"

.L.str.16:
  .asciz	"baaaa"

.L.str.17:
  .asciz	"B input:%s len:%lu pos:%lu depth:%lu\n"

  .bss
names_i:
  .quad	0                               # 0x0

names:
  .zero	16384

  .section	.rodata.str1.1,"aMS",@progbits,1
.L.str.18:
  .asciz	"n/a"

.L.str.19:
  .asciz	"empty"

.L.str.20:
  .asciz	"term"

.L.str.21:
  .asciz	"orelse_n"

.L.str.22:
  .asciz	"thenS_n"

.L.str.23:
  .asciz	"var"

.L.str.24:
  .asciz	"thenS"

.L.str.25:
  .asciz	"orelse"

.L.str.26:
  .asciz	"orelse3"

.L.str.27:
  .asciz	"orelse5"

.L.str.28:
  .asciz	"Sa"

.L.str.29:
  .asciz	"pls"

.L.str.30:
  .asciz	"mns"

.L.str.31:
  .asciz	"mul"

.L.str.32:
  .asciz	"div"

.L.str.33:
  .asciz	"opr"

.L.str.34:
  .asciz	"cpr"

.L.str.35:
  .asciz	"Exp"

.L.str.36:
  .asciz	"term_a"

.L.str.37:
  .asciz	"term_b"

.L.str.38:
  .asciz	"term_s"

.L.str.39:
  .asciz	"sS"

.L.str.40:
  .asciz	"aTs"

.L.str.41:
  .asciz	"sOs"

.L.str.42:
  .asciz	"or5"

  .local	or5
  .comm	or5,8,8
.L.str.43:
  .asciz	"or4"

  .local	or4
  .comm	or4,8,8
.L.str.44:
  .asciz	"or3"

  .local	or3
  .comm	or3,8,8
.L.str.45:
  .asciz	"or2"

  .local	or2
  .comm	or2,8,8
.L.str.46:
  .asciz	"or"

  .local	or
  .comm	or,8,8
.L.str.47:
  .asciz	"andor5"

  .local	andor5
  .comm	andor5,8,8
.L.str.48:
  .asciz	"andor4"

  .local	andor4
  .comm	andor4,8,8
.L.str.49:
  .asciz	"andor2"

  .local	andor2
  .comm	andor2,8,8
.L.str.50:
  .asciz	"andor"

  .local	andor
  .comm	andor,8,8
.L.str.51:
  .asciz	"and7or"

  .local	and7or
  .comm	and7or,8,8
.L.str.52:
  .asciz	"and7"

  .local	and7
  .comm	and7,8,8
.L.str.53:
  .asciz	"and6or4"

  .local	and6or4
  .comm	and6or4,8,8
.L.str.54:
  .asciz	"and5or4"

  .local	and5or4
  .comm	and5or4,8,8
.L.str.55:
  .asciz	"and5or3"

  .local	and5or3
  .comm	and5or3,8,8
.L.str.56:
  .asciz	"and5or"

  .local	and5or
  .comm	and5or,8,8
.L.str.57:
  .asciz	"and5"

  .local	and5
  .comm	and5,8,8
.L.str.58:
  .asciz	"and4or2"

  .local	and4or2
  .comm	and4or2,8,8
.L.str.59:
  .asciz	"and4or"

  .local	and4or
  .comm	and4or,8,8
.L.str.60:
  .asciz	"and4"

  .local	and4
  .comm	and4,8,8
.L.str.61:
  .asciz	"and3or4"

  .local	and3or4
  .comm	and3or4,8,8
.L.str.62:
  .asciz	"and3or3"

  .local	and3or3
  .comm	and3or3,8,8
.L.str.63:
  .asciz	"and3or"

  .local	and3or
  .comm	and3or,8,8
.L.str.64:
  .asciz	"and3"

  .local	and3
  .comm	and3,8,8
.L.str.65:
  .asciz	"and2or7"

  .local	and2or7
  .comm	and2or7,8,8
.L.str.66:
  .asciz	"and2or5"

  .local	and2or5
  .comm	and2or5,8,8
.L.str.67:
  .asciz	"and2or4"

  .local	and2or4
  .comm	and2or4,8,8
.L.str.68:
  .asciz	"and2or3"

.L.str.69:
  .asciz	"and2or2"

  .local	and2or2
  .comm	and2or2,8,8
.L.str.70:
  .asciz	"and2or"

  .local	and2or
  .comm	and2or,8,8
.L.str.71:
  .asciz	"and2"

.L.str.72:
  .asciz	"and"

.L.str.73:
  .asciz	"os_wordump"

  .local	os_wordump
  .comm	os_wordump,8,8
.L.str.74:
  .asciz	"os_unsoll_free"

.L.str.75:
  .asciz	"os_unsoll"

.L.str.76:
  .asciz	"os_soll_n"

.L.str.77:
  .asciz	"os_soll_free"

  .local	os_soll_free
  .comm	os_soll_free,8,8
.L.str.78:
  .asciz	"os_soll_dup"

  .local	os_soll_dup
  .comm	os_soll_dup,8,8
.L.str.79:
  .asciz	"os_soll"

  .local	os_soll
  .comm	os_soll,8,8
.L.str.80:
  .asciz	"os_queue_soll"

.L.str.81:
  .asciz	"os_queue_n"

  .local	os_queue_n
  .comm	os_queue_n,8,8
.L.str.82:
  .asciz	"os_queue_clear"

  .local	os_queue_clear
  .comm	os_queue_clear,8,8
.L.str.83:
  .asciz	"os_call_n"

  .local	os_call_n
  .comm	os_call_n,8,8
.L.str.84:
  .asciz	"nar"

  .local	nar
  .comm	nar,8,8
.L.str.85:
  .asciz	"got"

  .local	got
  .comm	got,8,8
.L.str.86:
  .asciz	"gor"

  .local	gor
  .comm	gor,8,8
.L.str.87:
  .asciz	"god"

  .local	god
  .comm	god,8,8
.L.str.88:
  .asciz	"dot"

.L.str.89:
  .asciz	"debugger"

  .local	debugger
  .comm	debugger,8,8
.L.str.90:
  .asciz	"co2"

  .local	co2
  .comm	co2,8,8
.L.str.91:
  .asciz	"co1"

  .local	co1
  .comm	co1,8,8
.L.str.92:
  .asciz	"co0"

  .local	co0
  .comm	co0,8,8
.L.str.93:
  .asciz	"printf"

.L.str.94:
  .asciz	"\341\203\233\341\203\227\341\203\220\341\203\225\341\203\220\341\203\240\341\203\230"

  .ident	"clang version 13.0.1"
  .section	".note.GNU-stack","",@progbits

