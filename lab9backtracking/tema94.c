int vcoins[50]; // vector where i have coins
int vectsols[50];//the vector for solutions
int counter=0;//counter for the vector of sols to know the on which elem i;m

int coins(int suma,int indexcoins)
{
	//main action where i put my  solutions 
	//index coins ii sa vad pe ce coin sunt
	if(suma>=vcoins[indexcoins] && indexcoins!=-1)
	{
		vectsols[counter]=vcoins[indexcoins];
		counter++;

		 return coins(suma-vcoins[indexcoins],indexcoins);

	}

	// if the sum is different than 0 and i still have coins left and check.
	if(suma!=0 && indexcoins!=0)
	{	
		return coins(suma,indexcoins-1);
	}
	//just the printing of the solution for one index
	if(suma==0)
	{
		for(int i=0;i<counter;i++)
		{
			printf("%d ",vectsols[i]);
		}
		printf("\n");
		counter=0;
		return 0;
	}
	
	

return 0;


}

int main()
{
	int nrcoins,suma;
	printf("Give the number of how many coins and the sum, after that the actual coins exe 1 5 10 25 \n");
	scanf("%d %d",&nrcoins,&suma);

	for(int i=0;i<nrcoins;i++)
	{
		scanf("%d", &vcoins[i]);
	}


	// here i start from coin max to coin min. (de la mic la mare, o sa fac o functie care sa imi sorteze asta dupa :))) )
	for(int i=nrcoins;i>=1;i--)
	{

		coins(suma,i-1);

	}

	return 0;

}