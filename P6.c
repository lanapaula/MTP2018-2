/* P6.c */
/* lana_paula */
/* 11811EEL043 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926536

typedef struct 
{
  float x, y;
}Ponto;


int main()
{
	int N, i;
	Ponto *xy;
    printf("Digite o total pontos desejados: ");
    scanf("%i", &N);
    getchar();
    xy= (Ponto *) malloc(N*sizeof(Ponto)); 
    printf("\n");
    for(i=0; i<N; i++)
	{
    	xy->x = cos(i*2.0*PI/(N-1));
     	xy->y = sin(i*2.0*PI/(N-1));
        printf("(%.3f, %.3f) ", xy->x, xy->y);
    }
    printf("\n");
	free(xy);
	return 0;
}
