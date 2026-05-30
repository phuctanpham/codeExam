/*
Delete element: Complete the function Delete(Hashtable &ht, int maso, int &nprob) to delete an element with an integer code (maso) in a hash table of type Hashtable (ht). The Delete function will return the integer 1 and the number of probes (nprob) of type int required to delete that element, or return 0 if it cannot be deleted. Given:
- Hashtable is a hash table that handles collisions using probing.
- The re-hash function uses quadratic probing: h(key, i) = ((key % M) + i*i) % M. Where M is the hash table size.
- The hash function is h(key) = key % M.
- The load factor of the hash table is set to 0.7, meaning the hash table always ensures the number of elements stored does not exceed 70% of the hash table size.
- The constant EMPTY 0 is the designated code value for the case where the corresponding position on the hash table is still empty.
- The constant DELETE -1 is the designated code value for the case where the corresponding position on the hash table had an element previously but has been deleted.

Note:
1) Only implement the Delete function.
2) Data types and necessary functions for the data types are pre-installed. Students can read to use them.
3) Input and output have been pre-processed and match the input/output format.
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
int Delete(Hashtable &, int, int &);
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
        if (Delete(hashtable, k, nprob)) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG XOA DUOC" << endl;
        }
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

int Delete(Hashtable &ht, int maso, int &nprob) {
// your code here
    nprob = 0;
    if (ht.M <= 0) return 0;

    int h = ((maso % ht.M) + ht.M) % ht.M;

    for (int i = 0; i < ht.M; i++) {
        int pos = (h + i * i) % ht.M;
        int code = ht.table[pos].Maso;
        if (code == maso) {
            nprob = i;
            ht.table[pos].Maso = DELETE;
            ht.n--;
            return 1;
        }
        if (code == EMPTY) return 0;
    }
    return 0;