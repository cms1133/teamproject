#include <stdio.h>

int main() {
    FILE *fp;
    int americano = 4000;
    int latte = 4500;
    int flatwhite = 5000;

    int cnt_ame, cnt_lat, cnt_flat;
    int total = 0;

    
    printf("[메뉴] 아메리카노: 4000, 카페라떼: 4500, 플랫화이트: 5000\n");

    
    printf("아메리카노 수량? ");
    scanf("%d", &cnt_ame);
    printf("카페라떼 수량? ");
    scanf("%d", &cnt_lat);
    printf("플랫화이트 수량? ");
    scanf("%d", &cnt_flat);

   
    fp = fopen("receipt.txt", "w");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    
    int price_ame = americano * cnt_ame;
    int price_lat = latte * cnt_lat;
    int price_flat = flatwhite * cnt_flat;

    total = price_ame + price_lat + price_flat;

    
    fprintf(fp, "제품명\t\t단가\t수량\t금액\n");
    fprintf(fp, "-----------------------------------------\n");

    if (cnt_ame > 0)
        fprintf(fp, "아메리카노\t%d\t%d\t%d\n", americano, cnt_ame, price_ame);

    if (cnt_lat > 0)
        fprintf(fp, "카페라떼\t\t%d\t%d\t%d\n", latte, cnt_lat, price_lat);

    if (cnt_flat > 0)
        fprintf(fp, "플랫화이트\t%d\t%d\t%d\n", flatwhite, cnt_flat, price_flat);

    fprintf(fp, "\n합계\t\t\t\t%d\n", total);

    fclose(fp);

    printf("\n계산서가 receipt.txt 파일에 저장되었습니다.\n");

    return 0;
}