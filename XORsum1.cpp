class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums , 0 , 0);
    }
    int solve(vector<int>& nums , int i , int ans)
    {
        if(i == nums.size()) // the end
        {
            return ans;
        }
        return solve(nums , i + 1 , ans^nums[i]) + solve(nums , i + 1 , ans);
    }
};