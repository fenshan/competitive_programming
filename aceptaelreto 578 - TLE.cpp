#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<string>::iterator low;
	string s;

	while (1) {

		cin >> n;
		if (!n) return 0;
		getline(cin, s);

		vector<string> v;
		while (n--) {
			getline(cin, s);
			transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
			low = lower_bound(v.begin(), v.end(), s);
			if (low == v.end())v.push_back(s);
			else if (!v.size() || s < *low) v.insert(low, s);
		}		
		cout << v.size() << endl;
	}
}