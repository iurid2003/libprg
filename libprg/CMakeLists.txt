cmake_minimum_required(VERSION 3.21)

# Add header files here manually
set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
)
# Add source files here manually
set(SOURCES 
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/sum.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/sub.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/libprg.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/lista_linear.c"
)

add_library(libprg
        src/libprg/lista_linear.c
        src/libprg/fila.c
        src/libprg/lista_contato.c
        src/libprg/pilha.c
        src/libprg/fila_encadeada.c
        src/libprg/pilha_encadeada.c
        src/libprg/lista_encadeada_circular.c
        src/libprg/alg_ord_troca.c
        src/libprg/alg_ord_div.c
        Ponteiro/AULA1.c
        src/libprg/recursividade.c
        Ponteiro/AULA2.c
        Ponteiro/AULA3.c
        Ponteiro/AULA4.c
        Ponteiro/AULA5.c
        Ponteiro/AULA6.c
        Ponteiro/AULA7.c
        Ponteiro/AULA8.c
        Ponteiro/ex001.c
        Ponteiro/ex002.c
        Ponteiro/ex003.c
        Ponteiro/ex004.c
        Alocaçao/malloc.c
        Alocaçao/calloc.c
        Alocaçao/vetor_dinamico.c
        src/libprg/lista_circular_duplamente_encadeada.c
)
target_sources(libprg PUBLIC ${SOURCES})
target_include_directories(libprg PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/include)

target_compile_features(libprg PUBLIC c_std_17)

# https://cmake.org/cmake/help/latest/prop_tgt/AUTOGEN_TARGETS_FOLDER.html
source_group(
       TREE "${PROJECT_SOURCE_DIR}/libprg/src/include"
       PREFIX "Header Files"
       FILES ${HEADERS})

# https://cmake.org/cmake/help/latest/command/install.html
install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADER_LIST} DESTINATION include)