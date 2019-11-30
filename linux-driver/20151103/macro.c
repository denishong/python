#define __must_check	__attribute__((warn_unused_result))

int __must_check foo()
{
	return 1;
}

int main()
{
	int ret;
	// request_irq
	ret = foo();
	return 0;
}
