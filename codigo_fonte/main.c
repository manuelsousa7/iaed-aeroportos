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
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover);

int main()
{
	int int1_input, int2_input, index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID];
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
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, ADICIONA);
				break;

			case 'G':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, ADICIONA);
				break;

			case 'R':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDA, REMOVE);
				break;

			case 'S':
				AdicionaRemoveVoo(grafo, aeroportos, numero_aeroportos, IDAEVOLTA, REMOVE);
				break;

			case 'N':
				RetornaVoo(grafo, aeroportos, numero_aeroportos);
				break;

			case 'P':
				AeroportoPopular(aeroportos, numero_aeroportos);
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