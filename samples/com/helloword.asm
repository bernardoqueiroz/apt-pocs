section .text
    org 0x100

start:
    mov ah, 0x09
    lea dx, [message]
    int 0x21
    mov ax, 0x4C00
    int 0x21

message db 'Hello, World!$'
