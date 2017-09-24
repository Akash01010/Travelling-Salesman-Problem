#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	string type;
	int no_cities;
	cin>>type;
	cin>>no_cities;
	int path[no_cities+1],start,prev,next;
	float cost, a[no_cities+1][2],b[no_cities+1][no_cities+1],min_cost=9999999;
	rep(j,1,no_cities+1)
	{
		cin>>a[j][0]>>a[j][1];
	}
	rep(i,1,no_cities+1)
	{
		rep(j,1,no_cities+1)
		{
				cin>>b[i][j];
		}
	}
	return 0;
}