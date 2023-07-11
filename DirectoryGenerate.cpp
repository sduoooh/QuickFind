#include <io.h>
#include "QuickFind.h"

void generrate(std::string path, vectors& files, maps& map) {

	std::intptr_t hFile = 0;
	struct _finddata_t fileinfo;
	std::regex reg("(\.git)|(node_modules)|(_.*)|(img)");
	std::string p;

	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {

		do {

			std::string& fullypath = p.assign(path).append("\\").append(fileinfo.name);
			std::string filename = fileinfo.name;

			files.push_back(fileinfo.name);
			map.insert(maps::value_type(filename, fullypath));

			if ((fileinfo.attrib & _A_SUBDIR) && (!(std::regex_match(fileinfo.name, reg)))) {

				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					generrate(fullypath, files, map);
				}
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void create() {
	while (true) {
		std::unique_lock<std::mutex> lockergenerater(m);
		while (!isupdate) {
			generater.wait(lockergenerater);
		}

		std::cout << "正在进行索引建立......" << std::endl;
		vector.clear();
		map.clear();
		auto time_start = std::chrono::steady_clock::now();

		generrate(desktoppath, vector, map);
		generrate(srcpath, vector, map);

		auto time_end = std::chrono::steady_clock::now();
		auto time_diff = time_end - time_start;
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_diff);

		std::string temp;
		std::cout << "索引建立完成，共索引：" << vector.size() << "个文件；共耗时：" << duration.count() << "ms.\n\n" << std::endl;
		std::cout << "输入任意语句以开始检索： " << std::endl;
		std::cin >> temp;
		issreach = true;
		isupdate = false;
		finder.notify_one();
	}
}
