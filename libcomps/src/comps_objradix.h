/* libcomps - C alternative to yum.comps library
 * Copyright (C) 2013 Jindrich Luza
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to  Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA
 */

#ifndef COMPS_OBJRADIX_H
#define COMPS_OBJRADIX_H

#include <stdlib.h>
#include <string.h>
#include "comps_hslist.h"
#include "comps_obj.h"

typedef struct {
    char *key;
    unsigned is_leaf;
    COMPS_HSList *subnodes;
    COMPS_Object *data;
} COMPS_ObjRTreeData;

typedef struct {
    COMPS_HSList *subnodes;
    unsigned int len;
} COMPS_ObjRTree;

typedef struct {
    char *key;
    COMPS_Object *data;
} COMPS_ObjRTreePair;

COMPS_ObjRTreeData* __comps_objrtree_data_create(char *key,
                                                  unsigned int keylen,
                                                  COMPS_Object *data);
COMPS_HSList* __comps_objrtree_all(COMPS_ObjRTree *rt, char pairorkey);

void comps_objrtree_data_destroy(COMPS_ObjRTreeData *rtd);
void comps_objrtree_data_destroy_v(void *rtd);

COMPS_ObjRTreeData* comps_objrtree_data_create(char *key,
                                               COMPS_Object *data);
COMPS_ObjRTreeData* comps_objrtree_data_create_n(char *key,
                                                 unsigned int len,
                                                 COMPS_Object *data);

COMPS_ObjRTree* comps_objrtree_create(void* (*data_constructor)(void*),
                                 void* (*data_cloner)(void*),
                                 void (*data_destructor)(void*));
void comps_objrtree_destroy(COMPS_ObjRTree *rt);

void comps_objrtree_set(COMPS_ObjRTree *rt, char *key, COMPS_Object *data);
void comps_objrtree_set_n(COMPS_ObjRTree *rt, char *key, unsigned int len,
                          COMPS_Object *data);

void* comps_objrtree_get(COMPS_ObjRTree *rt, const char *key);
void comps_objrtree_unset(COMPS_ObjRTree *rt, const char *key);
void comps_objrtree_clear(COMPS_ObjRTree *rt);

void comps_objrtree_values_walk(COMPS_ObjRTree *rt, void* udata,
                                               void (*walk_f)(void*, void*));
COMPS_HSList* comps_objrtree_values(COMPS_ObjRTree *rt);
COMPS_HSList* comps_objrtree_keys(COMPS_ObjRTree *rt);
COMPS_HSList* comps_objrtree_pairs(COMPS_ObjRTree *rt);
COMPS_ObjRTree* comps_objrtree_clone(COMPS_ObjRTree *rt);
COMPS_ObjRTree* comps_objrtree_union(COMPS_ObjRTree *rt1, COMPS_ObjRTree *rt2);
void comps_objrtree_unite(COMPS_ObjRTree *rt1, COMPS_ObjRTree *rt2);
COMPS_ObjRTree* comps_objrtree_union(COMPS_ObjRTree *rt1, COMPS_ObjRTree *rt2);

COMPS_ObjRTreePair* comps_objrtree_pair_create(char *key, void *data,
                                          void (*data_destructor(void*)));
void comps_objrtree_pair_destroy(COMPS_ObjRTreePair *pair);
void comps_objrtree_pair_destroy_v(void *pair);

extern COMPS_ObjectInfo COMPS_ObjRTree_ObjInfo;

#endif