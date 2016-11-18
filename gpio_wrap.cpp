#include "gpio_wrap.h"

namespace ports
{

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Persistent;
using v8::String;
using v8::Value;
using v8::Exception;

Persistent<Function> GpioWrap::constructor;

GpioWrap::GpioWrap(double value) : value_(value)
{
    pin = (unsigned int)value;
    polltiemout = 3000; // 3 seconds
    nfds = 2;
    file = -1;
    config(pin, OUTPUT_PIN, NONE);
}

void GpioWrap::Init(Local<Object> exports)
{
    Isolate *isolate = exports->GetIsolate();

    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "GpioWrap"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    NODE_SET_PROTOTYPE_METHOD(tpl, "setValue", setValue);

    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "GpioWrap"),
                 tpl->GetFunction());
}

void GpioWrap::NewInstance(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    const int argc = 1;
    Local<Value> argv[argc] = {args[0]};
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    Local<Object> result =
        cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(result);
}

void GpioWrap::setValue(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    GpioWrap *obj = ObjectWrap::Unwrap<GpioWrap>(args.Holder());
    if (!args[0]->IsBoolean())
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong arguments")));
        return;
    }

    // Perform the operation
    bool value = args[0]->BooleanValue();
    obj->set_value(value);

    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}
}