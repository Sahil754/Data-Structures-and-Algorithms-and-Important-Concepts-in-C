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
    {           //Declairing an array of pointers and assigning it 3 functions.
		void (*pf[])(int) = {f1, f2, f3};

                //Calling and assinging values to different functions
		int c = 0;
		while(c < 3)
		{
			pf[c](c);
			c++;
		}

		return 0;
    }