#include "mainwindow.h"

class MyApp : public Gtk::Application {
protected:
  MyApp() : Gtk::Application("org.example.MyApp") {}

  void on_activate() override {
    auto builder = Gtk::Builder::create_from_resource("/cn/yatiger/app/mainwindow.ui");
    // auto win = builder->get_widget_derived<MainWindow>("main_window");
    auto win = Gtk::Builder::get_widget_derived<MainWindow>(builder, "main_window");
    
    
    if (!win)
      throw std::runtime_error("Could not get MainWindow from UI file");

    add_window(*win);
    win->present();
  }

public:
  static Glib::RefPtr<MyApp> create() {
    return Glib::RefPtr<MyApp>(new MyApp());
  }
};

int main(int argc, char* argv[]) {
  auto app = MyApp::create();
  return app->run(argc, argv);
}