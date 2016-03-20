//Cria um novo aeroporto
void CriaAeroporto(Aeroporto aeroportos[], int numero_aeroportos, Voo popular[])
{
	int capacidade;
	char str1_input[MAXID];
	scanf("%s %d",str1_input,&capacidade);
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	aeroporto.conectados=0;
	aeroporto.soma=0;
	aeroporto.partem=0;
	aeroporto.chegam=0;
	aeroporto.crono=numero_aeroportos;
	strcpy(aeroporto.id,str1_input);
	aeroportos[numero_aeroportos] = aeroporto;
}

//Altera a capacidade do aeroporto
void AlteraCapacidadeAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos)
{
	int cap, index_1;
	char str1_input[MAXID];
	scanf("%s %d", str1_input, &cap);
	index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);

	if(index_1 != -1 && aeroportos[index_1].soma <= (aeroportos[index_1].capacidade + cap) && aeroportos[index_1].estado)
		aeroportos[index_1].capacidade += cap;
	else
		printf("*Capacidade de %s inalterada\n",str1_input);
}

void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos)
{
	int i;
	for (i = 0 ; i < numero_aeroportos; i++){
        if(aeroportos[i].estado==true)
		  printf("%s:%d:%d:%d\n",aeroportos[i].id,aeroportos[i].capacidade,aeroportos[i].partem,aeroportos[i].chegam);
    }
}

//Adiciona ou remove um voo de ida ou de ida e volta
bool AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover, Voo popular[], long int total_voos[]){

	int index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID];

	scanf("%s %s", str1_input, str2_input);
	index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
	index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);
	if (index_1 != -1 && index_2 != -1 && aeroportos[index_1].estado && aeroportos[index_2].estado){
		//se for para remover
		if (remover){
			//se o numero de voos for maior que 0
			if (grafo[index_2][index_1] > 0 && !(ida_volta)){
				grafo[index_2][index_1] -= 1;
				aeroportos[index_1].partem -= 1;
				aeroportos[index_1].soma -= 1;
				aeroportos[index_2].chegam -= 1;
				aeroportos[index_2].soma -= 1;
				//Se os aeroportos deixarem de estar conectados
				if (grafo[index_2][index_1] == 0 && grafo[index_1][index_2] == 0){
					aeroportos[index_1].conectados -= 1;
					aeroportos[index_2].conectados -= 1;
				}
			}
			else if (!ida_volta){
				printf("*Impossivel remover voo %s %s\n", str1_input, str2_input);
				return false;
			}
		}
		//se for para adicionar
		else {
			//se os aeroportos nao tiverem excedido a capacidade
			if (aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade && aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade && !(ida_volta)){
				//Se os aeroportos ainda nao estavam conectados
				if (grafo[index_2][index_1] == 0 && grafo[index_1][index_2] == 0){
					aeroportos[index_1].conectados += 1;
					aeroportos[index_2].conectados += 1;
				}

				grafo[index_2][index_1] += 1;
				aeroportos[index_1].partem += 1;
				aeroportos[index_1].soma += 1;
				aeroportos[index_2].chegam += 1;
				aeroportos[index_2].soma += 1;

				//se for o primeiro voo, este passa a ser o mais popular
				if (total_voos[0] == 0){
					popular[0].voos = grafo[index_2][index_1];
					strcpy(popular[0].partida,str1_input);
					popular[0].partida_crono = aeroportos[index_1].crono;
					strcpy(popular[0].chegada,str2_input);
				}
				else {
					if (grafo[index_2][index_1] >= popular[0].voos){
						if (grafo[index_2][index_1] == popular[0].voos){
							if (popular[0].partida_crono > aeroportos[index_1].crono){
								strcpy(popular[0].partida,str1_input);
								popular[0].partida_crono = aeroportos[index_1].crono;
								strcpy(popular[0].chegada,str2_input);
							}
						}
						else {
							popular[0].voos = grafo[index_2][index_1];
							strcpy(popular[0].partida,str1_input);
							popular[0].partida_crono = aeroportos[index_1].crono;
							strcpy(popular[0].chegada,str2_input);
						}
						
					}
				}
			}
			else if (!ida_volta){
				if (!(aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade))
					printf("*Impossivel adicionar voo %s %s\n", str1_input, str2_input);
				if (!(aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade))
					printf("*Impossivel adicionar voo %s %s\n", str1_input, str2_input);
				return false;
			}
		}

		if (ida_volta){
			//se for para remover
			if (remover) {
				if (grafo[index_1][index_2] > 0 && grafo[index_2][index_1] > 0){
					grafo[index_2][index_1] -= 1;
					aeroportos[index_1].partem -= 1;
					aeroportos[index_1].soma -= 1;
					aeroportos[index_2].chegam -= 1;
					aeroportos[index_2].soma -= 1;
					grafo[index_1][index_2] -= 1;
					aeroportos[index_2].partem -= 1;
					aeroportos[index_2].soma -= 1;
					aeroportos[index_1].chegam -= 1;
					aeroportos[index_1].soma -= 1;

					//Se os aeroportos deixarem de estar conectados
					if (grafo[index_2][index_1] == 0 && grafo[index_1][index_2] == 0){
						aeroportos[index_1].conectados -= 1;
						aeroportos[index_2].conectados -= 1;
					}
				}
				else {
					printf("*Impossivel remover voo RT %s %s\n", str1_input, str2_input);
					return false;
				}
			}
			//se for para adicionar
			else {
				if (aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade && aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade){
					//Se os aeroportos ainda nao estavam conectados
					if (grafo[index_2][index_1] == 0 && grafo[index_1][index_2] == 0){
						aeroportos[index_1].conectados += 1;
						aeroportos[index_2].conectados += 1;
					}
					grafo[index_2][index_1] += 1;
					aeroportos[index_1].partem += 1;
					aeroportos[index_1].soma += 1;
					aeroportos[index_2].chegam += 1;
					aeroportos[index_2].soma += 1;
					grafo[index_1][index_2] += 1;
					aeroportos[index_2].partem += 1;
					aeroportos[index_2].soma += 1;
					aeroportos[index_1].chegam += 1;
					aeroportos[index_1].soma += 1;

					//se for o primeiro voo, este passa a ser o mais popular
					if (total_voos[0] == 0){
						popular[0].voos = grafo[index_2][index_1];
						strcpy(popular[0].partida,str1_input);
						popular[0].partida_crono = aeroportos[index_1].crono;
						strcpy(popular[0].chegada,str2_input);
					}
					else {

						//verifica a rota de ida
						if (grafo[index_2][index_1] >= popular[0].voos){
							if (grafo[index_2][index_1] == popular[0].voos){
								if (popular[0].partida_crono > aeroportos[index_1].crono){
									strcpy(popular[0].partida,str1_input);
									popular[0].partida_crono = aeroportos[index_1].crono;
									strcpy(popular[0].chegada,str2_input);
								}
							}
							else {
								popular[0].voos = grafo[index_2][index_1];
								strcpy(popular[0].partida,str1_input);
								popular[0].partida_crono = aeroportos[index_1].crono;
								strcpy(popular[0].chegada,str2_input);
							}
							
						}
						//verifica a rota de volta
						if (grafo[index_1][index_2] >= popular[0].voos){
							if (grafo[index_1][index_2] == popular[0].voos){
								if (popular[0].partida_crono > aeroportos[index_2].crono){
									strcpy(popular[0].partida,str1_input);
									popular[0].partida_crono = aeroportos[index_2].crono;
									strcpy(popular[0].chegada,str2_input);
								}
							}
							else {
								popular[0].voos = grafo[index_1][index_2];
								strcpy(popular[0].partida,str1_input);
								popular[0].partida_crono = aeroportos[index_2].crono;
								strcpy(popular[0].chegada,str2_input);
							}
							
						}
					}
				}

				else{
					if (!(aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade))
						printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
					if (!(aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade))
						printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
					return false;
				}
			}
		}
		return true;
	}

	else {

		if (remover){
			if (ida_volta)
				printf("*Impossivel remover voo RT %s %s\n", str1_input, str2_input);
			else
				printf("*Impossivel remover voo %s %s\n", str1_input, str2_input);
		}
		else{
			if (ida_volta)
				printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
			else
				printf("*Impossivel adicionar voo %s %s\n", str1_input, str2_input);
		}
		return false;
	}
}

void RetornaVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos){
	int index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID];

	scanf("%s %s", str1_input, str2_input);
	index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
	index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

	printf("Voos entre cidades %s:%s:%d:%d\n", str1_input, str2_input, grafo[index_2][index_1], grafo[index_1][index_2]);
}

void AeroportoPopular(Aeroporto aeroportos[], int numero_aeroportos){
	int iterador, maior = 0, indice = 0;

	for (iterador = 0; iterador < numero_aeroportos; iterador++)
		if (maior < (aeroportos[iterador].soma)){
			maior = (aeroportos[iterador].soma);
			indice = iterador;
		}

	printf("Aeroporto com mais rotas %s:%d:%d\n", aeroportos[indice].id,aeroportos[indice].partem,aeroportos[indice].chegam);
}

void AeroportoConectado(Aeroporto aeroportos[], int numero_aeroportos){
	int iterador, maior = 0, indice = 0;

	for (iterador = 0; iterador < numero_aeroportos; iterador++)
		if (maior < (aeroportos[iterador].conectados)){
			maior = (aeroportos[iterador].conectados);
			indice = iterador;
		}
		else if (maior == (aeroportos[iterador].conectados)){
			if (aeroportos[iterador].crono < aeroportos[indice].crono){
				maior = (aeroportos[iterador].conectados);
				indice = iterador;
			}
		}

	printf("Aeroporto com mais ligações %s:%d\n", aeroportos[indice].id,maior);
}

void HistogramaImprime(Aeroporto aeroportos[], int numero_aeroportos){
	Histograma hist[MAXAEROPORTOS];
    int index,i;
    int n_hist=1;
    hist[0].soma=aeroportos[0].soma;
    hist[0].n=1;
    for (i=1;i<numero_aeroportos;i++){
        if(aeroportos[i].estado==true){
            index=PesquisaBinariaHistograma(hist,aeroportos[i].soma,n_hist);
            if(index==-1){
                hist[n_hist].soma=aeroportos[i].soma;
                hist[n_hist].n=1;
                n_hist++;
            }
            else
                hist[index].n++;
        }
    }
    qsort(hist, n_hist, sizeof(Histograma), OrdenaHistograma);
    for(i=0;i<n_hist;i++)
        printf("%d:%d\n", hist[i].soma,hist[i].n);
}

void EncerraReabreAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, long int total_voos[], int encerra)
{
    char str1_input[MAXID];
    int index;
    scanf("%s",str1_input);
    index=PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    if(encerra==1 && index!=-1){
        aeroportos[index].estado=false;
        aeroportos[index].partem=0;
        aeroportos[index].chegam=0;
        aeroportos[index].soma=0;
        aeroportos[index].conectados = 0;
    	for (int i = 0; i < numero_aeroportos; i++){
    		if (grafo[i][index] != 0){
    			if (grafo[index][i] == 0)
    				aeroportos[i].conectados -= 1;
    			total_voos[0] -= grafo[i][index];
    			aeroportos[i].chegam -= grafo[i][index];
    			aeroportos[i].soma -= grafo[i][index];
    			grafo[i][index] = 0;
    		}
    		if (grafo[index][i] != 0){
    			if (grafo[i][index] == 0)
    				aeroportos[i].conectados -= 1;
    			total_voos[0] -= grafo[index][i];
    			aeroportos[i].partem -= grafo[index][i];
    			aeroportos[i].soma -= grafo[index][i];
    			grafo[index][i] = 0;
    		}
    	}
    }

    else if(encerra==0 && index!=-1)
        aeroportos[index].estado=true;
    else
        printf("*Aeroporto %s inexistente\n",str1_input);
}