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

Student stu[1020] =
    {
        {"Jingyu", "LI", "202200000000", 85, 0},
        {"Jy", "LEE", "202200100000", 89, 0},
        {"Jxxxyx", "Leeeee", "202100100000", 100, 1},
        {"Jingyu11", "LI", "202200000001", 85, 0}};

int Delete(char id[])
{
  for (int i = 0; i < 4; i++)
  {
    if (strcmp(stu[i].id, id) == 0)
    {
      strcpy(stu[i].id, "\0");
      return 1;
    }
  }
  return 0;
}
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
int main()
{
  printf("Name_f Name_l stu_id score retake GPA\n");
  char id[20];
  int i = 4;
  for (int i = 0; i < 4; i++) stu[i].GPA = getGPA(stu[i].score);
  while (scanf("%s", id) != EOF)
  {
    if (strlen(id) != 12)
      continue;
    if (Delete(id))
      i--;
  }
  for (int i = 0; i < 4; i++)
  {
    if (strcmp(stu[i].id, "\0") != 0)
      printf("%s %s %s %d %d %s\n", stu[i].first_name,\
      stu[i].last_name, stu[i].id, stu[i].score, stu[i].retake, stu[i].GPA);
  }
  printf("Total: %d", i);
  return 0;
}