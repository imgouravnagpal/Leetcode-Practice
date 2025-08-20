class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int start = i+1;
            int end = n-1;
            while(start < end)
            {

                if(nums[i] + nums[start] + nums[end] == 0)
                {
                    vector<int> temp = {nums[i] , nums[start] , nums[end]};
                    ans.push_back(temp);

                    while(start+1 < n && nums[start] == nums[start+1])
                    {
                        start++;
                    }
                    start++;

                    while(end-1 >=0 && nums[end] == nums[end-1])
                    {
                        end--;
                    }
                    end--;
                }
                else if (nums[i] + nums[start] + nums[end] < 0)
                {
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
        
    }
};