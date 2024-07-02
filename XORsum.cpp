class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int s = nums.size();
        if(s == 0)
        {
            return 0;
        }
        if(s == 1)
        {
            return nums[0];
        }
        int ans = 0;
        for(int i = 0 ; i < (1 << s) ; i++)
        {
            int tmp = 0;
            for(int j = 0 ; j < s ; j++)
            {
                if(i & (1 << j))
                {
                    tmp ^= nums[j];
                }
            }
            ans += tmp;
        }
        return ans;
    }
};