

class Solution {
public:
    // Function to heapify a subtree rooted with node i
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left child
        int right = 2 * i + 2; // right child

        // If left child is larger than root
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(nums[i], nums[largest]);

            // Recursively heapify the affected subtree
            heapify(nums, n, largest);
        }
    }

    // Main function to do heap sort
    void heapSort(vector<int>& nums) {
        int n = nums.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(nums[0], nums[i]);

            // Call max heapify on the reduced heap
            heapify(nums, i, 0);
        }
    }

    // Function to sort an array
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
