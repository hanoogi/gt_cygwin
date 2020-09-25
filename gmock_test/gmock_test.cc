#include <iostream>
#include <string>
using namespace std;
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Unit
{
    public:
        // Unit을 상속받는 형태로 Mock을 생성해야 하기 때문에
        // 반드시 가상 소멸자를 제공해야 한다.
        virtual ~Unit() {}

        virtual void stop() = 0;
        virtual void say(const string& message) = 0;
        virtual void attack(Unit* target) = 0;
        virtual void move(int x, int y) = 0;
        virtual int getX() const = 0;
        virtual int getY() const = 0;
};

// 함수 매크로를 통해서 MOCK을 수행하는 방법
//  1. MOCK_METHOD{파라미터 개수}  (함수명, 함수타입)
//  2. MOCK_CONST_METHOD{파라미터 개수}(함수명, 함수타입)
// 아래의 코드를 직접 작성하는것이 아니라, 생성하는 도구가 제공됩니다.
// googlemock/scripts/generator/gmock_gen.py

class MockUnit:public Unit{
    public:
        MOCK_METHOD0(stop, void());
        MOCK_METHOD1(say, void(const string& message));
        MOCK_METHOD1(attack, void(Unit* target));
        MOCK_METHOD2(move, void(int x, int y));
        MOCK_CONST_METHOD0(getX, int());
        MOCK_CONST_METHOD0(getY, int());
};

// 행위기반 검증
// 1. 호출 여부 검증 => EXPECT_CALL
// 2. 호출 횟수 검증 => EXPECT_CALL.Times()
// 3. 호출 순서 검증 => InSequence seq
// 4. 인자 검증 => _

void foo(MockUnit* p){
    p->stop();
}

TEST(MockUnitTest, Sample1)
{
    // 1.mock 생성
    MockUnit mock;

    // 2. 기대 행위를 명시한다.
    EXPECT_CALL(mock, stop());

    // 3. mock이 적용된 코드를 실행한다.
    foo(&mock);
}

void goo(MockUnit* p)
{
    p->stop();
    p->stop();
}


// 2. 호출 횟수 검증
using :: testing::AnyNumber;
TEST(MockUnitTest, Sample2)
{

    MockUnit mock;
    //EXPECT_CALL(mock, stop()).Times(2);
    EXPECT_CALL(mock, stop()).Times(AnyNumber());

    goo(&mock);
}

void hoo(MockUnit* p)
{
    p->attack(nullptr);
    p->move(10, 20);
}

// 3. 호출인자 검증
using::testing::_;
TEST(MockUnitTest, Sample3){
    MockUnit mock;

    EXPECT_CALL(mock, move(10, _));
    EXPECT_CALL(mock, attack(_));

    hoo(&mock);
}

// 4. 호출 순서 검증
using::testing::InSequence;
TEST(MockUnitTest, Sample4)
{
    // 순서의 검증이 필요하다면, 아래 객체만 추가하면 됩니다.
    InSequence seq;
    MockUnit mock;


}

class Time{
    public:
        string getTimeString(){
            return "12:56";
        }
};

class MockTime: public Time{
    public:
        MOCK_METHOD0(getTimeString, string());

};

using ::testing::Return;
TEST(TimeTest, Sample)
{
    MockTime stub;
    ON_CALL(stub, getTimeString()).WillByDefault(Return("00:00"));

    cout << stub.getTimeString() << endl;

}

// 실행방법
// g++ 파일명.cc -c
// g++ 파일명.o -lgtest -lgmock -lgmock_maind -lpthread
// ./a.exe