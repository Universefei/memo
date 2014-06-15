typedef Struct
==============

There 2 ways to define a struct:

## 1 struct foo {}

**define:**
```
struct node {
	int weight;
	Struct node *parent, *lch, *rch;
};
```

**invoke struct to declare variable:**
```
struct node var1, var2;
```

## 2 typedef struct foo {} bar

**define:**
```
typedef struct node {
	int weight;
	struct node *parent, *lch, *rch;
} Node;
```
OR
```
typedef struct node {
	int weight;
	Node *parent, *lch, *rch;
} Node;
```
OR
```
typedef struct {
	int weight;
	Node *parent, *lch, *rch;
} Node;
```

**invoke struct to declare variable:**
```
struct node var1, var2;
```
OR
```
Node var1, var2;
```

Wrap-up
=======

`typedef struct foo {} bar`
is just a typedef warp-up for `struct foo {}` clause

It is equal to
```
struct foo {};
typedef foo bar;
```

so `typedef struct foo {} bar` do one more statement than `struct foo {}`

* so the former is more functional:
it can declara var via 2 approaches:

`struct foo var;`
OR
`bar var;`

* while the latter can just declare variable like:
`struct foo var;`

