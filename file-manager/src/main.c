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


typedef struct _win_boreder_struct {
    chtype ls, rs, ts, bs, tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {

    int start_x, start_y;
    int height, width;
    WIN_BORDER border;
} WIN;


void init_win_params(WIN *p_win, const char *dir_name);
void print_win_params(WIN *p_win);
void create_box(WIN *p_win, bool flag);


int main() {

    WIN window;
    int ch;

    int cur_x, cur_y;
    cur_x = cur_y = 0;

    initscr();
    start_color();
    cbreak();

    keypad(stdscr, TRUE);
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    printw("Press F1 to exit");
    refresh();
    attroff(COLOR_PAIR(1));

    // initialize win parameters
    init_win_params(&window, ".");
    print_win_params(&window);

//    create_box(&window, TRUE);

    move(cur_y, cur_x);

    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case KEY_UP:
                if (cur_y > 0) {
                    cur_y--;
                }
                break;

            case KEY_DOWN:
                if (cur_y < LINES) {
                    cur_y++;
                }
                break;

            case KEY_LEFT:
                if (cur_x > 0) {
                    cur_x--;
                }
                break;

            case KEY_RIGHT:
                if (cur_x < COLS / 2) {
                    cur_x++;
                }
                break;

            default:
                cur_y = 0;
                cur_x = 0;
        }

        move(cur_y, cur_x);
        refresh();
    }

    endwin();

    return 0;
}


void init_win_params(WIN *p_win, const char *dir_name) {

    p_win->height = LINES;
    p_win->width = COLS / 2;
    p_win->start_x = 0;
    p_win->start_y = 0;
    p_win->border.rs = '|';

    printw("\n");

    DIR *d;
    struct dirent *dir;
    d = opendir(dir_name);

    while ((dir = readdir(d)) != NULL) {
        printw("%s\n", dir->d_name);
    }

    closedir(d);
}

void print_win_params(WIN *p_win) {
#ifdef _DEBUG
    mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty, p_win->width, p_win->height);
    refresh();
#endif
}

void create_box(WIN *p_win, bool flag) {

    int i, j;
    int x, y, w, h;

    x = p_win->start_x;
    y = p_win->start_y;
    w = p_win->width;
    h = p_win->height;

    if (flag == TRUE) {
//        mvaddch(y, x, p_win->border.tl);
//        mvaddch(y, x + w, p_win->border.tr);
//        mvaddch(y + h, x, p_win->border.bl);
//        mvaddch(y + h, x + w, p_win->border.br);
//        mvhline(y, x + 1, p_win->border.ts, w - 1);
//        mvhline(y + h, x + 1, p_win->border.bs, w - 1);
//        mvvline(y + 1, x, p_win->border.ls, h - 1);
//        mvvline(y + 1, x + w, p_win->border.rs, h - 1);

    } else {
        for (j = y; j <= y + h; ++j) {
            for (i = x; i <= x + w; ++i) {
                mvaddch(j, i, ' ');
            }
        }
    }

    refresh();
}


