"use strict";

const native = require('../build/Release/blurbehind.node');

const DwmEnableBlurBehindWindow = (window, shouldEnable) => {
    if (window.getNativeWindowHandle) {
        window = window.getNativeWindowHandle();
    }
    if (!(window instanceof Buffer)) {
        throw "window is not a native window handle or BrowserWindow!";
    }

    if (typeof shouldEnable !== "boolean") {
        throw "shouldEnable is not a bool!";
    }

    // Call the native function
    native.blurbehind(window, shouldEnable);
};

module.exports = { DwmEnableBlurBehindWindow };