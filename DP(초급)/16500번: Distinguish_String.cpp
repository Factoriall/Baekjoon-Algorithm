#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;//전체 문자열
string a[101];//부분 문자열
bool isExist[101];//지금 문자열 위치부터 왼쪽 부분이 a 배열 중 겹치는게 존재하는지 여부

bool distinguish(int num) {
	int i;
	if (isExist[num] == false)//dp 확인해 이미 false로 바뀌어 있으면 확인할 필요 없음
		return false;

	if (num == s.length())//성공 조건
		return true;

	bool result = false;
	for (i = 0; i < n; i++) {
		int tmp = a[i].length();
		if (s.compare(num, tmp, a[i]) == 0) {
			//compare 함수로 지금 위치부터 a[i] 길이 만큼을 a[i]과 비교
			result = distinguish(num + tmp);//맞을 시 다음 비교
			if (result == true)//true 반환 시 끝!
				break;
		}
	}
	isExist[num] = result;//dp에 저장, false 저장하면 여기선 이제 볼일 없다는 뜻.
	return result;
}

int main() {
	
	
	int i;

	cin >> s;
	cin >> n;

	fill(isExist, isExist + 101, true);//일단 dp를 true로 채우기

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
