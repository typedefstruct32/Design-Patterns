//线程安全的单例模式，使用lock_guard

#include <iostream>
#include <mutex>

class Singleton
{
public:
    static Singleton* get_instance(){
        std::lock_guard<std::mutex> lk(_m);
        if (!_instance) {
            _instance = new Singleton(m_param);
        }
        //_instance(m_param);
        return _instance;
       
    }
    static int m_param;  //只能在类内声明,不能初始化
    int m_storage;

private:
    Singleton(int m) : m_storage(m) {}
    ~Singleton() {
       // delete _instance;
        std::cout<<"instance is deleted";
    }
    Singleton() = default;
    //~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator = (const Singleton &) = delete;
    Singleton &operator = (Singleton &&) = delete;
    static std::mutex _m;
    static Singleton* _instance;
    //static Singleton _instance;

};

int Singleton::m_param = 1;  //静态成员函数只能在类外定义 + 初始化
Singleton* Singleton::_instance = 0;  //如果这里不进行初始化，只是定义，可能_instance的初始化顺序不固定（在运行时）
//Singleton Singleton::_instance(m_param);
std::mutex Singleton::_m;

int main()
{
    Singleton::m_param = 3;
    std::cout<<Singleton::get_instance()->m_storage;
}