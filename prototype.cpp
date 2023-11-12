#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Address{
    public:
    int building;
    Address(int b):building(b){}
};


class Shape {
public:
    //Address addr;
    virtual Shape* clone() = 0; 
    virtual void draw() = 0;  
    virtual ~Shape() {}
};


class Circle : public Shape {
private:
    double radius;
    
 
public:
    Address addr;
    int* ptr;
    Circle(double r,Address a, int* p) : radius(r),addr(a),ptr(p) {}
 
    Shape* clone() {
        return new Circle(*this);
    }
 
    void draw() {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
        cout<<"test: "<<addr.building<<endl;
        cout<<"ptr: "<<ptr<<endl;
    }
};


class Rectangle : public Shape {
private:
    double width;
    double height;
 
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
 
    Shape* clone() {
        return new Rectangle(*this);
    }
 
    void draw() {
        std::cout << "Drawing a rectangle with width " << width << " and height " << height << std::endl;
    }
};


int main(){
    int x = 5;
    int y = 6;
    int *test_ptr = &x;
    Address test(1);
    Circle circlePrototype(5.0,test,test_ptr);
    Rectangle rectanglePrototype(4.0, 6.0);

    
    Shape* shape1 = circlePrototype.clone();
    Shape* shape2 = rectanglePrototype.clone();

    shape1->draw(); 
    shape2->draw(); 

    circlePrototype.addr.building = 2;
    circlePrototype.ptr = &y;
    shape1->draw();
    circlePrototype.draw();

    /*Shape* shape3 = circlePrototype.clone();
    shape3->draw();*/
    
     

}