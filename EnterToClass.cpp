#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

class Power
{
public:
    int x = 3;
    int y = 7;

    Power(int one = 3, int two = 7)
    {
        x = one;
        y = two;
        
    }

    void set()
    {
        int x = 3;
        int y = 5;
        int z = 7;
    }

    void calculate()
    {
        double x = 3, y = 7;
        cout << pow(x, y);
    }
};

class RGBA
{
public:

    using component_type = std::uint8_t;

private:
    component_type  m_red;
    component_type  m_green;
    component_type  m_blue;
    component_type  m_alpha;

public:

    RGBA(component_type red = 0, component_type green = 0, component_type blue = 0,
        component_type alpha = 255):
        m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
    {
    }

    void print()
    {
        cout << "r=" << static_cast<int>(m_red) <<
            "g=" << static_cast<int>(m_green) <<
            "b=" << static_cast<int>(m_blue) <<
            "a=" << static_cast<int>(m_alpha) << '\n';
    }
};

class STACK
{
private:
int MyArray[10];
int index;

public:

    void reset()
    {
        index = 0;
        for (int i = 0; i < 10; ++i)
            MyArray[i] = 0;
    }

    bool push(int value)
    {
        if (index == 10)
            return false;

        MyArray[index++] = value; 
        return true;
    }

    int pop()
    {
        assert(index > 0);

        return MyArray[--index];
    }

    void print()
    {
        cout << "( ";
        for (int i = 0; i < index; ++i)
            cout << MyArray[i] << ' ';
        cout << ")\n";
    }
};

int main(int argc, char* argv[])
{
    STACK stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}