class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  // Base case

        string sub = countAndSay(n - 1);  // Recursive call
        string newSub = "";
        int count = 1;

        // Loop through the string and apply RLE (Run Length Encoding)
        for (int i = 1; i < sub.size(); ++i) {
            if (sub[i] == sub[i - 1]) {
                count++;  // Same character, increase the count
            } else {
                newSub += to_string(count) + sub[i - 1];  // Append count and the character
                count = 1;  // Reset count for the next character
            }
        }

        // Append the last group
        newSub += to_string(count) + sub.back();

        return newSub;
    }
};
