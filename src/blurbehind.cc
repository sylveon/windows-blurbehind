#include <dwmapi.h>
#include <napi.h>
#include <uv.h>
#include <node_buffer.h>

void blurbehind(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	const HWND handle = *reinterpret_cast<HWND *>(args[0].As<Napi::Object>(.As<Napi::Buffer<char>>().Data()));

	const DWM_BLURBEHIND bb = {
		DWM_BB_ENABLE,
		args[1].As<Napi::Boolean>()->Value(),
		NULL,
		FALSE
	};

	const HRESULT returnValue = DwmEnableBlurBehindWindow(handle, &bb);

	args.GetReturnValue().Set(SUCCEEDED(returnValue));
}

void extendframe(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	const HWND handle = *reinterpret_cast<HWND *>(args[0].As<Napi::Object>(.As<Napi::Buffer<char>>().Data()));

	const MARGINS inset = {
		args[1].As<v8::Int32>()->Value(),
		args[2].As<v8::Int32>()->Value(),
		args[3].As<v8::Int32>()->Value(),
		args[4].As<v8::Int32>()->Value()
	};

	const HRESULT returnValue = DwmExtendFrameIntoClientArea(handle, &inset);

	args.GetReturnValue().Set(SUCCEEDED(returnValue));
}

void init(Napi::Object exports)
{
	NODE_SET_METHOD(exports, "blurbehind", blurbehind);
	NODE_SET_METHOD(exports, "extendframe", extendframe);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)
