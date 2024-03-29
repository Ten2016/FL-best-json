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

#include <stddef.h>



#define BJSON_VERSION           "1.0.0"             // 版本号
#define BJSON_VERSION_MAJOR     (1)
#define BJSON_VERSION_MINOR     (0)
#define BJSON_VERSION_PATCH     (0)


#define BJSON_DEPTH_MAX         (64)                // json 最大嵌套深度
#define BJSON_CHILD_MAX         (1024 * 1024)       // json 下一级子结构最大元素个数

#define BJSON_STRING_LEN_MAX    (1024 * 1024)       // 字符串最大长度



// json 布尔类型
typedef int json_bool;
#define bool_true               (1)
#define bool_false              (0)

// json 整型类型
typedef long long json_int;

// json 浮点类型
typedef double json_float;

// json 结构
typedef struct json_t json_t;

// json 类型
typedef enum {
    json_type_null,                  // 空值
    json_type_bool,                  // 布尔值
    json_type_int,                   // 整型值[64位]
    json_type_float,                 // 浮点值[64位]
    json_type_string,                // 字符串
    json_type_array,                 // 数组
    json_type_object,                // 对象
    json_type_max,
} json_type_e;



typedef enum {
    MODE_ANY,
    MODE_OBJ_ARR
} fmt_mode_t;


// 错误码
typedef enum {
    json_success = 0,
    json_err_param_invalid_1 = 1,
    json_err_param_invalid_2 = 2,
    json_err_param_invalid_3 = 3,
    json_err_memory_insufficient = 4,
    json_err_depth_max = 5,
    json_err_child_max = 6,
    json_err_string_max = 7,
} json_code_e;


/************************  以下为对外接口  ************************/


// 类型检查
#define json_type(json)         ((json)->type)
#define json_is_null(json)      ((json) && json_type(json) == json_type_null)
#define json_is_bool(json)      ((json) && json_type(json) == json_type_bool)
#define json_is_int(json)       ((json) && json_type(json) == json_type_int)
#define json_is_float(json)     ((json) && json_type(json) == json_type_float)
#define json_is_string(json)    ((json) && json_type(json) == json_type_string)
#define json_is_array(json)     ((json) && json_type(json) == json_type_array)
#define json_is_object(json)    ((json) && json_type(json) == json_type_object)


// 构造
json_t* json_new_null();
json_t* json_new_bool(json_bool json_b);
json_t* json_new_int(json_int json_i);
json_t* json_new_float(json_float json_f);
json_t* json_new_string(const char *json_s);
json_t* json_new_string_n(const char *json_s, size_t size);
json_t* json_new_array();
json_t* json_new_object();


// 添加

json_code_e json_array_add_null(json_t *json,   const json_t *json_n);
json_code_e json_array_add_bool(json_t *json,   const json_t *json_b);
json_code_e json_array_add_int(json_t *json,    const json_t *json_i);
json_code_e json_array_add_float(json_t *json,  const json_t *json_f);
json_code_e json_array_add_string(json_t *json, const json_t *json_s);
json_code_e json_array_add_array(json_t *json,  const json_t *json_a);
json_code_e json_array_add_object(json_t *json, const json_t *json_o);

json_code_e json_object_add_null(json_t *json,   const char *key, const json_t *json_n);
json_code_e json_object_add_bool(json_t *json,   const char *key, const json_t *json_b);
json_code_e json_object_add_int(json_t *json,    const char *key, const json_t *json_i);
json_code_e json_object_add_float(json_t *json,  const char *key, const json_t *json_f);
json_code_e json_object_add_string(json_t *json, const char *key, const json_t *json_s);
json_code_e json_object_add_array(json_t *json,  const char *key, const json_t *json_a);
json_code_e json_object_add_object(json_t *json, const char *key, const json_t *json_o);


// 删除
json_code_e json_array_delete(json_t *json, size_t index);
json_code_e json_object_delete(json_t *json, const char *key);

// 清空
void json_delete(json_t *json);
void json_array_clear(json_t *json);
void json_object_clear(json_t *json);



// 深拷贝
json_code_e json_deep_copy(const json_t *json);


// 合并
json_code_e json_merge_array(const json_t *json_dst, json_t *json_src);
json_code_e json_merge_object(const json_t *json_dst, json_t *json_src);


// 遍历






// 序列化json，输出简化字符串
const char* json_dump_simple(const json_t *json);

// 序列化json，输出格式化字符串
const char* json_dump_format(const json_t *json);

// 加载json，从字符串读入
json_t* json_load_str(const char *str);
json_t* json_load_str_n(const char *str, size_t size);

// 加载json，从文件读入
json_t* json_load_file(const char *fname);


// json 字符串格式化
char* json_str_format(const char *json_str, fmt_mode_t mode);

#endif