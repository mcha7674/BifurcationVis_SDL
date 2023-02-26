#pragma once
#include <vector>
#include "Layer.h"
class LayerStack
{
public:
	LayerStack();
	~LayerStack(); // deletes all layers in layerstack

	void PushLayer(Layer* layer);
	void PopLayer(Layer* layer); // Will pop layer from m_Layers but not delete it

	std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
	std::vector<Layer*>::iterator end() { return m_Layers.end(); }
private:
	std::vector<Layer*> m_Layers; // The Actual layer stack
	uint32_t m_LayerInsertIndex = 0;
};
