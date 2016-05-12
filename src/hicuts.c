#include "hicuts.h"

int main(int argc, char *argv[])
{
  //FILE *fpr1,*fpt1;
  char readline[MAXBITS] = {'\0'};
  char firstline[MAXBITS] = {'\0'};
  int i=0,
    fields=1,
    rules=0,
    fbit[MAXFIELDS]={'\0'};
  rule *R;
  //fpr1 = fpr; //何故か使えない
  //fpt1 = fpt; 
  parseargs(argc, argv);
  
   while ( fgets(readline, MAXBITS, fpr) != NULL ) {
    if(rules==0)
      strcpy(firstline,readline);
    rules++;
  }
  printf("%drules ",rules);
  
  while(firstline[i] !='\n'){
    // printf("%c",firstline[i]); 確認用
    if(firstline[i] == ' ')
      fields++;
    else
      fbit[fields-1]++;
    i++;
  }
  
  
  printf("%dfields\n",fields);
  printf("fieldrange ");
  for(i=0;i<fields-1;i++)
    printf("%d,",fbit[i]);
  printf("%d bits\n",fbit[i]);

  /* ファイルのクローズ */
  //fprintf( stderr, "Check\n" );
  /*  fclose(fpt);*/
 
  R = makefield(rules,fields,fbit,fpr);
  

  // printf("%c\n",*(R[1].field[1][2]));
  // Allfree(rules,fields,fbit,R);

  printall(rules,fields,fbit,R);
   
  free(R);

  fclose(fpr);
  rule a;
  char *s = "hoge";
  a.field = &(s);
  printf("%s\n", *(a.field));
 
  return 0;
}
