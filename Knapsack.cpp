#include <stdio.h>

#define N 4 // number of items
#define MW 5 // Max Weight
int ItemWeights[] = {2,1,3,2};
int ItemValues[] = {12,10,20,15};
int MaxWeight = MW;
int SolveM[N+1][MW+1] = {0};

int max(int, int); // return value of item which it is more greater
void printSolveM(); // print our matrix which we use it to solve problem
void solve(); // main algorithm
void printsolveditems(); //we solved but we don't know which items we used so we need to print them

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void printSolveM()
{
	for(int i=0; i<=N; i++)
	{
		puts("\n");
		for(int j=0; j<=MW; j++)
			printf("%2d ", SolveM[i][j]);
	}
		
}

void solve()
{
	for(int i=1; i<=N; i++)
		for(int j=1; j<=MW; j++)
			if(ItemWeights[i-1] > j)
				SolveM[i][j] = SolveM[i-1][j];
			else
				SolveM[i][j] = max(SolveM[i-1][j], ItemValues[i-1] + SolveM[i-1][j-ItemWeights[i-1]]);

			
}

void printsolveditems()
{
	int i=N,j=MW;
	while (j > 0)
	{
		if(SolveM[i][j] != SolveM[i-1][j]) // we use it this item 
		{
			j -= ItemWeights[i-1]; 
			printf("%d ", i);
		}
		i--;
	}
}

int main()
{
	puts("Before");
	printSolveM();
	solve();
	puts("\nAfter");
	printSolveM();
	puts("used");
	printsolveditems();
	return 0;
}
