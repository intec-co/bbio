#include <node.h>

#include "gpio_wrap.h"
#include "spi_wrap.h"

namespace ports
{

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;

void CreateGpio(const FunctionCallbackInfo<Value> &args)
{
  GpioWrap::NewInstance(args);
}

void CreateSpi(const FunctionCallbackInfo<Value> &args)
{
  SpiWrap::NewInstance(args);
}

void init(Local<Object> exports)
{
  GpioWrap::Init(exports->GetIsolate());
  SpiWrap::Init(exports->GetIsolate());

  NODE_SET_METHOD(exports, "gpio", CreateGpio);
  NODE_SET_METHOD(exports, "spi", CreateSpi);
}

NODE_MODULE(ports, init)
}