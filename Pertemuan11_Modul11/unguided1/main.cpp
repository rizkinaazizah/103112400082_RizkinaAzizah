#include "MultiLL.h"

int main() {
listParent LP;
createListParent(LP);


NodeParent G1 = allocNodeParent("G001", "Aves");
NodeParent G2 = allocNodeParent("G002", "Mamalia");
NodeParent G3 = allocNodeParent("G003", "Pisces");
NodeParent G4 = allocNodeParent("G004", "Amfibi");
NodeParent G5 = allocNodeParent("G005", "Reptil");


insertLastParent(LP, G1);
insertLastParent(LP, G2);
insertLastParent(LP, G3);
insertLastParent(LP, G4);
insertLastParent(LP, G5);


insertLastChild(G1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
insertLastChild(G1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));


insertLastChild(G2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
insertLastChild(G2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
insertLastChild(G2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));


insertLastChild(G4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

//no.3
// Hapus parent G004 (Amfibi)
NodeParent P = LP.first;
// Cari node G003 (sebelum G004)
while (P != NULL && P->isidata.idGolongan != "G003") {
    P = P->next;
}

if (P != NULL) {
    deleteAfterParent(LP, P);
}

cout << endl << "SETELAH DELETE G004" << endl << endl;
//

printMLLStructure(LP);
cout << endl;
searchHewanByEkor(LP, false);
return 0;
}