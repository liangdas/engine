// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_NATIVE_WINDOW_H_
#define FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_NATIVE_WINDOW_H_

#include <android/native_window.h>
#include "lib/ftl/macros.h"
#include "lib/ftl/memory/ref_counted.h"
#include "lib/ftl/memory/ref_ptr.h"
#include "third_party/skia/include/core/SkSize.h"

namespace shell {

class AndroidNativeWindow
    : public ftl::RefCountedThreadSafe<AndroidNativeWindow> {
 public:
  using Handle = ANativeWindow*;

  bool IsValid() const;

  Handle handle() const;

  SkISize GetSize() const;

 private:
  Handle window_;

  /// Creates a native window with the given handle. Handle ownership is assumed
  /// by this instance of the native window.
  explicit AndroidNativeWindow(Handle window);

  ~AndroidNativeWindow();

  FRIEND_MAKE_REF_COUNTED(AndroidNativeWindow);
  FRIEND_REF_COUNTED_THREAD_SAFE(AndroidNativeWindow);
  FTL_DISALLOW_COPY_AND_ASSIGN(AndroidNativeWindow);
};

}  // namespace shell

#endif  // FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_NATIVE_WINDOW_H_
