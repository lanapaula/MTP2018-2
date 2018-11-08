/* P4.c */
/* lana_paula */
/* 11811EEL043 */

#include <stdio.h>

int Ackermann(int m, int n) 
{
	if(m==0)
	{
		return n+1;
	}
	else if( n==0)
	{
		return Ackermann(m-1, 1);
	}
	else
	{
		return Ackermann(m-1, Ackermann(m, n-1));
	}
}

int main()
{
	int m=0, n=0;
	
	printf("Entre com valores para 'm' e 'n': \n");
	scanf("%i %i", &m, &n);
	getchar();
	
	printf("%i", Ackermann(m,n)); 
	
	return 0;
}
