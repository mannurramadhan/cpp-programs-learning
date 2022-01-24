                    int a = 0, b = 0, c = 0, d = 0;

                    while ((j + a) < inp.vLine) {
                        down += arrChar[j+a][k];
                        if (down == searchWord.substr(0, (a + 1))) {
                            a++;
                            if (down == searchWord) {wordNum += 1;}
                        } else {
                            a=0;
                            break;
                        }
                        cout << "Point (Down) :" + down <<endl;
                    }
                    while ((j - b) > 0) {
                        up += arrChar[j-b][k];
                        if (up == searchWord.substr(0, (b + 1))) {
                            b++;
                            if (up == searchWord) {wordNum += 1;}
                        } else {
                            b=0;
                            break;
                        }
                        cout << "Point (Up) :" + up <<endl;
                    }
                    while ((k + c) < inp.hLine) {
                        right += arrChar[j][k+c];
                        if (right == searchWord.substr(0, (c + 1))) {
                            c++;
                            if (right == searchWord) {wordNum += 1;}
                        } else {
                            c=0;
                            break;
                        }
                        cout << "Point (Right) :" + right <<endl;
                    }
                    while ((k - d) > 0) {
                        left += arrChar[j][k-d];
                        if (left == searchWord.substr(0, (d + 1))) {
                            d++;
                            if (left == searchWord) {wordNum += 1;}
                        } else {
                            d=0;
                            break;
                        }
                        cout << "Point (Left) :" + left <<endl;
                    }



                    ================================================
                                            int a = 0, b = 0, c = 0, d = 0;

                        while ((j + a) < inp.vLine) {
                            down += arrChar[j+a][k];
                            if (down == searchWord) {
                                wordNum += 1;
                                break;
                            } else if (down == searchWord.substr(0, (a+1))) {
                                a++;
                            } else {
                                break;
                            }
                        }
                        while ((j - b) > 0) {
                            up += arrChar[j-b][k];
                            if (up == searchWord) {
                                wordNum += 1;
                                break;
                            } else if (up == searchWord.substr(0, (b+1))) {
                                b++;
                            } else {
                                break;
                            }
                        }
                        while ((k + c) < inp.hLine) {
                            right += arrChar[j][k+c];
                            if (right == searchWord) {
                                wordNum += 1;
                                break;
                            } else if (right == searchWord.substr(0, (c+1))) {
                                c++;
                            } else {
                                break;
                            }
                        }
                        while ((k - d) > 0) {
                            left += arrChar[j][k-d];
                            if (left == searchWord) {
                                wordNum += 1;
                                break;
                            } else if (left == searchWord.substr(0, (d+1))) {
                                d++;
                            } else {
                                break;
                            }
                        }
