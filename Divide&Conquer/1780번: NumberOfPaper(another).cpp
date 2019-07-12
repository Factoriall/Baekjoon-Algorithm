#include <iostream>
using namespace std;

int o = 0;//1의 개수
int z = 0;//0의 개수
int mo = 0;//-1의 개수

int paper[2187][2187];


void dac(int sy, int sx, int n) {
	int i, j;
	bool isSame = true;

	int first = paper[sy][sx];
	
	for (i = sy; i < sy+n; i++) {
		for (j = sx; j < sx+n; j++) {
			if (first != paper[i][j]) {//만약 같지 않은게 나오면 탈출
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) {//9개의 수가 모두 같다면 first 값 따라 수를 더한다.
		if (first == 1) 
			o++;
		else if (first == 0) 
			z++;
		else if (first == -1) 
			mo++;
	}
	else {//9개 수가 하나라도 다르다면 쪼개서 divide 작업 지속
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
