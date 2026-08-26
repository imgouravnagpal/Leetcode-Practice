class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size()+2;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n,vector<int>(n,0));


        for(int len=2;len<n;len++)
        {
            for(int i=0;i+len < n;i++)
            {
                int j = i+len;

                for(int k=i+1;k<j;k++)
                {
                    dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};