/**
 * @file        best_json.h
 * @author      tjl
 * @brief       非常轻量的json库
 * @version     0.1
 * @date        2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __BEST_JSON_H
#define __BEST_JSON_H

typedef enum {
    json_null,
    json_int

} type_e;

typedef struct {
    type_e type;
    const char *key;
    union {
        long integer;
        double number;
        char *string;
    };

} json_t;

// 序列化json，输出标准字符串
const char *json_dump(const json_t *json);

// 序列化json，输出格式化字符串
const char *json_dump_fmt(const json_t *json);

// 加载json，从字符串读入
json_t *json_load_str(const char *str);

// 加载json，从文件读入
json_t *json_load_file(const char *fname);



#endif