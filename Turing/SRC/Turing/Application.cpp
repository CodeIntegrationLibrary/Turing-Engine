#include"trpch.h"
#include "Application.h"

#include"Turing/Log.h"

#include <glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Turing::Application::Application() {
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	unsigned int id;
	glGenVertexArrays(1, &id);
}

Turing::Application::~Application() {

}

void Turing::Application::PushLayer(Layer* layer) {
	m_LayerStack.PushLayer(layer);
}

void Turing::Application::PushOverlay(Layer* layer) {
	m_LayerStack.PushOverlay(layer);
}

void Turing::Application::OnEvent(Event& e) {
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
		(*--it)->OnEvent(e);
		if (e.Handled)
			break;
	}
}

void Turing::Application::Run() {
	while (m_Running) {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_Window->OnUpdate();
	}
}

bool Turing::Application::OnWindowClose(WindowCloseEvent& e) {
	m_Running = false;
	return true;
}