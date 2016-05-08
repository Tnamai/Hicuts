#ifndef __HICUTS_IO_H__
#define __HICUTS_IO_H__

typedef struct rule {
  char** field;
} rule;

void parseargs(int,char*[]);
char makefield(int,int,int[]);
void Allfree(int,int,int[],rule[]);

int binth ;       // leaf threashold
float spfac ;      // space explosion factor
int opt ;          // dimension selection
FILE *fpr;            // ruleset file
FILE *fpt;            // test trace file

#define MAXBITS 256   // one rule range 
#define MAXFIELDS 15  // one rule fields
#endif
