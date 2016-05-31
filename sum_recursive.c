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
int sum_recursive (SnodoPtr head)
{

	/*VAR*/
	int tot;

//BEGIN

	if (head == NULL)
	{
		return 0;
	}
	else
	{
		return  tot = ( head->sec + sum_recursive(head->next) );
	}


}/*fine*/
