#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
using namespace std;

int next_move(int i, int *visited){
	int rand_move=(rand()%i)+1;
	int j=1;
	while(rand_move){
		if (visited[j]==0)
		{
			rand_move--;
			j++;
		}
		else
			j++;
	}
	return --j;
}

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
	

	while(1){
		int visited[no_cities+1]={0};
		start = rand()%no_cities +1;
		visited[start]=1;
		path[1]=start;
		next=start;
		cost=0;
		rep(i,2,(no_cities+1)/2)
		{
			prev=next;
			next=next_move(no_cities - i + 1,visited);
			path[i]=next;
			visited[next]=1;
			cost+=b[prev][next];
		}
		rep(i,(no_cities+1)/2,no_cities+1)
		{
			prev=next;
			next=next_move(no_cities - i + 1,visited);
			path[i]=next;
			visited[next]=1;
			cost+=b[prev][next];
			if (cost>min_cost)
			{
				break;
			}
		}
		if (cost < min_cost)
		{
			min_cost=cost;
			cout<<"Path: ";
			rep(i,1,no_cities+1){
				cout<<path[i]<<" ";
			}
			cout<<min_cost<<"\n";
		}
	}
	

	return 0;
}