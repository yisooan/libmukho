/*
 * Copyright 2018 Yi-Soo An <yisooan@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GLS2_HANDLE_H
#define GLS2_HANDLE_H

#if !defined (__GLS2_HEADER_INCLUDE__) && !defined (GLS2_COMPILATION)
#   error "Only <gls2/gls2.h> can be included directly!"
#endif

#include <glib.h>
#include <glib-object.h>
#include <luna-service2/lunaservice.h>

G_BEGIN_DECLS

typedef struct _Gls2Handle             Gls2Handle;
typedef struct _Gls2HandleClass        Gls2HandleClass;
typedef struct _Gls2HandlePrivate      Gls2HandlePrivate;

G_DEFINE_AUTOPTR_CLEANUP_FUNC (Gls2Handle, g_object_unref)

#define GLS2_TYPE_HANDLE                (gls2_handle_get_type ())
#define GLS2_HANDLE(obj)                (G_TYPE_CHECK_INSTANCE_CAST(obj, \
                                         GLS2_TYPE_HANDLE, Gls2Handle))
#define GLS2_HANDLE_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST(klass, \
                                         GLS2_TYPE_HANDLE, Gls2HandleClass))
#define GLS2_IS_HANDLE(obj)             (G_TYPE_CHECK_INSTANCE_TYPE(obj, \
                                         GLS2_TYPE_HANDLE))
#define GLS2_IS_HANDLE_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE(klass, \
                                         GLS2_TYPE_HANDLE))
#define GLS2_HANDLE_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS(obj, \
                                         GLS2_TYPE_HANDLE, Gls2HandleClass))

GType               gls2_handle_get_type                    (void);

Gls2Handle *        gls2_handle_new                         (const gchar    *service_name);
Gls2Handle *        gls2_handle_new_with_application_id     (const gchar    *service_name,
                                                             const gchar    *application_id);

const LSHandle *    gls2_handle_get_lshandle                (Gls2Handle    *self);
const gchar *       gls2_handle_get_service_name            (Gls2Handle    *self);
gchar *             gls2_handle_dup_service_name            (Gls2Handle    *self);
const gchar *       gls2_handle_get_application_id          (Gls2Handle    *self);
gchar *             gls2_handle_dup_application_id          (Gls2Handle    *self);

G_END_DECLS

#endif
