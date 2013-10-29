
#include <upp11.h>

using namespace std;
using namespace upp11;

UP_SUITE_BEGIN(suteTestInvoker)

UP_TEST(InvokerShouldCatchAllExceptionInTestCtor)
{
	// Given
	struct TestWithException {
		TestWithException() {
			throw runtime_error("setUp exception");
		}
		void operator()() {};
	};
	TestInvokerTrivial<TestWithException> invoker("");
	// When/Then
	UP_ASSERT(!invoker.invoke());
}

UP_TEST(ParametrizedShouldCatchAllExceptionInTestCtor)
{
	// Given
	struct TestWithException {
		TestWithException() {
			throw runtime_error("setUp exception");
		}
		void operator()(const tuple<> &) {};
	};
	TestInvokerParametrized<TestWithException> invoker("", {});
	// When/Then
	UP_ASSERT(!invoker.invoke(make_tuple()));
}

UP_SUITE_END()

UP_MAIN()
