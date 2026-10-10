
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(0, nums, curr, ans);
        return ans;
    }

    void backtrack(int start, vector<int>& nums,
                   vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);

            backtrack(i + 1, nums, curr, ans);

            curr.pop_back();
        }
    }
};
