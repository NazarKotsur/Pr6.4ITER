#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.4ITER/Pr6.4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectNameUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест для findMin
        TEST_METHOD(TestFindMin)
        {
            double arr[] = { 5.0, 3.0, 8.0, 2.0, 7.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            double result = findMin(arr, n);
            Assert::AreEqual(2.0, result);
        }

        // Тест для findSumBetweenPositives
        TEST_METHOD(TestFindSumBetweenPositives)
        {
            double arr[] = { -2.0, 5.0, 3.0, 8.0, 2.0, 7.0, -1.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            double result = findSumBetweenPositives(arr, n);
            Assert::AreEqual(13.0, result);
        }

        // Тест для moveZerosToFront
        TEST_METHOD(TestMoveZerosToFront)
        {
            double arr[] = { 0.0, -2.0, 5.0, 0.0, 3.0, 8.0, 2.0, 7.0, -1.0, 0.0 };
            int n = sizeof(arr) / sizeof(arr[0]);
            moveZerosToFront(arr, n);
            double expected[] = { 0.0, 0.0, 0.0, -2.0, 5.0, 3.0, 8.0, 2.0, 7.0, -1.0 };
            for (int i = 0; i < n; i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
    };
}
