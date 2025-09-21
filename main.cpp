#include "mainwindow.h"

class Athena : public Gtk::Application {
protected:
  Athena() : Gtk::Application("cn.yatiger.athena") {}

  void on_activate() override {
    auto builder = Gtk::Builder::create_from_resource("/cn/yatiger/athena/mainwindow.ui");
    auto win = Gtk::Builder::get_widget_derived<MainWindow>(builder, "main_window");

    if (!win)
      throw std::runtime_error("Could not get MainWindow from UI file");

    add_window(*win);
    win->present();
  }

public:
  static Glib::RefPtr<Athena> create() {
    return Glib::RefPtr<Athena>(new Athena());
  }
};

int main(int argc, char* argv[]) {
  auto app = Athena::create();
  return app->run(argc, argv);
}