/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Count Nodes at Level K in a BST
--------------------------------------------------------------------------------
A young computer science student, Minh, is experimenting with Binary Search Trees. 
He inserts a sequence of integers one by one and wonders: for a given depth level 
k (where the root sits at level 0), how many nodes live exactly at that level? 

Problem
Given a sequence of n distinct integers inserted into an initially empty BST 
(in the given order), count the number of nodes at exactly level k. The root is 
at level 0, its children are at level 1, their children at level 2, and so on. 
If no node exists at level k, output 0.

Input Format
- Line 1: two integers n and k — the number of nodes and the target level.
- Line 2: n space-separated distinct integers — the insertion order.

Output Format
A single integer — the number of nodes at level k.

Constraints
- 1 <= n <= 10^4
- 0 <= k <= n
- 1 <= values <= 10^6
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Giải pháp tối giản sử dụng 2 bước:
1. Xây dựng cây (Build Tree): Dùng vòng lặp (Iterative) để thêm Node nhằm đảm bảo
   tối ưu bộ nhớ, không bị lỗi Stack Overflow với test case cây bị lệch (n = 10^4).
2. Duyệt tìm số lượng Node (BFS - Level Order):
   - Sử dụng Hàng đợi (Queue) để duyệt cây theo từng tầng (chiều rộng).
   - Biến `current_level` bắt đầu từ 0 (tầng của Root).
   - Nếu `current_level == k`, kích thước của Queue hiện tại chính là số Node 
     thuộc tầng đó -> Trả về `queue.size()`.
   - Nếu không, rút tất cả Node ở tầng hiện tại ra, đẩy con của chúng vào Queue 
     để chuẩn bị duyệt tầng tiếp theo, đồng thời tăng `current_level` lên 1.
   - Nếu Queue rỗng mà chưa tới được tầng `k`, tức là cây không đủ sâu -> Trả về 0.
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

// Hàm đếm số Node tại tầng K bằng BFS
int CountNodesAtLevel(Node* root, int k) {
    if (!root) return 0;
    
    std::queue<Node*> q;
    q.push(root);
    int current_level = 0;
    
    while (!q.empty()) {
        // Nếu đã đến đúng tầng K, trả về số lượng phần tử trong hàng đợi
        if (current_level == k) {
            return q.size();
        }
        
        int size = q.size();
        // Xử lý hết các node ở tầng hiện tại để đẩy tầng tiếp theo vào
        while (size--) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        
        current_level++;
    }
    
    return 0; // Cây không đủ chiều sâu k
}

int main() {
    // Tối ưu hóa I/O
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
    
    std::cout << CountNodesAtLevel(root, k) << "\n";
    
    return 0;
}