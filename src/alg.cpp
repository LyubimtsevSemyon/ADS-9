// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  if (!file.is_open()) {
    throw std::string("Error! File did not open!");
  }
  while (!file.eof()) {
    word = "";
    while (true) {
      char pod = file.get();
      if ((pod >= 65 && pod <= 90) || (pod >= 97 && pod <= 122)) {
        word += tolower(pod);
      } else {
        break;
      }
    }
    bst.Add(word);
  }
  return bst;
}
