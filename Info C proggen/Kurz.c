#include <stdio.h>

 main() 
 {

  int ausgangswaehrung, zielwaehrung;
  float betrag;
  float gbp, us$, ca$, euro=1;
   
   printf("Euro zu US$ Kurs:");
   scanf("%f",&us$);
   
   printf("Euro zu GBP Kurs:");
   scanf("%f",&gbp);
   
   printf("Euro zu CA$ Kurs:");
   scanf("%f",&ca$);
   
  printf("Was ist Ihre Ausgangswaehrung?\n 1.Euro\n 2.US$\n 3.GBP\n 4.CA$\n"); 
  scanf("%d",&ausgangswaehrung);
  
  
  switch(ausgangswaehrung){
  
	case 1: 
	        printf("Welchen Euro-Betrag wollen Sie wechseln?\n");
                scanf("%f",&betrag);  
				betrag= betrag / euro ;     
	break;	    
	
	
	case 2: 
	        printf("Welchen US$-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);   
			betrag= betrag / us$;    			
	break;
	
	
	case 3: 
	        printf("Welchen GBP-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);  
			betrag = betrag / gbp;     				
	break;
	
	
	case 4:
	        printf("Welchen Ca$-Betrag wollen Sie wechseln?\n");
	        scanf("%f",&betrag);
	        betrag = betrag / ca$;
	break;  
	
	default:
		printf("Falsche Eingabe.");	
}

  printf("Was ist Ihre Zielwaehrung? \n 1.Euro\n 2.US$\n 3.GBP\n 4.CA$\n");
  scanf("%d",&zielwaehrung);
  
  switch(zielwaehrung){
  	
	case 1: 
	        betrag = betrag*euro;
			printf("Sie erhalten %f Euro",betrag) ;     
	break;	    
	
	
	case 2: 
	        betrag = betrag*us$;
			printf("Sie erhalten %f US$",betrag); 			
	break;
	
	
	case 3: 
	       betrag = betrag*gbp;
		   printf("Sie erhalten %f GBP",betrag);     				
	break;
	
	
	case 4:
	      betrag = betrag*ca$;
	      printf("Sie erhalten %f CA$",betrag);
	break;  
	
	default:
		printf("Falsche Eingabe.");	
  }
  
  
  return 0;
  
  
}
