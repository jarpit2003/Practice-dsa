class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        // Initialize the min-heap with the first k elements (or fewer)
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // If the heap has fewer than k elements, just add the value
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // If the new value is larger than the smallest in the heap, replace the smallest
        else if (val > minHeap.top()) {
            minHeap.pop();  // Remove the smallest
            minHeap.push(val);  // Add the new value
        }
        // Return the kth largest element, which is the smallest element in the min-heap
        return minHeap.top();
    }

private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};