#pragma once
#include "Layer.h"

namespace Anacardia
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();
		void AddLayer(Layer* layer);
		void RemoveLayer(Layer* layer);
	private:
		std::vector<Layer*> m_Layers;
	};
}


