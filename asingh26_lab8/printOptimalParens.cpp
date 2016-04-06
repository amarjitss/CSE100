//Amarjit Singh

#include <iostream>
#include <vector>
#include <limits>
#include <list>
#include <cstddef>
#include <string>

using namespace std;

int MatrixChainOrder(int *p, int size);
void PrintOptimalParens(vector<vector<int> > s, int i, int j);

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
			//p[i] = input;
		}
		
		MatrixChainOrder(p, x+1);
		cin >> x;
	}
}

int MatrixChainOrder(int *p, int size)
{
	int j=0, q=0;
	//int size = (sizeof p /sizeof p[0]);
	int n = size -1;
	int m[n][n];

	vector< vector<int> > s;
	s.resize(n);

	for(int i = 0; i<n; i++)
	{
		s[i].resize(n);
	}
	
	for(int i =0; i<n; i++)
	{
		m[i][i] =0;
	}
	
	for(int l = 2; l<=n; l++)
	{
		for(int i = 0; i<=n-l; i++)
		{
			j = i + l -1;
			int imax = numeric_limits<int>::max();
			m[i][j] = imax;
			
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

	PrintOptimalParens(s,0,n-1);
	cout << endl;
}

void PrintOptimalParens(vector<vector<int> > s, int i, int j)
{
	if(i==j)
	{
		cout<<"A"<< i;
	}
	else
	{
		cout<<"(";
		PrintOptimalParens(s, i, s[i][j]);
		PrintOptimalParens(s, (s[i][j])+1, j);
		cout<<")";
	}
}
