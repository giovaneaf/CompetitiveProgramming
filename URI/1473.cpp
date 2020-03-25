#include <stdio.h>

int main()
{
	int row, col;
	while(scanf("%d %d", &row, &col) != EOF)
	{
		int M[300][300];
		int row1;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
			{
				scanf("%d", &M[i][j]);
				if(M[i][j] == 1)
					row1 = i;
			}
		int swaps = 0;
		bool solvable = true;
		for(int j = 0; j < col; j++)
		{
			if(M[row1][j] != j+1)
			{
				swaps++;
				int index = -1;
				for(int k = j+1; k < col; k++)
					if(M[row1][k] == j+1)
						index = k;
				if(index == -1)
				{
					solvable = false;
					break;
				}
				else
				{
					for(int k = 0; k < row; k++)
					{
						int aux = M[k][index];
						M[k][index] = M[k][j];
						M[k][j] = aux;
					}
				}
			}
		}
		int val = 1;
		if(solvable)
		{
			for(int i = 0; i < row; i++)
			{
				if(M[i][0] != val)
				{
					swaps++;
					int index = -1;
					for(int k = i+1; k < row; k++)
						if(M[k][0] == val)
							index = k;
					if(index == -1)
					{
						solvable = false;
						break;
					}
					else
					{
						for(int k = 0; k < col; k++)
						{
							int aux = M[index][k];
							M[index][k] = M[i][k];
							M[i][k] = aux;
						}
					}
				}
				val += col;
			}
			if(solvable)
			{
				val = 1;
				for(int i = 0; i < row && solvable; i++)
					for(int j = 0; j < col; j++)
					{
						if(M[i][j] != val)
						{
							solvable = false;
							break;
						}
						val++;
					}	
			}
		}
		if(solvable)
			printf("%d\n", swaps);
		else
			printf("*\n");
	}
	return 0;
}