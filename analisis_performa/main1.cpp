#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace std::chrono;

int modulus_iteratif(int a, int b) {
    int sisa = a;
    while (sisa >= b) {
        sisa -= b;
    }
    return sisa;
}

int modulus_rekursif(int a, int b) {
    if (a < b)
        return a;
    else
        return modulus_rekursif(a - b, b);
}

struct DataWaktu {
    int ukuranInput;
    double waktuIteratif; 
    double waktuRekursif; 
};

vector<DataWaktu> grafikData;

void updateGrafikData(int n, double waktuIter, double waktuRekurs) {
    grafikData.push_back({n, waktuIter, waktuRekurs});
}

void cetakTabel() {
    cout << left << setw(5)  << " " 
         << left << setw(20) << "Ukuran Data (n)" 
         << left << setw(25) << "Waktu Rekursif (ms)" 
         << left << setw(25) << "Waktu Iteratif (ms)" << endl;

    int index = 0;
    for (auto &data : grafikData) {
        cout << left << setw(5)  << index++ 
             << right << setw(10) << data.ukuranInput << "          "
             << left << setw(25) << fixed << setprecision(6) << data.waktuRekursif
             << left << setw(25) << fixed << setprecision(6) << data.waktuIteratif << endl;
    }
    cout << endl;
}

int main() {
    int b = 7; 

    vector<int> daftarN = {100, 200, 300, 400, 1500};

    for (int n : daftarN) {
        auto startIter = high_resolution_clock::now();
        modulus_iteratif(n, b);
        auto endIter = high_resolution_clock::now();
        double durasiIter = duration<double, milli>(endIter - startIter).count();

        auto startRek = high_resolution_clock::now();
        modulus_rekursif(n, b);
        auto endRek = high_resolution_clock::now();
        double durasiRek = duration<double, milli>(endRek - startRek).count();

        updateGrafikData(n, durasiIter, durasiRek);
    }

    cetakTabel();

    ofstream file("data_modulus.csv");
    if (!file.is_open()) {
        cout << "GAGAL MEMBUAT FILE CSV" << endl;
        return 1;
    }

    file << "N,Iteratif,Rekursif\n";
    for (auto &d : grafikData) {
        file << d.ukuranInput << ","
             << d.waktuIteratif << ","
             << d.waktuRekursif << "\n";
    }
    file.close();

    cout << "CSV berhasil dibuat!" << endl;

    return 0;  
}
