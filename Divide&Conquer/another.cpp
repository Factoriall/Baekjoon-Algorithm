#include <iostream>
using namespace std;

int o = 0;
int z = 0;
int mo = 0;

int paper[2187][2187];


void dac(int sy, int sx, int n) {
	int i, j;
	bool isSame = true;

	int first = paper[sy][sx];
	
	for (i = sy; i < sy+n; i++) {
		for (j = sx; j < sx+n; j++) {
			if (first != paper[i][j]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) {
		if (first == 1) 
			o++;
		else if (first == 0) 
			z++;
		else if (first == -1) 
			mo++;
	}
	else {
		int d = n / 3;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				dac(sy + (i*d), sx + (j*d), d);
			}
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	dac(0, 0, n);

	cout << mo << endl;
	cout << z << endl;
	cout << o << endl;

	return 0;
}