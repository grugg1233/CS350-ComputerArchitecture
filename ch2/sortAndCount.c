

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int pos[26];  

void swap(int* a, int *b ){
    *a^=*b; 
    *b^=*a;
    *a^=*b;
}

void bub(int a[]) {

    for ( int i = 0 ; i < 26; i++) {
        pos[i] = i;
    }
    for (int i = 0 ; i < 26 ; i ++ ) { 
        for(int j = i + 1 ; j < 26 ; j++ ) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swap(&pos[i], &pos[j]);}
        }
    }
    
}

int main()
{
    int base = (int) 'A';
    int alpahbetMap[26] = {0};
    char* str =  "MOBUEWO LI QOUOYNYVA PZYF BOPPOQ IEC GQO EVO ES PZO SOM UZEFOV PE NYFYP CF GP PZO SYSPZ VOJP WEVPZ GVK PGDO TGQP ES PZO OBOUPYEV TQEUOFF MO ZETO PZGP IEC ZGNO PZO TEFFYLYBYPI PE AYNO CF PZO TBOGFCQO ES IECQ UEWTGVI GVK PZGP IEC GUUOTP PZO ZEVECQ GF MOBB GF PZO QOFTEVFYLYBYPI ES PZYF GFFYAVWOVP PZYF IOGQ PZO WOOPYVA MYBB PGDO TBGUO GP DOVFYVAPEV VYVO PGDO PZO LCF PZQOO ZCVKQOK PMOBNO FONOV FPGPYEVF SQEW PZO UOVPQGB DOOT PZO GKKQOFF GF MOBB GF PZO KGI G FOUQOP LOFP QOAGQKF";
    for (int c = 0 ; c < strlen(str); c++) {
            int ch = (int) str[c]; 
            alpahbetMap[ch - base] += 1; 
    }
    

    bub(alpahbetMap);
    
    for (int i =0 ; i < 26; i++)
        printf("%c : %d\n", pos[i] + 'A', alpahbetMap[i]);
        // printf("%d\n", pos[i]);
    
    
    return 0;
}