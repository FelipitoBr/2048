#include <stdio.h>
#include <stdlib.h>

#define LIGNE 4
#define COLONNE 4
void affichetab(char tab[LIGNE][COLONNE])
{
	for(int i=0; i<LIGNE; i++)
	{
		for(int j= 0; j<COLONNE; j++)
		{
			printf("[%c]",tab[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char **argv)
{
	char tab[LIGNE][COLONNE];
	
	for(int i=0; i<LIGNE; i++)
		for(int j= 0; j<COLONNE; j++)
			{tab[i][j]=" ";}
	affichetab(tab);
	
	return 0;
}
