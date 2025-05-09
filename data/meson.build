desktop_file = i18n.merge_file(
  input: 'org.gtkmm.complex.example.desktop.in',
  output: 'org.gtkmm.complex.example.desktop',
  type: 'desktop',
  po_dir: '../po',
  install: true,
  install_dir: get_option('datadir') / 'applications'
)

desktop_file_validate = find_program('desktop-file-validate', required: false)
if desktop_file_validate.found()
  test(
    'Validate desktop file',
    desktop_file_validate,
    args: [desktop_file.full_path()]
  )
endif