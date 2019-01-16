/*
  Problem:
  
  Theory:
    
    A friend function of a class is defined outside that class' scope but it has the right to access all private and protected 
    members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not 
    member functions.
    A friend can be a function, function template, or member function, or a class or class template, in which case the
    entire class and all of its members are friends.
    To declare a function as a friend of a class, precede the function prototype in the class definition with keyword friend.
    
    For friend keyword see also: https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm  
    
    C++ provides a variety of ways to cast between types. Each of the C++ casts has the following generic form:
      
      cast_name<cast_to_type>(item_to_cast)
      
      The C++ ways of cast are:
      
      - static_cast:
          static_cast handles implicit conversions between types (e.g. integral type conversion, any pointer type to void*). 
          static_cast can also call explicit conversion functions. e.g. int * y = static_cast<int*>(malloc(10));
          We will primarily use it for converting in places where implicit conversions fail, such as malloc.
          There are no runtime checks performed for static_cast conversions.
          static_cast cannot cast away const or volatile.
      - reinterpret_cast:
        reinterpret_cast is a compiler directive which tells the compiler to treat the current type as a new type.
        You can use reinterpret_cast to cast any pointer or integral type to any other pointer or integral type. 
        This can lead to dangerous situations: nothing will stop you from converting an int to a std::string *.
        You will use reinterpret_cast in your embedded systems. A common scenario where reinterpret_cast applies is converting 
        between uintptr_t and an actual pointer or between: uintptr_t ptr = reinterpret_cast<uintptr_t>(p);
      - const_cast: 
        adds or removes const from a variable. Strangely enough, you can also use const_cast to add or remove volatile from a variable. 
        No other C++ cast can add or remove these keywords.
      - dynamic_cast:
        We use dynamic_cast to handle polymorphism. dynamic_cast can convert pointers and references to any
        polymorphic type at run-time, primarily to cast down a type's inheritance hierarchy. If dynamic_cast 
        can't find the desired type in the inheritance hierarchy, it will return nullptr for pointers or throw 
        a std::bad_cast exception for references.
      - C-style casts:
        A C-style cast in C++ tries the following casts in order, using the first C++ cast that works:
          1) const_cast
          2) static_cast
          3) static_cast, then const_cast (change type + remove const)
          4) reinterpret_cast
          5) reinterpret_cast, then const_cast (change type + remove const)
        Note that dynamic_cast is never considered when using a C-style cast.
        
      For C++/C casts ee also: https://embeddedartistry.com/blog/2017/2/28/c-casting-or-oh-no-we-broke-malloc
*/

