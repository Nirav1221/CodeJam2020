#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Empty(int mat[5][5], int &i, int &j, int n)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j] == 0)
			{	
			return 1;
            }
		}
	}
	return 0;
}

int trace(int mat[5][5], int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum+=mat[i][i];
	}
	return sum;
}
int uniqueRow(int mat[5][5], int r, int a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(mat[r][i] == a )
		{
			return 0;
		}
	}
	return 1;
}

int uniqueCol(int mat[5][5], int c, int a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(mat[i][c] == a )
		{
			return 0;
		}
	}
	return 1;
}
int genMat(int mat[5][5], int n, int k)
{	
	int i,r, c, a, sum;
	
	if(Empty(mat,r,c,n) == 0)
	{
		return 1;
	}
	//Generate and check all possible traces for unique row and columns
	for(a=1;a<=n;a++)
	{
		if(uniqueRow(mat, r, a, n) * uniqueCol(mat, c, a , n) == 1)
			{	
				mat[r][c] = a;
				if(genMat(mat, n,k) == 1 && trace(mat,n) == k)
				{
					return 1;
				}
				mat[r][c] = 0;
			}
				
	}
	//No such trace found.
	return 0;
	
}

int main()
{
	int i,j,l,t;
	cin >> t;
	int n[t],k[t];
	//Only works for 1st case .. hence 44...
	int grid [44][5][5] = {0};
	for(i=0;i<t;i++)
	{
		cin >> n[i] >> k[i];

		if(genMat(grid[i], n[i], k[i]) == 1)
		{
			printf("Case #%d: POSSIBLE\n",i+1);
			for(j=0; j<n[i]; j++)
			{
				for(l=0; l<n[i]; l++)
				{
					printf("%d ", grid[i][j][l]);
				}
				cout << "\n";
			}
		}
		
		else
			printf("Case #%d: IMPOSSIBLE\n",i+1);	
		
	}
	
}
// Will add commmments soon
