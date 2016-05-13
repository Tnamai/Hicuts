#include "base.h"
#include "io.h"

void parseargs(int argc, char *argv[]) {
  binth = 16;  //
  spfac = 4;   //この３つは仮の初期値
  opt = 1;     //
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

cons scalecheck(cons p,FILE *fp){
  int i;
  char readline[MAXBITS] = {'\0'};
  char firstline[MAXBITS] = {'\0'};
  //p.fbit[MAXFIELDS];
  p.rules=0;
  p.fields=1;
  for(i=0;i<MAXFIELDS;i++)  //宣言時に初期化できないからしぶしぶ
    p.fbit[i] = 0;
  i=0;
  rewind(fp);
  while ( fgets(readline, MAXBITS, fp) != NULL ) {
    if(p.rules==0)
      strcpy(firstline,readline);
    p.rules++;
  }
  printf("%drules ",p.rules);

  while(firstline[i] !='\n'){
    //printf("%c",firstline[i]);//確認用
    if(firstline[i] == ' ')
      p.fields++;
    else
      p.fbit[p.fields-1]++;
    i++;
  }
  
  printf("%dfields\n",p.fields);
  printf("fieldrange ");
  for(i=0;i<p.fields-1;i++)
    printf("%d,",p.fbit[i]);
  printf("%d bits\n",p.fbit[i]);
  return  p;
}
rule* makefield(int r,int f,int fb[],FILE *fp){
  rule *R = (rule*)malloc((r)*sizeof(rule));
  char w;
  int i,j,k;
  rewind(fp);
  for(i=0;i<r;i++){
    R[i].field=(char**)malloc(f*sizeof(char*));
    for(j=0;j<f;j++){
      R[i].field[j]=(char*)malloc(fb[j]*sizeof(char));
      for(k=0;k<fb[j];k++){
	do{
	  w = fgetc(fp);
	  if(w != 32 && w != 10){
	    R[i].field[j][k] = w;
	    //printf("%d,%d,%d,%d,%c\n",i,j,k,w,R[i].field[j][k]);　//確認用
	    break;
	  }
	}while(w == 32 || w == 10);
      }
    }
  }
  return R;
}
void printall(int rules,int fields,int fbit[] ,rule* P)
{
  int i,j,k;
  for(i=0;i<rules;i++){
    for(j=0;j<fields;j++){
      for(k=0;k<fbit[j];k++){
	printf("%c",P[i].field[j][k]);
      }
      printf(" ");
    }
    printf("\n");
  }
}




/*
void Allfree(int r,int f,int fb[],rule *R){
  int i,j,k;
  for(i=0;i<r;i++){
    for(j=0;j<f;j++){
      free(R[i].field[j]);
    }
    free(R[i].field);
  }
  free(R);
}
*/
