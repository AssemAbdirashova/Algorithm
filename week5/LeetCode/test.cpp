#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_vector(vector<int> v)
{ 
    for(int i=0; i<(int)v.size(); i++)
        std::cout << '\t' << v[i]; 
    std::cout << "\n"; 
    
}

int main()
{
    set <vector<int>> set_of_vectors;
    vector<int> vec_1{ 12, 13, 25, 26 }; 
    vector<int> vec_2{ 10, 11, 12 }; 
    vector<int> vec_3{ 5, 22, 44, 12, 14, 11, 13 }; 
    vector<int> vec_4{ 10, 11, 12 }; 
    vector<int> vec_5{ 12, 13, 25, 26 };
    set_of_vectors.insert(vec_1); 
    set_of_vectors.insert(vec_2); 
    set_of_vectors.insert(vec_3); 
    set_of_vectors.insert(vec_4); 
    set_of_vectors.insert(vec_5);
    set< std::vector<int> >::iterator itr; 
    for(itr=set_of_vectors.begin(); itr!=set_of_vectors.end(); itr++) 
        print_vector(*itr);
    
}