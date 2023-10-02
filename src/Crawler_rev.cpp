#include "Datatable.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>

unsigned long write_callback(void *content, unsigned long size, unsigned long nmemb, void *userdata) {
    //Datatable::saveWebsite(*(Datatable **)((long)userdata + 8), (char *)userdata, (char *)content);
    // How tf am I supposed to call savewebsite???
    printf("%d\n", size * nmemb & 0xffffffff);
    return size * nmemb;
}

long sender(char *url, Datatable *datatable) {
    curl_global_init(3); // What is param??? must be == 3
    CURL* curl = curl_easy_init();
    if (curl != 0) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url);
        CURLcode curl_code = curl_easy_perform(curl);
        if (curl_code != CURLE_OK) {
            char* strerror = (char *)curl_easy_strerror(curl_code);
            fprintf(stderr, "curl_easy_perform() failed: %s\n",strerror);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

int HashFunction(char const* some_cstr, Datatable* dt, int some_int) {

}

int main(int argc, char *argv[])
{
    long fstream_options;

    if (argc == 2)
    {
        std::fstream myFile;
        myFile.open(argv[1], std::ios::in | std::ios::out);
        if (myFile.is_open() == '\x01')
        {
            Datatable *datatable = new Datatable();
            std::string myText;
            while (getline(myFile, myText))
            {
                if (4 < myText.size())
                {
                    char *url = (char *) myText.c_str();
                    int sender_success_code = sender(url, datatable);
                    if (sender_success_code == 0)
                    {
                        char *url = (char *) myText.c_str();
                        printf("HTTP request succeeded for URL: %s\n", url);
                    }
                    else
                    {
                        char *url = (char *) myText.c_str();
                        printf("HTTP request failed for URL: %s\n", url);
                    }
                }
            }
            fstream_options = 0;
            // deconstruct string object
            // deconstruct datatable object
        }
        else
        {
            puts("Failed to open file");
            fstream_options = 1;
        }
    }
    else
    {
        puts("give url file please");
        fstream_options = 1;
    }

    return fstream_options;
}
