#include	<string.h>
#include	<stdlib.h>
#include	"Utils.h"
#include <Windows.h>
#include <string>
#include <vector>

#pragma warning(disable:4996)

std::vector<std::string> get_all_files_names_within_folder(std::string folder)
{
	std::vector<std::string> names;
	std::string tmp;
	std::string search_path = folder + "/*.py";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				tmp = fd.cFileName;
				tmp = tmp.substr(0, tmp.size() - 3);
				names.push_back(tmp);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}