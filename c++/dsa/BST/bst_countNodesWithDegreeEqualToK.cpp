/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Count Nodes with Degree Equal to K in a BST
--------------------------------------------------------------------------------
A botanist named Minh studies binary trees in nature. Each tree node can branch 
out in 0, 1, or 2 directions. Minh wants to classify nodes by how many branches 
they have — a leaf has no branches, some nodes fork in one direction, and others 
spread in both directions. Given a binary search tree, can you help Minh count 
how many nodes have exactly k branches?

Problem
Given a sequence of n distinct integers, build a Binary Search Tree (BST) by 
inserting them in the given order. The degree of a node is defined as its number 
of children (0, 1, or 2). Given an integer k (0, 1, or 2), count how many nodes 
in the BST have degree exactly k.

Input Format
- Line 1: two integers n and k — the number of nodes and the target degree
- Line 2: n space-separated distinct integers — the insertion order

Output Format
A single integer — the count of nodes with degree exactly k.

Constraints
- 1 <= n <= 10^4
- k in {0, 1, 2}
- 1 <= values <= 10^6
- All values are distinct
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Đúng với triết lý tinh gọn (Lean & Minimalism), thuật toán gồm 2 bước an toàn:
1. Xây dựng cây (Build Tree): Tiếp tục sử dụng vòng lặp (iterative) để chèn Node. 
   Việc này giúp tránh lỗi tràn bộ nhớ (Stack Overflow) với các cây bị suy biến 
   thành danh sách liên kết khi n = 10^4.
2. Duyệt và Đếm (Traverse & Count):
   - Sử dụng Duyệt theo chiều rộng (BFS) với Hàng đợi (Queue) thay vì đệ quy.
   - Duyệt qua từng Node trong cây, đếm số lượng con trực tiếp của nó (0, 1, hoặc 2).
   - Nếu số lượng con (degree) bằng đúng với k, ta tăng biến đếm `count`.
   - Đồng thời đẩy các Node con (nếu có) vào hàng đợi để tiếp tục xét.
   - Cuối cùng trả về `count`.
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

// Hàm chèn Node vào cây (Iterative)
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

// Hàm đếm số Node có bậc bằng K (Iterative BFS)
int CountNodesWithDegreeK(Node* root, int k) {
    if (!root) return 0;
    
    int count = 0;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        int degree = 0;
        
        // Kiểm tra và đếm số lượng con, đồng thời đẩy vào Queue
        if (curr->left) {
            degree++;
            q.push(curr->left);
        }
        if (curr->right) {
            degree++;
            q.push(curr->right);
        }
        
        // Nếu bậc của Node bằng đúng k, tăng biến đếm
        if (degree == k) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Tối ưu I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k;
    if (!(std::cin >> n >> k)) return 0;
    
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        root = Insert(root, val);
    }
    
    std::cout << CountNodesWithDegreeK(root, k) << "\n";
    
    return 0;
}