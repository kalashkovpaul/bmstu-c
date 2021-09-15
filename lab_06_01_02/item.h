#ifndef _ITEM_H_

#define _ITEM_H_

#define NAME_LENGTH 25

typedef struct 
{
    char name[NAME_LENGTH + 1];
    double mass;
    double volume;
} item;

#endif