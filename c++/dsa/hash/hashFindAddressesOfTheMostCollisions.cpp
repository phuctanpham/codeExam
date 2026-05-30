/*
Assignment: List of addresses with the most collisions.

Given an open addressing hash table, with the hash function h(key)=key%M, 
and linear probing function h(key,i)=(h(key)+i)%M. Where key is the key value, 
M is the hash table size, and i is the probe number. Write a program to print 
the addresses on the hash table that experience the most collisions according 
to an input dataset.

Input:
- The first line contains two numbers n, M. Indicating that this dataset has 
  n keys entered, and the hash table has size M.
- The next n numbers are the key values added to the hash table. The value 
  of key is in the range [10000, 100000].

Output: 
A single line consisting of k addresses that have the most collisions, 
printed in ascending order. Each address is separated by a space.

Note:
1) The hash table does not limit the number of keys entered.
2) The maximum number of probes is M-1 times.
3) Students are allowed to use any data structure or library.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, M;
    if (!(cin >> n >> M)) return 0;

    // Initialize hash table with -1 (indicating empty slots)
    vector<int> table(M, -1);
    
    // Array to keep track of collision counts at each address
    vector<int> collisions(M, 0);

    for (int k = 0; k < n; ++k) {
        int key;
        cin >> key;
        
        int h = key % M; // Base hash function

        // Linear probing (up to M-1 probes means checking up to M total slots)
        for (int i = 0; i < M; ++i) {
            int pos = (h + i) % M;
            
            if (table[pos] == -1) {
                // Found an empty slot, insert key and stop probing
                table[pos] = key;
                break;
            } else {
                // Slot is occupied, record a collision at this address
                collisions[pos]++;
            }
        }
    }

    // Find the maximum number of collisions that occurred at any address
    int max_collisions = -1;
    for (int i = 0; i < M; ++i) {
        if (collisions[i] > max_collisions) {
            max_collisions = collisions[i];
        }
    }

    // Print all addresses that have the maximum number of collisions in ascending order
    bool first = true;
    for (int i = 0; i < M; ++i) {
        if (collisions[i] == max_collisions) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}