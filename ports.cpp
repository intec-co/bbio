#include <node.h>

#include "gpio.h"
#include "spi.h"

namespace ports {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void CreateObject(const FunctionCallbackInfo<Value>& args) {
  gpio::NewInstance(args);
}

void init(Local<Object> exports) {
  gpio::Init(exports->GetIsolate());
  NODE_SET_METHOD(exports, "gpio", set_gpio);
  //NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(ports, init)

}