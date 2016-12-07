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

#ifndef __G_SLIST_H__
#define __G_SLIST_H__

#include <gmem.h>

G_BEGIN_DECLS

typedef struct _GSList		GSList;

struct _GSList
{
  gpointer data;
  GSList *next;
};

/* Singly linked lists
 */
void     g_slist_push_allocator (GAllocator       *alocator);
void     g_slist_pop_allocator  (void);
GSList*  g_slist_alloc          (void);
void     g_slist_free           (GSList           *lst);
void     g_slist_free_1         (GSList           *lst);
GSList*  g_slist_append         (GSList           *lst,
				 gpointer          data);
GSList*  g_slist_prepend        (GSList           *lst,
				 gpointer          data);
GSList*  g_slist_insert         (GSList           *lst,
				 gpointer          data,
				 gint              position);
GSList*  g_slist_insert_sorted  (GSList           *lst,
				 gpointer          data,
				 GCompareFunc      func);
GSList*  g_slist_insert_before  (GSList           *sist,
				 GSList           *siling,
				 gpointer          daa);
//GSList*  g_slist_concat         (GSList           *lst1,
//				 GSList           *lst2);
GSList*  g_slist_remove         (GSList           *lst,
				 gconstpointer     data);
GSList*  g_slist_remove_link    (GSList           *lst,
				 GSList           *link);
GSList*  g_slist_delete_link    (GSList           *lst,
				 GSList           *link);
GSList*  g_slist_reverse        (GSList           *lst);
GSList*  g_slist_copy           (GSList           *lst);
GSList*  g_slist_nth            (GSList           *lst,
				 guint             n);
GSList*  g_slist_find           (GSList           *lst,
				 gconstpointer     data);
GSList*  g_slist_find_custom    (GSList           *lst,
				 gconstpointer     data,
				 GCompareFunc      func);
gint     g_slist_position       (GSList           *lst,
				 GSList           *llink);
gint     g_slist_index          (GSList           *lst,
				 gconstpointer     data);
GSList*  g_slist_last           (GSList           *lst);
guint    g_slist_length         (GSList           *lst);
void     g_slist_foreach        (GSList           *lst,
				 GFunc             func,
				 gpointer          user_data);
GSList*  g_slist_sort           (GSList           *lst,
				 GCompareFunc      compare_func);
GSList*  g_slist_sort_with_data (GSList           *lst,
				 GCompareFuncData  compare_func,
				 gpointer          user_data);
gpointer g_slist_nth_data       (GSList           *lst,
				 guint             n);
#define  g_slist_next(slist)	((slist) ? (((GSList *)(slist))->next) : NULL)

G_END_DECLS

#endif /* __G_SLIST_H__ */

