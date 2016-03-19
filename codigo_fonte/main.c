/*                                                         .:INSTITUTO SUPERIOR TECNICO:.
											Programa Realizado Por:
													 - Gonçalo Marques (84719)
													 - Manuel Sousa (84740)
											Tema: Redes de Aeroportos
											Curso: Licenciatura de Engenharia Informática e Computadores (LEIC-T)
											Cadeira: Introdução aos Algoritmos e Estruturas de Dados
											Data de Entrega: 02/04/2016
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "constantes.h"
#include "funcoes_comandos.h"
#include "funcoes_auxiliares.h"

int main()
{
	Aeroporto aeroportos[MAXAEROPORTOS];
	int int1_input;
	char c;
	bool muda_voo;
	int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS];
	long long int total_voos;
	memset(grafo, 0, sizeof(grafo[0][0]) * MAXAEROPORTOS * MAXAEROPORTOS);
	while (1){	
		c = getchar();
		switch (c){
			case 'A':

				//E SE O UTILIZADOR INTRODUZIR UM AEROPORTO COM MAIS DE 3 LETRAS??

				CriaAeroporto(aeroportos, numero_aeroportos);
				numero_aeroportos++;
				break;

			case 'I':
				AlteraCapacidadeAeroporto(grafo, aeroportos, numero_aeroportos);
				break;

			case 'F':
				muda_voo = AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, ADICIONA);
				if (muda_voo)
					total_voos += 2;
				break;

			case 'G':
				muda_voo = AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, ADICIONA);
				if (muda_voo)
					total_voos += 1;
				break;

			case 'R':
				muda_voo = AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, REMOVE);
				if (muda_voo)
					total_voos -= 1;
				break;
			case 'S':
				muda_voo = AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, REMOVE);
				if (muda_voo)
					total_voos -= 2;
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
				//VooPopular(grafo, numero_aeroportos);
				break;

			case 'C':
				EncerraReabreAeroporto(aeroportos,numero_aeroportos,1);
				break;

			case 'O':
				EncerraReabreAeroporto(aeroportos,numero_aeroportos,0);
				break;
			case 'L':
				scanf("%d",&int1_input);
				if(int1_input==0){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosCronologicamente);
					//InsertionSortAeroporto(aeroportos,numero_aeroportos,1);
					ImprimeAeroportos(aeroportos,numero_aeroportos);
				}
				else if(int1_input==1){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
					//InsertionSortAeroporto(aeroportos,numero_aeroportos,0);
					ImprimeAeroportos(aeroportos,numero_aeroportos);
				}
				else{
					HistogramaImprime(aeroportos,numero_aeroportos);
				}
				break;
		}		
		if(c=='X'){
			printf("%lld:%d\n",total_voos,numero_aeroportos);
			break;
		}
	}
	return 0;
}

// P
// V
// C
// O
