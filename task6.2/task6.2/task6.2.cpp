#include <iostream>
#include <cstdio>

const int maxSize = 1000;

struct Shape {
    char type;
    union {
        struct {
            double radius;
        } krug;
        struct {
            double a;
            double b;
        } rectangle;
    };
    bool isPainted;

    Shape() : type('\0'), isPainted(false) {
        krug.radius = 0.0;
        rectangle.a = 0.0;
        rectangle.b = 0.0;
    }

    Shape(char t, double r, bool painted = false) {
        type = t;
        krug.radius = r;
        isPainted = painted;
    }

    Shape(char t, double sideA, double sideB, bool painted = false) {
        type = t;
        rectangle.a = sideA;
        rectangle.b = sideB;
        isPainted = painted;
    }

    void print() {
        if (type == 'K') {
            printf("Circle, radius: %f\n", krug.radius);
        }
        else if (type == 'R') {
            printf("Rectangle, sides: %f, %f\n", rectangle.a, rectangle.b);
        }
        else {
            printf("Unknown shape\n");
        }
    }
};

void printMass(Shape* shapes, int countShape) {
    for (int i = 0; i < countShape; ++i) {
        shapes[i].print();
    }
    printf("\n");
}

void addShape(int& countShape, Shape* shapes) {
    if (countShape >= maxSize) {
        printf("Error: Maximum number of shapes reached.\n");
        return;
    }
    char type;
    printf("Press K for circle, press R for rectangle: ");
    scanf_s(" %c", &type);
    if (type == 'K') {
        printf("Enter radius: ");
        double radius;
        scanf_s("%lf", &radius);
        shapes[countShape++] = Shape('K', radius);
    }
    else if (type == 'R') {
        double a, b;
        printf("Enter side a: ");
        scanf_s("%lf", &a);
        printf("Enter side b: ");
        scanf_s("%lf", &b);
        shapes[countShape++] = Shape('R', a, b);
    }
    else {
        printf("Error: Invalid shape type.\n");
    }
}

void deleteShape(Shape* shapes, int& countShape) {
    if (countShape == 0) {
        printf("Error: No shapes to delete.\n");
        return;
    }
    int delIndex;
    printf("Enter index of shape to delete: ");
    scanf_s("%d", &delIndex);
    if (delIndex >= 0 && delIndex < countShape) {
        for (int i = delIndex; i < countShape - 1; i++) {
            shapes[i] = shapes[i + 1];
        }
        countShape--;
    }
    else {
        printf("Error: Invalid index.\n");
    }
}

void menu(Shape* shapes, int& countShape) {
    int choice;
    do {
        printf("1. Add shape\n");
        printf("2. Delete shape\n");
        printf("3. Print shapes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addShape(countShape, shapes);
            break;
        case 2:
            deleteShape(shapes, countShape);
            break;
        case 3:
            printMass(shapes, countShape);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    Shape shapes[maxSize];
    int countShape = 0;

    menu(shapes, countShape);
    return 0;
}