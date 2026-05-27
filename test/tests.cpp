#include "gtest/gtest.h"
#include "train.h"

TEST(lab8_test1, test1) {
    Train train;
    train.AddCar(false);
    train.AddCar(false);
    train.AddCar(false);
    int len = train.GetLength();
    int op = train.GetOpCount();
    EXPECT_EQ(len, 3);
    EXPECT_GT(op, 0);
}

TEST(lab8_test2, test2) {
    Train train;
    train.AddCar(false);
    train.AddCar(false);
    train.AddCar(false);
    train.AddCar(false);
    int len = train.GetLength();
    int op = train.GetOpCount();
    EXPECT_EQ(len, 4);
    EXPECT_GT(op, 0);
}

TEST(lab8_test3, test3) {
    Train train;
    train.AddCar(false);
    train.AddCar(true);
    train.AddCar(false);
    int len = train.GetLength();
    int op = train.GetOpCount();
    EXPECT_EQ(len, 3);
    EXPECT_GT(op, 0);
}

TEST(lab8_test4, test4) {
    Train train;
    train.AddCar(true);
    train.AddCar(true);
    train.AddCar(true);
    int len = train.GetLength();
    int op = train.GetOpCount();
    EXPECT_EQ(len, 3);
    EXPECT_GT(op, 0);
}

TEST(lab8_test5, test5) {
    Train train;
    train.AddCar(true);
    train.AddCar(false);
    train.AddCar(true);
    train.AddCar(false);
    int len = train.GetLength();
    int op = train.GetOpCount();
    EXPECT_EQ(len, 4);
    EXPECT_GT(op, 0);
}
