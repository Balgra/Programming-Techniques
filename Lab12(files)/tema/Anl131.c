void UptoLow(FILE *fin)
{
	int c;

	while((c=fgetc(fin))!=EOF)
	{
		if(c>='a' && c<='z')
		{

			fprintf(fin,"%c",c-32);
		}

	}

}

int main(int argc, char *argv[])
{
	//printf("It works %s %d \n",argv[0],argc);

	FILE *fin;

	if(argc>1)
	{
		fin=fopen(argv[1],"r+");
	}
	else
	{
		printf("probleme la command line \n");

		return 0;
	}

	if(fin==NULL)
	{
		printf("probleme la fisier pls no \n");

		return 0;
	}


	UptoLow(fin);

	fclose(fin);

}