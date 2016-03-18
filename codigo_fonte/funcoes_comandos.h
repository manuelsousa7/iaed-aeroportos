
//Cria um novo aeroporto
Aeroporto CriaAeroporto(int capacidade,char id[],int numero_aeroportos)
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	aeroporto.partem=0;
	aeroporto.chegam=0;
	aeroporto.crono=numero_aeroportos;
	strcpy(aeroporto.id,id);
	return aeroporto;
}
/*
//Altera a capacidade do aeroporto
Aeroporto AlteraCapacidadeAeroporto(int capacidade,char id[])
{
	
}*/

void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos)
{
	int i;
	for (i = 0 ; i < numero_aeroportos ; i++)
		printf("%s:%d:%d:%d\n",aeroportos[i].id,aeroportos[i].capacidade,aeroportos[i].partem,aeroportos[i].chegam);
}