#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;
class Rotor {
public:
    string wiring;        // 26-char string
    char notch;           // // Turning point for other rotors
    int position;         // record the current position 
    int ringSetting;      // Setting up the Rotor ring's first value 

    Rotor (char notch,int ringSetting){
        this->notch = notch;
        this->position = ringSetting;
        this->wiring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    void step(){
        position = (position + 1) % 26;
    };
    bool atNotch(){
        return position == notch - 'A';
    };
};

class Reflector {
public:
    string wiring; // 26-char string
    char reflect(char c);
};

class Plugboard {
public:
    unordered_map<char, char> mapping;
    char swap(char c);
};

class EnigmaMachine {
public:
    Plugboard plugboard;
    Rotor left(E,0);
    Rotor middle(K,4);
    Rotor left(F,8);

    
    Reflector reflector;

    char encryptChar(char c);
    string encryptMessage(string msg);
};
