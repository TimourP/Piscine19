#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void       ft_show_tab(struct s_stock_str *par);

int main(void)
{
    struct s_stock_str *test;
    char *str[100] = {"6IOxW0k7xIbkYhUdYtv3nc6txE4YVrlD", "OmW4DkATxjl9gr4M", "iR00mGJBMPd4cUxi"};
    test = ft_strs_to_tab(3, str);
    ft_show_tab(test);
    return (0);
}