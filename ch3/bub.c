#include <stdio.h> 

void main() {
	int a[] = {6,5,4,1,2,3};
	int i = 0 , n =6;
	BUB:
		if ( i > n) goto BREAK;

	OUTLOOP:
		int j =i ;
		if (j > n) goto EINNER;
	INNERLOOP:
		if (a[i]> a[j] ) goto SWAP;

	POSTSWAP:
		j++;
		goto INNERLOOP;
	SWAP:
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
		goto POSTSWAP;
	EINNER:
		i++;
		goto OUTLOOP;
	BREAK:
		if (n>0) goto PARR;
		goto RET;
	PARR:
		int p = 0;
		printf("%d\n", a[p]);
		if(p == n) goto RET;
		goto PARR;
	RET:
		return;
}
