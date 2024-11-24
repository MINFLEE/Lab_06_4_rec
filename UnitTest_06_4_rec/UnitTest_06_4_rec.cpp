#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_rec/Lab_06_4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064it
{
	TEST_CLASS(UnitTest064it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 6;
			double* a = new double[n];
			a[0] = 6;
			a[1] = 3;
			a[2] = 7;
			a[3] = -5;
			a[4] = 8;
			a[5] = 4;
			double expected = 4032;
			double actual = ProductOfPositiveElements(a, n);
			Assert::AreEqual(expected, actual);
		}
	};
}