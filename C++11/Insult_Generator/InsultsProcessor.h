//
//        Author: Ibrar Yunus <Dated: 16/04/2018>
//
//        InsultProcessor: Generates insults of required number of words.
//        - overloaded constructor allows to read insults from custom file
//        - has a print facility to neatly print insults
//
//        ! Happy Swearing !
//

#ifndef INSULTSGENERATOR_INSULTSPROCESSOR_H
#define INSULTSGENERATOR_INSULTSPROCESSOR_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <cxxabi.h>
#include <random>
#include <cstdlib>
#include <ctime>


using namespace std;

class InsultsProcessor {
private:
    vector<string> insults;
    string DEFAULT_PATH = "res/insults_list.swear";


    void loadInsults(string path) {

        ifstream file(path);
        string line;
        while(getline(file, line)) {
            insults.push_back(line);
        }
    }

    string getDemangledName() {
        int status;
        char * demangled = abi::__cxa_demangle(typeid(this).name(),0,0,&status);
        return string(demangled);
    }


public:


    void printInsults() {
        cout<< getDemangledName() + " : printing list of insults"<<endl;

        int newline_counter = 4;

        cout<<insults.at(0) << endl;


        for(int i = 1; i < insults.size(); i++) {
            cout << insults.at(i) << " ";
            --newline_counter;

            if(newline_counter == 0) {
                cout<<endl;
                newline_counter = 4;
            }
        }


    }

    InsultsProcessor() {
        srand(time(NULL));
        cout<< getDemangledName() + " : initializing insults from default path"<<endl;
        loadInsults(DEFAULT_PATH);
    }

    InsultsProcessor(string path) {
        srand(time(NULL));
        cout<< getDemangledName() + " : initializing insults from custom path"<<endl;
        loadInsults(path);
    }


    string generateInsult(int number_of_words) {

        string builder = "";

        for (size_t i = 0; i < number_of_words; ++i) {

//            int index = rand() % insults.size() + 1;
            builder += insults.at(rand() % insults.size() + 1) + " ";
        }

        return builder;
    }
};


#endif //INSULTSGENERATOR_INSULTSPROCESSOR_H
