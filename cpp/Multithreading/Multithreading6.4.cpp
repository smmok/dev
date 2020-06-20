#include <thread>
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
#include <future>
#include <deque>

#include <experimental/filesystem>

namespace fs=std::experimental::filesystem;
using namespace std::experimental::filesystem;
using namespace std;

template<class T>
class MessageQueue
{
private:
	mutable mutex _mtx;
	deque<T> _messages;
	mutable condition_variable _cond;
public:
	void send(T msg)
	{
		lock_guard<mutex> lck(_mtx);
		_messages.push_back(move(msg));
		_cond.notify_one();
	}
	T receive()
	{
		unique_lock<mutex> lck(_mtx);
		_cond.wait(lck, [this] {return !_messages.empty(); });
		T msg = move(_messages.back());
		_messages.pop_back();
		return msg;
	}
};

//void listDir(string path, FileMonitor& fileSink)
//{
//	for (directory_iterator it(path); it != directory_iterator(); ++it)
//	{
//		if (is_regular_file(it->status()))
//		{
//			//fileSink.push_back(it->path().leaf());
//			fileSink.push_back(it->path().string());
//		}
//	}
//}
//
//void listDirs(vector<path> paths, FileMonitor& fileSink)
//{
//	vector<future<void>> futures;
//	for (auto& path : paths)
//	{
//		cout << path << endl;
//		futures.emplace_back(async(listDir, path.string(), ref(fileSink)));
//	}
//
//	for (;;)
//	{
//		string name = fileSink.pop_back();
//		cout << name << endl;
//	}
//
//	for (auto& fut : futures)
//	{
//		fut.wait();
//	}
//}
//
int main(int argc, char** argv)
{
	MessageQueue<path> queue;
	fs::path myPath = "44";
	future<void> fut = async([&queue, &myPath] {queue.send(myPath); });
	int i = stoi(queue.receive().u8string());
	cout << "Received: " << i << endl;
	fut.wait();

	return 0;
}
