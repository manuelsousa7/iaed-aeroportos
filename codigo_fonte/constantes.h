#define MAXAEROPORTOID 4
#define MAXAEROPORTOS 1001
#define COMANDOS "AIFGRSNPQVCOLX"

typedef struct{
	char id[4];
	long int capacidade;
	bool estado = true;
} Aeroporto;

unsigned short int numero_aeroportos;

Aeroporto grafo[MAXAEROPORTOS][MAXAEROPORTOS];