class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> first, last , count;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(first.find(nums[i]) == first.end())
            {
                first[nums[i]] = i;
            }
            last[nums[i]] = i;
            count[nums[i]]++;
        }
        int ans = 0;
        for(auto i : count)
        {
            if(i.second == (last[i.first] - first[i.first] + 1))
            {
                ans++;
            }
        }
        return ans;
    }
};