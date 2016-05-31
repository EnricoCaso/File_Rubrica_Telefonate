/*
---------------------------------------------------------------------
|Nome:Enrico							    |
|Cognome:Caso							    |
|Matricola: N86 00 19 71					    |
|Anno:2016/2017							    |
---------------------------------------------------------------------
TRACCIA



*/



//Librerie
#include<stdio.h>

// Struttura prima lista
struct nodo
{
	long int num;		// Numero di telfono
	struct nodo *next;
};
typedef struct nodo Nodo;
typedef Nodo *NodoPtr;


//Function & Procedure
void lista_chiamate(NodoPtr *head,FILE *rubPtr,FILE *telPtr);
void print_list (NodoPtr head);
void info_numero(FILE *telPtr,NodoPtr head,long int num_find);

//inizio
int main()
{

	//VAR
	FILE *rubPtr;			// Puntatore a file rubrica
	FILE *telPtr;			// Puntatore a file telefonate
	NodoPtr head;			// Testa della lista
	long int num;			// Numero di cui voglio sapere info


//BEGIN

	// Creiamo la lista con assegnazione di head null
	head=NULL;

	// Apriamo i due file
	if ( (rubPtr=fopen("rubrica.txt","r")) != NULL )
	{
		printf("File rubrica.txt aperto \n");
	}
	else
	{
		printf("File rubrica non aperto \n");
	}

	if ( (telPtr=fopen("telefonate.txt","r")) != NULL )
	{
		printf("File telefonate.txt aperto \n");
	}
	else
	{
		printf("File telefonate.txt non aperto \n");
	}


	// Richiamo della procedura lista_chiamate
	lista_chiamate(&head,rubPtr,telPtr);

	// Chiudiamo rubrica
	fclose(rubPtr);

	// Stampiamo la lista
	printf("La lista estratta è \n");
	print_list(head);


	// Chiedo il numero di cui voglio sapere informazioni
	printf("Inserisci il numero di cui vuoi sapere informazioni \n");
	scanf("%ld",&num);
	

	// Richiamo funzione info_numero
	info_numero(telPtr,head,num);


	// Chiuduamo file delle telefonate
	fclose(telPtr);

return 0;
}//fine
