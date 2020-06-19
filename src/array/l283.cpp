//
// Created by pairs on 12/29/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
//                nums[i] = 0;
            }
        }
        for (int j = index; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

int main() {
    Solution slu;
    vector<int> t = {1};
    slu.moveZeroes(t);
    for (auto v : t) {
        cout << v << " ";
    }
    cout << endl;
}