#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n;
	string s;

	while (1) {

		cin >> n;
		if (!n) return 0;
		getline(cin, s);

		map<string, int> m;
		while (n--) {
			getline(cin, s);
			transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
			if (!m[s]) m[s] = 0;
		}		
		cout << m.size() << endl;
	}
}