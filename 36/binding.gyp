{
  "targets": [{
    "target_name": "addon",
    "sources": [
      "addon.cc"
    ],
    "include_dirs": [ "<!@(node -p \"require('node-addon-api').include\")" ],
    "dependencies": [ "<!(node -p \"require('node-addon-api').gyp\")" ]
  }]
}