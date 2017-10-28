#include <stdio.h>
#include <string.h>


void numberConvert(int num, int dst, char result[])
{
	int i = 0;

	
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	while(num > 0 ) {
		result[i] = hex[num % dst];
		num = num / dst;
		i++;
	}
	strrev(result);
}


int main(int argc, char *argv[])
{
	/*number to convert*/
	int num = 0;
	/*destined numeral system*/
	int dst = 0;
	/*result as a string*/
	char result[50] = {0};

	printf("Geben sie die Ausgangszahl ein : ");
	scanf("%d", &num);

	if(num < 0){
		printf("Ausgangszahl '%d' wird als '%d' gewertet !\n",num ,abs(num));
		num = abs(num);
	}

	printf("In welches Zahlensystem soll umgerechnet werden? : ");
	scanf("%d", &dst);

	/* if(dst == 2 || dst == 8 || dst == 16){	
	numberConvert(num, dst, result);	
	} else {
		printf("Bitte nur das Binaer/Oktal oder Hexasystem benutzen!\n");
		
	} */
    
    while(dst != 2 || dst != 8 || dst !=16) {
    	if ( (dst == 2) || (dst == 8) || (dst == 16) ){
    		numberConvert(num, dst, result);
    		break;
		}
    	    printf("Bitte nur das Binaer(2)/Oktal(8) oder Hexasystem(16) benutzen!\n");
    		printf("In welches Zahlensystem soll umgerechnet werden? : ");
	        scanf("%d", &dst); 
	}

	if(dst == 16){
		printf("Die Ergebniszahl lautet: 0x%s\n", result);
	} else {
		printf("Die Ergebniszahl lautet: %s\n", result);
	}
	return 0;
}
