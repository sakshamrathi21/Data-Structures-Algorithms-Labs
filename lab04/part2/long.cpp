#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char **argv) {

  if( argc < 2 ) {
    cout<<"Give a sequence of paranthesses!\n"
        <<endl;
    return 1;
  }
  auto s = string(argv[1]);
  int matched_length = 0;
  vector<int> mat_lengths;
  vector<char> check_test;
  for ( int i = 0; i<s.size(); i++) {
    if (s[i] == '(') {
      check_test.push_back(s[i]);
    }
    else{
      if(check_test.empty()) {
        mat_lengths.push_back(matched_length);
        matched_length = 0;
      }
      else {
        check_test.pop_back();
        matched_length += 2;
      }
    }
  }
  for ( int j = 0; j < mat_lengths.size(); j++) {
    matched_length = max(matched_length, mat_lengths[j]);
  }
  cout << s << " " << matched_length <<  endl;
}
