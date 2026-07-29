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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) return result;
        
        vector<TreeNode*> currLevel = {root};

        while(!currLevel.empty()) {
            vector<TreeNode*> nextLevel;
            vector<int> thisLevelResult;

            for(auto peerNode: currLevel) {
                thisLevelResult.push_back(peerNode->val);
                if (peerNode->left != nullptr) nextLevel.push_back(peerNode->left);
                if (peerNode->right != nullptr) nextLevel.push_back(peerNode->right);
            }

            currLevel = std::move(nextLevel);
            result.push_back(std::move(thisLevelResult));
        }

        return result;
    }
};
