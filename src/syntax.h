#ifndef SYNTAX_H
#define SYNTAX_H

#include <termios.h>
#include <time.h>

#define black 30
#define red 31
#define green 32
#define yellow 33
#define blue 34
#define purple 35
#define cyan 36
#define white 37
#define grey 90
#define l_red 91
#define l_green 92
#define l_yellow 93
#define l_blue 94
#define l_pink 95
#define l_cyan 96
#define l_white 97

#define CTRL_KEY(k) ((k) & 0x1f)

enum editorKey
{
    BACKSPACE = 127,
    ESC = 27,
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    DEL_KEY,
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN,
    CTRL_ARROW_LEFT,
    CTRL_ARROW_RIGHT,
    CTRL_DEL
};

enum editorHighlight
{
    HL_NORMAL = 0,
    HL_STRING,
    HL_NUMBER,
    HL_MATCH,
    HL_COMMENT,
    HL_MLCOMMENT,
    HL_KEYWORD1,
    HL_KEYWORD2
};

#define HL_HIGHLIGHT_NUMBERS (1 << 0)
#define HL_HIGHLIGHT_STRINGS (1 << 1)

struct editorSyntax
{
    char *filetype;
    char **filematch;
    char **keywords;
    char *singleline_comment_start;
    char *multiline_comment_start;
    char *multiline_comment_end;
    int flags;
};

typedef struct erow
{
    int idx, size, rsize, hl_open_comment;
    char *chars, *render;
    unsigned char *hl;
} erow;

struct editorConfig
{
    int cx, cy;
    int rx;
    int rowoff, coloff;
    int screenrows, screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};

/* Global editor instance - defined in syntax.c */
extern struct editorConfig E;

/* Syntax highlighting database - defined in syntax.c */
extern struct editorSyntax HLDB[];
extern unsigned int HLDB_ENTRIES;

/* Function declarations */
int is_separator(int c);
void editorUpdateSyntax(erow *row);
int editorSyntaxToColour(int hl);
void editorSelectSyntaxHighlight();

#endif
