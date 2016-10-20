#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Definizione della funzione "main()".
int main()
{
	//Impostazione del seme tramite le funzioni "srand()" e "time()", delle librerie "sdtlib.h" e "time.h".
	srand(time(NULL));
	//Definizione delle variabili necessarie al funzionamento del programma
	int casuale;
	int indovinato = 0;
	int scelta = 0;
	int tentativi = 0;
	//Calcolo del numero casuale.
	casuale = (rand()%1000)+1;
	do
	{
		//Richiesta all'utente dei numeri da inserire.
		printf("Inserire un numero compreso tra 1 e 1000 (0 per terminare): ");
		scanf("%d",&scelta);
		//Verifica del numero inserito nel caso in cui esso sia maggiore di 0.
		if(scelta>0)
		{
			//Calcolo dei tentativi.
			tentativi++;
			//Se il numero inserito dall'utente viene indovinato, la variabile "indovinato" viene portata a 1.
			if(scelta == casuale)
			{
				indovinato = 1;
			}
			else
			{
				/*In caso contrario il programma comunica all'utente
				se il numero inserito è troppo alto o troppo basso.*/
				if(scelta>casuale)
				{
					printf("\n%d e' troppo alto!!! Riprovare!!!\n\n",scelta);
				}
				else
				{
					printf("\n%d e' troppo basso!!!Riprovare!!!\n\n",scelta);
				}
			}
		}

	}
	//Il ciclo si ripete finché l'utente non ha indovinato, o finché non ha inserito "0" per rinunciare.
	while(!indovinato || scelta<=0);
	/*Nel caso in cui, al termine del ciclo, la varibaile "indovinato" abbia assunto valore "1", il programma
	comunicherà la vincita all'utente con il rispettivo numero di tentativi.*/
	if(indovinato)
	{
		printf("\nComplimenti!!! Hai indovinato in %d tentativi!!!\n\n",tentativi);
	}

}