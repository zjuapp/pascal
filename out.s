section .data
baab db "fuck2", 0x0a, 0
caab db "fuck3", 0x0a, 0
daab db "fuck4", 0x0a, 0
section .text
global main
main:
sub esp, 20
xor esi, esi
xor edi,edi
mov edi, 3
mov ebp, esp
mov [ebp + 16], edi
xor edi,edi
mov edi, 4
mov ebp, esp
mov [ebp + 8], edi
mov ebp, esp
mov edi, [ebp + 16]
mov ebp, esp
mov ebx, [ebp + 8]
imul edi, ebx
mov ebp, esp
mov [ebp + 16], edi
mov ebp, esp
mov edi, [ebp + 16]
xor ebx,ebx
mov ebx, 5
mov eax, edi
xor edx, edx
idiv ebx
mov edi, edx
cmp edi, 2
jz eaab
cmp edi, 3
jz faab
cmp edi, 4
jz gaab

jmp haab
eaab:
mov ebp, esp
mov eax, baab
mov [ebp + 0], eax
jmp haab
faab:
mov ebp, esp
mov eax, caab
mov [ebp + 0], eax
jmp haab
gaab:
mov ebp, esp
mov eax, daab
mov [ebp + 0], eax
jmp haab
haab:;
mov ebp, esp
mov ebx, [ebp + 0]
push dword ebx
extern prints
call prints
pop ebx
mov eax, 1
mov ebx, 0
int 80h
