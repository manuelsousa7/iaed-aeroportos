#define ADICIONA false
#define REMOVE true
#define IDA false
#define IDAEVOLTA true
#define MAXID 4
#define MAXAEROPORTOS 1001
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define COMANDOS "AIFGRSNPQVCOLX"


typedef struct{
	char id[4];
	int capacidade;
	bool estado;
	int crono;
	int conectados;
	int soma;
	int partem;
	int chegam;
} Aeroporto;

typedef struct{
	int soma;
	int n;
} Histograma;

int OrdenaAeroportosCronologicamente(const void *a, const void *b) ;
int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos);
bool AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover);
int OrdenaHistograma(const void *a, const void *b);
int PesquisaBinariaHistograma(Histograma histograma[], int n, int n_hist);