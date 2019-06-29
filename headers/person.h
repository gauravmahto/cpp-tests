/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "field.h"

namespace cpptest
{

	class Data
	{
	public:
		Data() : m_id(0), m_name(L"") {}

		Data(const Data& rhs) = default;
		Data& operator=(const Data& rhs) = default;

		Data(Data&& rhs) = default;
		Data& operator=(Data&& rhs) = default;

		~Data() = default;

		template <class T>
		void SetId(T&& val)
		{
			m_id.SetValue(std::forward<T>(val));
		}

		const int& GetId() const
		{
			return m_id.GetValue();
		}

		template <class T>
		void SetName(T&& val)
		{
			m_name.SetValue(std::forward<T>(val));
		}

		const std::wstring& GetName() const
		{
			return m_name.GetValue();
		}

	private:
		Field<int> m_id{ 0 };
		Field<std::wstring> m_name{ L"" };
	};

	class Person
	{
	public:
		Person() = default;

		Person(const Person& rhs) = default;
		Person& operator=(const Person& rhs) = default;

		Person(Person&& rhs) = default;
		Person& operator=(Person&& rhs) = default;

		~Person() = default;

		template <class T>
		void SetData(T&& val)
		{
			m_person.SetValue(std::forward<T>(val));
		}

		const Data& GetData() const
		{
			return m_person.GetValue();
		}

	private:
		Field<Data> m_person{};
	};

}

#endif
