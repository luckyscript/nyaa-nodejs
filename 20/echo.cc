#include <nan.h>
namespace My 
{
    using v8::String;
    using v8::FunctionTemplate;

    NAN_METHOD(Echo)
    {
        if(info.Length() < 1){
            Nan::ThrowError("wrong arguments");
            return;
        }
        info.GetReturnValue().Set(info[0]);
    }

    NAN_MODULE_INIT(Init)
    {
        Nan::Set(target, Nan::New<String>("echo").ToLocalChecked(),
                Nan::GetFunction(Nan::New<FunctionTemplate>(Echo)).ToLocalChecked());
    }

    NODE_MODULE(echo, Init)
}