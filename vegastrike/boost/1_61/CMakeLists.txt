add_definitions(-DBOOST_PYTHON_NO_PY_SIGNATURES -DBOOST_PYTHON_STATIC_LIB)
include_directories("${vsUTCS_SOURCE_DIR}/boost/1_61")
add_library(boost_python
  python/src/object/inheritance.cpp
  python/src/object/function.cpp
  python/src/object/stl_iterator.cpp
  python/src/object/class.cpp
  python/src/object/life_support.cpp
  python/src/object/enum.cpp
  python/src/object/function_doc_signature.cpp
  python/src/object/pickle_support.cpp
  python/src/object/iterator.cpp
  python/src/object_protocol.cpp
  python/src/list.cpp
  python/src/tuple.cpp
  python/src/exec.cpp
  python/src/numeric.cpp
  python/src/slice.cpp
  python/src/wrapper.cpp
  python/src/errors.cpp
  python/src/long.cpp
  python/src/dict.cpp
  python/src/module.cpp
  python/src/object_operators.cpp
  python/src/import.cpp
  python/src/str.cpp
  python/src/converter/type_id.cpp
  python/src/converter/from_python.cpp
  python/src/converter/builtin_converters.cpp
  python/src/converter/arg_to_python_base.cpp
  python/src/converter/registry.cpp)

add_library(boost_system
  system/src/error_code.cpp)
