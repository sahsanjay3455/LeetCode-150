class Solution {
public:
 // Function to check if a character is a vowel
    bool isvowel(char ch) {
        char ch1 = tolower(ch);
        return (ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u');
    }

    string reverseVowels(string s) {
        vector<char> v;

        // Collect all vowels from the string into the vector
        for (char &ch : s) {
            if (isvowel(ch)) {
                v.push_back(ch);
            }
        }

        // Reverse the collected vowels
        reverse(begin(v), end(v));
        
        int j = 0;

        // Replace vowels in the string with reversed vowels from the vector
        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};