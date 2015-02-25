#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
int my_strlen(string str){
	int len = 0;
	while(str[len]!='\0'){
		len++;
	}
	return len;
}
int main(){
	string test_str="my test!";
	int len = my_strlen(test_str);
	cout << "the length is " << len << endl;
	return 1;
}
