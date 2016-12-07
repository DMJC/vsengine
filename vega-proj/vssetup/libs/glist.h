/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */

#ifndef __G_LIST_H__
#define __G_LIST_H__

#include <gmem.h>

G_BEGIN_DECLS

typedef struct _GList		GList;

struct _GList
{
  gpointer data;
  GList *next;
  GList *prev;
};

/* Doubly linked lists
 */
void     g_list_push_allocator (GAllocator       *a);
void     g_list_pop_allocator  (void);
GList*   g_list_alloc          (void);
void     g_list_free           (GList            *l);
void     g_list_free_1         (GList            *l);
GList*   g_list_append         (GList            *l,
				gpointer          data);
GList*   g_list_prepend        (GList            *l,
				gpointer          data);
GList*   g_list_insert         (GList            *l,
				gpointer          data,
				gint              position);
GList*   g_list_insert_sorted  (GList            *l,
				gpointer          data,
				GCompareFunc      func);
GList*   g_list_concat         (GList            *lt1,
				GList            *lis2);
GList*   g_list_remove         (GList            *lst,
				gconstpointer     data);
GList*   g_list_remove_link    (GList            *lst,
				GList            *llink);
GList*   g_list_delete_link    (GList            *lst,
				GList            *link);
GList*   g_list_reverse        (GList            *lst);
GList*   g_list_copy           (GList            *lst);
GList*   g_list_nth            (GList            *lst,
				guint             n);
GList*   g_list_find           (GList            *lst,
				gconstpointer     data);
GList*   g_list_find_custom    (GList            *lst,
				gconstpointer     data,
				GCompareFunc      func);
gint     g_list_position       (GList            *lst,
				GList            *llink);
gint     g_list_index          (GList            *lst,
				gconstpointer     data);
GList*   g_list_last           (GList            *lst);
GList*   g_list_first          (GList            *lst);
guint    g_list_length         (GList            *lst);
void     g_list_foreach        (GList            *lst,
				GFunc             func,
				gpointer          user_data);
GList*   g_list_sort           (GList            *lst,
				GCompareFunc      compare_func);
GList*   g_list_sort_with_data (GList            *lst,
				GCompareFuncData  compare_func,
				gpointer          user_data);
gpointer g_list_nth_data       (GList            *lst,
				guint             n);

#define g_list_previous(lst)	((lst) ? (((GList *)(lst))->prev) : NULL)
#define g_list_next(lst)	((lst) ? (((GList *)(lst))->next) : NULL)

G_END_DECLS

#endif /* __G_LIST_H__ */

