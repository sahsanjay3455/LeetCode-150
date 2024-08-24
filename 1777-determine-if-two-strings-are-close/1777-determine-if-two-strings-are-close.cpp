class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
       int n = word1.size();
        int m = word2.size();
        if (n != m) {
            return false;
        }

        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        // Frequency count
        for (int i = 0; i < n; i++) {
            
            arr1[word1[i] - 'a']++;
            arr2[word2[i] - 'a']++;
        }

        // Check if both words contain the same unique characters
        for (int i = 0; i < 26; i++) {
            if ((arr1[i] == 0) != (arr2[i] == 0)) {
                return false;
            }
        }

        // Sort and compare frequency counts
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        return arr1 == arr2;
    
        
        
    }
};