#define ADICIONA false
#define REMOVE true
#define IDA false
#define IDAEVOLTA true
#define MAXID 4
#define MAXAEROPORTOS 1001
#define COMANDOS "AIFGRSNPQVCOLX"


typedef struct{
	char id[4];
	int capacidade;
	bool estado;
	int crono;
	int partem;
	int chegam;
} Aeroporto;

int OrdenaAeroportosCronologicamente(const void *a, const void *b) ;
int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos);
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover);