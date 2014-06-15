CMake
=====

**Content**
- Resources
- Tips for CMake
- Commands
- Statements(if/Loop contral)
- Function and Macro

## Resources

- [Wikipedia](http://zh.wikibooks.org/zh-cn/CMake_%E5%85%A5%E9%96%80)
- [podofomomo example](https://github.com/Universefei/podofomemo/blob/master/podofo/CMakeLists.txt)

## Tips for CMake

- CMake 的语法非常单纯，由指令(command)和注解所组成，所有的空白、换行、tab 都没有特殊作用，仅为语汇元素的区隔。
- 凡是由 # 字符开头一直到换行字符间的内容皆会被视为注解，不会有任何作用。
- 指令为指令名称加上小括号，括号内可以有零或若干个参数，指令则依照出现在 CMakeLists 当中的顺序执行。
- 所有指令名称大小写都一视同仁，例如 Command、COMMAND 皆视为同一个指令。
- 变量大小写不同视为相异，内建的变量都必须要全大写。
- 在撰写 CMakeLists 时可以使用变量(Variable)储存资料，严格说起来 CMake 只有字串和串行两种资料形态，数值和布林值本质上只是带有特殊意义的字串。
- 不过一个常见的风格是一切都用大写命名，只要按下 caps lock 从头写到尾即可。

## Commands

- message()
	- message(${var})
	- message("helloworld")
- set(VARIABLE value)
	- set(a alpha beta gamma)
	- set(b "alpha beta gamma")
	- set(c "alpha\
		beta\
		gamma\
		)
	- set(d "${b} delta")
	- set(e ${b} "delta")
- math(EXPR var "1+3*4)
- list()
- string()
- find_package()
- include()
- include_directories()
- add_subdirectory()
- add_library()
- add_executable()
- target_link_libraries()
- set_target_properties()
- install()
- file()
- cmake_minimum_required(VERSION 2.6)
- project()
- add_custom_command()
- set_source-files_properties()

## Statements

**if;elseif;else;endif**

```
# 當 expr 值為下列其中之一時，執行 command1：
#    ON, 1, YES, TRUE, Y
# 當 expr 值為下列其中之一時，執行 command2：
#    OFF, 0, NO, FALSE, N, NOTFOUND, *-NOTFOUND, IGNORE 

if(expr)
	command1(arg)
else(expr)
	command2(arg)
endif(expr) 
```

* condition judge

```
if((expr) AND (expr OR (expr)))
```

* NB(Note Board)

```
# 下面兩行意義相同
if (foo)
if (${foo})

# 下面兩行意義相同
if (foo AND bar)
if (${foo} AND ${bar})
```

**Loop contral**
* foreach...endforeach

```
set(V  alpha beta gamma)
message(${V})

foreach(i  ${V})
	message(${i})
endforeach() 
```

* while...endwhile

```
instance waitting
```

## Functions and Macro
CMake 有两种设计子程序的方式：

* function ... endfunction
* macro ... endmacro

主要的差别在于 function 会建立 local的变量，而 macro 则会影响 global 变量。

```
# 定義名為 print1 的 macro 

macro(print1 MESSAGE)
	message(${MESSAGE})
endmacro(print1)

# 定義名為 print2 的 function
function(print2 MESSAGE)
	message(${MESSAGE})
endfunction(print2) 

print1("from print1")
print2("from print2")
```

