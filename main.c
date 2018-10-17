#include <stdio.h>
#include <stdlib.h>
#include "choose.h"
#include "initc.h"
#include "inits.h"
int main()
{
    printf("-----------------init-----------------\n");
    printf("========================================\n\n");
    initc();
    inits();
    choose();
    return 0;
}
