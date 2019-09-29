#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MIN = -987654321;

long long dp[15];
char function[30];

long long dynamic_programming(int n) {
	long long& ret = dp[n / 2];
	if (ret != MIN)
		return ret;
	if (n == 0)
		return ret = function[0] - '0';

	long long result;
	switch (function[n - 1]) {
	case '+':
		result = dynamic_programming(n - 2) + (function[n] - '0');
		break;
	case '-':
		result = dynamic_programming(n - 2) - (function[n] - '0');
		break;
	case '*':
		result = dynamic_programming(n - 2) * (function[n] - '0');
		break;
	}

	if (n >= 4) {
		switch (function[n - 3]) {
		case '+':
			if (function[n - 1] == '+')
				result = max(result, dynamic_programming(n - 4) + ((function[n - 2] - '0') + (function[n] - '0')));
			if (function[n - 1] == '-')
				result = max(result, dynamic_programming(n - 4) + ((function[n - 2] - '0') - (function[n] - '0')));
			if (function[n - 1] == '*')
				result = max(result, dynamic_programming(n - 4) + ((function[n - 2] - '0') * (function[n] - '0')));
			break;
		case '-':
			if (function[n - 1] == '+')
				result = max(result, dynamic_programming(n - 4) - ((function[n - 2] - '0') + (function[n] - '0')));
			if (function[n - 1] == '-')
				result = max(result, dynamic_programming(n - 4) - ((function[n - 2] - '0') - (function[n] - '0')));
			if (function[n - 1] == '*')
				result = max(result, dynamic_programming(n - 4) - ((function[n - 2] - '0') * (function[n] - '0')));
			break;
		case '*':
			if (function[n - 1] == '+')
				result = max(result, dynamic_programming(n - 4) * ((function[n - 2] - '0') + (function[n] - '0')));
			if (function[n - 1] == '-')
				result = max(result, dynamic_programming(n - 4) * ((function[n - 2] - '0') - (function[n] - '0')));
			if (function[n - 1] == '*')
				result = max(result, dynamic_programming(n - 4) * ((function[n - 2] - '0') * (function[n] - '0')));
			break;
		}
	}
	//printf("%d %lld\n", n, result);

	return ret = result;
}

int main() {
	int N;
	scanf("%d", &N);
	scanf("%s", function);

	fill(dp, dp + 15, MIN);

	printf("%lld", dynamic_programming(N - 1));

	return 0;
}