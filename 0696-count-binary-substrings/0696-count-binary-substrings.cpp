class Solution {
public:
    int countBinarySubstrings(string s) {
    // Vector to store consecutive characters and their counts
        vector<pair<char, int>> vp;
        
        // Group consecutive characters
        for (int i = 0; i < s.size();) {
            char ch = s[i];
            int start = i;
            
            // Count consecutive characters
            while (i < s.size() && s[i] == ch) {
                i++;
            }
            vp.push_back(pair<char, int>(ch, i - start));
        }
        
        int ans= 0;

        // Traverse pairs of consecutive groups of '0's and '1's
        for (int i = 0; i < vp.size() - 1; i++)
        {
            ans+=min(vp[i].second,vp[i+1].second);

        
            
        }
        
        return ans;
    }
};