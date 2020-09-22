

int ft_strlen(char * str)
{
    int i;
    int count;
    i = -1;
    count = 0;
    while(str[i++] != '\0')
    {
        count ++;
    }
    count --;
    return count;
}