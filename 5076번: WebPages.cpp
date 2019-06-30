#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	string code;
	stack<string> s;
	bool isIllegal;//illegal인지 아닌지 테스트

	while(1) {
		isIllegal = false;
		getline(cin, code);//엔터로 input을 구분하는 조건
		if (code.compare("#") == 0)//끝내는 조건
			break;
		for (string::size_type i = 0; i < code.size(); i++) {
			if (code[i] == '<' && code[i + 1] != '/') {//opening tag 조건
				//cout << "here" << endl;
				int a = 0;
				string::iterator start = code.begin() + i + 1;//'<'다음을 가리키는 반복자
				string::iterator end = start;//'>'바로 전을 가리키는 반복자
				string::iterator tagEnd = start;//tag의 끝을 가리키는 반복자

				while (*end != '>')
					end++; a++;
				
				while (*tagEnd != '>' && *tagEnd != ' ')
					tagEnd++;

				if (*(end - 1) != '/') {//만약 <>안에 closing tag도 같이 있으면 넣을 필요가 없다. 없으면 stack에 넣기
					string t(start, tagEnd);
					//cout << "push: " << t << endl;
					s.push(t);
				}
				
				i += a;//이 부분은 필요없으니 더해서 스킵
			}
			if (code[i] == '<' && code[i + 1] == '/') {//closiing tag 확인 조건
				string::iterator start = code.begin() + i + 2; //'</'다음을 가리키는 반복자
				string::iterator end = start;//'>'바로 전을 가리키는 반복자

				while (*end != '>')
					end++;

				string t(start, end);
				if (!s.empty() && t.compare(s.top()) == 0) {//만약 빼야할 것과 같다면 pop
					//cout << "pop: " << t << endl;
					s.pop();
				}
				else {//아니면 이미 illegal하므로 빠져나간다
					isIllegal = true;  
					break;
				}
			}
		}


		if (s.empty() && !isIllegal)
			cout << "legal" << '\n';
		else
			cout << "illegal" << '\n';

		while (!s.empty())//비우기
			s.pop();
	} 

	return 0;
}
