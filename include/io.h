#ifndef __HICUTS_IO_H__
#define __HICUTS_IO_H__

#define MAXBITS 256   // one rule range 
#define MAXFIELDS 15  // one rule fields

typedef struct rule {
  char** field;
} rule;

typedef struct cons {
  int fields;
  int rules;
  int fbit[MAXFIELDS];
} cons;

void parseargs(int,char*[]);
cons scalecheck(cons,FILE*);
rule* makefield(int,int,int[],FILE*);
//void Allfree(int,int,int[],rule*);
void printall(int,int,int[],rule*);

int binth ;       // leaf threashold
float spfac ;      // space explosion factor
int opt ;          // dimension selection
FILE *fpr;            // ruleset file
FILE *fpt;            // test trace file

#endif
