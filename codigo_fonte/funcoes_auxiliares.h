int PesquisaBinaria (int x, int v[], int e, int d){ 
	int i = (e + d)/2;	
	if (v[i] == x)
		return i;	
	if (e == d)
		return -1; 
	else if (v[i] < x)
		return PesquisaBinaria(x, v, i+1, d);
	return PesquisaBinaria(x, v, e, i-1);
}

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j){
        while(valor[i] < x && i < direita)
            i++;
        while(valor[j] > x && j > esquerda)
            j--;
        if(i <= j){
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
        quickSort(valor, esquerda, j);
    if(i < direita)
        quickSort(valor,  i, direita);
}
