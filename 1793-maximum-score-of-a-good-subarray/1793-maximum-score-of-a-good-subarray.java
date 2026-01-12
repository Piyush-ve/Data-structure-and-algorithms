class Solution {
    public int maximumScore(int[] nums, int k, int i, int j, int Max)
    {
        if(i<0 || j>=nums.length)
        {
            return Integer.MIN_VALUE;
        }
        int a=Integer.MAX_VALUE;
        for(int l=i;l<=j;l++){
            a=Math.min(a,nums[l]);
        }
        a=a*(j-i+1);
        int b=maximumScore(nums, k, i-1,j,Max);
        int c=maximumScore(nums, k, i, j+1, Max);

        Max = Math.max(Max, Math.max(a, Math.max(b, c)));
        return Max;  
    }
    public int maximumScore(int[] nums, int k) {
        int n= nums.length;
        
        return maximumScore(nums, k, k, k, Integer.MIN_VALUE);
        
    }
}