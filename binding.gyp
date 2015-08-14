{
  'targets': [
    {
      'target_name': '<(module_name)',
      'include_dirs' : [
  	    "<!(node -e \"require('nan')\")"
      ],
      'sources': [ 'node-SUSIIoT.cpp',  'node-SUSIIoT-function-define.cpp'],
      'conditions': [
        [
          'OS=="linux"', {
              'libraries': [ '-lSusiIoT' ]
          }
        ],
        [
          'OS=="win"',
          {
            'libraries':[
              'SusiIoT.lib'
            ],
            'conditions':[
              [
                'target_arch=="ia32"',
                {
                  'library_dirs':[
                    'C:\\Program Files\\Advantech\\SusiIoT\\SDK\\SusiIoT\\lib\\x86'
                  ]
                }
              ],
              [
                'target_arch=="x64"',
                {
                  'library_dirs':[
                    'C:\\Program Files\\Advantech\\SusiIoT\\SDK\\SusiIoT\\lib\\x64'
                  ]
                }
              ]
            ]
          }
        ]
      ]
    },

    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)\\<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
  ]
}
