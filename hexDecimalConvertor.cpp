#include <bits/stdc++.h>
using namespace std;

#define ll long long

char translateFromNumToAlpha(ll a);
string convertFromDecimalToHexDecimal(string input);
ll translateFromAlphaToNum(char a);
string getInput();
string convertFromHexDecimalToDecimal(string input);
ll getChooseOptionFromUser();
void printResultNumber (string resultNumber);
void printSaparator();

int main() {
    string result;
    string input;
    while(true){
        ll chooseOption = getChooseOptionFromUser();
        if(chooseOption == 0){
            break;
        }

        input = getInput();

        if (chooseOption == 1){
            result = convertFromHexDecimalToDecimal(input);
        }

        else if(chooseOption == 2){
            result = convertFromDecimalToHexDecimal(input);
        }

        printResultNumber(result);
        printSaparator();
    }
}


ll getChooseOptionFromUser(){
    ll chooseOption;
    cout << "hello please choose option\n" << 
            "1- from hexDecimal to decimal\n" << 
            "2- from decimal to hexDecimal\n" << 
            "0- exit\n" << 
            ">>> ";

    cin >> chooseOption;

    return chooseOption;
}

string getInput(){
    string number;
    cout << "please enter the number: ";
    cin >> number;

    return number;
}

ll translateFromAlphaToNum(char a){
    if (isalpha(a)){
        return a - '7';
    }
    else {
        return a - '0';
    }
}

string convertFromHexDecimalToDecimal(string input){
    ll currPower = 0;
    ll resultNumber = 0;
    ll base = 16;
    for (int i = input.size()-1; i >= 0;i--){
        input[i] = toupper(input[i]);
        resultNumber += pow(base,currPower)*translateFromAlphaToNum(input[i]);
        currPower++;
    }
    return to_string(resultNumber);
}

char translateFromNumToAlpha(ll a){
    if (a >= 10 && a <= 15){
        return a + '7';
    }
    else{
        return a + '0';
    }
}

string convertFromDecimalToHexDecimal(string input){
    ll inputLl = stoll(input);
    string resultNumber;
    ll base = 16;
    while (inputLl != 0){
        resultNumber += translateFromNumToAlpha(inputLl % base);
        inputLl /= base;
    }
    reverse(resultNumber.begin(), resultNumber.end());
    return resultNumber;
}

void printResultNumber (string resultNumber){
    cout << "the result is: " << resultNumber << endl;
}

void printSaparator(){
    cout << "======================================\n\n";
}