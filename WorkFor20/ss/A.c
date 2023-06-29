#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
  char id[20];          
  char first_name[100]; 
  char last_name[100];  
  int relearn;         
  int score_c;          
  char GPA[2];          
  int Rank;             
} Student;

struct Student stu[100];
int cnt;

const char *assgpa(int x)
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

void add(char first[100], char last[100], char id[20], int score)  
{
  cnt++;
  stu[cnt].score_c = score;
  strcpy(stu[cnt].id, id);
  strcpy(stu[cnt].first_name, first);
  strcpy(stu[cnt].last_name, last);
  strcpy(stu[cnt].GPA, assgpa(score));
  id[4] = '\0';
  if (strcmp(id, "2022")) {
    stu[cnt].relearn = 1;
  }
  else {
    stu[cnt].relearn = 0;
  }
}

int main () {
    char first_name[100], last_name[100], id[20];
    int score;
    printf("Name_f Name_l stu_id score retake GPA rank\n");
    while (scanf("%s %s %s %d", first_name, last_name, id, &score)!=EOF) {
        add(first_name, last_name, id, score);
        if(strlen(stu[cnt].id) == 12) {
            printf("%s %s %s %d %d %s\n", stu[cnt].first_name, stu[cnt].last_name, \
            stu[cnt].id,stu[cnt].score_c, stu[cnt].relearn, stu[cnt].GPA);
        }
    }
}