long switcher(long x, long y, long z) {
    long ret = 0;
    switch (x) {
        case 5:
            ret = 0x1bbe;
            break;  
        case 0:
        case 1: 
            z-=5; 
        case 2:
            ret = z*4; 
            break;
        case 3: 
            z = 0x2; 
        case 7:
            y&=z; 

        case 4: 
        case 6: 
        default:
            ret = 4+y; 
    }
    return ret ; 

}


/*

0000000000000000 <switcher>:
   0:   48 83 ff 07               cmp    $0x7,%rdi          # x - 0x7  
   4:   77 1c                     ja     0x22               # if (x > 7u) goto 0x22; 
   6:   ff 24 fd 30 00 00 00      jmp    *0x30 ; 
   d:   48 83 ea 05               sub    $0x5,%rdx          # z -= 5;
  11:   48 8d 04 95 00 00 00 00   lea    0x0(,%rdx,4),%rax  # long ret = z*4
  19:   c3                        ret                       # return ret ; 
  1a:   ba 02 00 00 00            mov    $0x2,%edx          # z = 0x2 ; 
  1f:   48 21 d6                  and    %rdx,%rsi          # y &= z; 


  22:   48 8d 46 04               lea    0x4(%rsi),%rax     # long ret = 4+y
  26:   c3                        ret                       # return ret
  27:   b8 be 1b 00 00            mov    $0x1bbe,%eax       # long ret = 0x1bbe 
  2c:   c3                        ret                       # return ret

  <jumptable>: 
  30:  0 : 0d 00 00 00 00 00 00 00 # fall through     
       1 : 0d 00 00 00 00 00 00 00 # fall through 
  40:  2 : 11 00 00 00 00 00 00 00 # does break
       3 : 1a 00 00 00 00 00 00 00 # does not break fall through to 7 
  50:  4 : 22 00 00 00 00 00 00 00 # default
       5 : 27 00 00 00 00 00 00 00 # does break 
  60:  6 : 22 00 00 00 00 00 00 00 # default
       7 : 1f 00 00 00 00 00 00 00 # does not break 

*/