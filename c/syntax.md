#SYNTAX of C/C++

 This file record strange C/C++ syntax encounted

##Contents
- 001 static 
- 002 const - 003 explicit
- 004 friend
- 005 inline
- 006 namespace
- 007 boost::noncopyable
- 008 boost::array
- 009 boost::function\<\> name
- 010 restrict keyworld
- 011 virtual keyworld(C++)
- 012 auto keyworld(c)
- 013 boost::ptr_vector<muduo::Thread> threads_
- 014 boost::shared_ptr<pid_t> tid_
- 015 assert.h <assert.h>
- 016 implicit_cast()
- 017 static_cast()



##001.static

**reference**

- [stackoverflow1](http://stackoverflow.com/questions/177437/const-static)
- [stackoverflow2](http://stackoverflow.com/questions/1312241/using-a-static-const-int-in-a-struct-class)

A lot of people gave the basic answer but nobody pointed out that const 
defaults to static (and some gave wrong information). See the C++98 standard 
section 3.5.3.

First some background:

- Translation unit: A source file after the pre-compiler (recursively) included 
all its include files.

- Static linkage: A symbol is only available within its translation unit.

- External linkage: A symbol is available from other translation units.

**At namespace level**

This includes the global namespace aka global variables

```
static const int sci = 0; // sci is explicitly static
const int ci = 1;         // ci is implicitly static
extern const int eci = 2; // eci is explicitly extern
extern int ei = 3;        // ei is explicitly extern
int i = 4;                // i is implicitly extern
static int si = 5;        // si is explicitly static
```

**At function level**

static means the value is maintained between function calls.
The semantics of function static variables is similar to global variables in 
that they reside in the program's data-segment (and not the stack or the heap),
see this question for more details about static variables' lifetime.

**At class level**

static means the value is shared between all instances of the class and const 
means it doesn't change (and can be initialized inline) this is the only case 
in which neither the static nor the const are redundant.

##002.const

##003.explicit
used only for constructor of class

**reference**
- [stackoverflow](http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean)
- [IBM](http://publib.boulder.ibm.com/infocenter/comphelp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8a.doc%2Flanguage%2Fref%2Fexplicit_keyword.htm)
- [visual studio](http://msdn.microsoft.com/en-us/library/vstudio/h1y7x448.aspx)

##004.friend

##005.inline

##006.namespace

##007.boost::noncopyable

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8248960)

##008.boost::array

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8248361)

##009.boost::function

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8249278)

##010.restrict keyworld

**reference**

- [CSDN](http://blog.csdn.net/llf021421/article/details/8092602)

##011.virtual keyworld


##012.auto keyworld(c)

##015.assert()

sort of like `set -e` option in bash

For function prototype `assert( expression )`
the `expression` must be true, or process will abort here!

* [asser()函数用法总结](http://www.cnblogs.com/ggzss/archive/2011/08/18/2145017.html)
