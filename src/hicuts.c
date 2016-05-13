#include "hicuts.h"

int main(int argc, char *argv[])
{
  rule *R,*T;  //RはRule TはTrace
  cons r,t;
  
  parseargs(argc, argv); //オプション引数から読み込み
  
  r = scalecheck(r,fpr); //ルール数、次元数、各次元の範囲を探索
  t = scalecheck(t,fpt);

  //fprintf( stderr, "Check\n" ); //バグチェック

  R = makefield(r.rules,r.fields,r.fbit,fpr);//ピッタリの領域確保＆代入
  T = makefield(t.rules,t.fields,t.fbit,fpt);

  printall(r.rules,r.fields,r.fbit,R);//ファイルと同じ形で出力
  printf("-------------------------------\n");
  printall(t.rules,t.fields,t.fbit,T);

  /* メモリ開放 */
  free(R);
  free(T);
  /* ファイルのクローズ */
  fclose(fpr);
  fclose(fpt);
 
  return 0;
}
