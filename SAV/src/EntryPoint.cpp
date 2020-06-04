#include "EntryPoint.h"

int main() {
  App* app = CreateApp();
  app->run();
  delete app;
  return 0;
}