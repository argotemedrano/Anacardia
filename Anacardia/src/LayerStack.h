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
		void AddOverlay(Layer* overlay);
		void RemoveOverlay(Layer* overlay);
		void DisableLayer(Layer* layer);
		void Update();
		inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		inline std::vector<Layer*>::const_iterator cbegin() { return m_Layers.cbegin(); }
		inline std::vector<Layer*>::const_iterator cend() { return m_Layers.cend(); }
		inline std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		inline std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend();  }
		inline std::vector<Layer*>::const_reverse_iterator crbegin() { return m_Layers.crbegin(); }
		inline std::vector<Layer*>::const_reverse_iterator crend() { return m_Layers.crend(); }

	private:
		std::vector<Layer*> m_Layers;
	};
}


