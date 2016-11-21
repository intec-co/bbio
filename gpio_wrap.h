#ifndef GPIO_WRAP_H_
#define GPIO_WRAP_H_

#include <node.h>
#include <node_object_wrap.h>

#include "gpio.h"

namespace ports
{
class GpioWrap : public node::ObjectWrap
{
public:
  static void Init(v8::Isolate *isolate);
  static void NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args);
  inline double value() const { return value_; }

private:
  explicit GpioWrap(double value = 0);
  ~GpioWrap();

  static void New(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void configure(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void write(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void read(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void interrupt(const v8::FunctionCallbackInfo<v8::Value> &args);
  static v8::Persistent<v8::Function> constructor;
  double value_;
  gpio *port;
};
}
#endif /* GPIO_WRAP_H_ */
