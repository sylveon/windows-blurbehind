#include <dwmapi.h>
#include <node.h>
#include <node_buffer.h>

void blurbehind(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	const HWND handle = *reinterpret_cast<HWND *>(node::Buffer::Data(args[0].As<v8::Object>()));

	const DWM_BLURBEHIND bb = {
		DWM_BB_ENABLE,
		args[1]->BooleanValue(),
		NULL,
		FALSE
	};

	const HRESULT returnValue = DwmEnableBlurBehindWindow(handle, &bb);

	args.GetReturnValue().Set(SUCCEEDED(returnValue));
}

void init(v8::Local<v8::Object> exports)
{
	NODE_SET_METHOD(exports, "blurbehind", blurbehind);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)