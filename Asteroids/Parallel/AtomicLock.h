#ifndef ATOMIC_LOCK
#define ATOMIC_LOCK
#include <atomic>

class AtomicLock
{
private:
	std::atomic_flag f = ATOMIC_FLAG_INIT;
public:
	AtomicLock();
	void lock();
	void unlock();
	~AtomicLock();
};

#endif