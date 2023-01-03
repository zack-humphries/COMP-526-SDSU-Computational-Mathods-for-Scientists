PROGRAM runge_fourth
    IMPLICIT NONE
    
    REAL::x0=1,x, x_end,x1,k1,k2,k3,k4,k,h
    x1=x0
    x_end=x0
    
    h = 0.5
    
    x = 9.0

    
    
    DO WHILE (x1<x)
    
      k1=h*f(x1)
      k2=h*f(x1+(h/2))
      k3=h*f(x1+(h/2))
      k4=h*f(x1+h)
    
      k=(1/6.)*(k1+(2*k2)+(2*k3)+k4)
    
    
      x1=x1+h
      x_end = x_end+k
    
    END DO

    WRITE(*,*) x1
    WRITE(*,*) x_end

    
   CONTAINS
    
    REAL function f(x1)
    REAL, INTENT(IN) ::x1
      f=1.0/(2.0*x1)
    return
    end function f
END PROGRAM runge_fourth