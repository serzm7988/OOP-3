#include <iostream>
#include <cmath>
#include <string>
#include <iterator>
#include "container.cpp"

class Device
{
public:
    friend void write_Device(Device, std::string);
    friend class Decorator_Device;
    friend class Decorator_Computer;
    int serial_number;
private:
    void turn_on() {
        std::cout << "Device is on";
    }
    std::string operator+ (int s)
    {
        std::string sum = serial_number + "."+  s;
        return (sum);
    }
};

class Computer : private Device {
    friend class Decorator_Computer;
public:
    void say_hello() {
        std::cout << std::endl << "Welcome to Windows 95!" << std::endl;
    }
};

class Decorator_Device : public Device {
protected:
    Device device_;

public:
    Decorator_Device(Device device) : device_(device) {
    }
    void turn_onn()
    {
        std::cout << '[';
        this->device_.turn_on();
        std::cout << ']'<<std::endl;;
    }
};

class Decorator_Computer : public Computer {
protected:
    Computer device_;

public:
    Decorator_Computer(Computer device) : device_(device) {
    }
    void turn_onn()
    {
        std::cout << '[';
        this->device_.turn_on();
        std::cout << ']';
    }
};

void write_Device(Device Device_instance)
{
    Decorator_Device dec = Device(Device_instance);
    std::cout << "\t Device" << std::endl;
    std::cout << "Serial number is: " << Device_instance.serial_number << std::endl;
    dec.turn_onn();
}

void write_Computer(Computer Device_instance)
{
    Decorator_Computer dec = Computer(Device_instance);
    std::cout << std::endl << "\t Computer" << std::endl;
    dec.turn_onn();
}
void swap(list<Device> y, list<Device> x) {
    list<Device> z = y;
    y = x;
    x = z;
}

int main() 
{
    list<Device> the_list;
    list<Device>::iterator list_iter;

    for (int i=0; i < 5;i++) {
        Device Device_instance;
        Device_instance.serial_number = rand() % 1000 + 1;
        std::cout << Device_instance.serial_number << std::endl;
        the_list.add(Device_instance);
    }
    write_Device(*the_list.begin());
    write_Device(*(++the_list.begin()));
    Computer  Computer_instance;
    Computer_instance.say_hello();
    return 0;
}