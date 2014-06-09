section .data

hello: db "hello world", 0x0a
hellolen: equ $-hello

section .text
global main

main:
	push edx
	pop ecx
	xor eax, eax
	mov ax, 4
	mov ecx, hello
	mov edx, hellolen
	int 80h
	mov ax, 1
	mov ebx, 0
	int 80h

