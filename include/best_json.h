/**
 * @file        best_json.h
 * @author      tjl
 * @brief       使用时仅需包含此头文件
 * @version     0.1
 * @date        2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __BEST_JSON_H
#define __BEST_JSON_H

// 版本号
#define BJSON_VERSION   "1.0.0"

#include "best_json_def.h"


#define BJSON_DEPTH_MAX     (64)                // json 最大嵌套深度
#define BJSON_CHILD_MAX     (1048576)           // json 下一级子结构最大元素个数

typedef enum {
    MODE_ANY,
    MODE_OBJ_ARR
} fmt_mode_t;

/************************  以下为对外接口  ************************/


// 类型检查
#define json_is_null(json)      ((json) && json_type(json) == json_type_null)
#define json_is_bool(json)      ((json) && json_type(json) == json_type_bool)
#define json_is_int(json)       ((json) && json_type(json) == json_type_int)
#define json_is_float(json)     ((json) && json_type(json) == json_type_float)
#define json_is_string(json)    ((json) && json_type(json) == json_type_string)
#define json_is_array(json)     ((json) && json_type(json) == json_type_array)
#define json_is_object(json)    ((json) && json_type(json) == json_type_object)


// 获取元素





// 序列化json，输出标准字符串
const char *json_dump(const json_t *json);

// 序列化json，输出格式化字符串
const char *json_dump_fmt(const json_t *json);

// 加载json，从字符串读入
json_t *json_load_str(const char *str);

// 加载json，从文件读入
json_t *json_load_file(const char *fname);


// json 字符串格式化
char *json_format(const char *json_str, fmt_mode_t mode);

#endif