#include <stdio.h>

 main() 
 {
 	
  int waehrung, wechselwaehrung, auswahl;
  float betrag;
  float gbp = 0.884, usd = 1.20, eur = 1.0;
  
  
  gbpdoll=usd/gbp;

printf("1 Euro zu US$ Kurs: %f\n",usd);

printf("1 Euro zu GBP Kurs: %f\n",gbp);

printf("Was ist Ihre Ausgangswaehrung?\n 1.Euro\n 2.US$\n 3.GBP\n"); 
scanf("%d",&waehrung);

/* Beträge einlesen + welche Währung ausgewählt wurde */

switch (waehrung) {
	
	case 1: 
	        printf("Welchen Euro-Betrag wollen Sie wechseln?\n");
            scanf("%f",&betrag);
            auswahl = 1;
	break;	    
	
	
	case 2: 
	        printf("Welchen US$-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);
	        auswahl = 2;			
	break;
	
	
	case 3: 
	        printf("Welchen GBP-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);
	        auswahl = 3;				
	break;
	
	
	default: 
	        printf("Falsche Eingabe.");	
		
}

printf("In welche Waehrung wollen Sie wechseln?\n 1.Euro\n 2.US$\n 3.GBP\n");
scanf("%d",&wechselwaehrung);

switch (wechselwaehrung) {
	
	/*Ausgabe in Euro*/
    case 1: 
	        if(auswahl == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag);
	   }
    
	        else if(auswahl == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", betrag / usd);
	   }
      
            else if(auswahl == 3) {/*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n", betrag / gbp);
	   }
	break;
	
	
	/*Ausgabe in Dollar*/
	case 2: 
	        if(auswahl == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag * usd);
	   }
      
	        else if(auswahl == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", betrag);
	   }
    
	        else if(auswahl == 3){ /*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n",betrag*(usd/gbp));
	   }
	break;


 	/*Ausgabe in GBP*/
	case 3: 
	        if(auswahl == 1){ /*Eingabe in EUR*/
	          printf("Sie erhalten dafuer %f\n", betrag*gbp);
	   }

	        else if(auswahl == 2){ /*Eingabe in Dollar*/
	          printf("Sie erhalten dafuer %f\n", (betrag / usd)*gbp);
	   }
   
            else if(auswahl == 3){ /*Eingabe in GBP*/
	          printf("Sie erhalten dafuer %f\n", betrag);
       }
	break;

	default: 
	printf("Falsche Eingabe.");	
    
} 

}
