//
// Created by mrbgn on 15.12.2020.
//

#include "Explorer.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  std::string path = ".";
  if (argc == 0) {
    //pathToLookupDirectory = argv[1];
    std::cout << path << std::endl;
  }

  if (argc == 1) {
    path = argv[1];
    std::cout << path << std::endl;
  }

}