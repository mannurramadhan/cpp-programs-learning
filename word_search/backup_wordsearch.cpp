#include <iostream>
#include <cstdlib>
using namespace std;

class Inputs {
public:
    int caseNumber, vLine, hLine;
    string word;
    void validateLineNum(int index, int num);
    void validateWordLength(int length);
    void validateCaseNum(int num);
    void getClearObj();
    int setValue(int index, int value);
};

void Inputs::validateLineNum(int index, int num) {
    if (num < 1 || num > 100) {
        cout << "The line number out of constraint! It must in range 1 - 100 \n";
        switch (index) {
        case (1) :
            cout << "The number of the vertical lines (N) : ";
            cin >> vLine;
            validateLineNum(1, vLine);
            break;
        case (2) :
            cout << "The number of the horizontal lines (M) : ";
            cin >> hLine;
            validateLineNum(2, hLine);
            break;
        default :
            exit(0);
        }
    }
}

void Inputs::validateWordLength(int length) {
    if (length < 1 || length > 100) {
        cout << "The word length out of constraint! It must in range 1 - 100 \n";
        cout << "The number of the horizontal lines (M) : ";
        cin >> word;
        validateWordLength(word.length());
    }
}

void Inputs::validateCaseNum(int num) {
    if (num < 1 || num > 100) {
        cout << "The case number out of constraint! It must in range 1 - 100 \n";
        cout << "The number of cases (T) : ";
        cin >> caseNumber;
        validateCaseNum(caseNumber);
    }
}

void Inputs::getClearObj() {
    caseNumber = 0, vLine = 0; hLine = 0;
    word = "";
}

int Inputs::setValue(int key, int value) {
    switch (key) {
    case (1):
        caseNumber = value;
        return caseNumber;
        break;
    case (2):
        vLine = value;
        return vLine;
    case (3):
        hLine = value;
        return hLine;
    default:
        cout << "Set value failed!";
        exit(0);
    }
}

int main() {
    // Section opening program
    cout << "#####################################################\n";
    cout << "##########       WORD SEARCH PROGRAM       ##########\n";
    cout << "##########   By: Mohammad Annur Ramadhan   ##########\n";
    cout << "#####################################################\n\n";

    // Declare input object
    Inputs inp;

    // Declare value variable
    string strLine, wordLost, firstChar, up, down, left, right, diagonal, d1, d2, d3, d4;
    int casenum, vline, hline, length, wordNum;

    // Create & Validate inputs value
    cout << "The number of cases (T) : ";
    cin >> casenum;
    inp.validateCaseNum(casenum);
    inp.setValue(1, casenum);

    // Declare array variable
    int arrN[inp.caseNumber], arrM[inp.caseNumber], arrRes[inp.caseNumber];
    string arrW[inp.caseNumber];

    // Looping in each cases for input variable value
    for (int i = 0; i < inp.caseNumber; i++) {
        cout << "\n########## CASE " << (i + 1) << " INPUTS ##########\n";

        // Input N as vertical lines (rows)
        cout << "The number of the vertical lines (N) : ";
        cin >> vline;
        inp.validateLineNum(1, vline);
        inp.setValue(2, vline);
        arrN[i] = vline;

        // Input M as horizontal lines (rows)
        cout << "The number of the horizontal lines (M) : ";
        cin >> hline;
        inp.validateLineNum(2, hline);
        inp.setValue(3, hline);
        arrM[i] = hline;

        // Input lineChar in each lines
        string arrChar[inp.vLine][inp.hLine];
        for (int j = 0; j < inp.vLine; j++) {
            cout << "Line " << (j + 1) << ": ";
            cin >> strLine;
            for (int k = 0; k < inp.hLine; k++) {
                arrChar[j][k] = strLine[k];
            }
            strLine = "";
        }

        // Input W as word to look for
        cout << "The word to look for (W) : ";
        cin >> inp.word;
        inp.validateWordLength(inp.word.length());
        arrW[i] = inp.word;

        // Search word in array
        wordLost = arrW[i];
        firstChar = wordLost[0];
        length = wordLost.length();
        wordNum = 0;

        //cout << "------- Traced Words -------" << endl;
        for (int j = 0; j < inp.vLine; j++) {
            for (int k = 0; k < inp.hLine; k++) {
                if (arrChar[j][k] == firstChar) {
                    if ((j == 0) && (k == 0)) {
                        for (int l = 0; l < length; l++) {
                            if (inp.hLine >= length) {right += arrChar[j][k+l];}
                            if (inp.vLine >= length) {
                                down += arrChar[j+l][k];
                                diagonal += arrChar[l][l];
                            }
                        }
                        if (right == arrW[i]) {wordNum += 1;}
                        if (down == arrW[i]) {wordNum += 1;}
                        if (diagonal == arrW[i]) {wordNum += 1;}

                        //cout << right + " " + down + " " + diagonal << endl;
                    } else if ((j == (inp.vLine - 1) && (k == 0))) {
                        for (int l = 0; l < length; l++) {
                            if (inp.hLine >= length) {right += arrChar[j][k+l];}
                            if (inp.vLine >= length) {
                                up += arrChar[j-l][k];
                                diagonal += arrChar[j-l][l];
                            }
                        }
                        if (right == arrW[i]) {wordNum += 1;}
                        if (up == arrW[i]) {wordNum += 1;}
                        if (diagonal == arrW[i]) {wordNum += 1;}

                        //cout << right + " " + up + " " + diagonal << endl;
                    } else if ((j == 0) && (k == (inp.hLine - 1))) {
                        for (int l = 0; l < length; l++) {
                            if (inp.hLine >= length) {left += arrChar[j][k-l];}
                            if (inp.vLine >= length) {
                                down += arrChar[j+l][k];
                                diagonal += arrChar[l][k-l];
                            }
                        }
                        if (left == arrW[i]) {wordNum += 1;}
                        if (down == arrW[i]) {wordNum += 1;}
                        if (diagonal == arrW[i]) {wordNum += 1;}

                        //cout << left + " " + down + " " + diagonal << endl;
                    } else if ((j == (inp.vLine - 1)) && (k == (inp.hLine - 1))) {
                        for (int l = 0; l < length; l++) {
                            if (inp.hLine >= length) {left += arrChar[j][k-l];}
                            if (inp.vLine >= length) {
                                up += arrChar[j-l][k];
                                diagonal += arrChar[j-l][k-l];
                            }
                        }
                        if (left == arrW[i]) {wordNum += 1;}
                        if (up == arrW[i]) {wordNum += 1;}
                        if (diagonal == arrW[i]) {wordNum += 1;}

                        //cout << left + " " + up + " " + diagonal << endl;
                    } else if ((j == ((inp.vLine - 1) / 2)) && (k == ((inp.hLine - 1) / 2))) {
                        for (int l = 0; l < length; l++) {
                            if (inp.hLine >= length) {
                                right += arrChar[j][k+l];
                                left += arrChar[j][k-l];
                            }

                            if (inp.vLine >= length) {
                                down += arrChar[j+l][k];
                                up += arrChar[j-l][k];
                            }
                            if (((inp.vLine + 1) / 2) >= length) {
                                d1 += arrChar[j+l][k+l];
                                d2 += arrChar[j+l][k-l];
                                d3 += arrChar[j-l][k-l];
                                d4 += arrChar[j-l][k+l];
                            }

                        }
                        if (right == arrW[i]) {wordNum += 1;}
                        if (down == arrW[i]) {wordNum += 1;}
                        if (left == arrW[i]) {wordNum += 1;}
                        if (up == arrW[i]) {wordNum += 1;}
                        if (d1 == arrW[i]) {wordNum += 1;}
                        if (d2 == arrW[i]) {wordNum += 1;}
                        if (d3 == arrW[i]) {wordNum += 1;}
                        if (d4 == arrW[i]) {wordNum += 1;}

                        //cout << right + " " + down + " " + left + " " + up + " " + d1 + " " + d2 + " " + d3 + " " + d4 << endl;

                        // Set null d value
                        d1 = "", d2 = "", d3 = "", d4 = "";
                    } else {
                        int a = 0, b = 0, c = 0, d = 0;
                        while ((j + a) < inp.vLine) {
                            down += arrChar[j+a][k];
                            a++;
                        }
                        while ((j - b) > 0) {
                            up += arrChar[j-b][k];
                            b++;
                        }
                        while ((k+c) < inp.hLine) {
                            right += arrChar[j][k+c];
                            c++;
                        }
                        while ((k-d) > 0) {
                            left += arrChar[j][k-d];
                            d++;
                        }

                        if (down == arrW[i]) {wordNum += 1;}
                        if (up == arrW[i]) {wordNum += 1;}
                        if (right == arrW[i]) {wordNum += 1;}
                        if (left == arrW[i]) {wordNum += 1;}

                        //cout << down + " " + up + " " + right + " " + left << endl;
                    }

                    // Set null all variable value
                    up = "", down = "", left = "", right = "", diagonal = "";
                }
            }
        }
        arrRes[i] = wordNum;
        firstChar = "", length = 0, wordNum = 0;
        system("cls");
    }

    // Section result
    cout << "\n########## RESULT ##########\n";

    // Looping in each case for searching word
    for (int i = 0; i < inp.caseNumber; i++) {
        // Show result in each cases
        cout << "Case " << i + 1 << ": " << arrRes[i] << endl;
    }

    return 0;
}
