class Solution {
public:
    unordered_map<string, bool> memo; // Memoization map

    // Helper function to parse and evaluate a boolean expression
    bool evaluate(string expression) {
        // Check if the result is already memoized
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        // Base case: if expression is just 't' or 'f'
        if (expression == "t") return true;
        if (expression == "f") return false;

        // The operator is the first character
        char op = expression[0];
        
        // For NOT operation
        if (op == '!') {
            // Evaluate the sub-expression inside parentheses
            return memo[expression] = !evaluate(expression.substr(2, expression.size() - 3));
        }

        // For AND or OR operation
        vector<bool> results;
        int start = 2, braces = 0;
        
        // Extract and evaluate sub-expressions
        for (int i = 2; i < expression.size(); ++i) {
            if (expression[i] == ',' && braces == 0) {
                results.push_back(evaluate(expression.substr(start, i - start)));
                start = i + 1;
            } else if (expression[i] == '(') {
                braces++;
            } else if (expression[i] == ')') {
                braces--;
            }
        }
        results.push_back(evaluate(expression.substr(start, expression.size() - start - 1)));
        
        // Combine results based on the operator
        if (op == '&') {
            return memo[expression] = all_of(results.begin(), results.end(), [](bool r) { return r; });
        } else { // op == '|'
            return memo[expression] = any_of(results.begin(), results.end(), [](bool r) { return r; });
        }
    }

    bool parseBoolExpr(string expression) {
        // Call the evaluate function to parse and calculate the result
        return evaluate(expression);
    }
};
