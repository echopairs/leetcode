#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

using namespace std;
class Solution {
public:
    unordered_map<char, int> priority = {
	{'(', 1},{')', 1},
	{'[', 2},{']', 2},
	{'{', 3},{'}', 3},
    };
    bool isValid(string s) {
	std::stack<char> help;
	for (int i = 0; i < s.size(); i++) {
	    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
		help.push(s[i]);
	    } else {
		// ')'、']'、'}'
		if (help.empty()) {
		    return false;
		}
		if (priority[help.top()] == priority[s[i]]) {
		    help.pop();
		} else {
		    return false;
		}
	    }
	}
	if (help.empty()) {
	    return true;
	}
	return false;
    }
};

int main() {
    Solution slu;
    cout << slu.isValid("]") << endl;
}
