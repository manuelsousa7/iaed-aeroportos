int OrdenaAeroportosNome(const void *a, const void *b) 
{ 
	Aeroporto *ia = (Aeroporto *)a;
	Aeroporto *ib = (Aeroporto *)b;
	return strcmp(ia->id, ib->id);
} 


int OrdenaAeroportosCronologicamente(const void *a, const void *b) { 
	Aeroporto *ia = (Aeroporto *)a;
	Aeroporto *ib = (Aeroporto *)b;
	return ia->crono > ib->crono;
}


int OrdenaHistograma(const void *a, const void *b) { 
	Histograma *ia = (Histograma *)a;
	Histograma *ib = (Histograma *)b;
	return ia->soma - ib->soma;
}

/******************************************************************************************
* PesquisaBinariaHistograma()
*
* Arguments:	aeroportos:   		estrutura dos aeroportos (abertos e fechados)
*              	a_procurar:  		valor a procurar
*				numero_aeroportos: 	numero de aeroportos atuais (abertos e fechados)	
*
* Returns: int 	retorna o indice apos procurar, caso nao encontre retorna -1
* Side-Effects: none
* Complexity: 	O(log N) average-worst case | O(1) best case
* Description:  procura de forma eficiente o valor de uma soma na estrutura do histograma
*****************************************************************************************/
int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos){ 
	qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
	Aeroporto key, *res;
	strcpy(key.id ,a_procurar);
	res = bsearch(&key, aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
	size_t index = res - aeroportos;
	if (res == NULL)
		return -1;
	else
		return index;
}

/******************************************************************************************
* PesquisaBinariaHistograma()
*
* Arguments:	hist:   	estrutura dos elementos do histrograma (todos)
*              	a_procurar: valor a procurar
*				n_hist:		numero de valores já existentes no array de estruturas	
*
* Returns: int 	retorna o indice apos procurar, caso nao encontre retorna -1
* Side-Effects: none
* Complexity: 	O(log N) average-worst case | O(1) best case
* Description:  procura de forma eficiente o valor de uma soma na estrutura do histograma
*****************************************************************************************/
int PesquisaBinariaHistograma(Histograma hist[], int a_procurar, int n_hist){ 
	qsort(hist, n_hist, sizeof(Histograma), OrdenaHistograma);
	Histograma key, *res;
    key.soma=a_procurar;
    res = bsearch(&key, hist, n_hist, sizeof(Histograma), OrdenaHistograma);
    size_t index = res - hist;
	if (res == NULL)
		return -1;
	else
		return index;
}

/******************************************************************************************
* InsertionSortAeroporto()
*
* Arguments:	aeroportos:   		matrix 2D que representa o grafo dos voos entre os diferentes aeroportos
*              	numero_aeroportos:  numero de aeroportos atuais
*				crono:				booleano que indica se ordena cronologicamente (true) ou por id do aeroporto (false)
*
* Returns: void
* Side-Effects: none
* Complexity: 	O(N^2) worst case perfomance | O(n) best case perfomance
* Description:  ordena aeroportos cronologicamente ou por id do aeroporto
*****************************************************************************************/
void InsertionSortAeroporto(Aeroporto aeroportos[], int numero_aeroportos, bool crono){
    int i, j;
    Aeroporto atual;
    for (i = 1; i < numero_aeroportos; i++)
    {
        atual = aeroportos[i];
        j = i - 1;
        while (((j >= 0) && (atual.crono < aeroportos[j].crono && crono==1)) || ((j >= 0) && (atual.id > aeroportos[j].id && crono==0)))
        {
            aeroportos[j + 1] = aeroportos[j];
            j = j - 1;
        }
        aeroportos[j + 1] = atual;
    }
}