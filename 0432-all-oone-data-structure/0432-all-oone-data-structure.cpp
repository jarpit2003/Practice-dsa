class AllOne {
private:
    // Doubly linked list node structure
    struct Node {
        int count;
        unordered_set<string> keys; // Set of keys with this count
        Node(int c) : count(c) {}
    };

    // Doubly linked list
    list<Node> dll;

    // Hashmap to track the key -> count node in the linked list
    unordered_map<string, list<Node>::iterator> keyCountMap;

public:
    AllOne() {}

    // Increment the count of a key
    void inc(const string& key) {
        // If the key is not in the map, add it with count 1
        if (keyCountMap.find(key) == keyCountMap.end()) {
            if (dll.empty() || dll.front().count != 1) {
                // Create a new node for count 1 if it doesn't exist
                dll.push_front(Node(1));
            }
            dll.front().keys.insert(key);
            keyCountMap[key] = dll.begin();
        } else {
            // Move the key to the next count node
            auto curNode = keyCountMap[key];
            int curCount = curNode->count;
            auto nextNode = next(curNode);
            
            // If there is no next node or its count is not curCount + 1, add a new node
            if (nextNode == dll.end() || nextNode->count != curCount + 1) {
                nextNode = dll.insert(nextNode, Node(curCount + 1));
            }
            nextNode->keys.insert(key);
            keyCountMap[key] = nextNode;

            // Remove the key from the current node and erase the node if it's empty
            curNode->keys.erase(key);
            if (curNode->keys.empty()) {
                dll.erase(curNode);
            }
        }
    }

    // Decrement the count of a key
    void dec(const string& key) {
        if (keyCountMap.find(key) == keyCountMap.end()) return;

        auto curNode = keyCountMap[key];
        int curCount = curNode->count;

        // If the count is 1, remove the key entirely
        if (curCount == 1) {
            keyCountMap.erase(key);
        } else {
            // Move the key to the previous count node
            auto prevNode = prev(curNode);
            if (curNode == dll.begin() || prevNode->count != curCount - 1) {
                // Add a new node for curCount - 1 if it doesn't exist
                prevNode = dll.insert(curNode, Node(curCount - 1));
            }
            prevNode->keys.insert(key);
            keyCountMap[key] = prevNode;
        }

        // Remove the key from the current node and erase the node if it's empty
        curNode->keys.erase(key);
        if (curNode->keys.empty()) {
            dll.erase(curNode);
        }
    }

    // Get the key with the maximum count
    string getMaxKey() {
        return dll.empty() ? "" : *dll.back().keys.begin();
    }

    // Get the key with the minimum count
    string getMinKey() {
        return dll.empty() ? "" : *dll.front().keys.begin();
    }
};