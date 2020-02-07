#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <vector>
#include <string>
#include <map>

std::map<std::string, std::vector<std::string>> mapcreator(std::vector<std::string> digraphs, std::vector<std::string> master);

int islargest(std::map<std::string , int> sizemap);

void qNumber(std::vector<std::string> digraphs, std::vector<std::string> master, int number);

void qDigraph(std::vector<std::string> digraphs, std::vector<std::string> master, std::string query);

std::map<std::string, int> countcreator(std::vector<std::string> digraphs, std::vector<std::string> master);

void count(std::vector<std::string> digraphs, std::vector<std::string> master);

void ASCII(std::vector<std::string> digraphs, std::vector<std::string> master);

void rASCII(std::vector<std::string> digraphs, std::vector<std::string> master);

bool isdigraph (std::vector<std::string> digraphs, std::string query);

#endif
