#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 4

int main()
{
	srand(time(NULL));
	int casuale[DIM] = {0,0,0,0};
	int numUtente[DIM];
	int ripetuta, trovato;
	int tentativo = 0;
	int indovinato = 0;
	int cifraGenerata;
	int strike,ball;
	int i,j;
	int inputUtente;
	int uscita;

	//Ciclo di generazione del numero.
	for(i=0;i<DIM;i++)
	{
		do
		{
			ripetuta = 0;
			cifraGenerata = rand()%10;
			j = 0;
			while(j<DIM && !ripetuta)
			{
				if(casuale[j]==cifraGenerata)
				{
					ripetuta = 1;
				}
				j++;
			}
		}
		while(ripetuta);
		casuale[i]=cifraGenerata;
	}
	//---Stampa del numero generato---//

	for(i = 0;i<DIM;i++)
	{
		printf("%d",casuale[i]);
	}

	//Tentativi dell'utente.
	printf("\n\n");
	do
	{
		tentativo++;
		uscita = 0;
		inputUtente = 0;
		trovato = 0;
		i=0;
		while(i<DIM && !uscita)
		{
			printf("Inserire la cifra n.%d del numero: ",i+1);
			scanf("%d",&inputUtente);
			if(inputUtente > -1)
			{
				numUtente[i] = inputUtente;
				i++;
			}
			else
			{
				if(inputUtente==-1)
				{
					if(i!=0)
					{
						printf("\n\nAttenzione!!!Valori fuori range!!!Riprovare!!!\n\n");
					}
					else
					{
						uscita = 1;
					}
				}
			}
		}
		if(uscita!=1 && inputUtente>-1)
		{
			strike = 0;
			ball = 0;
			for(i=0;i<DIM;i++)
			{
				j=0;
				while(j<DIM)
				{
					if(casuale[i]==numUtente[j])
					{
						if(i==j)
						{
							strike++;
						}
						else
						{
							ball++;
						}
					}
					j++;
				}
			}
			printf("\nPer il tentativo n.%d hai fatto %d strike e %d ball\n\n",tentativo,strike,ball);
			if(strike==4)
			{
				indovinato = 1;
			}
		}
	}
	while(!indovinato && !uscita);
	if(inputUtente!=-1)
	{
		printf("\nCongratulazioni! Hai indovinato il numero in %d tentativi!!!",tentativo);
	}
	else
	{
		printf("\nIl numero da indovinare era: ");
		for(i = 0;i<DIM;i++)
		{
				printf("%d",casuale[i]);
		}
	}

	//printf("%d",DIM);
	printf("\n\n");
}