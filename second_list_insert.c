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
#include <stdlib.h>


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
void second_list_search(SnodoPtr *head,SnodoPtr *current,SnodoPtr *previus,long int chiamato,int *found);



/*inizio*/
void second_list_insert(SnodoPtr *head,long int chiamato,int sec)
{

	/*VAR*/
	SnodoPtr previus,current,newnode;		// Nodi Precendente Corrente e nuovonodo
	int found;					// Contiene il risultato retituito da search_list


//BEGIN

	// Inizializziamo i nodi current e previus e found a 0 cioè elemento non trovato
	current=*head;
	previus=NULL;
	found=0;

	
	// Cerchiamo nella lista se il dato da inserire controllando se è presente o meno
	second_list_search(head,&current,&previus,chiamato,&found);


	// Se found è 0 significa che il dato non è presente se 1 dato presente e non possiamo aggiungere nodi
	if (found == 0)
	{

		// Allocazione nuovo nodo 
		newnode=malloc(sizeof(Snodo));
		newnode->numC=chiamato;
		newnode->sec=sec;

		// Controlliamo se l'inserimento avviene in testa altrimenti nel corpo della lista
		if (previus == NULL)
		{
			newnode->next=*head;
			*head=newnode;
			printf("Nodo Inserito in testa alla lista \n");
		}
		else
		{
			newnode->next=previus->next;
			previus->next=newnode;
			printf("Nodo inserito nel corpo della lista \n");
		}

	}
	else
	{
		printf("Il numero %ld è gia presente nella lista impossibile aggiungerlo \n",chiamato);
	}
	




}/*fine*/
