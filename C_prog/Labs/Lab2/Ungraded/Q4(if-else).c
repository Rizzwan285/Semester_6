int score = 75;
int has_badge = 0;
int status;

if (score > 90 || has_badge)
{
    status = 100;
}
else if (score > 50 && !has_badge)
{
    status = 50;
}
else
{
    status = 0;
}
