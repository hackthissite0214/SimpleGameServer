#pragma once

//	µ¿±âÈ­ °´Ã¼
class _SERVERCORE_DECLSPEC CriticalSection
{
public:
    CriticalSection();
    ~CriticalSection();

#if(_WIN32_WINNT >= 0x0400)
    BOOL TryLock();
#endif

    void Lock();
    void UnLock();

private:
    CriticalSection(const CriticalSection& cs) = delete;
    CriticalSection& operator=(const CriticalSection& cs) = delete;

private:
    CRITICAL_SECTION _cs;
};

class _SERVERCORE_DECLSPEC LockGuard
{
public:
    explicit LockGuard(CriticalSection& owner);
    ~LockGuard();

private:
    LockGuard(const LockGuard& lockGuard) = delete;
    LockGuard& operator=(const LockGuard& lockGuard) = delete;

private:
    CriticalSection& _owner;
};
