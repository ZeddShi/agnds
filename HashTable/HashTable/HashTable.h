//
//  HashTable.h
//  HashTable
//
//  Created by Zedd on 2017/10/28.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#pragma once
typedef struct HashTable HashTable;

#ifdef __cplusplus
extern "C" {
#endif
    
    /* new an instance of HashTable */
    HashTable* hash_table_new(void);
    
    /*
     delete an instance of HashTable,
     all values are removed auotmatically.
     */
    void hash_table_delete(HashTable* ht);
    
    /*
     add or update a value to ht,
     free_value(if not NULL) is called automatically when the value is removed.
     return 0 if success, -1 if error occurred.
     */
#define hash_table_put(ht,key,value) hash_table_put2(ht,key,value,NULL);
    int hash_table_put2(HashTable* ht, char* key, void* value, void(*free_value)(void*));
    
    /* get a value indexed by key, return NULL if not found. */
    void* hash_table_get(HashTable* ht, char* key);
    
    /* remove a value indexed by key */
    void hash_table_rm(HashTable* ht, char* key);
    
#ifdef __cplusplus
}
#endif

#endif /* HashTable_h */
