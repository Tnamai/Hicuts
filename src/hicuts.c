#include "hicuts.h"

int main(int argc, char *argv[])
{
  
  FILE *fprcp; 
  char readline[MAXBITS] = {'\0'};
  char firstline[MAXBITS] = {'\0'};
  int i=0,
    fields=1,
    rules=0,
    fbit[MAXFIELDS]={'\0'};
  char *R;
  
  parseargs(argc, argv);
  
  fprcp = fpr;

  while ( fgets(readline, MAXBITS, fprcp) != NULL ) {
    if(rules==0)
      strcpy(firstline,readline);
    rules++;
  }
  printf("%drules ",rules);
  
  while(firstline[i] !='\0'){
    // printf("%c",firstline[i]); 確認用
    if(firstline[i] == ' '){
      fields++;
	}
    else
      fbit[fields-1]++;
    i++;
  }
  fbit[fields-1]--; //何故か最後のフィールドbits数を多く数えてしまう。要改善？
  
  printf("%dfields\n",fields);
  printf("fieldrange ");
  for(i=0;i<fields-1;i++)
    printf("%d,",fbit[i]);
  printf("%d bits\n",fbit[i]);

  /* ファイルのクローズ */
  //fprintf( stderr, "Check\n" );
  /*  fclose(fpt);*/
  
  R = makefield(rules,fields,fbit);
  // printf("%c\n",*(R[1].field[1][2]));
  Allfree(R);
  fclose(fpr);
  rule a;
  char *s = "hoge";
  a.field = &(s);
  printf("%s\n", *(a.field));
 
  return 0;
}
