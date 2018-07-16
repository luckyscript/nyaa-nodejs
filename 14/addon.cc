#include <node.h>
namespace demo {
    using v8::Exception;
    using v8::Object;
    using v8::Value;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Number;
    using v8::Local;

    void Add(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        double value = args[0] -> NumberValue() + args[1] -> NumberValue();
        Local<Number> num = Number::New(isolate, value);
        args.GetReturnValue().Set(num);
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(addon, Init);
    
}