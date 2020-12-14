class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;
    
    MedianFinder() {
        while (!first.empty()) first.pop();
        while (!second.empty()) second.pop();
    }
    
    void addNum(int num) {
        if (!second.empty()) {
            first.push(second.top()), second.pop();
        }
        first.push(num);
        
        while (first.size() > second.size()) {
            second.push(first.top());
            first.pop();
        }
    }
    
    double findMedian() {
        int even = ((int) first.size() + (int) second.size()) % 2 == 0;
        if (even) {
            return ((double) first.top() + second.top()) / 2.0;
        } else {
            return (double) second.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
