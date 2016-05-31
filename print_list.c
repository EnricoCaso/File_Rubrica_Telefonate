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



/*inizio*/
void print_list (NodoPtr head)
{

	/*VAR*/

//BEGIN

	if (head == NULL)
	{
		printf("Lista vuota \n");	
	}
	else
	{
		while (head != NULL)
		{
			printf("%ld --> ",head->num);
			head=head->next;
		}
		printf("NULL \n\n");
	}

}/*fine*/
