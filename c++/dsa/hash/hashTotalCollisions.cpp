/*
Total Collisions: Write a program to insert n positive integer keys into an open-addressing hash table and report the total number of collisions during the insertion of these n keys. The hash table has:
- Hash table size M.
- Hash function: h(key) = key % M.
- Re-hash function (probe sequence): h(key, i) = (h(key) + i) % M.
- Number of re-hashes from 1 to M-1.
- There is no limit to the number of keys entered into the hash table.

The program has input as follows:
- First line: a pair of numbers M and n.
- n following lines, each containing a key to be added to the hash table.

Output: total collisions.

Note: students may use any data structures and libraries.
Examples:

| Input | Output |
| --- | --- |
| `7 5` | `2` |
| `10010 10019 10021 10026 10031` | `//Key 10026 collided 1 time at position 2. Key 10031 collided 1 time at position 0` |
|  |  |
| `7 5` | `3` |
| `10010 10017 10021 10027 10031` | `//Key 10017 collided 1 time at address 0. Key 10031 collided 2 times at address 0 and 1.` |
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long M;
	int n;
	if (!(cin >> M >> n)) return 0;

	if (M <= 0) {
		cout << 0;
		return 0;
	}

	vector<long long> table((size_t)M, LLONG_MIN);
	long long totalCollisions = 0;

	for (int k = 0; k < n; ++k) {
		long long key;
		cin >> key;
		long long h = key % M;
		if (h < 0) h += M;

		bool placed = false;
		for (long long i = 0; i < M; ++i) {
			long long idx = (h + i) % M;
			if (table[(size_t)idx] == LLONG_MIN) {
				table[(size_t)idx] = key;
				totalCollisions += i; // number of occupied probes before placing
				placed = true;
				break;
			}
		}
		if (!placed) {
			// table full: count M collisions (probed all slots)
			totalCollisions += M;
		}
	}

	cout << totalCollisions;
	return 0;
}