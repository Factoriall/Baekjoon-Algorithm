#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

struct Plane {//구조체 자체는 매개변수로 보낼 시 참조가 아닌 그냥 복사된 값이 가기 때문에 함수 내 내용 복사 X, 포인터 사용되어야 함
	char p[3][3];
	char * u[3];
	char * r[3];
	char * d[3];
	char * l[3];
};

void rotate(Plane * now, char dir) {
	char tmp[3] = { *now->u[0], *now->u[1], *now->u[2] };
	if (dir == '+') {
		for (int i = 0; i < 3; i++) {
			*now->u[i] = *now->l[i];
			*now->l[i] = *now->d[i];
			*now->d[i] = *now->r[i];
			*now->r[i] = tmp[i];
		}
		char tc1 = now->p[0][0];
		now->p[0][0] = now->p[2][0];
		now->p[2][0] = now->p[2][2];
		now->p[2][2] = now->p[0][2];
		now->p[0][2] = tc1;
		char tc2 = now->p[0][1];
		now->p[0][1] = now->p[1][0];
		now->p[1][0] = now->p[2][1];
		now->p[2][1] = now->p[1][2];
		now->p[1][2] = tc2;
	}
	else {
		for (int i = 0; i < 3; i++) {
			*now->u[i] = *now->r[i];
			*now->r[i] = *now->d[i];
			*now->d[i] = *now->l[i];
			*now->l[i] = tmp[i];
		}
		char tc1 = now->p[0][0];
		now->p[0][0] = now->p[0][2];
		now->p[0][2] = now->p[2][2];
		now->p[2][2] = now->p[2][0];
		now->p[2][0] = tc1;
		char tc2 = now->p[0][1];
		now->p[0][1] = now->p[1][2];
		now->p[1][2] = now->p[2][1];
		now->p[2][1] = now->p[1][0];
		now->p[1][0] = tc2;
	}
}

int main() {
	int T;
	Plane up, down, front, back, left, right;

	
	for (int i = 0; i < 3; i++) {
		up.u[i] = &back.p[0][2 - i];
		up.r[i] = &right.p[0][2 - i];
		up.d[i] = &front.p[0][2 - i];
		up.l[i] = &left.p[0][2 - i];

		down.u[i] = &front.p[2][i];
		down.r[i] = &right.p[2][i];
		down.d[i] = &back.p[2][i];
		down.l[i] = &left.p[2][i];

		front.u[i] = &up.p[2][i];
		front.r[i] = &right.p[i][0];
		front.d[i] = &down.p[0][2 - i];
		front.l[i] = &left.p[2 - i][2];

		back.u[i] = &up.p[0][2 - i];
		back.r[i] = &left.p[i][0];
		back.d[i] = &down.p[2][i];
		back.l[i] = &right.p[2 - i][2];

		left.u[i] = &up.p[i][0];
		left.r[i] = &front.p[i][0];
		left.d[i] = &down.p[i][0];
		left.l[i] = &back.p[2 - i][2];

		right.u[i] = &up.p[2 - i][2];
		right.r[i] = &back.p[i][0];
		right.d[i] = &down.p[2 - i][2];
		right.l[i] = &front.p[2 - i][2];
	}

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 3; i++) {//초기화
			for (int j = 0; j < 3; j++) {
				up.p[i][j] = 'w';
				down.p[i][j] = 'y';
				front.p[i][j] = 'r';
				back.p[i][j] = 'o';
				left.p[i][j] = 'g';
				right.p[i][j] = 'b';
			}
		}

		for (int k = 0; k < n; k++) {
			char dir[3];
			scanf("%s", dir);//scanf의 경우 개행문자 포함됩니다! 그러므로 1개 더 추가해야합니다!

			switch (dir[0]) {
			case 'U':
				rotate(&up, dir[1]);
				break;
			case 'F':
				rotate(&front, dir[1]);
				break;
			case 'D':
				rotate(&down, dir[1]);
				break;
			case 'L':
				rotate(&left, dir[1]);
				break;
			case 'B':
				rotate(&back, dir[1]);
				break;
			case 'R':
				rotate(&right, dir[1]);
				break;
			}
			/*puts("[up]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", up.p[i][j]);
				printf("\n");
			}
			puts("[down]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", down.p[i][j]);
				printf("\n");
			}
			puts("[front]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", front.p[i][j]);
				printf("\n");
			}
			puts("[back]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", back.p[i][j]);
				printf("\n");
			}
			puts("[left]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", left.p[i][j]);
				printf("\n");
			}
			puts("[right]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", right.p[i][j]);
				printf("\n");
			}
			puts("=============");*/
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%c", up.p[i][j]);
			printf("\n");
		}

	}

	return 0;
}
