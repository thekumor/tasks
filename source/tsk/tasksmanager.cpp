#include "tasksmanager.h"

namespace tsk
{

	TaskManager* TaskManager::m_Instance = nullptr;

	TaskManager* TaskManager::Get()
	{
		if (!m_Instance)
		{
			m_Instance = new TaskManager;
		}

		return m_Instance;
	}

	std::shared_ptr<TaskInfo>& TaskManager::AddTask(const std::string& content)
	{
		TaskInfo newTask{
			.Content = content
		};

		return m_Tasks.emplace_back(std::make_shared<TaskInfo>(newTask));
	}

	std::shared_ptr<TaskInfo>& TaskManager::GetTask(uint16_t id)
	{
		return m_Tasks[id];
	}

	size_t TaskManager::GetCount()
	{
		return m_Tasks.size();
	}

	void TaskManager::RemoveTask(uint16_t identifier)
	{
		m_Tasks.erase(m_Tasks.begin() + identifier);
	}

	void TaskManager::SaveToFile(const std::string& path)
	{
		std::fstream handle(path, std::ios::out);
		if (!handle)
		{
			// blah blah blah
			return;
		}

		for (auto& k : m_Tasks)
		{
			handle << k->Content << "\n";
		}

		handle.close();
	}

	void TaskManager::LoadFromFile(const std::string& path)
	{
		std::fstream handle(path, std::ios::in);
		if (!handle)
		{
			return;
		}

		std::string line;
		while (std::getline(handle, line))
		{
			if (line != "\n")
			{
				AddTask(line);
			}
		}

		handle.close();
	}

}