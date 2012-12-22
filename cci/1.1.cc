#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>
#include <unordered_map>

using namespace std;

// 1.1 Implement an algorithm to determine if a string has all unique
// characters.  What if you cannot use additional data structures?

bool all_unique(string& str) {
  unordered_map<char,int> char_map;
  string::iterator i;
  for (i = str.begin(); i < str.end(); i++) {
    char_map[*i] += 1;
    if (char_map[*i] > 1) return false;
  }
  return true;
}

bool all_unique2(string& str) {
  string::iterator i, j;
  for (i = str.begin(); i < (str.end() - 1); i++)
    for (j = i + 1; j < str.end(); j++)
      if (*i == *j) return false;
  return true;
}

bool all_unique3(string& str_) {
  int char_map[256] = { 0 };
  const char *str = str_.c_str();
  for (int i = 0; i < strlen(str); i++) {
    char c = *(str + i);
    char_map[c] += 1;
    if (char_map[c] > 1) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  string s1("a uniq-str");
  string s2("another");
  string empty("");
  string sc = s1 + s2 + empty;

  assert(all_unique(s1));
  assert(all_unique(s2));
  assert(all_unique(empty));
  assert(!all_unique(sc));

  assert(all_unique2(s1));
  assert(all_unique2(s2));
  assert(all_unique2(empty));
  assert(!all_unique2(sc));

  assert(all_unique3(s1));
  assert(all_unique3(s2));
  assert(all_unique3(empty));
  assert(!all_unique3(sc));

  return 0;
}
