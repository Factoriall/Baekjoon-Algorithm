#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool flag;

typedef struct {
	int n;
	int atk;
	int vit;
}Minions;

void myTurn(vector<Minions> my, vector<Minions> oppo, vector<int> order, bool isFinished[], bool modok) {
	if (flag)
		return;

	if (oppo.empty()) {//���� ���� -> ���� ��� �׾��� ��
		flag = true;
		printf("%d\n", order.size());
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == -1)
				puts("use modok");
			else
				printf("attack %d %d\n", order[i] / 10 + 1, order[i] % 10 + 1);
		}
		return;
	}

	//���� ���� -> ��� �Ʊ� �ϼ����� �����ϰ� �𵶱��� ����ߴµ��� ���� ������ ��
	bool isf = true;
	if (!modok)
		isf = false;
	else {
		for (int i = 0; i < N; i++) {
			if (!isFinished[i]) {
				isf = false;
				break;
			}
		}
	}
	if (isf)
		return;

	if (!modok) {//�� ���
		vector<Minions> myCopy = my;
		vector<Minions> opCopy = oppo;
		bool finCopy[7];
		for (int i = 0; i < N; i++)
			finCopy[i] = isFinished[i];

		bool isDead;
		do {
			vector<int> me;
			isDead = false;

			for (int i = 0; i < myCopy.size(); i++) {
				myCopy[i].vit -= 1;
				if (myCopy[i].vit == 0) {
					isDead = true;
					finCopy[myCopy[i].n] = true;
					me.push_back(i);
				}
			}
			for (int i = me.size() - 1; i >= 0; i--) 
				myCopy.erase(myCopy.begin() + me[i]);

			vector<int> oe;
			for (int i = 0; i < opCopy.size(); i++) {
				opCopy[i].vit -= 1;
				if (opCopy[i].vit == 0) {
					isDead = true;
					oe.push_back(i);
				}
			}
			for (int i = oe.size() - 1; i >= 0; i--)
				opCopy.erase(opCopy.begin() + oe[i]);
		
		} while (isDead);
		order.push_back(-1);
		myTurn(myCopy, opCopy, order, finCopy, true);

		order.erase(order.end() - 1);
	}

	
	
	for (int i = 0; i < my.size(); i++) {
		for (int j = 0; j < oppo.size(); j++) {
			if (!isFinished[my[i].n]) {//���� ���ߴٸ�
				//�̸� ����
				vector<Minions> myCopy = my;
				vector<Minions> opCopy = oppo;
				bool finCopy[7];
				for (int i = 0; i < N; i++)
					finCopy[i] = isFinished[i];

				//����
				myCopy[i].vit -= opCopy[j].atk;
				opCopy[j].vit -= myCopy[i].atk;
				order.push_back(myCopy[i].n * 10 + opCopy[j].n);//�Ʊ� �ϼ���: 10�� �ڸ�, �� �ϼ���: 1�� �ڸ�
				finCopy[myCopy[i].n] = true;
				if (myCopy[i].vit <= 0)
					myCopy.erase(myCopy.begin() + i);
				if (opCopy[j].vit <= 0)
					opCopy.erase(opCopy.begin() + j);

				myTurn(myCopy, opCopy, order, finCopy, modok);

				order.erase(order.end() - 1);
			}
		}
	}
}


int main() {
	vector<Minions> myTeam;
	vector<Minions> opponent;
	vector<int> order;
	bool isFinished[7] = { 0, };

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int a, v;
		scanf("%d %d", &a, &v);
		myTeam.push_back(Minions{ i, a, v });
	}

	for (int i = 0; i < M; i++) {
		int a, v;
		scanf("%d %d", &a, &v);
		opponent.push_back(Minions{ i, a, v });
	}

	myTurn(myTeam, opponent, order, isFinished, false);

	if (!flag)
		puts("-1");

	return 0;
}