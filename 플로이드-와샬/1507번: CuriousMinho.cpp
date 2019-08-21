#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main() {
	int N;
	int dist[20][20];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &dist[i][j]);

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != k && j != k && dist[i][j] != INF ){
					if (dist[i][j] == dist[i][k] + dist[k][j]) 
						dist[i][j] = INF;
					
					else if (dist[i][j] > dist[i][k] + dist[k][j]) {
						printf("-1\n");
						return 0;
					}
				}
			}
			
		}

		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] != INF)
					printf("%d\t", dist[i][j]);
				else
					printf("INF\t");
			}
			printf("\n");
		}
		printf("\n");*/
	}


	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] != INF)
				printf("%d\t", dist[i][j]);
			else
				printf("INF\t");
		}
		printf("\n");
	}*/


	
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (dist[i][j] != INF) {
				result += dist[i][j];
			}
		}
	}
	printf("%d\n", result);

	return 0;
}
