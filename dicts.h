#include <iostream>

void raise(string msg){
    throw msg;
}

/*
    -> dicts.h
    ---
    hash and node class for hashing
*/
template<typename T>
class Node{
public:
    T val;
    bool is_active = 0;
    char index;
    array<Node<T>> children;

    Node(char _index = '.'){
        index = _index;
    }

    Node<T>& get_child(char c){
        //cout << "checking char: " << c << endl;
        //cout << "\tlen of childrens: " << children.length() << endl;
        for(int i=0; i<children.length(); i++){
            Node<T>& node = children[i];
            if (node.index == c){
                return node;
            }
        }
        raise("HashError: Key is does not exist.");
    }

    bool exists(char c){
        for(int i=0; i<children.length(); i++){
            Node<T>& node = children[i];
            if (node.index == c){
                return 1;
            }
        }
        return 0;
    }

    bool add_child(Node<T> node){
        if(!exists(node.index)){
            //cout << "\tpushed node with index: " << node.index << endl;
            children.push(node);
            return 1;
        }
        return 0;
    }
};
template<typename T>
class Hash{
private:
    Node<T> head;
    
    Node<T>& get(string str){
        Node<T> *node = &head;
        for(char c : str){
            node = &node->get_child(c);
        }
        return *node;
    
    }
public:
    Hash(){
        head = Node<T>();
    }


    T& operator[](string index){
        Node<T>& node = get(index);
        if (node.is_active) {
            return get(index).val;
        } else {
            raise("KeyError: Key is non existent.");
        }
    }

    // function to add or edit values
    void push(string str, T value){
        Node<T> *node = &head;

        for(int i=0; i<str.length(); i++){
            //cout << "pushing node with char: " << str.at(i) << endl;
            
            Node<T> t_node(str.at(i));
            
            if(i == str.length()-1){
                t_node.val = value;
                t_node.is_active = 1;
            }

            bool added = node->add_child(t_node);

            node = &node->get_child(str.at(i));

            if (!added) {
                node->val = value;
                node->is_active = 1;
            }
        }
    } // push aliases
    void set(string str, T value){
        push(str, value);
    }
    void add(string str, T value){
        push(str, value);
    }

    T pop(string str){
        Node<T>& node = get(str);
        if(node.is_active){
            node.is_active = 0;
            return node.val;
        } else {
            raise("KeyError: Key does not exist.");
        }
    }

};