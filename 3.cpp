class Solution {
public:
    int kadaneMax(vector<int> nums) {
        int sum=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++) {
            sum = max(nums[i],sum+nums[i]);
            ans= max(ans,sum);
        }
        return ans;

    }
    int kadaneMin(vector<int> nums) {
        int sum=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++) {
            sum = min(nums[i],sum+nums[i]);
            ans= min(ans,sum);
        }
        return ans;

    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        int maxsum = kadaneMax(nums);
        int minsum = kadaneMin(nums);

        if(maxsum<0) return maxsum;
        else return max(maxsum, sum-minsum);

        
    }
};






















// maximum sum cirular subarray
