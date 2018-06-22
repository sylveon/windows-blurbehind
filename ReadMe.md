# windows-blurbehind

Invoke like this:

```js
const bb = require('window-blurbehind');
bb.DwmEnableBlurBehindWindow(myWindow, shouldEnable);
```

Where the first parameter can either be an Electron `BrowserWindow` or a window handle stored as `Buffer`.

`shouldEnable` is a boolean indicating whether the blur behind is to be turned on or off.

## Tips for usage on Electron

For best user and developer experience, **do not set** `transparent` to `true`. It has many shortcomings, such as no support for maximised window state and shadows. Instead set `backgroundColor` to `#00000000`.