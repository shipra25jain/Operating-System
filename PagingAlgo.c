#include<stdio.h>
#include<stdlib.h>
int n, pg[150], fr[10];
n=150;
void fifo ();
void optimal ();
void lru ();
FILE *myFile1;
int Limits[10], pID[10],pID2[110],LAddr[110];
    int i;


void
main ()
{

   myFile1 = fopen("referencestream.txt", "r");
 
   for (i = 0; i < 110; i++)
    {
        fscanf(myFile1, "%d", &pID2[i]);
         fscanf(myFile1, "%d", &LAddr[i]);
    }
  int i, ch;
  //printf ("\nHi...Please enter total number of pages in your sequence:");
  //scanf ("%d", &n);
  printf ("\nReading the  sequence....wait");
  for (i = 0; i < 110; i++)    //accepting sequence
    pg[i]=LAddr[i];
printf("\nSelect the Paging Algorithm:\n 1. FIFO\n 2. LRU\n 3.Clock\n");
int mychoice;
scanf("%d",&mychoice);
if(mychoice==1)
{
 printf
    ("\n\\FIFO PAGING ALGORITGHM\n");
optimal();

}
else if(mychoice==2)
{
 printf
    ("\n\\LEAST RECENTLY USED PAGING ALGORITGHM\n");
lru();

}
else if(mychoice==3)
{
 printf
    ("\n\\CLOCK PAGING ALGORITGHM\n");
optimal();

}
 
}
    



void
fifo ()
{
  int i, f, r, s, count, flag, num, fsize;
  f = 0;
  r = 0;
  s = 0;
  flag = 0;
  count = 0;
  printf ("\nEnter size of page table:");
  scanf ("%d", &fsize);
  for (i = 0; i < fsize; i++)
    {
      fr[i] = -1;
    }


  while (s < n) //no. of pages
    {
      flag = 0;
      num = pg[s];
      for (i = 0; i < fsize; i++)
    {
      if (num == fr[i])
        {
          s++;
          flag = 1;
          break;
        }
    }
      if (flag == 0)
    {
      if (r < fsize)
        {
          fr[r] = pg[s];
          r++;
          s++;
          count++;
        }
      else
        {
          if (f < fsize)
        {
          fr[f] = pg[s];
          s++;
          f++;
          count++;
        }
          else
        f = 0;
        }
    }
      printf ("\n");
      for (i = 0; i < fsize; i++)
    {
      printf ("%d\t", fr[i]);
    }
    }
  printf ("\nTotal Page Faults are =%d\n", count);
  getchar ();}

void lru ()
{
  int count[10], i, j, k, fault, f, flag, temp, current, c, dist, max, m, cnt,
    p, x;
  fault = 0;
  dist = 0;
  k = 0;
  printf ("\nEnter page table size:");
  scanf ("%d", &f);
//initilizing distance and frame array
  for (i = 0; i < f; i++)
    {
      count[i] = 0;
      fr[i] = -1;
    }
  for (i = 0; i < n; i++)

// lru algorithm implementation,. for n =o ni am () jhjkljkn for()
    {
      flag = 0;
      temp = pg[i];
      for (j = 0; j < f; j++)
    {
      if (temp == fr[j])
        {
          flag = 1;
          break;
        }
    }
      if ((flag == 0) && (k < f))
    {
      fault++;
      fr[k] = temp;
      k++;
    }
      else if ((flag == 0) && (k == f))
    {
      fault++;
      for (cnt = 0; cnt < f; cnt++)
        {
          current = fr[cnt];
          for (c = i; c > 0; c--)
        {
          if (current != pg[c])
            count[cnt]++;
          else
            break;
        }
        }
      max = 0;
      for (m = 0; m < f; m++)
        {
          if (count[m] > max)
        {
          max = count[m];
          p = m;
        }
        }
      fr[p] = temp;
    }
      printf ("\n");
      for (x = 0; x < f; x++)
    {
      printf ("%d\t", fr[x]);
    }
    }
  printf ("\nTotal number of faults=%d", fault);// page faults given by lru paging algorithm in which least recently used are replaced henever a page fault occurs
  getchar ();
}
void
optimal ()
{
  int count[10], i, j, k, fault, f, flag, temp, current, c, dist, max, m, cnt,
    p, x;
  fault = 0;
  dist = 0;
  k = 0;
  printf ("\nEnter frame size:");
  scanf ("%d", &f);
//initilizing distance and frame array
  for (i = 0; i < f; i++)
    {
      count[i] = 0;
      fr[i] = -1;
    }
  for (i = 0; i < n; i++)
    {
      flag = 0;
      temp = pg[i];
      for (j = 0; j < f; j++)
    {
      if (temp == fr[j])
        {
          flag = 1;
          break;
        }
    }
      if ((flag == 0) && (k < f))
    {
      fault++;
      fr[k] = temp;
      k++;
    }
      else if ((flag == 0) && (k == f))
    {
      fault++;
      for (cnt = 0; cnt < f; cnt++)
        {
          current = fr[cnt];
          for (c = i; c < n; c++)
        {
          if (current != pg[c])
            count[cnt]++;
          else
            break;
        }
        }
      max = 0;
      for (m = 0; m < f; m++)
        {
          if (count[m] > max)
        {
          max = count[m];
          p = m;
        }
        }
      fr[p] = temp;
    }
      printf ("\n");
      for (x = 0; x < f; x++)
    {
      printf ("%d\t", fr[x]);
    }
    }
  printf ("\nTotal number of faults=%d", fault);
  getchar ();
}
