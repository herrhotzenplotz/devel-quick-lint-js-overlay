--- src/quick-lint-js/port/child-process.cpp.orig	2023-05-02 14:47:30 UTC
+++ src/quick-lint-js/port/child-process.cpp
@@ -42,6 +42,10 @@ using namespace std::literals::string_view_literals;
 
 namespace quick_lint_js {
 namespace {
+#if QLJS_HAVE_UNISTD_H
+char** get_posix_environment();
+#endif
+
 #if QLJS_HAVE_POSIX_SPAWN || QLJS_HAVE_WINDOWS_H
 void handle_process_io(const run_program_options& options,
                        pipe_fds& program_input, pipe_fds& program_output,
@@ -122,14 +126,11 @@ run_program_result run_program(span<const char* const>
   const char* exe_file = command[0];
 
   ::pid_t pid;
-#if QLJS_HAVE_NS_GET_ENVIRON
-  char**& environ = *::_NSGetEnviron();
-#endif
   int rc = ::posix_spawnp(/*pid=*/&pid, /*file=*/exe_file,
                           /*file_actions=*/&file_actions,
                           /*attrp=*/nullptr,
                           /*argv=*/argv.data(),
-                          /*envp=*/environ);
+                          /*envp=*/get_posix_environment());
   if (rc != 0) {
     std::fprintf(stderr, "error: failed to spawn %s: %s\n", exe_file,
                  std::strerror(errno));
@@ -347,6 +348,20 @@ run_program_result run_program(span<const char* const>
 #endif
 
 namespace {
+#if QLJS_HAVE_UNISTD_H
+#if !QLJS_HAVE_NS_GET_ENVIRON
+extern "C" char** environ;
+#endif
+
+char** get_posix_environment() {
+#if QLJS_HAVE_NS_GET_ENVIRON
+  return *::_NSGetEnviron();
+#else
+  return environ;
+#endif
+}
+#endif
+
 #if QLJS_HAVE_POSIX_SPAWN || QLJS_HAVE_WINDOWS_H
 void handle_process_io(const run_program_options& options,
                        pipe_fds& program_input, pipe_fds& program_output,
