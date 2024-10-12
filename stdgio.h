#include <iostream>
#include <vector>
#include <limits>
#include "arrays.h"

#define INT_MAX numeric_limits<int>::max()

using namespace std;

void raise(string msg = ""){
    throw msg;
}

int iota(bool reset = 0){
    static int counter;
    if(reset){
        counter = 0;
        return counter++;
    } else {
        return counter++;
    }
}

template<typename T>
T input(string msg = "") {
    T rtrn;
    cout << msg;
    while(!(cin >> rtrn)){
        cout << "invalid input, try again: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    cin.ignore(INT_MAX, '\n');
    return rtrn;
}

string get_string(string msg = ""){
    cout << msg;
    string var;
    getline(cin, var);
    return var;
}

array<string> split(string str, char chr=' '){
    string temp;
    array<string> vec;
    for(auto c : str){
        if(c != chr){
            temp+=c;
        } else {
            if(!temp.empty()){
                vec.push(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        vec.push(temp);
    }
    return vec;
}

template <typename T>
void print_vector(const array<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

array<string> span(bool(*key)(char), string str){
    string t_string = "";
    string f_string = "";

    bool done = 0;

    for(char c : str){
        if (key(c) and !done) {
            t_string += c;
        } else {
            done = 1;
            f_string += c;
        }
    }
    array<string> temp;
    temp.push(t_string);
    temp.push(f_string);
    return temp;
}
