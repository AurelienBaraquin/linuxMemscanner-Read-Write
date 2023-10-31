#include "cheat.hpp"

void printAddr(pair <long, int> addr) {
    try {
        cout << hex << addr.first << " : " << dec << addr.second << endl;
    } catch (const exception& e) {
        cout << hex << addr.first << " : " << "Error" << endl;
    }
}

void printAllAddr(vector<pair <long, int>> addrs) {
    for (auto addr : addrs) {
        printAddr(addr);
    }
}

void printHelp(void) {
    cout << "Commands :" << endl;
    cout << "X : set value to X" << endl;
    cout << "=X : equal to X" << endl;
    cout << ">X : greater than X" << endl;
    cout << "<X : less than X" << endl;
    cout << ">=X : greater than or equal to X" << endl;
    cout << "<=X : less than or equal to X" << endl;
    cout << "!=X : not equal to X" << endl;
    cout << "X..X : between X and X" << endl;
    cout << "X.. : greater than or equal to X" << endl;
    cout << "..X : less than or equal to X" << endl;
    cout << "X : set value to X" << endl;
    cout << "= : equal to last value" << endl;
    cout << "> : greater than last value" << endl;
    cout << "< : less than last value" << endl;
    cout << ">= : greater than or equal to last value" << endl;
    cout << "<= : less than or equal to last value" << endl;
    cout << "!= : not equal to last value" << endl;
    cout << "+X : add X to last value" << endl;
    cout << "-X : sub X to last value" << endl;
    cout << "show : show all addresses and there values" << endl;
    cout << "pidX : set pid to X" << endl;
    cout << "exit : exit" << endl;
    cout << "help : show this help" << endl;
    cout << "clear : clear screen" << endl;
    cout << "scan : scan memory" << endl;
    cout << "scand : scan dynamic memory" << endl;
    cout << "reset : reset addresses" << endl;
    cout << "setX : set all addresses to value" << endl;
    // cout << "typeX : type = nb byte : 16, 32, 64 for short, int, long" << endl;
}
