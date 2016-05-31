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
void list_insert(NodoPtr *head,long int num);



/*inizio*/
void lista_chiamate(NodoPtr *head,FILE *rubPtr,FILE *telPtr)
{

	/*VAR*/
	char cognome[20];
	char nome[20];
	long int num;
	long int chiamante;
	long int chiamato;
	int secondi;
	int find;


//BEGIN


	// Estraggo da rubrica il primo record
	fscanf(rubPtr,"%s%s%ld",cognome,nome,&num);
	// Mentre il file rubrica non è terminato
	while ( !feof(rubPtr) )
	{
		// Estraggo da telefonate i record
		fscanf(telPtr,"%ld%ld%d",&chiamante,&chiamato,&secondi);
		find=0;
		// Mentre non ho finitio di scrollare il file telefonate oppure ho trovato il chiamante che corrisponde al num in rubrica
		while ( !feof(telPtr) && (find == 0))
		{
			if (num == chiamante)
			{
				//Inserisci in lista
				list_insert(head,num);
				find=1;
				rewind(telPtr);
			}
			else
			{
				// Estraggo prossimo record file telefonate
				fscanf(telPtr,"%ld%ld%d",&chiamante,&chiamato,&secondi);
			}
		}

		// Estraggo record file rubrica 
		fscanf(rubPtr,"%s%s%ld",cognome,nome,&num);
		rewind(telPtr);
	}




}/*fine*/
