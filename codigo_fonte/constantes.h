#define TRUE 1
#define FALSE 0
#define MAXAEROPORTOID 4
#define MAXAEROPORTOS 1001
#define COMANDOS "AIFGRSNPQVCOLX"


typedef struct{
	char id[4];
	short int capacidade;
	bool estado;
	short int crono;
	int partem;
	int chegam;
} Aeroporto;
