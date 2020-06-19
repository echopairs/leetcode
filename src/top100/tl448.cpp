#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> r(nums.size()+1, 0);
	for (int i = 0; i < nums.size(); i++) {
	    r[nums[i]] = 1;
	}
	int index = 0;
	for (int i = 1; i < r.size(); i++) {
	    if (r[i] == 0) {
		r[index++] = i;
	    }
	}
	return vector<int>(r.begin(), r.begin()+index);         
    }
};

int main() {
    Solution slu;
    vector<int> t = {4,3,2,7,8,2,3,1};
    auto r = slu.findDisappearedNumbers(t);

    for (auto v : r) {
	cout << v << " ";
    }
    cout << endl;
}
