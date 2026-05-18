/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Get Degree of a Node in a BST
--------------------------------------------------------------------------------
A computer science student is studying Binary Search Trees and wants to understand 
the structure of each node. The degree of a node tells you how many children it has 
— 0 for a leaf, 1 for a node with one branch, and 2 for a fully internal node. 
Given a BST built by inserting integers in a specific order, the student wants to 
look up the degree of any queried value.

Problem
Build a Binary Search Tree (BST) by inserting n integers one by one in the given 
order (standard BST insertion — smaller values go left, larger values go right, 
duplicates are ignored). Then, given a query value x, return the degree of the 
node containing x:
- 0 if the node is a leaf (no children)
- 1 if the node has exactly one child
- 2 if the node has two children
- -1 if x is not found in the BST

Input Format
- Line 1: A single integer n — the number of values to insert
- Line 2: n space-separated integers — the values to insert (in order, no duplicates)
- Line 3: A single integer x — the query value

Output Format
A single integer: the degree of the node containing x (0, 1, or 2), or -1 if x is 
not in the BST.

Constraints
- 1 <= n <= 10^4
- 1 <= values, x <= 10^6
- No duplicate values in the input
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thuật toán tinh gọn gồm 2 giai đoạn chính:
1. Xây dựng cây (Build Tree): Sử dụng vòng lặp (iterative) để chèn lần lượt các 
   giá trị vào cây BST. Phương pháp này an toàn với bộ nhớ stack ngay cả khi cây 
   bị lệch (degenerate tree).
2. Tìm và tính bậc (Find & Calculate Degree):
   - Duyệt từ root xuống theo quy tắc BST để tìm node chứa giá trị `x`.
   - Nếu duyệt đến nullptr (không tìm thấy), trả về -1.
   - Nếu tìm thấy node, kiểm tra hai con trỏ `left` và `right`. Số lượng con trỏ 
     khác nullptr chính là bậc (degree) của node đó (0, 1, hoặc 2).
================================================================================
*/

// ================================================================================
// PART 3: CODE
// ================================================================================
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn Node (Iterative)
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

// Hàm tìm và trả về bậc của Node
int GetDegree(Node* root, int x) {
    Node* curr = root;
    
    // Duyệt tìm node chứa giá trị x
    while (curr) {
        if (x == curr->data) {
            // Tính số lượng con trực tiếp (bậc của node)
            int degree = 0;
            if (curr->left) degree++;
            if (curr->right) degree++;
            return degree;
        }
        
        if (x < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    return -1; // Không tìm thấy x trong cây
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
    
    int x;
    std::cin >> x;
    
    std::cout << GetDegree(root, x) << "\n";
    
    return 0;
}