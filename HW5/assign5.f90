PROGRAM assign5
    IMPLICIT NONE
    REAL, PARAMETER     :: e = 2.7182818284
    REAL, PARAMETER     :: ic = (1.0/e) - 5.0, startx = -1.0, endx = 1.0
    REAL, PARAMETER     :: h = 0.1
    INTEGER, PARAMETER  :: n = (endx-startx)/h
    REAL                :: k2_list(5), k3_list(5), k4_list(5), k5_list(5), k6_list(5), k_final_list(6)
    REAL, TARGET        :: k1=0.0, k2=0.0, k3=0.0, k4=0.0, k5=0.0, k6=0.0
    REAL                :: yn, ksum=0.0
    REAL, DIMENSION(n)  :: y_list
    INTEGER             :: count, count2

    TYPE ptr_list
        TYPE(REAL), POINTER :: p
    end type ptr_list

    TYPE(ptr_list), DIMENSION(6) :: k_values

    k_values(1)%p => k1
    k_values(2)%p => k2
    k_values(3)%p => k3
    k_values(4)%p => k4
    k_values(5)%p => k5
    k_values(6)%p => k6

    
    

    k2_list = (/1.0/5.0,        0.0,                0.0,                0.0,            0.0/)
    k3_list = (/3.0/40.0,       9.0/40.0,           0.0,                0.0,            0.0/)
    k4_list = (/44.0/45.0,      -56.0/15.0,         32.0/9.0,           0.0,            0.0/)
    k5_list = (/19372.0/6561.0, -25360.0/2187.0,    64448.0/6561.0,     -212.0/729.0,     0.0/)
    k6_list = (/9017.0/3168.0,  -355.0/33.0,        46732.0/5247.0,     49.0/176.0,     -5103.0/18656.0/)

    k_final_list = (/35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0/)

    count = 1
    count2 = 1

    yn= ic
    k1 = f(ic)


    DO
        IF (count > n) EXIT
        ksum=0
        count2 = 1
        WRITE(*,*) "xi: ", h*(count-1)+startx
        !WRITE(*,*) count," K1: ", k1
        DO
            IF (count2 > 5) THEN
                count2=1
                !WRITE(*,*) ksum, yn+(h*(ksum))
                k2 = f(yn+(h*(ksum)))
                ksum=0
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k2_list(count2))
            !WRITE(*,*) count2, ": ", k_values(count2)%p, k2_list(count2)
            count2 = count2 +1
        END DO
        
        !WRITE(*,*) count," K2: ", k2
        
        DO
            IF (count2 > 5) THEN
                count2=1
                k3 = f(yn+(h*(ksum)))
                ksum=0
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k3_list(count2))
            count2 = count2 +1
        END DO
        
        !WRITE(*,*) count," K3: ", k3

        DO
            IF (count2 > 5) THEN
                count2=1
                k4 = f(yn+(h*(ksum)))
                ksum=0
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k4_list(count2))
            count2 = count2 +1
        END DO
        
        !WRITE(*,*) count," K4: ", k4
        DO
            IF (count2 > 5) THEN
                count2=1
                k5 = f(yn+(h*(ksum)))
                ksum=0
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k5_list(count2))
            count2 = count2 +1
        END DO
        
        !WRITE(*,*) count," K5: ", k5
        DO
            IF (count2 > 5) THEN
                count2=1
                k6 = f(yn+(h*(ksum)))
                ksum = 0
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k6_list(count2))
            count2 = count2 +1
        END DO
        !WRITE(*,*) count," K6: ", k6
        DO
            IF (count2 > 6) THEN
                count2=1
                EXIT
            END IF
            ksum = ksum + (k_values(count2)%p *k_final_list(count2))
            count2 = count2 +1
        END DO
        yn = yn + h*(ksum)
        WRITE(*,*) count," yn: ", yn
        k1 = f(yn)
        y_list(count) = yn
        count = count+1
    END DO

CONTAINS
    REAL FUNCTION f(x)
        IMPLICIT NONE
        REAL, INTENT(IN) :: x
        f = 1.0/(EXP(x) - (10*x))
    END FUNCTION f
END PROGRAM assign5