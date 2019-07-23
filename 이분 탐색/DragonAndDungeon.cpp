#include <iostream>
using namespace std;

int type[123457];//타입
int attack[123457];//공격력
int hp[123457];//체력
long long hpChange[123457];//메모이제이션

int main() {
	int i;
	int atk;//초기 공격력
	int num;//방 수

	cin >> num >> atk;

	for (i = 0; i < num; i++) 
		cin >> type[i] >> attack[i] >> hp[i];

	for (i = 0; i < num; i++) 
		hpChange[i] = -1;
	
	
	long long hi = 9223372036854775800;//64 signed 진수 중 가장 큰 수
	long long lo = 0;

	while (lo + 1 < hi) {//2진 탐색 실시
		long long mid = (hi + lo) / 2;
		long long a = atk;
		long long h = mid;
		bool isDead = false;

		for (i = 0; i < num; i++) {
			if (type[i] == 1) {//드래곤 방
				long long da = attack[i];
				long long dh = hp[i];

				if (hpChange[i] == -1) {
					long long maxAtk = (dh / a) + (dh%a == 0 ? 0 : 1);
					if (maxAtk == 0)
						hpChange[i] = 0;
					else
						hpChange[i] = (maxAtk - 1) * da;
				}
				cout << "dp: "<< hpChange[i] << endl;
				
				if (hpChange[i] < h)
					h = h - hpChange[i];
				else {
					isDead = true;
					break;
				}
			}
			else {//물약 방
				a += attack[i];
				h = (h + hp[i] < mid ? (h + hp[i]) : mid);
			}
		}

		if (isDead)
			lo = mid;
		else
			hi = mid;
	}

	cout << hi << '\n';

	return 0;
}