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

char makefield(int r,int f,int fb[]){
  rule R[r+1];
  int w;
  int i,j,k;
  for(i=1;i<r+1;i++){
    R[i].field=(char**)malloc(f+1);
    for(j=0;j<f;j++){
      R[i].field[j]=(char*)malloc(fb[j]+1);
      for(k=0;k<fb[j];k++){
	w = fgetc(fpr);
	//R[i].field[j][k] = &(w);
	printf("%d\n",w);
      }
      fgetc(fpr);
    }
  }
  return *R;
}
void Allfree(int r,int f,int fb[],rule R[]){
  int i,j,k;
  for(i=1;i<r+1;i++){
    for(j=0;j<f;j++){
      for(k=0;k<fb[j];k++){
	free(R[i].field[j][k]);
      }
      free(R[i].field[j]);
    }
  }
}
