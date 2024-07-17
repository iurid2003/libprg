//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//typedef struct {
//    int num ;
//}dado;
//
//typedef struct no {
//     dado d ;
//    struct no *proximo ;
//}No_p;
//
//dado d(){
//    dado dado1 ;
//    printf("Entre com um numero : ");
//    scanf("%d",&dado1.num);
//    return dado1 ;
//
//}
//
//void imprimir_dado_p(dado dado1){
//    printf("%d\n",dado1.num);
//}
//
//void imprimir_pilha(No_p * topo){
//    printf("%\n---------Pilha------\n");
//    while (topo){
//        imprimir_dado_p(topo->d);
//        topo = topo->proximo ;
//    }
//    printf("----------fim da Pilha-------\n");
//}
//
//// Funcao para a opecao push
//
//No_p * empillhar (No_p * topo){
//No_p *novo = malloc(sizeof(No_p));
//  if(novo){
//      novo->d = d();
//      novo->proximo = topo;
//      return novo ;
//  }else{
//      printf("Erro ao Alocar memoria");
//  }
//}
//
//No_p * desempilhar(No_p ** topo){
//   if(*topo != NULL){
//       No_p * remover = *topo ;
//       *topo = remover->proximo ;
//       return remover ;
//   }else{
//       printf("Erro ao Desempilhar");
//       return NULL;
//   }
//}
//
//
//
//
//int main(){
//    No_p *topo = NULL , *remover = NULL ;
//    int opcao;
//
//
//    printf("Entre com uma opcao\n ");
//    do {
//        printf("- Sair(1)  \n- Empilhar(2) \n- Desempilhar(3) \n- Imprimir (4)  ");
//        printf("\n:== ");
//        scanf("%d", &opcao);
//        switch (opcao) {
//            case 1:
//                break;
//            case 2:
//                topo = empillhar(topo);
//                break;
//            case 3:
//                remover = desempilhar(&topo);
//                if(remover){
//                    printf("Removido com sucesso\n");
//                    imprimir_dado_p(remover->d);
//                    free(remover);
//                }else{
//                    printf("Sem no a Remover");
//                }
//                break;
//            case 4:
//                imprimir_pilha(topo);
//                break;
//            default:
//                printf("Opcao errada");
//                break;
//        }
//
//    }while(opcao != 1);
//
//    return 0 ;
//
//
//}
//
