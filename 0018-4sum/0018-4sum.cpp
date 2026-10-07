// this code is for solving the run time else the idea is same
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 3; ++i) 
        {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; ++j) 
            {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long targetSum = static_cast<long long>(target) - nums[i] - nums[j];
                int start = j + 1;
                int end = n - 1;

                while (start < end) 
                {
                    long long sum = static_cast<long long>(nums[start]) + nums[end];
                    
                    if (sum == targetSum) 
                    {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        
                        // Skip duplicates for the third element
                        while (start < end && nums[start] == nums[start + 1])
                            ++start;
                        
                        // Skip duplicates for the fourth element
                        while (start < end && nums[end] == nums[end - 1])
                            --end;

                        ++start;
                        --end;
                    } 
                    else if (sum < targetSum) 
                    {
                        ++start;
                    } 
                    else 
                    {
                        --end;
                    }
                }
            }
        }
        
        return result;
    }
};
