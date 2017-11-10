#include <stdio.h>
#define KeyN 10
#define Hlen 14
#define Max 9999
#define H1 key[i] % 11
#define H2 key[i] % 9 + 1

typedef int Elemtype;

void creatHash(Elemtype key[KeyN], Elemtype HF[Hlen], Elemtype poli[Hlen])
{
	int i, d, h2, PoliTime;
	for(i = 0; i < KeyN; i++)
	{
		d = H1;
		PoliTime = 0;
		h2 = H2;
		while(HF[d] != Max)
		{
			d = (d + h2) % Hlen;
			PoliTime++;
			h2++;
		}
		HF[d] = key[i];
		poli[d] = PoliTime;
	}
}

void main()
{
	int i, s = 0;
	Elemtype KEY[KeyN] = {12,13,25,23,38,34,6,84,91,92};
	Elemtype HF[Hlen], POLI[Hlen] = {0};
	printf("   Key:");
	for(i = 0; i < KeyN; i++) {
		printf("%5d", KEY[i]);
	}
	printf("\n\nAddres:");
	for(i = 0; i < Hlen; i++) {
		HF[i] = Max;
		printf("%5d", i);
	}
	printf("\n  Hash:");
	creatHash(KEY, HF, POLI);
	for(i = 0; i < Hlen; i++) {
		if(HF[i] != Max) {
			printf("%5d", HF[i]);
		} else {
			printf("     ");
		}
	}
	printf("\n  Poli:");
	for(i = 0; i < Hlen; i++) {
		if(HF[i] != Max) {
			printf("%5d", POLI[i]);
			s += POLI[i] + 1;
		} else {
			printf("     ");
		}
	}
	printf("\n\nASL=%.2f\n\n", (float)s / KeyN);
}
