!/************************* iterativeAckermannFunction.f90 ****************************
! Student Name: Erik Zorn - Wallentin  Student Number: 0864583
! Date: Thur, Feb.18 / 2016            Course Name: CIS*4500
! I have exclusive control over this submission via my password.
! By including this statement in this header comment, I certify that:
!     1) I have read and understood the University policy on academic integrity;
!     2) I have completed the Computing with Integrity Tutorial on Moodle; and
!     3) I have achieved at least 80% in the Computing with Integrity Self Test.
! I assert that this work is my own. I have appropriately acknowledged any and all material
! (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
! Furthermore, I certify that this assignment was prepared by me specifically for this course.
!****************************************************************************/

!This program iteratively calls ackermann function to calculate an input (m,n)

module stack
 
	public
	!The struct of the stack
	type stackStruct
		integer, allocatable :: data(:)
		integer :: size = 0
	end type stackStruct
 
	!Size of the struct
	integer:: stackSize = 20
 
contains
 
	!push subroutine
	subroutine push(stackVar, numberInStack)
		type(stackStruct), intent(inout) :: stackVar
		integer, intent(in) :: numberInStack
		integer, allocatable :: wk(:)
			if (.not. allocated(stackVar % data)) then
				! Allocate space if not yet done
				allocate(stackVar % data(stackSize))
 
			elseif (stackVar % size == size(stackVar % data)) then
				! Grow the allocated space
				allocate(wk(size(stackVar % data) + stackSize))
				wk(1: stackVar % size) = stackVar % data
				call move_alloc(wk, stackVar % data)
 
			end if
 
			! Store the data in the stack
			stackVar % size = stackVar % size + 1
			stackVar % data(stackVar % size) = numberInStack
	end subroutine push
 
	!pop subroutine
	function pop(stackVar)
		integer :: pop
		type(stackStruct), intent(inout) :: stackVar
		if (stackVar % size == 0 .or. .not. allocated(stackVar % data)) then
			pop = 0
			return
		end if
		pop = stackVar % data(stackVar % size)
		stackVar % size = stackVar % size - 1
	end function pop
 
	!isEmpty subroutine
	logical function isEmpty(stackVar)
		type(stackStruct), intent(inout) :: stackVar
		isEmpty = (stackVar % size == 0 .or. .not. allocated(stackVar % data))
	end function isEmpty
 
end module stack
 
program iterativeInFortran
	use stack
	implicit none
  
	!Stack Variables
	integer :: resultFromStack
	type(stackStruct) :: stackVar
	
	!Input variables from user
	integer :: firstNum = 0
	integer :: secondNum = 0
	
	!Timer variables
	integer :: startTime
	integer :: finishTime
	integer :: rateOfTime
	
	print*, 'Ackermann function iterative in Fortran: Enter two numbers (Below 4 for a quick result)'
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

	function ackermannFunc(m, n) result(ackermannResult)
		integer, intent(in) :: m, n ! input
		
		integer             :: ackermannResult ! output
		integer             :: mResult ! output
		integer             :: nResult ! output
		
		integer :: resultFromStack
		type(stackStruct) :: stackVar
		
		mResult = m
		nResult = n
		
		call push(stackVar, mResult)
		do while (.NOT. isEmpty(stackVar))
				mResult = pop(stackVar)
				if (mResult == 0) then
					nResult = nResult + 1;
				else if (nResult == 0) then
					call push(stackVar, mResult - 1)
					nResult = 1;
				else
					call push(stackVar, mResult - 1)
					call push(stackVar, mResult)
					nResult = nResult - 1;
				end if
		end do
		ackermannResult = nResult;
		
	end function ackermannFunc
	
end program iterativeInFortran
!	return n;
!}
