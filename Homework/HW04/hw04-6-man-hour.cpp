/*
    เขียนโปรแกรมภาษาซีเพื่อรับข้อมูลพนักงานของบริษัทซอร์ฟแวร์ โดยรับข้อมูล รหัสประจำตัวพนักงาน , จำนวนชั่วโมงที่ทำงาน , รายได้ต่อชั่วโมง จากนั้นให้แสดงข้อมูลเลขประจำตัวพนักงาน พร้อมกับรายได้ทั้งหมดที่หนักงานจะได้รับทั้งหมด
    (ผลลัพธ์ของ Salary จะต้องอยู่ในรูปแบบ Decimal Number เท่านั้น เช่น 374,000.00)

    Test case:
        Input the Employees ID(Max. 10 chars): 
            0342
        Input the working hrs: 
            8
        Salary amount/hr: 
            15000
    Output:
        Expected Output:
        Employees ID = 0342
        Salary = U$ 120,000.00

    Test case:
        Input the Employees ID(Max. 10 chars): 
            0000500349
        Input the working hrs: 
            11
        Salary amount/hr: 
            34000
    Output:
        Expected Output:
        Employees ID = 0000500349
        Salary = U$ 374,000.00
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char employeeId[11] ;
    float hoursWorked, hourlyRate ;
    printf( "Input the Employees ID(Max. 10 chars): \n" ) ;
    scanf( "%s", employeeId ) ;
    printf( "Input the working hrs: \n" ) ;
    scanf( "%f", &hoursWorked ) ;
    printf( "Salary amount/hr: \n" ) ;
    scanf( "%f", &hourlyRate ) ;

    float salary = hoursWorked * hourlyRate;
    printf( "Expected Output: \n" ) ;
    printf( "Employee ID = %s\n", employeeId ) ;
    printf( "Salary = U$ " ) ;

    char num[100];
    sprintf( num, "%.2f", salary ) ;

    int size = strlen( num ) ;
    int zise = 0 ;
    int count = 0, dot = 0, x = 0 ;

    for ( x = 0 ; x < size ; x++ ) {
        if (num[x] == '.') {
            dot = x ;
            while ( count < size - x - 1 ) {
                count++; 
            } // end while
        } // end if
    } // end for
    if (count > 0) {
        zise = size - count ;
        zise-- ;
    } else {
        zise = size ; 
    } //end else
    if (zise < 4) {
        for ( x = 0 ; x < zise ; x++ ) {
            printf( "%c", num[x] ) ;
        } // end for
    } // end if
    if ( zise > 3 ) {
        if ( zise % 3 == 1 ) {
            for ( x = 0 ; x < zise ; x++ ) {
                printf( "%c", num[x] ) ;
                if ( ( zise - x ) % 3 == 1 && x != zise - 1 ) {
                    printf( "," ) ;
                } // end if
            } // end for
        } // end if
        if ( zise % 3 == 2 ) {
            for ( x = 0 ; x < zise ; x++ ) {
                printf( "%c", num[x] ) ;
                if ( ( zise - x ) % 3 == 1 && x != zise - 1 ) {
                    printf( "," ) ;
                } // end if
            } // end for
        } // end if
        if ( zise % 3 == 0 ) {
            for ( x = 0 ; x < zise ; x++ ) {
                printf( "%c", num[x] ) ;
                if ( ( zise - x ) % 3 == 1 && x != zise - 1 ) {
                    printf( "," ) ;
                } // end if
            } // end for
        } // end if
    } // end if
    if ( num[dot] == '.' ) {
        if ( num[dot + 4] >= 53 && num[dot + 4] <= 58 ) {
            num[dot + 3]++;
        } // end if 
    } // end if 
    printf( "." ) ;
    for ( x = dot + 1 ; x <= dot + 2 && x < size ; x++ ) {
        printf( "%c", num[x] ) ;
    } // end for 
    printf( "\n" ) ;
    return 0 ;
} // end main function