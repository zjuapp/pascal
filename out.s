section .data
section .text
global main
main:
xor esi, esi
extern printr
extern prints
extern print
sub esp, 92
xor edi,edi
mov edi, 0
mov ebp, esp
mov [ebp + 0], edi
baab:
xor edi,edi
mov edi, 10
mov eax, [ebp + 0]
cmp eax, edi
jz caab
mov ebp, esp
mov edi, [ebp + 0]
mov ebp, esp
mov ebx, [ebp + 0]
mov ebp, esp
push esi
xor esi, esi
mov edx, edi
imul edx, 4
add esi, edx

mov [ebp + esi + 48], ebx
pop esi
mov eax, [ebp + 0]
add eax, 1
mov [ebp + 0], eax
jmp baab
caab:
xor edi,edi
mov edi, 0
mov ebp, esp
mov [ebp + 0], edi
daab:
xor edi,edi
mov edi, 10
mov eax, [ebp + 0]
cmp eax, edi
jz eaab
mov ebp, esp
mov edi, [ebp + 0]
xor ebx,ebx
mov ebx, 10
mov ebp, esp
mov ecx, [ebp + 0]
sub ebx, ecx
mov ebp, esp
push esi
xor esi, esi
mov edx, edi
imul edx, 4
add esi, edx

mov [ebp + esi + 4], ebx
pop esi
mov eax, [ebp + 0]
add eax, 1
mov [ebp + 0], eax
jmp daab
eaab:
xor edi,edi
mov edi, 0
mov ebp, esp
mov [ebp + 0], edi
faab:
xor edi,edi
mov edi, 10
mov eax, [ebp + 0]
cmp eax, edi
jz gaab
mov ebp, esp
mov edi, [ebp + 0]
mov ebp, esp
mov ebx, [ebp + 0]
mov ebp, esp
push esi
xor esi, esi
mov eax, ebx
imul eax, 4
add esi, eax
mov ebx, [ebp + esi + 48]
pop esi
mov ebp, esp
mov ecx, [ebp + 0]
mov ebp, esp
push esi
xor esi, esi
mov eax, ecx
imul eax, 4
add esi, eax
mov ecx, [ebp + esi + 4]
pop esi
imul ebx, ecx
mov ebp, esp
push esi
xor esi, esi
mov edx, edi
imul edx, 4
add esi, edx

mov [ebp + esi + 48], ebx
pop esi
mov eax, [ebp + 0]
add eax, 1
mov [ebp + 0], eax
jmp faab
gaab:
xor edi,edi
mov edi, 0
mov ebp, esp
mov [ebp + 0], edi
haab:
xor edi,edi
mov edi, 10
mov eax, [ebp + 0]
cmp eax, edi
jz iaab
mov ebp, esp
mov ebx, [ebp + 0]
mov ebp, esp
push esi
xor esi, esi
mov eax, ebx
imul eax, 4
add esi, eax
mov ebx, [ebp + esi + 48]
pop esi
push dword ebx
call print
pop ebx
mov eax, [ebp + 0]
add eax, 1
mov [ebp + 0], eax
jmp haab
iaab:
add esp, 92
mov eax, 1
mov ebx, 0
int 80h
