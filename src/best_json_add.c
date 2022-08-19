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

static json_code_e json_array_add(json_t *json, const json_t *json_e)
{
    if (!json || !json->val_a) {
        return json_err_param_invalid_1;
    }
    if (!json_e) {
        return json_err_param_invalid_2;
    }

    jsons_t *array = json->val_a;
    if (array->size >= BJSON_CHILD_MAX) {
        return json_err_child_max;
    }

    json_a_t *elem = JSON_A_CALLOC;
    if (!elem) {
        return json_err_memory_insufficient;
    }

    elem->val = json_e;
    elem->next = array->v_a;

    array->v_a = elem;
    array->size++;

    return json_success;
}


static json_code_e json_object_add(json_t *json, const char *key, const json_t *json_e)
{
    if (!json || !json->val_o) {
        return json_err_param_invalid_1;
    }
    if (!key) {
        return json_err_param_invalid_2;
    }
    if (!json_e) {
        return json_err_param_invalid_3;
    }

    jsons_t *object = json->val_o;
    if (object->size >= BJSON_CHILD_MAX) {
        return json_err_child_max;
    }

    size_t key_size = strlen(key);
    json_o_t *elem = JSON_O_CALLOC(key_size + 1);
    if (!elem) {
        return json_err_memory_insufficient;
    }

    elem->val = json_e;
    elem->next = object->v_o;
    memcpy(elem->key, key, key_size);

    object->v_o = elem;
    object->size++;

    return json_success;
}


json_code_e json_array_add_null(json_t *json, const json_t *json_n)
{
    return json_array_add(json, json_n);
}


json_code_e json_array_add_bool(json_t *json,   const json_t *json_b)
{
    return json_array_add(json, json_b);
}


json_code_e json_array_add_int(json_t *json,    const json_t *json_i)
{
    return json_array_add(json, json_i);
}


json_code_e json_array_add_float(json_t *json,  const json_t *json_f)
{
    return json_array_add(json, json_f);
}


json_code_e json_array_add_string(json_t *json, const json_t *json_s)
{
    return json_array_add(json, json_s);
}


json_code_e json_array_add_array(json_t *json,  const json_t *json_a)
{
    return json_array_add(json, json_a);
}


json_code_e json_array_add_object(json_t *json, const json_t *json_o)
{
    return json_array_add(json, json_o);
}


json_code_e json_object_add_null(json_t *json, const char *key, const json_t *json_n)
{
    return json_object_add(json, key, json_n);
}


json_code_e json_object_add_bool(json_t *json,   const char *key, const json_t *json_b)
{
    return json_object_add(json, key, json_b);
}


json_code_e json_object_add_int(json_t *json,    const char *key, const json_t *json_i)
{
    return json_object_add(json, key, json_i);
}


json_code_e json_object_add_float(json_t *json,  const char *key, const json_t *json_f)
{
    return json_object_add(json, key, json_f);
}


json_code_e json_object_add_string(json_t *json, const char *key, const json_t *json_s)
{
    return json_object_add(json, key, json_s);
}


json_code_e json_object_add_array(json_t *json,  const char *key, const json_t *json_a)
{
    return json_object_add(json, key, json_a);
}


json_code_e json_object_add_object(json_t *json, const char *key, const json_t *json_o)
{
    return json_object_add(json, key, json_o);
}




// 删除
json_code_e json_array_delete(json_t *json, size_t index)
{

}


json_code_e json_object_delete(json_t *json, const char *key);


// 清空
void json_array_clear(json_t *json);
void json_object_clear(json_t *json);