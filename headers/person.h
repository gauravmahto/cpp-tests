/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#ifndef PERSON_H
#define PERSON_H

#include "string"

#include "field.h"

namespace cpptest 
{

  class Data
  {
  public:
    constexpr Data() = default;

    constexpr Data(const Data &rhs) = default;
    Data &operator=(const Data &rhs) = default;

    constexpr Data(Data &&rhs) = default;
    constexpr Data &operator=(Data &&rhs) = default;

    ~Data() = default;

    template <class T>
    constexpr void SetId(T &&val)
    {
      m_id.SetValue(std::forward<T>(val));
    }

    constexpr const int &GetId() const
    {
      return m_id.GetValue();
    }

    template <class T>
    constexpr void SetName(T &&val)
    {
      m_name.SetValue(std::forward<T>(val));
    }

    constexpr const std::wstring &GetName() const
    {
      return m_name.GetValue();
    }

  private:
    Field<int> m_id;
    Field<std::wstring> m_name;
  };

  class Person
  {
  public:
    constexpr Person() = default;

    Person(const Person &rhs) = default;
    Person &operator=(const Person &rhs) = default;

    Person(Person &&rhs) = default;
    Person &operator=(Person &&rhs) = default;

    ~Person() = default;

    template <class T>
    constexpr void SetData(T &&val)
    {
      m_person.SetValue(std::forward<T>(val));
    }

    constexpr const Data &GetData() const
    {
      return m_person.GetValue();
    }

  private:
    Field<Data> m_person;
  };

}

#endif
