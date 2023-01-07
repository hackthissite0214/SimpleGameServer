#include "pch.h"
#include "CriticalSection.h"

CriticalSection::CriticalSection()
{
	::InitializeCriticalSection(&_cs);
}

CriticalSection::~CriticalSection()
{
	::DeleteCriticalSection(&_cs);
}

BOOL CriticalSection::TryLock()
{
	return ::TryEnterCriticalSection(&_cs);
}

void CriticalSection::Lock()
{
	::EnterCriticalSection(&_cs);
}

void CriticalSection::UnLock()
{
	::LeaveCriticalSection(&_cs);
}

LockGuard::LockGuard(CriticalSection& owner)
	: _owner(owner)
{
	_owner.Lock();
}

LockGuard::~LockGuard()
{
	_owner.UnLock();
}
