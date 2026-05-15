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
    map<int,vector<pair<int,int>>>nodes;
    void dfs(TreeNode* root, int x,int y){
        if(!root) return ;
        // we have to store in the map 
        nodes[x].push_back({y,root->val});
        // call the next nodes
        dfs(root->left,x-1,y+1);
        dfs(root->right,x+1,y+1);

        return ;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {

        dfs(root,0,0);
        // getting the answer 
        vector<vector<int>>result;
        for (auto& [col, vec] : nodes) {
                stable_sort(vec.begin(), vec.end(),
                            [](const pair<int, int>& a, const pair<int, int>& b) {
                                return a.first < b.first;  // sort ONLY by row
                            });

            vector<int> colVals;
            for (auto& [_, val] : vec){
                
                colVals.push_back(val);
            }
            result.push_back(colVals);
    }

    return result;
    }
};