#include <stdio.h>

short sum(short iter){
	int i = 0;
	short iterCopy = iter;
	while (i < iterCopy){
		iter += iter;
		iter |= i;
		i++;
	}
	return iter;

}

int main() {
	short iter = 4;
	printf("%d", 1 + sum(iter));
	return 0;

}

//%rax - ret
//caller saved : %rdi - 1, %rsi - 2, %rdx, %rcx, %r8, %r9, %r10, %r11 
//callee 
/*
void *rsp;// 0x124
rsp = *(rsp - 24); // 0x100 
*(rsp + 16) = 15213;   
// b (byte) - 8 bit, w (word)  - 16 bit, l (double) - 32 bit, q (quad) - 64 bit

main:
	movw $40, %di  #short iter =40
	call sum	#sum(iter)
	addl $1, %eax  # 1 + sum(iter)
	ret

sum:
	movl $0, %esi #int x = 0
	movw %di, %dx #short iterCopy = iter
.L2:	
	cmp %edx, %esi # iterCopy - i
	jl .L1 #if (i < iterCopy)
	movw %di, %ax
	ret # %rip = line(32)
.L1:
	addw %di, %di # iter += iter
	orl   %esi, %edi # iter |= i 
	addl $1, %esi #i++
	jmp .L2
*/
