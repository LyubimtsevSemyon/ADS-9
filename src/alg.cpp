// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> MyTree;
  std::ifstream fin(filename);
  char G;
  std::string word = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return MyTree;
  }
  while (!fin.eof()) {
      G = fin.get();
      if (G >= 'A') {
          if (G <= 'Z') {
              G = G + 32;
          }
      }
      if (G >= 'a') {
          if (G <= 'z') {
              word = word + G;
          }
      } else {
          MyTree.Add(word);
          word = "";
      }
  }
  fin.close();
  return MyTree;
}
