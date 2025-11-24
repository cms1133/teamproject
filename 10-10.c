#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char name[30];
    int price;
    int stock;
} PRODUCT;

int main() {
    PRODUCT p[MAX];
    int count = 0;

    while (count < MAX) {
        printf("제품명? ");
        scanf("%s", p[count].name);

        
        if (strcmp(p[count].name, "끝") == 0)
            break;

        printf("가격? ");
        scanf("%d", &p[count].price);

        printf("재고? ");
        scanf("%d", &p[count].stock);

        count++;
        printf("\n");
    }

    printf("\n[구조체 내용 출력]\n");
    for (int i = 0; i < count; i++) {
        printf("제품명: %s\n", p[i].name);
        printf("가격: %d\n", p[i].price);
        printf("재고: %d\n\n", p[i].stock);
    }

    return 0;
}
