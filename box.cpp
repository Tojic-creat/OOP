#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

// Класс Шарик
class Ball {
private:
    std::string color;
    
public:
    Ball(const std::string& c) : color(c) {}
    
    std::string getColor() const {
        return color;
    }
    
    std::string toString() const {
        return "Шарик (" + color + ")";
    }
};

// Класс Коробка
class Box {
private:
    std::string name;
    std::vector<Ball> balls;
    
public:
    Box(const std::string& n) : name(n) {}
    
    void addBall(const Ball& ball) {
        balls.push_back(ball);
        std::cout << ball.toString() 
                  << " добавлен в " << name << "\n";
    }
    
    void printInfo() const {
        std::cout << name << ": ";
        
        if (balls.empty()) {
            std::cout << "пустая\n";
            return;
        }
        
        std::cout << "всего " << balls.size() << " шариков\n";
        
        // Подсчет шариков по цветам
        std::map<std::string, int> colorCount;
        for (const auto& ball : balls) {
            colorCount[ball.getColor()]++;
        }
        
        for (const auto& pair : colorCount) {
            std::cout << "   - " << pair.first 
                      << ": " << pair.second << " шт.\n";
        }
    }
    
    int size() const {
        return balls.size();
    }
};

int main() {
    // Настройка генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1); // 0 или 1
    
    // Создаем коробки
    Box box1("Коробка №1");
    Box box2("Коробка №2");
    
    // Цвета 10 шариков
    std::vector<std::string> colors = {
        "красный", "синий", "зеленый", "желтый", "белый",
        "красный", "синий", "красный", "зеленый", "желтый"
    };
    
    std::cout << "========================================\n";
    std::cout << "РАСПРЕДЕЛЯЕМ ШАРИКИ ПО КОРОБКАМ\n";
    std::cout << "========================================\n";
    
    // Кладем шарики в случайные коробки
    for (const auto& color : colors) {
        Ball ball(color);
        if (dist(gen) == 0) {
            box1.addBall(ball);
        } else {
            box2.addBall(ball);
        }
    }
    
    std::cout << "\n========================================\n";
    std::cout << "ИТОГОВАЯ ИНФОРМАЦИЯ\n";
    std::cout << "========================================\n";
    
    box1.printInfo();
    std::cout << "\n";
    box2.printInfo();
    
    std::cout << "\nВсего шариков в обеих коробках: " 
              << (box1.size() + box2.size()) << "\n";
    
    return 0;
}