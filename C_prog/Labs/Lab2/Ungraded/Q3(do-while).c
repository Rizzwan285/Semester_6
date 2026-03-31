int t_minus = 10;
int skip_check = 4;

do
{
    if (t_minus == skip_check)
    {
        t_minus--;
        continue;
    }

    printf("T-minus %d\n", t_minus);
    t_minus -= 2;

} while (t_minus > 0);