#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
string a[101];
bool isExist[101];

bool distinguish(int num) {
	int i;
	if (isExist[num] == false)
		return false;

	if (num == s.length())
		return true;

	bool result = false;
	for (i = 0; i < n; i++) {
		int tmp = a[i].length();
		if (s.compare(num, tmp, a[i]) == 0) {
			result = distinguish(num + tmp);
			if (result == true)
				break;
		}
	}
	isExist[num] = result;
	return result;
}

int main() {
	
	
	int i;

	cin >> s;
	cin >> n;

	fill(isExist, isExist + 101, true);

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