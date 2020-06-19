#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::set<std::vector<int> > res;
        std::vector<int> path;
	sort(candidates.begin(), candidates.end());
        bt(path, res, candidates, 0, target);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void bt(vector<int>&path, set<vector<int>> &res, vector<int> &candidates, int current, int target) {
        if (current == target) {
	    vector<int> r = path;
	    sort(r.begin(), r.end());
            res.insert(r);
            return;
        }
        if (current + candidates[0] > target) {
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            // means ok
	    if (current + candidates[i] > target) {
		return;
	    }
	    path.emplace_back(candidates[i]);
            current += candidates[i];
            bt(path, res, candidates, current, target);
            path.pop_back();
	    current -= candidates[i];
        }
    }
};

int main() {
    Solution slu;
/*    vector<int> t = {2,3,6,7};
    auto ress = slu.combinationSum(t, 7);
    for (auto res : ress) {
	for (auto value : res) {
	    cout << value << " ";
	}
	cout << endl;
    }
*/  
    vector<int> t1 = {2,3,5};
    auto ress2 = slu.combinationSum(t1, 8);
    for (auto res : ress2) {
	for (auto value : res) {
	    cout << value << " ";
	}
	cout << endl;
    }

}


