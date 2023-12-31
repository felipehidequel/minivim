#include "minivim.hpp"

Minivim::Minivim(const std::string &file) {

  lines.push_back("");
  x = y = 0;
  mode = 'n';
  status = "NORMAL";

  if (file.empty()) {
    filename = "untitled";
  } else {
    filename = file;
  }

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);
}

Minivim::~Minivim() {
  refresh();
  endwin();
}

void Minivim::run() {
  while (mode != 'q') {
    update();
    statusline();
    mode = getch();
  }
}

void Minivim::update() {
  switch (mode) {
  case 27:
  case 'n':
    status = "NORMAL";
    break;
  case 'i':
    status = "INSERT";
    break;
  case 'q':
    break;
  }
}

void Minivim::statusline() {
  attron(A_REVERSE);
  mvprintw(LINES - 1, 0, status.c_str());
  attroff(A_REVERSE);
}