#pragma once

#include "SAV.h"

class Sandbox : public App {
 public:
  Sandbox();
  ~Sandbox();

 private:
  virtual void InitUser() override;
};

App* CreateApp();

