#pragma once

#include"Core.h"
#include"Events/Event.h"
#include"Window.h"

namespace Turing {

	/* TURING_API ������ Core.h �ļ����滻�� _declspec(dllexport) */
	class TURING_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();	// ������

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	/* To be defined in CLIENT (�� CLIENT �ж���) */
	Application* CreateApplication();
}