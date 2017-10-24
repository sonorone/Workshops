#include <iostream>
using namespace std;
#include "Kingdom.h"

namespace sict {
    
    void display(const Kingdom& kingdom) {
        
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
    void display(const Kingdom* kArr, int arSize) {
        
        int totalPopulation = 0;
        
        cout
        << "------------------------------" << endl
        << "Kingdoms of SICT"               << endl
        << "------------------------------" << endl;
        for (int i = 0; i < arSize; ++i) {
            
            //// replace the below with display()
            // cout << i + 1 << ". " << kArr[i].m_name
            //     << ", population " << kArr[i].m_population << endl;
            //
            cout << i + 1 << ". ";
            display(kArr[i]);
            display(kArr[i+1]);
            totalPopulation += kArr[i].m_population;
        }
        cout
        << "------------------------------"<< endl
        << "Total population of SICT: " << totalPopulation << endl
        << "------------------------------"<< endl;
    }
}
