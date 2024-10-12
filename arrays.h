// requirements:
#include <iostream>
#include <sstream>

using namespace std;

void print(string prompt){
    printf(prompt.c_str());
    printf("\n");
}

void arr_raise(string msg){
    throw msg;
}

//LEN function from python (we love python)
template<typename T, size_t N>
int len(T (&arr)[N]){
    return N;
}

template<typename T>
int len_pointer(T* arr){
    cout << sizeof(arr) << " - " << sizeof(arr[0]) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

template<typename T>
float default_key(T item){
    return float(item);
}

template<typename T>
class array{
    // private:
    public:
    int _length = 0;
    int _capacity = 0;
    T*  _data;
    
    int check_bounds(int index){
        if (index == -1){
            index = _length-1;
            return index;
        }
        if(index < 0 or index >= _length){
            arr_raise("IndexError: List index out of range");
        }
        return index;
    }

    T& get(int index){
        index = check_bounds(index);
        return _data[index];
    }

    bool check_capacity(int offset){
        return (_length + offset > _capacity);
    }

    void expand(){
        if(_capacity){
            _capacity*= 2;
        } else {
            _capacity = 1;
        }
    }

    void copy(){
        T* temp = new T[_capacity];
        for(int i=0; i<_length; i++){
            temp[i] = _data[i];
        }
        _data = nullptr;
        _data = temp;
    }

    // public:
    // LOADER
    template<size_t N>
    void load(T (&arr)[N]){
        for(int i=0; i<N; i++){
            push_back(arr[i]);
        }
    }
        
    T& operator[](int index){
        return get(index);
    }

    // push_back function
    void push_back(T _element){
        if (check_capacity(1)){
            expand();
            copy();
        }
        _data[_length] = _element;
        _length++;
    }
    
    // alias for push_back funcion
    void push(T _element){
        push_back(_element);
    }

    // INSERT function
    void insert(T _element, int index){
        index = check_bounds(index);
        if(check_capacity(1)){
            expand();
        }
        T* temp = new T[_capacity];
        int copied = 0;
        for(int i=0; i<_length; i++){
            if(i==index){
                copied++;
                temp[i] = _element;
            }
            temp[i+copied] = _data[i];
        }
        _length += copied;
        _data = nullptr;
        _data = temp;
    }
    
    // POP function
    T pop(int index=-1){
        index = check_bounds(index);
        T popped;
        T* temp = new T[_length-1];
        int _did_pop = 0;
        for(int i=0; i<_length; i++){
            if(i!=index){
                temp[i-_did_pop] = get(i);
            }else{
                _did_pop = 1;
                popped = get(i);
            }
        }
        _data = nullptr;
        _data = temp;
        _length--;
        return popped;
    }
    
    // SORT function 
    array<T> sort(float(*key)(T)=default_key){
        int n = _length;
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                
                if (key(get(j)) > key(get(j+1))){
                    T temp = get(j);
                    get(j) = get(j+1);
                    get(j+1) = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        } 
    }
    
    // DUPER
    array<T> dup(){
        array<T> temp_arr;
        for(int i=0; i<_length; i++){
            temp_arr.push_back(get(i));
        }
        return temp_arr;
    }
    
    string str() {
        ostringstream oss;
        oss << "[";
        for(int i=0; i<_length; i++){
            if (i != _length-1) {
                oss << _data[i] << ", ";
            } else {
                oss << _data[i];
            }
        }
        oss << "]";
        return oss.str();
    }
    
    // SORTED COPY
    array<T> __sorted__(){
        array<T> temp = dup();
        temp.sort();
        return temp;
    }
    
    //__REVERSED__ function
    array<T> __reversed__(){
        array<T> temp;
        for(int i=0; i<_length; i++){
            temp.push_back(get(_length-i-1));
        }
        return temp;
    }
    
    // length getter
    int length(){ 
        return _length;
    }
    
    // CLEAR function
    void clear() {
        _data = nullptr; // Set the pointer to nullptr to avoid dangling pointer issues
        _length = 0; // Resetting the length
    }
    
    //RAW DATA getter
    T* data(){
        return _data;
    }
    
    //REFERENCING
    T* operator*(){
        return data();
    }
};

template<typename T>
string print_array(array<T> arr, bool newline = 0){
    cout << arr.str();
    if(newline){
        cout << "\n";
    }
}