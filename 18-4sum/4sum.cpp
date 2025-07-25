class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            long long sum3 = target - nums[i];
            for(int j=i+1;j<n;j++)
            {
                long long sum2 = sum3-nums[j];
                int start = j+1;
                int end = n-1;
                while(start < end)
                {
                    long long sum = nums[start] + nums[end];
                    if(sum == sum2)
                    {
                        vector<int> cur = {nums[i],nums[j],nums[start],nums[end]};
                        ans.push_back(cur);
                        while(start+1 < n && nums[start] == nums[start+1])
                        {
                            start++;
                        }
                        while(end-1 >=0 && nums[end] == nums[end-1])
                        {
                            end--;
                        }
                        
                        start++,end--;
                    }
                    else if(sum > sum2)
                    {
                        end--;
                    }
                    else{
                        start++;
                    }
                }
                while(j+1<n&&nums[j]==nums[j+1])
                {
                    j++;
                }
            }
            while(i+1<n&&nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return ans;
    }
};