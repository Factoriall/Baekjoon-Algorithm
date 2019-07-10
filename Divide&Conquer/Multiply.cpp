#include <iostream>
using namespace std;

long long int c;

long long int dac(long long int n, long long int p) {
	if (p == 1)
		return n % c;
	if (p % 2 == 0)
		return ((dac(n, p / 2) % c) * (dac(n, p / 2) % c)) % c;
	else
		return ((dac(n, p / 2) * n % c) * (dac(n, p / 2) % c)) % c;
}

int main() {
	long long int a, b;

	cin >> a >> b >> c;

	long long int result = dac(a, b);

	cout << result << '\n';

	return 0;
}