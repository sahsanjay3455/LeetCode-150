class Solution {
public:
   // Helper function to recursively find the longest chain
int dfs(const string& word, unordered_map<string, int>& memo, const unordered_map<string, bool>& wordSet) {
    if (memo.find(word) != memo.end()) {
        return memo[word];
    }

    int max_chain_length = 1; // Start with 1 as the word itself is a valid chain

    // Try removing one character at a time
    for (int i = 0; i < word.length(); ++i) {
        string predecessor = word.substr(0, i) + word.substr(i + 1);
        if (wordSet.find(predecessor) != wordSet.end()) {
            max_chain_length = max(max_chain_length, 1 + dfs(predecessor, memo, wordSet));
        }
    }

    // Memoize the result for the current word
    memo[word] = max_chain_length;
    return max_chain_length;
}

int longestStrChain(vector<string>& words) {
    // Sort words by length
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    unordered_map<string, bool> wordSet; // Set for quick lookup of words
    unordered_map<string, int> memo;     // Memoization map

    // Insert all words into the wordSet for quick access
    for (const string& word : words) {
        wordSet[word] = true;
    }

    int longest_chain = 0;
    
    // Find the longest chain for each word
    for (const string& word : words) {
        longest_chain = max(longest_chain, dfs(word, memo, wordSet));
    }

    return longest_chain;
}

};