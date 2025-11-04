# Machine Level Representation of Programs
This project is inspired by [Computer Systems: A Programmer's Perspective](https://csapp.cs.cmu.edu/), which is a manner for a learner to understand how a program manipulates memories under the hood.

## `main` Function
```c
int main() {
    int a = 5;
    int b = 10;
    int sum = add(a, b);
    printf("Sum: %d\n", sum);
    return 0;
}
```

### Disassemble `main`

```sh
Dump of assembler code for function main:
   0x0000555555555177 <+0>:     endbr64
   0x000055555555517b <+4>:     push   %rbp
   0x000055555555517c <+5>:     mov    %rsp,%rbp
   0x000055555555517f <+8>:     sub    $0x10,%rsp
   0x0000555555555183 <+12>:    movl   $0x5,-0xc(%rbp)
   0x000055555555518a <+19>:    movl   $0xa,-0x8(%rbp)
   0x0000555555555191 <+26>:    mov    -0x8(%rbp),%edx
   0x0000555555555194 <+29>:    mov    -0xc(%rbp),%eax
   0x0000555555555197 <+32>:    mov    %edx,%esi
   0x0000555555555199 <+34>:    mov    %eax,%edi
   0x000055555555519b <+36>:    call   0x555555555149 <add>
   0x00005555555551a0 <+41>:    mov    %eax,-0x4(%rbp)
   0x00005555555551a3 <+44>:    mov    -0x4(%rbp),%eax
   0x00005555555551a6 <+47>:    mov    %eax,%esi
   0x00005555555551a8 <+49>:    lea    0xe55(%rip),%rax        # 0x555555556004
   0x00005555555551af <+56>:    mov    %rax,%rdi
   0x00005555555551b2 <+59>:    mov    $0x0,%eax
   0x00005555555551b7 <+64>:    call   0x555555555050 <printf@plt>
   0x00005555555551bc <+69>:    mov    $0x0,%eax
   0x00005555555551c1 <+74>:    leave
   0x00005555555551c2 <+75>:    ret
```

## `add` Function

```c
int add(int a, int b) {
    return a + b;
}
```

### Disassemble `add`

```sh
Dump of assembler code for function add:
   0x0000555555555149 <+0>:     endbr64
   0x000055555555514d <+4>:     push   %rbp
   0x000055555555514e <+5>:     mov    %rsp,%rbp
   0x0000555555555151 <+8>:     mov    %edi,-0x4(%rbp)
   0x0000555555555154 <+11>:    mov    %esi,-0x8(%rbp)
   0x0000555555555157 <+14>:    mov    -0x4(%rbp),%edx
   0x000055555555515a <+17>:    mov    -0x8(%rbp),%eax
   0x000055555555515d <+20>:    add    %edx,%eax
   0x000055555555515f <+22>:    pop    %rbp
   0x0000555555555160 <+23>:    ret
```

