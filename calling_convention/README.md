# Calling Convention in x86_64
This project is dedicated to experiment on the [**Calling Convention**](https://wiki.osdev.org/Calling_Conventions) by looking into the assembly code which is compiled from the source code written in C.

## QuickStart

In order to compare the different behaviors performed by `i686-elf` cross compiler and `x86_64-linux-gnu` native compiler, we can look into the assembly codes generated with the variable `CROSS_COMPILE` being enabled or disabled in `Makefile`. If `CROSS_COMPILE` is not empty, it means cross compilation is enabled, and vice versa.

```makefile
# ...

# Enable cross-compilation by setting CROSS_COMPILE to non-empty value
CROSS_COMPILE = 1

# ...
```

Ensuring current directory is the same as where `Makefile` exits at before executing `make`.

```bash
make clean; make
```

If the `make` process is completed without an error, take a look at this file `build/calling_convention.S` for the disassembly of `main` function. Its code snippet is as show below.

```assembly
# Target: 32-bit i686-elf
08048054 <main>:
 8048054:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 8048058:	83 e4 f0             	and    $0xfffffff0,%esp
 804805b:	ff 71 fc             	push   -0x4(%ecx)
 804805e:	55                   	push   %ebp
 804805f:	89 e5                	mov    %esp,%ebp
 8048061:	51                   	push   %ecx
 8048062:	83 ec 14             	sub    $0x14,%esp
 8048065:	6a 28                	push   $0x28	# Argument 7
 8048067:	6a 23                	push   $0x23	# Argument 6
 8048069:	6a 1e                	push   $0x1e	# Argument 5
 804806b:	6a 19                	push   $0x19	# Argument 4
 804806d:	6a 14                	push   $0x14	# Argument 3
 804806f:	6a 0f                	push   $0xf		# Argument 2
 8048071:	6a 0a                	push   $0xa		# Argument 1
 8048073:	6a 35                	push   $0x35	# Argument 0
 8048075:	e8 13 00 00 00       	call   804808d <add_numbers>
 804807a:	83 c4 20             	add    $0x20,%esp
 804807d:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048080:	b8 00 00 00 00       	mov    $0x0,%eax
 8048085:	8b 4d fc             	mov    -0x4(%ebp),%ecx
 8048088:	c9                   	leave
 8048089:	8d 61 fc             	lea    -0x4(%ecx),%esp
 804808c:	c3                   	ret

# Target 64-bit x86_64-linux-gnu
0000000000401000 <main>:
  401000:	f3 0f 1e fa          	endbr64
  401004:	55                   	push   %rbp
  401005:	48 89 e5             	mov    %rsp,%rbp
  401008:	48 83 ec 10          	sub    $0x10,%rsp
  40100c:	6a 28                	push   $0x28		# Argument 7
  40100e:	6a 23                	push   $0x23		# Argument 6
  401010:	41 b9 1e 00 00 00    	mov    $0x1e,%r9d	# Argument 5
  401016:	41 b8 19 00 00 00    	mov    $0x19,%r8d	# Argument 4
  40101c:	b9 14 00 00 00       	mov    $0x14,%ecx	# Argument 3
  401021:	ba 0f 00 00 00       	mov    $0xf,%edx	# Argument 2
  401026:	be 0a 00 00 00       	mov    $0xa,%esi	# Argument 1
  40102b:	bf 35 00 00 00       	mov    $0x35,%edi	# Argument 0
  401030:	e8 0e 00 00 00       	call   401043 <add_numbers>
  401035:	48 83 c4 10          	add    $0x10,%rsp
  401039:	89 45 fc             	mov    %eax,-0x4(%rbp)
  40103c:	b8 00 00 00 00       	mov    $0x0,%eax
  401041:	c9                   	leave
  401042:	c3                   	ret
```

## Conclusion

For the modern 64-bit application, it appears that the first 6 arguments for the sub-routine (sub-function) are stored in general-purpose registers such as `%edi`, `%esi`, etc. The rest of the arguments are pushed onto the stack.

By contrast, 32-bit application only pushes all the arguments onto the stack without using general-registers to pass data.