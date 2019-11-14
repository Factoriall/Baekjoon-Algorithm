#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N, L;
		double result = 101;//결과는 무조건 101을 넘지 않는다.
		int schedule[1001] = { 0, };

		scanf("%d %d", &N, &L);

		for (int i = 0; i < N; i++)
			scanf("%d", &schedule[i]);

		for (int l = L; l <= N; l++) {
			int sum = 0;//전체 합
			for (int i = 0; i < l; i++)//0-(l-1) 범위 값 미리 넣기
				sum += schedule[i];
			//printf("%d\n", sum);

			int mini = sum;

			for (int i = l; i < N; i++) {//끝까지 탐색해서 가장 작은 묶음 찾기
				sum = sum + schedule[i] - schedule[i - l];//다음거 더하고 왼쪽 제거
				//printf("%d\n", sum);
				mini = min(sum, mini);
			}
			//printf("result: %lf, mini: %lf\n", result, mini / (double)l);
			result = min(result, mini / (double)l);
		}
		printf("%.10lf\n", result);
	}

	return 0;
}