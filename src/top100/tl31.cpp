#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int left;
        for (left = nums.size() - 2; left >= 0; left--) {
            if (nums[left] < nums[left+1]) {
                break;
            }
        }
        if (left < 0) {
            sort(nums.begin(), nums.end());
	    return;
        }

	int right = nums.size() - 1;
	while (nums[right] <= nums[left]) {
	    right--;
	}
	cout << "left: " << left << " right: " << right << endl;
	swap(nums[left], nums[right]);
	sort(nums.begin() + left + 1, nums.end());
    }
};

int main() {
    Solution slu;
    vector<int> t = {3, 5, 8, 7, 6, 4};
    slu.nextPermutation(t);
    for (auto v : t) {
	cout << v << " ";
    }
    cout << endl;
    int a, b,c;
    a,b,c=1,b,c;
}
