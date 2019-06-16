/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#include "iostream"
#include "memory"
#include "string"

template <class T>
class Field
{
public:
  constexpr Field() = default;

  constexpr Field(const Field<T> &rhs)
  {
    Clone(rhs);
  };
  constexpr Field &operator=(const Field<T> &rhs)
  {
    if (this != *rhs)
    {
      Clone(rhs);
    }

    return (*this);
  }

  constexpr Field(Field<T> &&rhs) = default;
  constexpr Field<T> &operator=(Field<T> &&rhs) = default;

  ~Field() = default;

  constexpr void SetValue(T &&val)
  {
    CheckAndMakeValue();
    *m_ptrVal = std::forward<T>(val);
  }

  constexpr T &GetValue()
  {
    CheckAndMakeValue();

    return (*m_ptrVal);
  }

  constexpr const T &GetValue() const
  {
    CheckAndMakeValue();

    return (*m_ptrVal);
  }

private:
  constexpr void CheckAndMakeValue() const
  {
    if (!m_ptrVal)
    {
      m_ptrVal = std::make_unique<T>();
    }
  }

  constexpr void Clone(const Field<T> &rhs)
  {
    if (rhs.m_ptrVal.get())
    {
      CheckAndMakeValue();
      *m_ptrVal = *rhs.m_ptrVal;
    }
  }
  mutable std::unique_ptr<T> m_ptrVal;
};

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

void main(void)
{
  // Data someone;

  // auto &id = someone.GetId();
  // auto &name = someone.GetName();

  // someone.SetId(1);
  // someone.SetName(L"Hi");

  // std::wcout << id << L" -- " << name << "\n";

  Person author;
  auto authData = author.GetData();

  std::wcout << "-----------Before assignment-----------";
  std::wcout << authData.GetId() << L" -- " << authData.GetName() << "\n";

  authData.SetId(1);
  authData.SetName(L"Hi");
  author.SetData(std::move(authData));

  auto &authData2 = author.GetData();
  std::wcout << "-----------After assignment-----------";
  std::wcout << authData2.GetId() << L" -- " << authData2.GetName() << "\n";

  std::cin.get();
}
