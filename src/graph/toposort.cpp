//
// Created by pairs on 12/20/19.
//
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> degree(numCourses);
        unordered_map<int, set<int> > matrix;

        for (auto pre : prerequisites) {
            // pre[0] = 1. pre[1] = 0  0->1
            degree[pre[0]] += 1;            // degree[1] = 1
            matrix[pre[1]].insert(pre[0]);  // matrix[0] = {1}
        }

        queue<int> r;
        for (int i = 0; i < numCourses; i++) {
            if (0 == degree[i]) {
                r.push(i);
            }
        }
        while(!r.empty()) {
            int temp = r.front();
            r.pop();
            res.emplace_back(temp);
            for (auto pre : matrix[temp]) {
                if (--degree[pre] == 0) {
                    r.push(pre);
                }
            }
        }
        if (numCourses == res.size()) {
            return res;
        } else {
            return vector<int>{};
        }
    }
};

int main() {
    Solution slu;
    vector<vector<int> > t = {
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2}
    };
    auto res = slu.findOrder(4, t);
    for (auto u : res) {
        cout << u << " ";
    }
    cout << endl;
}