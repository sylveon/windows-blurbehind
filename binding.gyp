{
  "targets": [
    {
      "target_name": "blurbehind",
      "msvs_settings": {
        "VCCLCompilerTool": { "ExceptionHandling": 1 },
      },
      "sources": [ "src/blurbehind.cc" ],
      "link_settings": {
        "libraries": [ "dwmapi.lib" ]
      }
    }
  ]
}
