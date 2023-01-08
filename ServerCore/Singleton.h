#pragma once

#pragma warning(disable: 4251)

class _SERVERCORE_DECLSPEC Singleton
{
public:
    Singleton();
    virtual ~Singleton();

public:
    virtual void    Release() = 0;
    static  void    ReleaseAll();

private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static std::set<Singleton*>   S_singletons;
};

#define DECLEAR_SINGLETON(name)			\
public:									\
	static	name*	Instance();			\
	virtual void	Release();			\
private:								\
	static	name*	_instance;


#define IMPLEMENT_SINGLETON( name )		\
	name* name::_instance = nullptr;	\
	name* name::Instance()				\
	{									\
		if ( nullptr == _instance )		\
		{								\
			_instance = new name;		\
		}								\
		return _instance;				\
	}									\
	void name::Release()				\
	{									\
		if ( nullptr != _instance )		\
		{								\
		delete _instance;				\
		_instance = nullptr;			\
		}								\
	}