#include "PolinomDNC.hpp"
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;

int main() {
    int n;
    int count_kali, count_tambah;

    cout << "=========================================================" << endl;
    cout << "=============== Program Perkalian Polinom ===============" << endl;
    cout << "===== Menggunakan BruteForce dan Devide and Qonquer =====" << endl;
    cout << "=========================================================" << endl << endl;
    cout << "Masukkan derajat tertinggi Polinom : ";
    cin >> n;
    PolinomDNC A(n, true);
    PolinomDNC B(n, true);
    
    cout << endl << "Polinom 1 : " ;
    A.CetakPolinomBF();
    cout << "Polinom 2 : " ;
    B.CetakPolinomBF();
    cout << endl;

    const clock_t begin_time = clock();
    cout << "Hasil BF : ";
    BruteForce(A,B, count_kali, count_tambah).CetakPolinomBF();
    cout << "Waktu yang diperlukan algoritma BF tersebut : ";
    cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
    cout << "Operasi Kali : " << count_kali << endl;
    cout << "Operasi Tambah : " << count_tambah << endl;

    cout << endl;

    count_tambah = 0;
    count_kali = 0;
    const clock_t begin_time2 = clock();
    cout << "Hasil DNC : ";
    DevideAndConcuer(A,B, count_kali, count_tambah).CetakPolinomBF();
    cout << "Waktu yang diperlukan algoritma DNC tersebut : ";
    cout << float( clock () - begin_time2 ) /  CLOCKS_PER_SEC << endl;
    cout << "Operasi Kali : " << count_kali << endl;
    cout << "Operasi Tambah : " << count_tambah << endl;
    return 0;
}