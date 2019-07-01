#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	int i;
	queue<int> q;

	cin >> n;

	for (i = 1; i <= n; i++) 
		q.push(i);
	
	while (n > 1) {
		//cout << q.front() << '\n';
		q.pop();
		n--;

		//cout << q.front() << '\n';
		int card = q.front();
		q.pop();
		q.push(card);
	}
	cout << q.front() << '\n';
	q.pop();

	return 0;
}