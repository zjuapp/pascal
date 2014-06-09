section .data
section .text
global main
main:
sub esp, 12
xor esi, esi
xor edi,edi
mov edi, 10
mov ebp, esp
mov [ebp + 4], edi
push esi
add esi, 0
mov ebp, esp
sub esp, 0
call take
add esp, 0
pop esi
mov ebp, esp
mov edi, [ebp + 4]
push dword edi
extern print
call print
mov eax, 1
mov ebx, 0
int 80h
take:
mov ebp, esp
mov edi, [ebp + esi + 12]
xor ebx,ebx
mov ebx, 10
add edi, ebx
mov ebp, esp
mov [ebp + esi + 12], edi
push esi
add esi, 0
mov ebp, esp
sub esp, 0
call take2
add esp, 0
pop esi
ret
take2:
mov ebp, esp
mov edi, [ebp + esi + 20]
xor ebx,ebx
mov ebx, 2
add edi, ebx
mov ebp, esp
mov [ebp + esi + 20], edi
ret
