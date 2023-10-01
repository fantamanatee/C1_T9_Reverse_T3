#ifndef DATATABLE_H
#define DATATABLE_H


class Datatable {
public:
    Datatable();
    void saveWebsite(char *param_1, char *param_2);
    ~Datatable();
};

Datatable::Datatable() {
    /*
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

void Datatable::saveWebsite(char *param_1, char *param_2) {

}

#endif DATATABLE_H