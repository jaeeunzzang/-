#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
  char name[20];
  struct node *link;
}NODE; //구조체 선언


int main(void)
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
  
  h=NULL;
  do
  {
    while(1)
    {
      puts("각 메뉴는 순차적으로 한 번씩 실행됩니다.");
      puts("1. 네 명의 정보 입력하기");
      puts("2. 입력 된 사람의 정보 삭제");
      puts("3. 입력 된 사람의 정보 뒤에 새로운 사람 정보 삽입");
      puts("4. 입력 된 사람의 정보 뒤에 있는 사람 정보 삭제");
      puts("5. 마지막 노드가 처음을 가리키게 함"); //환상형 연결리스트
      puts("6. 종료");
      
      printf("\n%d번 메뉴를 실행하세요\n",m);
      scanf("%d",&c);
      getchar();
      
         if(c!=m)
            printf("순서대로 입력해 주세요. 현재 %d 번",m);
         else
            {
              m++;
              break;
             }
    }
      
         switch(c)
              {
           case 1:
                  while(cnt !=4)
                     {
                          p=(NODE *)malloc(sizeof(NODE));
                          if(p == NULL)
                              {
                                 puts("메모리 할당 오류");
                                 exit(1);
                               }
                           cnt++;
                           printf("이름을 입력하세요 : ");
                           gets(buffer);
                           strcpy(p -> name, buffer);
            
                          if(h==NULL)
                            {
                              h=p;
                              mid=p;
                            }
                          else
                           {
                              mid -> link = p;
                              mid=p;
                           }
                           p -> link=NULL;
                      }
                   printf("\n물리적 저장 구조를 알아보기 위한 주소 출력\n");
                   p=h;
                  while(p!=NULL)
                     {
                       printf("%10s ->",p->name);
                       p=p->link;
                      }
                   printf("null\n");
                   p=h;
                   while(p!=NULL)
                     {
                        printf("%10d ->",p);
                        p= p -> link;
                      }
                   printf("null\n");
                   break;
         
          
           case 2:
                   printf("이름을 입력하세요 : ");
                   gets(buffer);
          
                   p=h;
                  while(p!=NULL)
                    {
                      if(strcmp(p -> name,buffer)==0)
                      break;
                      else
                      p=p->link;
                     }
                   if(p==NULL)
                   puts("일치하는 사람이 없습니다.");
                  else
                   {
                      if(p==h)
                        {
                           h=p->link;
                           free(p);
                         }
                      else if(p->link==NULL)
                         {
                           mid=p;
                           p=h;
                           while(p->link !=mid)
                             {
                                 p=p->link;
                              }
                           p->link=NULL;
                           free(mid);
                          }
                        else
                         {
                           mid=p;
                           p=h;
                           while(p->link !=mid)
                             {
                                  p=p->link;
                             }
                           p->link=mid->link;
                           free(mid);
                          }
                    }
                    printf("\n삭제 이후의 연결리스트 모습\n");
                    p=h;
                    while(p!=NULL)
                    {
                      printf("%10s ->",p->name);
                      p=p->link;
                    }
                    printf("null\n");
                    p=h;
                    while(p!=NULL)
                    {
                      printf("%10d->",p);
                      p=p->link;
                    }
                    printf("null\n");
                    break;
           case 3:
                temp = (NODE *)malloc(sizeof(NODE));
                if(temp==NULL)
                {
                  puts("메모리 할당 오류");
                  exit(1);
                }
                printf("삽입할 사람의 이름을 입력하세요 :");
                gets(temp->name);
                printf("누구의 뒤에 삽입 하겠습니까? :");
                gets(buffer);
                p=h;
                while(p!=NULL)
                {
                  if(strcmp(p -> name, buffer)==0)
                    break;
                  else
                    p=p->link;
                }
                  if(p==NULL)
                  puts("일치하는 사람이 없습니다.");
                  else
                  {
                    if(p->link==NULL)
                    {
                      p->link=temp;
                      temp->link=NULL;
                    }
                    else
                    {
                      temp->link=p->link;
                      p->link=temp;
                    }
                  }
                  p=h;
                  while(p != NULL)
                  {
                    printf("%10s ->",p->name);
                    p=p->link;
                  }
                  printf("null\n");
                  p=h;
                 while(p!=NULL)
                   {
                      printf("%10d ->",p);
                      p=p->link;
                   }
                 printf("null\n");
                 break;
             
           case 4:
             printf("삭제하기 위해 입력한 사람의 뒤에 있는 정보를 입력하세요:");
             gets(buffer);
             p=h;
             while(p!=NULL)
             {
               if(strcmp(buffer,p->name)==0)
                 break;
               else
                 p=p->link;
             }
             if(p==NULL)
               puts("일치하는 사람이 없습니다.");
             else
             {
               if(p->link == NULL)
                puts("입력하신 정보 뒤에는 삭제할 정보가 없습니다.");
               else
               {
                 mid=p->link;
                 if(mid->link==NULL)
                 {
                   p->link=NULL;
                   free(mid);
                 }
                 else
                 {
                   p->link=mid->link;
                   free(mid);
                 }
               }
             }
             p=h;
             while(p!=NULL)
             {
               printf("%10s ->",p->name);
               p=p->link;
             }
             printf("null\n");
             p=h;
             while(p!=NULL)
             {
               printf("%10d ->",p);
               p=p->link;
             }
             printf("null\n");
             break;
             
           case 5:
             p=h;
             while(p->link!=NULL)
             {
               p=p->link;
             }
             p->link=h;
             p=h;
             while(test<6)
             {
               printf("%10s->",p->name);
               p=p->link;
               test++;
             }
             printf("\n무한반복\n");
             p=h;
             test=0;
             while(test<6)
             {
               printf("%10d ->",p);
               p=p->link;
               test++;
             }
             printf("\n무한반복\n");
             break;
             
           case 6:
             printf("종료합니다.");
             break;
             
           default:
             printf("실행됨\n");
             break;
         }
    } while(c!=6)
    return 0;
  }
