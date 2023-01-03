PROGRAM fcnDomain
    IMPLICIT NONE
    REAL                :: x
    REAL                :: fcnVal
    REAL                :: y1


    READ(*,*) x
    y1=x
    IF (y1 >= -1 .AND. y1 <= 3) THEN
        fcnVal = computeVal(y1)
        WRITE(*,*) fcnVal
    ELSE
        WRITE(*,*) x, ' is out of range. Need -1 =< x =< 3. Run program again.'
        WRITE(*,*)
    END IF
    
CONTAINS
    REAL FUNCTION computeVal(y)
        REAL, INTENT(IN) :: y
        computeVal = SQRT((y+1)*(3-y))
    END FUNCTION computeVal
END PROGRAM fcnDomain