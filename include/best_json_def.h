/**
 * @file best_json_def.h
 * @author tjl
 * @brief  相关结构定义
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __BEST_JSON_DEF_H
#define __BEST_JSON_DEF_H


// json 整型类型
typedef long long json_int;

// json 浮点类型
typedef double json_float;


// json 类型
typedef enum {
    json_type_null,                  // 空值
    json_type_bool,                  // bool 值
    json_type_int,                   // 整型值[64位]
    json_type_float,                 // 浮点值[64位]
    json_type_string,                // 字符串
    json_type_array,                 // 数组
    json_type_object,                // 对象
    json_type_max,
} json_type_e;


typedef struct json_t;


// json 数组或对象集合
typedef struct {
    json_t *val_j;              // json 结构
    int size;                   // 结构个数
} jsons_t;


// json 结构
typedef struct {
    json_type_e type;               // json 类型
    const char *key;                // 键值
    union {                         // 值类型
        int val_b;                  // bool 值
        json_int val_i;             // 整型值
        json_float val_f;           // 浮点值
        const char *val_s;          // 字符串值
        jsons_t *val_a;              // 数组值
        jsons_t *val_o;              // 对象值
    };
} json_t;


// 获取 json 类型
#define json_type(json) ((json)->type)



#endif
