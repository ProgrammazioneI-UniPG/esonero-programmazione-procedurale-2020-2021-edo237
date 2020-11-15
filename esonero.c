//librerie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//dichiarazione variabili
char M[128];
char K[128];
char C[128];
int menuScelta;
time_t t;
char randomKey[128];

int main(void){
//inserimento stringa da tastiera
	printf("\nInserisci una stringa MAX 128:");
	printf("\nDigita: ");
	fgets(M, 128, stdin);
	//menu di scelta per l'utente
	printf("\n----------COME VUOI PROCEDERE?----------");
  printf("\n- Premi 1 per inserire una chiave MAX 128");
	printf("\n- Premi 2 per generare casualmente una chiave");
	printf("\n----------------------------------------");
	printf("\nDigita:");
	int c;

//ciclo do while che controlla la scelta dell'utente 1 o 2
	do{
		scanf("%d", &menuScelta);
		//utente menu 1
		if(menuScelta ==1){
			do{
				c=getchar();
			}
			while(c != '\n'&& c != EOF);
		printf("\nInserisci una stringa di lunghezza uguale o superiore ");
		//ciclo do while di controllo per avere la chiave K di lunghezza uguale o superiore della stringa M
		do{
		printf("\nDigita: ");
		fgets(K,128,stdin);
	}
		while(strlen(K)<strlen(M));
		printf("\n----------------------------------------");
		//stampa della stringa inserita da tastiera M carattere per carattere
		printf("\nStringa inserita da tastiera (M):");
		for(int i=0; i<strlen(M); i++){
		printf("%c", M[i]);
		}
		//stampa della chiave K carattere per carattere
		printf("\nChiave(K):");
		for(int i=0; i<strlen(K); i++){
		printf("%c", K[i]);
	}
		//operazione di xor tra la stringa iniziale M e la chiave K per ottenere la stringa cifrata C
		for(int i=0; i<strlen(M);i++){
			C[i]= M[i]^K[i];
	}
		//stampa della stringa cifrata C carattere per carattere
		printf("\nStringa cifrata(C):");
		for(int i=0; i<strlen(M); i++){
		printf("%x", C[i]);
		}
		//operazione di xor tra la stringa cifrata C e la chiave K per ottenere la stringa M decifrata
		for(int i=0; i<strlen(C);i++){
			M[i]= C[i]^K[i];
	}
		//stampa della stringa M decifrata carattere per carattere
		printf("\n\nStringa decifrata(M):");
		for(int i=0; i<strlen(M); i++){
		printf("%c", M[i]);
		}
		printf("\n----------------------------------------\n");
		return 0;
	}
	//utente menu 2
	else if (menuScelta == 2){
		srand((unsigned) time(&t));
		for(int i = 0; i<strlen(M)-1; i++){
			int randNum = (rand()% (128-32+1)) + 32;
			randomKey[i]= (char)(randNum);
		}
	//stampa della chiave casuale randomKey carattere per carattere
	printf("\nChiave generata casualmente: ");
	for(int i=0; i<strlen(randomKey); i++){
	printf("%c", randomKey[i]);
	}
	printf("\n----------------------------------------");
	//stampa della stringa M inserita da tastiera
	printf("\nStringa iniziale(M):");
	for(int i=0; i<strlen(M); i++){
	printf("%c", M[i]);
	}
	//stampa della chiave casuale carattere per carattere
	printf("\nChiave(K):");
	for(int i=0; i<strlen(M); i++){
	printf("%c", randomKey[i]);
	}
	//operazione di xor per ottenere la stringa cifrata
	for(int i=0;i<strlen(M);i++){
		C[i]=M[i]^randomKey[i];
	}
	//stampa della stringa cifrata C carattere per carattere
	printf("\n\nStringa cifrata(C):");
	for(int i=0;i<strlen(M);i++){
		printf("%x",C[i]);
	}
	//operazione di xor tra la chiave e la stringa cifrata C per ottenere la stringa iniziale M
	for(int i=0;i<strlen(C);i++){
		M[i]=C[i]^randomKey[i];
	}
	//stampa della stringa M decifrata
	printf("\n\nStringa decifrata(M):");
	for(int i=0; i<strlen(M); i++){
	printf("%c", M[i]);
		}
		printf("\n----------------------------------------\n");
		return 0;
	}
}
while(menuScelta!=1 && menuScelta!= 2);
}
