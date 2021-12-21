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
    json_int,

} type_e;

typedef struct {
    type_e type;
    enum {

    }

} json_t;

const char *json_dump();

json_t *json_load_str(const char *str);

json_t *json_load_file(const char *fname);



#endif