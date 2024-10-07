class Solution {
public:
    int minBitFlips(int start, int goal) {
        start = start ^ goal;
        int count = 0;
        while(start != 0) {
            count += start % 2;
            start /= 2;
        }
        return count;
    }
};
