/**
 * @file best_json_def.h
 * @author tjl
 * @brief  各类定义
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __BEST_JSON_DEF_H
#define __BEST_JSON_DEF_H

#include <assert.h>
#include <stdlib.h>

#include "best_json.h"


// json 对象内部结构
typedef struct {
    char*       key;
    json_t*     val;
} json_k_t;

// json 数组或对象
typedef struct {
    size_t          size;           // 长度
    union {
        char*       v_s;            // 字符串值
        json_t*     v_a;            // 数组值
        json_k_t*   v_o;            // 对象值
    };
} jsons_t;


// json 结构
typedef struct {
    json_type_e     type;           // 类型
    union {                         // 值
        json_bool   val_b;          // 布尔值
        json_int    val_i;          // 整型值
        json_float  val_f;          // 浮点值
        jsons_t*    val_s;          // 字符串值
        jsons_t*    val_a;          // 数组值
        jsons_t*    val_o;          // 对象值
    };
} json_t;


#define JSON_T_SIZE                     (sizeof(json_t))
#define JSONS_T_SIZE                    (sizeof(jsons_t))
#define JSON_S_SIZE                     (JSON_T_SIZE + JSONS_T_SIZE)

#define JSON_T_CALLOC                   ((json_t*)calloc(1, JSON_T_SIZE))

#define JSON_S_CALLOC(__size)           ((json_t*)calloc(1, JSON_S_SIZE + (__size)))


#endif