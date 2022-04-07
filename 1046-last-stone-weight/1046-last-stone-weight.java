class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b-a);
        
        for(int stone : stones) {
            pq.offer(stone);
        }
        
        while(pq.size() > 1) {
            int diff = pq.poll() - pq.poll();
            pq.offer(diff);
        }
        
        return pq.peek();
    }
}