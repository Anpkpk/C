#include <stdio.h>
#include <string.h>
#include <ctype.h>

void morse(char c[]){
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
    for (int i = 26; i < 36; i++){
        if (strcmp(c, Morse[i]) == 0){
            printf("%c", (char)(i + 22));
            return;
        }
    }
    for (int i = 0; i < 26; i++){
        if (strcmp(c, Morse[i]) == 0){
            printf("%c", (char)(i + 65));
            return;
        }
    }
}

int main(){
    char c[1000], s[100][1000], tmp[100][1000];
    fgets(c, 1000, stdin);
    int n = 0;
    int len = strlen(c);
    int i = 0, j = 0;
    for (int i = 0; i < len; i++){
        if (c[i] != ' '){
            s[n][j++] = c[i];
        }
        else{
            if (c[i+1] == ' ' || c[i-1] == ' '){
                i += 2;
                s[n++][j] = '\0';
                j = 0;
                continue;
            }
            s[n][j++] = c[i];
        }
    }
    int k;
    fflush(stdin);
    for (int i = 0; i <= n; i++){
    	k = 0;
        char *token = strtok(s[i], " ");
     	while (token != NULL){
         	strcpy(tmp[k], token);
         	token = strtok(NULL, " ");
         	++k;
     	}
     	for (int j = 0; j < k; j++){
     		morse(tmp[j]);
		}
		fflush(stdin);
		printf(" ");
    }
    
}