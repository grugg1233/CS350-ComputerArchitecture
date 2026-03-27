long last(long u, long v) {
    return u*v; 
}

long first( long x ) {
    int y = x+1; 
    x--; 
    return last(x, y);
}

void main() {
    first(10);
    // ...
    return;    
}
/*

Disassembly of last (long u, long v)
u in %rdi, v in %rsi

0000000000400540 <last>:
  400540: 48 89 f8        mov    %rdi,%rax        L1: u
  400543: 48 0f af c6     imul   %rsi,%rax        L2: u*v
  400547: c3              retq                   L3: Return


Disassembly of first (long x)
x in %rdi

0000000000400548 <first>:
  400548: 48 8d 77 01     lea    0x1(%rdi),%rsi   F1: x+1
  40054c: 48 83 ef 01     sub    $0x1,%rdi        F2: x-1
  400550: e8 eb ff ff ff  callq  400540 <last>   F3: Call last(x-1,x+1)
  400555: f3 c3           repz retq              F4: Return


  400560: e8 e3 ff ff ff  callq  400548 <first>  M1: Call first(10)
  400565: 48 89 c2        mov    %rax,%rdx        M2: Resume


*/


/*
Instruction                     State Values (at beginning )

Label     PC      Instruction   %rdi    %rsi    %rax        %rsp                        *%rsp   Description
M1     0x400560     callq        10       --    --          0x7fffffffe820              --      call first(10)
F1     0x400548     lea          10       --     --         0x7fffffffe818             0x400565      x+1
F2     0x40054c     sub          9        11     --         0x7fffffffe818             0x400565      x-1
F3     0x400550     callq        9        11     --         0x7fffffffe818              0x400565    call last( x+1, x-1 )
L1     0x400540     mov          9        11     --         0x7fffffffe810              0x400555    long  z =  u;
L2     0x400543     imul         9        11     9         0x7fffffffe810              0x400555     z*=v ; 
L3     0x400547     retq         9        11     99        0x7fffffffe810              0x400555     return z; 
F4     0x400555     retq         9        11     99        0x7fffffffe818              0x400565     return last(x+1, x-1); 
M2     0x400565     mov          9        11     99         0x7fffffffe820             --          long t = first(10);
*/