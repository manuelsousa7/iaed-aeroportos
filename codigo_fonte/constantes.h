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




