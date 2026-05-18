/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Get Level of a Node in a BST
--------------------------------------------------------------------------------
A librarian organizes books in a special binary shelf system: each new book is 
placed to the left if its code is smaller than the current shelf's code, or to 
the right if it is larger. The first book placed becomes the root at level 0. 
Given the sequence of books added and a query code, the librarian needs to know 
exactly how deep that book sits in the shelf — or report that it was never shelved.

Problem
You are given n integers inserted one by one into a Binary Search Tree (BST) in 
the given order. The root is at level 0. Its children are at level 1, 
grandchildren at level 2, and so on.

Given a query value x, find and print its 0-indexed level in the BST. 
If x is not present in the BST, print -1.

Input Format
- Line 1: a single integer n — the number of nodes to insert
- Line 2: n space-separated integers — the values to insert (in order), no duplicates
- Line 3: a single integer x — the value to search for

Output Format
A single integer — the 0-indexed level of x in the BST, or -1 if x is not found.

Constraints
- 1 <= n <= 10^4
- 1 <= values <= 10^6 (all distinct)
- 1 <= x <= 10^6
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Theo đúng tinh thần tinh gọn (lean), chúng ta chia bài toán thành 2 bước đơn giản:
1. Xây dựng cây (Build Tree): Đọc từng giá trị và chèn vào BST theo đúng quy tắc 
   cơ bản (nhỏ hơn qua trái, lớn hơn qua phải). Dùng vòng lặp (iterative) thay vì 
   đệ quy để đảm bảo không bị tràn Stack với N = 10^4 trong trường hợp cây bị lệch.
2. Tìm mức của Node (Find Level):
   - Khởi tạo biến `level = 0` bắt đầu từ root.
   - Duyệt cây tìm giá trị `x`:
     + Nếu `x == giá trị hiện tại`: Trả về `level`.
     + Nếu `x < giá trị hiện tại`: Đi sang nhánh trái, `level` tăng 1.
     + Nếu `x > giá trị hiện tại`: Đi sang nhánh phải, `level` tăng 1.
   - Nếu duyệt đến Node rỗng (nullptr) tức là không tìm thấy, trả về -1.
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

// Hàm chèn Node vào BST (Iterative)
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

// Hàm tìm Level của Node (Iterative)
int GetLevel(Node* root, int x) {
    int level = 0;
    Node* curr = root;
    
    while (curr) {
        if (x == curr->data) return level;
        
        if (x < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        level++;
    }
    
    return -1; // Không tìm thấy
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
    
    std::cout << GetLevel(root, x) << "\n";
    
    return 0;
}