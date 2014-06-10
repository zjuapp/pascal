section .data
section .text
global main
main:
xor esi, esi
extern printr
extern prints
extern print
sub esp, 8
xor edi,edi
mov edi, 0
mov ebp, esp
mov [ebp + 0], edi
mov ebp, esp
mov eax, ebp
add eax ,0
mov [ebp - 24], eax
xor edi,edi
mov edi, 5

mov [ebp - 28], edi
push esi
push edi
push ebx
push ecx
add esi, 0
sub esp, 12
call gao
add esp, 8
mov ebp, esp
mov eax, [ebp]
add esp, 4
pop ecx
pop ebx
pop edi
pop esi
mov edi, eax
mov ebp, esp
mov [ebp + 4], edi
mov ebp, esp
mov edi, [ebp + 4]
push dword edi
call print
pop edi
mov ebp, esp
mov edi, [ebp + 0]
push dword edi
call print
pop edi
add esp, 8
mov eax, 1
mov ebx, 0
int 80h
gao:
sub esp, 8
mov ebp, esp
mov edi, [ebp + 12]
xor ebx,ebx
mov ebx, 0
cmp ebx, edi
pushf
pop eax
shr eax, 7
and eax, 1
mov edi, eax
cmp edi, 0
jz baab
mov ebp, esp
mov edi, [ebp + 12]
mov ebp, esp
mov eax, [ebp + 16]
mov [ebp - 24], eax
mov ebp, esp
mov ebx, [ebp + 12]
xor ecx,ecx
mov ecx, 1
sub ebx, ecx

mov [ebp - 28], ebx
push esi
push edi
push ebx
push ecx
add esi, 40
sub esp, 12
call gao
add esp, 8
mov ebp, esp
mov eax, [ebp]
add esp, 4
pop ecx
pop ebx
pop edi
pop esi
mov ebx, eax
imul edi, ebx
mov ebp, esp
mov [ebp + 20], edi
jmp caab
baab:
xor edi,edi
mov edi, 1
mov ebp, esp
mov [ebp + 20], edi
caab:
mov ebp, esp
mov ebp, [ebp + 16]
mov edi, [ebp]
mov ebp, esp
mov ebx, [ebp + 20]
add edi, ebx
mov ebp, esp
mov ebp, [ebp + 16]
mov [ebp], edi
mov ebp, esp
mov edi, [ebp + esi + 40]
mov ebp, esp
mov ebx, [ebp + 20]
add edi, ebx
mov ebp, esp
mov [ebp + esi + 40], edi
add esp, 8
ret
test:
sub esp, 8
add esp, 8
ret
