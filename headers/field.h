/*!
  * Copyright 2019 - Author gauravm.git@gmail.com
  */

#ifndef FIELD_H
#define FIELD_H

namespace cpptest 
{

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

}

#endif
