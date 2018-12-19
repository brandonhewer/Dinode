#include "polymorphic_types/addon.hpp"

namespace Project {
namespace Types {

napi_value init_all (napi_env env, napi_value exports) {
  napi_value print_fn;
  napi_create_function(env, NULL, 0, print, NULL, &print_fn);
  napi_set_named_property(env, exports, "print", print_fn);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init_all)

}
} // namespace Project