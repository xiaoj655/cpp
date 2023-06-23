#include <stdio.h>
#include <string.h>
typedef struct Student
{
    char first_name[20];
    char last_name[20];
    char id[20];
    int score;
    int rank;

} Student;
Student stu[1020];
Student tem;

void Set_rank(int n)
{
    stu[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (stu[i].score == stu[i - 1].score)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = i + 1;
    }
}

void Sort(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stu[i].score < stu[j].score)
            {
                tem = stu[i];
                stu[i] = stu[j];
                stu[j] = tem;
            }
        }
    }
}


int main()
{
    printf("Name_f Name_l stu_id score Rank\n");
    int n = 0;
    while (scanf("%s%s%s%d", stu[n].first_name, stu[n].last_name,
                 stu[n].id, &stu[n].score))
        n++;
    Sort(n);
    Set_rank(n);
    for (int i = 0; i < n; i++)
        printf("%s %s %s %d %d\n", stu[i].first_name,
               stu[i].last_name, stu[i].id, stu[i].score, stu[i].rank);
    return 0;
}