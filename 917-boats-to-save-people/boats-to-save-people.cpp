class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int size = people.size();
        int boats = 0;
        int start = 0;
        int end = size-1;
        while(start <= end) {
            if(people[start]+people[end] <= limit) {
                boats++;
                start++;
                end--;
            }else{
                end--;
                boats++;
            }
        }
        return boats;
    }
};