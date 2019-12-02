//
// Created by pairs on 12/2/19.
//

#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /*
    分析:
    对于节点node来说，以该节点为顶点的最大值有两种情况。一种是包含该节点，另一种为不包含该节点。
    包含该节点为孙子节点的最大值:
        node->val + node->left->left + node->left->right + node->right->left + node->right->right
    不包含该节点为左右两个节点之和：
        node->left + node->right
    */
    int rob(TreeNode* root) {
//         _rob1(root);
        auto r = _rob2(root);
        return r[0];
    }

    /*
        如下代码，计算root->left最大值时，会计算root->left->left和root->left->right
        计算root->right时，也会计算root->left->left和root->left->right。
    */
    int _rob1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = _rob1(root->left);
        int r = _rob1(root->right);
        int val = root->val;

        if (root->left) {
            val += _rob1(root->left->left);
            val += _rob1(root->left->right);
        }
        if (root->right) {
            val += _rob1(root->right->left);
            val += _rob1(root->right->right);
        }
        return max(l + r, val);
    }

    /*
        根据上述重复计算的情况，在计算node最大值的时候，保存左右子节点最大值
    */
    vector<int> _rob2(TreeNode* root) {
        // max, left, right
        vector<int> res(3, 0);
        if (!root) {
            return res;
        }

        auto l = _rob2(root->left);
        auto r = _rob2(root->right);

        res[0] = max(l[0] + r[0], root->val + l[1] + l[2] + r[1] + r[2]);
        res[1] = l[0];
        res[2] = r[0];
        return res;
    }
private:
};

int main() {
    TreeNode n1 =  TreeNode(2);
    TreeNode n2 = TreeNode(1);
    TreeNode n3 = TreeNode(3);
    TreeNode n4 = TreeNode(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    Solution s;
    cout << s.rob(&n1) << endl;

    TreeNode nn1 =  TreeNode(4);
    TreeNode nn2 =  TreeNode(1);
    TreeNode nn3 =  TreeNode(2);
    TreeNode nn4 =  TreeNode(3);
    nn1.left = &nn2;
    nn2.right = &nn3;
    nn3.right = &nn4;
    cout << s.rob(&nn1) << endl;
}