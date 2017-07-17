#include<iostream>

using namespace std;

void nextPermutation(string s)
{
	//first find the last up ranging
	int up = 0;
	for (int i = s.size() - 1; i > 0; --i) {
		if (s[i] > s[i - 1])
			up = i - 1;
	}
	//then find the last number greater then s[up]
	for (int i = s.size()) - 1; i > up; --i){
	if (s[i] > s[up]) {
		char c = s[i];
		s[i] = s[up];
		s[up] = c;
		for (int i = up + 1; i <= (up + s.size()) / 2; ++i) {
			char c = s[i];
			s[i] = s[up + s.size() - i];
			s[up + s.size() - i] = c;
		}
		}
	}
}
string getPermutation(int n, int k)
{
	string s;
	for (int i = 0; i < n; ++i) s += (i + 1) + '0';
	for (int i = 0; i < k; ++i) {
		nextPermutation(s);
	}
	return s;
}
int main()
{
	int n = 3;
	int k = 0;
	cout << getPermutation(n, k);
}