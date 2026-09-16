class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>mapp;

        for(int i=0 ; i< nums.size() ;i++)
        {
            int rem = target - nums[i] ;
            if(mapp.find(rem) != mapp.end())
            {
                return {i,mapp[rem]};
            }

            mapp[nums[i]]=i;
        }
        return {-1,-1};
    }
};