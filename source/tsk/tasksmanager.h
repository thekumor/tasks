#pragma once

#include <vector>
#include <string>
#include <memory>
#include <cstdint>
#include <fstream>

namespace tsk
{

	struct TaskInfo
	{
		std::string Content = "";
		bool IsChecked = false;
	};

	class TaskManager
	{
	public:
		static TaskManager* Get();

		std::shared_ptr<TaskInfo>& AddTask(const std::string& content);
		std::shared_ptr<TaskInfo>& GetTask(uint16_t id);
		size_t GetCount();
		void RemoveTask(uint16_t identifier);
		void SaveToFile(const std::string& path);
		void LoadFromFile(const std::string& path);

	protected:
		TaskManager() = default;

	private:
		static TaskManager* m_Instance;
		std::vector<std::shared_ptr<TaskInfo>> m_Tasks = {};
	};

}