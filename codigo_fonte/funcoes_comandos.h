
//Cria um novo aeroporto
Aeroporto cria_aeroporto(int capacidade,char id[],int numero_aeroportos)
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	aeroporto.crono=numero_aeroportos;
	strcpy(aeroporto.id,id);
	return aeroporto;
}

//Altera a capacidade do aeroporto
Aeroporto altera_capacidade_aeroporto(int capacidade,char id[])
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	strcpy(aeroporto.id,id);
	return aeroporto;
}