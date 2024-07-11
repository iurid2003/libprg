#include <stdio.h>
#include <stdlib.h>


int mult_ite(int m , int n){
    if(n == 0 ){
        return 0 ;
    }
    return (m + mult_ite(m,n-1));
}

int n_fatorial(int n){
    if(n == 1){
        return 1 ;
    }
    return n * n_fatorial(n - 1);
}

int fibonnaci(int n){
  if(n == 1 ){
      return 0 ;
  }else {
      if (n == 2) {
          return 1;
      } else
          return fibonnaci(n-2) + fibonnaci(n-1);
  }
  }




int main(void){

  int fa = mult_ite(5,3);
  printf("%d\n", fa);
    for (int i = 0; i < ; ++i) {
        
    }
  printf("%d\n", fibonnaci(4));

  printf("%d\n", n_fatorial(4));
    return 0 ;
}