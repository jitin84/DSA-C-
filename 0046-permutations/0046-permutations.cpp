class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        function<void(int)> solve = [&](int index) {
            if (index == nums.size()) {
                ans.push_back(nums);
                return;
            }
            for (int i = index; i < nums.size(); i++) {
                swap(nums[index], nums[i]);
                solve(index + 1);
                swap(nums[index], nums[i]);
            }
        };
        solve(0);
        return ans;
    }
};