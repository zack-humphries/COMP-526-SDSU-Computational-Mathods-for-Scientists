!! Zachary Humphries
!! COMP 526
!! HW6
!! 11/16/2022

PROGRAM assign6
    IMPLICIT NONE
    REAL, PARAMETER         :: PI = 3.14159265358979
    REAL, DIMENSION(49)     :: A1
    REAL, DIMENSION(7,7)    :: A
    REAL, DIMENSION(7)      :: b, x_array
    REAL                    :: h, ai
    INTEGER                 :: count = 1, count2 = 1
    
    h = PI/4.0

    A1 = (/2, -1,  0,  0,  0,  0,  0, &
         -1,  2, -1,  0,  0,  0,  0, &
          0, -1,  2, -1,  0,  0,  0, &
          0,  0, -1,  2, -1,  0,  0, &
          0,  0,  0, -1,  2, -1,  0, &
          0,  0,  0,  0, -1,  2, -1, &
          0,  0,  0,  0,  0, -1,  2  /)

    A = RESHAPE(A1, SHAPE(A))
    A = TRANSPOSE(A)

    DO
        IF (count == 7) THEN
            b(count) = h*h*(2.0*PI+p(count*h))
            count = 1
            EXIT
        END IF
        b(count) = h*h*(p(count*h))
        count = count + 1
    END DO


    !! STEP 1
    DO
        IF (count > 7) THEN
            count = 1
            EXIT
        END IF

        IF (count == 1) THEN
            b(1) = b(1)/A(1,1) 
            A(1,:) = A(1,:)/A(1,1)
        ELSE
            ai = A(count,count-1)

            b(count-1) = b(count-1)*ai
            A(count-1,:) = A(count-1,:)*ai

            b(count) = b(count)-b(count-1)
            A(count,:) = A(count,:)-A(count-1,:)

            b(count-1) = b(count-1)/ai
            A(count-1,:) = A(count-1,:)/ai

            ai = A(count,count)
            b(count) = b(count)/ai
            A(count,:) = A(count,:)/ai

        END IF
        count = count+1
    END DO
        
    !! STEP 2
    count2 = 7
    DO
        IF (count2 < 1) THEN
            EXIT
        END IF

        IF (count2 == 7) THEN
            x_array(count2) = b(count2)
        ELSE
            x_array(count2) = b(count2) - (A(count2, count2+1)*x_array(count2+1))
        END IF
        count2 = count2 - 1
    END DO
    
    WRITE(*,*) "x = "

    DO
        IF (count > 7) THEN
            count =1
            EXIT
        END IF
        PRINT *, x_array(count)
        count = count+1
    END DO

CONTAINS
    REAL FUNCTION p(x)
        IMPLICIT NONE
        REAL, INTENT(IN) :: x
        p = 2.0*SIN(x) + x*COS(x)
    END FUNCTION

END PROGRAM assign6