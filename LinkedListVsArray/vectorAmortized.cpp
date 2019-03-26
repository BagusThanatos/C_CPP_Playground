#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int main(){
    vector<int> elements;
    
    int element_count;
    cin >> element_count;
    
    for(int i=0;i<element_count;++i){
        int e;
        cin >> e;
        elements.push_back(e);
    }
    
    std::sort(elements.begin(), elements.end());
    
    //for(int i=0;i<element_count;++i)
    //cout<<elements[i];
    
    return 0;
}