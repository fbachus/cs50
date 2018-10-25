#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
#include <crypt.h>


int main(void){
    string hash0 = get_string("input key:");
    char key1[] = "     ";
    int a = 0;
    int b;
    // hash0 = crypt(key0, 50);
    for (int i =1; i < (pow(57, 5) + 1); i++) {
        b = 'A';
        string hash1 = crypt(key1, "50");
        if (hash0 == hash1){
            printf("hallo %s", key1);
            return 0;
        }
        else {
            if (i % 57 == 1 ){
                if ((i/57) > 0){
                    b = b - 57;
                }
                double d = log10(i) / log10(57);
                for (int w = 0; w < d; w++){
                    key1[w] = 'A';
                }
                key1[(int)d]++;
                if (i % 10000 == 0){
                    printf("%s, %i \n", key1, i);
                }
            }
            else{
                int r = i % 57;
                key1[0] = (char) (r + 65);
                // key1[0] = b;
            }
        }
        b++;
        // printf("%s \n", key1);
    }
    printf("nothing matched\n");
}