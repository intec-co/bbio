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
    /*pin = (unsigned int)value;
    polltiemout = 3000; // 3 seconds
    nfds = 2;
    file = -1;
    config(pin, OUTPUT_PIN, NONE);*/
}

GpioWrap::~GpioWrap()
{
}

void GpioWrap::Init(v8::Isolate *isolate)
{
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "GpioWrap"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NODE_SET_PROTOTYPE_METHOD(tpl, "configure", configure);
    NODE_SET_PROTOTYPE_METHOD(tpl, "write", write);
    NODE_SET_PROTOTYPE_METHOD(tpl, "read", read);

    constructor.Reset(isolate, tpl->GetFunction());
}

void GpioWrap::New(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    if (args.IsConstructCall())
    {
        // Invoked as constructor: `new MyObject(...)`
        double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
        GpioWrap *obj = new GpioWrap(value);
        obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = {args[0]};
        Local<Context> context = isolate->GetCurrentContext();
        Local<Function> cons = Local<Function>::New(isolate, constructor);
        Local<Object> instance =
            cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(instance);
    }
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

void GpioWrap::configure(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    GpioWrap *obj = ObjectWrap::Unwrap<GpioWrap>(args.Holder());

    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}

void GpioWrap::write(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    GpioWrap *obj = ObjectWrap::Unwrap<GpioWrap>(args.Holder());

    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}

void GpioWrap::read(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    GpioWrap *obj = ObjectWrap::Unwrap<GpioWrap>(args.Holder());

    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}

void GpioWrap::interrupt(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Isolate *isolate = args.GetIsolate();

    GpioWrap *obj = ObjectWrap::Unwrap<GpioWrap>(args.Holder());

    args.GetReturnValue().Set(Number::New(isolate, obj->value_));
}
}