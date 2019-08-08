

#include "list.h"
#include <assert.h>

typedef struct CountIndex_s{
    struct dl_list head;
    int count;
}CountIndex_t;

typedef struct CountIndexInfo_s{
    struct dl_list next;
    int index;
}CountIndexInfo_t;

void test1()
{
    CountIndex_t *SCountList = (CountIndex_t *)calloc(1, sizeof(CountIndex_t));
    assert( NULL != SCountList);

    dl_list_init(&(SCountList->head));

    int i = 0;
    for (; i < 10; ++i)
    {
        CountIndexInfo_t *SNewCountListInfo = (CountIndexInfo_t *)calloc(1, sizeof(CountIndexInfo_t));
        assert(NULL != SNewCountListInfo);

        SNewCountListInfo->index = i;

        //dl_list_add_tail(&(SCountList->head), &(SNewCountListInfo->next));
        dl_list_add(&(SCountList->head), &(SNewCountListInfo->next));
        SCountList->count++;
    }

    CountIndexInfo_t *item;
    CountIndexInfo_t *n = NULL;
    dl_list_for_each_safe(item, n, &SCountList->head, CountIndexInfo_t, next)
    {
        printf("index=%d\n", item->index);
    }
}

int main()
{
    test1();
    return 0;
}