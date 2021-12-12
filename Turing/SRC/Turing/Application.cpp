#include"trpch.h"
#include "Application.h"

#include"Turing/Events/ApplicationEvent.h"
#include"Turing/Log.h"

#include<GLFW/glfw3.h>

Turing::Application::Application() {
	m_Window = std::unique_ptr<Window>(Window::Create());
}

Turing::Application::~Application() {

}

void Turing::Application::Run() {
	while (m_Running) {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}