class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int maxTillNow = 0;

        int maxElement = INT_MIN;
        for(auto i : nums)
        {
            maxElement = max(maxElement,i);
        }
        if(maxElement < 0)
        {
            return maxElement;
        }

        for(auto i : nums)
        {
            maxTillNow += i;
            if(maxTillNow < 0)
            {
                maxTillNow = 0;
            }

            maxSum = max(maxSum , maxTillNow);
        }
        return maxSum;
        
    }
};