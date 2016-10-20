#include<stdio.h>
#include<math.h>

/*Dichiarazione della funzione "calcolaBase()".
La funzione riceve in input 4 parametri:
1)int rappresentazione[] => Array contenente la rappresentazione in base b del numero.
2)int size => Dimensione dell'array.
3)int numero => Numero da rappresentare in base b.
4)int base => Nuova base di rappresentazione.
*/
void calcolaBase(int rappresentazione[],int size,int numero,int base);

int main()
{
	//Variabili contenenti la base e il numero.
	int numero;
	int base;
	int size;

	//Richiesta in input del numero (con controllo sui dati inseriti).
	do
	{
		printf("Inserire il numero (maggiore di 0): ");
		scanf("%d",&numero);
		if(numero<=0)
		{
			printf("\nValore fuori intervallo!!!");
		}
		printf("\n\n");

	}
	while(numero<=0);
	//Richiesta in input del numero (con controllo sui dati inseriti).
	do
	{
		printf("Inserire il numero (compresa tra 2 e 9): ");
		scanf("%d",&base);
		if(base<2 || base >9)
		{
			printf("\nValore fuori intervallo!!!");
		}
		printf("\n\n");

	}
	while(base<2 || base >9);
	//Calcolo della dimensione dell'array.
	size = floor(log(numero)/log(base))+1;
	//Definizione di un array di dimensione "size", calcolata precedentemente.
	int rappresentazione[size];
	//Invocazione della procedura "calcolaBase()", con i rispettivi parametri.
	calcolaBase(rappresentazione,size,numero,base);
	//Stampa del numero rappresentato nella nuova base.
	printf("\nNumero convertito nella nuova base: ");
	for(int i = 0;i<size;i++)
	{
		printf("%d",rappresentazione[i]);
	}
	printf("\n\n");
}
//Definizione della funzione calcola base.
void calcolaBase(int rappresentazione[],int size,int numero,int base)
{
	//Definizione dell'indice "i", necessario alla manipolazione dell'array.
	int i;
	/*Calcolo della rappresentazione del numero nella nuova base, mediante l'algoritmo
	delle divisioni ripetute per base.
	*/
	for(i=size-1;i>=0;i--)
	{
		rappresentazione[i] = numero%base;
		numero = numero/base;
	}
}