#pragma once

#include"Core.h"
#include"Events/Event.h"
#include"Window.h"

namespace Turing {

	/* TURING_API 引用自 Core.h 文件，替换了 _declspec(dllexport) */
	class TURING_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();	// 空运行

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	/* To be defined in CLIENT (在 CLIENT 中定义) */
	Application* CreateApplication();
}