#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    // Проверяем, был ли передан аргумент командной строки с путем к файлу
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <путь_к_файлу>" << std::endl;
        return 1; // Возвращаем код ошибки
    }
    
    // Открываем файл для чтения
    std::ifstream file(argv[1]);
    
    // Проверяем, был ли файл успешно открыт
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1; // Возвращаем код ошибки
    }
    
    // Строка для хранения содержимого файла
    std::string content;
    
    // Читаем файл построчно и добавляем каждую строку в переменную content
    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    
    // Выводим содержимое файла в консоль
    std::cout << "Содержимое файла:" << std::endl;
    std::cout << content << std::endl;
    
    // Закрываем файл
    file.close();
    
    return 0;
}
