global _start

section .data
    msg db 'Hello, World', 0xA
    len equ $ - msg

section .text
_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; stdout
    mov rsi, msg
    mov rdx, len
    syscall

    mov rax, 60         ; syscall: exit
    xor rdi, rdi
    syscall

