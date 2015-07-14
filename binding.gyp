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
        ['OS=="win"', {
              'sources': [ 'node-SUSIIoT.cpp',  'node-SUSIIoT-function-define.cpp'],
              'libraries': [ 'SusiIoT.lib' ],
        }]
      ]
    }
  ]
}
