#include <jni.h>
#include <stdio.h>
#include <stdlib.h>

#include "JNI_HelloWorld.h"

// Implementation of native method sayHelloWorld() of JNI_HelloWorld class
JNIEXPORT void JNICALL Java_JNI_1HelloWorld_sayHelloWorld
  (JNIEnv * env, jobject obj)
{
   printf("Hello World\n");
}