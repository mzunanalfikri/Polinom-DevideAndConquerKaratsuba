#include "PolinomDNC.hpp"
#include <iostream>
using namespace std;

PolinomDNC::PolinomDNC(){}

PolinomDNC::PolinomDNC(int n, bool random) : PolinomBF(n,random){}

PolinomDNC DevideAndConcuer(const PolinomDNC& P1, const PolinomDNC& P2, int& count_kali, int& count_tambah){
    //fungsi untuk mengalikan polinom dengan metode divide and conquer
    PolinomDNC res(P1.derajat + P2.derajat, false);
    int mid = P1.derajat / 2;
    PolinomDNC A0(mid - 1, false);
    PolinomDNC A1(P1.derajat - mid, false);
    PolinomDNC B0(mid - 1, false);
    PolinomDNC B1(P2.derajat - mid, false);

    for (int i = 0 ; i <= mid-1 ; i++){
        A0.koefisien[i] = P1.koefisien[i];
        B0.koefisien[i] = P2.koefisien[i];
    }
    
    for (int i = 0 ; i <=  P2.derajat - mid ; i++){
        A1.koefisien[i] = P1.koefisien[mid+i];
        B1.koefisien[i] = P2.koefisien[mid+i];
    }
    
    int x;
    if (mid-1>P1.derajat - mid){
        x = mid-1;
    } else {
        x = P1.derajat - mid;
    }
    PolinomDNC A0plusA1(x, false );
    PolinomDNC B0plusB1(x, false );
    for (int i = 0 ; i <= mid-1 ; i++){
        A0plusA1.koefisien[i] = A0.koefisien[i]+ A1.koefisien[i];
        B0plusB1.koefisien[i] = B0.koefisien[i]+ B1.koefisien[i];
    }
    for (int i = mid ; i <=  P2.derajat - mid; i++){
        A0plusA1.koefisien[i] = A1.koefisien[i];
        B0plusB1.koefisien[i] = B1.koefisien[i];
    }
    PolinomDNC Y(A0plusA1.derajat + B0plusB1.derajat, false);
    PolinomDNC U(A0.derajat + B0.derajat, false);
    PolinomDNC Z(A1.derajat + B1.derajat, false);
    
    if (P1.derajat == 0){
        PolinomDNC temp(0, false);
        temp.koefisien[0] = P1.koefisien[0]*P2.koefisien[0];
        count_kali ++;
        return temp;
    } 
    else if (P1.derajat == 1) {
        PolinomDNC temp(2, false);
        int ac = P1.koefisien[0]*P2.koefisien[0];
        int bd = P1.koefisien[1]*P2.koefisien[1];
        int abcd = (P1.koefisien[0]+P1.koefisien[1])*(P2.koefisien[0]+P2.koefisien[1]);
        temp.koefisien[0] = ac;
        temp.koefisien[1] = abcd - ac - bd;
        temp.koefisien[2] = bd;
        count_tambah += 4;
        count_kali+=3;
        return temp;
    } 
    else {
        Y = DevideAndConcuer(A0plusA1, B0plusB1, count_kali, count_tambah);
        U = DevideAndConcuer(A0, B0, count_kali, count_tambah);
        Z = DevideAndConcuer(A1, B1, count_kali, count_tambah);
    }

    for (int i = 0 ; i <= U.derajat ; i++){
        res.koefisien[i] += U.koefisien[i];
        res.koefisien[i + mid] -= U.koefisien[i]; 
    }
    for (int i = 0 ; i <= Y.derajat ; i++){
        res.koefisien[i + mid] += Y.koefisien[i];
    }
    for (int i = 0 ; i <= Z.derajat ; i++){
        res.koefisien[i + mid] -= Z.koefisien[i];
        res.koefisien[i + mid*2] += Z.koefisien[i];
    }
    return res;
}
