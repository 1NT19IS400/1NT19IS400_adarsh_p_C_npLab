#include <stdio.h>
#include <limits.h>
int nodes;

void BellmanFord(int graph[][nodes], int nodes, int src)
{
	
	int dist[nodes], via[nodes];
	for(int i = 0; i<nodes; i++){
		dist[i] = 999;
		via[i] = src;
	}
	
	dist[src] = 0;
	
	for(int i = 0; i<nodes-1; i++){
		for(int j = 0; j<nodes; j++){
			if(dist[j] > dist[i]+graph[i][j]){
				dist[j] = dist[i]+graph[i][j];
				via[j] = i;
			}
			
		}
	}
	
	printf("to  via  cost\n");
	for (int i = 0; i < nodes; i++)
		printf("%d    %d    %d\n", i+1, via[i]+1, dist[i]);
}

int main()
{

	printf("Enter the number of nodes : ");

	scanf("%d", &nodes);
	
	int graph[nodes][nodes];
	printf("Enter the cost matrix: \n");
	
	for(int i = 0; i<nodes; i++){
		for(int j = 0; j<nodes; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	
	for(int i = 0; i<nodes; i++){
		printf("\n--------Routing for node %d---------\n", i+1);
		BellmanFord(graph, nodes, i);
	}
	
	return 0;
}