const native: any = require("../build/Release/blurbehind.node");

/**
 * Enables or disable blur behind a window
 * @param window The target window's native handle.
 * @param enable Whether to enable or disable blur behind.
 */
export function DwmEnableBlurBehindWindow(window: Buffer, enable: boolean) {
    return native.blurbehind(window, enable);
};

/**
 * Extends the window frame in the client area.
 * @param window The target window's native handle.
 * @param left 
 * @param right 
 * @param top 
 * @param bottom 
 */
export function DwmExtendFrameIntoClientArea(window: Buffer, left: number, right: number, top: number, bottom: number) {
    return native.extendframe(window, left, right, top, bottom);
}