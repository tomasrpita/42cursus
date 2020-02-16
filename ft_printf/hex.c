//*************************************************************
// void prntnum(unsigned long n, int base, char sign, char *outbuf)
// unsigned long num = number to be printed
// int base        = number base for conversion;  decimal=10,hex=16
// char sign       = signed or unsigned output
// char *outbuf   = buffer to hold the output number
//*************************************************************

static void prntnum(unsigned long num, int base, char sign, char *outbuf)
{

    int i = 12;
    int j = 0;

    do{
        outbuf[i] = "0123456789ABCDEF"[num % base];
        i--;
        num = num/base;
    }while( num > 0);

    if(sign != ' '){
        outbuf[0] = sign;
        ++j;
    }

    while( ++i < 13){
       outbuf[j++] = outbuf[i];
    }

    outbuf[j] = 0;

}

int     itoh(int n)
{

    int quotient;
    int remainder;
    int i;
    int j;
    char hex[100];

    quotient = n;
    j = 0;
    i = 0;
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++] = 55 + remainder;
        quotient = quotient / 16;
    }












}
