#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	string code;
	stack<string> s;
	bool isIllegal;//illegal���� �ƴ��� �׽�Ʈ

	while(1) {
		isIllegal = false;
		getline(cin, code);//���ͷ� input�� �����ϴ� ����
		if (code.compare("#") == 0)//������ ����
			break;
		for (string::size_type i = 0; i < code.size(); i++) {
			if (code[i] == '<' && code[i + 1] != '/') {//opening tag ����
				//cout << "here" << endl;
				int a = 0;
				string::iterator start = code.begin() + i + 1;//'<'������ ����Ű�� �ݺ���
				string::iterator end = start;//'>'�ٷ� ���� ����Ű�� �ݺ���
				string::iterator tagEnd = start;//tag�� ���� ����Ű�� �ݺ���

				while (*end != '>')
					end++; a++;
				
				while (*tagEnd != '>' && *tagEnd != ' ')
					tagEnd++;

				if (*(end - 1) != '/') {//���� <>�ȿ� closing tag�� ���� ������ ���� �ʿ䰡 ����. ������ stack�� �ֱ�
					string t(start, tagEnd);
					//cout << "push: " << t << endl;
					s.push(t);
				}
				
				i += a;//�� �κ��� �ʿ������ ���ؼ� ��ŵ
			}
			if (code[i] == '<' && code[i + 1] == '/') {//closiing tag Ȯ�� ����
				string::iterator start = code.begin() + i + 2; //'</'������ ����Ű�� �ݺ���
				string::iterator end = start;//'>'�ٷ� ���� ����Ű�� �ݺ���

				while (*end != '>')
					end++;

				string t(start, end);
				if (!s.empty() && t.compare(s.top()) == 0) {//���� ������ �Ͱ� ���ٸ� pop
					//cout << "pop: " << t << endl;
					s.pop();
				}
				else {//�ƴϸ� �̹� illegal�ϹǷ� ����������
					isIllegal = true;  
					break;
				}
			}
		}


		if (s.empty() && !isIllegal)
			cout << "legal" << '\n';
		else
			cout << "illegal" << '\n';

		while (!s.empty())//����
			s.pop();
	} 

	return 0;
}