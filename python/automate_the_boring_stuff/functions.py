
def helloWorld():
    print("Hello, World")

helloWorld()

def hello(name):
    print ("Hello, " + name)

hello("world")
hello("mike")

def bar():
    global foo
    print("What is foo? " + str(foo))

foo = 42
bar()
