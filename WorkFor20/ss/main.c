#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
  char id[20];          // 学号
  char first_name[100]; // 名
  char last_name[100];  // 姓
  bool relearn;         // 重修
  int score_c;          // C语言成绩
  char GPA[2];          // 绩点
  int Rank;             // 班级排名
} Student;

Student stu[1020];
int cnt;

void swap(Student *a, Student *b)
{
  Student temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

const char *getGPA(int x)
{
  if (x >= 93)  return "A+";
  else if (x <= 92 && x >= 85)  return "A";
  else if (x <= 84 && x >= 80)  return "B+";
  else if (x <= 79 && x >= 75)  return "B";
  else if (x <= 74 && x >= 70)  return "C+";
  else if (x <= 69 && x >= 65)  return "C";
  else if (x <= 64 && x >= 60)  return "D";
  else  return "F";
}


void Search(char id[20]) // 查找学生信息
{
  for (int i = 1; i <= cnt; i++)
  {
    if (!strcmp(id, stu[i].id))
    {
      printf("********************************\n");
      printf("id: %s\n", stu[i].id);
      printf("first_name: %s", stu[i].first_name);
      printf("last_name: %s\n", stu[i].last_name);
      printf("重修: %s\n", stu[i].relearn ? "yes" : "no");
      printf("C语言成绩: %d\n", stu[i].score_c);
      printf("GPA: %s\n", stu[i].GPA);
      printf("班级排名: %d\n", stu[i].Rank);
      printf("********************************\n");
      break;
    }
  }
}


void add(char first_name[100], char last_name[100], char id[20], int score) // 添加学生信息
{
  cnt++;
  sprintf(stu[cnt].first_name, "%s", first_name);
  sprintf(stu[cnt].last_name, "%s", last_name);
  sprintf(stu[cnt].id, "%s", id);
  stu[cnt].score_c = score;
  sprintf(stu[cnt].GPA, "%s", getGPA(score));
  id[4] = 0;
  if (strcmp(id, "2022"))
    stu[cnt].relearn = true;
  else 
    stu[cnt].relearn = false;
}

void deleteStu(char id[20]) // 删除学生信息
{
  for (int i = 1; i <= cnt; i++)
  {
    if (!strcmp(id, stu[i].id))
    {
      swap(stu + i, stu + cnt);
      stu[cnt];
      cnt--;
      break;
    }
  }
}

void mergesort(int l, int r) // 归并排序
{
  int mid = l + r >> 1;
  if (l >= r) return;

  mergesort(l, mid);
  mergesort(mid + 1, r);

  int i = l, j = mid + 1;
  Student *temp = (Student *)malloc((r - l + 1) * sizeof(Student));
  int k = 0;

  while (i <= mid && j <= r)
  {
    if (stu[i].score_c > stu[j].score_c)
      temp[k++] = stu[i++];
    else
      temp[k++] = stu[j++];
  }

  while (i <= mid)  temp[k++] = stu[i++];
  while (j <= r)  temp[k++] = stu[j++];
  for (int i = l; i <= r; i++)  stu[i] = temp[i - l];
  free(temp);
}

void sort_by_score() // 按成绩排序
{
  mergesort(1, cnt);
  for (int i = 1; i <= cnt; i++)
  {
    stu[i].Rank = i;
  }
  printf("%-14s %-12s %-12s %-3s %-3s %-3s %-4s\n", "学号", "first_name",
         "last_name", "重修", "C语言成绩", "GPA", "班级排名");
  for (int i = 1; i <= cnt; i++)
  {
    printf("%-12s %-12s %-12s %-4s %-3d %9s %-4d\n",\
          stu[i].id, stu[i].first_name,stu[i].last_name,\
          stu[i].relearn ? "是" : "否", stu[i].score_c,\
          stu[i].GPA, stu[i].Rank);
  }
}

char *tem = NULL;

// 加密规则 y = (x+key)%10
// 解密规则 x = (y-key+10)%10
const char *encrypt(int key) // 加密
{
  static char pvkey[3020];
  int pv = 0;
  char temp[4];
  pv = 0;
  for (int i = 1; i <= cnt; i++)
  {
    sprintf(temp, "%d", stu[i].score_c);
    int len = strlen(temp);
    for (int j = 0; j < len; j++)
      pvkey[pv++] = (temp[j] - '0' + key) % 10 + '0';
  }
  return tem = pvkey;
}

const char *decrypt(int key, char *str) // 解密
{
  if (tem == NULL)
    return "请先加密再解密\n";
  static char pckey[3020];
  int pc = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    pckey[pc++] = (str[i] - '0' - key + 10) % 10 + '0';
  }
  return pckey;
}

void analysis() // 成绩分析
{
  int a1 = 0, a = 0, b1 = 0, b = 0;
  int c1 = 0, c = 0, d = 0, f = 0;
  for (int i = 1; i <= cnt; i++)
  {
    int x = stu[i].score_c;
    if (x <= 100 && x >= 93)  a1++;
    else if (x <= 92 && x >= 85)  a++;
    else if (x <= 84 && x >= 80)  b1++;
    else if (x <= 79 && x >= 75)  b++;
    else if (x <= 74 && x >= 70)  c1++;
    else if (x <= 69 && x >= 65)  c++;
    else if (x <= 64 && x >= 60)  d++;
    else if (x < 60)  f++;
  }
  printf("***************************\n");
  printf("考情分析如下：\n");
  printf("A+的人数有%d个\n", a1);
  printf("A 的人数有%d个\n", a);
  printf("B+的人数有%d个\n", b1);
  printf("B 的人数有%d个\n", b);
  printf("C+的人数有%d个\n", c1);
  printf("C 的人数有%d个\n", c);
  printf("D 的人数有%d个\n", d);
  printf("F 的人数有%d个\n", f);
  printf("***************************\n");
}

void say() // 打印菜单
{
  printf("\
1 add\n\
2 delete\n\
3 search\n\
4 sort by score\n\
5 encrypt\n\
6 decrypt\n\
7 analysis\n\
0 exit\n\
  ");
}

int main()
{
  int op;
  printf("He11o,p1s input a series of studentinformation!\n");
  printf("okay, data upload finished. what do you what to \
  do next? You can enter a number to tel1 me.\n");
  say();
  while (scanf("%d", &op), op)
  {
    switch (op)
    {
    case 1:
    {
      char first_name[100], last_name[100], id[20];
      int score;
      printf("please input the first_name,last_name,id and\
 the score\n");
      scanf("%s%s%s%d", first_name, last_name, id, &score);
      add(first_name, last_name, id, score);
      break;
    }
    case 2:
    {
      char id[20];
      printf("please input the id\n");
      scanf("%s", id);
      deleteStu(id);
      break;
    }
    case 3:
    {
      char id[20];
      printf("please input the id\n");
      scanf("%s", id);
      Search(id);
      break;
    }
    case 4:
    {
      sort_by_score();
      break;
    }
    case 5:
    {
      int key;
      printf("please input the key\n");
      scanf("%d", &key);
      printf("%s\n", encrypt(key));
      break;
    }
    case 6:
    {
      int key;
      printf("please input the key\n");
      scanf("%d", &key);
      printf("%s\n", decrypt(key, tem));
      break;
    }
    case 7:
    {
      analysis();
      break;
    }
    case 0:
    {
      return 0;
    }
    }
    printf("okay, data upload finished. what do you what \
    to do next? You can enter a number to tel1 me.\n");
    say();
  }
  return 0;
}