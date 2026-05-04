class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;
    int size = 0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        size ++;

        maxHeap.push(num);

        if (maxHeap.size() > size / 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (size % 2 == 1) {
            return minHeap.top();
        }

        return ((double) maxHeap.top() + (double)minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */