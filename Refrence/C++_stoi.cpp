// Since C++11 Support
// stoi example

#include <iostream>   // cout
#include <string>     // string, stoi
using namespace std;

int main ()
{
  string str_dec = "2001, A Space Odyssey";
  string str_hex = "40c3";
  string str_bin = "-10010110001";
  string str_auto = "0x7f";

  string::size_type sz;   // alias of size_t

  int i_dec = stoi (str_dec,&sz);
  int i_hex = stoi (str_hex,nullptr,16);
  int i_bin = stoi (str_bin,nullptr,2);
  int i_auto = stoi (str_auto,nullptr,0);

  cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  cout << str_hex << ": " << i_hex << '\n';
  cout << str_bin << ": " << i_bin << '\n';
  cout << str_auto << ": " << i_auto << '\n';

  return 0;
}
