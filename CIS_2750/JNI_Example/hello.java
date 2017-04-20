public class JNI_HelloWorld
{
    static 
    {
	System.loadLibrary("JNI_HelloWorld");
    }

    // This means the method is implemented in another language
    private native void sayHelloWorld();

    public static void maid(String[] args) 
    {
       new JNI_HelloWorld().sayHello(); //Show c program

    }
}