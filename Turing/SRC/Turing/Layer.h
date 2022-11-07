#pragma once

#include "Turing/Core.h"
#include "Turing/Events/Event.h"

namespace Turing {

	class TURING_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDethch() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DeBugName; }
	protected:
		std::string m_DeBugName;
	};
};