CC = gcc

tokenizer: ./tokeniser/tokeniser.c
    ${CC} tokeniser.c -o tokeniser
