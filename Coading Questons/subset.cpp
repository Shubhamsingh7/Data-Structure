#include<iostream>
using namespace std;



void subset(string s,string arr[]){
    arr[0] = "";
    int length = 1;
    int temp = length;
    string str = " ";
    for(int i = 0 ; i < s.length() ; i++){
        for(int j = 0 ; j < temp ; j++){
            str = arr[j] + s[i];
            length = length + 1;
            arr[length-1] = str;
        }
    temp = length;
    }
}

int main(){
    string s = "abc";
    int size = 1 << s.length();
    string arr[size];
    subset(s,arr);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}