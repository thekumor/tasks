#include "buffers.h"

namespace tsk
{

	std::unordered_map<std::string, BufferInfo> BufferManager::m_Buffers = {};

	BufferInfo& BufferManager::GetBuffer(const std::string& name)
	{
		return m_Buffers[name];
	}

	void BufferManager::KillBuffer(const std::string& name)
	{
		m_Buffers.erase(name);
	}

}