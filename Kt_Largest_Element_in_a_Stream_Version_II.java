class KthLargest {
    int k;
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    public KthLargest(int k, int[] nums) {
        this.k = k;
        for(var n : nums) {
            this.add(n);
        }
    }
    
    public int add(int val) {
        if(minHeap.size() < k) {
            minHeap.add(val);
        } else if (val > minHeap.peek()) {
            minHeap.poll();  
            minHeap.add(val); 
        }
        return minHeap.peek();
    }
}
