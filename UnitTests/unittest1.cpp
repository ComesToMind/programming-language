#include "stdafx.h"
#include "CppUnitTest.h"
#include "../programming language/Container.h"
#include "../programming language/Functional.h"
#include "../programming language/Language.h"
#include "../programming language/ObjectOriented.h"
#include "../programming language/Procedural.h"

#include "../programming language/Container_Constr.cpp"
#include "../programming language/Container_In.cpp"
#include "../programming language/Container_Out.cpp"
#include "../programming language/Functional_In.cpp"
#include "../programming language/Functional_Out.cpp"
#include "../programming language/Language_Compare.cpp"
#include "../programming language/Language_In.cpp"
#include "../programming language/Language_Out.cpp"
#include "../programming language/ObjectOriented_In.cpp"
#include "../programming language/ObjectOriented_Out.cpp"
#include "../programming language/Procedural_In.cpp"
#include "../programming language/Procedural_Out.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(YearsPassedM)
		{
			ObjectOriented language;
			language.mData = 2014;
			int actual = passedYears(&language);
			int expected = 2020 - language.mData;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompareM)
		{
			Functional *language_new = new Functional;
			Procedural *language_old = new Procedural;
			language_new->mKey = type::FUNCTIONAL;
			language_new->mData = 2020;
			language_old->mKey = type::PROCEDURAL;
			language_old->mData = 2010;
			//<
			bool actual = Compare((Language*)language_new, (Language*)language_old);
			bool expected = true;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ProceduralInputM)
		{
			ifstream fin("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/In_Proc_Test.txt");
			//if (fin.is_open())
			//{

			Procedural *actual = inProc(fin);
			Procedural *expected = new Procedural;

			expected->mAbstractDT = 0;
			expected->mData = 2000;
			expected->mKey = type::PROCEDURAL;
			expected->mRef = 20000;

			Assert::AreEqual(expected->mAbstractDT, actual->mAbstractDT);
			Assert::AreEqual(expected->mData,actual->mData);
			Assert::AreEqual((int)expected->mKey, (int)actual->mKey);
			Assert::AreEqual(expected->mRef, actual->mRef);
			//}
		}
		
		TEST_METHOD(ProceduralOutput)
		{
			ofstream fout("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/Out_Proc_Test_Act.txt");
			Procedural *act = new Procedural;
			act->mAbstractDT = 0;
			act->mData = 2000;
			act->mKey = type::PROCEDURAL;
			act->mRef = 20000;

			Out(act, fout);
			ifstream fin_act("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/Out_Proc_Test_Act.txt");
			ifstream fin_exp("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/Out_Proc_Test_Exp.txt");
			string expected, actual;
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected,actual);

		}
		TEST_METHOD(ContainerStream)
		{
			ifstream fin("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutputIn.txt");
			ofstream fout("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutput.txt");
			Container c;
			Init(c);
			In(c, fin);
			Out(c, fout);
			fout.close();
			ifstream fin_exp("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutputExp.txt");
			ifstream fin_act("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)),std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SortContainer)
		{
			ifstream fin("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutputIn.txt");
			ofstream fout("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutput.txt");
			Container *c = new Container;
			Init(*c);
			In(*c, fin);
			Sort(c);
			Out(*c, fout);
			fout.close();
			ifstream fin_exp("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/SortContainerExp.txt");
			ifstream fin_act("C:/Users/Данила/source/repos/programming Versions/proc3/programming-language/UnitTests/ContainerOutput.txt");
			string expected((std::istreambuf_iterator<char>(fin_exp)), std::istreambuf_iterator<char>());
			string actual((std::istreambuf_iterator<char>(fin_act)), std::istreambuf_iterator<char>());
			Assert::AreEqual(expected, actual);
		}

	};
}