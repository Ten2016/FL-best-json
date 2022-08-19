/**
 * @file best_json_copy.c
 * @author tjl
 * @brief  拷贝、合并相关操作
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "best_json.h"
#include "best_json_def.h"


static json_t* json_deep_copy_1(const json_t *json)
{
    assert(json);

    json_t *json_copy = JSON_T_CALLOC;
    if (!json_copy) {
        return NULL;
    }

    memcpy(json_copy, json, JSON_T_SIZE);

    return json_copy;
}


static json_t* json_deep_copy_2(const json_t *json)
{
    assert(json);

    if (!(json->val_s)) {
        return NULL;
    }
    if (json->val_s->size == 0 || !(json->val_s->v_s)) {
        return NULL;
    }

    json_t *json_copy = JSON_S_CALLOC(json->val_s->size);
    if (!json_copy) {
        return NULL;
    }

    memcpy(json_copy, json, JSON_S_SIZE + json->val_s->size);

    json_copy->val_s = json_copy + JSON_T_SIZE;
    json_copy->val_s->v_s = json_copy + JSON_S_SIZE;

    return json_copy;
}


static json_t* json_deep_copy_3(const json_t *json)
{
    assert(json);

    json_t *json_copy = JSON_T_CALLOC;
    if (!json_copy) {
        return NULL;
    }

    memcpy(json_copy, json, JSON_T_SIZE);

    switch()

    return json_copy;
}


static json_t* json_deep_copy_2(const json_t *json)
{




// 深拷贝
json_t* json_deep_copy(const json_t *json)
{
    if (!json) {
        return NULL;
    }

    switch (json->type) {
        case json_type_null:
        case json_type_bool:
        case json_type_int:
        case json_type_float:
            return json_deep_copy_1(json);

        case json_type_string:
            return json_deep_copy_2(json);
        
        case json_type_array:
        case json_type_object:
            return json_deep_copy_3(json);
        
        default:
            break;
    }

    return NULL;
}


// 合并
json_t* json_merge_array(const json_t *json_src, json_t *json_dst)
{

}




json_t* json_merge_object(const json_t *json_src, json_t *json_dst)
{

}