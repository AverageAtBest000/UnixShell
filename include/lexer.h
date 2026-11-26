#pragma once
#include "ds_string.h"
struct ds_string;

// Token types
typedef enum { WORD_TOK, PIPE_TOK, AND_TOK, OR_TOK, SEMI_TOK } TOK_TYPE;
typedef struct {
  char **data;
  int size;
  int capacity;
  TOK_TYPE *type;
} TOK_ARRAY;
// COMMAND struct
typedef struct {
  char **argv; // argv for execution
  int argc;
} COMMAND;

// PIPE struct
typedef struct {
  COMMAND *commands; //  Array of commands for execution
  int argc;
} PIPE;

// ANDOR struct
typedef struct {
  PIPE *pipes; // array of pipes
  TOK_TYPE **operators;
  int argc;
} ANDOR;

typedef struct {
  ANDOR *chains;
  int n;
} LIST;

int lex(int *argc, char ***argv, ds_string *cmd, char delim);
