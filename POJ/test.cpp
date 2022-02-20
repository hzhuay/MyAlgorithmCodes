#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#define BUF_SIZE 100000
using namespace std;
bool if_valid_char(char ch){return 32 <= ch && ch <= 127;}
bool if_hex_char(char ch){return ('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F');}
bool if_tag_char(char ch){return ('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z');}
char buf[BUF_SIZE];
int length;
bool valid;
stack<string>tags;
int main(){
	while (cin.getline(buf, BUF_SIZE)){
		length = strlen(buf);
		valid = true;
		int i = 0;
		while (i < length) {
			if (buf[i] == '&') {
				i++;
				if (buf[i] == 'l' && buf[i + 1] == 't' && buf[i + 2] == ';') i += 3;
				else if (buf[i] == 'g' && buf[i + 1] == 't' && buf[i + 2] == ';') i += 3;
				else if (buf[i] == 'a' && buf[i + 1] == 'm' && buf[i + 2] == 'p' && buf[i + 3] == ';') i += 4;
				else if (buf[i] == 'x') {
					i++;
					if (!if_hex_char(buf[i]) || !if_hex_char(buf[i + 1])) {valid=false;break;}
					i += 2;
					while (true) {
						if (buf[i] == ';')break;
						else if (if_hex_char(buf[i]) && if_hex_char(buf[i + 1])) {
							i += 2;
						}else {valid = false;break;}
					}
					if (!valid) break;
				}else {valid = false;break;}
			} 
			else if (buf[i] == '>') {valid = false;break;} 
			else if (buf[i] == '<') {
				i++;
				if (buf[i] == '/') {
					i++;
					if (buf[i] == '>')i++;
					else {
						if (tags.empty()) {valid = false;break;}
						string temp = tags.top();
						tags.pop();
						int t_length = temp.length();
						for (int j = 0; j < t_length; j++) {
							if (temp[j] != buf[i++]) {valid = false;break;}
						}
						if (buf[i++] != '>')valid = false;
						if (!valid)break;
					}
				}else {
					int pos = i;
					while (true) {
						if (buf[i] == '/') {
							i++;
							if (buf[i] == '>') {i++;break;}
							else {valid = false;break;}
						} else if (buf[i] == '>') {
							tags.push(string(buf + pos, buf + i));
							i++;
							break;
						} else if (if_tag_char(buf[i]))i++;
						 else {valid = false;break;}
					}
					if (!valid) break;
				}
			} else if (if_valid_char(buf[i]))i++;
				else {valid = false;break;}
		}
		if (!tags.empty())valid=false;
		if (valid)cout<<"valid"<<endl;
		else cout<<"invalid"<<endl;
		while(!tags.empty())tags.pop();
	}
	return 0;
}
