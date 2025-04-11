# Data Types

## 🧱 1. **What Are Data Types in C++?**

In C++, **data types** define the type of data a variable can hold — such as integers, floating-point numbers, characters, or boolean values. They **tell the compiler how much space to allocate** in memory and how to interpret the bit patterns stored in that space.

---

## 🧠 2. **Classification of Data Types**

| Category | Types |
| --- | --- |
| **Primitive** | `int`, `float`, `char`, `double`, `bool`, `void` |
| **Derived** | Arrays, Pointers, References, Functions |
| **User-defined** | Structures (`struct`), Classes (`class`), Unions (`union`) |
| **Abstract / Empty** | `void` |

For this discussion, we'll focus mainly on **primitive data types**, particularly **numeric** types.

---

## 📊 3. **Numeric Data Types**

### 📌 Integer Types

| Data Type | Size (in bytes) | Range (Signed) | Range (Unsigned) |
| --- | --- | --- | --- |
| `short` | 2 | -32,768 to 32,767 | 0 to 65,535 |
| `int` | 4 | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295 |
| `long` | 4 or 8 | platform dependent | platform dependent |
| `long long` | 8 | −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 0 to 18,446,744,073,709,551,615 |

🔸 **Signed vs Unsigned:**

- `signed`: Can hold **positive and negative** values (default if not specified).
- `unsigned`: Can only hold **positive** values, but the range is **doubled** upwards (starts from 0).

```cpp
int x = -5;        // valid (signed int)
unsigned int y = -5; // invalid (y will overflow)

```

---

### 📌 Floating-Point Types

| Data Type | Size (bytes) | Precision | Range |
| --- | --- | --- | --- |
| `float` | 4 | ~7 decimal digits | ±1.5 × 10^−45 to ±3.4 × 10^38 |
| `double` | 8 | ~15 decimal digits | ±5.0 × 10^−324 to ±1.7 × 10^308 |
| `long double` | 12/16 | ~18+ digits | Larger range than double |

Used for **real numbers**, with `float` being smaller and faster, and `double` being more precise.

---

### 📌 Character Type

| Data Type | Size (bytes) | Range (Signed) | Range (Unsigned) |
| --- | --- | --- | --- |
| `char` | 1 | -128 to 127 | 0 to 255 |
- Stores **single characters** using ASCII codes.
- Can be treated as an **integer** type in arithmetic operations.

---

### 📌 Boolean Type

| Data Type | Size (bytes) | Values |
| --- | --- | --- |
| `bool` | 1 | `true` or `false` (1 or 0) |

Used for logical operations and conditions.

---

## 🧮 4. **Signed vs Unsigned — In Depth**

Every binary number has two interpretations:

- **Signed** means the **MSB (most significant bit)** is used to denote **sign** (0 for positive, 1 for negative).
- **Unsigned** interprets all bits as magnitude → gives a higher maximum.

For example, an 8-bit number:

- Signed range: −128 to 127
- Unsigned range: 0 to 255

```cpp
signed char a = -100;
unsigned char b = 200;

```

> 🌟 Signed is default — use unsigned only if negative numbers are not possible (like array indices, memory sizes, etc.)
> 

---

## ⚙️ 5. **Void Type**

- `void` means **no value**.
- Used for:
    - **Functions** returning nothing.
    - **Generic pointers**: `void*` (can point to any type).

```cpp
void greet() {
    std::cout << "Hello";
}

```

---

## 🧪 6. **How to Check Size in C++**

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
}

```

> 🎯 Use sizeof() operator to get size on your system. Size may vary slightly based on compiler and platform.
> 

---

## 🏗️ 7. **Modifiers in C++**

Modifiers allow **customization** of basic data types.

| Modifier | Use |
| --- | --- |
| `signed` | Include negative numbers |
| `unsigned` | Only positive values |
| `short` | Smaller range |
| `long` | Larger range |

Valid combinations:

```cpp
unsigned int;
long double;
short int;
unsigned long long;

```

---

## 🌍 8. **Platform Dependency and Standard Sizes**

- C++ standard specifies **minimum ranges**, but actual size can vary:
    - `int` = at least 16 bits
    - `long long` = at least 64 bits
- Use `<cstdint>` for **fixed-width integers**:
    
    ```cpp
    int8_t, uint8_t, int16_t, int32_t, int64_t
    
    ```
    

These are **portable**, e.g., `int32_t` is guaranteed to be 4 bytes.

---

## 📝 9. **Best Practices**

- Use `int` for general integers.
- Use `long long` for competitive programming and large calculations.
- Use `double` if decimals are involved.
- Use `unsigned` only when sure the number won't be negative.
- Use `bool` for flags and conditions.
- Use `char` for characters, or as a compact storage.

---