class Solution {
public:
   
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(auto i :freq)
        {
            if(i.second > n/3)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};