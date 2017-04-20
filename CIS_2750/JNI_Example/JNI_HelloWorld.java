public class JNI_HelloWorld
{
    static 
    {
	//System.loadLibrary("JNI_HelloWorld");
		System.load("C:/Users/Klaus/Desktop/JNI_Example/JNI_HelloWorld.dll");
    }

    // This means the method is implemented in another language
    private native String PM_create1(String fileName);

    public static void main(String[] args) 
    {
       new JNI_HelloWorld().sayHelloWorld(); //Show c program
    }
}