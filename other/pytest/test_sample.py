import pytest

def func(x):
    return x + 1

def test_wrong_answer():
    assert func(3) == 5

def test_right_answer():
    assert func(3) == 4

def is_even(x: int) -> bool:
    """Note, this actually returns the opposite of what we want"""
    return x % 2 == 1

def test_is_even():
    assert is_even(4) == True, "value was odd, should be even"

def is_actually_even(x: int) -> bool:
    """This actually returns what we want"""
    return x % 2 == 0

def test_is_actually_even():
    assert is_actually_even(4) == True, "value was odd, should be even"

def test_zero_division():
    with pytest.raises(ZeroDivisionError):
        1 / 0

def test_recursion_depth():
    with pytest.raises(RuntimeError) as excinfo:

        def f():
            f()

        f()
    assert "maximum recursion" in str(excinfo.value)
