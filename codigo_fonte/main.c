/******************************************************************************
* File Name:   main.c
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME:        Rede de Aeroportos - IST/IAED - 2015/2016 2º Semestre
* SYNOPSIS:    #include <stdio.h>
			   #include <string.h>
			   #include <stdbool.h>
			   #include <stdlib.h>
			   #include "constantes.h"
			   #include "funcoes_comandos.h"
			   #include "funcoes_auxiliares.h"
* DESCRIPTION: Rede de Aeroportos - funcao main.
* DIAGNOSTICS: tested
* USAGE:       make clean
			   make all
			   make run
*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "constantes.h"
#include "funcoes_comandos.h"
#include "funcoes_auxiliares.h"

/******************************************************************************
* main()
*
* Arguments: nenhum
* Returns: 0
* Description: 	menu de comandos com chamada dos varios modulos (Apenas)		   
*****************************************************************************/
int main(){
	Aeroporto aeroportos[MAXAEROPORTOS];
	Voo popular[1]; //vetor de dimensao 1 para que seja passado por referencia nas funcoes
	char c;
	int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS], int1_input;
	long int total_voos[1];
	memset(grafo, 0, sizeof(grafo[0][0]) * MAXAEROPORTOS * MAXAEROPORTOS); // Inicializa entradas do grafo a 0

	while (1) {
		c = getchar();
		switch (c){

			case 'A':
				CriaAeroporto(aeroportos, numero_aeroportos);
				numero_aeroportos++;
				qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
				break;

			case 'I':
				AlteraCapacidadeAeroporto(aeroportos, numero_aeroportos);
				break;

			case 'F':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, ADICIONA, popular, total_voos);
				break;

			case 'G':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, ADICIONA, popular, total_voos);
				break;

			case 'R':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, REMOVE, popular, total_voos);
				break;

			case 'S':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, REMOVE, popular, total_voos);
				break;

			case 'N':
				RetornaVoo(grafo, aeroportos, numero_aeroportos);
				break;

			case 'P':
				AeroportoPopular(aeroportos, numero_aeroportos);
				break;

			case 'Q':
				AeroportoConectado(aeroportos, numero_aeroportos);
				break;

			case 'V':
				VerificaPopular(grafo, aeroportos, numero_aeroportos, popular, total_voos);
				break;

			case 'C':
				EncerraReabreAeroporto(grafo, aeroportos,numero_aeroportos, total_voos ,1);
				break;

			case 'O':
				EncerraReabreAeroporto(grafo, aeroportos,numero_aeroportos, total_voos ,0);
				break;
				
			case 'L':
				scanf("%d", &int1_input);
				if(int1_input == 0){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosCronologicamente);
					ImprimeAeroportos(aeroportos, numero_aeroportos);
					// Mantem aeroportos ordenados por ID para nao haver problema com a Pesquisa Binaria
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome); 
				} 
				else if(int1_input == 1){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
					ImprimeAeroportos(aeroportos, numero_aeroportos);
				} else {
					HistogramaImprime(aeroportos, numero_aeroportos);
				}
				break;
		}	
		if(c == 'X'){
			printf("%ld:%d\n", total_voos[0], numero_aeroportos);
			break;
		}
	}
	return 0;
}