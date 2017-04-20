package body Stack is
	
	-- Push integer on the stack
	procedure Push(S: in out IntegerStack; I: Integer) is
	begin
		if S.Size < sizeOfStack then
			S.Size := S.Size + 1;
			S.Data(S.Size) := I;
		end if;
	end Push;

	-- Pop integer off the stack
	procedure Pop(S: in out IntegerStack; I: out Integer) is
	begin
		if S.Size > 0 then
			I := S.Data(S.Size);
			S.Size := S.Size - 1;
		end if;
	end Pop;

	-- Check if stack if empty
	function Empty(S: IntegerStack) return Boolean is
	begin
		return S.Size = 0;
	end Empty;

end Stack;
