#ifndef DATATABLE_H
#define DATATABLE_H


class Datatable {
public:
    Datatable();
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
    int a = 100;
    int b = 0;
    int c = 0x4000;
    int d = 100;
}

Datatable::~Datatable() {

}

void Datatable::saveWebsite(char *content, char *userdata) {
	// ???	
}

#endif DATATABLE_H
