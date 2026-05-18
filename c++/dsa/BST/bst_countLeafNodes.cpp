/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Count Leaf Nodes in a BST
--------------------------------------------------------------------------------
A gardener plants seeds in a tree shaped by numbers — each new seed finds its 
place by going left when smaller and right when larger than the current branch. 
After all seeds are planted, the gardener wants to count the leaf nodes: the 
tips of the tree that have grown no further branches.

Problem
Given a sequence of n distinct integers inserted one by one into an initially 
empty Binary Search Tree (BST), count the total number of leaf nodes — nodes 
that have no left child and no right child.

Input Format
- Line 1: a single integer n — the number of nodes to insert
- Line 2: n space-separated distinct integers — the insertion order

Output Format
A single integer — the number of leaf nodes in the BST after all insertions.

Constraints
- 1 <= n <= 10^4
- 1 <= values <= 10^6
- All values are distinct (no duplicates)

Notes
- A leaf node is defined as a node with left == nullptr and right == nullptr.
- Insertion follows standard BST rules: values smaller than the current node 
  go left; values larger go right; duplicates are ignored.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Duy trì sự tinh gọn và an toàn, giải pháp được chia làm 2 bước:
1. Xây dựng cây (Build Tree): Tiếp tục dùng vòng lặp (iterative) để chèn Node, 
   tránh hoàn toàn rủi ro Stack Overflow khi gặp test case cây suy biến (mọc 
   lệch về một phía với độ sâu 10^4).
2. Đếm số lá (Count Leaves): 
   - Thay vì dùng đệ quy (có nguy cơ tràn bộ nhớ stack với cây quá sâu), ta dùng 
     Duyệt theo chiều rộng (BFS) kết hợp Hàng đợi (Queue).
   - Lấy từng Node ra khỏi Queue kiểm tra: Nếu Node đó không có cả con trái và 
     con phải (!left && !right), nó là một chiếc lá -> tăng biến đếm (count).
   - Nếu có con, tiếp tục đẩy các con vào Queue để kiểm tra sau.
================================================================================
*/

// ================================================================================
// PART 3: CODE
// ================================================================================
#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn Node (Iterative Insertion)
Node* Insert(Node* root, int val) {
    if (!root) return new Node(val);
    
    Node* curr = root;
    while (true) {
        if (val < curr->data) {
            if (!curr->left) {
                curr->left = new Node(val);
                break;
            }
            curr = curr->left;
        } else if (val > curr->data) {
            if (!curr->right) {
                curr->right = new Node(val);
                break;
            }
            curr = curr->right;
        } else {
            break; 
        }
    }
    return root;
}

// Hàm đếm số Node lá (Iterative BFS)
int CountLeaves(Node* root) {
    if (!root) return 0;
    
    int leaf_count = 0;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        // Kiểm tra điều kiện Node lá
        if (!curr->left && !curr->right) {
            leaf_count++;
        }
        
        // Đẩy các Node con vào hàng đợi
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    
    return leaf_count;
}

int main() {
    // Tối ưu I/O cho C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (!(std::cin >> n)) return 0;
    
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        root = Insert(root, val);
    }
    
    std::cout << CountLeaves(root) << "\n";
    
    return 0;
}