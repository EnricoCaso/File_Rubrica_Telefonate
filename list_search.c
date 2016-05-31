/*
---------------------------------------------------------------------
|Nome:Enrico							    |
|Cognome:Caso							    |
|Matricola: N86 00 19 71					    |
|Anno:2016/2017							    |
---------------------------------------------------------------------

	1 - SCOPO
	2 - SPECIFICHE
	3 - LISTA PARAMETRI
	4 - INDICATORE DI ERRORE
	5 - PROCEDURE AUSILIARIE
	6 - RACCOMANDAZIONI DI USO
	7 - ESEMPIO DI USO
*/


/*Librerie*/
#include<stdio.h>

// Struttura prima lista
struct nodo
{
	long int num;		// Numero di telfono
	struct nodo *next;
};
typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

/*Function & Procedure*/




/*inizio*/
void search_list(NodoPtr *head,NodoPtr *current,NodoPtr *previus,long int num,int *found)
{

	/*VAR*/
	int notFound=1;

//BEGIN

	// Mentre l'elemento non è stato trovato e la lista nn è terminata
	while( (notFound == 1) && (*current != NULL) )
	{
		// Se il dato da ricercare è <= dell elemento corrente
		if( (num) == (*current)->num )
		{
			notFound=0;
		}
		else // Scorriamo la lista
		{
			*previus=*current;
			*current=(*current)->next;
		}
	}
	

	// Controlliamo se la lista non è terminata
	if (*current != NULL)
	{
		// Se il campo info dell elemento corrente è uguale all elemento che cerchiamo
		if ( (*current)->num == num )
		{
			*found=1;
		}
	}
	else
	{
		printf("Elemento non presente in lista quindi può essere aggiunto \n");
	}




}/*fine*/
