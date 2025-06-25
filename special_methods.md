# Special Methods

By implementing special methods, your objects can behave like the built-in types,
enabling the expressive coding style the community considers 'pythonic'.

## String/Byte representation

```python3
__repr__ __str__ __format__ __bytes__ __fspath__
```

## Conversion to number

```python3
__bool__ __complex__ __int__ __float__ __hash__ __index__
```

## Emulating Collections

```python3
__len__ __getitem__ __setitem__ __delitem__ __contains__
```

## Iteration

```python3
__iter__ __aiter__ __next__ __anext__ __reversed__
```

## Callable/Coroutine Execution

```python3
__call__ __await__
```

## Context Management

```python3
__enter__ __exit__ __aexit__ __aenter__
```

## Instance creation and destruction

```python3
__new__ __init__ __del__
```

## Attribute management

```python3
__getattr__ __getattribute__ __setattr__ __delattr__ __dir__
```

## Attribute descriptors

```python3
__get__ __set__ __delete__ __set_name__
```

## Abstract base classes

```python3
__instancecheck__ __subclasscheck__
```

## Class metaprogramming

```python3
__prepare__ __init_subclass__ __class_getitem__ __mro_entries__
```

## Unary numeric

```python3
- __neg__, + __pos__, abs() __abs__
```

## Rich comparison

```python3
< __lt__, <= __le__, == __eq__, != __ne__, > __gt__, >= __ge__
```

## Arithmetic

```python3
+ __add__, - __sub__, * __mul__, / __truediv__, // __floordiv__, % __mod__, @ __matmul__, divmod() __divmod__,
round() __round__, ** pow() __pow__
```

## Reversed arithmetic (arithmetic operators with swapped operands)

```python3
__radd__, __rsub__, __rmul__, __rtruediv__, __rfloordiv__, __rmod__, __rmatmul__, __rdivmod__, __rpow__
```

## Augmented assignment arithmetic

```python3
+= __iadd__, -= __isub__, *= __imul__, /= __itruediv__, //= __ifloordiv__, %= __imod__, @= __imatmul__, **= __ipow__
```

## Bitwise

```python3
& __and__, | __or__, ^ __xor__, << __lshift__, >> __rshift__, ~ __invert__
```

## Reversed bitwise (bitwise operators with swapped operands)

```python3
__rand__, __ror__, __rxor__, __rlshift__, __rrshift__
```

## Augmented assignment bitwise

```python3
&= __iand__, |= __ior__, ^= __ixor__, <<= __ilshift__, >>= __irshift__
```
