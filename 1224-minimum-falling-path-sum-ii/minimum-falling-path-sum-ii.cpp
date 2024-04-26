class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 1) {
            return grid[0][0];
        } else if (grid.size() == 2) {
            return min(grid[0][0] + grid[1][1], grid[0][1] + grid[1][0]);
        }
        int smallestIndex = -1, secondSmallestIndex = -1, smallestSum = 0, secondSmallestSum = 0;
        for (auto& row : grid) {
            auto [firstIndex, firstNum, secondIndex, secondNum, thirdIndex, thirdNum] = getTwoSmallestNums(row);
            if (smallestIndex != firstIndex && smallestIndex != secondIndex) {
                secondSmallestIndex = secondIndex;
                secondSmallestSum = smallestSum + secondNum;
                smallestIndex = firstIndex;
                smallestSum += firstNum;
            } else if (smallestIndex == secondIndex) {
                if (secondSmallestSum + secondNum < smallestSum + thirdNum) {
                    secondSmallestSum += secondNum;
                    secondSmallestIndex = secondIndex;
                } else {
                    secondSmallestSum = smallestSum + thirdNum;
                    secondSmallestIndex = thirdIndex;
                }
                smallestSum += firstNum;
                smallestIndex = firstIndex;
            } else {
                if (smallestSum + secondNum < secondSmallestSum + firstNum) {
                    if (smallestSum + thirdNum < secondSmallestSum + firstNum) {
                        secondSmallestSum = smallestSum + thirdNum;
                        secondSmallestIndex = thirdIndex;
                    } else {
                        secondSmallestSum += firstNum;
                        secondSmallestIndex = firstIndex;
                    }
                    smallestSum += secondNum;
                    smallestIndex = secondIndex;
                } else {
                    swap(smallestSum, secondSmallestSum);
                    smallestSum += firstNum;
                    smallestIndex = firstIndex;
                    secondSmallestSum += secondNum;
                    secondSmallestIndex = secondIndex;
                }
            }
            cout << smallestSum << ' ' << secondSmallestSum << endl;
        }
        return smallestSum;
    }

private:
    array<int, 6> getTwoSmallestNums(vector<int>& arr) {
        int firstIndex = -1, secondIndex = -1, thirdIndex = -1;
        int firstVal = 1e9, secondVal = 1e9, thirdVal = 1e9;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < firstVal) {
                thirdVal = secondVal;
                secondVal = firstVal;
                firstVal = arr[i];
                thirdIndex = secondIndex;
                secondIndex = firstIndex;
                firstIndex = i;
            } else if (arr[i] < secondVal) {
                thirdVal = secondVal;
                secondVal = arr[i];
                thirdIndex = secondIndex;
                secondIndex = i;
            } else if (arr[i] < thirdVal) {
                thirdVal = arr[i];
                thirdIndex = i;
            }
        }
        return {firstIndex, firstVal, secondIndex, secondVal, thirdIndex, thirdVal};
    }
};