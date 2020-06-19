#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*			<——	
         	1——>3——>2——>4

        */
        int f = nums[0];
        int s = nums[0];

        while (s < nums.size()) {
        	f = nums[f];
        	s = nums[nums[s]];
        	if (f == s) {
        		break;
        	}
        }
        f = nums[0];
        while (f != s) {
        	f = nums[f];
        	s = nums[s];
        }
        return f;
    }
};

int main() {
    vector<int> t = {1,3,4,2,2};
    Solution slu;
    cout << slu.findDuplicate(t) << endl;
}
