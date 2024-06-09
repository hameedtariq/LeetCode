class Solution {
    void bucketSort(std::vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;

        int minEl = *std::min_element(nums.begin(), nums.end());
        int maxEl = *std::max_element(nums.begin(), nums.end());

        if (minEl == maxEl) return; // All elements are the same, already sorted

        // The range for determining bucket index
        double range = static_cast<double>(maxEl - minEl + 1) / size;

        std::vector<std::vector<int>> buckets(size);

        // Distribute elements into buckets
        for (const int& n : nums) {
            int index = static_cast<int>((n - minEl) / range);
            if (index >= size) {
                index = size - 1; // Handle boundary case where index can be size
            }
            buckets[index].push_back(n);
        }

        // Sort each bucket and concatenate results
        int index = 0;
        for (int i = 0; i < size; ++i) {
            std::sort(buckets[i].begin(), buckets[i].end());
            for (const int& val : buckets[i]) {
                nums[index++] = val;
            }
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        bucketSort(nums);
        int prevVal = -1;
        int maxGap = 0;
        for(auto & num: nums) {
            if(prevVal == -1) {
                prevVal = num;
                continue;
            }
            maxGap = max(maxGap, num - prevVal);
            prevVal = num;
        }

        return maxGap;
    }
};