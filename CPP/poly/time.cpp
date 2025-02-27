#include <iostream>
using namespace std;

class Sum{
    private:
        double length,breadth,height;
    public:
        // constructor to initialize length, breadth and height
        Sum(double l, double b, double h){
            this->length = l;
            this->breadth = b;
            this->height = h;
        }
        // member function to calculate and return the volume of the cuboid
        double getVolume(){
            return length * breadth * height;
        }
        // member function to calculate and return the surface area of the cuboid
        double getSurfaceArea(){
            return 2 * (length * breadth + length * height + breadth * height);
        }
        // overloading + operator to add two cuboids
        Sum operator+(Sum& other){
            return Sum(length + other.length, breadth + other.breadth, height + other.height);
        }
};
int main()
{
    Sum cuboid1(5, 6, 7);
    Sum cuboid2(3, 4, 2);
    Sum sum = cuboid1 + cuboid2;
    cout << "Volume of cuboid1       : " << cuboid1.getVolume() << endl;
    cout << "Surface area of cuboid1 : " << cuboid1.getSurfaceArea() << endl;
    cout << "Volume of cuboid2       : " << cuboid2.getVolume() << endl;
    cout << "Surface area of cuboid2 : " << cuboid2.getSurfaceArea() << endl;
    cout << "Volume of sum of cuboids: " << sum.getVolume() << endl;
    cout << "Surface area of sum of  : " << sum.getSurfaceArea() << endl;

    return 0;
}