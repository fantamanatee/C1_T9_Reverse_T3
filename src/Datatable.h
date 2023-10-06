#ifndef DATATABLE_H
#define DATATABLE_H
#include <cstdio>
#include <cstring>

class Datatable {
public:
    Datatable();
    char url[0x190000];
    int a;
    int num_requests_made;
    int c;
    int d;
    void saveWebsite(char *content, char *userdata);
    ~Datatable();
};

Datatable::Datatable() {
    /* How do I recreate this? This def hiding something I can feel it
    *(int *)(this + 0x190004) = 0;
    *(int *)(this + 0x190008) = 0x4000;
    *(int *)(this + 0x190000) = 100;
    *(int *)(this + 0x19000c) = 100;
    */
    a = 100;
    num_requests_made = 0;
    c = 0x4000;
    d = 100;
}
int HashFunction(char *content, Datatable *datatable, int param_3);

Datatable::~Datatable() {
}

void Datatable::saveWebsite(char *content, char *userdata) {
	unsigned int a = HashFunction(content, this, this->c);
    printf("%s|||-%d-|||\n", this->url, (unsigned long) a);
    // strcpy((char *)(this + (long)(this->num_requests_made * this->d) + 0x10), content); // The asm instr adds a random (char *)(our_calc) * 0x10 in param 1
    //                                                                                  // of strcpy which must be removed
    // strcpy((char*)(this + a), userdata);
    this->num_requests_made += 1;
}

int HashFunction(char *content, Datatable *datatable, int param_3) {
    // printf("Websites saved %d\n", datatable->num_requests_made);
    // printf("c %d\n", datatable->c);
    // printf("should be %d\n", 0x4000);
    return datatable->num_requests_made * datatable->c;
}

#endif DATATABLE_H
