#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int n;
	string s;

	while (1) {

		cin >> n;
		if (!n) return 0;
		getline(cin, s);

		unordered_set<string> m;
		while (n--) {
			getline(cin, s);
			transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
			if (!m.count(s)) m.insert(s);
		}		
		cout << m.size() << endl;
	}
}