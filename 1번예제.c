#include <stdio.h>

int main()
{
  int a[20][19][3] ={0};
  int i,j;
  
  for(i=1;i<20;i++)
  {
    for(j=0;j<19;j++)
    {
       a[i][j][0] = i;
      a[i][j][1] = j+1;
      a[i][j][2]= (i)*(j+1);
    }
  }
  
  printf("구구단을 출력합니다.\n");
  
  for(i=1;i<20;i++)
  {
    printf("%d 단\n",i);
    
    for(j=0;j<19;j++)
    {
      printf("%d *%2d =%2d\t",a[i][j][0],a[i][j][1],a[i][j][2]);
      
      if((j+1)%4==0)
      printf("\n");
    }
     if(j /19  == 1)
        printf("\n");
  }
  
  printf("합계를 출력합니다.\n");
  
  for(j=0;j<19;j++)
  {
    for(i=0;i<20;i++)
    {
      a[20][j][0] += a[i][0][3];
      
    }
  }
  for(j=0;j<19;j++)
  {
    a[20][0][0]+=a[20][j+1][0];
  }
  printf("합계 : %d\n",a[20][0][0]);
  return 0;
}
      
