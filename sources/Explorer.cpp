//
// Created by mrbgn on 15.12.2020.
//

#include "Explorer.hpp"

Explorer::Explorer(std::string &dirPath)
{
  try {
    _path = path(dirPath);
    _dirIterator = directory_iterator(_path);
  } catch (...) {
    _path = path(".");
    _dirIterator = directory_iterator(_path);

  }
}

Explorer::~Explorer()
{
  for (account& acc : _trader)
  {
    acc.balance.clear();
  }
  _trader.clear();
}

void Explorer::AccPush(const account& tempAcc)
{
  _trader.push_back(tempAcc);
}

void Explorer::PathAnalyze(const directory_entry& dirEntry)
{
  if (is_regular_file(dirEntry)) FileAnalyze(dirEntry.path());
}

bool Explorer::isNumber(const std::string& fileNamePart)
{
  const std::string number = "012345678";
  std::size_t found;
  for (const auto part : fileNamePart) {
    found = number.find(part);
    if (found == std::string::npos) return false;
  }
  return true;
}



bool Explorer::NameAnalyze(const path& filePath) {
  const std::string balance = "balance";
  const std::string trueFileExt = ".txt";
  const std::string falseFileExt = "old";
  const std::string sep = "_";
  const uint32_t trueFileLength = 25;
  const uint32_t secSepStart = 16;
  const uint32_t firstNumberStart = 8;
  const uint32_t secNumberStart = 17;
  const uint32_t numberLength = 8;
  const uint32_t balanceLength = balance.length();
  const std::string fileName = filePath.stem().string();
  const std::string fileExt = filePath.extension().string();

  std::size_t found;

  if (fileExt == trueFileExt) {
    found = fileName.find(falseFileExt);
    if (found == std::string::npos) {
      if (fileName.length() == trueFileLength) {
        found = fileName.find(balance);
        if (found != std::string::npos) {
          if (found == 0) {
            if (fileName.substr(balanceLength, 1) == sep &&
                fileName.substr(secSepStart, 1) == sep) {
              if (isNumber(fileName.substr(firstNumberStart, numberLength)) &&
                  isNumber(fileName.substr(secNumberStart, numberLength))) {
                return true;
              } else
                return false;
            } else
              return false;
          } else
            return false;
        } else
          return false;
      } else
        return false;
    } else
      return false;
  } else
    return false;
}

void Explorer::FileAnalyze(const path& filePath)
{
  if (NameAnalyze(filePath)) std::cout << filePath.filename() << std::endl;
}

void Explorer::Analyze()
{
  account tempAcc;
  tempAcc.balance.clear();

  for (const auto& x : _dirIterator)
  {
    PathAnalyze(x);
  }
}

