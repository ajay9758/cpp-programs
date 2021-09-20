/*
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.
The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
We stop adding right before a duplicate element occurs in s[k].
Return the longest length of a set s[k].
Example 1:

Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
Example 2:

Input: nums = [0,1,2]
Output: 1

*/
#include <iostream>
#include <vector>
#include<random>
#include<time.h>
using namespace std;

class Solution
{
    
    int maxi = 0;
    int vis[100005];

public:
    void ok(int i, int t, vector<int> &nums)
    {
        if (vis[i] == 1)
        {
            maxi = max(maxi, t);
            return;
        }
        vis[i] = 1;
        ok(nums[i], t + 1, nums);
        return;
    }

    int arrayNesting(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] == 0)
            {
                ok(i, 0, nums);
            }
        }
        return maxi;
    }
};

int main()
{
    int n, x;
    cin >> n;
    vector<int> nums;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand() %10;
        cout<<x<<" ";
        nums.push_back(x);
    }

    Solution obj;
cout<<endl;
    cout << obj.arrayNesting(nums);
}