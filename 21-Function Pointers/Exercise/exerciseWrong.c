    #include <stdio.h>

    void f1(int var)
    {
            printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var)
    {
            printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var)
    {
            printf("this is f3 and var is: %d\n", var);
    }

    int main()
    {
                /* define an array full of function pointers 
                to the above functions, that take an `int` as 
                their only argument */
                void (*fun1) (int);
                fun1 = &f1;

                void (*fun2) (int);
                fun2 = &f2;

                void (*fun3) (int);
                fun3 = &f3;

                int *ptr[] = {fun1, fun2, fun3};
                int *ptr2[3];

		int c = 0;
		while(c < 3)
		{
                        /* call the functions using the function pointers
                        of the array at index `c` with `c` as an argument */
            ptr2[c] = &ptr[c];
			++c;
		}

	  return 0;
    }