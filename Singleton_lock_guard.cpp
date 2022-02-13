//线程安全的单例模式，使用lock_guard

#include <iostream>
#include <mutex>

class Singleton
{
public:
    static Singleton& get_instance(){
        std::lock_guard<std::mutex> lk(_m);
        if (!_instance) {
            _instance = new Singleton();
        }
        return *_instance;
       
    }
    static int m_param;  //只能在类内声明,不能初始化
    int m_storage;

private:
    Singleton(int m) : m_storage(m) {}
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator = (const Singleton &) = delete;
    Singleton &operator = (Singleton &&) = delete;
    static std::mutex _m;
    static Singleton* _instance;

};

int Singleton::m_param = 1;  //静态成员函数只能在类外定义 + 初始化
Singleton* Singleton::_instance;
std::mutex Singleton::_m;

int main()
{
    Singleton::m_param = 3;
    Singleton& s1 = Singleton::get_instance();
    std::cout<<s1.m_storage;
}