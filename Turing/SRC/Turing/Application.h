#pragma once

#include"Core.h"

namespace Turing {

	// TURING_API 引用自 Core.h 文件，替换了 _declspec(dllexport)
	class TURING_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();	// 空运行
	};

	// To be defined in CLIENT (在 CLIENT 中定义)
	Application* CreateApplication();

}