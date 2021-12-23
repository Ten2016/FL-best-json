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


#include <stddef.h>


#include "best_json.h"



/**
 * @brief 序列化json，输出标准字符串
 * 
 * @param json 
 * @return const char* 
 */
const char *json_dump(const json_t *json) {


    return NULL;
}


/**
 * @brief 序列化json，输出格式化字符串
 * 
 * @param json 
 * @return const char* 
 */
const char *json_dump_fmt(const json_t *json) {



    return NULL;
}


/**
 * @brief 加载json，从字符串读入
 * 
 * @param str 
 * @return json_t* 
 */
json_t *json_load_str(const char *str) {



    return NULL;
}


/**
 * @brief 加载json，从文件读入
 * 
 * @param fname 
 * @return json_t* 
 */
json_t *json_load_file(const char *fname) {



    return NULL;
}