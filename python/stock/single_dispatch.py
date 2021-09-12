"""
Playing with python's single dispatch.
See: https://hynek.me/articles/serialization/
See also PEP 443: https://www.python.org/dev/peps/pep-0443/
"""
from datetime import datetime
from functools import singledispatch


# Let's define some custom data types (classes)
# ---------------------------------------------

class Foo:
    value = 'foo'

    def __str__(self):
        return "I'm a Foo instance, named '{}'".format(self.value)


class Bar:
    value = 'bar'

    def __str__(self):
        return "I'm a Bar instance, with value = '{}'".format(self.value)


# And now some functions to serialize objects (i.e. convert to strings)
# ---------------------------------------------------------------------

@singledispatch
def to_serializable(val):
    """Used by default."""
    return str(val)


@to_serializable.register(datetime)
def ts_datetime(val):
    """Used if *val* is an instance of datetime."""
    return val.isoformat() + "Z"


@to_serializable.register(Bar)
def ts_bar(val):
    """Used if *val* is an instance of our Bar class."""
    return "BAR: {}".format(str(val))


def test():
    """A function to test it all out! Create some objects then call
    `to_serializable` on each of them.
    """
    objects = [
        "A simple string",
        datetime.now(),
        Foo(),
        Bar(),
    ]

    for item in objects:
        print(to_serializable(item))

        # Expected output is something like:
        # ---------------------------------
        # A simple string
        # 2016-08-23T17:02:08.665038Z
        # I'm a Foo instance, named 'foo'
        # BAR: I'm a Bar instance, with value = 'bar'


if __name__ == "__main__":
    test()
