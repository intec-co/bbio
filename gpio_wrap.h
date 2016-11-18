#ifndef GPIO_WRAP_H_
#define GPIO_WRAP_H_

#include <node.h>
#include <node_object_wrap.h>

namespace ports
{
lass GpioWrap : public node::ObjectWrap
{
  private:
    explicit GpioWrap(double value = 0);
    static v8::Persistent<v8::Function> constructor;
    static void setValue(const v8::FunctionCallbackInfo<v8::Value> &args);

  public:
    static void Init(v8::Local<v8::Object> exports);
    static void NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args);
};
}
#endif /* GPIO_WRAP_H_ */
