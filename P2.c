/* P2.c */
/* lana_paula */
/* 11811EEL043 */
#include <stdio.h>

void preenche(char bits[])
{
	printf("\nDigite o numero que deseja converter: ");
	scanf("%s", bits);
}
int basedec(char bits[], int b) 
{
	int i=0, aux=0;
	for(i=0; bits[i]!='\0'; i++)
	{
	    if (bits[i]<=57 && bits[i]>=48)
	    {
            aux=aux*b+(bits[i] - '0');
	    }
        else if (bits[i]>=65)
        {
            {
        	    if (bits[i]>=97)
    	        {
    	        	bits[i]-=32;
    	        	aux=aux*b+(bits[i] - '7');
				}
    	        else
        	        aux=aux*b+(bits[i] - '7');
		    }
	    }
    }
    return aux;
}
int basebin(int num, int b)
{
	char bin[256];
	int i=0, j=0, k=1, n=0, aux=0, aux2;
	for (n=0; num>=(1<<n); n++);
	for (i=1; i<=n; i++)
	{
		if (num%2==0)
		{
			bin[n-i]='0';
			num=num/2;
		}
		else
		{
			bin[n-i]='1';
			num=(num-1)/2;
		}
	}
	for (i=0; bin[i]!='\0'; i++)
	{
		k=1;
		for(j=1; j<(n-i); j++)
		    k=k*b;
		aux+=(bin[i] - '0')*(k);
	}
    return aux;
}
void basehex(int num, int b, int menu)
{
	int i=0, j=0, k=0, aux=0, n=0;
	char hex[256], temp[256];
	k=num;
	while (k!=0)
	{
		aux=k%b;
		if (aux<10)
			temp[j++]=48+aux;
		else
		    temp[j++]=55+aux;
		k=k/b;
		n++;
	}
	for (i=n-1, j=0; i+1!=0; --i, ++j)
		hex[j]=temp[i];
	hex[n]='\0';
	printf("\n| \"%i\" + \"%i\" | \"%s\"|\n", menu, num, hex);
}
int baseoct(int num, int b)
{
    int aux=0, i=1;
    while (num!=0)
    {
        aux+=(num%b)*i;
        num/=b;
        i*=10;
    }
    return aux;
}

int main()
{
	char bits[256];
	int menu=0, b=0, cv=0, num=0, test=0;
	do
	{
		printf("\n\n-----------Menu-----------\n");
		printf("Escolha uma opcao: \n");
		printf("1 - Binario para Decimal \n2 - Binario para Hexadecimal \n3 - Haxadecimal para Decimal \n4 - Hexadecimal para Binario \n5- Decimal para Binario \n6- Decimal para Hexadecimal \n7 - Octal para decimal \n8 - Decimal para octal \n9 - Sair.");
		scanf("%i", &menu);
		switch (menu)
		{
			case 1: 
				b=2;
				preenche(bits);
                cv=basedec(bits, b);
				printf("\n| \"%i\" + \"%s\" | \"%i\" |\n", menu, bits, cv);
				break;
			case 2: 
			    b=2;
			    preenche(bits);
			    num=basedec(bits, b);
			    b=16;
                basehex(num, b, menu);
				break;
			case 3: 
				b=16;
				preenche(bits);
                cv=basedec(bits, b);
				printf("\n| \"%i\" + \"%s\" | \"%i\" |\n", menu, bits, cv);
				break;
			case 4: 
				b=16;
				preenche(bits);
				num=basedec(bits, b);
				b=10;
				cv=basebin(num, b);
				printf("\n| \"%i\" + \"%s\" | \"%i\" |\n", menu, bits, cv);
				num=0;
				break;
			case 5: 
				b=10;
				printf("\nDigite o numero que deseja converter: ");
	            scanf("%i", &num);
                cv=basebin(num, b);
				printf("\n| \"%i\" + \"%i\" | \"%i\" |\n", menu, num, cv);
				break;
			case 6: 
			    b=16;
			    printf("\nDigite o numero que deseja converter: ");
	            scanf("%i", &num);
                basehex(num, b, menu);
				break;
			case 7: 
				b=8;
				preenche(bits);
                cv=basedec(bits, b);
				printf("\n| \"%i\" + \"%s\" | \"%i\" |\n", menu, bits, cv);
				break;
			case 8: 
			    b=8;
			    printf("\nDigite o numero que deseja converter: ");
            	scanf("%i", &num);
			    cv=baseoct(num, b);
			    printf("\n| \"%i\" + \"%i\" | \"%i\" |\n", menu, num, cv);
				break;
			default: 
			    if(menu!=9)
			    {
			    	printf("\n\nEscolha invalida!\n\n");
			        break;
				}
		}
	}while (menu!=9);
	return 0;
}
