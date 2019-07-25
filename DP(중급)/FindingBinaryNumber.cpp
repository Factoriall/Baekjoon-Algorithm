#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long dp[32][32];//dp �ȿ��� n,m ���� ������ �����ϴ� ��Ʈ�� ���� ���� ����

long long binary(int n, int m) {//n: ������ ä���� �� ���� ��Ʈ��, m: ä������ ���� 1�� ����
	long long& ret = dp[n][m];
	if (ret != -1)
		return ret;
	if (n == 0 || m == 0)
		return ret = 1;

	ret = binary(n - 1, m);//���� ���� 0���� ä���� ��
	if (m > 0)
		ret += binary(n - 1, m - 1);//���� ���� 1�� ä���� ��
	
	return ret;
}

void printAns(int n, int m, long long r) {
	if (m == 0 || r == 1) {
		while (n > 0) {
			printf("0");
			n--;
		}
		return;
	}
	if (n == 0)
		return;

	if (r > dp[n - 1][m]) {//1�� ä������ ���
		printf("1");
		//printf("%d %d %d\n", n - 1, m - 1, r - dp[n - 1][m]);
		printAns(n - 1, m - 1, r - dp[n - 1][m]);
	}
	else {//0���� ä������ ���
		printf("0");
		//printf("%d %d %d\n", n - 1, m, r);
		printAns(n - 1, m, r);
	}
}

int main() {
	int N, L;
	long long I;

	scanf("%d %d %lld", &N, &L, &I);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= L; j++) {
			dp[i][j] = -1;
		}
	}

	binary(N, L);
	printAns(N, L, I);
	printf("\n");
	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= L; j++) {
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}