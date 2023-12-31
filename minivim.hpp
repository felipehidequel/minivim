#pragma once
#pragma clang diagnostic ignored "-Wformat-security"

#include <memory>
#include <ncurses.h>
#include <string>
#include <vector>

class Minivim {

  int x, y;
  char mode;
  std::string filename, status;
  std::vector<std::string> lines;

public:
  Minivim(const std::string &);
  ~Minivim();
  void run();

protected:
  void update();
  void statusline();
};
