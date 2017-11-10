#include <stdio.h>
#define KeyN 10
#define Hlen 13
#define Max 9999
#define h1 key[i] % 13

typedef int Elemtype;

void creatHash(Elemtype key[KeyN], Elemtype HF[Hlen], Elemtype poli[Hlen])
{
	int i, d, PoliTime;
	for(i = 0; i < KeyN; i++)
	{
		d = h1;
		PoliTime = 0;
		while(HF[d] != Max) {
			d = (d + 1) % Hlen;
			PoliTime++;
		}
		HF[d] = key[i];
		poli[d] = PoliTime;
	}
}

void main()
{
	int i, s = 0;
	Elemtype KEY[KeyN] = {18,16,24,1,78,19,55,10,11,89};
	Elemtype HF[Hlen], POLI[Hlen] = {0};
	printf("   Key:");
	for(i = 0; i < KeyN; i++) {
		printf("%4d", KEY[i]);
	}
	printf("\n\nAddres:");
	for(i = 0; i < Hlen; i++) {
		HF[i] = Max;
		printf("%4d", i);
	}
	printf("\n  Hash:");
	creatHash(KEY, HF, POLI);
	for(i = 0; i < Hlen; i++) {
		if(HF[i] != Max) {
			printf("%4d", HF[i]);
		} else {
			printf("    ");
		}
	}
	printf("\n  Poli:");
	for(i = 0; i < Hlen; i++) {
		if(HF[i] != Max) {
			printf("%4d", POLI[i]);
			s += POLI[i] + 1;
		} else {
			printf("    ");
		}
	}
	printf("\n\nASL=%.2f\n\n", (float)s / KeyN);
}
