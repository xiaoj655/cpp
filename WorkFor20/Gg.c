#include <stdio.h>
char GPA[10][5] = {{"A+"}, {"A"}, {"B+"}, {"B"}, {"C+"}, {"C"}, {"D"}, {"F"}};
int cnt[10] = {0};

void process(int x) {
        if (x >= 93) cnt[0]++;
        else if (x >= 85) cnt[1]++;
        else if (x >= 80) cnt[2]++;
        else if (x >= 75) cnt[3]++;
        else if (x >= 70) cnt[4]++;
        else if (x >= 65) cnt[5]++;
        else if (x >= 60) cnt[6]++;
        else if (x>=0) cnt[7]++;
}
int main()
{
    int scores;
    while (scanf("%d", &scores) != EOF)
    {
        process(scores);
    }
    for (int i = 0; i < 8; i++)
        if (cnt[i])
            printf("%s: %d\n", GPA[i], cnt[i]);
    return 0;
}