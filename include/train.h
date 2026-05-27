// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Car {
        bool light;     // состояние лампочки
        Car* next;      // указатель на следующий вагон
        Car* prev;      // указатель на предыдущий вагон

        explicit Car(bool light_state);  // конструктор вагона
    };

    int count_op_;      // счетчик шагов (число переходов)
    Car* first_;        // точка входа в поезд (первый вагон)
    int real_length_;   // реальная длина поезда

 public:
    Train();                            // конструктор
    ~Train();                           // деструктор

    void AddCar(bool light);            // добавить вагон
    int GetLength();                    // вычислить длину поезда
    int GetOpCount() const;             // вернуть число переходов
    int GetRealLength() const;          // вернуть реальную длину
    void Clear();                       // очистить поезд

 private:
    // Запрещаем копирование
    Train(const Train&);
    Train& operator=(const Train&);
};
#endif  // INCLUDE_TRAIN_H_
