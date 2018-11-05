#include "AtomicLock.h"

AtomicLock::AtomicLock()
{
}

void AtomicLock::lock()
{
	while (f.test_and_set()) {}
}

void AtomicLock::unlock()
{
	f.clear();
}

AtomicLock::~AtomicLock()
{
}
