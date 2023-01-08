#include "pch.h"
#include "Singleton.h"

std::set<Singleton*> Singleton::S_singletons;

Singleton::Singleton()
{
	//	TEMP : Singleton ??
	S_singletons.insert(this);
}

Singleton::~Singleton()
{
	auto it = S_singletons.find(this);

	if (it != S_singletons.end())
		S_singletons.erase(it);
}

void Singleton::Release()
{

}

void Singleton::ReleaseAll()
{
	for (auto singleton : S_singletons)
		singleton->Release();

	S_singletons.clear();
}
