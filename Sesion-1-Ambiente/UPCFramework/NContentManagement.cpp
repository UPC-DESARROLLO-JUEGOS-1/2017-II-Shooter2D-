#include "NContentManagement.h"
#include "FatalError.h"

bool NContentManagement::ReadFileToBuffer(const std::string filePath,
	std::vector<unsigned char>& buffer) {

	std::ifstream file(filePath, std::ios::binary);

	if (file.fail()) {
		FatalError("NContentManagement::ReadFileToBuffer> " + filePath);
		return false;
	}

	// lee de inicio a fin
	file.seekg(0, std::ios::end);
	// saco el tamaño del archivo
	int fileSize = file.tellg();

	// ahora sacar header
	file.seekg(0, std::ios::beg);
	// resto el tamaño del header
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read((char*)&(buffer[0]), fileSize);
	file.close();

	return true;
}