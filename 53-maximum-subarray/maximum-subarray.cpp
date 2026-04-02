class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTilNow = 0;
        int ans = INT_MIN;
        for(auto i : nums)
        {
            ans = max(ans,i);
        }
        if(ans <=0)
        {
            return ans;
        }
        ans = 0;


        for(auto i : nums)
        {
            maxTilNow += i;
            if(maxTilNow < 0)
            {
                maxTilNow = 0;
            }

            ans = max(ans , maxTilNow);
        }
        return ans;
    }
    
};