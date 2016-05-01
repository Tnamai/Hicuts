#include "hicuts.h"

void parseargs(int argc, char *argv[]) {
  int	c;
  bool ok = 1;
  while ((c = getopt(argc, argv, "b:s:o:r:t:h")) != -1) {
    switch (c) {
    case 'b':
      binth = atoi(optarg);  //int?
      break;
    case 's':
      spfac = atof(optarg);  //float?
      break;
    case 'o':
      opt = atoi(optarg);
      break;
    case 'r':
      fpr = fopen(optarg, "r");
      break;
    case 't':
      fpt = fopen(optarg, "r");
      break;
    case 'h':
      printf("hicut [-b binth][-s spfac][-o opt][-r ruleset][-t trace]\n");
      printf("mail me: 46490141029\n");
      exit(1);
      break;
    default:
      ok = 0;
    }
  }
  if(binth <= 0 || binth > 300){
    printf("binth should be greater than 0 and less than %d\n", 300);
    ok = 0;
  }	
  if(spfac < 1.0){
    printf("space factor should be >= 1\n");
    ok = 0;
  }	
  if(opt < 0 || opt > 3){
    printf("option shoudl be between 0 and 3\n");
    ok = 0;	
  }
  if(fpr == NULL){
    printf("can't open ruleset file\n");
    ok = 0;
  }
  /*
  if(fpt == NULL){
    printf("can't open traceset file\n");
    ok = 0;
  }
  */
  if (!ok || optind < argc) {
    fprintf (stderr, "hicuts [-b binth][-s spfac][-o opt][-r ruleset][-t trace]\n");
    fprintf (stderr, "Type \"hicuts -h\" for help\n");
    exit(1);
  }
  /*
  printf("Bucket Size =  %d\n", binth);
  printf("Space Factor = %f\n", spfac);
  printf("Option = %d\n", opt);
  */
}



int main(int argc, char *argv[])
{
  FILE *fprcp; 
  char readline[MAXBITS] = {'\0'};
  char firstline[MAXBITS] = {'\0'};
  int i=0,
    fields=1,
    rules=0,
    fbit[MAXFIELDS]={'\0'};
  
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
  fclose(fpr);
  /*  fclose(fpt);*/


  /*
  rule a;
  char *s = "hoge";
  a.field = &(s);
  printf("%s\n", *(a.field));
  */
  return 0;

}


