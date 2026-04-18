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

/* filetypes */

char *C_HL_extensions[] = {".c", ".h", ".cpp", NULL};
char *py_HL_extensions[] = {".py", NULL};
char *clj_HL_extensions[] = {".clj", ".cljr", ".cljc", NULL};


char *C_HL_keywords[] = {
    "switch", "if", "while", "for", "break", "continue", "return", "else",
    "struct", "union", "typedef", "static", "enum", "class", "case",
    "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
    "void|", NULL};

char *py_HL_keywords[] = {
    "and", "as", "assert", "async", "await",
    "break", "class", "continue", "def", "del", "elif", "else", "except",
    "finally", "for", "from", "global", "if", "in", "is", "lambda", "not", 
    "or", "pass", "raise", "return", "try", "while", "with", "yield",
    "global|", "nonlocal|", "import|", "in|", "True|", "False|", "None|", 
    "print|", "int|", "float|", "str|", "list|", "dict|", "set|", "tuple|", NULL};

char *clj_HL_keywords[] = {
    "def", "defn", "defmacro", "defmethod", "defmulti", "defprotocol", 
    "defrecord", "deftype", "fn", "if", "do", "let", "loop", "recur", 
    "when", "cond", "case", "for", "doseq", "try", "catch", "finally", "throw", 
    "ns", "require", "import", "use", "refer", "and", "or", "not", "nil?", 
    "true?", "false?", "zero?", "pos?", "neg?", "println",
    "nil|", "true|", "false|", "string?|", "number?|", "seq?|", "map?|", 
    "vector?|", "set?|", NULL};

struct editorSyntax HLDB[] = {
    {"c",
     C_HL_extensions,
     C_HL_keywords,
     "//", "/*", "*/",
     HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS},
    {"python",
     py_HL_extensions,
     py_HL_keywords,
     "#", "'''", "'''",
     HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS},
    {"clojure",
     clj_HL_extensions,
     clj_HL_keywords,
     ";", "", "",
     HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS}
};

#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
