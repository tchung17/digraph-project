#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "digraph.h"
#include <fstream>
#include <map>
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::get;
using std::ifstream;
using std::ostream;
using std::cerr;
using std::make_pair;

ostream& operator<<(ostream& out, const vector<string> &vector1){
  for(vector<string>::const_iterator it = vector1.cbegin(); it != vector1.cend(); it++){
    if (it == vector1.cend() - 1) {
      out << *it;
    } else{
    out<< *it << ", ";
    }
  }
  return out;
}

void qNumber(vector<string> digraphs, vector<string> master, int number){ //query is a number
   map<string, vector<string>> rawmap = mapcreator(digraphs, master);
   bool present = false;
   for (map<string, vector<string>>::iterator it = rawmap.begin(); it!= rawmap.end(); it++) {
     if ((int) it->second.size() == (int) number) {
       present = true;
       cout << it->first << endl;
       vector<string> temp = it->second;
       for(int i = 0; i < (int)temp.size(); i++) {
	 cout << temp[i] << endl;
       }
     }
   }
   if (!present) {
     cout << "None" << endl;
   }
}

void qDigraph(vector<string> digraphs, vector<string> master, string query){ //query is a digraph
  map<string, vector<string>> rawmap = mapcreator(digraphs, master);
  bool present = false;
  for (map<string, vector<string>>::iterator it = rawmap.begin(); it!= rawmap.end(); it++) {
    if (it->first.compare(query) == 0) { //if match
      present = true;
      cout << it->second.size() << endl;
      vector<string> temp = it->second;
      for (int i = 0; i < (int) temp.size(); i++) {
	cout << temp[i] << endl;
      }
    }
  }
  if (!present) {
    cout << "No such digraph" << endl;
  }
}

int islargest(map<string, int> sizemap) {
  int largest = 0;
  for(map<string, int>::iterator it = sizemap.begin(); it != sizemap.end(); it++) {
    if (it -> second > largest) {
      largest = it->second;
    }
  }
  return largest;
}
map<string, int> countcreator(vector<string> digraphs, vector<string> master) {
  map<string, vector<string>> rawmap = mapcreator(digraphs, master);
  map<string, int> sizemap;
  for(map<string, vector<string>>::iterator it = rawmap.begin(); it != rawmap.end(); it++) {
    sizemap[it->first] = it->second.size();
  }
  return sizemap;
}
void count(vector<string> digraphs, vector<string> master){
  map<string, vector<string>> rawmap = mapcreator(digraphs, master);
  map<string, int> sizemap = countcreator(digraphs, master);
  int largest = islargest(sizemap);
  for(map<string, int>::iterator it = sizemap.begin(), end = sizemap.end(); it != end;) {
    if (it->second == largest){
      cout<< it->first << ": [" << rawmap[it->first] << "]" <<endl;
      sizemap.erase(it);
      largest = islargest(sizemap);
      it = sizemap.begin();
      end = sizemap.end();
    }
    else{
      it++;
    }
  }
}

map<string, vector<string>> mapcreator(vector<string> digraphs, vector<string> master) { //raw order map
  map<string, vector<string>> bigMap;
  for (int i = 0; i < (int)digraphs.size(); i++) {
    vector<string> thewords; //temp vector to store digraph matches
    string digraph = digraphs[i]; //current digraph
    for (int j = 0; j < (int)master.size(); j++) {
      string word = master[j];
      if (word.find(digraph) != std::string::npos) {
	thewords.push_back(word);
      }
    }
    bigMap.insert({digraph, thewords});
  }
  return bigMap;
}

void ASCII(vector<string> digraphs, vector<string> master) {
  map<string, vector<string>> rawmap = mapcreator(digraphs, master);
  for (map<string, vector<string>>::iterator it = rawmap.begin(); it!= rawmap.end(); it++){
    cout << it->first << ": [" << it->second << "]" << endl;
    }
}

void rASCII(vector<string> digraphs, vector<string> master) {
  map<string, vector<string>> rawmap = mapcreator(digraphs, master);
  for (map<string, vector<string>>::reverse_iterator itr = rawmap.rbegin(); itr!= rawmap.rend(); itr++){
    cout << itr->first << ": [" << itr->second << "]" << endl;
  }
}

bool isdigraph (vector<string> digraphs, string query) {
  for (int i = 0; i < (int)digraphs.size(); i++) {
    if (digraphs[i].compare(query) == 0) {
      return true;
    }
  }
  return false;
}






