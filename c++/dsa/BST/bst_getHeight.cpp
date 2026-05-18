/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Get Height of a BST
--------------------------------------------------------------------------------
A forest ranger maintains a record of tree heights by building a classification 
tree — a Binary Search Tree where each new species is inserted in the order it 
is discovered. The ranger needs to know the height of this BST to understand how 
balanced (or unbalanced) the classification has become over time.

Problem:
Given a sequence of n distinct integers inserted into a Binary Search Tree (BST) 
in the given order, compute the height of the BST. The height is defined as the 
number of edges on the longest path from the root to any leaf. A single-node 
tree has height 0.

Input Format:
- Line 1: An integer n — the number of nodes.
- Line 2: n space-separated integers representing the values to insert.

Output Format:
A single integer — the height of the BST.

Constraints:
- 1 <= n <= 10^4
- 1 <= values <= 10^6
- All values are distinct.

Notes:
- ⚠️ Stack warning: For a degenerate (fully sorted) input of n = 10^4, a naive 
  recursive GetHeight may exhaust the default call stack. Consider an iterative 
  approach.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Giải pháp tuân thủ nguyên tắc Tinh gọn (Lean) & An toàn (Robust):
1. Xây dựng cây (Build Tree): Dùng vòng lặp (while) thay vì đệ quy để chèn Node. 
   Đảm bảo không bao giờ bị tràn Stack (Stack Overflow) khi N = 10^4 và dữ liệu 
   đã sắp xếp (cây suy biến thành 1 đường thẳng).
2. Tính chiều cao (Get Height): Thay vì dùng đệ quy duyệt sâu (DFS) rủi ro cao, 
   ta dùng Duyệt theo chiều rộng (BFS) kết hợp hàng đợi (Queue).
   - Bắt đầu với height = -1.
   - Mỗi lần hàng đợi có phần tử, ta duyệt TẤT CẢ các node ở tầng (level) hiện tại, 
     tăng height thêm 1, và đẩy toàn bộ node con của chúng vào hàng đợi cho tầng kế.
   - Khi hàng đợi rỗng, vòng lặp kết thúc, `height` chính là số cạnh dài nhất.
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

// Iterative Insertion (Tránh Stack Overflow)
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

// Iterative BFS Height (Tránh Stack Overflow)
int GetHeight(Node* root) {
    if (!root) return -1; 
    
    int height = -1;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int level_size = q.size();
        height++; 
        
        // Xử lý hết một tầng
        while (level_size--) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    
    return height;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, val;
    if (std::cin >> n) {
        Node* root = nullptr;
        for (int i = 0; i < n; ++i) {
            std::cin >> val;
            root = AddNode(root, val);
        }
        std::cout << GetHeight(root) << "\n";
    }
    
    return 0;
}