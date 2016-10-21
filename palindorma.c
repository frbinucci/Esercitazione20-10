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
	//Indici necessari all'utilizzo degli array.
	int i,j;
	//Variabile booleana "palindromo", inizializzata a 1.
	int palindromo = 1;
	//Indice "j", che parte dal fondo dell'array.
	j=size-1;
	//Indice "i", che parte dalla cima dell'array.
	i=0;
	/*Ciclo di controllo.
	Il ciclo viene interrotto se l'array è scansionato nella sua interezza
	o se è stato riscontrato che non è palindromo.*/
	while(i<size && palindromo)
	{
		if(vet[i]!=vet[j])
		{
			palindromo = 0;
		}
		i++;
		j--;
	}
	//Restituzione dell'esito del controllo.
	return palindromo;
}

