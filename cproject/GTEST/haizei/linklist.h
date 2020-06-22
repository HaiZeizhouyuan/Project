/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: Thu Jun 18 19:49:20 2020
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) ((long long)(&(((T *)(0))->name)))
#define Head(p, T, name) ((T *)(((char *)p ) - offset(T, name)))

typedef struct LinkNode {
    struct LinkNode *next;//这样可以不跟链表走
}Node;

#endif
