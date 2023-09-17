#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//  ³ëµå ¼Ò¸ê 
void Exit(USERDATA* Head)
{
    USERDATA* Current = Head;

    while (Current->pNext != NULL) {
        free(Current);
    }
    
}