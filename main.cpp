#include "QuickFind.h"

std::mutex m;
std::condition_variable generater;
std::condition_variable finder;
std::condition_variable spyer;

bool isupdate = true;
bool issreach = false;
maps map;
vectors vector;

int main() {
	std::thread spythread(spy);
	std::thread generaterthread(create);
	std::thread findthread(find);
	spythread.join();
	generaterthread.join();
	findthread.join();

	return 0;
}
