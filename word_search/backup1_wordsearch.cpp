#include <iostream>
#include <cstdlib>
using namespace std;

class Inputs {
public:
    int caseNumber;
    void validateLineNum(int index, int num) {
        int vLine, hLine;
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
    };

    void validateWordLength(int length) {
        string word;
        if (length < 1 || length > 100) {
            cout << "The word length out of constraint! It must in range 1 - 100 \n";
            cout << "The number of the horizontal lines (M) : ";
            cin >> word;
            validateWordLength(word.length());
        }
    };

    void validateCaseNum(int num) {
        int caseNumber;
        if (num < 1 || num > 100) {
            cout << "The case number out of constraint! It must in range 1 - 100 \n";
            cout << "The number of cases (T) : ";
            cin >> caseNumber;
            validateCaseNum(caseNumber);
        }
    };

    void setCaseNumber(int num) {
        caseNumber = num;
    };
};

int main() {
    // Section opening program
    cout << "#####################################################\n";
    cout << "##########       WORD SEARCH PROGRAM       ##########\n";
    cout << "##########   By: Mohammad Annur Ramadhan   ##########\n";
    cout << "#####################################################\n\n";

    // Declare input object
    Inputs inp;

    // Declare value variable
    string word, strLine, searchWord, firstChar, up, down, left, right, diagonal, d1, d2, d3, d4;
    int caseNumber, vLine, hLine, length, wordNum;

    // Create & Validate inputs value
    cout << "The number of cases (T) : ";
    cin >> caseNumber;
    inp.validateCaseNum(caseNumber);
    inp.setCaseNumber(caseNumber);

    // Declare array variable
    int arrRes[inp.caseNumber], arrN[inp.caseNumber], arrM[inp.caseNumber];
    string arrW[inp.caseNumber];

    // Looping in each cases for input variable value
    for (int i = 0; i < inp.caseNumber; i++) {
        cout << "\n########## CASE " << (i + 1) << " INPUTS ##########\n";

        // Input N as vertical lines (rows)
        cout << "The number of the vertical lines (N) : ";
        cin >> vLine;
        inp.validateLineNum(1, vLine);
        arrN[i] = vLine;

        // Input M as horizontal lines (rows)
        cout << "The number of the horizontal lines (M) : ";
        cin >> hLine;
        inp.validateLineNum(2, hLine);
        arrM[i] = hLine;

        // Input lineChar in each lines
        string arrChar[arrN[i]][arrM[i]];
        for (int j = 0; j < arrN[i]; j++) {
            cout << "Line " << (j + 1) << ": ";
            cin >> strLine;
            for (int k = 0; k < arrM[i]; k++) {
                arrChar[j][k] = strLine[k];
            }
            strLine = "";
        }

        // Input W as word to look for
        cout << "The word to look for (W) : ";
        cin >> word;
        inp.validateWordLength(word.length());
        arrW[i] = word;

        // Search word in array
        searchWord = arrW[i];
        firstChar = searchWord[0];
        length = searchWord.length();
        wordNum = 0;

        //cout << "------- Traced Words -------" << endl;
        for (int j = 0; j < arrN[i]; j++) {
            for (int k = 0; k < arrM[i]; k++) {
                if (arrChar[j][k] == firstChar) {
                    if ((j == 0) && (k == 0)) {
                        for (int l = 0; l < length; l++) {
                            if (arrM[i] >= length) {right += arrChar[j][k+l];}
                            if (arrN[i] >= length) {
                                down += arrChar[j+l][k];
                                diagonal += arrChar[l][l];
                            }
                        }
                        if (right == searchWord) {wordNum += 1;}
                        if (down == searchWord) {wordNum += 1;}
                        if (diagonal == searchWord) {wordNum += 1;}

                        //cout << right + " " + down + " " + diagonal << endl;
                    } else if ((j == (arrN[i] - 1) && (k == 0))) {
                        for (int l = 0; l < length; l++) {
                            if (arrM[i] >= length) {right += arrChar[j][k+l];}
                            if (arrN[i] >= length) {
                                up += arrChar[j-l][k];
                                diagonal += arrChar[j-l][l];
                            }
                        }
                        if (right == searchWord) {wordNum += 1;}
                        if (up == searchWord) {wordNum += 1;}
                        if (diagonal == searchWord) {wordNum += 1;}

                        //cout << right + " " + up + " " + diagonal << endl;
                    } else if ((j == 0) && (k == (arrM[i] - 1))) {
                        for (int l = 0; l < length; l++) {
                            if (arrM[i] >= length) {left += arrChar[j][k-l];}
                            if (arrN[i] >= length) {
                                down += arrChar[j+l][k];
                                diagonal += arrChar[l][k-l];
                            }
                        }
                        if (left == searchWord) {wordNum += 1;}
                        if (down == searchWord) {wordNum += 1;}
                        if (diagonal == searchWord) {wordNum += 1;}

                        //cout << left + " " + down + " " + diagonal << endl;
                    } else if ((j == (arrN[i] - 1)) && (k == (arrM[i] - 1))) {
                        for (int l = 0; l < length; l++) {
                            if (arrM[i] >= length) {left += arrChar[j][k-l];}
                            if (arrN[i] >= length) {
                                up += arrChar[j-l][k];
                                diagonal += arrChar[j-l][k-l];
                            }
                        }
                        if (left == searchWord) {wordNum += 1;}
                        if (up == searchWord) {wordNum += 1;}
                        if (diagonal == searchWord) {wordNum += 1;}

                        //cout << left + " " + up + " " + diagonal << endl;
                    } else if ((j == ((arrN[i] - 1) / 2)) && (k == ((arrM[i] - 1) / 2))) {
                        for (int l = 0; l < length; l++) {
                            if (arrM[i] >= length) {
                                right += arrChar[j][k+l];
                                left += arrChar[j][k-l];
                            }

                            if (arrN[i] >= length) {
                                down += arrChar[j+l][k];
                                up += arrChar[j-l][k];
                            }
                            if (((arrN[i] + 1) / 2) >= length) {
                                d1 += arrChar[j+l][k+l];
                                d2 += arrChar[j+l][k-l];
                                d3 += arrChar[j-l][k-l];
                                d4 += arrChar[j-l][k+l];
                            }

                        }
                        if (right == searchWord) {wordNum += 1;}
                        if (down == searchWord) {wordNum += 1;}
                        if (left == searchWord) {wordNum += 1;}
                        if (up == searchWord) {wordNum += 1;}
                        if (d1 == searchWord) {wordNum += 1;}
                        if (d2 == searchWord) {wordNum += 1;}
                        if (d3 == searchWord) {wordNum += 1;}
                        if (d4 == searchWord) {wordNum += 1;}

                        //cout << right + " " + down + " " + left + " " + up + " " + d1 + " " + d2 + " " + d3 + " " + d4 << endl;
                    } else {
                        int a = 0, b = 0, c = 0, d = 0;
                        while ((j + a) < arrN[i] && a < length) {
                            down += arrChar[j+a][k];
                            if (down != searchWord.substr(0, a+1)) {
                                break;
                            }
                            a++;
                        }
                        while ((j - b) > 0 && b < length) {
                            up += arrChar[j-b][k];
                            if (up != searchWord.substr(0, b+1)) {
                                break;
                            }
                            b++;
                        }
                        while ((k+c) < arrM[i] && c < length) {
                            right += arrChar[j][k+c];
                            if (right != searchWord.substr(0, c+1)) {
                                break;
                            }
                            c++;
                        }
                        while ((k-d) > 0 && d < length) {
                            left += arrChar[j][k-d];
                            if (left != searchWord.substr(0, d+1)) {
                                break;
                            }
                            d++;
                        }

                        if (down == searchWord) {wordNum += 1;}
                        if (up == searchWord) {wordNum += 1;}
                        if (right == searchWord) {wordNum += 1;}
                        if (left == searchWord) {wordNum += 1;}
                        if (d1 == searchWord) {wordNum += 1;}
                        if (d2 == searchWord) {wordNum += 1;}
                        if (d3 == searchWord) {wordNum += 1;}
                        if (d4 == searchWord) {wordNum += 1;}

                        //cout << down + " " + up + " " + right + " " + left << endl;
                        a = 0, b = 0, c = 0, d = 0;
                    }

                    // Set null all variable value
                    up = "", down = "", left = "", right = "", diagonal = "", d1 = "", d2 = "", d3 = "", d4 = "";
                }
            }
        }
        arrRes[i] = wordNum;
        //word = "", searchWord = "", firstChar = "", length = 0, wordNum = 0, vLine = 0, hLine = 0;
        system("cls");
    }

    // Section result
    cout << "\n########## RESULT ##########\n";

    // Looping in each case for searching word
    for (int i = 0; i < inp.caseNumber; i++) {
        // Show result in each cases
        cout << "Case " << i + 1 << ": " << arrRes[i] << endl;
    }
}
