#include "stdio.h"
#include "DATA_TYPES.h"
#include "stdlib.h"

extern u8 count_entries;

typedef enum {true, false} bool ;

struct data
{
    u32 student_ID;
    u32 student_Year;
    u32 subjects[3];
    u32 grades [3];
    struct data *next;
};

bool SDB_IsFull(void);
u8 SDB_GetUsedSize(void);
bool SDB_AddEntry(u32 id, u32 year, u32*subjects, u32* grades);
void SDB_DeleteEntry(u32 id);
bool SDB_ReadEntry(u32 id);
void SDB_GetList(void);
bool SDB_IsIdExist(u32 id);
