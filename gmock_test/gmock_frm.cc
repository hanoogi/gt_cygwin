#include <iostream>
using namespace std;
struct IMP3
{
    virtual void play() = 0;
    virtual ~IMP3() {}
};

class iPod : public IMP3
{
    public:
    void play() override{
        cout << "play mp3 with IPOD" <<endl;
    }
};

class Person
{
    public:
    void playMp3(IMP3* mp3)
    {
        mp3->play();
    }
};
#include "gtest/gtest.h"

// Person의 playMp3() -> mp3->play() 검증
// : 함수를 호출하였을 때 발생하는 부작용을 관찰할 수 없어
//   테스트 안된 요구사항이 있다면 모의 객체를 사용하자.
// => 행위 기반 테스트

// 모의 객체는 직접구현해서 사용하는 것이 아니라
// => Mock Framework
// 1. Google Mock
// 2. jMock, easyMock, Mockito

// 테스트 접근방식
// 1) 상태검증 - 상태 기반 테스트
//    : 테스트에 검증해야 할 상태가 있을 때, 어떻게 테스트 할 것인가?
//   => SUT를 실행 후, 상태를 보고 이를 기대값과 비교한다.

// 2) 동작검증 - 행위 기반 테스트
//    : 테스트에 검증해야 할 상태가 없을 때, 어떻게 테스트 할 것인가?
//   => 함수의 리턴값이 없거나, 리턴값을 확인하는 것만으로는 
//      예상대로 동작했음을 보증하기 어려울 때 사용한다.


//google mock 정적 라이브러리
// 1. 정적라이브러리 프로젝트 
// 2. src추가
//     gmock-all.cc
//     gtest-all.cc
//     gmock_main.cc
//  3. include path
//      $GTest/googlemock
//      $GTest/googlemock/include 
//      $GTest/googletest
//      $GTest/googletest/include

//Test Project
//  1. include path
//      $GTEST/googlemock/include
//      $GTEST/googletest/include
//  2. gmock 정적 라이브러리의 참조
