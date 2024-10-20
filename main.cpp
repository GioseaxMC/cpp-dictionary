#include "dicts.h"
#include <windows.h>

using namespace std;

int main(void){
    try{
        Hash<string> map;
        
        map.add("foo", "ciaoooo");
        
        cout << map["foo"] << endl;
        
        map.set("foglia", "256");
        
        cout << map["foglia"] << endl;
    } catch (string e){
        cout << e << endl;
    }
    
    system("pause");
}