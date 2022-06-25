#include <stdio.h>
#include <stdlib.h>

#include "best_json.h"


int main()
{
    const char *json_str = "{\"test\":{\"obj_test\":\"this is test\",\"int_test\":2},"
                           "\"test_2\":[\"arr_test_1\",\"arr_test_2\"]}";

    printf("json fmt\nbefore:\n%s\n", json_str);

    char *fmt_str = json_format(json_str, MODE_OBJ_ARR);

    printf("after:\n%s\n", fmt_str);

    return 0;
}
