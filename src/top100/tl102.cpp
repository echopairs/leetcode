#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        
        queue<TreeNode*> help;
        queue<TreeNode*> next;
        vector<int> temp;
	help.push(root);
        while (!help.empty()) {
            while (help.size() > 0) {
                auto front = help.front();
                help.pop();
                temp.emplace_back(front->val);
                if (front->left) {
                    next.push(front->left);
                }
                if (front->right) {
                    next.push(front->right);
                }
            }
            res.emplace_back(temp);
            temp.clear();
            swap(help, next);
        }
        return res;
    }
};

int main() {
    TreeNode *n1 = new TreeNode(3);
//    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
//    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    
    Solution slu;
    auto ress = slu.levelOrder(n1);
    for (auto res : ress) {
	for (auto value : res) {
	    cout << value << " ";
	}
	cout << endl;
    }

}


