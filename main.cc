#include "athena.h"

int main(int argc, char* argv[]) {
  auto app = Athena::create();
  return app->run(argc, argv);
}