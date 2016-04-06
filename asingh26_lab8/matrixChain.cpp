//Amarjit Singh

#include <iostream>
#include <vector>
#include <limits>
#include <list>
#include <cstddef>
#include <string>

using namespace std;

void MatrixChainOrder(int *p, int size);

int main()
{
	//variables
	int x=-1;
	cin>>x;
	
	while(x!=0)
	{
		if(x==0)
			break;
		int p[x];
		for(int i = 0; i < (x+1); i++)
		{
			cin >> p[i];
		}
		
		MatrixChainOrder(p, x+1);
		cin >> x;
	}
}

void MatrixChainOrder(int *p, int size)
{
	int j=0, q=0;
	int n = size -1;
	int m[n][n];
	int s[n][n];
	
	for(int i =0; i<n; i++)
	{
		m[i][i] =0;
	}
	
	for(int l = 2; l<=n; l++)
	{
		for(int i = 0; i<=n-l; i++)
		{
			j = i + l -1;
			int i_max = numeric_limits<int>::max();
			m[i][j] = i_max;
			
			for(int k = i; k<j; k++)
			{
				q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}//end if
			}// for k
		}//for i
	}// for l

	cout<< m[0][n-1]<<endl;
}

