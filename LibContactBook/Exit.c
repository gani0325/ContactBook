#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//  ��� �Ҹ� 
void Exit(USERDATA* Head)
{
    free(Head);
}