#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        //很明显这道题要使用dfs遍历，并且每次枚举中位数
        vector<TreeNode* > res = dfs(1, n);
        return res;
    }

    vector<TreeNode*> dfs(int l, int r)
    {
        if(l > r) return {nullptr};
        vector<TreeNode*> temp;//保存本层递归的所有root节点
        for(int i = l; i <= r; i++)
        {
            //每次枚举中位数，将lr分成左右子树
            vector<TreeNode*> left = dfs(l, i - 1);
            vector<TreeNode*> right = dfs(i + 1, r);
            for(int k = 0; k < left.size(); k++)
                for(int u = 0; u < right.size(); u++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[k];
                    root->right = right[u];
                    temp.push_back(root);
                }
        }
        return temp;
    }