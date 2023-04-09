
#ifdef __unix__
	#define CLS "clear"
#elif defined(_WIN32) || defined(WIN32)
	#define CLS "cls"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNE 4
#define COLONNE 4

void affichetab(int tab[LIGNE][COLONNE])
{
	for(int i=0; i<LIGNE; i++)
	{
		for(int j=0; j<COLONNE; j++)
		{
			printf("[%d]",tab[i][j]);
		}
		printf("\n");
	}
}
void gen(int tab[LIGNE][COLONNE])
{
	tab[rand()%4][rand()%4]=2;
}
void move(int tab[LIGNE][COLONNE], int key)
{
	int current;
	if(key==4||key==6)
	{
		for(int i =0; i<LIGNE; i++)
		{
			for(int j =0; j<COLONNE; j++)
			{
				if(key==6)
					current=3;
				else
					current=0;
				if(tab[i][j]!=0)
				{
					if(tab[i][current]==0)
					{
						tab[i][current]=tab[i][j];
						tab[i][j]=0;
					 }
				}
			}
		}
	}
	else if(key==8||key==2)
	{
		for (int j = 0; j < 4; j++) 
		{
			if(key==8)
				current = 0;
			else
				current=3;
			for (int i = 1; i < 4; i++) 
			{
				if (tab[i][j] != 0) 
				{
					if (tab[current][j] == 0) 
					{
						tab[current][j] = tab[i][j];
						tab[i][j] = 0;
					}
				}
			}
		}
	}
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int tab[LIGNE][COLONNE]={0};
	int key;
	tab[2][2]=2;
	tab[3][1]=2;
	while(1)
	{	printf("\n");
		affichetab(tab);
		printf("8: ↑\n2: ↓\n4: ←\n6:→ ");
		scanf("%d", &key);
		move(tab,key);
		printf("\n");
		affichetab(tab);
	}
	return 0;
}



