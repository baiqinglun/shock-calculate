# CMake generated Testfile for 
# Source directory: E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner
# Build directory: E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-build/src/jsontestrunner
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(jsoncpp_readerwriter "C:/Users/Administrator/AppData/Local/Programs/Python/Python39/python.exe" "-B" "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/runjsontests.py" "E:/Programming/c++/H2-shock/cmake-build-debug/bin/jsontestrunner_exe.exe" "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter PROPERTIES  WORKING_DIRECTORY "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/CMakeLists.txt;43;add_test;E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/CMakeLists.txt;0;")
add_test(jsoncpp_readerwriter_json_checker "C:/Users/Administrator/AppData/Local/Programs/Python/Python39/python.exe" "-B" "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/runjsontests.py" "--with-json-checker" "E:/Programming/c++/H2-shock/cmake-build-debug/bin/jsontestrunner_exe.exe" "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/data")
set_tests_properties(jsoncpp_readerwriter_json_checker PROPERTIES  WORKING_DIRECTORY "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/../../test/data" _BACKTRACE_TRIPLES "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/CMakeLists.txt;47;add_test;E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src/src/jsontestrunner/CMakeLists.txt;0;")