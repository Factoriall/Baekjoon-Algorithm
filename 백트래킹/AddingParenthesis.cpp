#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MIN = -2147483647;

int N;
char function[20];
int sum = 0;
int result = MIN;

void dfs(int n) {
	if (n == N + 1) {
		//printf("%d\n", sum);
		result = max(result, sum);
		return;
	}

	int tmp = sum;
	if (n == 0) {
		sum = function[0] - '0';
		dfs(n + 2);
	}
	else {
		switch (function[n - 1]) {
		case '+':
			sum += function[n] - '0';
			dfs(n + 2);
			sum = tmp;
			if (n + 2 != N + 1) {
				if (function[n + 1] == '+')
					sum += ((function[n] - '0') + (function[n + 2] - '0'));
				else if (function[n + 1] == '-')
					sum += ((function[n] - '0') - (function[n + 2] - '0'));
				else
					sum += ((function[n] - '0') * (function[n + 2] - '0'));
			}
			dfs(n + 4);
			break;
		case '-':
			sum -= function[n] - '0';
			dfs(n + 2);
			sum = tmp;
			if (n + 2 != N + 1) {
				if (function[n + 1] == '+')
					sum -= ((function[n] - '0') + (function[n + 2] - '0'));
				else if (function[n + 1] == '-')
					sum -= ((function[n] - '0') - (function[n + 2] - '0'));
				else
					sum -= ((function[n] - '0') * (function[n + 2] - '0'));
			}
			dfs(n + 4);
			break;
		case '*':
			sum *= function[n] - '0';
			dfs(n + 2);
			sum = tmp;
			if (n + 2 != N + 1) {
				if (function[n + 1] == '+')
					sum *= ((function[n] - '0') + (function[n + 2] - '0'));
				else if (function[n + 1] == '-')
					sum *= ((function[n] - '0') - (function[n + 2] - '0'));
				else
					sum *= ((function[n] - '0') * (function[n + 2] - '0'));
			}
			dfs(n + 4);
			break;
		}
	}
	
	sum = tmp;

}

int main() {
	
	
	scanf("%d", &N);
	scanf("%s", function);
	
	dfs(0);
	printf("%d\n", result);

	return 0;
}