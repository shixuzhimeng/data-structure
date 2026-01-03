#include "SeqList.h"

int main()
{
	SL s;
	SeqInit(&s);
    int option = 0;
    while(option != -1)
    {
	    scanf("%d",&option);
	    if(option == 1)
	    {
		    int x = 0;
		    printf("输入要存的数据：以-1结束");
		    while(x!=-1)
		    {
			    scanf("%d",&x);
			    SeqPushBack(&s,x);
		    }
	    }
	    else if(option == 2)
	    {
		    SeqPrint(&s);
	    }
    }

    return 0;
}