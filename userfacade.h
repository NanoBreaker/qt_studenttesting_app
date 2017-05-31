#ifndef USERFACADE_H
#define USERFACADE_H

//Шаблон проектирования фасад, для выбора интерфейса в зависимости от типа пользователя
class UserFacade
{
public:
    UserFacade(int _state); //конструктор
    ~UserFacade(); //деструктор

private:
    void initSuperUserInterface(); //Метод для инициализации интерфейса для администратора
    void initLecturerInterface(); //для преподователя
    void initRecDecInterface(); //для деканата/ректората
    void initStudentInreface(); //для студента
    int state;
};

#endif // USERFACADE_H
