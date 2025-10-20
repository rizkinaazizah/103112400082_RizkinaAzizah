#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;


struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

string  createpejaran(string namaMapel, string kodeMapel);
void tampilpelajaran(pelajaran &p);

#endif 