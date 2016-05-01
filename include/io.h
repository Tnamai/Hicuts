#ifndef __HICUTS_IO_H__
#define __HICUTS_IO_H__

typedef struct rule {
  char** field;
} rule;

int binth = 16;      // leaf threashold
float spfac = 2;     // space explosion factor
int opt = 3;         // dimension selection
FILE *fpr;           // ruleset file
FILE *fpt;           // test trace file
#define MAXBITS 256
#define MAXFIELDS 15
#endif
