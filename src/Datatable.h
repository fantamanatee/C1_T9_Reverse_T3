#ifndef DATATABLE_H
#define DATATABLE_H


class Datatable {
public:
    Datatable();
    char test[0x190000];
    int a;
    int b;
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
    b = 0;
    c = 0x4000;
    d = 100;
}

Datatable::~Datatable() {

}

void Datatable::saveWebsite(char *content, char *userdata) {
	// ???	
}

#endif DATATABLE_H
