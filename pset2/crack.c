#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
#include <crypt.h>

// -----------------------------------------
//   --- give the variables good names ---
// -----------------------------------------
int increase_char(int);

int main(void){
    string hash0 = get_string("input key:");
    char key[6] ;
    printf("%s\n", key);
    // hash0 = crypt(key0, 50);
    for (int i = 1; i < (pow(52, 5) + 1); i++) {
        string hash1 = crypt(key, "50");
        if (hash0 == hash1){
            printf("hallo %s", key);
            return 0;
        }
        if (i % 10000 == 0){
            printf("%s, %i \n", key, i);
        }
        for (int cha = 0; cha < 6; cha++){
            if (key[cha] == 'z'){
                key[cha + 1] = increase_char(key[cha + 1]);
            }
        }
        key[0] = increase_char(key[0]);
    }
    printf("nothing matched\n");
}

int increase_char(int changeable_char){
    if (changeable_char == ' ' || changeable_char == 'z' || (changeable_char < 'A' && changeable_char > 'z')){
        changeable_char = 'A';
    }
    else if (changeable_char == 'Z'){
        changeable_char = 'a';
    }
    else{
        changeable_char++;
    }
    return changeable_char;
}
//|| changeable_char == '@'