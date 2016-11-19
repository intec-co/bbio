#ifndef SPI_WRAP_H_
#define SPI_WRAP_H_

#include <node.h>
#include <node_object_wrap.h>

namespace ports
{
class SpiWrap : public node::ObjectWrap
{
public:
  static void Init(v8::Isolate *isolate);
  static void NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args);
  inline double value() const { return value_; }

private:
  explicit SpiWrap(double value = 0);
  ~SpiWrap();

  static void New(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void configure(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void write(const v8::FunctionCallbackInfo<v8::Value> &args);
  static void read(const v8::FunctionCallbackInfo<v8::Value> &args);
  static v8::Persistent<v8::Function> constructor;
  double value_;
};
}
#endif /* SPI_WRAP_H_ */