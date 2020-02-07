#include"digraph.h"
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>
#include<iostream>
#include <map>

using std::map;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
using std::ifstream;
using std::endl;
using std::cerr;

int main(int argc, char*argvp[]) {
  
  vector<string> master;
  vector<string> digraphs;
  string cmd = argvp[2];
  string a;
  int number;
   
  if (argc != 3) {
    cerr << "invalid command line arguments" << endl;
    return 1;
  }

  if (cmd != "r" && cmd != "a" && cmd != "c") {
    cerr << "invalid command line arguments" << endl;
    return 1;
  }

  
  ifstream inputfile(argvp[1]);

  if (!inputfile.is_open()) {
    cout << "could not open file" << endl;
  }

  int i;
  inputfile >> number;
  for (i = 0; i < (number); i++) {
    inputfile >> a;
    for (int i = 0; i < (int) a.length(); i++) {
      if (a[i] < 91) {
	a[i] += 32;
      }
    }
    digraphs.push_back(a);
  }

  while (inputfile >> a) {
    for (int i = 0; i < (int)a.length(); i++) {
      if (a[0] < 91) {
        a[0] += 32;
      }
    }
    char punctuation = a[a.length() - 1];
    if (punctuation == '.' || punctuation == ',' || punctuation == '!' || punctuation == '?') { //checks last char of each word for punctuation
      a.erase(a.length() - 1);
    }
    master.push_back(a);
  }
  if (cmd == "r") {
    rASCII(digraphs, master);  
  }
  if (cmd == "a") {
    ASCII(digraphs, master);
  }
  if (cmd == "c") {
    count(digraphs, master);
  }

  cout << "q?>";
  string input2;
  cin >> input2;
  while(input2 != "quit" && input2 != "Quit") {
    if(isalpha(input2[0]) != 0) { //if alphabetical
      for (int i = 0; i < (int)input2.length(); i++) {
	if (input2[i] < 91) {
	  input2[i] += 32;
	}
      }
      if (isdigraph(digraphs, input2)) {
	qDigraph(digraphs, master, input2);
      }
      else {
	cout << "No such digraph" << endl;
      }
    }
    else{
      int number = std::stoi(input2);
      qNumber(digraphs, master, number);
    }
    cout << "q?>";
    cin >> input2; 
    }
  return 0;
}
