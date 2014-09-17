// Given an input string, reverse the string word by word.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int cnt, sub_len = 0;
		string rep_str("");

		for (cnt = s.size(); cnt >= 0; cnt--) {
			if (('\0' == s[cnt - 1]) || (' ' == s[cnt - 1]) || 0 == cnt) {
				if (0 != sub_len) {
					if (rep_str.empty())
						rep_str = rep_str + s.substr(cnt, sub_len);
					else
						rep_str = rep_str + ' ' + s.substr(cnt, sub_len);
				}
				sub_len = 0;
			} else {
				sub_len++;
			}
		}
		s = rep_str;
	}
};

int main(int argc, char *argv[])
{
	Solution *a = new Solution();
	string p_str("the sky is blue");
	a->reverseWords(p_str);

	cout<<"return: "<<p_str<<endl;

	return 0;
}
