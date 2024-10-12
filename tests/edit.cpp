#include "../dicts.h"

int main(void){

    Hash<int> map;

    cout << "\n\nexpected output:\n";
    cout << 128 << endl << 4096 << endl;
    cout << "returned output:\n";
    
    try{
        map.set("value", 256);
        map["value"] = 128;
        cout << map["value"] << endl;
        map["value"] = 4096;
        cout << map["value"];
    } catch (string e) {
        cout << e;
    }

}