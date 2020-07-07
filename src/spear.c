#include <stdio.h>

int n;
int k;
int A[100000];

int isKEnoughLong(int thisLong){
  
  int spearSum = 0;
  for(int i=0; i<n; i++) spearSum += A[i] / thisLong;

  return spearSum < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = A[n-1];

  while(ub - lb > 1){
    
    int mid = (ub + lb) / 2;
    if(isKEnoughLong(mid)){
      ub = mid;
    }else{
      lb = mid;
    }

  }

  printf("%d\n", lb);

  return 0;
}
