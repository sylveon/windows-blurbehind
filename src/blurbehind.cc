#include <dwmapi.h>
#include <node.h>
#include <node_buffer.h>

void blurbehind(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	const HWND handle = *reinterpret_cast<HWND *>(node::Buffer::Data(args[0].As<v8::Object>()));

	const DWM_BLURBEHIND bb = {
		DWM_BB_ENABLE,
		args[1].As<v8::Boolean>()->Value(),
		NULL,
		FALSE
	};

	const HRESULT returnValue = DwmEnableBlurBehindWindow(handle, &bb);

	args.GetReturnValue().Set(SUCCEEDED(returnValue));
}

void extendframe(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	const HWND handle = *reinterpret_cast<HWND *>(node::Buffer::Data(args[0].As<v8::Object>()));

	const MARGINS inset = {
		args[1].As<v8::Int32>()->Value(),
		args[2].As<v8::Int32>()->Value(),
		args[3].As<v8::Int32>()->Value(),
		args[4].As<v8::Int32>()->Value()
	};

	const HRESULT returnValue = DwmExtendFrameIntoClientArea(handle, &inset);

	args.GetReturnValue().Set(SUCCEEDED(returnValue));
}

void init(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "blurbehind", blurbehind);
	NODE_SET_METHOD(exports, "extendframe", extendframe);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
