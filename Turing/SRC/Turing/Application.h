#pragma once

#include"Core.h"

namespace Turing {

	// TURING_API ������ Core.h �ļ����滻�� _declspec(dllexport)
	class TURING_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();	// ������
	};

	// To be defined in CLIENT (�� CLIENT �ж���)
	Application* CreateApplication();

}