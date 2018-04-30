//
// Created by SunStriKE on 2018/4/30.
//

#ifndef MODERN_C_SINGLETON_H
#define MODERN_C_SINGLETON_H

#include <pthread.h>
#include <mutex>
//假如有一个全局对象A 构造函数里引用上文中饿汉形式的指针，
//若在A构造函数构造之前以上单例并未构造出来，那就会有问题。
/*
class singleton {
protected:
    singleton() {}

private:
    static singleton *p;
public:
    static singleton *initance();
};

//懒汉实现
class singleton_lan
{
protected:
    singleton_lan() {}
public:
    static std::mutex _mutex;
    static singleton_lan* initance();
};
*/
template <typename T>
class Singleton
{
public:
    template<typename... Args>
    static T* Instance(Args&&... args)
    {
        if(m_pInstance==nullptr)
            m_pInstance = new T(std::forward<Args>(args)...);
        return m_pInstance;
    }
    static T* GetInstance() {
        if (m_pInstance == nullptr)
            throw std::logic_error("the instance is not init, "
                                   "please initialize the instance first");
        return m_pInstance;
    }
    static void DestroyInstance()
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }

private:
    Singleton(void);
    virtual ~Singleton(void);
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);
private:
    static T* m_pInstance;
};

template <class T> T*  Singleton<T>::m_pInstance = nullptr;

#endif //MODERN_C_SINGLETON_H
