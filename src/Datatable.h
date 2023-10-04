#ifndef DATATABLE_H
#define DATATABLE_H
#include <cstdio>
#include <cstring>

class Datatable {
public:
    int a;
    int websites_saved;
    int c;
    int d;

    Datatable();
    void saveWebsite(char *content, char *userdata);
    ~Datatable();
};

int HashFunction(char *content, Datatable *datatable, int param_3);

Datatable::Datatable() : a(100), websites_saved(0), c(0x4000), d(100) {}

Datatable::~Datatable() {}

void Datatable::saveWebsite(char *content, char *userdata) {
	unsigned int a = HashFunction(content, this, this->c);
    printf("%s|||-%d-|||\n", content, (unsigned long) a);
    strcpy((char *)(this + (long)(this->websites_saved * this->d) + 0x10), content); // The asm instr adds a random (char *)(our_calc) * 0x10 in param 1
                                                                                     // of strcpy which must be removed
    strcpy((char*)(this + a), userdata);
    this->websites_saved += 1;
}

int HashFunction(char *content, Datatable *datatable, int param_3) {
    return datatable->websites_saved * datatable->c;
}

#endif DATATABLE_H
