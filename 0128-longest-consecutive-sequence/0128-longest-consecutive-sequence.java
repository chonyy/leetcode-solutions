class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        int res = 0;

        for (int num : nums) {
            set.add(num);
        }

        for (int num : set) {
            if (set.contains(num-1)) {
                continue;
            }

            int combo = 1;

            while (set.contains(num+1)) {
                combo ++;
                num = num+1;
            }

            res = Math.max(res, combo);
        }

        return res;
    }
}