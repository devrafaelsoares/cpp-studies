#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int temp;

        while (left < right) {

            temp = nums[left];

            left++;
            right--;
        }

        return 0;
    }
};



int main()
{

    Solution* solution = new Solution();
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int expected = solution->removeDuplicates(nums);

    cout << "Resultado: " << expected << endl;

    delete solution;

    return 0;
}