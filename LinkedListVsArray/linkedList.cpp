#include <list>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::list;

int main(){
    list<int> elements;
    
    int element_count;
    cin >> element_count;
    //elements.reserve(element_count);
    
    for(int i=0;i<element_count;++i){
        int e;
        cin >> e;
        elements.push_back(e);
    }
    
    //std::sort(elements.begin(), elements.end());
    elements.sort();
    
    //cout<<i;
    //for(int i: elements)
    //for(int i=0;i<element_count;++i)
    //cout<<elements[i];
    
    return 0;
}