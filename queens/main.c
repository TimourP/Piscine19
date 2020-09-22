#include <stdlib.h>
#include <stdio.h>
#define dim 14

char main_array[dim] = {0};

int abs(num)
{
    if (num<0){
        return (0-num);
    }else{
        return (num);
    }
}


void initialize_array()
{
    int i;
    i=0;
    while(i<dim){
        main_array[i]=-1;
        i++;
    }
    main_array[0]=0;
}


int check(int number, int line)
{
    int value;
    int num;
    int queen;
    int real_value;
    value=1;
    num = number+dim*line;
    queen=0;
    while (queen<dim)
    {   
        if (main_array[queen]!=-1)
        { 
            real_value=(dim*queen+main_array[queen]);
            if (num <= real_value%dim)
            {
                value=0;
            }
            else if (abs(num-real_value)%dim==0)
            {
                value=0;
            }
            else if (abs(num-real_value)==(dim-1)*abs(line-queen))
            {
                value=0;
            }
            else if (abs(num-real_value)==(dim+1)*abs(line-queen)){
                value=0;
            }
        }
        queen++;
    }
    return (value);
}


int check_line(int line)
{
    int i;
    i=0;
    while(i<dim)
    {
        if (i>main_array[line])
        {
            if (check(i,line))
            {
                return (i);
            }
        }
        i++;
    }
    return (-2);
}


void main()
{   
    int count;
    int poss;
    int allPoss;
    allPoss=0;
    count=1;
    initialize_array(main_array,dim);
    while (main_array[0]!=-1)
    {   
        poss=check_line(count);
        if (poss!=(-2))
        {
            main_array[count]=poss;
            count++;
        }else
        {
            int i;
            i=0;
            while (i<dim-count)
            {
                main_array[dim-i-1]=-1;
                i++;
            }
            count--;
        }
        if (count==dim)
        {
            count--;
            allPoss++;
        }
    }
    printf("%d\n",allPoss);
}