--- test/test-file.cpp.orig	2023-04-13 23:36:53 UTC
+++ test/test-file.cpp
@@ -38,7 +38,7 @@
 #endif
 
 #if QLJS_HAVE_LIBUTIL_H
-#include <util.h>
+#include <libutil.h>
 #endif
 
 #if QLJS_HAVE_MKFIFO
