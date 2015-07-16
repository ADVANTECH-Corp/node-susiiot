{
  'targets': [
    {
      'target_name': 'node-SUSIIoT',
      'include_dirs' : [
  	"<!(node -e \"require('nan')\")"
			],
      'conditions': [ 
        ['OS=="linux"', {
              'sources': [ 'node-SUSIIoT.cpp',  'node-SUSIIoT-function-define.cpp'],
              'libraries': [ '-lSusiIoT' ],
        }],
        [
          'OS=="win"',
          {
            'sources': [ 'node-SUSIIoT.cpp',  'node-SUSIIoT-function-define.cpp'],
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
    }
  ]
}
