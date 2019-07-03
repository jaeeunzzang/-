#include <stdio.h>
#include <string.h>
#incluse <stdlib.h>

typedef struct node
{
  char name[20];
  struct node *link;
}NODE;

int main()
{
  char buffer[20];
  NODE *p,*h,*mid,*temp; //mid=temp
  int c=0, m=1, cnt=0, test=0;
  /*
  switch문 제어 변수 c
  메뉴제어 변수 m
  인원수 제어변수 cnt
  환상형 연결리스트 테스트변수 test
  */
  
  h=null;
  do
  {
    while(1)
    {
      puts("각 메뉴는 순차적으로 한 번씩 실행됩니다.");
      printf("%d번 메뉴를 실행\n",m);
      puts("1. 네 명의 정보 입력하기");
      puts("2. 입력 된 사람의 정보 삭제");
      puts("3. 입력 된 사람의 정보 뒤에 새로운 사람 정보 삽입");
      puts("4. 입력 된 사람의 정보 뒤에 있는 사람 정보 삭제");
      puts("5. 마지막 노드가 처음을 가리키게 함"); //환상형 연결리스트
      puts("6. 종료");
      scanf("%d",&c);
      getchar();
      
      if(c!=m)
        printf("순서대로 입력해 주세요. 현재 %d 번",m);
     else
     {
       m++;
       break;
     }
      
      switch(c)
      {
          case 1;
          while(cnt !=4)
          {
            p=(NODE *)malloc(sizeof(NODE));
            if(p==null)
            {
              puts("메모리 할당 오류");
              exit(1);
            }
            cnt++;
            printf("이름을 입력하세요 : ");
            gets(buffer);
            strcpy(p -> name, buffer);
            
            if(h==null)
            {
              h=p;
              mid=p;
            }
            else
            {
              mid -> link=p;
              mid=p;
            }
            p -> link=null;
          }
          printf("\n물리적 저장 구조를 알아보기 위한 주소 출력\n");
          p=h;
          while(p!=null)
          {
            printf("%10s ->",p->name);
            p=p->link;
          }
          printf("null\n");
          p=h;
          while(p!=null)
          {
            printf("%10d ->",p);
            p= p -> link;
          }
          
                   
         
            
      


