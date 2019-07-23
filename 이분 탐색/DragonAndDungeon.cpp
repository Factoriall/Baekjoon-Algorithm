#include <iostream>
using namespace std;

int type[123457];//Ÿ��
int attack[123457];//���ݷ�
int hp[123457];//ü��
long long hpChange[123457];//�޸������̼�

int main() {
	int i;
	int atk;//�ʱ� ���ݷ�
	int num;//�� ��

	cin >> num >> atk;

	for (i = 0; i < num; i++) 
		cin >> type[i] >> attack[i] >> hp[i];

	for (i = 0; i < num; i++) 
		hpChange[i] = -1;
	
	
	long long hi = 9223372036854775800;//64 signed ���� �� ���� ū ��
	long long lo = 0;

	while (lo + 1 < hi) {//2�� Ž�� �ǽ�
		long long mid = (hi + lo) / 2;
		long long a = atk;
		long long h = mid;
		bool isDead = false;

		for (i = 0; i < num; i++) {
			if (type[i] == 1) {//�巡�� ��
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
			else {//���� ��
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