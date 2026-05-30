/*
Add Student: Please complete the `Insert(Hashtable &, Hocsinh)` function to add an element of the `Hocsinh` data type to a hash table of type `Hashtable`. The `Insert` function will return a result of `1` if the element is successfully added, and return `0` if the element cannot be added. Information provided:
- `Hashtable` is a type of hash table that handles collisions using the probing method.
- The probe function uses the linear probing method: `h(key, i) = ((key % M) + i) % M`, where `M` is the hash table size.
- The hash function is `h(key) = key % M`.
- The load factor of the hash table is fixed at `0.7`, meaning the hash table must always guarantee that the number of elements stored in the hash table does not exceed 70% of the hash table size.
- The symbolic constant `EMPTY` with value `0` is the designated code value for the case where the corresponding position in the hash table is still empty.
- The symbolic constant `DELETE` with value `-1` is the designated code value for the case where the corresponding position in the hash table previously had an element but has been deleted.

Notes:
1. Only implement the `Insert` function.
2. Data types and necessary functions for the data types are already pre-implemented. Students can read and use them.
3. Input and output have been pre-processed and conform to the input/output format.
4. Do not change below default code until meet "your_code_here" comment
*/
#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso <<  ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x) {
//you code here
    if (ht.M <= 0) return 0;
    // enforce load factor: cannot exceed 70%
    int maxAllowed = (int)(LOAD * ht.M + 1e-9);
    if (ht.n >= maxAllowed) return 0;

    long long key = x.Maso;
    int M = ht.M;
    int h = (int)((key % M + M) % M);

    int firstDel = -1;
    for (int i = 0; i < M; ++i) {
        int idx = (h + i) % M;
        int code = ht.table[idx].Maso;
        if (code == EMPTY) {
            int place = (firstDel != -1) ? firstDel : idx;
            ht.table[place] = x;
            ht.n++;
            return 1;
        } else if (code == DELETE) {
            if (firstDel == -1) firstDel = idx;
        } else {
            if (code == x.Maso) {
                return 0; // duplicate key
            }
        }
    }

    if (firstDel != -1) {
        ht.table[firstDel] = x;
        ht.n++;
        return 1;
    }

    return 0;