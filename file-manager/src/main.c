#include <dirent.h>
#include <limits.h>
#include <ncurses.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

DIR *dir;
WINDOW *main_win, *path_win, *file_info_win;

void init_windows() {
    main_win = newwin(LINES, COLS / 2, 0, 0);
    refresh();
    path_win = newwin(LINES / 4, COLS / 2, LINES - LINES / 4, 0);
    refresh();
    file_info_win = newwin(LINES, COLS / 2, 0, COLS / 2);
    refresh();
}

void update_windows() {
    box(main_win, '|', '-');
    box(path_win, '|', '-');
    box(file_info_win, '|', '-');
    wrefresh(main_win);
    wrefresh(path_win);
    wrefresh(file_info_win);
    keypad(main_win, TRUE);
}

void init() {
    initscr();
    start_color();
    cbreak();

    keypad(stdscr, TRUE);
    noecho();

    init_windows();
    update_windows();

    move(1, 1);
    printw("Directory: %s", "####dir####");
    move(2, 1);
}

int main() {

    init();

    int ch;

    while ((ch = getch()) != KEY_F(1)) {
        printf("%d\n", ch);
    }

    endwin();

    return 0;
}







