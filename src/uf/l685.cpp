#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> f(edges.size() + 1);
        // 存储边
        vector<int> root(edges.size() + 1), first, second;
        // find root
        for (auto &edge : edges) {
            // [2, 1]
            if (root[edge[1]] == 0) {
                root[edge[1]] = edge[0];
            } else {
                first = {root[edge[1]], edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }

        for (int i = 1; i <= edges.size(); i++) {
            f[i] = i;
        }

        for (auto edge :edges) {
            if (edge[1] == 0) {
                continue;
            }
            int x = findf(edge[0], f);
            int y = findf(edge[1], f);
            if (x == y) {
                // means circle
                if (first.empty()) {
                    return vector < int > {edge[0], edge[1]};
                }
                return first;
            }
	    f[x] = y;
        }
        // remove second means ok
        return second;
    }


    int findf(int index, vector<int> &f) {
        int head = index;
        while (head != f[head]) {
            head = f[head];
        }
        // 路径压缩(todo)
        return head;
    }
};

int main() {
    Solution slu;
    vector<vector<int>> t = {
	{2, 1}, {3, 1}, {4, 2}, {1, 4}
    };
    vector<vector<int>> t1 = {
	{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}
    };
    auto r = slu.findRedundantDirectedConnection(t1);
    cout << r[0] << " " << r[1] << endl;
}



