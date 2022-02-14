#include <iostream>
class Singleton
{
public:
    static Singleton* getInstance() {
        if (instance == NULL) {
            instance = new Singleton();
        }
        return instance;
    }

private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton operator = (const Singleton&) = delete;
    Singleton operator = (Singleton&&) = delete;
    Singleton(Singleton &&) = delete;
    static Singleton* instance;

public:
    class Deletor {
    public:
        ~Deletor() {
            std::cout<<"~Deletor"<<std::endl;
            if (Singleton::instance)
                delete Singleton::instance;
        }

    };
    
    static Deletor deletor;
};

Singleton * Singleton::instance = NULL;
Singleton::Deletor Singleton::deletor;   //类内静态成员Deletor需要在类外初始化，否则连构造都不会有，何谈析构。

int main()
{
    Singleton::getInstance();
}