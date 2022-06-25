/**
 * @file        best_json.c
 * @author      tjl
 * @brief       非常轻量的json库
 * @version     0.1
 * @date        2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


#include "best_json.h"


#define BJSON_SPACE_LEN     (4)


/**
 * @brief 序列化json，输出标准字符串
 * 
 * @param json 
 * @return const char* 
 */
const char *json_dump(const json_t *json)
{


    return NULL;
}


/**
 * @brief 序列化json，输出格式化字符串
 * 
 * @param json 
 * @return const char* 
 */
const char *json_dump_fmt(const json_t *json)
{



    return NULL;
}


/**
 * @brief 加载json，从字符串读入
 * 
 * @param str 
 * @return json_t* 
 */
json_t *json_load_str(const char *str)
{



    return NULL;
}


/**
 * @brief 加载json，从文件读入
 * 
 * @param fname 
 * @return json_t* 
 */
json_t *json_load_file(const char *fname)
{



    return NULL;
}


/**
 * @brief 添加字符
 * 
 * @param p_str     [in] 待添加的字符串地址 
 * @param c         [in] 待添加的字符
 * @param number    [in] 添加的数量
 * @return char* 添加后的字符串地址
 */
static char *append_char(char *p_str, char c, int number)
{
    assert(p_str);
    
    while (number) {
        *p_str = c;
        p_str++;
        number--;
    }

    return p_str;
}


/**
 * @brief 添加空格
 * 
 * @param p_str     [in] 待添加的字符串地址 
 * @param number    [in] 添加的数量
 * @return char*    添加后的字符串地址
 */
static char *append_space(char *p_str, int number)
{
    return append_char(p_str, ' ', number);
}


/**
 * @brief 格式化
 * 
 * @param old_str       [in] 格式化前字符串
 * @param new_str       [out] 格式化后字符串
 * @param c             [in] 当前结构
 * @param curr_depth    [in] 当亲深度
 * @return int 转换结果
 */
static int json_format_(const char **old_str, char **new_str, char c, int curr_depth)
{
    assert(old_str);
    assert(new_str);

    if (**old_str == '\0') {
        return 0;
    }

    char struct_c = c;

    if (**old_str == '{' || **old_str == '[') {
        struct_c = **old_str;

        *new_str = append_space(*new_str, 1);

        **new_str = struct_c;
        (*new_str)++;

        **new_str = '\n';
        (*new_str)++;

        curr_depth++;
        *new_str = append_space(*new_str, curr_depth * BJSON_SPACE_LEN);

        (*old_str)++;
    }
    else if (**old_str == '}' || **old_str == ']') {

        struct_c = **old_str;

        curr_depth--;

        **new_str = '\n';
        (*new_str)++;

        *new_str = append_space(*new_str, curr_depth * BJSON_SPACE_LEN);

        **new_str = struct_c;
        (*new_str)++;

        **new_str = '\n';
        (*new_str)++;

        (*old_str)++;
    }
    else if (**old_str == ',') {
        **new_str = **old_str;
        (*new_str)++;

        **new_str = '\n';
        (*new_str)++;

        *new_str = append_space(*new_str, curr_depth * BJSON_SPACE_LEN);
        (*old_str)++;
    }
    else {
        **new_str = **old_str;
        (*new_str)++;
        (*old_str)++;
    }

    return json_format_(old_str, new_str, struct_c, curr_depth);
}

/**
 * @brief json 字符串格式化
 * 
 * @param json_str  [in] 待格式化的字符串
 * @param mode      [in] 模式
 * @return char* 格式化后的字符串
 */
char *json_format(const char *json_str, fmt_mode_t mode)
{
    if (!json_str) {
        return NULL;
    }

    const char *old_str = json_str;
    if (old_str[0] != '[' && old_str[0] != '{') {
        if (mode != MODE_ANY) {
            return NULL;
        }
    }

    int res_len = strlen(json_str);
    char *ret_str = (char *)calloc(1, res_len * 100);

    int curr_depth = 0;
    char *new_str = ret_str;
    if (json_format_(&old_str, &new_str, '-', curr_depth) != 0) {
        free(ret_str);
        return NULL;
    }

    return ret_str;
}