!/************************* a1.f90 ****************************
!Student Name: Erik Zorn - Wallentin  Student Number: 0864583
!Date: Tue, Feb.3 / 2015              Course Name: CIS*3190 (DE)
!I have exclusive control over this submission via my password.
!By including this statement in this header comment, I certify that:
!1) I have read and understood the University policy on academic integrity;
!2) I have completed the Computing with Integrity Tutorial on Moodle; and
!3) I have achieved at least 80% in the Computing with Integrity Self Test.
!I assert that this work is my own. I have appropriately acknowledged any and all material
!(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
!Furthermore, I certify that this assignment was prepared by me specifically for this course.
!****************************************************************************/

!Program converts an algebraic expression (infix notation) into reverse polish notation

program main
implicit none

	  !Variable source: input string from the user in normal algebraic form
	  !Variable shier: array containing the hierarchy numbers of the input
	  !Variable opstick: the "operator stack" that contains operators from the input
	  !Variable ohier: the array containing the hierarchy numbers of the operators	
	  !Variable polish: the output string, in polish notation
	  character(LEN = 40) :: source = '', shier = ''
	  character(LEN = 40) :: opstick = '', ohier = '', polish = ''

      !Variables for all the operators	  
	  character :: blank = ' ', lparen = '(', rparen = ')' 
	  character :: plus = '+', minus = '-', astrsk = '*', slash = '/'
      
	  integer :: n = 1, length = 0, i = 1, j = 2, k = 1
	  integer :: test1 = 0, test2 = 0
	  
      print*, 'Starting program! You can exit at any time by typing "exit"'	  
	  !Exit when the user types in exit as input, else continue on forever
	  do while ( source /= "exit")
	        !Print out the input from the user
			print*, ''	
			print*, 'Please input an alegbraic expression: '	 
            read(*,*) source
	      	
			!Get the length of the input and trim out rest of array
			length = LEN_TRIM(source)
			do while (n <= length)
				  !Check for operands and number them based on hierarchy
				  if (source(n:n) == plus .or. source(n:n) == minus) then
						shier(n:n) = '3'
                  else if (source(n:n) == astrsk) then
						shier(n:n) = '4'
                  else if (source(n:n) == slash) then
						shier(n:n) = '4'
                  else if (source(n:n) == lparen) then
						shier(n:n) = '1'
                  else if (source(n:n) == rparen) then
                        shier(n:n) = '2'
                  else
                        shier(n:n) = '0'				  
				  end if
				  
				  n = n + 1
			end do

			shier(n:n) = '0'
			ohier(1:1) = '9'
			
			
			n = 1
			
			!Start to translate the code from algebraic expression to VPN
			do while (i <= length)
			      !Check for operands
			      if (source(i:i) == plus .or. source(i:i) == minus &
				  .or. source(i:i) == astrsk .or. source(i:i) == slash) then
					  polish(k:k) = source(i:i)
					  !print*, polish
					  i = i + 1
					  k = k + 1
					  test1 = ichar(ohier(j-1:j-1))
					  test2 = ichar(shier(i:i))
					  !print*, test1
					  if (test1 == 9) then
					       !print*, 'CHANGED'
					       test1 = -1
					  end if 
					  
					  do while (test1 >= test2)
					       polish(k:k) = opstick(j-1:j-1)
				           j = j - 1
						   k = k + 1
						
						   test1 = ichar(ohier(j-1:j-1))
						   test2 = ichar(shier(i:i))
					  end do
					  
					  if (i == length) then
					       !Print out the result
			               !print*, polish
						   !print*, 'EXIT'
					  else
					       !Loop to start   
					  end if
				  !Check for ")"	  
				  else if (source(i:i) == rparen) then
				      i = i + 1
					  j = j - 1
					  
					  test1 = ichar(ohier(j-1:j-1))
					  test2 = ichar(shier(i:i))
					  !print*, test1
					  if (test1 == 9) then
					       !print*, 'CHANGED'
					       test1 = -1
					  end if 
					  
					  do while (test1 >= test2)
					       polish(k:k) = opstick(j-1:j-1)
				           j = j - 1
						   k = k + 1
						
						   test1 = ichar(ohier(j-1:j-1))
						   test2 = ichar(shier(i:i))
					  end do
					  
					  if (i == length) then
					       !Print out the result
			               !print*, polish
						   !print*, 'EXIT'
					  else
					       !Loop to start   
					  end if
				  !Some other operator was found
				  else 
				  
				      opstick(j:j) = source(i:i) 
					  ohier(j:j) = shier(i:i)
				  end if
				  
				  i = i + 1
                  j = j + 1				  
		    end do
	
	        i = 1
			
			!Print out the result
			if ( source /= "exit") then
			     print*, 'Your converted RPN: ', source	
		    end if
			!print*, shier
			!print*, opstick
			!print*, ohier
			!print*, polish
      end do
      print*, 'Now exiting the program!'
	  
end program main