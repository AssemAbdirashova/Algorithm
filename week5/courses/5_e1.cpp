#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;
 
#define SIZE 26
 
int longCommonAnagramSubseq(int str1[],  int str2[], int n1, int n2){
    unordered_map<int, int> freq1, freq2;
    // int freq1[SIZE], freq2[SIZE];
    // memset(freq1, 0, sizeof(freq1));
    // memset(freq2, 0, sizeof(freq2));
     
    int len = 0;

    for (int i = 0; i < n1; i++)
        freq1[str1[i]]++;
     
    for (int i = 0; i < n2; i++)   
        freq2[str2[i]]++;
    
    for (int i = 0; i < SIZE; i++)   
        len += min(freq1[i], freq2[i]);
     
    // required length
    return len;   
}                               
 
// Driver program to test above
int main()
{
    long long int n, m;
    cin >> n;
    int a[n];
    for(long long int i =0 ; i< n; i++){
        long long int x;
        cin>>x;
        a[i] = x;
    }
    cin >> m;
    int b[m];
    for(long long int i =0 ; i< m; i++){
        long long int x;
        cin>>x;
        b[i] = x;
    }
    cout << longCommonAnagramSubseq(a, b, n, m);
    return 0;    
}