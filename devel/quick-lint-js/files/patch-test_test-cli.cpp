--- test/test-cli.cpp.orig	2023-04-13 23:36:53 UTC
+++ test/test-cli.cpp
@@ -14,7 +14,7 @@
 #include <quick-lint-js/port/have.h>
 
 #if QLJS_HAVE_LIBUTIL_H
-#include <util.h>
+#include <libutil.h>
 #endif
 
 #if QLJS_HAVE_UTIL_H
