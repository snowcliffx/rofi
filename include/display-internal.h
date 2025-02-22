/*
 * rofi
 *
 * MIT/X11 License
 * Copyright © 2013-2020 Qball Cow <qball@gmpclient.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef ROFI_DISPLAY_INTERNAL_H
#define ROFI_DISPLAY_INTERNAL_H

#include "display.h"
#include "helper.h"
#include "nkutils-bindings.h"
#include <glib.h>

struct _workarea;
struct _view_proxy;

typedef struct _display_proxy {
  gboolean (*setup)(GMainLoop *main_loop, NkBindings *bindings);
  gboolean (*late_setup)(void);
  void (*early_cleanup)(void);
  void (*cleanup)(void);
  void (*dump_monitor_layout)(void);
  void (*startup_notification)(RofiHelperExecuteContext *context,
                               GSpawnChildSetupFunc *child_setup,
                               gpointer *user_data);
  int (*monitor_active)(struct _workarea *mon);

  void (*set_input_focus)(guint window);
  void (*revert_input_focus)(void);
  void (*get_clipboard_data)(int type, ClipboardCb callback, void *user_data);
  void (*set_fullscreen_mode)(void);

  guint (*scale)(void);

  const struct _view_proxy *(*view)(void);
} display_proxy;

#endif
