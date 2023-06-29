#include <stdio.h>
#include <string.h>
typedef struct Student
{
  char first_name[20];
  char last_name[20];
  char id[20];
  int score;
  int retake;
  char *GPA;
} Student;

Student stu[110] =
    {
        {"Jingyu", "LI", "202200000000", 85, 0},
        {"Jy", "LEE", "202200100000", 89, 0},
        {"Jxxxyx", "Leeeee", "202100100000", 100, 1},
        {"Jingyu11", "LI", "202200000001", 85, 0}};

char check_id[] = {"2022"};

char *getGPA(int x)
{
  if (x >= 93)
  {
    return "A+";
  }
  else if (x <= 92 && x >= 85)
  {
    return "A";
  }
  else if (x <= 84 && x >= 80)
  {
    return "B+";
  }
  else if (x <= 79 && x >= 75)
  {
    return "B";
  }
  else if (x <= 74 && x >= 70)
  {
    return "C+";
  }
  else if (x <= 69 && x >= 65)
  {
    return "C";
  }
  else if (x <= 64 && x >= 60)
  {
    return "D";
  }
  else
  {
    return "F";
  }
}

void Add(char first[], char last[], char id[], int score, int i)
{
  strcpy(stu[i].first_name, first);
  strcpy(stu[i].last_name, last);
  strcpy(stu[i].id, id);
  stu[i].score = score;
}
void init()
{
  printf("Name_f Name_l stu_id score retake GPA\n");
  printf("Jingyu LI 202200000000 85 0 A\n");
  printf("Jy LEE 202200100000 89 0 A\n");
  printf("Jxxxyx Leeeee 202100100000 100 1 A+\n");
  printf("Jingyu11 LI 202200000001 85 0 A\n");
}

int main()
{
  init();
  char name_f[20], name_l[20], id[20];
  int score;
  int i = 4;
  for (int i = 0; i < 4; i++)
    stu[i].GPA = getGPA(stu[i].score);
  while (~scanf("%s%s%s%d", name_f, name_l, id, &score))
  {
    if (strlen(id) != 12 || score < 0 || score > 100)
      continue;
    Add(name_f, name_l, id, score, i);
    stu[i].GPA = getGPA(stu[i].score);
    if (memcmp(stu[i].id, check_id, 4) != 0)
      stu[i].retake = 1;
    printf("%s %s %s %d %d %s\n", stu[i].first_name, stu[i].last_name, stu[i].id, stu[i].score, stu[i].retake, stu[i].GPA);
    i++;
  }
  printf("Total: %d", i);
  return 0;
}