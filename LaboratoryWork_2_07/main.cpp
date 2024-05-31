#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <chrono>


std::mutex mtx;
std::condition_variable condition;
std::vector<std::string> completed_threads;

void fibonacci(size_t f1, size_t f2, size_t i, size_t n, std::string thread_name)
{
	if (i <= n)
	{
		std::unique_lock<std::mutex> ul(mtx);
		std::cout << "thread: " << thread_name << "\t id: " << std::this_thread::get_id() << "\t value: " << f1 << std::endl;
		ul.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		fibonacci(f2, f1 + f2, i + 1, n, thread_name);
	}
	else 
	{
		std::unique_lock<std::mutex> cmpl(mtx);

		completed_threads.push_back(thread_name);
		condition.notify_one();
	}
}

void natural_numbers(unsigned n, std::string thread_name)
{
	for (unsigned i = 1; i < n + 1; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::unique_lock<std::mutex> ul(mtx);
		std::cout << "thread: " << thread_name << "\t id: " << std::this_thread::get_id() << "\t value: " << i << std::endl;
	}
	std::unique_lock<std::mutex> cmpl(mtx);
	completed_threads.push_back(thread_name);
	condition.notify_one();
}

void random_numbers(unsigned n, std::string thread_name)
{
	srand(time(0));
	for (unsigned i = 0; i < n; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::unique_lock<std::mutex> ul(mtx);
		std::cout << "thread: " << thread_name << "\t id: " << std::this_thread::get_id() << "\t value: " << rand() % 100 << std::endl;
	}
	std::unique_lock<std::mutex> cmpl(mtx);
	completed_threads.push_back(thread_name);
	condition.notify_one();
}

void thread_complete()
{
	size_t count_completed_threads = 0;
	while (count_completed_threads != 3) 
	{
		std::unique_lock<std::mutex> cmpl(mtx);
		condition.wait(cmpl);
		std::cout << "===================== completed " << completed_threads[count_completed_threads] << " =====================" << std::endl;
		count_completed_threads++;
	}
}

int main()
{

	auto start = std::chrono::high_resolution_clock::now();

	srand(time(0));

	int n1, n2, n3;
	std::cout << "Enter n1, n2, n3: ";
	std::cin >> n1 >> n2 >> n3;

	std::thread thread1(fibonacci, 1, 1, 1, n1,  "thread1");
	std::thread thread2(natural_numbers, n2, "thread2");
	std::thread thread3(random_numbers, n3, "thread3");
	std::thread thread4(thread_complete);

	thread1.detach();
	thread2.detach();
	thread3.detach();
	thread4.join();

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "=============== Child threads are completed ==================" << std::endl;
	std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

	return 0;
}