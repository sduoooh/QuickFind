#include "QuickFind.h"

void find() {
	std::string temp = "1";
	while (true) {
		temp = "1";
		std::unique_lock<std::mutex> lockerfinder(m);

		while (isupdate) {
			finder.wait(lockerfinder);
		}

		if (!issreach) {
			if (temp == "1") std::cout << "是否检测更新？是则输入1。 " << std::endl;
			std::cin >> temp;
			issreach = true;
			if (temp == "1") continue;
		};

		std::cout << "请输入关键词：\n" << std::endl;
		std::string input;
		std::cin >> input;
		std::cout << "\n" << std::endl;

		std::regex reg(".*" + input + ".*");
		auto first = vector.begin();
		auto end = vector.end();
		int count = 0;

		while (first != end)
		{
			if (std::regex_match(*first, reg)) {
				std::cout << "第" << count + 1 << "个结果：" << map[*first] << std::endl;
				count++;
			}
			++first;
		}
		if (!count) std::cout << "所选目录下无匹配结果。" << std::endl;
		issreach = false;
		std::cout << "\n\n" << std::endl;
	}
}
