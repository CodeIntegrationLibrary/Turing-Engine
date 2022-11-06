#include"trpch.h"
#include "Application.h"

#include"Turing/Log.h"

#include<GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Turing::Application::Application() {
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Turing::Application::~Application() {

}

void Turing::Application::OnEvent(Event& e) {
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

	TR_CORE_TRACE("{0}",e);
}

void Turing::Application::Run() {
	while (m_Running) {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}

bool Turing::Application::OnWindowClose(WindowCloseEvent& e) {
	m_Running = false;
	return true;
}