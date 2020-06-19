#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0;
        int C = 0;
        int R = nums.size() - 1;
        while (C <= R) {
        	if (nums[C] == 0) {
        		swap(nums[C++], nums[L++]);
        		// nums[L] 元素只能是1
        	} else if (nums[C] == 1) {
        		// 1
        		C++;
        	} else {
        		swap(nums[R--], nums[C]);
       		}
        }
    }
};

int main() {
    vector<int> t = {};
    Solution slu;
    slu.sortColors(t);
    for (auto value : t) {
	cout << value << " ";
    }
    cout << endl;
}
