#include "App.h"

bool dirtyFlag = 1;

App::App() : m_arraySize(100), m_delay(5) {
  InitLog();
  InitGlfw();
  InitGlew();
  InitImgui();
}

App::~App() {
  ImguiShutdown();
  GlfwShutdown();
}

void App::run() {
  InitUser();
  m_dataCtrl->Generate(m_arraySize);
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    m_dataRndr->Clear();
    m_dataRndr->Draw();
    ImguiRenderLayer();
    glfwSwapBuffers(window);
  }
}
// To be defined in client code
void App::InitUser() {}

void App::InitLog() {
  Log::Init();
  LOG_INFO("spdlog initialization is completed.");

}

void App::InitGlfw() {
  LOG_INFO("Starting GLFW context.");
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window = glfwCreateWindow(WIDTH, HEIGHT, "SAV", nullptr, nullptr);
  if (window == nullptr) {
    LOG_CRITICAL("Failed to create GLFW window");
    glfwTerminate();
    abort();
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  GLCall(glViewport(0, -height, width, 2 * height));

  LOG_INFO("GLFW context initialization is completed.");
}

void App::InitGlew() {
  LOG_INFO("Starting GLEW initialization.");

  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    LOG_CRITICAL("Failed to initialize GLEW");
    abort();
  }
  LOG_INFO("GLEW initialization is completed.");
}

void App::InitImgui() {
  LOG_INFO("Starting imgui initialization.");

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  LOG_INFO("imgui initialization is completed.");
}

void App::ImguiRenderLayer() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
  {
    static int sortChooser = -1;
    ImGui::Begin("SAV Control panel");

    ImGui::Text("Delay:      ");
    ImGui::SameLine();
    ImGui::PushItemWidth(100);
    if (ImGui::InputInt("  ", &m_delay)) {
      m_dataRndr->SetDelay(m_delay);
      LOG_INFO("New Delay has set!");
    }
    ImGui::PopItemWidth();

    ImGui::Text("Array size: ");
    ImGui::SameLine();
    ImGui::PushItemWidth(100);
    ImGui::InputInt("", &m_arraySize);
    ImGui::PopItemWidth();
    if (ImGui::Button("Generate", {96, 25}) && dirtyFlag) {
      m_dataCtrl->Generate(m_arraySize);
      m_dataRndr->SetData(&m_dataCtrl->GetData());
      m_dataCtrl->ResetCounters();
      LOG_INFO("New Array has generated!");
    }
    ImGui::SameLine();
    if (ImGui::Button("Shuffle", {96, 25}) && dirtyFlag) {
      m_dataRndr->Reset();
      m_dataCtrl->ResetCounters();
      m_dataCtrl->Shuffle();
    }
    ImGui::Text((std::string("Swap count: ") +
                 std::to_string(m_dataCtrl->GetSwapCount()))
                    .c_str());
    ImGui::Text((std::string("Compare count: ") +
                 std::to_string(m_dataCtrl->GetCmpCount()))
                    .c_str());
    ImGui::Text((std::string("Assignment count: ") +
                 std::to_string(m_dataCtrl->GetAssignmentCount()))
                    .c_str());

    ImGui::NewLine();
    const auto& collection = SortsController::Get().GetSortCollection();
    for (unsigned int i = 0; i < collection.size(); i++) {
      std::string btn_name = collection[i]->GetName().insert(0, "Begin ");
      if (ImGui::Button(btn_name.c_str(), {200, 25}) && dirtyFlag) {
        SortsController::Get().SetSort(collection[i]);
        LOG_INFO("{0} is choosed!", collection[i]->GetName().c_str());
        SortsController::Get().BeginSort();
        LOG_INFO("{0} has started!", collection[i]->GetName().c_str());
      }
    }

    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                ImGui::GetIO().Framerate);
    ImGui::End();
  }
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void App::ImguiShutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void App::GlfwShutdown() { glfwTerminate(); }
