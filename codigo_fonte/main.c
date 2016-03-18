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
	short int int1_input, int2_input, index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID], popular[MAXID];
	char c;
	unsigned short int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS];
	Aeroporto aeroportos[MAXAEROPORTOS];
	while (1){
		c = getchar();
		switch (c){
			case 'A':
				scanf("%s %hd",str1_input,&int1_input);
				aeroportos[numero_aeroportos] = cria_aeroporto(int1_input,str1_input, numero_aeroportos);
				numero_aeroportos++;
				break;

			case 'I':
				scanf("%s %hd",str1_input,&int1_input);
				index_1 = PesquisaBinariaAeroportos(aeroportos,str1_input,numero_aeroportos);
				qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);

				if(index_1!=-1)
					aeroportos[index_1].capacidade += int1_input;
				else
					printf("*Capacidade de %s inalterada\n",str1_input);
				break;

			case 'F':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, true, false);
				break;

			case 'G':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, false, false);
				break;

			case 'R':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, false, true);
				break;

			case 'S':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, true, true);
				break;

			case 'N':
				RetornaVoo(grafo, aeroportos, numero_aeroportos, n_going_coming, str1_input, str2_input);
				break;

			case 'P':
				AeroportoPopular(grafo, aeroportos, numero_aeroportos, popular);
				break;

			case 'Q':
				break;

			case 'V':
				break;

			case 'C':
				break;

			case 'O':
				break;

			case 'L':

				break;
		}		
		if(c=='X')
			break;
	}
	printf("%s %d\n",aeroportos[0].id,aeroportos[0].capacidade);
	printf("%s %d\n",aeroportos[1].id,aeroportos[1].capacidade);
	printf("%s %d\n",aeroportos[2].id,aeroportos[2].capacidade);
	return 0;
}