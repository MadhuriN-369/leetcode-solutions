class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2)
        return nums.size();
        int m=0; // this will store all the bit that ever appears in the array
        for(int n:nums)
        m|=n;
        return m+1; // include 0 so add 1
        
    }
};