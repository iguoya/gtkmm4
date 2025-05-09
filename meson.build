project(
  'gtkmm-complex-example',
  'cpp',
  version: '1.0.0',
  license: 'GPL-3.0-or-later',
  meson_version: '>=0.50.0',
  default_options: [
    'cpp_std=c++17',
    'warning_level=2',
    'werror=false',
  ]
)

# 依赖项
gtkmm_dep = dependency('gtkmm-4.0')

# 源代码文件
sources = files([
  'application.cc',
  'app_window.cc',
  'custom_dialog.cc',
  'main.cc'
])

# 构建可执行文件
executable(
  meson.project_name(),
  sources,
  dependencies: gtkmm_dep,
  install: true
)

# 安装UI文件
install_subdir(
  'ui',
  install_dir: get_option('datadir') / meson.project_name()
)

# 安装桌面文件
install_data(
  'org.gtkmm.complex.example.desktop.in',
  rename: 'org.gtkmm.complex.example.desktop',
  install_dir: get_option('datadir') / 'applications'
)

# 桌面文件验证 (如果可用)
desktop_file_validate = find_program('desktop-file-validate', required: false)
if desktop_file_validate.found()
  test(
    'Validate desktop file',
    desktop_file_validate,
    args: [meson.current_source_dir() / 'org.gtkmm.complex.example.desktop.in']
  )
endif