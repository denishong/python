#if 1
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)
# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)
int __UNIQUE_ID(license) = 10; int __UNIQUE_ID(license) = 20;
//int aaa = 10;
//int aaa = 20;
int main()
{
	return 0;
}

//MODULE_LICENSE("GPL");
//MODULE_LICENSE("BSD");
#endif
#if 0
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)
# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
int __UNIQUE_ID(license) = 10; int __UNIQUE_ID(license) = 20;
//int aaa = 10;
//int aaa = 20;
int main()
{
	return 0;
}

//MODULE_LICENSE("GPL");
//MODULE_LICENSE("BSD");
#endif
#if 0
#define __used			__attribute__((__used__))
#define __stringify_1(x)	#x
#define __stringify(x)	__stringify_1(x)

char a[] 
__used __attribute__((section(".modinfo"), unused, aligned(1)))     
= __stringify(license) "=" "GPL";
int main()
{
	return 0;
}
#endif
#if 0
#define __stringify_1(x)	#x
#define __stringify(x)	__stringify_1(x)

char a[] 
__attribute__((section(".modinfo")))
= __stringify(license) "=" "GPL";
//  "license" "=" "GPL";
//  "license=GPL";
int main()
{
	return 0;
}
#endif

#if 0
#define  license  hello
#define __stringify_1(x)	#x
#define __stringify(x)	__stringify_1(x)

int main()
{
	__stringify(license);
	return 0;
}
#endif
