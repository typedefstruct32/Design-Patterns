//带参数的单例模式，延迟初始化，懒汉模式

#include <iostream>
#include <cassert>

class Singleton
{
public:
    static Singleton& get_instance(){
        static Singleton instance(m_param);  //静态局部变量
        //m_param = param;  静态成员不能在类中初始化
        std::cout<<"get_instance"<<std::endl;
        return instance;
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

};

int Singleton::m_param = 1;  //静态成员函数只能在类外初始化

int main()
{
    auto &a = Singleton::get_instance();
    auto &b = Singleton::get_instance();
    assert(&a == &b);
    Singleton::m_param = 3;
    std::cout<< Singleton::get_instance().m_storage;
}