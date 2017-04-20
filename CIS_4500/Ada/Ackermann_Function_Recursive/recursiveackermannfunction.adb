--/************************* recursiveackermannfunction.adb ****************************
-- Student Name: Erik Zorn - Wallentin  Student Number: 0864583
-- Date: Thur, Feb.18 / 2016            Course Name: CIS*4500
-- I have exclusive control over this submission via my password.
-- By including this statement in this header comment, I certify that:
--     1) I have read and understood the University policy on academic integrity;
--     2) I have completed the Computing with Integrity Tutorial on Moodle; and
--     3) I have achieved at least 80% in the Computing with Integrity Self Test.
-- I assert that this work is my own. I have appropriately acknowledged any and all material
-- (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
-- Furthermore, I certify that this assignment was prepared by me specifically for this course.
--****************************************************************************/

-- This program iteratively calls ackermann function to calculate an input (m,n)

with Ada.Text_IO; use Ada.Text_IO;
with ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Calendar; use Ada.Calendar;
with Ada.Calendar.Formatting; use Ada.Calendar.Formatting;
with Ada.Calendar.Time_Zones; use Ada.Calendar.Time_Zones;

procedure recursiveAckermannFunction is
	function ackermann (M, N : Natural) return Natural is
	begin
		if M = 0 then
			return N + 1;
		elsif N = 0 then
			return ackermann (M - 1, 1);
		else
			return ackermann (M - 1, ackermann (M, N - 1));
		end if;
	end ackermann;
	
	-- Timer variables
	firstTime : Time := Clock;
	secondTime : Time := Clock;

	-- Ackermann function variables (M, N)
	m : integer := 0;
	n: integer := 0;
begin
	
	Put_Line("Ackermann function recursive in Ada: Enter two numbers (Below 4 for a quick result)");
	Put_Line("Please enter number 1: ");
	Get(m);
	Put_Line("Please enter number 2: ");
	Get(n);

	Put_Line("");
	Put_Line("Starting Time: ");
	Put_line(Image(Date => firstTime, Time_Zone => -7*60));
   
	Put (Natural'Image (ackermann (m, n)));
	
	secondTime := Clock;
	Put_Line("");
	Put_Line("Ending Time: ");
	Put_line(Image(Date => secondTime, Time_Zone => -7*60));
   
end recursiveAckermannFunction;
