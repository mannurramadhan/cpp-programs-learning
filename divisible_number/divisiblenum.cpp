#include <iostream>
using namespace std;

class Inputs {
public:
    int caseNumber, startNumber, endNumber, divisorNumber;
    int validateVarNum(int index, int num);
    int validateCaseNum(int num);
};

int Inputs::validateVarNum(int index, int num) {
    if (num < 1 || num > 10000) {
        cout << "The var number out of constraint! It must in range 1 - 10000 \n";
        switch (index) {
        case (1) :
            cout << "The number of start (A) : ";
            cin >> startNumber;
            validateVarNum(1, startNumber);
            break;
        case (2) :
            cout << "The number of end (B) : ";
            cin >> endNumber;
            validateVarNum(2, endNumber);
            break;
        case (3) :
            cout << "The number of divisor (K) : ";
            cin >> divisorNumber;
            validateVarNum(3, divisorNumber);
            break;
        default :
            exit(0);
        }
    }
}

int Inputs::validateCaseNum(int num) {
    if (num < 1 || num > 100) {
        cout << "The case number out of constraint! It must in range 1 - 100 \n";
        cout << "The number of cases (T) : ";
        cin >> caseNumber;
        validateCaseNum(caseNumber);
    }
}

int generateCalc(int A, int B, int K) {
    // Declare result variable
    int result;

    // Catch divisible number in range A to B
    while (A <= B) {
        if ((A % K) == 0) {
            result += 1;
        }
        A++;
    }
    return result;
}

int main() {
    // Declare Input Object
    Inputs inp;

    // Section Opening Program
    cout << "#####################################################\n";
    cout << "########## DIVISIBLE NUMBER SEARCH PROGRAM ##########\n";
    cout << "##########   By: Mohammad Annur Ramadhan   ##########\n";
    cout << "#####################################################\n\n";

    // Create & Validate Inputs Value
    cout << "The number of cases (T) : ";
    cin >> inp.caseNumber;
    inp.validateCaseNum(inp.caseNumber);

    // Declare Array Variable
    int arrA[inp.caseNumber], arrB[inp.caseNumber], arrK[inp.caseNumber];

    // Looping in each cases for input variable value
    for (int i = 0; i < inp.caseNumber; i++) {
        cout << "\n########## CASE " << (i + 1) << " INPUTS ##########\n";

        // Input A as start number
        cout << "The number of start (A) : ";
        cin >> inp.startNumber;
        inp.validateVarNum(1, inp.startNumber);
        arrA[i] = inp.startNumber;

        // Input B as end number
        cout << "The number of end (B) : ";
        cin >> inp.endNumber;
        inp.validateVarNum(2, inp.endNumber);
        arrB[i] = inp.endNumber;

        // Input K as divisor number
        cout << "The number of divisor (K) : ";
        cin >> inp.divisorNumber;
        inp.validateVarNum(3, inp.divisorNumber);
        arrK[i] = inp.divisorNumber;
    }

    // Section Result
    cout << "\n########## RESULT ##########\n";

    // Looping in each case for generate calculation
    for (int j = 0; j < inp. caseNumber; j++) {
        // Call Function
        int divisibleNumber = generateCalc(arrA[j], arrB[j], arrK[j]);

        // Show Result in each Cases
        cout << "Case " << j + 1 << ": " << divisibleNumber << endl;
    }
}
