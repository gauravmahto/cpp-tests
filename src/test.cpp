/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#include "iostream"

#include "person.h"

using namespace cpptest;

int main(void)
{

	// Data someone;

	// auto &id = someone.GetId();
	// auto &name = someone.GetName();

	// someone.SetId(1);
	// someone.SetName(L"Hi");

	// std::wcout << id << L" -- " << name << "\n";

	Person author{};
	auto authData = author.GetData();

	std::wcout << "-----------Before assignment-----------";
	std::wcout << authData.GetId() << L" -- " << authData.GetName() << "\n";

	authData.SetId(1);
	authData.SetName(L"Hi");
	author.SetData(std::move(authData));

	auto& authData2 = author.GetData();
	std::wcout << "-----------After assignment-----------";
	std::wcout << authData2.GetId() << L" -- " << authData2.GetName() << "\n";

	std::cin.get();

	return 0;

}
