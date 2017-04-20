CFLAGS = -fPIC

all: JNI_HelloWorld.o
	gcc -shared -Wl,-soname,libJNI_Example.so -I/usr/lib/jvm/java-1.6.0-openjdk/include -I/usr/lib/jvm/java-1.6.0-openjdk/include/linux -o libJNI_HelloWorld.dll JNI_HelloWorld.o

JNI_HelloWorld.o : JNI_HelloWorld.c
	gcc $(CFLAGS) -I/usr/lib/jvm/java-1.6.0-openjdk/include -I/usr/lib/jvm/java-1.6.0-openjdk/include/linux -c JNI_HelloWorld.c