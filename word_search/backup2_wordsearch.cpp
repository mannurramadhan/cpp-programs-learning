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

        cout << "------- Traced Words -------" << endl;
        for (int j = 0; j < arrN[i]; j++) {
            for (int k = 0; k < arrM[i]; k++) {
                if (arrChar[j][k] == firstChar) {
                    int a = 0, b = 0, c = 0, d = 0;
                    if ((j == 0) && (k == 0)) {
                        while (arrM[i] >= length && a < length) {
                            right += arrChar[j][k + a];
                            a++;
                        }

                        while (arrN[i] >= length && b < length) {
                            down += arrChar[j + b][k];
                            diagonal += arrChar[b][b];
                            b++;
                        }

                        cout << right + " " + down + " " + diagonal << endl;
                    } else if ((j == (arrN[i] - 1) && (k == 0))) {
                        while (arrM[i] >= length && a < length) {
                            right += arrChar[j][k + a];
                            a++;
                        }

                        while (arrN[i] >= length && b < length) {
                            up += arrChar[j - b][k];
                            diagonal += arrChar[j - b][b];
                            b++;
                        }

                        cout << right + " " + up + " " + diagonal << endl;
                    } else if ((j == 0) && (k == (arrM[i] - 1))) {
                        while (arrM[i] >= length && a < length) {
                            left += arrChar[j][k - a];
                            a++;
                        }

                        while (arrN[i] >= length && b < length) {
                            down += arrChar[j + b][k];
                            diagonal += arrChar[b][k - b];
                            b++;
                        }

                        cout << left + " " + down + " " + diagonal << endl;
                    } else if ((j == (arrN[i] - 1)) && (k == (arrM[i] - 1))) {
                        while (arrM[i] >= length && a < length) {
                            left += arrChar[j][k - a];
                            a++;
                        }

                        while (arrN[i] >= length && b < length) {
                            up += arrChar[j - b][k];
                            diagonal += arrChar[j - b][k - b];
                            b++;
                        }

                        cout << left + " " + up + " " + diagonal << endl;
                    } else if ((((arrN[i] - 1) % 2) == 0) && (((arrM[i] - 1) % 2) == 0)) {
                        if ((j == ((arrN[i] - 1) / 2)) && (k == ((arrM[i] - 1) / 2))) {
                            while (arrM[i] >= length && a < length) {
                                right += arrChar[j][k + a];
                                left += arrChar[j][k - a];
                                a++;
                            }

                            while (arrN[i] >= length && b < length) {
                                down += arrChar[j + b][k];
                                up += arrChar[j - b][k];
                                b++;
                            }

                            while (((arrN[i] + 1) / 2) >= length && c < length) {
                                d1 += arrChar[j + c][k + c];
                                d2 += arrChar[j + c][k - c];
                                d3 += arrChar[j - c][k - c];
                                d4 += arrChar[j - c][k + c];
                                c++;
                            }
                        }

                        cout << right + " " + down + " " + left + " " + up + " " + d1 + " " + d2 + " " + d3 + " " + d4 << endl;
                    } else {
                        while ((j + a) < arrN[i] && a < length) {
                            down += arrChar[j + a][k];
                            a++;
                        }
                        while ((j - b) >= 0 && b < length) {
                            up += arrChar[j - b][k];
                            b++;
                        }
                        while ((k + c) < arrM[i] && c < length) {
                            right += arrChar[j][k + c];
                            c++;
                        }
                        while ((k - d) >= 0 && d < length) {
                            left += arrChar[j][k - d];
                            d++;
                        }

                        // Reset var parameter
                        a = 0, b = 0, c = 0, d = 0;
                        while ((j + a) < arrN[i] && (k + a) < arrM[i] && a < length) {
                            d1 += arrChar[j + a][k + a]; //right-down
                            a++;
                        }
                        while ((j + b) < arrN[i] && (k - b) >= 0 && b < length) {
                            d3 += arrChar[j + b][k - b]; //left-down
                            b++;
                        }
                        while ((j - c) >= 0 && (k + c) < arrM[i] && c < length) {
                            d2 += arrChar[j - c][k + c]; //right-up
                            c++;
                        }
                        while ((j - d) >= 0 && (k - d) >= 0 && d < length) {
                            d4 += arrChar[j - d][k - d]; //left-up
                            d++;
                        }
                        cout << down + " " + up + " " + right + " " + left + " " + d1 + " " + d2 + " " + d3 + " " + d4 << endl;
                    }

                    // Set wordNum
                    if (right == searchWord) {wordNum += 1;}
                    if (down == searchWord) {wordNum += 1;}
                    if (left == searchWord) {wordNum += 1;}
                    if (up == searchWord) {wordNum += 1;}
                    if (diagonal == searchWord) {wordNum += 1;}
                    if (d1 == searchWord) {wordNum += 1;}
                    if (d2 == searchWord) {wordNum += 1;}
                    if (d3 == searchWord) {wordNum += 1;}
                    if (d4 == searchWord) {wordNum += 1;}

                    // Set null all variable value
                    up = "", down = "", left = "", right = "", diagonal = "", d1 = "", d2 = "", d3 = "", d4 = "";
                }
            }
        }

        arrRes[i] = wordNum;
        word = "", searchWord = "", firstChar = "", length = 0, wordNum = 0, vLine = 0, hLine = 0;
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
