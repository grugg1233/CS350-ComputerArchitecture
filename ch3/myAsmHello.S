.global _start
_start:
	movw $4, %di  #short iter =40
	call sum	#sum(iter)
	addl $1, %eax  # 1 + sum(iter)

  movl %eax, %edi # exit(result) 
  movl $60, %eax # syscall: 
  syscall


sum:
	movl $0, %esi #int i = 0
	movw %di, %dx #short iterCopy = iter

.L2:	
  movzwl %dx , %r8d  
	cmp %r8d, %esi # iterCopy - i
	jl .L1 #if (i < iterCopy)
	movzwl %di, %eax
	ret # %rip = line(32)
.L1:
	addw %di, %di # iter += iter
	orl   %esi, %edi # iter |= i 
	addl $1, %esi #i++
	jmp .L2

