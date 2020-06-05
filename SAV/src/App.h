#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_glfw.h"
#include "imgui/examples/imgui_impl_opengl3.h"

#include "Log.h"

#include "DataController/IDataController.h"

#include "Graphics/DataRenderer/IDataRenderer.h"

#include "SortsController/SortsController.h"

#include "Sorts/ISort.h"

#include <memory>

class App {
 public:
  App();
  virtual ~App();

  void run();

 protected:
   // To be defined in client code
  virtual void InitUser();

 protected:
  std::shared_ptr<IDataController> m_dataCtrl;
  std::shared_ptr<IDataRenderer> m_dataRndr;
  int m_arraySize;
  int m_delay;
 private:
  void InitLog();
  void InitGlfw();
  void InitGlew();
  void InitImgui();

  void ImguiRenderLayer();

  void ImguiShutdown();
  void GlfwShutdown();
 private:
  const GLuint WIDTH = 1200, HEIGHT = 800;
  GLFWwindow* window;

};