#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
std::vector<std::vector<int> > threeSum(std::vector<int> nums) {
    std::vector<std::vector<int> > res;
    if (nums.size() < 3) {
	return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0) {
            break;
        }
        int target = -nums[i];

        int begin = i + 1;
	int end = nums.size() - 1;

	while (begin < end) {
		if (nums[begin] + nums[end] == target) {
		    vector<int> t = {nums[i], nums[begin], nums[end]};
		    res.emplace_back(t);
		    begin++;
		    end--;
		    while (begin < end && nums[begin] == nums[begin-1]) {
			begin++;
		    }
		    while (begin < end && nums[end] == nums[end+1]) {
			end--;
		    }
		    continue;
		}
		if (nums[begin] + nums[end] > target) {
		    end--;
		}
		if (nums[begin] + nums[end] < target) {
		    begin++;
		}
	}

        // 去重
	    while (nums[i] == nums[i+1] && i < nums.size() - 2) {
		i++;
	    } 
	}
	return res;
    }
};

int main() {
    Solution slu;
    /*
    vector<int> t = {-1, 0, 1, 2, -1, -4};
    auto res = slu.threeSum(t);
    for (auto r : res) {
	for (auto value : r) {
	    cout << value << " ";
	}
	cout << endl;
    }
    vector<int> t1 = {};
    slu.threeSum(t1);
*/
    vector<int> t2 = {-2,0,0,2,2};
    auto res1 = slu.threeSum(t2);
    for (auto r : res1) {
	for (auto value : r) {
	    cout << value << " ";
	}
	cout << endl;
    }
}
