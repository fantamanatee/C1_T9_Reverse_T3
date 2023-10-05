#ifndef DATATABLE_H
#define DATATABLE_H
#include <cstdio>
#include <cstring>

class Datatable {
public:
    int a;
    int websites_saved;
    int max_transfer_size_in_bytes;
    int d;

    Datatable();
    void saveWebsite(char *content, char *userdata);
    ~Datatable();
};

int HashFunction(char *content, Datatable *datatable, int max_transfer_size_in_bytes);

Datatable::Datatable() : websites_saved(0), max_transfer_size_in_bytes(0x4000), a(100), d(100) {}

Datatable::~Datatable() {}

// Missing asm instructions in saveWebsite
void Datatable::saveWebsite(char *content, char *userdata) {
	unsigned int a = HashFunction(content, this, this->max_transfer_size_in_bytes);
    printf("%s|||-%d-|||\n", content, (unsigned long) a);
    // Instructions below segfault
    // strcpy((char *)(this + (long)(this->websites_saved * this->d) + 0x10), content);
    // strcpy((char*)(this + a), userdata);
    this->websites_saved += 1;
}

int HashFunction(char *content, Datatable *datatable, int max_transfer_size_in_bytes) {
    return datatable->websites_saved * datatable->max_transfer_size_in_bytes;
}

#endif DATATABLE_H
