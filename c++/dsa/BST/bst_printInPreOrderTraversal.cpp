/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Print BST in NLR (Pre-order) Traversal
--------------------------------------------------------------------------------
Given n integers in a specific insertion order, build a Binary Search Tree by 
inserting each value one by one (no duplicates). Then print all values using 
NLR (Node -> Left -> Right) pre-order traversal.

Input Format
- Line 1: A single integer n — the number of values.
- Line 2: n space-separated integers — insertion order (no duplicates).

Output Format
Print n space-separated integers: the NLR pre-order traversal of the BST.

Constraints
- 1 <= n <= 10^4
- 1 <= each value <= 10^6
- All values are distinct (no duplicates)

Notes
- The first value in line 2 becomes the root of the BST.
- Implement the PrintNLR function recursively.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thuật toán tuân theo nguyên tắc tinh gọn gồm 2 phần:
1. Xây dựng cây (Build Tree): Tiếp tục sử dụng vòng lặp (iterative) để chèn node 
   mới nhằm đảm bảo an toàn bộ nhớ (tránh Stack Overflow) khi tạo cây.
2. Duyệt cây tiền thứ tự (Pre-order / NLR): Sử dụng đệ quy (recursive) theo đúng 
   yêu cầu của bài toán (Notes). Thứ tự thực hiện tại mỗi hàm đệ quy là:
   - N (Node) : Xử lý/In ra giá trị của node hiện tại.
   - L (Left) : Tiếp tục gọi đệ quy đi sâu xuống toàn bộ nhánh trái.
   - R (Right): Tiếp tục gọi đệ quy đi sâu xuống toàn bộ nhánh phải.
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

// Hàm duyệt và in cây theo tiền thứ tự NLR (Recursive)
void PrintNLR(Node* root) {
    if (!root) return; // Điều kiện dừng đệ quy
    
    std::cout << root->data << " "; // N: Xử lý Node hiện tại
    PrintNLR(root->left);           // L: Duyệt nhánh trái
    PrintNLR(root->right);          // R: Duyệt nhánh phải
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
    
    PrintNLR(root);
    std::cout << "\n";
    
    return 0;
}