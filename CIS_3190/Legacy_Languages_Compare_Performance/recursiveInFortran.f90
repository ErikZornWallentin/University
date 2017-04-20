!/************************* recursiveInFortran.f90 ****************************
! Student Name: Erik Zorn - Wallentin  Student Number: 0864583
! Date: Thur, April.2 / 2015           Course Name: CIS*3190 (DE)
! I have exclusive control over this submission via my password.
! By including this statement in this header comment, I certify that:
!  1) I have read and understood the University policy on academic integrity;
!  2) I have completed the Computing with Integrity Tutorial on Moodle; and
!  3) I have achieved at least 80% in the Computing with Integrity Self Test.
! I assert that this work is my own. I have appropriately acknowledged any and all material
! (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
! Furthermore, I certify that this assignment was prepared by me specifically for this course.
!****************************************************************************/

!Program calculates ackermann function recursively in FORTRAN 90
!Takes in two numbers and calculates the result

!Next type gfortran recursiveInFrotran.f90 -o recursiveFortran in the command prompt.
!The output would be called: recursiveFortran
!To run program in LINUX environment type: ./recursiveFortran

program RecursiveInFortran
	implicit none

	!Input variables from user
	integer :: firstNum
	integer :: secondNum
	
	!Timer variables
	integer :: startTime
	integer :: finishTime
	integer :: rateOfTime
	
	print*, 'Ackermann function recursive in Fortran: Enter two numbers (Below 4 for a quick result)'
	print*, 'Please enter number 1: '
 	read(*,*) firstNum
 	print*, 'Please enter number 2: '
 	read(*,*) secondNum
	
	!Start the timer before calling the function!
	call system_clock(count_rate=rateOfTime)
	call system_clock(startTime)   
	
	!Call the ackermann function
	write(*,*) ackermannFunc(firstNum, secondNum)
	
	!End the timer after function and display the time it took
	call system_clock(finishTime)         
	write(6,*) 'Total time in seconds: ', float(finishTime - startTime ) / rateOfTime
 
contains
 
	recursive function ackermannFunc(m, n) result(ackermannResult)
		integer :: m
		integer :: n
		integer :: ackermannResult
 
		if (m == 0) then
			ackermannResult = n + 1
		else if (n == 0) then
			ackermannResult = ackermannFunc(m - 1, 1)
		else
			ackermannResult = ackermannFunc(m - 1, ackermannFunc(m, n - 1))
		end if
	end function ackermannFunc
 
end program RecursiveInFortran
