class Solution {
public:
    string countAndSay(int n) {
        string result = "1";  // Start with the base case for n = 1
        
        for (int i = 2; i <= n; ++i) {
            string current = "";  // Will store the next sequence
            int count = 1;  // Initialize the count of the first character

            // Process the previous sequence (result) to generate the current one
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    count++;  // Same character, increment count
                } else {
                    // Different character, append the count and previous character
                    current += to_string(count) + result[j - 1];
                    count = 1;  // Reset count for the new character
                }
            }
            
            // Append the last group
            current += to_string(count) + result.back();

            // Update the result to the new sequence
            result = current;
        }
        
        return result;
    }
};
