/**
 * @file best_json_type.h
 * @author tjl
 * @brief  相关结构定义
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __BEST_JSON_TYPE_H
#define __BEST_JSON_TYPE_H

#define bool_true       (1)
#define bool_false      (0)

// json 布尔类型
typedef int json_bool;

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


typedef struct json_t json_t;


// json 对象内部结构
typedef struct {
    const char* key;
    json_t*     val;
} json_k_t;

// json 数组或对象
typedef struct {
    int size;                   // 结构个数
    union {
        json_t*     val_a;      // 数组值
        json_k_t*   val_o;      // 对象值
    };
} jsons_t;


// json 结构
struct json_t {
    json_type_e type;               // 类型
    union {                         // 值
        json_bool   val_b;          // 布尔值
        json_int    val_i;          // 整型值
        json_float  val_f;          // 浮点值
        const char* val_s;          // 字符串值
        jsons_t*    val_a;          // 数组值
        jsons_t*    val_o;          // 对象值
    };
};


// 获取 json 类型
#define json_type(json) ((json)->type)


#endif
