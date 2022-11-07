#pragma once

#include"Core.h"

#include "Window.h"
#include "Turing/LayerStack.h"
#include "Turing/Events/Event.h"
#include "Turing/Events/ApplicationEvent.h"

namespace Turing {

	/* TURING_API 引用自 Core.h 文件，替换了 _declspec(dllexport) */
	class TURING_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();	// 空运行

		void OnEvent(Event & e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	/* To be defined in CLIENT (在 CLIENT 中定义) */
	Application* CreateApplication();
}