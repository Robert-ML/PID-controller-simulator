#include "./linker.h"

Linker* Linker::instance = NULL;

Linker* Linker::get_instance() {
	if (instance == NULL) {
		instance = new Linker();
	}
	return instance;
}

void Linker::give_command(int _command) {
	std::lock_guard	<std::mutex> guard(Linker::get_instance()->command_mutex);
	Linker::get_instance()->command = _command;
}

// you are not allowed to call this funciton
int Linker::get_command() {
	std::lock_guard	<std::mutex> guard(Linker::get_instance()->command_mutex);
	return Linker::get_instance()->command;
}

// you are not allowed to call this funciton
void Linker::give_error(double _error) {
	std::lock_guard	<std::mutex> guard(Linker::get_instance()->error_mutex);
	Linker::get_instance()->error = _error;
}

double Linker::get_error() {
	std::lock_guard	<std::mutex> guard(Linker::get_instance()->error_mutex);
	return Linker::get_instance()->error;
}