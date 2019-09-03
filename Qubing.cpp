#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void rotate(char* u[3], char * l[3], char * d[3], char * r[3], char now[3][3], char pm) {//회전
	char tmp[3] = { *u[0], *u[1], *u[2] };
	if (pm == '+') {
		for (int i = 0; i < 3; i++) {
			*u[i] = *l[i];
			*l[i] = *d[i];
			*d[i] = *r[i];
			*r[i] = tmp[i];
		}
		char tc1 = now[0][0];
		now[0][0] = now[2][0];
		now[2][0] = now[2][2];
		now[2][2] = now[0][2];
		now[0][2] = tc1;
		char tc2 = now[0][1];
		now[0][1] = now[1][0];
		now[1][0] = now[2][1];
		now[2][1] = now[1][2];
		now[1][2] = tc2;
	}
	else {
		for (int i = 0; i < 3; i++) {
			*u[i] = *r[i];
			*r[i] = *d[i];
			*d[i] = *l[i];
			*l[i] = tmp[i];
		}
		char tc1 = now[0][0];
		now[0][0] = now[0][2];
		now[0][2] = now[2][2];
		now[2][2] = now[2][0];
		now[2][0] = tc1;
		char tc2 = now[0][1];
		now[0][1] = now[1][2];
		now[1][2] = now[2][1];
		now[2][1] = now[1][0];
		now[1][0] = tc2;
	}
}

int main() {
	int T;
	char up[3][3];
	char down[3][3];
	char front[3][3];
	char back[3][3];
	char left[3][3];
	char right[3][3];
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);
		
		for (int i = 0; i < 3; i++) {//초기화
			for (int j = 0; j < 3; j++) {
				up[i][j] = 'w';
				down[i][j] = 'y';
				front[i][j] = 'r';
				back[i][j] = 'o';
				left[i][j] = 'g';
				right[i][j] = 'b';
			}
		}

		for (int k = 0; k < n; k++) {
			char dir[3];
			scanf("%s", dir);//scanf의 경우 개행문자 포함됩니다!

			switch (dir[0]) {
			case 'U': 
			{
				char * u[3] = { &back[0][2], &back[0][1], &back[0][0] };
				char * l[3] = { &left[0][2], &left[0][1], &left[0][0] };
				char * d[3] = { &front[0][2], &front[0][1], &front[0][0] };
				char * r[3] = { &right[0][2], &right[0][1], &right[0][0] };
				rotate(u, l, d, r, up, dir[1]);
				break;
			}
			case 'F':
			{
				char * u[3] = { &up[2][0], &up[2][1], &up[2][2] };
				char * l[3] = { &left[2][2], &left[1][2], &left[0][2] };
				char * d[3] = { &down[0][2], &down[0][1], &down[0][0] };
				char * r[3] = { &right[0][0], &right[1][0], &right[2][0] };
				rotate(u, l, d, r, front, dir[1]);
				break;
			}
			case 'D':
			{
				char * u[3] = { &front[2][0], &front[2][1], &front[2][2] };
				char * l[3] = { &left[2][0], &left[2][1], &left[2][2] };
				char * d[3] = { &back[2][0], &back[2][1], &back[2][2] };
				char * r[3] = { &right[2][0], &right[2][1], &right[2][2] };
				rotate(u, l, d, r, down, dir[1]);
				break;
			}
			case 'L':
			{
				char * u[3] = { &up[0][0], &up[1][0], &up[2][0] };
				char * l[3] = { &back[2][2], &back[1][2], &back[0][2] };
				char * d[3] = { &down[0][0], &down[1][0], &down[2][0] };
				char * r[3] = { &front[0][0], &front[1][0], &front[2][0] };
				rotate(u, l, d, r, left, dir[1]);
				break;
			}
			case 'B':
			{
				char * u[3] = { &up[0][2], &up[0][1], &up[0][0] };
				char * l[3] = { &right[2][2], &right[1][2], &right[0][2] };
				char * d[3] = { &down[2][0], &down[2][1], &down[2][2] };
				char * r[3] = { &left[0][0], &left[1][0], &left[2][0] };
				rotate(u, l, d, r, back, dir[1]);
				break;
			}
			case 'R':
			{
				char * u[3] = { &up[2][2], &up[1][2], &up[0][2] };
				char * l[3] = { &front[2][2], &front[1][2], &front[0][2] };
				char * d[3] = { &down[2][2], &down[1][2], &down[0][2] };
				char * r[3] = { &back[0][0], &back[1][0], &back[2][0] };
				rotate(u, l, d, r, right, dir[1]);
				break;
			}
			}
			/*puts("[up]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", up[i][j]);
				printf("\n");
			}
			puts("[down]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", down[i][j]);
				printf("\n");
			}
			puts("[front]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", front[i][j]);
				printf("\n");
			}
			puts("[back]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", back[i][j]);
				printf("\n");
			}
			puts("[left]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", left[i][j]);
				printf("\n");
			}
			puts("[right]");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", right[i][j]);
				printf("\n");
			}
			puts("=============");*/
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%c", up[i][j]);
			printf("\n");
		}

	}

	return 0;
}