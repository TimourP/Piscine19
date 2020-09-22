#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *test[100] = {"bSQcfgTk32DRFvf4gRkBlXIbx5jqR0Aa1hYzAP5xdrJeFIpAmx2D75C5K", "gQk7RQxnfZJF3w5iHZCXgzrt6fT2CfrMX3NlVT0kVK55YwI5We", "tu", "vas"};
    char sep[100] = "";
    int i;
    
    char *teste = ft_strjoin(4, test, sep);
    printf("%s\n", teste);
    i = -1;
    while (teste[++i])
    {
        printf("%d : %c\n", i, teste[i]);
    }
    printf("%d : %d\n", i, teste[i] == 0);
    return 0;
}