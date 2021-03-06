#ifndef MYSQLCONTROLLER_H
#define MYSQLCONTROLLER_H

//Singleton MySQLController для управления соединениями и запросами к базе данных
class MySQLController
{
//глобально доступные методы и поля
public:
    //статический метод для получения Singleton-на
    static MySQLController & Instance()
    {
        static MySQLController mysqlcontroller; //синглтон как-бы создаёт сам себя во время запроса
        return mysqlcontroller; //возвращаем класс
    }

//приватные методы и поля (доступны только внутри класса)
private:
    MySQLController(); //конструктор класса
    ~MySQLController(); //деструктор класса

    //Запрещаем копирование
    MySQLController(MySQLController const&);
    MySQLController & operator= (MySQLController const&);

};

#endif // MYSQLCONTROLLER_H
