/******************************************************************************
 * CriaAeroporto()
 *
 * Arguments:   aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  cria novo aeroporto e inicializa variaveis a 0
 *****************************************************************************/
void CriaAeroporto(Aeroporto aeroportos[], int numero_aeroportos)
{
	int cap;
	char str1_input[MAXID];
	scanf("%s %d", str1_input, &cap);
	Aeroporto aeroporto;
	aeroporto.capacidade = cap;
	aeroporto.estado = true;
	aeroporto.conectados = 0;
	aeroporto.soma = 0;
	aeroporto.partem = 0;
	aeroporto.chegam = 0;
	aeroporto.crono = numero_aeroportos;
	strcpy(aeroporto.id,str1_input);
	aeroportos[numero_aeroportos] = aeroporto;
}

/************************************************************************************************
 * AlteraCapacidadeAeroporto()
 *
 * Arguments:   aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  altera a capacidade do aeroporto se as condicoes necessarias se confirmarem
 ***********************************************************************************************/
void AlteraCapacidadeAeroporto(Aeroporto aeroportos[], int numero_aeroportos)
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

/**********************************************************************
 * ImprimeAeroportos()
 *
 * Arguments:	aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  imprime todos os aeroportos adicionados
 **********************************************************************/
void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos)
{
	int i;
	for (i = 0 ; i < numero_aeroportos; i++){
		printf("%s:%d:%d:%d\n",aeroportos[i].id,aeroportos[i].capacidade,aeroportos[i].partem,aeroportos[i].chegam);
    }
}

/*****************************************************************************************************************
 * AdicionaRemoveVoo()
 *
 * Arguments:   grafo:   			matrix com os voos entre os diferentes aeroportos
 *				aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *				ida_volta:			boolean a true se a operacao for de ida e volta
 *				remover:			boolean a true se a operacao for de remocao
 *				popular:			vetor de dimensao 1 que contém informacoes sobre o aeroporto mais popular
 *				total_voos:			vetor de dimensao 1 que indica o numero total de voos
 *
 * Returns: void
 * Side-Effects: none
 * Description:  adiciona ou remove voos de ida e volta ou so de ida se as condicoes necessarias se confirmarem
 *****************************************************************************************************************/
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover, Voo popular[], long int total_voos[]){

	int index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID];

	scanf("%s %s", str1_input, str2_input);
	index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
	index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

	if (index_1 != -1 && index_2 != -1 && aeroportos[index_1].estado && aeroportos[index_2].estado){
		//se for para remover
		if (remover){
			//se o numero de voos for maior que 0
			if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] > 0 && !(ida_volta)){

				AdicionaRemove(grafo, aeroportos, remover, total_voos, index_1, index_2);
				RemovePopular(grafo, aeroportos, numero_aeroportos, popular, total_voos);

				//Se os aeroportos deixarem de estar conectados
				if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] == 0 && grafo[aeroportos[index_1].crono][aeroportos[index_2].crono] == 0){
					aeroportos[index_1].conectados -= 1;
					aeroportos[index_2].conectados -= 1;
				}
			}
			else if (!ida_volta){
				printf("*Impossivel remover voo %s %s\n", str1_input, str2_input);
			}
		}
		//se for para adicionar
		else {
			//se os aeroportos nao tiverem excedido a capacidade
			if (aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade && aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade && !(ida_volta)){
				//Se os aeroportos ainda nao estavam conectados
				if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] == 0 && grafo[aeroportos[index_1].crono][aeroportos[index_2].crono] == 0){
					aeroportos[index_1].conectados += 1;
					aeroportos[index_2].conectados += 1;
				}

				AdicionaRemove(grafo, aeroportos, remover, total_voos, index_1, index_2);
				VerificaPopular(grafo, aeroportos, popular, ida_volta, total_voos, index_1, index_2, str1_input, str2_input);
			}

			else if (!ida_volta){
				if (!(aeroportos[index_1].soma + 1 <= aeroportos[index_1].capacidade))
					printf("*Impossivel adicionar voo %s %s\n", str1_input, str2_input);
				if (!(aeroportos[index_2].soma + 1 <= aeroportos[index_2].capacidade))
					printf("*Impossivel adicionar voo %s %s\n", str1_input, str2_input);
			}
		}

		if (ida_volta){
			//se for para remover
			if (remover) {
				if (grafo[aeroportos[index_1].crono][aeroportos[index_2].crono] > 0 && grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] > 0){

					AdicionaRemove(grafo, aeroportos, remover, total_voos, index_1, index_2);
					AdicionaRemove(grafo, aeroportos, remover, total_voos, index_2, index_1);
					RemovePopular(grafo, aeroportos, numero_aeroportos, popular, total_voos);

					//Se os aeroportos deixarem de estar conectados
					if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] == 0 && grafo[aeroportos[index_1].crono][aeroportos[index_2].crono] == 0){
						aeroportos[index_1].conectados -= 1;
						aeroportos[index_2].conectados -= 1;
					}
				}
				else {
					printf("*Impossivel remover voo RT %s %s\n", str1_input, str2_input);
				}
			}
			//se for para adicionar
			else {
				if (aeroportos[index_2].soma + 2 <= aeroportos[index_2].capacidade && aeroportos[index_1].soma + 2 <= aeroportos[index_1].capacidade){
					//Se os aeroportos ainda nao estavam conectados
					if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] == 0 && grafo[aeroportos[index_1].crono][aeroportos[index_2].crono] == 0){
						aeroportos[index_1].conectados += 1;
						aeroportos[index_2].conectados += 1;
					}

					AdicionaRemove(grafo, aeroportos, remover, total_voos, index_1, index_2);
					AdicionaRemove(grafo, aeroportos, remover, total_voos, index_2, index_1);
					VerificaPopular(grafo, aeroportos, popular, ida_volta, total_voos, index_1, index_2, str1_input, str2_input);
					VerificaPopular(grafo, aeroportos, popular, ida_volta, total_voos, index_2, index_1, str2_input, str1_input);
				}

				else{
					if (!(aeroportos[index_2].soma + 2 <= aeroportos[index_2].capacidade))
						printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
					if (!(aeroportos[index_1].soma + 2 <= aeroportos[index_1].capacidade))
						printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
				}
			}
		}
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
	}
}

/******************************************************************************************
 * AdicionaRemove()
 *
 * Arguments:   grafo:   			matrix com os voos entre os diferentes aeroportos
 *				aeroportos:   		estrutura dos aeroportos (todos)
 *				remover:			boolean a true se a operacao for de remocao
 *				total_voos:			vetor de dimensao 1 que indica o número total de voos
 *				index_1:			indice do aeroporto de partida
 *				index_2:			indice do aeroporto de chegada
 *
 * Returns: void
 * Side-Effects: none
 * Description:  adiciona ou remove um voo de uma direção
 ******************************************************************************************/
void AdicionaRemove(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], bool remover, long int total_voos[], int index_1, int index_2)
{
	int num;

	if (remover)
		num = -1;
	else
		num = 1;

	grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] += num;
	aeroportos[index_1].partem += num;
	aeroportos[index_1].soma += num;
	aeroportos[index_2].chegam += num;
	aeroportos[index_2].soma += num;
	total_voos[0] += num;
}

/**************************************************************************************************************
 * VerificaPopular()
 *
 * Arguments:   grafo:   			matrix com os voos entre os diferentes aeroportos
 *				aeroportos:   		estrutura dos aeroportos (todos)
 *				popular:			vetor de dimensao 1 que contém informações sobre o aeroporto mais popular
 *				ida_volta:			boolean a true se a operacao for de ida e volta
 *				total_voos:			vetor de dimensao 1 que indica o número total de voos
 *				index_1:			indice do aeroporto de partida
 *				index_2:			indice do aeroporto de chegada
 *				str1_input:			nome do aeroporto de partida
 *				str2_input:			nome do aeroporto de chegada
 *
 * Returns: void
 * Side-Effects: none
 * Description:  verifica se os voos entre os dois aeroportos passam a ser populares
 **************************************************************************************************************/
void VerificaPopular(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], Voo popular[], bool ida_volta, long int total_voos[], int index_1, int index_2, char str1_input[], char str2_input[])
{
	if (total_voos[0] == 1)
	{
		popular[0].voos = grafo[aeroportos[index_2].crono][aeroportos[index_1].crono];
		strcpy(popular[0].partida,str1_input);
		popular[0].partida_crono = aeroportos[index_1].crono;
		strcpy(popular[0].chegada,str2_input);
		popular[0].chegada_crono = aeroportos[index_2].crono;
	}
	else
	{

		if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] >= popular[0].voos)
		{
			if (grafo[aeroportos[index_2].crono][aeroportos[index_1].crono] == popular[0].voos)
			{
				if (popular[0].partida_crono >= aeroportos[index_1].crono)
				{
					if (popular[0].partida_crono == aeroportos[index_1].crono)
					{
						if (popular[0].chegada_crono > aeroportos[index_2].crono)
						{
							strcpy(popular[0].partida,str1_input);
							popular[0].partida_crono = aeroportos[index_1].crono;
							strcpy(popular[0].chegada,str2_input);
							popular[0].chegada_crono = aeroportos[index_2].crono;
						}
					}
					else
					{
						strcpy(popular[0].partida,str1_input);
						popular[0].partida_crono = aeroportos[index_1].crono;
						strcpy(popular[0].chegada,str2_input);
						popular[0].chegada_crono = aeroportos[index_2].crono;
					}
				}
			}
			else
			{
				popular[0].voos = grafo[aeroportos[index_2].crono][aeroportos[index_1].crono];
				strcpy(popular[0].partida,str1_input);
				popular[0].partida_crono = aeroportos[index_1].crono;
				strcpy(popular[0].chegada,str2_input);
				popular[0].chegada_crono = aeroportos[index_2].crono;
			}
		}
	}
}

/**************************************************************************************************************
 * RemovePopular()
 *
 * Arguments:   grafo:   			matrix com os voos entre os diferentes aeroportos
 *				aeroportos:   		estrutura dos aeroportos (todos)
 *				popular:			vetor de dimensao 1 que contém informações sobre o aeroporto mais popular
 *				total_voos:			vetor de dimensao 1 que indica o número total de voos
 *
 * Returns: void
 * Side-Effects: none
 * Description:  verifica se os voos entre os dois aeroportos deixam de ser populares
 **************************************************************************************************************/
void RemovePopular(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, Voo popular[], long int total_voos[])
{
	if (total_voos[0] != 0)
	{
		int maior = 0, maior_i = -1, maior_j = -1;
		for (int i = 0; i < numero_aeroportos; i++)
		{
			for (int j = 0; j < numero_aeroportos; j++)
			{
				if (grafo[i][j] >= maior)
				{
					if (grafo[i][j] == maior)
					{
						if (popular[0].partida_crono >= aeroportos[i].crono)
						{
							if (popular[0].partida_crono == aeroportos[i].crono)
							{
								if (popular[0].chegada_crono > aeroportos[j].crono)
								{
									maior_i = i;
									maior_j = j;
									maior = grafo[i][j];
								}
							}
							else
							{
								maior_i = i;
								maior_j = j;
								maior = grafo[i][j];
							}
						}
					}
					else
					{
						maior_i = i;
						maior_j = j;
						maior = grafo[i][j];
					}
				}
			}
		}
		if (maior_i != -1 && maior_j != -1)
		{
			popular[0].voos = maior;
			strcpy(popular[0].partida,aeroportos[maior_i].id);
			popular[0].partida_crono = aeroportos[maior_i].crono;
			strcpy(popular[0].chegada,aeroportos[maior_j].id);
			popular[0].chegada_crono = aeroportos[maior_j].crono;
		}
	}
}
/******************************************************************************************
 * RetornaVoo()
 *
 * Arguments:   grafo:   			matrix com os voos entre os diferentes aeroportos
 *				aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  imprime o numero de voos entre dois aeroportos indicados pelo utilizador
 *****************************************************************************************/
void RetornaVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos){
	int index_1, index_2;
	char str1_input[MAXID], str2_input[MAXID];

	scanf("%s %s", str1_input, str2_input);
	index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
	index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

	if (index_1 == -1)
		printf("*Aeroporto %s inexistente", str1_input);

	if (index_2 == -1)
		printf("*Aeroporto %s inexistente", str2_input);

	if (index_1 != -1 && index_2 != -1)
		printf("Voos entre cidades %s:%s:%d:%d\n", str1_input, str2_input, grafo[aeroportos[index_2].crono][aeroportos[index_1].crono], grafo[aeroportos[index_1].crono][aeroportos[index_2].crono]);
}

/******************************************************************************************
 * AeroportoPopular()
 *
 * Arguments:	aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  imprime o aeroporto com mais voos a sair e a entrar
 *****************************************************************************************/
void AeroportoPopular(Aeroporto aeroportos[], int numero_aeroportos){
	int maior = 0, indice = 0;

	maior = (aeroportos[0].soma);

	for (int iterador = 1; iterador < numero_aeroportos; iterador++)
		if (maior < (aeroportos[iterador].soma)){
			maior = (aeroportos[iterador].soma);
			indice = iterador;
		}
		else if (maior == (aeroportos[iterador].soma && aeroportos[iterador].crono < aeroportos[indice].crono)){
			maior = (aeroportos[iterador].soma);
			indice = iterador;
		}

	printf("Aeroporto com mais rotas %s:%d:%d\n", aeroportos[indice].id,aeroportos[indice].partem,aeroportos[indice].chegam);
}

/****************************************************************************
 * AeroportoConectado()
 *
 * Arguments:	aeroportos:   		estrutura dos aeroportos (todos)
 *              numero_aeroportos:  numero de aeroportos atuais
 *
 * Returns: void
 * Side-Effects: none
 * Description:  imprime o aeroporto com mais conexoes com outros aeroportos
 ****************************************************************************/
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

	printf("Aeroporto com mais ligacoes %s:%d\n", aeroportos[indice].id,maior);
}

/******************************************************************************************
* HistogramaImprime()
*
* Arguments:	aeroportos:   		matrix 2D que representa o grafo dos voos entre os diferentes aeroportos
*              	numero_aeroportos:  numero de aeroportos atuais
*
* Returns: void
* Side-Effects: none
* Description:  reabre ou encerra o aeroporto e apaga os voos no segundo caso
*****************************************************************************************/
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

/******************************************************************************************
* EncerraReabreAeroporto()
*
* Arguments:	grafo:   			matrix 2D que representa o grafo dos voos entre os diferentes aeroportos
* 				aeroportos:   		estrutura dos aeroportos (abertos e fechados)
*              	numero_aeroportos:  numero de aeroportos atuais
*				total_voos:			vetor de dimensao 1 que indica o numero total de voos
*				encerra:			booleano que indica se encerra ou se reabre aeroporto
*
* Returns: void
* Side-Effects: none
* Description:  reabre ou encerra o aeroporto e apaga os voos no segundo caso
*****************************************************************************************/
void EncerraReabreAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, long int total_voos[], bool encerra)
{
    char str1_input[MAXID];
    int index;
    scanf("%s",str1_input);
    index = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    if(encerra==1 && index!=-1){
        aeroportos[index].estado=false;
        aeroportos[index].partem=0;
        aeroportos[index].chegam=0;
        aeroportos[index].soma=0;
        aeroportos[index].conectados = 0;
    	for (int i = 0; i < numero_aeroportos; i++){
    		if (grafo[aeroportos[i].crono][aeroportos[index].crono] != 0){
    			if (grafo[aeroportos[index].crono][aeroportos[i].crono] == 0)
    				aeroportos[i].conectados -= 1;
    			total_voos[0] -= grafo[aeroportos[i].crono][aeroportos[index].crono];
    			aeroportos[i].chegam -= grafo[aeroportos[i].crono][aeroportos[index].crono];
    			aeroportos[i].soma -= grafo[aeroportos[i].crono][aeroportos[index].crono];
    			grafo[aeroportos[i].crono][aeroportos[index].crono] = 0;
    		}
    		if (grafo[aeroportos[index].crono][aeroportos[i].crono] != 0){
    			if (grafo[aeroportos[i].crono][aeroportos[index].crono] == 0)
    				aeroportos[i].conectados -= 1;
    			total_voos[0] -= grafo[aeroportos[index].crono][aeroportos[i].crono];
    			aeroportos[i].partem -= grafo[aeroportos[index].crono][aeroportos[i].crono];
    			aeroportos[i].soma -= grafo[aeroportos[index].crono][aeroportos[i].crono];
    			grafo[aeroportos[index].crono][aeroportos[i].crono] = 0;
    		}
    	}
    }
    else if(encerra==0 && index!=-1)
        aeroportos[index].estado=true;
    else
        printf("*Aeroporto %s inexistente\n",str1_input);
}