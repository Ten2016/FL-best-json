#include <stdio.h>
#include <stdlib.h>

#include "best_json.h"

#define JSON_TEXT_FILE      "json_text.txt"

int main()
{
    const char *json_str = "{\"test      \":{\"obj_test\":\"this is test\",\"int_test\":2},     "
                           "\"test_2\":[\"arr_test_1\",\"arr_test_2\"]    }";

    printf("json fmt\nbefore:\n%s\n", json_str);

    char *fmt_str = json_format(json_str, MODE_OBJ_ARR);

    printf("after:\n%s\n", fmt_str);


    // 载入文件
    FILE *fp = fopen(JSON_TEXT_FILE, "rb");
    if (!fp) {
        printf("error: open file faild");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t f_size = ftell(fp);
    rewind(fp);

    char *str_buf = (char *)calloc(1, f_size + 1);
    if (!str_buf) {
        printf("error: calloc failed");
        return 1;
    }

    if (fread(str_buf, 1, f_size, fp) != f_size) {
        printf("error: read file failed");
        return 1;
    }

    printf("\njson fmt\nbefore:\n%s\n", str_buf);

    fmt_str = json_format(str_buf, MODE_OBJ_ARR);

    printf("after:\n%s\n", fmt_str);

    return 0;
}
