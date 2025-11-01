#include <bits/stdc++.h> 

// Node structure class
class node {
    public:
    
      int data;    //elementData
      int i;       //arrayNumber  - row
      int j;       //elementIndex - column
        
      //constructor
      node(int data, int row, int col){
          this->data = data;              // used this->data , coz 2 variables named data unlike row, col
          i = row;
          j = col;
      }
};


 // compare elements' value of 2 nodes
class compare{
    public:
      bool operator() (node* a, node* b){
          return a->data > b->data;      // checks if elemnt of node a is greater than b
      }
        
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;  // Using custom node to store the array elemnt the the array;s number(row) and element's index(col)
        
        //step1: Insert first elemnts of all k arrays
        for(int i=0; i<k; i++){
            node* temp = new node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        
        //step2
        while(!minHeap.empty()){
            
            // push the value of top-node (min) into ans array and pop the top node
            node* top = minHeap.top();
            ans.push_back(top->data);
            minHeap.pop();
            
            int i = top->i;
            int j = top->j;
            
            //create and push new node of the next element of the array(i) of which the popped node was into min heap
            if(j+1 < kArrays[i].size()) {
                node* next = new node(kArrays[i][j+1], i, j+1);
                minHeap.push(next);
            }
            
        }
    return ans;
}
