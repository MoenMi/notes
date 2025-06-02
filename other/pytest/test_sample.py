def func(x):
    return x + 1

def test_wrong_answer():
    assert func(3) == 5

def test_right_answer():
    assert func(3) == 4