/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Get Degree of a BST
--------------------------------------------------------------------------------
A teacher is demonstrating Binary Search Trees to her students by building one 
live, inserting numbers one by one. After all insertions, she wants to find a 
single number that captures how "branchy" the tree is — the maximum number of 
children any node has.

Problem
Given a sequence of integers inserted (in order) into an initially empty BST, 
compute the degree of the resulting tree. The degree of a tree is defined as 
the maximum degree among all nodes, where the degree of a node equals the 
number of its direct children (0, 1, or 2).

Input Format
- Line 1: A single integer n — the number of values to insert.
- Line 2: n space-separated integers — the values to insert.

Output Format
A single integer: 0, 1, or 2 — the degree of the BST.

Constraints
- 1 <= n <= 10^4
- 1 <= values <= 10^6
- All inserted values are distinct (no duplicates).
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thuật toán tinh gọn theo 2 bước, tích hợp "early exit" (thoát sớm) để tối ưu:
1. Xây dựng cây (Build Tree): Dùng vòng lặp (iterative) để chèn Node, loại bỏ rủi 
   ro tràn bộ nhớ Stack (Stack Overflow) với cây lệch (n = 10^4).
2. Tìm Bậc của Cây (Find Tree Degree):
   - Sử dụng Duyệt theo chiều rộng (BFS) với Hàng đợi (Queue).
   - Biến `max_degree` lưu bậc lớn nhất tìm được (khởi tạo là 0).
   - Tại mỗi Node, đếm số con trực tiếp của nó.
   - Nếu đếm được 2 con -> Trả về 2 ngay lập tức (vì 2 là bậc tối đa của BST, 
     không cần duyệt tiếp - chuẩn Lean/Minimalism).
   - Nếu đếm được 1 con -> Cập nhật `max_degree = 1` và tiếp tục duyệt.
   - Trả về `max_degree` khi duyệt xong.
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

// Hàm tính bậc lớn nhất của cây (Iterative BFS với Early Exit)
int GetTreeDegree(Node* root) {
    if (!root) return 0;
    
    int max_degree = 0;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        int current_node_degree = 0;
        
        if (curr->left) {
            current_node_degree++;
            q.push(curr->left);
        }
        if (curr->right) {
            current_node_degree++;
            q.push(curr->right);
        }
        
        // Tối ưu hóa Lean: 2 là bậc tối đa, nếu gặp thì ngắt vòng lặp ngay
        if (current_node_degree == 2) {
            return 2;
        }
        
        if (current_node_degree > max_degree) {
            max_degree = current_node_degree;
        }
    }
    
    return max_degree;
}

int main() {
    // Tối ưu I/O
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
    
    std::cout << GetTreeDegree(root) << "\n";
    
    return 0;
}