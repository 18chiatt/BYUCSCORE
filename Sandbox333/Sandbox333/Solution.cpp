#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 0;
        int previous = -3333;

        for (int curr : nums) {
            if (curr == previous) {
                continue;
            }
            previous = curr;
            nums[next] = curr;
            next++;
        }
        return next;
    }
};