package Stack is

   type IntegerStack is private;

   -- Max stack size (if not big enough for ackermann function make it bigger!)
   sizeOfStack: constant Integer := 200000;

   -- All the public stack functions
   procedure Push(S: in out IntegerStack; I: Integer);
   procedure Pop(S: in out IntegerStack; I: out Integer);
   function Empty(S: IntegerStack) return Boolean;

   private
      type stackType is array(1..sizeOfStack) of Integer;
      type IntegerStack is record
         Size: Integer := 0;
         Data: stackType;
      end record;
end Stack;
