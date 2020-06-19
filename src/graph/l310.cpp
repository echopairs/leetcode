//
// Created by pairs on 12/21/19.
//
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        set<int> remind;
        for (int i = 0; i < n; i++) {
            remind.insert(i);
        }

        vector<int> degree(n);
        map<int, set<int> > es;

        for (auto edge : edges) {
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;

            es[edge[0]].insert(edge[1]);
            es[edge[1]].insert(edge[0]);
        }

        queue<int> nodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 ) {
                nodes.push(i);
            }
        }
        queue<int> temp;
        while(remind.size() > 2) {
            while (!nodes.empty()) {
                int front = nodes.front();
                nodes.pop();
                remind.erase(front);
                for (auto e : es[front]) {
                    if (--degree[e] == 1 && remind.find(e) != remind.end()) {
                        temp.push(e);
                    }
                }
            }
            nodes = std::move(temp);
        }
        return vector<int> (remind.begin(), remind.end());
    }
};


int main() {
    std::vector<vector<int>> t = {
            {1, 0},
//            {1, 2},
//            {1, 3},
    };

    std::vector<vector<int>> t2 = {
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 4},
            {4, 5}
    };
    Solution slu;
    auto res = slu.findMinHeightTrees(6, t2);
    for (auto v : res) {
        cout << v << " ";
    }
    std::cout << endl;

    auto res2 = slu.findMinHeightTrees(2, t);
    for (auto v : res2) {
        cout << v << " ";
    }
    std::cout << endl;

    std::vector<vector<int>> t3 = {
            {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}
    };
    auto res3 = slu.findMinHeightTrees(6, t3);
    for (auto v : res3) {
        cout << v << " ";
    }
    std::cout << endl;
}