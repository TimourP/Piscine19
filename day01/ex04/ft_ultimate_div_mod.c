


void ft_ultimate_div_mod(int * a, int * b)
{
    int fidiv;
    int fimod;
    fidiv = *a / *b;
    fimod = *a % *b;
    *a = fidiv;
    *b = fimod;
}