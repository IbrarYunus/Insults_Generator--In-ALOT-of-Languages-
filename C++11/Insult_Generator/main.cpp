
//
//        Author: Ibrar Yunus <Dated: 16/04/2018>
//
//        Test Utility for InsultProcessor class
//
//        ! Happy Swearing !
//

#include <iostream>
#include "InsultsProcessor.h"

int main() {
    std::cout << "[*] Testing Insults Generator" << std::endl;
    InsultsProcessor ip = InsultsProcessor();

    cout<< "-- Testing insults!" << endl;

    for (int i = 2; i < 5; ++i) {
        cout<< "==============" << endl;
        cout<< "Generated insult of word length: " << i << endl;
        cout<< ip.generateInsult(i) << endl;
    }

    return 0;
}