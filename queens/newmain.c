#include <stdlib.h>
#include <stdio.h>

void init_grid(int * grid, int size)
{
    int i;
    i = -1;
    while(i++ < size-1)
    {
        grid[i] = -1;
    }
    grid[0] = 0;
}
int abs(int num)
{
    if(num<0)
        return 0-num;
    return num;
}

int check_poss(int * grid, int size, int line, int height)
{
    int i;
    int queenpos;
    int currqueenpos;
    i = -1;
    queenpos = height + line * size;    
    while (i++ < line-1)
    {
        if(grid[i]!=-1)
        {
            currqueenpos = grid[i] + size * i;
            if(queenpos % size == grid[i])
                return 0;
            if(abs(queenpos - currqueenpos)%(size+1)==0 && abs(queenpos - currqueenpos)>abs(line - i)*size)
                return 0;
            if(abs(queenpos - currqueenpos)%(size-1)==0 && abs(queenpos - currqueenpos)<abs(line - i)*size)
                return 0;
        }
    }
    return 1;
}

int check_line(int * grid, int size, int line)
{
    int i;
    i = grid[line];
    while(i++ < size - 1)
    {
        if(check_poss(grid, size, line, i))
            return i;
    }
    return -2;
}

void re_init(int * grid, int from, int size)
{
    int i;
    i = from-1;
    while(i++<size - 1)
    {
        grid[i] = -1;
    }
}

void print_grid(int * grid, int size)
{
    int i;
    i = -1;
    while (i++ < size-1)
    {
        printf("%d\t", grid[i]);
    }
    printf("\n");
    
}

int main()
{
    int degree;
    int count;
    int okcount;
    okcount = 0;
    degree = 14;
    count = 1;
    int * grid = malloc(degree * sizeof(int));
    init_grid(grid, degree);
    while(grid[0]!=-1)
    {
        int nextline;
        nextline=check_line(grid, degree, count);
        if(nextline!=-2)
        {
            grid[count] = nextline;
            count ++;
        }else
        {
            re_init(grid, count, degree);
            if(count>0)
                count --;
        }
        if (count == degree)
        {
            print_grid(grid, degree);
            okcount += 1;
        }     
    }
    free(grid);
    printf("%d\n", okcount);
}