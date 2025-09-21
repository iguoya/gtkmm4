#include "mainwindow.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::ApplicationWindow(cobject) {
  // 可以在这里连接信号或进行其他初始化
}

Glib::RefPtr<Gtk::Builder> MainWindow::create_builder() {
  return Gtk::Builder::create_from_file("ui/mainwindow.ui");
}