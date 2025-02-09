#include <stdio.h>
#include <stdlib.h>

struct Myarray
{
  int total_size;
  int used_size;
  int *ptr;
};

void createarray(struct Myarray *a, int tSize, int uSize)
{
  // (*a).total_size = tSize;
  // (*a).used_size = uSize;
  // (*a).ptr = (int *)malloc(tSize*sizeof(int));

  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct Myarray *a)
{
  for (int i = 0; i < (*a).used_size; i++)
  {
    printf("%d\t", (a->ptr)[i]);
  }
}

void setvalue(struct Myarray *a){
  for (int i = 0; i < a->used_size; i++)
  {
    printf("ENTER VALUE OF %d : ",i);
    scanf("%d",&(a->ptr)[i]);
  }
  
}
int main()
{
  struct Myarray marks;
  createarray(&marks,100,5);
  setvalue(&marks);
  show(&marks);
}