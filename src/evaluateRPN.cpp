#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <locale>
#include <stack>

using namespace std;
bool is_operator(const string &op){
	return op.size() == 1 && string("+-*/").find(op) != string::npos;
}
int evaluateRPN(vector<string> notation){
	//int currentValue = numeric_limits<int>::max();
	int currentValue = 10000;
	stack<string> buffer;
	// locale loc;
	for (int i = 0; i < notation.size(); i ++){
		cout << notation[i] << endl;
		cout << "check 1" << endl;
		cout << "current value=" << currentValue<< endl;
		if (!is_operator(notation[i])){
			cout << "check 4" << endl;
			buffer.push(notation[i]);
		}
		else{
			cout << "check 2" << endl;
			string tmp_value = buffer.top();
			// if (currentValue == numeric_limits<int>::max())
			if (currentValue == 10000){
				currentValue = atoi(tmp_value.c_str());
				buffer.pop();
				tmp_value = buffer.top();
			}
			if (notation[i] == "+")
				currentValue += atoi(tmp_value.c_str());
			else if (notation[i] == "-")
				currentValue = atoi(tmp_value.c_str()) - currentValue;
			else if (notation[i] == "*"){
				currentValue *= atoi(tmp_value.c_str());
			}
			else if (notation[i] == "/")
				currentValue = atoi(tmp_value.c_str()) / currentValue;
			buffer.pop();
		}
	}
	return currentValue;
}

int main()
{
	// string str[] = {"2", "2", "+", "3", "*"};
	string str[] = {"4", "13", "5", "/", "+"};
	vector<string> notation(str, str+5);
	/*
	vector<string> notation;
	notation.push_back("2");
	notation.push_back("2");
	notation.push_back("+");
	notation.push_back("3");
	notation.push_back("*");
	*/
	int d = evaluateRPN(notation);
	cout << "the result is " << d << endl;
	return 1;
}
