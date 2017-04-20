identification division.
program-id.  a3.
author.  Erik Zorn-Wallentin.
* an example showing how to read a sequential file without


environment division.
input-output section.
file-control.
    select romanFile assign to "input.txt"
		 organization is line sequential.

data division.
file section.
fd romanFile.

*> Read in one by line and get the calculation of each line
01 romanInfo.
   02  romanNumerals       pic x(10).

*> Each line will have some variables asscoiated with it
*> romanChar is the current one we are looking at
*> nextRomanChar is the next one after the current one
*> romanLength gets the length of the string
*> startLength always starts at slot 1
*> currValue is the converted value from the romanChar
*> nextValue is the converted value from the nextRomanChar
*> resultInteger is the final calculated result to be printed!
working-storage section.
	01  romanChar          pic x.
	01  nextRomanChar      pic x.
	01  romanLength        pic 999.
	77  startLength        pic 999 value 1.
	77  nextPos            pic 999 value 0.
	77  currValue          pic 999 value 0.
	77  nextValue          pic 999 value 0.
	77  resultInteger      pic 9999 value 0.
procedure division.

begin.
	open input romanFile
	read romanFile
		at end move high-values to romanInfo
	end-read

	display ""
	display "********** ROMAN CALCULATOR **********"

	*> Read in from file line by line
	perform until romanInfo = high-values
		if romanNumerals > spaces then
			perform varying    romanLength from length of romanNumerals by -1
				until romanNumerals (romanLength: 1) > space
			end-perform
		else
			move zero to romanLength
		end-if
		
		add 1 to romanLength
		perform until startLength = romanLength
			move romanNumerals(startLength:1) to romanChar(1:1)
			move startLength to nextPos
			add 1 to nextPos

			*> Here we check the next character to see if we subtract or add!!
		
			if nextPos < romanLength
				move romanNumerals(nextPos:1) to nextRomanChar(1:1)
				if nextRomanChar = 'm' or nextRomanChar = 'M' then
					move 1000 to nextValue
				else
					if nextRomanChar = 'd' or nextRomanChar = 'D' then
						move 500 to nextValue
					else
						if nextRomanChar = 'c' or nextRomanChar = 'C' then
							move 100 to nextValue
						else
							if nextRomanChar = 'l' or nextRomanChar = 'L' then
								move 50 to nextValue
							else
								if nextRomanChar = 'x' or nextRomanChar = 'X' then
									move 10 to nextValue
								else
									if nextRomanChar = 'v' or nextRomanChar = 'V' then
										move 5 to nextValue
									else
										if nextRomanChar = 'i' or nextRomanChar = 'I' then
											move 1 to nextValue
										end-if
									end-if			
								end-if		
							end-if
						end-if
					end-if
				end-if
			end-if

			*>display romanChar
			*> Now we iterate through the string and compare it to the next character to determine add or sub
			if romanChar = 'm' or romanChar = 'M' then
				move 1000 to resultInteger
				move 1000 to currValue
			else
				if romanChar = 'd' or romanChar = 'D' then
					move 500 to currValue
					if currValue < nextValue
						subtract 500 from resultInteger
					else
						add 500 to resultInteger
					end-if
				else
					if romanChar = 'c' or romanChar = 'C' then
						move 100 to currValue
						if currValue < nextValue
							subtract 100 from resultInteger
						else
							add 100 to resultInteger
						end-if
					else
						if romanChar = 'l' or romanChar = 'L' then
							move 50 to currValue
							if currValue < nextValue
								subtract 50 from resultInteger
							else
								add 50 to resultInteger
							end-if
						else
							if romanChar = 'x' or romanChar = 'X' then
								move 10 to currValue
								if currValue < nextValue
									subtract 10 from resultInteger
								else
									add 10 to resultInteger
								end-if
							else
								if romanChar = 'v' or romanChar = 'V' then
									move 5 to currValue
									if currValue < nextValue
										subtract 5 from resultInteger
									else
										add 5 to resultInteger
									end-if

								else
									if romanChar = 'i' or romanChar = 'I' then
										move 1 to currValue
										if currValue < nextValue
											subtract 1 from resultInteger
										else
											add 1 to resultInteger
										end-if
						
									end-if
								end-if			
							end-if		
						end-if
					end-if
				end-if
			end-if
		
			add 1 to startLength
		end-perform 
		move 1 to startLength
      
		*> Got all our calculations, print out string and result and reset everything
		display "Your Roman Numerals: ", romanNumerals
		display "The converted result is: ", resultInteger
		display ""
		move 0 to resultInteger

		read romanFile
			at end move high-values to romanInfo
		end-read
   end-perform
   close romanFile
   stop run.
