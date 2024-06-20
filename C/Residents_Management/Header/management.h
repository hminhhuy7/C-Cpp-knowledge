/*
* File: management.h
* Author: Nguyen Huynh Minh Huy
* Date: 15/01/2024
* Description: This is a header file to declare for managemant.c 
*/

#ifndef _MANAGEMENT_H
#define _MANAGEMENT_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct 
{
    char uId[20];
    char roomNumber[10]; 
    char name[50]; 
    char licensePlate[20];
} Member;

typedef struct MemberNode 
{
    Member data;
    struct MemberNode* next;
} MemberNode;

typedef enum{
    UID,
    LICENSE_PLATE
}Type;

MemberNode* createMemberNode(Member member);
void addMember(const char* filename, Member member);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember, const char* uid);
int searchByUID(const Member* member, const char* uid);
int searchByLicensePlate(const Member* member, const char* licensePlate);
Member searchMember(const char* filename, const char* searchValue, int (*function)(const Member*, const char*));

#endif