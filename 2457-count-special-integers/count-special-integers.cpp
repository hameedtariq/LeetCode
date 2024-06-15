#include <cmath>
#include <vector>

class Solution {
public:
    int countSpecialNumbers(int n) {
        std::vector<int> digits;
        int x = n;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int m = digits.size();
        int count = 0;

        // Count special numbers with fewer digits
        for (int i = 1; i < m; ++i) {
            count += 9 * A(9, i - 1);
        }

        // Count special numbers with the same number of digits
        std::vector<bool> used(10, false);
        for (int i = m - 1; i >= 0; --i) {
            int d = digits[i];
            for (int j = (i == m - 1) ? 1 : 0; j < d; ++j) {
                if (!used[j]) {
                    count += A(9 - (m - i - 1), i);
                }
            }
            if (used[d]) break;
            used[d] = true;
        }
        return count + (std::unordered_set<int>(digits.begin(), digits.end()).size() == m);
    }

private:
    int A(int m, int n) {  // Permutations: P(m, n) = m! / (m - n)!
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result *= (m - i);
        }
        return result;
    }
};
