class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int>mapp;
        int i=0 ;
        int j=0 ;
          int max_size = 0 ;
        while(j< s.size())
        {
            if(mapp.find(s[j]) != mapp.end())
            {
                i= max(i, mapp[s[j]]+1) ;

            }

            int size = (j-i+1);

           max_size = max(size , max_size);

           mapp[s[j]]=j ;
           j++;
        }

        return max_size ;
    }
};