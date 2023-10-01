#include "Datatable.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    long long fstream_options;

    if (argc == 2)
    {
        std::fstream myFile;
        myFile.open(argv[1], std::ios::in | std::ios::out);
        if (myFile.is_open())
        {
            // Instantiate datatable
            std::string myText;
            while (getline(myFile, myText))
            {
                if (4 < myText.size())
                {
                    std::string url = myText.c_str();
                    int sender_success_code = sender(); // Fill in args
                    if (sender_success_code == 0)
                    {
                        // Random copy paste of url = cstr???
                        printf("HTTP request succeeded for URL: %s\n", url);
                    }
                    else
                    {
                        // Random copy paste of url = cstr???
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
