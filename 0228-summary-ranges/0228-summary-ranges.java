class Solution {
    public List<String> summaryRanges(int[] nums) {
        int n = nums.length;
        List<String> list = new ArrayList<>();
        int i = 0;

        while (i < n) {
            int j = i;

            while(j < n-1 && nums[j+1] == nums[j] + 1) {
                j ++;
            }
            
            if (i == j) {
                list.add(String.valueOf(nums[i]));
            }
            else {
                list.add(String.format("%d->%d", nums[i], nums[j]));
            }
            i = j + 1;
        }

        return list;
    }
}