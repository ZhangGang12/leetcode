#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {} 
};

int res; 
int maxPathSum(TreeNode* root) {  //此题的难点在于dfs的时候，我们需要的是左子树+右子树 + 根节点的值
    if(!root) return 0;           //而dfs返回值，只是左子树右子树二选一，且必须大于0，然后加上根节点的值
    res = INT_MIN;
    dfs(root);
    return res;
}

int dfs(TreeNode* root)
{
    if(!root) return 0;
    int left = max(0,dfs(root->left)), right = max(0, dfs(root->right));
    res = max(left + right + root->val, res);
    return max(left,right) + root->val;
}