--/************************* hangman.adb ****************************
--Student Name: Erik Zorn - Wallentin  Student Number: 0864583
--Date: Thur, Feb.19 / 2015              Course Name: CIS*3190 (DE)
--I have exclusive control over this submission via my password.
--By including this statement in this header comment, I certify that:
--1) I have read and understood the University policy on academic integrity;
--2) I have completed the Computing with Integrity Tutorial on Moodle; and
--3) I have achieved at least 80% in the Computing with Integrity Self Test.
--I assert that this work is my own. I have appropriately acknowledged any and all material
--(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
--Furthermore, I certify that this assignment was prepared by me specifically for this course.
--****************************************************************************/

with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Command_Line;
with ada.strings.unbounded; use ada.strings.unbounded;
with Ada.Strings.Unbounded.Text_IO; use Ada.Strings.Unbounded.Text_IO;
with Ada.Numerics.Discrete_Random;

procedure Hangman is
    --Setup flag variable to check if a "-" should be printed or not, and setup ch variable to check the array of guesses
    flag : Boolean := false;
    guessedCorrect : integer := 0;
    ch : character;
	
    --Setup dictionary that contains 50 elements from hangman example, also get length of the element used at the time
    dictionary : array(1..50) of unbounded_string; 
    lengthOfElement : integer := 0;
    --Setup guesses unbounded string, continue to append to it when a guess is made, also get the length of the guesses string
    guesses : unbounded_string := To_Unbounded_String("");
    lengthOfGuesses : integer := 0;
    correctAmount : integer := 0;
    incorrectAmount: integer := 0;
	
    -- Setup random number generator between 1-50
    type Rand_Range is range 1..50;
    package Rand_Int is new Ada.Numerics.Discrete_Random(Rand_Range);
    seed : Rand_Int.Generator;
    randomNum : Rand_Range;
    value : integer;
	
    -- Function to draw the hangman
    procedure printHangman (result: in Integer) is
    begin
        if result = 1 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X    --- ");
            put_line ("X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
        elsif result = 2 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X    --- ");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
        elsif result = 3 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X    --- /");
            put_line ("X     X /");
            put_line ("X     X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
        elsif result = 4 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X");
            put_line ("X");
            put_line ("X");
        elsif result = 5 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X      \");
            put_line ("X       \");
            put_line ("X");
        elsif result = 6 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .)");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X    / \");
            put_line ("X   /   \");
            put_line ("X");
        elsif result = 7 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X   (. .) **");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X    / \");
            put_line ("X   /   \");
            put_line ("X");
        elsif result = 8 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X** (. .) **");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X    / \");
            put_line ("X   /   \");
            put_line ("X");
        elsif result = 9 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X** (. .) **");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X    / \");
            put_line ("X   /   \");
            put_line ("X        **");
        elsif result = 10 then
            put_line ("XXXXXXX");
            put_line ("X     X");
            put_line ("X    ---");
            put_line ("X** (. .) **");
            put_line ("X  \ --- /");
            put_line ("X   \ X /");
            put_line ("X    \X/");
            put_line ("X     X");
            put_line ("X     X");
            put_line ("X    / \");
            put_line ("X   /   \");
            put_line ("X **     **");
		end if;
    end printHangman;

begin
    dictionary := (To_Unbounded_String("gum"),To_Unbounded_String("sin"),To_Unbounded_String("for"),To_Unbounded_String("cry"),To_Unbounded_String("lug"),
    To_Unbounded_String("bye"),To_Unbounded_String("fly"),To_Unbounded_String("ugly"),To_Unbounded_String("each"),To_Unbounded_String("from"),To_Unbounded_String("work"),
    To_Unbounded_String("talk"),To_Unbounded_String("with"),To_Unbounded_String("self"),To_Unbounded_String("pizza"),To_Unbounded_String("thing"),To_Unbounded_String("feign"),
    To_Unbounded_String("fiend"),To_Unbounded_String("elbow"),To_Unbounded_String("fault"),To_Unbounded_String("dirty"),To_Unbounded_String("budget"),To_Unbounded_String("spirit"),
    To_Unbounded_String("quaint"),To_Unbounded_String("maiden"),To_Unbounded_String("escort"),To_Unbounded_String("pickaxe"),To_Unbounded_String("example"),To_Unbounded_String("tension"),
    To_Unbounded_String("quinine"),To_Unbounded_String("kidney"),To_Unbounded_String("replica"),To_Unbounded_String("sleeper"),To_Unbounded_String("triangle"),To_Unbounded_String("kangaroo"),
    To_Unbounded_String("mahogany"),To_Unbounded_String("sergeant"),To_Unbounded_String("sequence"),To_Unbounded_String("moustache"),To_Unbounded_String("dangerous"),To_Unbounded_String("scientist"),
    To_Unbounded_String("different"),To_Unbounded_String("quiescent"),To_Unbounded_String("magistrate"),To_Unbounded_String("erroneously"),To_Unbounded_String("loudspeaker"),To_Unbounded_String("phytotoxic"),
    To_Unbounded_String("matrimonial"),To_Unbounded_String("parasympathomimetic"),To_Unbounded_String("thigmotropism"));
    put_line ("THE GAME OF HANGMAN -- Exit at any time with '.' or 'N'");
	
    -- Before starting randomly generate word
    Rand_Int.Reset(seed);
    randomNum := Rand_Int.Random(seed);
    value := Integer'Value(Rand_Range'Image(randomNum));
    --Put_Line( dictionary(value) );
    
    lengthOfElement := length( dictionary(value) );

    loop
        correctAmount := 0;
        for i in 1..lengthOfElement loop
            ch := Element( dictionary(value), i );
            --put_line ("CH: " & ch);
            if lengthOfGuesses > 0 then
                for n in 1..lengthOfGuesses loop
                    -- Check if the last guess would be an incorrect guess or not
                    if n = lengthOfGuesses - 1 then
                        --put_line("CHECK LAST CHAR!");
                        if ch = Element( guesses, n ) then
                            --put_line("SET");
                            put(ch);
                            flag := true;
                            correctAmount := correctAmount + 1;
                            guessedCorrect := 2;
                        else
                            if guessedCorrect /= 2 then
                                guessedCorrect := 1;
                                --put_line("UN SET!!");
                            end if;
                        end if;		
                    -- Print out the found guesses
                    elsif ch = Element( guesses, n ) then
                        put(ch);
                        flag := true;
                        correctAmount := correctAmount + 1;
                    end if;
                end loop;
            end if;
			
            -- Print out the not found guesses
            if flag = false then
                put("-");
            end if;
            flag := false;
        end loop;
        new_line;
        -- Check if the guess was a correct word or not, if it was not correct it will call a function to print the hangman
        if guessedCorrect = 1 then
            put_line ("Sorry, that letter isn't in the word.");
            incorrectAmount := incorrectAmount + 1;
            if (incorrectAmount = 1) then
                put_line ("First we draw a head.");
                printHangman(1);
            elsif (incorrectAmount = 2) then
                put_line ("Now we draw a body.");
                printHangman(2);
            elsif (incorrectAmount = 3) then
                put_line ("Next we draw an arm.");
                printHangman(3);
            elsif (incorrectAmount = 4) then
                put_line ("This time it's the other arm.");
                printHangman(4);
            elsif (incorrectAmount = 5) then
                put_line ("Now, let's draw the right leg.");
                printHangman(5);
            elsif (incorrectAmount = 6) then
                put_line ("This time we draw the left leg.");
                printHangman(6);
            elsif (incorrectAmount = 7) then
                put_line ("Now we put up a hand.");
                printHangman(7);
            elsif (incorrectAmount = 8) then
                put_line ("Next the other hand.");
                printHangman(8);
            elsif (incorrectAmount = 9) then
                put_line ("Now we draw one foot.");
                printHangman(9);
            elsif (incorrectAmount = 10) then
                put_line ("Here's the other foot -- You're hung!!");
                printHangman(10);
                exit;		
            end if;
        end if;
		
        guessedCorrect := 0;
		
        put_line ("Here are the letters you used:");
        put_line(To_String(guesses));
        --Check if the word is completed
        if correctAmount = lengthOfElement then
            put_line ("You found the word.");
            put_line ("Do you want another word? (Y/N)");
            get(ch);
            if ch = 'Y' then
                -- Before starting randomly generate word
                Rand_Int.Reset(seed);
                randomNum := Rand_Int.Random(seed);
                value := Integer'Value(Rand_Range'Image(randomNum));
                --Put_Line( dictionary(value) );
				
                --Reset everything
                lengthOfGuesses := 0;
                correctAmount := 0;
                incorrectAmount := 0;
                flag := false;
                lengthOfElement := length( dictionary(value) );
                guesses := To_Unbounded_String("");
            else
                ch := '.';
            end if;
        else
            put_line ("What is your guess?");
            get(ch);
            Append( guesses, ch & ",");
            lengthOfGuesses := length( guesses );
            --put_line ("LENGTH OF gUESSES" & Integer'Image(lengthOfGuesses));
        end if;	
			
        exit when ch = '.' or ch = 'N';
    end loop;
	put_line ("Sorry, you loose. The word was " & dictionary(value) );
	put_line ("You missed that one.");
    put_line ("Ending...");
end Hangman;