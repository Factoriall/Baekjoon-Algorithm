#include <iostream>
using namespace std;

int myMin;
int opoMin;
bool win = false;

typedef struct {
	int power;
	int vital;
	bool isDead;
	bool isAttacked;
}minions;

//pair<int, int> player;//100��
//minions player;


void copyMin(minions copy[8], minions origin[8], int num) {
	int i;
	for (i = 1; i <= num; i++) {
		copy[i].isAttacked = origin[i].isAttacked;
		copy[i].isDead = origin[i].isDead;
		copy[i].power = origin[i].power;
		copy[i].vital = origin[i].vital;
	}
}

//�̴Ͼ� ����
void attack(minions& p, minions& o) {
	p.vital -= o.power;
	if (p.vital <= 0)
		p.isDead = true;

	o.vital -= p.power;
	if (o.vital <= 0)
		o.isDead = true;
}

//�� ���
void defile(minions player[8], minions opponent[8]) {
	int i;
	bool isDead = true;

	//�� ��ī����
	while (isDead) {
		isDead = false;
		for (i = 1; i <= myMin; i++) {
			if (!player[i].isDead) {
				player[i].vital -= 1;
				if (player[i].vital == 0) {
					isDead = true;
					player[i].isDead = true;
				}
			}
		}

		for (i = 1; i <= opoMin; i++) {
			if (!opponent[i].isDead) {
				opponent[i].vital -= 1;
				if (opponent[i].vital == 0) {
					isDead = true;
					opponent[i].isDead = true;
				}
			}
		}
	}
}

void calculate(int order[8], int cnt) {
	int i;
	
	for (i = 0; i < cnt; i++) {
		if (order[i] == -1) {
			cout << "use modok" << endl;
		}
		else {
			cout << "attack " << order[i] / 10 << " " << order[i] % 10 << endl;
		}
	}
}

void myTurn(minions player[8], minions opponent[8],int order[8], int cnt, bool defileUsed) {//order: ���� �� �� ��� ���, cnt: order �� �ø���
	int i, j;
	minions tmpPlayer[8];
	minions tmpOppo[8];

	//Ȯ��
	for (i = 0; i < cnt; i++)
		cout << order[i] << ' ';
	cout << endl;

	for (i = 1; i <= myMin; i++) {
		cout << "Player " << i << ": [" << player[i].power << ", " << player[i].vital << ']' << endl;
	}
	cout << endl;

	for (i = 1; i <= opoMin; i++) {
		cout << "Opponent " << i << ": [" << opponent[i].power << ", " << opponent[i].vital << ']' << endl;
	}
	cout << endl;

	cout << " ==================================================== " << endl;

	if (win)//�ϳ��� ������ ������
		return;

	if (opoMin == 0) {
		cout << 0 << endl;
		return;
	}

	//�� ���� ���� Ȯ��
	for (i = 1; i <= opoMin; i++) {
		if (!opponent[i].isDead)
			break;
		
		if (i == opoMin) {//���� ����
			win = true;
			cout << cnt << endl;
			calculate(order, cnt);
			return;
		}
	}


	//�� ���, �� �ϼ��� ��� �Ǵ� ���� ���� �� �� �ϼ��� ������� ����
	for (i = 1; i <= myMin; i++) {
		if (!player[i].isDead || !player[i].isAttacked || defileUsed == false)
			break;

		if (i == myMin) {
			for (j = 0; j < opoMin; i++) {
				if (!opponent[i].isDead) {
					return;
				}
			}
		}
	}

	
	copyMin(tmpPlayer, player, myMin);
	copyMin(tmpOppo, opponent, opoMin);
	

	for (i = 1; i <= myMin; i++) {
		if (!defileUsed) {//�� ������� �ʾ��� ��
		//�� ���
			defile(tmpPlayer, tmpOppo);
			order[cnt] = -1;
			myTurn(tmpPlayer, tmpOppo, order, cnt + 1, true);

			//��Ʈ��ŷ
			order[cnt] = 0;
		}

		if (!tmpPlayer[i].isAttacked && !tmpPlayer[i].isDead) {//�������� �ʰ� ������ �ʾ����� player �̴Ͼ��� ���� ����
			//cout << "Here" << endl;
			for (j = 1; j <= opoMin; j++) {
				if (!tmpOppo[j].isDead) {//���� ���� �ʾҴٸ� ���� ����
					//����
					int tmpVital1 = tmpPlayer[i].vital;
					int tmpVital2 = tmpOppo[j].vital;

					attack(tmpPlayer[i], tmpOppo[j]);
					tmpPlayer[i].isAttacked = true;
					order[cnt] = i * 10 + j;
					myTurn(tmpPlayer, tmpOppo, order, cnt + 1, defileUsed);

					//��Ʈ��ŷ
					tmpPlayer[i].vital = tmpVital1;
					tmpOppo[j].vital = tmpVital2;
					tmpPlayer[i].isAttacked = false;
					tmpPlayer[i].isDead = false;
					tmpOppo[i].isDead = false;

					order[cnt] = 0;
				}
			}
		}
	}

	return;
}

int main() {
	
	int i;
	int order[8];
	minions player[8];
	minions opponent[8];

	cin >> myMin >> opoMin;

	for (i = 1; i <= myMin; i++) {
		cin >> player[i].power >> player[i].vital;
		player[i].isDead = false;
		player[i].isAttacked = false;
	}

	for (i = 1; i <= opoMin; i++) {
		cin >> opponent[i].power >> opponent[i].vital;
		opponent[i].isDead = false;
	}

	myTurn(player, opponent, order, 0, false);//dfs

	if (!win && opoMin != 0) {
		cout << -1 << endl;
	}

	return 0;
}