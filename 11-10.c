#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6
#define MAXLEN 100


int cmp_str(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
   
    char *movies[SIZE] = {
        "Ant-Man",
        "Avengers",
        "Bohemian Rhapsody",
        "Insidious",
        "MI:Fallout",
        "The Batman"
    };

    char target[MAXLEN];
    char new_title[MAXLEN];

    printf("<< 영화 목록 >>\n");
    for (int i = 0; i < SIZE; i++)
        printf("%s\n", movies[i]);

    
    printf("\n검색할 제목: ");
    fgets(target, MAXLEN, stdin);
    target[strcspn(target, "\n")] = 0;   

 
    char *key = target;

    char **found = bsearch(&key, movies, SIZE, sizeof(char *), cmp_str);

    if (found == NULL) {
        printf("해당 영화가 목록에 없습니다.\n");
        return 0;
    }

    
    printf("수정할 제목: ");
    fgets(new_title, MAXLEN, stdin);
    new_title[strcspn(new_title, "\n")] = 0;


    *found = strdup(new_title);   

    
    qsort(movies, SIZE, sizeof(char *), cmp_str);

    printf("\n<< 영화 목록 >>\n");
    for (int i = 0; i < SIZE; i++)
        printf("%s\n", movies[i]);

    return 0;
}