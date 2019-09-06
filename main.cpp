#include <iostream>
#include "minInstance.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    int m ,n;
    vector<int> vect;
    cin >> m;
    while (cin >> n){
        vect.push_back(n);
    }
    //for_each(vect.cbegin(),vect.cend(),[=](auto item){cout << item << endl;});
    minInstance instance(vect,m);
    instance.test();
    instance.toString();
    return 0;
}