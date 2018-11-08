/* P5.c */
/* lana_paula */
/* 11811EEL043 */

#include <stdio.h>

typedef unsigned long long int Bytes8; 
typedef struct LCG { Bytes8 a, c, m, rand_max, atual; } LCG;

void semente(LCG * r, Bytes8 seed)
{ 
    r->a = 0x5DEECE66DULL; 
    r->c = 11ULL; 
    r->m = (1ULL << 48); 
    r->rand_max = r->m - 1; 
    r->atual = seed; 
} 

Bytes8 lcg_rand(LCG * r) 
{ 
    r->atual = (r->a * r->atual + r->c) % r->m; 
    return r->atual; 
} 

double lcg_rand_01(LCG * r) 
{ 
    return ((double) lcg_rand(r))/(r->rand_max); 
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r) 
{ 
    int i; 
    for(i = 0; i < tam; i++) 
    	vetor[i] = (max-min)*lcg_rand_01(r) + min; 
}

float soma_vet (float num[], float i, float f, int p, int n)
{
    if(p < n)
	{
        f = i + num[p];
    		return soma_vet(num, f, f, p+1, n);
    }
    else
	{
    	return f;
    }
}

float produto (float num[], float i, float f, int p, int n)
{
    if(p < n)
	{
    	f = i * num[p];
        	return produto(num, f, f, p+1, n);
    }
    else
	{
        return f;
    }
}

int main()
{
	LCG random;	semente(&random, 123456); 
	int menu, n=50;
	float num[50];
	gera_numeros(num, n, 0.5, 1.5, &random);
	do
	{
		printf("\n-------MENU--------\n\n");
		printf("1 - Somatorio.\n2 - Produtorio.\n3 - Sair do programa.\n>");
		scanf("%d", &menu);	
		getchar();
		switch(menu)
		{
			case 1:
				printf("\nSomatorio: %f \n\n\n\n", soma_vet(num, 0, 0, 0, n));
				break;
			case 2:
				printf("\nProduto: %f \n\n\n\n", produto(num, 1, 0, 0, n));
				break;
			case 3:
				return 0;
			default:
				break;
		}	
	}
	while(menu != 4);
return 0;
}
