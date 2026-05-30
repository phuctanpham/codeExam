/*
Search by ID: Please complete the `Search(Hashtable &, int, int &)` function to find an element with an integer ID (`maso`) within a hash table of type `Hashtable` (`ht`). The `Search` function should return the integer index as the result, along with the integer number of probes (`nprob`) required to find that element. Note the following:
- `Hashtable` is a type of hash table that handles collisions using the probing (open addressing) method.
- The re-hash function uses quadratic probing: $h(key, i) = ((key \% M) + i*i) \% M$, where $M$ is the size of the hash table.
- The primary hash function is: $h(key) = key \% M$.
- The load factor of the hash table is fixed at **0.7**, meaning the hash table always ensures that the number of stored elements does not exceed **70%** of the hash table's total size.
- The symbolic constant `EMPTY` with a value of **0** is the designated ID value for cases where the corresponding position in the hash table is currently empty.
- The symbolic constant `DELETE` with a value of **-1** is the designated ID value for cases where the corresponding position in the hash table previously contained an element but has since been deleted.

Notes:
1. Only implement the `Search` function.
2. The necessary data types and their associated functions are pre-implemented. Students may review and utilize them.
3. The input and output have been pre-processed and conform perfectly to the required input/output format.
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
int Search(Hashtable, int, int &);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Search(hashtable, k, nprob) >- 1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
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

int Search(Hashtable ht, int maso, int &nprob) {
// your code here
    if (ht.M <= 0) { nprob = 0; return -1; }
    int h = ((maso % ht.M) + ht.M) % ht.M;
    nprob = 0;
    for (int i = 0; i < ht.M; ++i) {
        int idx = (h + i * i) % ht.M;
        int code = ht.table[idx].Maso;
        if (code == maso) { nprob = i; return idx; }
        if (code == EMPTY) return -1;
}

return -1;