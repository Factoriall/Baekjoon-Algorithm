#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int prep[1000002];
char str[1000002];
char comp[1000002];

int main() {
	
	fgets(str, 1000002, stdin);//엔터 및 null을 포함하기 때문에 2개가 더 추가되어야합니다!!
	fgets(comp, 1000002, stdin);

	//KMP
	int slen = strlen(str);
	int clen = strlen(comp);
	str[slen - 1] = NULL;
	comp[clen - 1] = NULL;
	slen--; clen--;

	//printf("%d %d\n", slen, clen);
	int start = 0;
	for (int i = 1; i < clen; i++) {
		while (start > 0 && comp[start] != comp[i]) 
			start = prep[start - 1];
		if (comp[start] == comp[i]) 
			prep[i] = ++start;
	}
	//for (int i = 0; i < clen; i++)
	//	printf("%d ", prep[i]);
	//printf("\n");
	vector<int> answer;

	int cp = 0;
	for (int i = 0; i < slen; i++) {
		//printf("i: %d\n", i);
		//printf("cp: %d\n", cp);
		//printf("%c %c\n", comp[cp], str[i]);
		while (cp > 0 && comp[cp] != str[i])
			cp = prep[cp - 1];
		//printf("cp: %d\n", cp);
		if (comp[cp] == str[i]) {
			if (cp == clen - 1) {
				answer.push_back(i - clen + 2);
				cp = prep[cp];
			}
			else
				cp++;
		}
	}
	
	printf("%d\n", answer.size());
	for (int s : answer)
		printf("%d ", s);

	return 0;
}