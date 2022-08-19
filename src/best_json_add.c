/**
 * @file best_json_add.c
 * @author tjl
 * @brief  添加、删除相关操作
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "best_json.h"
#include "best_json_def.h"



// 添加
json_code_e json_object_add_null(json_t *json, const char *key, const json_t *json_n)
{





}








json_code_e json_object_add_bool(json_t *json,   const char *key, const json_t *json_b);
json_code_e json_object_add_int(json_t *json,    const char *key, const json_t *json_i);
json_code_e json_object_add_float(json_t *json,  const char *key, const json_t *json_f);
json_code_e json_object_add_string(json_t *json, const char *key, const json_t *json_s);
json_code_e json_object_add_array(json_t *json,  const char *key, const json_t *json_a);
json_code_e json_object_add_object(json_t *json, const char *key, const json_t *json_o);

json_code_e json_array_add_null(json_t *json,   const json_t *json_n);
json_code_e json_array_add_bool(json_t *json,   const json_t *json_b);
json_code_e json_array_add_int(json_t *json,    const json_t *json_i);
json_code_e json_array_add_float(json_t *json,  const json_t *json_f);
json_code_e json_array_add_string(json_t *json, const json_t *json_s);
json_code_e json_array_add_array(json_t *json,  const json_t *json_a);
json_code_e json_array_add_object(json_t *json, const json_t *json_o);


// 删除
json_code_e json_array_delete(json_t *json, size_t index);
json_code_e json_object_delete(json_t *json, const char *key);

