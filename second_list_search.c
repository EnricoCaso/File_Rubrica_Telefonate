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
#include <stdio.h>

// Struttura seconda lista
struct s_nodo
{
	long int numC;			// Numero chiamato
	int sec;			// Totale secondi di conversazione
	struct s_nodo *next;		// Link al nodo successivo
};
typedef struct s_nodo Snodo;
typedef Snodo *SnodoPtr;		// Testa seconda lista 

/*Function & Procedure*/



/*inizio*/
void second_list_search(SnodoPtr *head,SnodoPtr *current,SnodoPtr *previus,long int chiamato,int *found)
{

	/*VAR*/
	int notFound=1;

//BEGIN

	// Mentre l'elemento non è stato trovato e la lista nn è terminata
	while( (notFound == 1) && (*current != NULL) )
	{
		// Se il dato da ricercare è <= dell elemento corrente
		if( (chiamato) <= (*current)->numC )
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
		if ( (*current)->numC == chiamato )
		{
			*found=1;
		}
	}
	else
	{
		printf("Elemento non presente in lista quindi può essere aggiunto \n");
	}





}/*fine*/
