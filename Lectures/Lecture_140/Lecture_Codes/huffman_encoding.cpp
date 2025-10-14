/*
Huffman Encoding Algorithm Implementation
Problem: Build Huffman tree and generate binary codes for characters based on frequency

Algorithm Steps:
1. Create leaf nodes for each character with their frequencies
2. Build min-heap (priority queue) of nodes
3. Repeatedly merge two nodes with smallest frequencies
4. Generate binary codes using preorder traversal

Time Complexity: O(N log N) - for priority queue operations
Space Complexity: O(N) - for storing nodes and result codes
*/

class Node {
    public:
    int data;          
    Node* left;        
    Node* right;   
    
    // Constructor to create a new node with given frequency
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Custom comparator for priority queue (min-heap based on frequency)
class cmp {
    public:
    // Operator to compare two nodes - returns true if 'a' has higher priority than 'b'
    // Since we want min-heap, node with smaller frequency has higher priority
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;  // Min-heap: smaller frequency = higher priority
    }
};

class Solution {
  public:
    void traverse(Node* root, vector<string> &ans, string temp) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);  
            return;
        }    
        
        // Recursive case: traverse left subtree (append '0' to code)
        traverse(root->left, ans, temp + '0');
        
        // Recursive case: traverse right subtree (append '1' to code)
        traverse(root->right, ans, temp + '1');
    }
    
    // Main function to build Huffman tree and generate codes
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Step 1: Create min-heap (priority queue) to store nodes
        // Nodes with smaller frequency will have higher priority
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        // Step 2: Create leaf nodes for each character and add to priority queue
        for (int i = 0; i < N; i++) {
            Node* temp = new Node(f[i]);  
            pq.push(temp);                
        }
        
        // Step 3: Build Huffman tree by merging nodes
        // Continue until only one node (root) remains in priority queue
        while (pq.size() > 1) {
            // Extract two nodes with minimum frequencies
            Node* left = pq.top();  
            pq.pop();
            
            Node* right = pq.top(); 
            pq.pop();
            
            // Create new internal node with combined frequency
            Node* newNode = new Node(left->data + right->data);
            
            // Merge rule: According to problem statement:
            // - If frequencies are same: first node goes left, second goes right
            // - If frequencies are different: smaller frequency goes left
            // Since we extract in ascending order, left will have <= frequency than right
            newNode->left = left;
            newNode->right = right;
            
            // Add merged node back to priority queue
            pq.push(newNode);
        }
        
        // Step 4: Get root of completed Huffman tree
        Node* root = pq.top();
        
        // Step 5: Generate Huffman codes using preorder traversal
        vector<string> ans;     // To store generated binary codes
        string temp = "";       // Current code being built during traversal
        
        
        // Traverse tree to generate codes for multiple characters
        traverse(root, ans, temp);
        
        return ans;  
    }
};
