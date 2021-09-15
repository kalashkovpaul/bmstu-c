#ifndef _GOOD_H_

#define _GOOD_H_

#define NAME_LENGTH 31
#define MAKER_LENGTH 16

typedef struct
{
    char name[NAME_LENGTH];
    char maker[MAKER_LENGTH];
    unsigned price;
    unsigned amount;
} the_good;

#endif