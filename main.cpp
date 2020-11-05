#include <bits/stdc++.h>
#include "./linker.h"
#include "./drone.h"
#include "./pid.h"


void pid_caller(std::future<void> futureObj);

int main() {
	Linker::give_command(INITIAL_COMMAND);
	Linker::give_error(INITIAL_ERROR);

	std::cout << "Welcome to PID simulator. The simulator is starting now..." << std::endl;
	// make a mechanism to stop the thread at the end
	std::promise<void> exitSignal;
	std::future<void> futureObj = exitSignal.get_future();

	// strat the pid thread
	std::thread pid_thread(pid_caller, std::move(futureObj));

	// start the drone
	start_drone(SIM_TIME);

	std::cout << "Well done, the simulater is shuting down..." << std::endl;
	// the simulation ends
	exitSignal.set_value();
	pid_thread.join();

	std::cout << "Have a nice day :)" << std::endl;
	return 0;
}

void pid_caller(std::future<void> futureObj) {
	while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
		loop();
	}
}