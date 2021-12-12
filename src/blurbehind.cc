#define WIN32_LEAN_AND_MEAN
#include <dwmapi.h>
#include <napi.h>
#include <uv.h>
#include <node_buffer.h>

Napi::Value blurbehind(const Napi::CallbackInfo& info)
{
	const HWND handle = (HWND)info[0].ToNumber().Int64Value();

	const DWM_BLURBEHIND bb = {
		DWM_BB_ENABLE,
		info[1].ToBoolean().Value(),
		NULL,
		FALSE
	};

	const HRESULT returnValue = DwmEnableBlurBehindWindow(handle, &bb);

	return Napi::Boolean::New(info.Env(), SUCCEEDED(returnValue));
}

Napi::Value extendframe(const Napi::CallbackInfo& info)
{
	const HWND handle = (HWND)info[0].ToNumber().Int64Value();

	const MARGINS inset = {
		info[1].ToNumber().Int32Value(),
		info[2].ToNumber().Int32Value(),
		info[3].ToNumber().Int32Value(),
		info[4].ToNumber().Int32Value()
	};

	const HRESULT returnValue = DwmExtendFrameIntoClientArea(handle, &inset);

	return Napi::Boolean::New(info.Env(), SUCCEEDED(returnValue));
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set("blurbehind",Napi::Function::New(env,  blurbehind));
	exports.Set("extendframe", Napi::Function::New(env, extendframe));
	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
