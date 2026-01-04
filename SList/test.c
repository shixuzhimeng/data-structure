#include "SList.h"

void Test()
{
    SLTNode* plist = NULL;
    SLTPushBack(&plist,1);

    SLTPrintf(plist);
}

int main()
{

    return 0;
}