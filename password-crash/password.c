#include <stdio.h>
#include <string.h>

int check(){
    char input[12];
    const char* password;
    password = "vasyapupkin";
    gets(input);
    if (0 == strcmp(password, input)){
        return 1;
    }
    else {
        return 0;
    }
}
        

int main() {
    //while (1){
        if (check()){
            printf("successful\n");
        }
        else {
            printf("wrong password\n");
        }
    //}
    return 0;
}