#include "../hashstd.h"

int main(void){

    Hash<int> map;

    cout << "\n\nexpected output:\n";
    cout << 256 << endl;
    cout << "returned output:\n";

    try{
        map.set("value", 256);
        cout << map["value"];
    } catch (string e) {
        cout << e;
    }

}