/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<TreeNode*> nodeList = {root};
        vector<int> result = {};

        while(!nodeList.empty()){
            vector<TreeNode*> newNodeList = {};

            for(auto& node: nodeList){
                if (node->left != nullptr) newNodeList.push_back(node->left);
                if (node->right != nullptr) newNodeList.push_back(node->right);
            }

            result.push_back(nodeList.back()->val);
            nodeList = newNodeList;
        }

        return result;
    }
};
