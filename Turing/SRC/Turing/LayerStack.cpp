#include "trpch.h"
#include "LayerStack.h"

Turing::LayerStack::LayerStack() {
	m_LayerInsert = m_Layers.begin();
}

Turing::LayerStack::~LayerStack() {
	for (Layer* layer : m_Layers)
		delete layer;
}

void Turing::LayerStack::PushLayer(Layer* layer) {
	m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void Turing::LayerStack::PushOverlay(Layer* overlay) {
	m_Layers.emplace_back(overlay);
}

void Turing::LayerStack::PopLayer(Layer* layer) {
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end()) {
		m_Layers.erase(it);
		m_LayerInsert--;
	}
}

void Turing::LayerStack::PopOverlay(Layer* overlay) {
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end()) {
		m_Layers.erase(it);
	}
}