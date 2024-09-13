class RandomizedSet {
private:
    vector<int> nums;  // Dynamic array to store values
    unordered_map<int, int> indices;  // Hashmap to store value -> index
    
public:
    RandomizedSet() {
        // Constructor
    }
    
    // Insert function
    bool insert(int val) {
        // If the value already exists, return false
        if (indices.find(val) != indices.end()) {
            return false;
        }
        // Otherwise, add the value to the vector and record its index in the hashmap
        nums.push_back(val);
        indices[val] = nums.size() - 1;
        return true;
    }
    
    // Remove function
    bool remove(int val) {
        // If the value does not exist, return false
        if (indices.find(val) == indices.end()) {
            return false;
        }
        // Get the index of the element to remove
        int index = indices[val];
        // Get the last element of the vector
        int lastElement = nums.back();
        
        // Swap the element to remove with the last element
        nums[index] = lastElement;
        indices[lastElement] = index;
        
        // Remove the last element from the vector
        nums.pop_back();
        // Remove the element from the hashmap
        indices.erase(val);
        
        return true;
    }
    
    // GetRandom function
    int getRandom() {
        // Generate a random index and return the element at that index
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */