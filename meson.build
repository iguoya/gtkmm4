project('myapp', 'cpp',
  version: '0.1',
  default_options: ['cpp_std=c++17'])

gtkmm_dep = dependency('gtkmm-4.0')

src_files = files(
  'main.cc',
  'mainwindow.cc'
)

executable('myapp', src_files,
  include_directories: include_directories('.'),
  dependencies: gtkmm_dep,
  install: true)