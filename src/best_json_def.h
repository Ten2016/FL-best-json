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

#include <stdlib.h>

#include "best_json_type.h"

#define JSON_T_SIZE         (sizeof(json_t))

#define JSON_T_CALLOC       ((json_t*)calloc(1, JSON_T_SIZE))


#endif