#include "../dicts.h"

int main(void){

    Hash<int> map;

    cout << "\n\nexpected output:\n";
    cout << 256 << endl;
    cout << "KeyError: Key is non existent." << endl;
    cout << "returned output:\n";

    try{
        map.set("value", 256);
        cout << map.pop("value") << endl;
        cout << map["value"];
    } catch (string e) {
        cout << e;
    }

}