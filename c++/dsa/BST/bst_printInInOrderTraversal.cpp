/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Print BST in LNR (In-order) Traversal
--------------------------------------------------------------------------------
A librarian organizes books on a shelf using a special rule: every book to the 
left has a smaller number, and every book to the right has a larger number. When 
she wants to list all books in order, she always starts from the leftmost shelf, 
works through the middle, and finishes at the rightmost shelf — a pattern known 
as LNR (Left -> Node -> Right) traversal.

Problem
Given a sequence of n distinct integers, build a Binary Search Tree (BST) by 
inserting the integers one by one in the given order. Then perform an in-order 
(LNR: Left -> Node -> Right) traversal and print all values.

Key insight: An in-order traversal of a BST always visits nodes in ascending sorted order.

Input Format
- Line 1: An integer n — the number of nodes.
- Line 2: n space-separated distinct integers — the values to insert into the BST, 
  in the given order. The first value becomes the root.

Output Format
Print n space-separated integers — the values visited during LNR (in-order) 
traversal, followed by a newline.

Constraints
- 1 <= n <= 10^4
- 1 <= value <= 10^6
- All values are distinct (no duplicates)

Notes
- You must implement the PrintLNR function using recursive in-order traversal.
- The BST is built using the provided AddNode function — do not change it.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Duy trì sự tinh gọn, giải pháp bao gồm 2 phần:
1. Xây dựng cây (Build Tree): Sử dụng hàm `AddNode` dạng vòng lặp (iterative) để 
   đảm bảo an toàn bộ nhớ (tránh Stack Overflow) khi chèn lượng lớn node có thể 
   tạo thành cây lệch.
2. Duyệt giữa (In-order / LNR): Sử dụng đệ quy (recursive) đúng như yêu cầu bắt 
   buộc của đề bài (phần Notes). Trình tự duyệt L-N-R:
   - L (Left): Gọi đệ quy đi tận cùng xuống nhánh trái (giá trị nhỏ nhất).
   - N (Node): Xử lý/In giá trị của node hiện tại.
   - R (Right): Gọi đệ quy sang nhánh phải (giá trị lớn hơn).
   Đặc tính tự nhiên của BST khi kết hợp với phép duyệt LNR là kết quả đầu ra 
   luôn tự động được sắp xếp theo thứ tự tăng dần.
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

// Hàm chèn Node vào BST (Iterative - Mô phỏng lại AddNode theo chuẩn an toàn)
Node* AddNode(Node* root, int val) {
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

// Hàm duyệt và in cây theo thứ tự giữa LNR (Recursive)
void PrintLNR(Node* root) {
    if (!root) return; // Điều kiện dừng đệ quy
    
    PrintLNR(root->left);           // L: Duyệt toàn bộ nhánh trái
    std::cout << root->data << " "; // N: In giá trị Node hiện tại
    PrintLNR(root->right);          // R: Duyệt toàn bộ nhánh phải
}

int main() {
    // Tối ưu hóa I/O cho luồng dữ liệu lớn
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (!(std::cin >> n)) return 0;
    
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        root = AddNode(root, val);
    }
    
    PrintLNR(root);
    std::cout << "\n";
    
    return 0;
}