/*constantes*/
#define ADICIONA false
#define ENCERRA true
#define REABRE false
#define REMOVE true
#define IDA false
#define IDAEVOLTA true
#define MAXID 4
#define MAXAEROPORTOS 1001

/*structs utilizados pelo programa*/
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

typedef struct{
	int voos;
	char partida[MAXID];
	int partida_crono;
	char chegada[MAXID];
} Voo;

/*funcoes_auxiliares.h*/
int OrdenaAeroportosNome(const void *a, const void *b);
int OrdenaAeroportosCronologicamente(const void *a, const void *b);
int OrdenaHistograma(const void *a, const void *b);
int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos);
int PesquisaBinariaHistograma(Histograma hist[], int a_procurar, int n_hist);
void InsertionSortAeroporto(Aeroporto aeroportos[], int numero_aeroportos, bool crono);

/*funcoes_comandos.h*/
void CriaAeroporto(Aeroporto aeroportos[], int numero_aeroportos, Voo popular[]);
void AlteraCapacidadeAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos);
void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos);
bool AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover, Voo popular[], long int total_voos[]);
void RetornaVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos);
void AeroportoPopular(Aeroporto aeroportos[], int numero_aeroportos);
void AeroportoConectado(Aeroporto aeroportos[], int numero_aeroportos);
void HistogramaImprime(Aeroporto aeroportos[], int numero_aeroportos);
void EncerraReabreAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, long int total_voos[], bool encerra);
void InsertionSortHistrograma(Histograma hist[], int n_hist);