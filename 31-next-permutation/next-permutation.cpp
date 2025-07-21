class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-1;i>0;i--)
        {   
            if(nums[i] > nums[i-1])
            {
                index = i-1;
                break;
            }
        }


        if(index < 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>index;i--)
        {
            if(nums[i] > nums[index])
            {
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        return;
        
    }
};