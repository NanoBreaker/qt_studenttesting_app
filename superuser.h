#ifndef SUPERUSER_H
#define SUPERUSER_H

//Singleton SuperUser для управления пользователями
class SuperUser
{
//глобально доступные методы и поля
public:
    //статический метод для получения Singleton-на
    static SuperUser & Instance()
    {
        static SuperUser superUser; //синглтон как-бы создаёт сам себя во время запроса
        return superUser; //возвращаем класс
    }

//приватные методы и поля (доступны только внутри класса)
private:
    SuperUser(); //конструктор класса
    ~SuperUser(); //деструктор класса

    //Запрещаем копирование
    SuperUser(SuperUser const&);
    SuperUser & operator= (SuperUser const&);

};

#endif // SUPERUSER_H
