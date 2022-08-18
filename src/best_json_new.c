/**
 * @file best_json_new.c
 * @author tjl
 * @brief  构造各类 json 值
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "best_json.h"
#include "best_json_def.h"


json_t* json_new_null()
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_null;

    return json;
}


json_t* json_new_bool(json_bool json_b)
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_bool;
    json->val_b = json_b;

    return json; 
}


json_t* json_new_int(json_int json_i)
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_int;
    json->val_i = json_i;

    return json; 
}


json_t* json_new_float(json_float json_f)
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_float;
    json->val_f = json_f;

    return json; 
}


json_t* json_new_string(const char *json_s)
{
    if (!json_s) {
        return NULL;
    }

    return json_new_string_n(json_s, strlen(json_s));
}


json_t* json_new_string_n(const char *json_s, size_t size)
{
    if (!json_s || size > BJSON_STRING_LEN_MAX) {
        return NULL;
    }

    json_t *json = JSON_S_CALLOC(size);
    if (!json) {
        return NULL;
    }

    json->type = json_type_string;
    json->val_s = json + JSON_T_SIZE;

    json->val_s->size = size;
    json->val_s->v_s = memcpy(json + JSON_S_SIZE, json_s, size);

    return json;
}


json_t* json_new_array()
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_array;
    json->val_a = NULL;

    return json;
}


json_t* json_new_object()
{
    json_t *json = JSON_T_CALLOC;
    if (!json) {
        return NULL;
    }

    json->type = json_type_object;
    json->val_o = NULL;

    return json;    
}


void json_delete(json_t *json)
{
    if (!json) {
        return ;
    }

    
    return ;
}



