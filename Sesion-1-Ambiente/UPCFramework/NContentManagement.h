#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <type_traits>

#include "NBaseContent.h"

class NFramework;

class NContentManagement
{
public:
	NContentManagement(NFramework* framework) {
		mFramework = framework;
	}
	~NContentManagement() {}

	virtual void Initialize() {}

	template<typename T>
	T* LoadAndGetContent(const std::string path) {
		std::map<std::string, NBaseContent*>::iterator it =
			mContents.find(path);
		T* result = it != mContents.end() ? (T*)it->second : nullptr;

		if (result == nullptr) {
			result = new T(this);
			result->Initialize();
			result->Load(path);

			mContents.insert(std::make_pair(path, result));
			std::cout << "Loaded content: " << path << std::endl;
		}

		return result;
	}

	static bool ReadFileToBuffer(const std::string filePath,
		std::vector<unsigned char>& buffer);
protected:
	NFramework* mFramework;
	std::map<std::string, NBaseContent*> mContents;

	NBaseContent* GetContent(const std::string path) {
		std::map<std::string, NBaseContent*>::iterator it =
			mContents.find(path);

		if (it == mContents.end()) {
			std::cout << "Content not found in "
				<< path << std::endl;
			return nullptr;
		}

		return it->second;
	}
};

