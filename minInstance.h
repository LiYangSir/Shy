//
// Created by 13152 on 2019/9/6.
//

#ifndef SHY_MININSTANCE_H
#define SHY_MININSTANCE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
class minInstance {
public:
    minInstance(vector<int> &it,int num);
    int test();
    int num(int i);
    int getMin();
    void getMax(int f);
    void toString();

private:
    int m;
    int n;
    vector<int> item,copyMax;
    int check();
    int min = 10000;
    int max = 0;
    vector<int> input;
};


#endif //SHY_MININSTANCE_H
