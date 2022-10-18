#pragma once

#include <unordered_map>
#include <string>
#include <cstdint>

#define TSK_BUFFER_SIZE 64

namespace tsk
{

	struct BufferInfo
	{
		std::string Name = "";
		const uint16_t c_Size = TSK_BUFFER_SIZE;
		char Content[TSK_BUFFER_SIZE];
	};

	class BufferManager
	{
	public:
		static BufferInfo& GetBuffer(const std::string& name);
		static void KillBuffer(const std::string& name);

	protected:
		BufferManager() = default;

	private:
		static std::unordered_map<std::string, BufferInfo> m_Buffers;
	};

}