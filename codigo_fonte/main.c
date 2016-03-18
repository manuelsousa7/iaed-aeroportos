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

int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos);
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos, int numero_aeroportos, int ida_volta, int remover);

int main()
{
	int int1_input, int2_input, index_1, index_2, n_going_coming[2];
	char str1_input[4], str2_input[4], popular[4];
	char c;
	int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS];
	Aeroporto aeroportos[MAXAEROPORTOS];
	memset(grafo, 0, sizeof(grafo[0][0]) * MAXAEROPORTOS * MAXAEROPORTOS);
	while (1){
		c = getchar();
		switch (c){
			case 'A':
				scanf("%s %d",str1_input,&int1_input);
				aeroportos[numero_aeroportos] = CriaAeroporto(int1_input,str1_input, numero_aeroportos);
				numero_aeroportos++;	
				break;

			case 'I':
				scanf("%s %d",str1_input,&int1_input);
				index_1 = PesquisaBinariaAeroportos(aeroportos,str1_input,numero_aeroportos);
				qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
				if(index_1!=-1)
					aeroportos[index_1].capacidade += int1_input;
				else
					printf("*Capacidade de %s inalterada\n",str1_input);
				break;

			case 'F':
				//printf("->%d",numero_aeroportos);
				scanf("%s %s", str1_input, str2_input);
				index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
				index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);
				grafo[index_2][index_1] += 1;
				grafo[index_1][index_2] += 1;
				//AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, 1, 0);
				break;

			case 'G':
				//AdicionaRemoveVoo(grafo[MAXAEROPORTOS], aeroportos, numero_aeroportos, 0, 0);
				break;

			case 'R':
				//AdicionaRemoveVoo(grafo[MAXAEROPORTOS], aeroportos, numero_aeroportos, 0, 1);
				break;

			case 'S':
				//AdicionaRemoveVoo(grafo[MAXAEROPORTOS], aeroportos, numero_aeroportos, 1, 1);
				break;

			case 'N':
				//RetornaVoo(grafo, aeroportos, numero_aeroportos, n_going_coming, str1_input, str2_input);
				printf("Voos entre cidades %s : %s : %d : %d", str1_input, str2_input, n_going_coming[0], n_going_coming[1]);
				break;

			case 'P':
				//VooPopular(grafo, aeroportos, numero_aeroportos, popular);
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
				scanf("%d",&int1_input);
				if(int1_input==0){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosCronologicamente);
					ImprimeAeroportos(aeroportos,numero_aeroportos);}
				else if(int1_input==1){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
					ImprimeAeroportos(aeroportos,numero_aeroportos);}
				else{//histograma

				}
				break;
		}		
		if(c=='X')
			break;
	}
	return 0;
}