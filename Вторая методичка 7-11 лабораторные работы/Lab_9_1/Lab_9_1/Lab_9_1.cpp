#include <stdio.h>
#include <math.h >

int main() {
  
    char str[100];
    FILE* fin;

    fin = fopen("D:\\file.txt", "r");


    printf("---FILE after load---\n");
    int count = 0;
    while (1) {
        if (NULL != fgets(str, 100, fin)){
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            printf("%s", str);
            count++;
        }
        else {
            break;
        }
    }


    fclose(fin);

    int weight;
    int height;

    printf("\nInput height: ");
    scanf("%d", &height);
    printf("\nInput weight: ");
    scanf("%d", &weight);

    fin = fopen("D:\\file.txt", "r");

    count = 0;
    int currentRecord = 1;
    int recordByHeight = 0;
    int recordByWeight = 0;
    int currentWeight = 0;
    while (1) {
        if (NULL != fgets(str, 100, fin)) {
            if (count == 4) {
                count = 0;
                currentRecord++;
            }
            if (count == 2) {
                int currentHeight = 0;
                int i;
                for (i = 0; str[i] != '\0'; i++) {
               
                }
                i -=2;
                for (int j = 0; str[j] != '\0'; j++) {
                    currentHeight += ((int)str[j] - (int)'0') * (int)pow(10, i);
                    i--;
                }
                if (currentHeight == height) {
                    recordByHeight = currentRecord;
                }
            }
            if (count == 3) {
                int currentWeight = 0;
                int i;
                for (i = 0; str[i] != '\n'; i++);
                i--;
                for (int j = 0; str[j] != '\0'; j++) {
                    currentWeight += ((int)str[j] - (int)'0') * (int)pow(10, i);
                    i--;
                }
                if (currentWeight == weight) {
                    recordByWeight = currentRecord;
                }
            }
            count++;
        }
        else {
            break;
        }
    }

    fclose(fin);

    int isNeedDeleted = 0;
    if (recordByHeight == recordByWeight) {
        isNeedDeleted = recordByHeight;
    }


    FILE* temp;
    if (isNeedDeleted) {
        fin = fopen("D:\\file.txt", "r");
        temp = fopen("D:\\temp.txt", "wb");

        count = 0;
        currentRecord = 1;
        while (1) {
            if (NULL != fgets(str, 100, fin)) {
                if (count == 4) {
                    count = 0;
                    currentRecord++;
                }
                if (currentRecord != isNeedDeleted) {
                    fprintf(temp, "%s", str);
                }
                count++;
            }
            else {
                break;
            }
        }
        fclose(temp);
        fclose(fin);
    }

    temp = fopen("D:\\temp.txt", "r");

    printf("\n---File after delete---\n");
    while (1) {
        if (NULL != fgets(str, 100, temp)) {
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            printf("%s", str);
            count++;
        }
        else {
            break;
        }
    }
    fclose(temp);

    int k = 2;

    temp = fopen("D:\\temp.txt", "a");

    printf("\n");
    char input[50];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                printf("Input name:\n");
            } else if (j == 1) {
                printf("Input birthday:\n");
            } else if (j == 2) {
                printf("Input height:\n");
            } else {
                printf("Input weight:\n");
            }
           
            scanf("%s", input);
            fprintf(temp, "%s", input);
            fprintf(temp, "%s", "\n");
        }
    }

    fclose(temp);

    temp = fopen("D:\\temp.txt", "r");

    printf("\n---File after add---\n");
    while (1) {
        if (NULL != fgets(str, 100, temp)) {
            if (count == 4) {
                count = 0;
                printf("\n");
            }
            printf("%s", str);
            count++;
        }
        else {
            break;
        }
    }
    fclose(temp);

}
