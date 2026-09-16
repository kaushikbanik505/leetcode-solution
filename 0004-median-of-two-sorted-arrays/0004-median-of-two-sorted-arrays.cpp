class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            ans.push_back(nums1[i]);
        }

        for(int j = 0; j < m; j++)
        {
            ans.push_back(nums2[j]);
        }

        int size = ans.size();
        sort(ans.begin(), ans.end());

        double result = 0.0;
        if(size % 2 == 0)
        {
            result = (ans[size/2 - 1] + ans[size/2]) / 2.0;
        }
        else 
        {
            result = ans[size/2] / 1.0;
        }
        return result;
    }
};
