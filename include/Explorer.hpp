//
// Created by mrbgn on 15.12.2020.
//

#ifndef TEMPLATE_EXPLORER_HPP
#define TEMPLATE_EXPLORER_HPP
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <iostream>

struct account{
  std::vector<std::string> balance;
  uint32_t file_count;
  std::string acc_id;
  std::string last_date;
};

class Explorer
{
 public:
  Explorer();
  ~Explorer();
 private:
  std::vector<struct account> _trader;
};

#endif  // TEMPLATE_EXPLORER_HPP
