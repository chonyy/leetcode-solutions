class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<Integer, Integer>();
        
        for(int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        Map<Integer, List<Integer>> bucket = new HashMap<Integer, List<Integer>>();
        
        for(var entry : freq.entrySet()) {
            int f = entry.getValue();
            if(bucket.get(f) == null) {
                bucket.put(f, new ArrayList<Integer>());
            }
            bucket.get(f).add(entry.getKey());
        }
        
        int[] res = new int[k];
        int n = nums.length;
        int curK = 0;
        for(int i = n; i >= 0; i --) {
            if(bucket.get(i) == null) {
                continue;
            }
            for(int num : bucket.get(i)) {
                if(curK >= k) {
                    break;
                }
                
                res[curK] = num;
                curK ++;
            }
        }
        
        return res;
    }
}