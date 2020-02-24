#ifndef _PolinomBF__
#define _PolinomBF__

#include <vector>
using namespace std;

class PolinomBF {
public:
    PolinomBF();
    PolinomBF(int n, bool random);
    void CetakPolinomBF();
    friend PolinomBF BruteForce(const PolinomBF& A, const PolinomBF& B, int& , int&);

protected:
    int derajat;
    vector<int> koefisien;
};



#endif