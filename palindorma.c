#include<stdio.h>
/*Funzione che verifica se un array e' palindromo:
int vet[] => Array da controllare.
int size => Lunghezza dell'array.
La funzione restituisce "1" se l'array è palindromo.
La funzione restituisce "0" se l'array non è palindromo.
*/
int isPalindromo(const int vet[],int size);

int main()
{
	//Variabile contenente la dimensione dell'array.
	int dim;
	//Richiesta della dimensione dell'array.
	printf("Inserire la dimensione dell'array: ");
	scanf("%d",&dim);
	printf("\n");
	int vet[dim];
	int i;
	int palindromo;
	//Caricamento dell'array.
	for(i=0;i<dim;i++)
	{
		printf("Inserire l'elemento n.%d dell'array:",i+1);
		scanf("%d",&vet[i]);
	}
	//Verifica se l'array è palindromo.
	palindromo = isPalindromo(vet,dim);
	//Stampa dei risultati.
	if(palindromo)
	{
		printf("\nL'array inserito e' palindromo!");
	}
	else
	{
		printf("\nL'array inserito non e' palindromo!");

	}
	printf("\n\n");


}
//Definizione della funzione "isPalindromo()".
int isPalindromo(const int vet[],int size)
{
	//Variabile contenente l'array invertito.
	int palVet[size];
	//Indici necessari all'utilizzo degli array.
	int i,j;
	/*Variabile "palindromo", contenente l'esito del controllo.
	1=>Array Palindromo.
	0=>Array non palindromo.
	*/
	int palindromo = 1;
	//Caricamento dell'array inverso.
	j=0;
	for(i=size-1;i>=0;i--)
	{
		palVet[j] = vet[i];
		j++;
	}

	i = 0;
	//Ciclo atto a controllare se l'array è palindromo.
	while(i<size && palindromo)
	{
		if(vet[i]!=palVet[i])
		{
			palindromo = 0;
		}
		i++;
	}
	//Restituzione dell'esito del controllo.
	return palindromo;
}

