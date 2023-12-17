#include <iostream>

using namespace std;

// Базовый класс
class Device {
public:
    string manufacturer;
    string model;
    string name;
    int capacity;
    int quantity;

    virtual void print() {
        cout << "Device: " << name << ", Manuf. name: " << manufacturer << ", Model: " << model << ", Capacity: " << capacity << ", Count: " << quantity << ";\n";
    }

    virtual void load() {
        cout << name << " has been loaded\n";
    }

    virtual void save() {
        cout << "Data on the " << name << " has been saved\n";
    }
};

// Производный класс
class FlashDrive : public Device {
public:
    void print() {
        manufacturer = "Kingston's";
        model = "DTMAXA";
        name = "Kingston DataTraveler Max Red";
        capacity = 512;
        quantity = 110;
        cout << "Device: Flash Drive, ";
        Device::print();
    }

    void load() {
        cout << "Flash drive has been loaded\n";
    }

    void save() {
        cout << "Data on the flash drive has been saved\n";
    }
};

// Производный класс
class HardDrive : public Device {
public:
    void print() {
        manufacturer = "Toshiba";
        model = "P300";
        name = "Toshiba P300 1TB 7200rpm 64MB HDWD110UZSVA 3.5 SATA III";
        capacity = 1024;
        quantity = 63;
        cout << "Device: Hard Drive, ";
        Device::print();
    }

    void load() {
        cout << "Hard Drive has been loaded\n";
    }

    void save() {
        cout << "Data on the hard drive has been saved\n";
    }
};

// Производный класс
class Phone : public Device {
public:
    void print() {
        manufacturer = "Samsung";
        model = "F731B";
        name = "Galaxy Flip5";
        capacity = 8;
        quantity = 255;
        cout << "Device: Telephone, ";
        Device::print();
    }

    void load() {
        cout << "Telephone has been loaded\n";
    }

    void save() {
        cout << "Data on the telephone has been saved\n";
    }
};

int main() {
    int count = 3;

    Device** device = new Device * [count];

    device[0] = new FlashDrive;
    device[1] = new HardDrive;
    device[2] = new Phone;

    for (int i = 0; i < count; i++)
    {
        device[i]->print();
        device[i]->load();
        cout << "///////////////\n";
    }

    for (int i = 0; i < count; i++)
    {
        delete device[i];
    }
    delete[] device;

    return 0;
}