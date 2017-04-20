--This code was given from the professor as indicated by the assignment,
--I do not own this code, but its needed for benchmarking !
--I modified the code a bit to be able to benchmark it better!

--To compile this program make sure you are in the correct directory in the terminal for where your file is.
--Follow these steps:
--1. Compile: gcc -c recursiveinada.adb
--2. BIND AND LINK: gnatmake recursiveinada.adb
--3. RUN: ./recursiveinada

with Ada.Text_IO; use Ada.Text_IO;
with ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Calendar; use Ada.Calendar;
with Ada.Calendar.Formatting; use Ada.Calendar.Formatting;
with Ada.Calendar.Time_Zones; use Ada.Calendar.Time_Zones;


procedure recursiveInAda is
	firstNum : integer := 0;
	secondNum : integer := 0;
	
	firstTime : Time := Clock;
	secondTime : Time := Clock;

	--function Ackermann (M, N : in Integer) return Integer is
	function Ackermann (M, N : Natural) return Natural is
	begin
		if M = 0 then
			return N + 1;
		elsif N = 0 then
			return Ackermann (M - 1, 1);
		else
			return Ackermann (M - 1, Ackermann (M, N - 1));
		end if;
	end Ackermann;

begin
	Put_Line("Ackermann function recursive in Fortran: Enter two numbers (Below 4 for a quick result)");
	Put_Line("Please enter number 1: ");
	Get(firstNum);
	Put_Line("Please enter number 2: ");
	Get(secondNum);

	Put_Line("Starting Time: ");
	Put_line(Image(Date => firstTime, Time_Zone => -7*60));
	
	Put(Natural'Image (Ackermann (firstNum, secondNum)));
	
	secondTime := Clock;
	Put_Line(" Ending Time: ");
	Put_line(Image(Date => secondTime, Time_Zone => -7*60));
	
end recursiveInAda;
