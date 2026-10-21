class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        // Split both version strings into vector of integers
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        
        int len1 = v1.size(), len2 = v2.size();
        int maxLength = max(len1, len2);
        
        // Compare revision by revision
        for (int i = 0; i < maxLength; ++i) {
            // If there are no more revisions in v1 or v2, treat them as 0
            int num1 = (i < len1) ? v1[i] : 0;
            int num2 = (i < len2) ? v2[i] : 0;
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        
        return 0;  // If all revisions are equal
    }

private:
    vector<int> split(string version) {
        vector<int> result;
        int num = 0;
        
        for (char ch : version) {
            if (ch == '.') {
                result.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (ch - '0');
            }
        }
        
        // Add the last revision number (if exists)
        result.push_back(num);
        
        return result;
    }
};
