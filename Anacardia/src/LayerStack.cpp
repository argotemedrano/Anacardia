#include "pch.h"
#include "LayerStack.h"

namespace Anacardia
{
	LayerStack::LayerStack()
	{
	}
	LayerStack::~LayerStack()
	{
	}

	void LayerStack::AddLayer(Layer* layer)
	{
		m_Layers.push_back(layer);
	}

	void LayerStack::RemoveLayer(Layer* layer)
	{

	}
	void LayerStack::DisableLayer(Layer* layer)
	{
		//layer->SetActive(false);
	}
	void LayerStack::Update()
	{
	}
}
