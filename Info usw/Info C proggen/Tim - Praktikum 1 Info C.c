#include <stdio.h>

 main() 
 {
 	
  int waehrung, wechselwaehrung;
  float betrag;
  float gbp, usd;
  

  printf("Euro zu US$ Kurs?");
  scanf("%f", &usd);

  printf("Euro zu GBP Kurs?");
  scanf("%f", &gbp);

/*Ausgangswährung wählen/eingeben */
  printf("Was ist Ihre Ausgangswaehrung?\n 1.Euro\n 2.US$\n 3.GBP\n"); 
  scanf("%d",&waehrung);

/* Beträge einlesen */

switch (waehrung) {
	
	case 1: 
	        printf("Welchen Euro-Betrag wollen Sie wechseln?\n");
                scanf("%f",&betrag);          
	break;	    
	
	
	case 2: 
	        printf("Welchen US$-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);       			
	break;
	
	
	case 3: 
	        printf("Welchen GBP-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);       				
	break;
	
	
	default: 
	        printf("Falsche Eingabe.");	
		
}

printf("In welche Waehrung wollen Sie wechseln?\n 1.Euro\n 2.US$\n 3.GBP\n");
scanf("%d",&wechselwaehrung);

switch (wechselwaehrung) {
	
	/*Ausgabe in Euro*/
    case 1: 
	        if(waehrung == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag);
	   }
    
	        else if(waehrung == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", betrag / usd);
	   }
      
            else if(waehrung == 3) {/*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n", betrag / gbp);
	   }
	break;
	
	
	/*Ausgabe in Dollar*/
	case 2: 
	        if(waehrung == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag * usd);
	   }
      
	        else if(waehrung == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", betrag);
	   }
    
	        else if(waehrung == 3){ /*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n",betrag*(usd/gbp));
	   }
	break;


 	/*Ausgabe in GBP*/
	case 3: 
	        if(waehrung == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag*gbp);
	   }

	        else if(waehrung == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", (betrag / usd)*gbp);
	   }
   
            else if(waehrung == 3){ /*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n", betrag);
       }
	break;

	default: 
	printf("Falsche Eingabe.");	
    
} 

return 0;
}
