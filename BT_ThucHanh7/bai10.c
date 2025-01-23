#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_upper(char c[], int len){
    for (int i = 0; i < len; i++){
        c[i] = toupper(c[i]);
    }
}

void morse(char c){
    char Morse[36][10] = {
        ".-",        //A
        "-...",      //B
        "-.-.",      //C
        "-..",       //D
        ".",         //E
        "..-.",      //F
        "--.",       //G
        "....",      //H
        "..",        //I
        ".---",      //J
        "-.-",       //K
        ".-..",      //L
        "--",        //M
        "-.",        //N
        "---",       //O
        ".--.",      //P
        "--.-",      //Q
        ".-.",       //R
        "...",       //S
        "-",         //T
        "..-",       //U
        "...-",      //V
        ".--",       //W
        "-..-",      //X
        "-.--",      //Y
        "--.." ,     //Z

        "-----",     //0
        ".----",     //1
        "..---",     //2
        "...--",     //3
        "....-",     //4
        ".....",     //5
        "-....",     //6
        "--...",     //7
        "---..",     //8
        "----.",     //9
    };
    if (c >= 'A' && c <= 'Z'){
        printf("%s ", Morse[(int)c - 65]);
    }
    if (c >= '0' && c <= '9'){
        printf("%s ", Morse[(int)c - 22]);
    }
}

int main(){
    char c[1000];
    char s[20][1000];
    fgets(c, 100, stdin);
    int n = 0, len = strlen(c);
    to_upper(c, len);
    char *token = strtok(c, " ");
    while (token != NULL){
        strcpy(s[n++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < strlen(s[i]); j++){
            morse(s[i][j]);
        }
        printf("  ");
    }

}