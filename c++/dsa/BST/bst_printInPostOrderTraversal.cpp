/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Print BST in LRN (Post-order) Traversal
--------------------------------------------------------------------------------
A librarian organises books by inserting each title one by one into a BST catalogue. 
To audit the collection she needs to visit every book in post order: first the 
entire left shelf, then the entire right shelf, and finally the shelf's root — 
a pattern known as LRN (Left -> Right -> Node).

Problem
Given a sequence of n distinct integers, build a Binary Search Tree (BST) by 
inserting them one by one in the given order. Then print all node values in 
LRN post-order (Left subtree -> Right subtree -> Node).

Input Format
- Line 1: a single integer n — the number of nodes.
- Line 2: n space-separated integers — the insertion order (all distinct).

Output Format
Print n space-separated integers — the post-order (LRN) traversal of the BST.

Constraints
- 1 <= n <= 10^4
- 1 <= value <= 10^6
- All values are distinct (no duplicates).

Notes
- The first value in the input is always the root of the BST.
- Implement void PrintLRN(Node* root) using the provided C++ skeleton.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Theo phương pháp tinh gọn, bài toán được xử lý qua 2 bước:
1. Xây dựng cây (Build Tree): Vẫn sử dụng vòng lặp (iterative) để chèn node thay 
   vì đệ quy. Điều này loại bỏ rủi ro tràn Stack (Stack Overflow) trong trường hợp 
   xấu nhất (cây bị lệch thành một đường thẳng với n = 10^4).
2. Duyệt cây hậu thứ tự (Post-order / LRN): Sử dụng đệ quy đơn giản và tự nhiên 
   nhất để duyệt theo đúng thứ tự L-R-N:
   - L (Left) : Đệ quy đi sâu xuống tận cùng của nhánh trái.
   - R (Right): Đệ quy đi sâu xuống tận cùng của nhánh phải.
   - N (Node) : In ra giá trị của node hiện tại sau khi đã xử lý xong hai nhánh con.
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

// Hàm duyệt và in cây theo hậu thứ tự LRN (Recursive)
void PrintLRN(Node* root) {
    if (!root) return; // Điều kiện dừng đệ quy
    
    PrintLRN(root->left);           // L: Duyệt nhánh trái trước
    PrintLRN(root->right);          // R: Duyệt nhánh phải sau
    std::cout << root->data << " "; // N: Xử lý (in) Node cuối cùng
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
    
    PrintLRN(root);
    std::cout << "\n";
    
    return 0;
}