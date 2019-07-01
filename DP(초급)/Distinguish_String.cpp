#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;//��ü ���ڿ�
string a[101];//�κ� ���ڿ�
bool isExist[101];//���� ���ڿ� ��ġ���� ���� �κ��� a �迭 �� ��ġ�°� �����ϴ��� ����

bool distinguish(int num) {
	int i;
	if (isExist[num] == false)//dp Ȯ���� �̹� false�� �ٲ�� ������ Ȯ���� �ʿ� ����
		return false;

	if (num == s.length())//���� ����
		return true;

	bool result = false;
	for (i = 0; i < n; i++) {
		int tmp = a[i].length();
		if (s.compare(num, tmp, a[i]) == 0) {
			//compare �Լ��� ���� ��ġ���� a[i] ���� ��ŭ�� a[i]�� ��
			result = distinguish(num + tmp);//���� �� ���� ��
			if (result == true)//true ��ȯ �� ��!
				break;
		}
	}
	isExist[num] = result;//dp�� ����, false �����ϸ� ���⼱ ���� ���� ���ٴ� ��.
	return result;
}

int main() {
	
	
	int i;

	cin >> s;
	cin >> n;

	fill(isExist, isExist + 101, true);//�ϴ� dp�� true�� ä���

	for (i = 0; i < n; i++)
		cin >> a[i];

	/*cout << s << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << '\n';*/

	if (distinguish(0))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	/*for (i = 0; i <= s.length(); i++)
		cout << isExist[i] << '\t';
	cout << '\n';*/

	return 0;
}