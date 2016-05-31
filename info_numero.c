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
		FILE *telPtr		: Puntatore al file telefonate.txt
		NodoPtr *head		: Testa della lista creata precedentemente
		long int num_find	: Numero di cui voglio sapere informazioni

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
void second_list_insert(SnodoPtr *head,long int chiamato,int sec);
int sum_recursive (SnodoPtr head);


/*inizio*/
void info_numero(FILE *telPtr,NodoPtr head,long int num_find)
{

	/*VAR*/
	int find=0;			// Valore logico
	long int chiamante;		// Numero chiamante
	long int chiamato;		// Numero chiamato
	int sec;			// Durata telefonata in secondi	
	SnodoPtr Shead;			// Testa della lista
	int totsec;			// Contiene il risultato della funzione ricorsiva per la somma dei secondi

//BEGIN

	// Creiamo la seconda lista
	Shead=NULL;

	// Ricerchiamo num_find nella lista
	while ( (head != NULL) && (find == 0)  )
	{
		
		if (  head->num == num_find )
		{
			find=1;
			printf("Numero presente nella lista estrazione delle informazioni \n");
			// Estraggo da telefonate.txt i record
			fscanf(telPtr,"%ld%ld%d",&chiamante,&chiamato,&sec);
			// Scrolliamo il file telefonate.txt fino alla fine
			while ( !feof(telPtr) )
			{
				// Se il num_find da ricercare è uguale al chiamente
				if (num_find == chiamante)
				{
					// Inserisci nella seconda lista il numero chiamato e i secondi di conversaizone
					second_list_insert(&Shead,chiamato,sec);
					// Estraggo da telefonate.txt i record
					fscanf(telPtr,"%ld%ld%d",&chiamante,&chiamato,&sec);
				}
				else
				{
					// Estraggo da telefonate.txt i record
					fscanf(telPtr,"%ld%ld%d",&chiamante,&chiamato,&sec);
				}
				
			}
		}
		else
		{
			// Scrolliamo la lista
			head=head->next;
		}

		

	}

	// Se la lista è terminata senza trovare il numero allora find sarà 0 e quindi il numero nella lista non è presente
	if (find == 0)
	{
		printf("Il numero %ld non è presente nella lista \n",num_find);
	}
	else
	{

		// Richiamiamo funzione ricorsiva per il calcolo dei secondi totali effettuati dal num_find
		totsec=sum_recursive(Shead);		



		// Una volta terminata la lista bisonga stamparla e stampare i campi secondi in minuti
		printf("I numeri chiamati da %ld sono :\n",num_find);
		while (Shead != NULL)
		{
			printf("Chiamato:%ld Time: %d Min %d sec \n",Shead->numC,((Shead->sec)/60),((Shead->sec)%60));
			Shead=Shead->next;
		}

		// Stampiamo la somma totale dei secondi espressi in minuti del numero num_find
		printf("Il totale dei minuti di conversazione è : Min %d sec %d \n",(totsec/60),(totsec%60));
	}


}/*fine*/
