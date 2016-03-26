/******************************************************************************
 * File Name:   main.c
 * Author:      Gonçalo Marques (84719) / Manuel Sousa (84740)
 * Revision:
 * NAME:        Rede de Aeroportos - IST/IAED - 2016 2º Semestre
 * SYNOPSIS:    #include <stdio.h>
				#include <string.h>
				#include <stdbool.h>
				#include <stdlib.h>
				#include <math.h>
				#include "constantes.h"
				#include "funcoes_comandos.h"
				#include "funcoes_auxiliares.h"
 * DESCRIPTION: Rede de Aeroportos - função main.
 * DIAGNOSTICS: tested
 * USAGE:       make all
				make run
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "constantes.h"
#include "funcoes_comandos.h"
#include "funcoes_auxiliares.h"


/******************************************************************************
* main()
*
* Arguments: nenhum
* Returns: 0
* Side-Effects: none
* Description: 	menu de comandos com chamada dos vários modulos (Apenas)		   
*****************************************************************************/
int main()
{
	Aeroporto aeroportos[MAXAEROPORTOS];
	Voo popular[1];
	char c;
	int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS],int1_input;
	long int total_voos[1];
	memset(grafo, 0, sizeof(grafo[0][0]) * MAXAEROPORTOS * MAXAEROPORTOS);
	while (1) {
		c = getchar();
		switch (c){
			case 'A':
				CriaAeroporto(aeroportos, numero_aeroportos);
				numero_aeroportos++;
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
				printf("Voo mais popular %s:%s:%d\n", popular[0].partida, popular[0].chegada, popular[0].voos);
				break;

			case 'C':
				EncerraReabreAeroporto(grafo, aeroportos,numero_aeroportos, popular, total_voos ,1);
				break;

			case 'O':
				EncerraReabreAeroporto(grafo, aeroportos,numero_aeroportos, popular, total_voos ,0);
				break;
			case 'L':
				scanf("%d",&int1_input);
				if(int1_input == 0){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosCronologicamente);
					//InsertionSortAeroporto(aeroportos,numero_aeroportos,1);
					ImprimeAeroportos(aeroportos, numero_aeroportos);
				}
				else if(int1_input==1){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
					//InsertionSortAeroporto(aeroportos,numero_aeroportos,0);
					ImprimeAeroportos(aeroportos, numero_aeroportos);
				}
				else{
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