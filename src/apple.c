#include <stdio.h>

int n;
int k;
int A[100000];

int isMidEnough(int i_capacity){
  int requiredBag = 0;

  for(int i=0; i < n; i++){
    printf("%d ", A[i]);
    if(A[i]%A[i_capacity] == 0){
      requiredBag += A[i]/A[i_capacity];
    }else{
      requiredBag += A[i]/A[i_capacity] + 1;
    }
  }
  
  return requiredBag <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1;
  ub = n-1;

  while(ub - lb > 1){
        
    int mid = (ub + lb) / 2;

    if(isMidEnough(mid)){
       ub = mid;
    }else{
      lb = mid;
    }

  }

  printf("%d\n", A[ub]);



  return 0;
}
