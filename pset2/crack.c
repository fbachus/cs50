#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
#include <crypt.h>


int main(void){
    string hash0 = get_string("input key:");
    char key1[] = "     ";
    int a = 0;
    int b = 'A';
    // hash0 = crypt(key0, 50);
    for (int i = 1; i < (pow(52, 5) + 1); i++) {
        string hash1 = crypt(key1, "50");
        int divi = (i / 52) % 52;
        // printf("%c", b);
        if (hash0 == hash1){
            printf("hallo %s", key1);
            return 0;
        }
        if ((i % 52) == 26){
            b = b + 6;
        }
        if (i % 10000 == 0){
            printf("%s, %i \n", key1, i);
        }
        if (i % 52 == 0 ){
            b = 'A';
            double d = log10(i) / log10(52);
            for (int w = 0; w < d; w++){
                key1[w] = 'A';
            }
            if ((key1[(int)d]) == ' '){
                key1[(int)d] = 'A';
            }
            else if ((key1[(int)d]) == 'Z'{
                key1[(int)d] = key1[(int)d] + 6;
            }
            else {
                key1[(int)d]++;
            }
        }
        else{
            key1[0] = b;
            b++;
            // key1[0] = b;
        }
    }
    printf("nothing matched\n");
}