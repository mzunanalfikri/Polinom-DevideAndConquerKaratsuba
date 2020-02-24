#include "PolinomBF.hpp"

class PolinomDNC : public PolinomBF {
public:
    PolinomDNC();
    PolinomDNC(int n, bool random);

    friend PolinomDNC DevideAndConcuer(const PolinomDNC& A, const PolinomDNC& B, int&, int&);
};