#include <stdio.h>
char GPA[10][5] = {{"A+"}, {"A"}, {"B+"}, {"B"}, {"C+"}, {"C"}, {"D"}, {"F"}};
int GPA_cnt[10] = {0};

void process(int x) {
    if (x < 0 || x > 100) return ;
    if (x >= 93) GPA_cnt[0]++;
    else if (x >= 85) GPA_cnt[1]++;
    else if (x >= 80) GPA_cnt[2]++;
    else if (x >= 75) GPA_cnt[3]++;
    else if (x >= 70) GPA_cnt[4]++;
    else if (x >= 65) GPA_cnt[5]++;
    else if (x >= 60) GPA_cnt[6]++;
    else GPA_cnt[7]++;
}
int main()
{
    int scores;
    while (scanf("%d", &scores) != EOF)
    {
        if (scores < 0 || scores > 100)
            continue;
        if (scores >= 93) GPA_cnt[0]++;
        else if (scores >= 85) GPA_cnt[1]++;
        else if (scores >= 80) GPA_cnt[2]++;
        else if (scores >= 75) GPA_cnt[3]++;
        else if (scores >= 70) GPA_cnt[4]++;
        else if (scores >= 65) GPA_cnt[5]++;
        else if (scores >= 60) GPA_cnt[6]++;
        else GPA_cnt[7]++;
    }
    for (int i = 0; i < 8; i++)
        if (GPA_cnt[i])
            printf("%s: %d\n", GPA[i], GPA_cnt[i]);
    return 0;
}