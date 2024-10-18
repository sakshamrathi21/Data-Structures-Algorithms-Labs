#ifndef HUFFMAN
#define HUFFMAN

#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;
using std::cout, std::endl, std::string;
using std::map, std::set, std::pair, std::make_pair;

// a node of the huffman tree. Already written, observe what is going on.
class tree{
public:
    string value = "┐"; // ┐/0/1/character. for now we just use just ┐.
    tree *left = nullptr, *right = nullptr;

    tree(){}
    tree(char value): value(1, value){}
    tree(tree *left): left(left){}
    tree(tree *left, tree *right): left(left), right(right){}
    
    static tree *merge_trees(tree *left, tree *right){
        return new tree(left, right);
    }

    void print(const string &prefix="", bool isLeftChild=false){
        cout << prefix << (prefix==""?"└──":(isLeftChild? "├─0":"└─1"));
        // cout << "value:" << value << "|" << endl;
        if (isLeaf()) cout << "─[" << value << "]" << endl; else cout << value << endl;
        if (left) left->print(prefix + (isLeftChild?"│  ":"   "), true);
        if (right) right->print(prefix + (isLeftChild?"│  ":"   "), false);
    }
    bool isLeaf() const{ return !(left && right); }
    void get_codes(map<char, string> &map_in_progress, const string &prefix="") const{
        if (left){
            if (left->isLeaf()) map_in_progress[left->value[0]] = prefix + "0";
            else left->get_codes(map_in_progress, prefix + "0");
        }
        if (right){ 
            if (right->isLeaf()) map_in_progress[right->value[0]] = prefix + "1";
            else right->get_codes(map_in_progress, prefix + "1");
        }
    }
    ~tree() {
        delete left; delete right;
    }
};

// this returns the huffman tree using passed map of character to frequency
tree *huffman(const map<char, double> &freq_map)
{   
    vector<tree*> T;
    for (const auto& pair: freq_map) {
        tree* N;
        N = &tree(pair.first);
        tree* temp;
        temp = &tree(*N, NULL);
        T.push_back(temp);
    }
    return BuildTree(T);
}

tree* BuildTree(vector<tree*> T) {
    if (T.size() == 1) return T[0];
    int min = 0;
    for ( int i = 0 ; i < T.size() ; i ++ ) {
        if (int(T[i]->value) < int(T[min]->value)) min = i;
    }
    tree* T_1= T[min];
    T.erase(T.begin() + min);
    min = 0;
    for ( int i = 0 ; i < T.size() ; i ++ ) {
        if (int(T[i]->value) < int(T[min]->value)) min = i;
    }
    tree* T_2= T[min];
    T.erase(T.begin() + min);
    tree* merged = tree::merge_trees(T_1, T_2);
    T.push_back(merged);
    BuildTree(T);
}

// compute the frequencies of characters in the string. For part 3, make sure to skip over backreferences and also set highest priority to the special character.
map<char, double> get_freqs(const string &buf) 
{ 
    map<char, double> frequency_map;
    cout<<"HELLO"<<endl;
    for (int i = 0 ; i < buf.length(); i ++) {
        frequency_map[buf[i]] ++;
    }
    
    return frequency_map; }

#endif