//
// Created by 13152 on 2019/9/6.
//

#include "minInstance.h"
using namespace std;

minInstance::minInstance(vector<int> &it, int num):input(it),m(num) {
    n = it.size();
}
int minInstance::test() {
    item.reserve(m-1);
    for(int i = 0; i <m-1;i++){
        item.push_back(1);
    }
    item.at(m-2) = n-m+2;
    num(m-2);
    while(true){
       int i = num(0);
        if(i == 1)
            break;
        if(i == 0){
            int sum = accumulate(item.cbegin(),item.cend(),0);
            if(sum == n){
              int j = getMin();
              min = j;
              getMax(j);
            }
        }
        item[m-2]++;
    }
    return 0;
}

int minInstance::num(int i) {

    while (check()!= -1){
        int i = check();
        item[i] = 1;
        item[i-1]++;
        if(item[0] == n-1)
            return 1;   //全部结束
    }
    return 0; //没有为5的数
}
int minInstance::check() {
    for(int i = 0; i < m -1;++i){
        if(item[i] == n-1)
            return i;
    }
    return -1;
}

int minInstance::getMin() {
    auto ite = input.cbegin();
    auto i = 0;
    auto index = 0;
    auto f = 10000;
    while(true){
        int sum = accumulate(ite+index,ite+index+item[i],0);
        index += item[i];
        i++;
        if(sum < f)
            f = sum;
        if(i == m-1)
            break;
    }
    return f;
}

void minInstance::getMax(int f) {
    if( max < f){
        max = f;
        copyMax = item;
    }

}

void minInstance::toString() {
    cout << max << endl;
    for_each(copyMax.cbegin(),copyMax.cend(),[](auto item1){cout << item1;});
}

