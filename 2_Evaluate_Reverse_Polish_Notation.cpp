// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
// Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
	int sub_index, first_operand, second_operand;
	stack<int> stk;
	/* Because of the case ["18"] these codes have to be comment out 
	if (tokens.size() < 3)
	    return false;
	    */

	for (sub_index = 0; sub_index < tokens.size(); sub_index++) {
	    if (1 == tokens[sub_index].size()) {
		switch(tokens[sub_index][0]) {
		    case '+':
			first_operand = stk.top();
			stk.pop();
			second_operand = stk.top();
			stk.pop();
			stk.push(second_operand + first_operand);
			//cout<<second_operand<<"+"<<first_operand<<"="<<stk.top()<<endl;
			break;
		    case '-':
			first_operand = stk.top();
			stk.pop();
			second_operand = stk.top();
			stk.pop();
			stk.push(second_operand - first_operand);
			//cout<<second_operand<<"-"<<first_operand<<"="<<stk.top()<<endl;
			break;
		    case '*':
			first_operand = stk.top();
			stk.pop();
			second_operand = stk.top();
			stk.pop();
			stk.push(second_operand * first_operand);
			//cout<<second_operand<<"*"<<first_operand<<"="<<stk.top()<<endl;
			break;
		    case '/':
			first_operand = stk.top();
			stk.pop();
			second_operand = stk.top();
			stk.pop();
			stk.push(second_operand / first_operand);
			//cout<<second_operand<<"/"<<first_operand<<"="<<stk.top()<<endl;
			break;
		    default:
			stk.push(stoi(tokens[sub_index], nullptr));
			break;
		}
	    } else {
		stk.push(stoi(tokens[sub_index], nullptr));
	    }
	}
	return stk.top();
    }
};

int main(int argc, char *argv[])
{
    Solution *a = new Solution();
    string str_array_a[] = {"2", "1", "+", "3", "*"}; 
    string str_array_b[] = {"4", "13", "5", "/", "+"};
    string str_array_c[] = {"-1","1","*","-1","+"};
    string str_array_d[] = {"18"};
    vector<string> v_str_a(str_array_a, str_array_a + sizeof(str_array_a) / sizeof(string));
    vector<string> v_str_b(str_array_b, str_array_b + sizeof(str_array_b) / sizeof(string));
    vector<string> v_str_c(str_array_c, str_array_c + sizeof(str_array_c) / sizeof(string));
    vector<string> v_str_d(str_array_d, str_array_d + sizeof(str_array_d) / sizeof(string));

    for(auto s : v_str_a) {
	cout<<s<<",";
    }
    cout<<endl;

    cout<<"a return:"<<a->evalRPN(v_str_a)<<endl;

    for(auto s : v_str_b) {
	cout<<s<<",";
    }
    cout<<endl;

    cout<<"b return:"<<a->evalRPN(v_str_b)<<endl;

    for(auto s : v_str_c) {
	cout<<s<<",";
    }
    cout<<endl;

    cout<<"c return:"<<a->evalRPN(v_str_c)<<endl;

    for(auto s : v_str_d) {
	cout<<s<<",";
    }
    cout<<endl;

    cout<<"d return:"<<a->evalRPN(v_str_d)<<endl;

    return 0;
}
