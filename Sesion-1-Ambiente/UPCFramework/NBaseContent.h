#pragma once

#include <string>

// Forward declaration, esto es para
// evitar dependencias circulares
class NContentManagement;

class NBaseContent
{
public:
	NBaseContent(NContentManagement* contentManagement) {
		mContentManagement = contentManagement;
	}
	~NBaseContent();

	std::string GetPath() { return mPath; }
	NContentManagement* GetContentManagement() { return mContentManagement; }

	virtual void Initialize() {}
	virtual bool Load(const std::string path) {
		mPath = path;
		return true;
	}

protected:
	std::string mPath;
	NContentManagement* mContentManagement;
};

