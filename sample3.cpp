




    mov ecx, 0         ; Initialize the counter (i) to 0

loop_start:
    cmp ecx, 10        ; Compare the counter (i) with the loop condition (10)
    jge loop_end       ; If i >= 10, jump to the end of the loop

    ; Print the message "AI is taking over..."
    ; ... (code to print the message)

    ; ... (code to print a new line)

    inc ecx            ; Increment the counter (i)
    jmp loop_start     ; Jump back to the start of the loop

loop_end:
    ; Rest of the code follows...
