# CPP06

This project is a set of C++ exercises focused on type conversion, serialization, and polymorphism. It is divided into three parts:

## Table of Contents
- [ex00: Scalar Converter](#ex00-scalar-converter)
- [ex01: Serializer](#ex01-serializer)
- [ex02: RTTI & Polymorphism](#ex02-rtti--polymorphism)
- [Build & Run Instructions](#build--run-instructions)

---

## What I Learned: Casting in C++

This project deepened my understanding of C++ type casting, especially the differences and use-cases for `static_cast`, `reinterpret_cast`, and `dynamic_cast`:

### 1. `static_cast`
- Used for well-defined, compile-time conversions between related types (e.g., numeric conversions, up/down-casting in inheritance when safe).
- In **ex00**, `static_cast` is used to convert a numeric value to `char`, `int`, `float`, and `double` for scalar conversion. It is safe here because the conversions are between fundamental types and checked for validity.

### 2. `reinterpret_cast`
- Used for low-level, bitwise reinterpretation of types, such as converting a pointer to an integer or vice versa.
- In **ex01**, `reinterpret_cast` is used to serialize a pointer (`Data*`) to an integer type (`uintptr_t`) and back. This is necessary for pointer serialization, but should be used with care as it does not ensure type safety.

### 3. `dynamic_cast`
- Used for safe downcasting in polymorphic class hierarchies. It checks at runtime whether the cast is valid, returning `nullptr` for pointers or throwing an exception for references if the cast fails.
- In **ex02**, `dynamic_cast` is used to identify the actual derived type of a `Base*` or `Base&` at runtime. This is essential for RTTI (Run-Time Type Information) and safe type identification in polymorphic code.

### Why Use These Casts?
- **`static_cast`**: For conversions that are guaranteed to be safe and do not require runtime checks.
- **`reinterpret_cast`**: For low-level memory manipulation, such as pointer serialization, where you need to treat the same memory as a different type.
- **`dynamic_cast`**: For safe downcasting in class hierarchies, especially when the actual type is only known at runtime.

Understanding when and why to use each cast is crucial for writing safe, efficient, and correct C++ code, as demonstrated in these exercises.

## ex00: Scalar Converter
Implements a static class `ScalarConverter` that converts a string literal to its corresponding scalar types (char, int, float, double). Handles edge cases and displays conversion results.

---
**Note:**
There is a little mistake in my implementation, I am supposed to identify the type first and then convert to other types, but here I am doing that only in case of char, for the rest of the numeric cases I am converting directly to long double using strtold and then converting to other types without explicitly checking if its int or float or double.

---

**Usage:**
```sh
cd ex00
make
./convert <literal_value>
```

---

## ex01: Serializer
Implements a `Serializer` class to serialize and deserialize pointers to a simple `Data` struct. Demonstrates pointer manipulation and type casting.

**Usage:**
```sh
cd ex01
make
./serializer
```

---

## ex02: RTTI & Polymorphism
Implements a base class `Base` and derived classes `A`, `B`, and `C`. Includes functions to generate a random derived class and identify its type using pointers and references (demonstrating RTTI and `dynamic_cast`).

**Usage:**
```sh
cd ex02
make
./identify
```

---

## Build & Run Instructions
1. Enter the desired exercise directory (`ex00`, `ex01`, or `ex02`).
2. Run `make` to build the project.
3. Execute the resulting binary as shown above.

---

## Author
- Henna Parveen

---
