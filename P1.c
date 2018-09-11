/* P1.c */
/* lana_paula */
/* 11811EEL043 */
#include <stdio.h>

int main()
{
	int i=0, estado = 0;
	char str[256];
	printf("Digite uma sequencia de 0s e 1s: ");
	fflush(stdin);
	scanf("%s", (char *)&str); 
	while(str[i] != '\0')
	{
		if(estado == 0)
		{
        	// SE ESTADO FOR 0
        	if(str[i] == '0')
            	estado = 0;
        	else
                estado = 1;
            //FIM CONDIÇÕES ESTADO == 0
		}
      	else if(estado == 1)
        {
          	// SE ESTADO FOR 1
        	if(str[i] == '0')
            	estado = 2;
        	else
                estado = 0;
          	//FIM CONDIÇÕES ESTADO == 1
        }
      	else if(estado == 2)
        {
          // SE ESTADO FOR 2
          if(str[i] == '0')
            estado = 1;
          else
            estado = 2;
          //FIM CONDIÇÕES ESTADO == 2
        }
      	i++;
	}
  	printf("Estado = %d\n", estado);
  	printf("Sequencia original: %s\n", str);
	if(estado == 0)
		printf("Eh multiplo de 3\n");
  	else
      	printf("Nao eh\n");	
	return 0;	
}
