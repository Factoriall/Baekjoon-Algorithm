#include <iostream>
using namespace std;

int o = 0;
int z = 0;
int mo = 0;

int paper[2187][2187];


int dac(int sy, int sx, int n) {
	bool isFinished = false;
	if (n == 1) {
		return paper[sy][sx];
	}
	int i, j;

	int d = n / 3;
	int tmp[3][3];
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tmp[i][j] = dac(sy + (i*d), sx + (j*d), d);
			if (!isFinished) {
				if (tmp[i][j] != tmp[0][0] || tmp[i][j] == 2)
					isFinished = true;
			}
		}
	}

	/*for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	if (isFinished) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (tmp[i][j] == 1) {
					//cout << "1 - yÁÂÇ¥: " << sy + (i*d) << ", xÁÂÇ¥: " << sx + (j*d) << ", Å©±â: " << d << endl;
					o++;
				}
				else if (tmp[i][j] == 0) {
					//cout << "0 - yÁÂÇ¥: " << sy + (i*d) << ", xÁÂÇ¥: " << sx + (j*d) << ", Å©±â: " << d << endl;
					z++;
				}
				else if (tmp[i][j] == -1) {
					//cout << "-1 - yÁÂÇ¥: " << sy + (i*d) << ", xÁÂÇ¥: " << sx + (j*d) << ", Å©±â: " << d << endl;
					mo++;
				}
			}
		}
		return 2;
	}
	else
		return tmp[0][0];
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	int fin = dac(0, 0, n);

	if (fin == 1)
		o++;
	if (fin == 0)
		z++;
	if (fin == -1)
		mo++;

	cout << mo << endl;
	cout << z << endl;
	cout << o << endl;

	return 0;
}