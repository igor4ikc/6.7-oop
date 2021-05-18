#include "pch.h"
#include "CppUnitTest.h"
#include "../6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bilsh0 <int> a;
			Assert::AreEqual(a.operator()(1), true);
		}
	};
}
