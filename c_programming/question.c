1)What is the difference between declaration and definition of a variable/function?
Ans: Declaration of a variable/function simply declares that the variable/function exists somewhere in the program but the memory is not allocated for them.
But the declaration of a variable/function serves an important role. And that is the type of the variable/function.
Therefore, when a variable is declared, the program knows the data type of that variable.
In case of function declaration, the program knows what are the arguments to that functions, their data types, the order of arguments and the return type of the function.
So that’s all about declaration. Coming to the definition, when we define a variable/function, apart from the role of declaration, it also allocates memory for that variable/function.
Therefore, we can think of definition as a super set of declaration. (or declaration as a subset of definition).

// This is only declaration. y is not allocated memory by this statement
extern int y;

// This is both declaration and definition, memory to x is allocated by this statement.
int x;

2)What are different storage class specifiers in C?
Ans: auto, register, static, extern

3)What is scope of a variable? How are variables scoped in C?
Ans: Scope of a variable is the part of the program where the variable may directly be accessible. In C, all identifiers are lexically (or statically) scoped.

4)When should we use pointers in a C program?
1. To get address of a variable
2. For achieving pass by reference in C: Pointers allow different functions to share and modify their local variables.
3. To pass large structures so that complete copy of the structure can be avoided.
4. To implement “linked” data structures like linked lists and binary trees.

5)What is NULL pointer?
Ans: NULL is used to indicate that the pointer doesn’t point to a valid location. Ideally, we should initialize pointers as NULL if we don’t know their value at the time of declaration. Also, we should make a pointer NULL when memory pointed by it is deallocated in the middle of a program.

6)What is Dangling pointer?
Ans: Dangling Pointer is a pointer that doesn’t point to a valid memory location. Dangling pointers arise when an object is deleted or deallocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the deallocated memory. Following are examples.

// EXAMPLE 1
int* ptr = (int*)malloc(sizeof(int));
..........................free(ptr);
  
// ptr is a dangling pointer now and operations like following are invalid
*ptr = 10; // or printf("%d", *ptr);

// EXAMPLE 2
int* ptr = NULL
{
    int x = 10;
    ptr = &x;
}
// x goes out of scope and memory allocated to x is free now.
// So ptr is a dangling pointer now.

7)What is memory leak? Why it should be avoided
Ans: Memory leak occurs when programmers create a memory in heap and forget to delete it.
Memory leaks are particularly serious issues for programs like daemons and servers which by definition never terminate.

/* Function with memory leak */
#include <stdlib.h>
  
void f()
{
    int* ptr = (int*)malloc(sizeof(int));
  
    /* Do some work */
  
    return; /* Return without freeing ptr*/
}

8)What are local static variables? What is their use?
Ans:A local static variable is a variable whose lifetime doesn’t end with a function call where it is declared.
It extends for the lifetime of complete program. All calls to the function share the same copy of local static variables.
Static variables can be used to count the number of times a function is called. Also, static variables get the default value as 0.
For example, the following program prints “0 1”

#include <stdio.h>
void fun()
{
    // static variables get the default value as 0.
    static int x;
    printf("%d ", x);
    x = x + 1;
}
  
int main()
{
    fun();
    fun();
    return 0;
}
// Output: 0 1

9)What are static functions? What is their use?
Ans:In C, functions are global by default. The “static” keyword before a function name makes it static. 
Unlike global functions in C, access to static functions is restricted to the file where they are declared. 
Therefore, when we want to restrict access to functions, we make them static. 
Another reason for making functions static can be reuse of the same function name in other files

10)What is difference between i++ and ++i? 
1) The expression ‘i++’ returns the old value and then increments i. The expression ++i increments the value and returns new value. 
2) Precedence of postfix ++ is higher than that of prefix ++. 
3) Associativity of postfix ++ is left to right and associativity of prefix ++ is right to left. 
4) In C++, ++i can be used as l-value, but i++ cannot be. In C, they both cannot be used as l-value.
// PROGRAM 1
#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    ++*p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",
                          arr[0], arr[1], *p);
    return 0;
}

// PROGRAM 2
#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    *p++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",
                          arr[0], arr[1], *p);
    return 0;
}

// PROGRAM 3
#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",
                          arr[0], arr[1], *p);
    return 0;
}

11)How will you print numbers from 1 to 100 without using loop? 
We can use recursion for this purpose.
/* Prints numbers from 1 to n */
void printNos(unsigned int n)
{
  if(n > 0)
  {
    printNos(n-1);
    printf("%d ",  n);
  }
}

12)Can a variable be both const and volatile? 
yes, the const means that the variable cannot be assigned a new value. The value can be changed by other code or pointer. For example the following program works fine. 
#include <stdio.h>
int main(void)
{
    const volatile int local = 10;
    int* ptr = (int*)&local;
    printf("Initial value of local : %d \n", local);
    *ptr = 100;
    printf("Modified value of local: %d \n", local);
    return 0;
}
13)What are entry control and exit control loops? 
Ans. C support only 2 loops:  
Entry Control: This loop is categorized in 2 part 
a. while loop 
b. for loop
Exit control: In this category, there is one type of loop known as 
a. do while loop.

14)Why pre-processor directive does not have a semi-colon at last? 
Ans. Semi-colon is needed by the compiler and as the name suggests Preprocessors are programs that process our source code before compilation.
Therefore the semi-colon is not required.

15)Why does “type demotion” does not exist instead of “type promotion”? Also, it would consume less space resource than by doing it from type promotion.? 
Ans. Let’s take an example to understand it. 
Suppose 
double a=1.5; int b=10 and we want to calculate a+b 
By type demotion, float type a will convert to int. Therefore a=1 and a+b=1+10=11 but we know that correct answer is 11.5 which will only get by type promotion.
So the conclusion is that by type demotion we will not get the correct answer.

16) What are stack and heap areas? 

Heap Area:It is used for the objects allocated dynamically (Using malloc() and calloc()).
Stack Area:It is used to store local variables and arguments of a method. This stays in memory only till the termination of that particular method.

17)Difference between ++*p, *p++ and *++p? 
    1) Precedence of prefix ++ and * is same. Associativity of both is right to left. 
    2) Precedence of postfix ++ is higher than both * and prefix ++. Associativity of postfix ++ is left to right.
(Refer: Precedence Table)
The expression ++*p has two operators of same precedence, so compiler looks for associativity. Associativity of operators is right to left.
Therefore the expression is treated as ++(*p). Therefore the output of first program is “arr[0] = 10, arr[1] = 20, *p = 11“.
The expression *p++ is treated as *(p++) as the precedence of postfix ++ is higher than *. Therefore the output of second program is “arr[0] = 10, arr[1] = 20, *p = 20“.
The expression *++p has two operators of same precedence, so compiler looks for associativity. Associativity of operators is right to left.
Therefore the expression is treated as *(++p). Therefore the output of third program is “arr[0] = 10, arr[1] = 20, *p = 20“
Please refer Difference between ++*p, *p++ and *++p for details.

18)Explain Deep Copy and Shallow Copy with examples? 
In the following C program, struct variable st1 contains pointer to dynamically allocated memory. When we assign st1 to st2, str pointer of st2 also start pointing to same memory location. This kind of copying is called Shallow Copy. 

// C program to demonstrate shallow copy
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
 
struct test
{
  char *str;
};
 
int main()
{
  struct test st1, st2;
  st1.str = (char *)malloc(sizeof(char) * 20);
 
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was shallow, both strings are same */
  printf("st1's str = %s\n", st1.str);
  printf("st2's str = %s\n", st2.str);
 
  return 0;
}
Output: 
st1's str = XYeksforGeeks
st2's str = XYeksforGeeks

//To do Deep Copy, we allocate new memory for dynamically allocated members and explicitly copy them.


// C program to demonstrate deep copy
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
 
struct test
{
  char *str;
};
 
int main()
{
  struct test st1, st2;
  st1.str = (char *)malloc(sizeof(char) * 20);
 
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
 
  // We add extra statements to do deep copy
  st2.str = (char *)malloc(sizeof(char) * 20);
  strcpy(st2.str, st1.str);
 
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was deep, both strings are different */
  printf("st1's str = %s\n", st1.str);
  printf("st2's str = %s\n", st2.str);
 
  return 0;
}
Output: 
st1's str = XYeksforGeeks
st2's str = GeeksforGeeks