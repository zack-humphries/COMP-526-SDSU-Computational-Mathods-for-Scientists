!! Zachary Humphries
!! COMP 526
!! HW6
!! 11/30/2022

PROGRAM assign7
    IMPLICIT NONE
    REAL, PARAMETER                       :: a = -0.5, b = 0.5
    INTEGER, PARAMETER                    :: n = 20

    call outFile(a,b,n)

    WRITE(*,*) arcLength(n, a, b)

CONTAINS

REAL FUNCTION arcLength(n, a, b)
    IMPLICIT NONE
    INTEGER, INTENT(IN)                  :: n
    REAL, INTENT(IN)                     :: a, b
    REAL, DIMENSION(:,:), ALLOCATABLE    :: derivatives
    INTEGER                              :: count = 1, iostat
    REAL                                 :: sum = 0.0

    ALLOCATE(derivatives(n+1,2))

    OPEN(11, FILE='outFile.txt', STATUS='OLD', FORM = 'FORMATTED')
    READ(11,* )

    DO
        IF (count > n) THEN
            count = 1
            EXIT
        ELSE
            READ(11,'(f6.3, f9.4)') derivatives(count,1), derivatives(count,2)
        END IF
        count = count+1
    END DO

    count = 2
    DO
        IF (count > n-1) THEN
            EXIT
        ELSE
            sum = sum + ABS(derivatives(count,2))
        END IF
        count = count+1
    END DO
    arcLength = ((b-a)/n) * ((ABS(derivatives(1,2)))/2 + sum + (ABS(derivatives(n+1,2)))/2)

END FUNCTION

END PROGRAM assign7

SUBROUTINE outFile(a,b,n)
    IMPLICIT NONE
    REAL, INTENT(IN)                       :: a, b
    INTEGER, INTENT(IN)                    :: n
    REAL                                   :: x_gap, xi
    INTEGER                                :: length_of_list
    INTEGER                                :: count = 1
    REAL, DIMENSION(:), ALLOCATABLE        :: x_list
    REAL, DIMENSION(:), ALLOCATABLE        :: f_prime_list


    length_of_list = (n/(b-a))+1
    x_gap = ((b-a)/n)


    ALLOCATE(x_list(length_of_list))
    ALLOCATE(f_prime_list(length_of_list))

    xi = a

    DO
        IF (count > length_of_list) THEN
            count = 1
            EXIT
        ELSE
            x_list(count) = xi
            f_prime_list(count) = f_prime(xi)
            xi = xi + x_gap
            count = count+1
        END IF
    END DO

    count = 1

    OPEN(10, FILE='outFile.txt', STATUS='UNKNOWN', FORM='FORMATTED')

    WRITE(10,*) "    x    f'(x)"
    DO
        IF (count > length_of_list) THEN
            count = 1
            EXIT
        ELSE
            WRITE(10,"(f6.3, f9.4)") x_list(count), f_prime_list(count)
            count = count+1
        END IF
    END DO

    CLOSE(10)


CONTAINS

REAL FUNCTION f_prime(x)
    IMPLICIT NONE
    REAL, INTENT(IN) :: x
    f_prime = 1.0/SQRT(((x**2)+1.0))
END FUNCTION


END SUBROUTINE outFile
