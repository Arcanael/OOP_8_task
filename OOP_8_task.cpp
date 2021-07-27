#include <iostream>
#include <string>
using namespace std;
using namespace std;


template <typename  T>
T div (T t1, T t2)
{
    if (t2 == 0) { throw 1; }
    return t1 / t2;
}

//int main()
//{
//    setlocale(LC_ALL, "Russian");
//
//    try
//    {
//        cout << "Деление 4 на 2\n" << to_string(div<int>(4, 2)) << endl; 
//        cout << "Деление 4 на 0\n" <<endl; 
//        cout << to_string(div<int>(4, 0)) << endl;
//    }
//    catch (int)
//    {
//        cout << "исключение деление на 0\n" << endl;
//    }
//
//
//    std::cout << "Hello World!\n";
//}

class Ex
{
private:
        int x;
public:
    
Ex(int a) : x(a) {};
int getX()
{
    return x;
}
};

class Bar
{
private:
    int y;
public:
    Bar(int a=0) : y(a) {};
    void set (int a)
    { 
        if (y + a > 100) 
        {
            throw Ex(y*a);
        }
        else
        {
            y = a;
        }
    
    }
};


//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    Bar bar;
//    int n;
//    try
//    {
//        while(true)
//        {
//            cout << "введите n " << endl;
//            cin >> n; 
//            if (n == 0) 
//            { 
//                break; 
//            }
//            bar.set(n);
//        }
//        
//    }
//    catch (Ex s)
//    {
//        cout << "сработало исключение " << endl << " данные исключения  " << s.getX() << endl;
//    }
//
//
//    
//}


class OffTheField
{
private:
    string m_error = "out of field";
    int x;
    int y;
    string direction;

public:
    OffTheField(int a, int b, string s) : x(a), y(b), direction(s)
    { }

    const char* getError() { return m_error.c_str(); }
    string getStrErr() { return " Координата х = " + to_string(x) + " координата у = " + to_string(y) + " направление " + direction; }
};


class IllegalCommand
{
private:
    string m_error = "Illegal Command";
    int direction;

public:
    IllegalCommand(int a) : direction(a)
    { }

    const char* getError() { return m_error.c_str(); }
    string getStrErr()
    {
        return "Введенное направление не явлется допустимым (1-4). Введено значение" + to_string(direction);
    }
};

class Robot 
{
private:
    int x;
    int y;
public:
    Robot(int a = 0, int b = 0): x(a),y(b){};
    
    void move(int s, int c=1)
    {
        string condX = "x+c<0 || 10<x+c"; 
        string condY = "y+c<0 || 10<y+c";
        if (s < 1 || s> 4 ) 
        { 
            throw IllegalCommand(s); 
        }
        switch (s)
        {
        case 1:
            if(y + c < 0 || 10 < y + c)
            {
                throw OffTheField(x, y, "up");
            }
            else { y += c; }
                break;
        case 2:
            if (y - c < 0 || 10 < y - c)
            {
                throw OffTheField(x, y, "down");
            }
            else { y -= c; }
                break;

        case 3:
            if (x + c < 0 || 10 < x + c)
            {
                throw OffTheField(x, y, "left");
            }
            else { x += c; }
            break;
        case 4:
            if (x - c < 0 || 10 < x - c)
            {
                throw OffTheField(x, y, "right");
            }
            else { x -= c; }
            break;
            
        default:
            cout << "Didnt move!\n";
                break;
        }
    }
};








int main()
{
    setlocale(LC_ALL, "Russian");
    Robot robo (0,0);
    int d;
    int f;
    try
    {
        while (true)
        {
            cout << "Введите направление движения 1 вверх 2 вниз 3 влево 4 вправо " << endl;
            cin >> d; 
            cout << "Введите дальность перемещения " << endl;
            cin >> f;
            robo.move(d, f);
             
        }

    }
    catch (OffTheField o)
    {
        cout << "сработало исключение " << endl << " данные исключения  " << o.getError()<< " " <<o.getStrErr() << endl;
    }
    catch (IllegalCommand i)
    {
        cout << "сработало исключение " << endl << " данные исключения  " << i.getError() << " " << i.getStrErr() << endl;
    }


    
}added text
another added text
