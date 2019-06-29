/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#ifndef FIELD_H
#define FIELD_H

#include <memory>

namespace cpptest
{

	template <class T>
	class Field
	{
	public:
		Field() = default;

		Field(T&& val) : m_ptrVal(std::make_unique<T>(std::forward<T>(val))) {}

		Field(const Field<T>& rhs)
		{
			Clone(rhs);
		};
		Field& operator=(const Field<T>& rhs)
		{
			if (this != *rhs)
			{
				Clone(rhs);
			}

			return (*this);
		}

		Field(Field<T>&& rhs) = default;
		Field<T>& operator=(Field<T>&& rhs) = default;

		~Field() = default;

		void SetValue(T&& val)
		{
			CheckAndMakeValue();
			*m_ptrVal = std::forward<T>(val);
		}

		T& GetValue()
		{
			CheckAndMakeValue();

			return (*m_ptrVal);
		}

		const T& GetValue() const
		{
			CheckAndMakeValue();

			return (*m_ptrVal);
		}

	private:
		void CheckAndMakeValue() const
		{
			if (!m_ptrVal)
			{
				m_ptrVal = std::make_unique<T>();
			}
		}

		void Clone(const Field<T>& rhs)
		{
			if (rhs.m_ptrVal.get())
			{
				CheckAndMakeValue();
				*m_ptrVal = *rhs.m_ptrVal;
			}
		}

		mutable std::unique_ptr<T> m_ptrVal{};
	};

}

#endif
