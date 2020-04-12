            ; CALL XREF from sym.__libc_csu_init @ 0x9a9
            ;-- section.:
            ;-- section..comment:
            ;-- section..symtab:
            ;-- section..strtab:
            ;-- section..shstrtab:
            ;-- segment.LOAD0:
            ;-- segment.GNU_STACK:
            ;-- segment.ehdr:
            ;-- .comment:
            ;-- __libc_start_main:
            ;-- __gmon_start__:
            ;-- _ITM_registerTMCloneTable:
            ;-- __cxa_finalize:
            ;-- rbx:
            ;-- r9:
            ;-- r10:
            ;-- r11:
            ;-- r12:
            ;-- r13:
            ;-- r14:
            ;-- r15:
            ;-- rax:
            ;-- rsi:
            ;-- rcx:
            ;-- rdx:
            ;-- rdi:
            ;-- r8:
            ;-- rbp:
            ;-- rflags:
            ;-- rsp:
┌ 325: loc.imp._ITM_deregisterTMCloneTable (int64_t arg2, uint32_t arg3, int64_t arg4);
│           ; arg int64_t arg2 @ rsi
│           ; arg uint32_t arg3 @ rdx
│           ; arg int64_t arg4 @ rcx
│       ┌─< 0x00000000      7f45           jg 0x47                     ; [28] ---- section size 254 named .shstrtab
│       │   ; DATA XREF from unk @ 
│       │   0x00000002      4c460201       add r8b, byte [rcx]         ; arg4
│       │   0x00000006      0100           add dword [rax], eax
│       │   0x00000008      0000           add byte [rax], al
│       │   0x0000000a      0000           add byte [rax], al
│       │   0x0000000c      0000           add byte [rax], al
│       │   0x0000000e      0000           add byte [rax], al
│       │   0x00000010      0300           add eax, dword [rax]
│       │   0x00000012      3e0001         add byte ds:[rcx], al       ; arg4
│       │   0x00000015      0000           add byte [rax], al
│       │   0x00000017      00b006000000   add byte [rax + 6], dh
│       │   0x0000001d      0000           add byte [rax], al
│       │   ; DATA XREF from unk @ 
│       │   0x0000001f      004000         add byte [rax], al
│       │   ; DATA XREF from str.Java_like_hashcode_is_0x_.8X @ +0xca
│       │   0x00000022      0000           add byte [rax], al
│       │   0x00000024      0000           add byte [rax], al
│       │   0x00000026      0000           add byte [rax], al
│       │   0x00000028      381a           cmp byte [rdx], bl          ; arg3
│       │   0x0000002a      0000           add byte [rax], al
│       │   ; DATA XREF from main @ 0x811
│       │   0x0000002c      0000           add byte [rax], al
│       │   0x0000002e      0000           add byte [rax], al
│       │   0x00000030      0000           add byte [rax], al
│       │   0x00000032      0000           add byte [rax], al
│       │   0x00000034      400038         add byte [rax], dil
│       │   0x00000037      0009           add byte [rcx], cl          ; arg4
│       │   0x00000039      004000         add byte [rax], al
│       │   0x0000003c  ~   1d001c0006     sbb eax, 0x6001c00
│       │   ;-- segment.PHDR:
│       │   0x00000040      06             invalid
│       │   0x00000041      0000           add byte [rax], al
│       │   0x00000043      000400         add byte [rax + rax], al
│       │   0x00000046  ~   0000           add byte [rax], al
│       │   ; CODE XREF from loc.imp._ITM_deregisterTMCloneTable @ 
│       └─> 0x00000047      004000         add byte [rax], al
│           0x0000004a      0000           add byte [rax], al
│           0x0000004c      0000           add byte [rax], al
│           0x0000004e      0000           add byte [rax], al
│           0x00000050      400000         add byte [rax], al
│           0x00000053      0000           add byte [rax], al
│           0x00000055      0000           add byte [rax], al
│           0x00000057      004000         add byte [rax], al
│           0x0000005a      0000           add byte [rax], al
│           0x0000005c      0000           add byte [rax], al
│           0x0000005e      0000           add byte [rax], al
│           0x00000060      f8             clc
│           ; DATA XREFS from main @ 0x7f1, 0x819
│           0x00000061      0100           add dword [rax], eax
│           0x00000063      0000           add byte [rax], al
│           ; DATA XREFS from main @ 0x7f9, 0x7fd, 0x839
│           0x00000065      0000           add byte [rax], al
│           0x00000067      00f8           add al, bh
│           0x00000069      0100           add dword [rax], eax
│           0x0000006b      0000           add byte [rax], al
│           0x0000006d      0000           add byte [rax], al
│           ; DATA XREFS from main @ 0x7e1, 0x821, 0x841
│           0x0000006f      0008           add byte [rax], cl
│           0x00000071      0000           add byte [rax], al
│           ; DATA XREF from main @ 0x809
│           0x00000073      0000           add byte [rax], al
│           ; DATA XREF from main @ 0x7d9
│           0x00000075      0000           add byte [rax], al
│           0x00000077      0003           add byte [rbx], al
│           ; DATA XREF from main @ 0x7e9
│           0x00000079      0000           add byte [rax], al
│           0x0000007b      000400         add byte [rax + rax], al
│           0x0000007e      0000           add byte [rax], al
│           0x00000080      3802           cmp byte [rdx], al          ; arg3
│           0x00000082      0000           add byte [rax], al
│           0x00000084      0000           add byte [rax], al
│           0x00000086      0000           add byte [rax], al
│           0x00000088      3802           cmp byte [rdx], al          ; arg3
│           0x0000008a      0000           add byte [rax], al
│           0x0000008c      0000           add byte [rax], al
│           0x0000008e      0000           add byte [rax], al
│           0x00000090      3802           cmp byte [rdx], al          ; arg3
│           0x00000092      0000           add byte [rax], al
│           0x00000094      0000           add byte [rax], al
│           0x00000096      0000           add byte [rax], al
│           0x00000098      1c00           sbb al, 0
│           0x0000009a      0000           add byte [rax], al
│           0x0000009c      0000           add byte [rax], al
│           0x0000009e      0000           add byte [rax], al
│           0x000000a0      1c00           sbb al, 0
│           0x000000a2      0000           add byte [rax], al
│           0x000000a4      0000           add byte [rax], al
│           0x000000a6      0000           add byte [rax], al
│           0x000000a8      0100           add dword [rax], eax
│           0x000000aa      0000           add byte [rax], al
│           0x000000ac      0000           add byte [rax], al
│           0x000000ae      0000           add byte [rax], al
│           0x000000b0      0100           add dword [rax], eax
│           0x000000b2      0000           add byte [rax], al
│           0x000000b4      0500000000     add eax, 0
│           0x000000b9      0000           add byte [rax], al
│           0x000000bb      0000           add byte [rax], al
│           0x000000bd      0000           add byte [rax], al
│           0x000000bf      0000           add byte [rax], al
│           0x000000c1      0000           add byte [rax], al
│           0x000000c3      0000           add byte [rax], al
│           0x000000c5      0000           add byte [rax], al
│           0x000000c7      0000           add byte [rax], al
│           0x000000c9      0000           add byte [rax], al
│           0x000000cb      0000           add byte [rax], al
│           0x000000cd      0000           add byte [rax], al
│           0x000000cf      00780b         add byte [rax + 0xb], bh
│           0x000000d2      0000           add byte [rax], al
│           0x000000d4      0000           add byte [rax], al
│           0x000000d6      0000           add byte [rax], al
│       ┌─< 0x000000d8      780b           js 0xe5
│       │   0x000000da      0000           add byte [rax], al
│       │   0x000000dc      0000           add byte [rax], al
│       │   0x000000de      0000           add byte [rax], al
│       │   0x000000e0      0000           add byte [rax], al
│       │   0x000000e2      2000           and byte [rax], al
│       │   0x000000e4  ~   0000           add byte [rax], al
│       │   ; CODE XREF from loc.imp._ITM_deregisterTMCloneTable @ 0xd8
│       └─> 0x000000e5      0000           add byte [rax], al
│           0x000000e7      0001           add byte [rcx], al          ; arg4
│           0x000000e9      0000           add byte [rax], al
│           0x000000eb      0006           add byte [rsi], al          ; arg2
│           0x000000ed      0000           add byte [rax], al
│           0x000000ef      00a00d000000   add byte [rax + 0xd], ah
│           0x000000f5      0000           add byte [rax], al
│           0x000000f7      00a00d200000   add byte [rax + 0x200d], ah
│           0x000000fd      0000           add byte [rax], al
│           0x000000ff      00a00d200000   add byte [rax + 0x200d], ah
│           0x00000105      0000           add byte [rax], al
│           0x00000107      007002         add byte [rax + 2], dh
│           0x0000010a      0000           add byte [rax], al
│           0x0000010c      0000           add byte [rax], al
│           0x0000010e      0000           add byte [rax], al
│           0x00000110      b002           mov al, 2
│           0x00000112      0000           add byte [rax], al
│           0x00000114      0000           add byte [rax], al
│           0x00000116      0000           add byte [rax], al
│           0x00000118      0000           add byte [rax], al
│           0x0000011a      2000           and byte [rax], al
│           0x0000011c      0000           add byte [rax], al
│           0x0000011e      0000           add byte [rax], al
│           0x00000120      0200           add al, byte [rax]
└           0x00000122      0000           add byte [rax], al
            0x00000124      06             invalid
            0x00000125      0000           add byte [rax], al
            0x00000127      00b00d000000   add byte [rax + 0xd], dh
            0x0000012d      0000           add byte [rax], al
            0x0000012f      00b00d200000   add byte [rax + 0x200d], dh
            0x00000135      0000           add byte [rax], al
            0x00000137      00b00d200000   add byte [rax + 0x200d], dh
            0x0000013d      0000           add byte [rax], al
            0x0000013f      00f0           add al, dh
            0x00000141      0100           add dword [rax], eax
            0x00000143      0000           add byte [rax], al
            0x00000145      0000           add byte [rax], al
            0x00000147      00f0           add al, dh
            0x00000149      0100           add dword [rax], eax
            0x0000014b      0000           add byte [rax], al
            0x0000014d      0000           add byte [rax], al
            0x0000014f      0008           add byte [rax], cl
            0x00000151      0000           add byte [rax], al
            0x00000153      0000           add byte [rax], al
            0x00000155      0000           add byte [rax], al
            0x00000157      000400         add byte [rax + rax], al
            0x0000015a      0000           add byte [rax], al
            0x0000015c      0400           add al, 0
            0x0000015e      0000           add byte [rax], al
            0x00000160      54             push rsp
            0x00000161      0200           add al, byte [rax]
            0x00000163      0000           add byte [rax], al
            0x00000165      0000           add byte [rax], al
            0x00000167      00540200       add byte [rdx + rax], dl
            0x0000016b      0000           add byte [rax], al
            0x0000016d      0000           add byte [rax], al
            0x0000016f      00540200       add byte [rdx + rax], dl
            0x00000173      0000           add byte [rax], al
            0x00000175      0000           add byte [rax], al
            0x00000177      00440000       add byte [rax + rax], al
            0x0000017b      0000           add byte [rax], al
            0x0000017d      0000           add byte [rax], al
            0x0000017f      00440000       add byte [rax + rax], al
            0x00000183      0000           add byte [rax], al
            0x00000185      0000           add byte [rax], al
            0x00000187      000400         add byte [rax + rax], al
            0x0000018a      0000           add byte [rax], al
            0x0000018c      0000           add byte [rax], al
            0x0000018e      0000           add byte [rax], al
            0x00000190      50             push rax
            0x00000191      e574           in eax, 0x74
            0x00000193      640400         add al, 0
            0x00000196      0000           add byte [rax], al
            0x00000198      280a           sub byte [rdx], cl
            0x0000019a      0000           add byte [rax], al
            0x0000019c      0000           add byte [rax], al
            0x0000019e      0000           add byte [rax], al
            0x000001a0      280a           sub byte [rdx], cl
            0x000001a2      0000           add byte [rax], al
            0x000001a4      0000           add byte [rax], al
            0x000001a6      0000           add byte [rax], al
            0x000001a8      280a           sub byte [rdx], cl
            0x000001aa      0000           add byte [rax], al
            0x000001ac      0000           add byte [rax], al
            0x000001ae      0000           add byte [rax], al
            0x000001b0      3c00           cmp al, 0
            0x000001b2      0000           add byte [rax], al
            0x000001b4      0000           add byte [rax], al
            0x000001b6      0000           add byte [rax], al
            0x000001b8      3c00           cmp al, 0
            0x000001ba      0000           add byte [rax], al
            0x000001bc      0000           add byte [rax], al
            0x000001be      0000           add byte [rax], al
            0x000001c0      0400           add al, 0
            0x000001c2      0000           add byte [rax], al
            0x000001c4      0000           add byte [rax], al
            0x000001c6      0000           add byte [rax], al
            0x000001c8      51             push rcx
            0x000001c9      e574           in eax, 0x74
            0x000001cb      64             invalid
            0x000001cc      06             invalid
            0x000001cd      0000           add byte [rax], al
            0x000001cf      0000           add byte [rax], al
            0x000001d1      0000           add byte [rax], al
            0x000001d3      0000           add byte [rax], al
            0x000001d5      0000           add byte [rax], al
            0x000001d7      0000           add byte [rax], al
            0x000001d9      0000           add byte [rax], al
            0x000001db      0000           add byte [rax], al
            0x000001dd      0000           add byte [rax], al
            0x000001df      0000           add byte [rax], al
            0x000001e1      0000           add byte [rax], al
            0x000001e3      0000           add byte [rax], al
            0x000001e5      0000           add byte [rax], al
            0x000001e7      0000           add byte [rax], al
            0x000001e9      0000           add byte [rax], al
            0x000001eb      0000           add byte [rax], al
            0x000001ed      0000           add byte [rax], al
            0x000001ef      0000           add byte [rax], al
            0x000001f1      0000           add byte [rax], al
            0x000001f3      0000           add byte [rax], al
            0x000001f5      0000           add byte [rax], al
            0x000001f7      0010           add byte [rax], dl
            0x000001f9      0000           add byte [rax], al
            0x000001fb      0000           add byte [rax], al
            0x000001fd      0000           add byte [rax], al
            0x000001ff      0052e5         add byte [rdx - 0x1b], dl
        ┌─< 0x00000202      7464           je 0x268
        │   0x00000204      0400           add al, 0
        │   0x00000206      0000           add byte [rax], al
        │   0x00000208      a00d00000000.  movabs al, byte [0xa00000000000000d]
        │   0x00000211      0d20000000     or eax, 0x20                ; "@"
        │   0x00000216      0000           add byte [rax], al
        │   0x00000218      a00d20000000.  movabs al, byte [0x600000000000200d] ; [0x600000000000200d:1]=255
        │   0x00000221      0200           add al, byte [rax]
        │   0x00000223      0000           add byte [rax], al
        │   0x00000225      0000           add byte [rax], al
        │   0x00000227      006002         add byte [rax + 2], ah
        │   0x0000022a      0000           add byte [rax], al
        │   0x0000022c      0000           add byte [rax], al
        │   0x0000022e      0000           add byte [rax], al
        │   0x00000230      0100           add dword [rax], eax
        │   0x00000232      0000           add byte [rax], al
        │   0x00000234      0000           add byte [rax], al
        │   0x00000236      0000           add byte [rax], al
        │   ;-- section..interp:
        │   ;-- segment.INTERP:
        │   ;-- .interp:
        │   0x00000238      2f             invalid                     ; [01] -r-- section size 28 named .interp
        │   0x00000239      6c             insb byte [rdi], dx
        │   0x0000023a      696236342f6c.  imul esp, dword [rdx + 0x36], 0x646c2f34
        │   0x00000241      2d6c696e75     sub eax, 0x756e696c
       ┌──< 0x00000246      782d           js 0x275
      ┌───< 0x00000248      7838           js 0x282
      │││   0x0000024a      362d36342e73   sub eax, 0x732e3436
      │││   0x00000250      6f             outsd dx, dword [rsi]
      │││   0x00000251      2e3200         xor al, byte cs:[rax]
      │││   ;-- section..note.ABI_tag:
      │││   ;-- segment.NOTE:
      │││   ;-- .note.ABI-tag:
      │││   0x00000254      0400           add al, 0                   ; [02] -r-- section size 32 named .note.ABI_tag
      │││   0x00000256      0000           add byte [rax], al
      │││   0x00000258      1000           adc byte [rax], al
      │││   0x0000025a      0000           add byte [rax], al
      │││   0x0000025c      0100           add dword [rax], eax
      │││   0x0000025e      0000           add byte [rax], al
      │││   0x00000260      474e55         push rbp
      │││   0x00000263      0000           add byte [rax], al
      │││   0x00000265      0000           add byte [rax], al
      │││   0x00000267      0003           add byte [rbx], al
      ││    0x00000269      0000           add byte [rax], al
      ││    0x0000026b      0002           add byte [rdx], al
      ││    0x0000026d      0000           add byte [rax], al
      ││    0x0000026f      0000           add byte [rax], al
      ││    0x00000271      0000           add byte [rax], al
      ││    0x00000273  ~   000400         add byte [rax + rax], al
      ││    ;-- section..note.gnu.build_id:
      ││    ;-- .note.gnu.build-id:
      ││    0x00000274      0400           add al, 0                   ; [03] -r-- section size 36 named .note.gnu.build_id
      │     0x00000276      0000           add byte [rax], al
      │     0x00000278      1400           adc al, 0
      │     0x0000027a      0000           add byte [rax], al
      │     0x0000027c      0300           add eax, dword [rax]
      │     0x0000027e      0000           add byte [rax], al
      │     0x00000280      474e55         push rbp
            0x00000283      00b3ebffa152   add byte [rbx + 0x52a1ffeb], dh
            0x00000289      a0ae96532f7f.  movabs al, byte [0x67a5317f2f5396ae] ; [0x67a5317f2f5396ae:1]=255
            0x00000292      1462           adc al, 0x62
            0x00000294      341f           xor al, 0x1f
            0x00000296      60             invalid
            0x00000297  ~   0502000000     add eax, 2
            ;-- section..gnu.hash:
            ;-- .gnu.hash:
            0x00000298      0200           add al, byte [rax]          ; [04] -r-- section size 40 named .gnu.hash
            0x0000029a      0000           add byte [rax], al
            0x0000029c      0a00           or al, byte [rax]
            0x0000029e      0000           add byte [rax], al
            0x000002a0      0100           add dword [rax], eax
            0x000002a2      0000           add byte [rax], al
            0x000002a4      06             invalid
            0x000002a5      0000           add byte [rax], al
            0x000002a7      0000           add byte [rax], al
            0x000002a9      0100           add dword [rax], eax
            0x000002ab      0000           add byte [rax], al
            0x000002ad      0110           add dword [rax], edx
            0x000002af      020a           add cl, byte [rdx]
            0x000002b1      0000           add byte [rax], al
            0x000002b3      000b           add byte [rbx], cl
            0x000002b5      0000           add byte [rax], al
            0x000002b7      0029           add byte [rcx], ch
            0x000002b9      1d8c1c39f2     sbb eax, 0xf2391c8c
            0x000002be  ~   8b1c00         mov ebx, dword [rax + rax]
            ;-- section..dynsym:
            ;-- .dynsym:
            0x000002c0      0000           add byte [rax], al          ; [05] -r-- section size 288 named .dynsym
            0x000002c2      0000           add byte [rax], al
            0x000002c4      0000           add byte [rax], al
            0x000002c6      0000           add byte [rax], al
            0x000002c8      0000           add byte [rax], al
            0x000002ca      0000           add byte [rax], al
            0x000002cc      0000           add byte [rax], al
            0x000002ce      0000           add byte [rax], al
            0x000002d0      0000           add byte [rax], al
            0x000002d2      0000           add byte [rax], al
            0x000002d4      0000           add byte [rax], al
            0x000002d6      0000           add byte [rax], al
            0x000002d8      7700           ja 0x2da
            0x000002da      0000           add byte [rax], al
            0x000002dc      2000           and byte [rax], al
            0x000002de      0000           add byte [rax], al
            0x000002e0      0000           add byte [rax], al
            0x000002e2      0000           add byte [rax], al
            0x000002e4      0000           add byte [rax], al
            0x000002e6      0000           add byte [rax], al
            0x000002e8      0000           add byte [rax], al
            0x000002ea      0000           add byte [rax], al
            0x000002ec      0000           add byte [rax], al
            0x000002ee      0000           add byte [rax], al
            0x000002f0      2300           and eax, dword [rax]
            0x000002f2      0000           add byte [rax], al
            0x000002f4      1200           adc al, byte [rax]
            0x000002f6      0000           add byte [rax], al
            0x000002f8      0000           add byte [rax], al
            0x000002fa      0000           add byte [rax], al
            0x000002fc      0000           add byte [rax], al
            0x000002fe      0000           add byte [rax], al
            0x00000300      0000           add byte [rax], al
            0x00000302      0000           add byte [rax], al
            0x00000304      0000           add byte [rax], al
            0x00000306      0000           add byte [rax], al
            0x00000308      1200           adc al, byte [rax]
            ; DATA XREF from entry0 @ 0x6bf
            0x0000030a      0000           add byte [rax], al
            0x0000030c      1200           adc al, byte [rax]
            0x0000030e      0000           add byte [rax], al
            0x00000310      0000           add byte [rax], al
            0x00000312      0000           add byte [rax], al
            0x00000314      0000           add byte [rax], al
            0x00000316      0000           add byte [rax], al
            0x00000318      0000           add byte [rax], al
            0x0000031a      0000           add byte [rax], al
            0x0000031c      0000           add byte [rax], al
            0x0000031e      0000           add byte [rax], al
            0x00000320      4f0000         add byte [r8], r8b
            0x00000323      0012           add byte [rdx], dl
            0x00000325      0000           add byte [rax], al
            0x00000327      0000           add byte [rax], al
            0x00000329      0000           add byte [rax], al
            0x0000032b      0000           add byte [rax], al
            0x0000032d      0000           add byte [rax], al
            0x0000032f      0000           add byte [rax], al
            0x00000331      0000           add byte [rax], al
            0x00000333      0000           add byte [rax], al
            0x00000335      0000           add byte [rax], al
            0x00000337      0038           add byte [rax], bh
            0x00000339      0000           add byte [rax], al
            0x0000033b      0012           add byte [rdx], dl
            0x0000033d      0000           add byte [rax], al
            0x0000033f      0000           add byte [rax], al
            0x00000341      0000           add byte [rax], al
            0x00000343      0000           add byte [rax], al
            0x00000345      0000           add byte [rax], al
            0x00000347      0000           add byte [rax], al
            0x00000349      0000           add byte [rax], al
            0x0000034b      0000           add byte [rax], al
            0x0000034d      0000           add byte [rax], al
            0x0000034f      009300000020   add byte [rbx + 0x20000000], dl
            0x00000355      0000           add byte [rax], al
            0x00000357      0000           add byte [rax], al
            0x00000359      0000           add byte [rax], al
            0x0000035b      0000           add byte [rax], al
            0x0000035d      0000           add byte [rax], al
            0x0000035f      0000           add byte [rax], al
            0x00000361      0000           add byte [rax], al
            0x00000363      0000           add byte [rax], al
            0x00000365      0000           add byte [rax], al
            0x00000367      000b           add byte [rbx], cl
            0x00000369      0000           add byte [rax], al
            0x0000036b      0012           add byte [rdx], dl
            0x0000036d      0000           add byte [rax], al
            0x0000036f      0000           add byte [rax], al
            0x00000371      0000           add byte [rax], al
            0x00000373      0000           add byte [rax], al
            0x00000375      0000           add byte [rax], al
            0x00000377      0000           add byte [rax], al
            0x00000379      0000           add byte [rax], al
            0x0000037b      0000           add byte [rax], al
            0x0000037d      0000           add byte [rax], al
            0x0000037f      00a200000020   add byte [rdx + 0x20000000], ah
            0x00000385      0000           add byte [rax], al
            0x00000387      0000           add byte [rax], al
            0x00000389      0000           add byte [rax], al
            0x0000038b      0000           add byte [rax], al
            0x0000038d      0000           add byte [rax], al
            0x0000038f      0000           add byte [rax], al
            0x00000391      0000           add byte [rax], al
            0x00000393      0000           add byte [rax], al
            0x00000395      0000           add byte [rax], al
            0x00000397      004000         add byte [rax], al
            0x0000039a      0000           add byte [rax], al
            0x0000039c      2200           and al, byte [rax]
            0x0000039e      0000           add byte [rax], al
            0x000003a0      0000           add byte [rax], al
            0x000003a2      0000           add byte [rax], al
            0x000003a4      0000           add byte [rax], al
            0x000003a6      0000           add byte [rax], al
            0x000003a8      0000           add byte [rax], al
            0x000003aa      0000           add byte [rax], al
            0x000003ac      0000           add byte [rax], al
            0x000003ae      0000           add byte [rax], al
            0x000003b0      2a00           sub al, byte [rax]
            0x000003b2      0000           add byte [rax], al
            0x000003b4      1100           adc dword [rax], eax
            0x000003b6      1800           sbb byte [rax], al
            0x000003b8      2010           and byte [rax], dl
            0x000003ba      2000           and byte [rax], al
            0x000003bc      0000           add byte [rax], al
            0x000003be      0000           add byte [rax], al
            0x000003c0      0800           or byte [rax], al
            0x000003c2      0000           add byte [rax], al
            0x000003c4      0000           add byte [rax], al
            0x000003c6      0000           add byte [rax], al
            0x000003c8      3100           xor dword [rax], eax
            0x000003ca      0000           add byte [rax], al
            0x000003cc      1100           adc dword [rax], eax
            0x000003ce      1800           sbb byte [rax], al
            0x000003d0      401020         adc byte [rax], spl
            0x000003d3      0000           add byte [rax], al
            0x000003d5      0000           add byte [rax], al
            0x000003d7      0008           add byte [rax], cl
            0x000003d9      0000           add byte [rax], al
            0x000003db      0000           add byte [rax], al
            0x000003dd      0000           add byte [rax], al
            0x000003df  ~   0000           add byte [rax], al
            ;-- section..dynstr:
            ;-- .dynstr:
            0x000003e0      006c6962       add byte [rcx + rbp*2 + 0x62], ch ; [06] -r-- section size 188 named .dynstr
            0x000003e4      632e           movsxd rbp, dword [rsi]
            0x000003e6      736f           jae 0x457
            0x000003e8      2e36006666     add byte ss:[rsi + 0x66], ah
            0x000003ed      6c             insb byte [rdi], dx
        ┌─< 0x000003ee      7573           jne 0x463
        │   0x000003f0      68005f5f73     push 0x735f5f00
       ┌──< 0x000003f5      7461           je 0x458
       ││   0x000003f7      636b5f         movsxd rbp, dword [rbx + 0x5f]
       ││   0x000003fa      63686b         movsxd rbp, dword [rax + 0x6b]
       ││   0x000003fd      5f             pop rdi
       ││   0x000003fe      66             invalid
       ││   0x000003ff      61             invalid
       ││   0x00000400      696c00737472.  imul ebp, dword [rax + rax + 0x73], 0x656c7274
       ││   0x00000408      6e             outsb dx, byte [rsi]
       ││   0x00000409      007374         add byte [rbx + 0x74], dh
       ││   0x0000040c      646f           outsd dx, dword fs:[rsi]
      ┌───< 0x0000040e      7574           jne 0x484
      │││   0x00000410      007374         add byte [rbx + 0x74], dh
     ┌────< 0x00000413      64657272       jb 0x489
     ││││   0x00000417      006670         add byte [rsi + 0x70], ah
    ┌─────< 0x0000041a      7269           jb 0x485
    │││││   0x0000041c      6e             outsb dx, byte [rsi]
   ┌──────< 0x0000041d      7466           je 0x485
   ││││││   0x0000041f      005f5f         add byte [rdi + 0x5f], bl
   ││││││   0x00000422      637861         movsxd rdi, dword [rax + 0x61]
   ││││││   0x00000425      5f             pop rdi
   ││││││   0x00000426      66696e616c69   imul bp, word [rsi + 0x61], 0x696c
  ┌───────< 0x0000042c      7a65           jp 0x493
  │││││││   0x0000042e      005f5f         add byte [rdi + 0x5f], bl
  │││││││   0x00000431      6c             insb byte [rdi], dx
  │││││││   0x00000432      6962635f7374.  imul esp, dword [rdx + 0x63], 0x6174735f
  ────────< 0x00000439      7274           jb 0x4af
  │││││││   0x0000043b      5f             pop rdi
  │││││││   0x0000043c      6d             insd dword [rdi], dx
  │││││││   0x0000043d      61             invalid
  │││││││   0x0000043e      696e00474c49.  imul ebp, dword [rsi], 0x42494c47
  │││││││   0x00000445      435f           pop r15
  │││││││   0x00000447      322e           xor ch, byte [rsi]
  │││││││   0x00000449      3400           xor al, 0
  │││││││   0x0000044b      474c4942435f   pop r15
  │││││││   0x00000451      322e           xor ch, byte [rsi]
  │││││││   0x00000453      322e           xor ch, byte [rsi]
  │││││││   0x00000455      35005f4954     xor eax, 0x54495f00
  │││││ │   0x0000045a      4d5f           pop r15
  │││││┌──< 0x0000045c      64657265       jb 0x4c5
  │││││││   0x00000460      676973746572.  imul esi, dword [ebx + 0x74], 0x4d547265
  ││││││    0x00000468      436c           insb byte [rdi], dx
  ││││││    0x0000046a      6f             outsd dx, dword [rsi]
  ││││││    0x0000046b      6e             outsb dx, byte [rsi]
  ││││││    0x0000046c      6554           push rsp
  ││││││    0x0000046e      61             invalid
  ││││││    0x0000046f      62             invalid
  ││││││    0x00000470      6c             insb byte [rdi], dx
  ││││││    0x00000471      65005f5f       add byte gs:[rdi + 0x5f], bl
  ││││││    0x00000475      676d           insd dword [edi], dx
  ││││││    0x00000477      6f             outsd dx, dword [rsi]
  ││││││    0x00000478      6e             outsb dx, byte [rsi]
  ││││││    0x00000479      5f             pop rdi
  ││││││┌─< 0x0000047a      7374           jae 0x4f0
  │││││││   0x0000047c      61             invalid
  ────────< 0x0000047d      7274           jb 0x4f3
  │││││││   0x0000047f      5f             pop rdi
  │││││││   0x00000480      5f             pop rdi
  │││││││   0x00000481      005f49         add byte [rdi + 0x49], bl
  │││││││   ; CODE XREF from unk @ 
  ││││└───> 0x00000484      54             push rsp
  ││││ ││   ; CODE XREF from unk @ 
  ││││ ││   ; CODE XREF from unk @ 
  │└└─────> 0x00000485      4d5f           pop r15
  │  │┌───< 0x00000487      7265           jb 0x4ee
  │  ││││   ; CODE XREF from unk @ 
  │  └────> 0x00000489      676973746572.  imul esi, dword [ebx + 0x74], 0x4d547265
  │   │││   0x00000491      436c           insb byte [rdi], dx
  │   │││   ; CODE XREF from unk @ 
  └───────> 0x00000493      6f             outsd dx, dword [rsi]
      │││   0x00000494      6e             outsb dx, byte [rsi]
      │││   0x00000495      6554           push rsp
      │││   0x00000497      61             invalid
      │││   0x00000498      62             invalid
      │││   0x00000499      6c             insb byte [rdi], dx
      │││   0x0000049a  ~   650000         add byte gs:[rax], al
      │││   ;-- section..gnu.version:
      │││   ;-- .gnu.version:
      │││   0x0000049c      0000           add byte [rax], al          ; [07] -r-- section size 24 named .gnu.version
      │││   0x0000049e      0000           add byte [rax], al
      │││   0x000004a0      0200           add al, byte [rax]
      │││   0x000004a2      0300           add eax, dword [rax]
      │││   0x000004a4      0200           add al, byte [rax]
      │││   0x000004a6      0200           add al, byte [rax]
      │││   0x000004a8      0000           add byte [rax], al
      │││   0x000004aa      0200           add al, byte [rax]
      │││   0x000004ac      0000           add byte [rax], al
      │││   0x000004ae      0200           add al, byte [rax]
      │││   0x000004b0      0200           add al, byte [rax]
      │││   0x000004b2      0200           add al, byte [rax]
      │││   0x000004b4      0000           add byte [rax], al
      │││   0x000004b6      0000           add byte [rax], al
      │││   ;-- section..gnu.version_r:
      │││   ;-- .gnu.version_r:
      │││   0x000004b8      0100           add dword [rax], eax        ; [08] -r-- section size 48 named .gnu.version_r
      │││   0x000004ba      0200           add al, byte [rax]
      │││   0x000004bc      0100           add dword [rax], eax
      │││   0x000004be      0000           add byte [rax], al
      │││   0x000004c0      1000           adc byte [rax], al
      │││   0x000004c2      0000           add byte [rax], al
      │││   0x000004c4      0000           add byte [rax], al
      │ │   0x000004c6      0000           add byte [rax], al
      │ │   0x000004c8      1469           adc al, 0x69
      │ │   0x000004ca      690d00000300.  imul ecx, dword [0x000304d4], 0x61
      │ │   0x000004d4      1000           adc byte [rax], al
      │ │   0x000004d6      0000           add byte [rax], al
      │┌──< 0x000004d8      751a           jne 0x4f4
      │││   0x000004da      690900000200   imul ecx, dword [rcx], 0x20000
      │││   0x000004e0      6b0000         imul eax, dword [rax], 0
      │││   0x000004e3      0000           add byte [rax], al
      │││   0x000004e5      0000           add byte [rax], al
      │││   0x000004e7  ~   00a00d200000   add byte [rax + 0x200d], ah
      │││   ;-- section..rela.dyn:
      │││   ;-- .rela.dyn:
      │││   0x000004e8      .qword 0x0000000000200da0 ; section..init_array ; segment.LOAD1 ; segment.GNU_RELRO ; sym..init_array ; obj.__frame_dummy_init_array_entry ; loc.__init_array_start ; [09] -r-- section size 240 named .rela.dyn
       ││   ; CODE XREF from unk @ 
       │└─> 0x000004f0      .qword 0x0000000000000008
            0x000004f8      .qword 0x00000000000007b0 ; entry.init0 ; sym.frame_dummy
            0x00000500      .qword 0x0000000000200da8 ; section..fini_array ; sym..fini_array ; obj.__do_global_dtors_aux_fini_array_entry ; loc.__init_array_end
            0x00000508      .qword 0x0000000000000008
            0x00000510      .qword 0x0000000000000770 ; entry.fini0 ; sym.__do_global_dtors_aux
            0x00000518      .qword 0x0000000000201008 ; obj.__dso_handle
            0x00000520      .qword 0x0000000000000008
            0x00000528      .qword 0x0000000000201008 ; obj.__dso_handle
            0x00000530      .qword 0x0000000000200fd8 ; reloc._ITM_deregisterTMCloneTable
            0x00000538      .qword 0x0000000100000006
            0x00000540      .qword 0x0000000000000000
            0x00000548      .qword 0x0000000000200fe0 ; reloc.__libc_start_main
            0x00000550      .qword 0x0000000400000006
            0x00000558      .qword 0x0000000000000000
            0x00000560      .qword 0x0000000000200fe8 ; reloc.__gmon_start
            0x00000568      .qword 0x0000000600000006
            0x00000570      .qword 0x0000000000000000
            0x00000578      .qword 0x0000000000200ff0 ; reloc._ITM_registerTMCloneTable
            0x00000580      .qword 0x0000000800000006
            0x00000588      .qword 0x0000000000000000
            0x00000590      .qword 0x0000000000200ff8 ; reloc.__cxa_finalize
            0x00000598      .qword 0x0000000900000006
            0x000005a0      .qword 0x0000000000000000
            0x000005a8      .qword 0x0000000000201020 ; section..bss ; reloc.stdout ; obj.stdout ; sym..bss ; obj.stdout__GLIBC_2.2.5
            0x000005b0      .qword 0x0000000a00000005
            0x000005b8      .qword 0x0000000000000000
            0x000005c0      .qword 0x0000000000201040 ; reloc.stderr ; obj.stderr ; obj.stderr__GLIBC_2.2.5
            0x000005c8      .qword 0x0000000b00000005
            0x000005d0      .qword 0x0000000000000000
            ;-- section..rela.plt:
            ;-- .rela.plt:
            0x000005d8      .qword 0x0000000000200fb8 ; reloc.strlen   ; [10] -r-- section size 96 named .rela.plt
            0x000005e0      .qword 0x0000000200000007
            0x000005e8      .qword 0x0000000000000000
            0x000005f0      .qword 0x0000000000200fc0 ; reloc.__stack_chk_fail
            0x000005f8      .qword 0x0000000300000007
            0x00000600      .qword 0x0000000000000000
            0x00000608      .qword 0x0000000000200fc8 ; reloc.fprintf
            0x00000610      .qword 0x0000000500000007
            ; DATA XREF from unk @ 
            0x00000618      .qword 0x0000000000000000
            0x00000620      .qword 0x0000000000200fd0 ; reloc.fflush
            0x00000628      .qword 0x0000000700000007
            0x00000630      .qword 0x0000000000000000
            ; CALL XREF from sym.__libc_csu_init @ 0x98c
            ;-- section..init:
            ;-- .init:
┌ 23: sym._init ();
│           0x00000638      4883ec08       sub rsp, 8                  ; [11] -r-x section size 23 named .init
│           0x0000063c      488b05a50920.  mov rax, qword [reloc.__gmon_start] ; [0x200fe8:8]=0
│           0x00000643      4885c0         test rax, rax
│           0x00000646      7402           je 0x64a
│           0x00000648      ffd0           call rax
│           ; CODE XREF from sym._init @ 0x646
│           0x0000064a      4883c408       add rsp, 8
└           0x0000064e      c3             ret
            0x0000064f  ~   00ff           add bh, bh
            ; CODE XREF from unk @ 
            ; CODE XREF from unk @ 
            ; CODE XREF from unk @ 
            ; CODE XREF from unk @ 
            ;-- section..plt:
            ;-- .plt:
            0x00000650      ff3552092000   push qword [0x00200fa8]     ; [12] -r-x section size 80 named .plt
            0x00000656      ff2554092000   jmp qword [0x00200fb0]      ; [0x200fb0:8]=0
            0x0000065c      0f1f4000       nop dword [rax]
        │   ; CALL XREFS from main @ 0x893, 0x935
┌ 6: size_t sym.imp.strlen (const char *s);
└       │   0x00000660      ff2552092000   jmp qword [reloc.strlen]    ; [0x200fb8:8]=0x666 ; "f\x06"
            0x00000666      6800000000     push 0
     ╎╎╎╎   0x0000066b      e9e0ffffff     jmp sym..plt
     ╎╎╎╎   ; CALL XREF from main @ 0x951
┌ 6: void sym.imp.__stack_chk_fail ();
└    ╎╎╎╎   0x00000670      ff254a092000   jmp qword [reloc.__stack_chk_fail] ; [0x200fc0:8]=0x676 ; "v\x06"
     ╎╎╎╎   0x00000676      6801000000     push 1
     ╎╎╎╎   0x0000067b      e9d0ffffff     jmp sym..plt
     ╎╎╎╎   ; CALL XREFS from main @ 0x8b7, 0x8fb
┌ 6: int sym.imp.fprintf (FILE *stream, const char *format,   ...);
└    ╎╎╎╎   0x00000680      ff2542092000   jmp qword [reloc.fprintf]   ; [0x200fc8:8]=0x686
      ╎╎╎   0x00000686      6802000000     push 2
      ╎╎╎   0x0000068b      e9c0ffffff     jmp sym..plt
      ╎╎╎   ; CALL XREFS from main @ 0x8c6, 0x90a
┌ 6: int sym.imp.fflush (FILE *stream);
└     ╎╎╎   0x00000690      ff253a092000   jmp qword [reloc.fflush]    ; [0x200fd0:8]=0x696
       ╎╎   0x00000696      6803000000     push 3
       ╎╎   0x0000069b      e9b0ffffff     jmp sym..plt
       ╎╎   ; CALL XREF from entry.fini0 @ 0x78e
       ╎╎   ;-- section..plt.got:
       ╎╎   ;-- .plt.got:
       ╎╎   0x000006a0      .qword 0x90660020095225ff                  ; [13] -r-x section size 8 named .plt.got
        ╎   0x000006a8      0000           add byte [rax], al
        ╎   0x000006aa      0000           add byte [rax], al
        ╎   0x000006ac      0000           add byte [rax], al
        ╎   0x000006ae      0000           add byte [rax], al
        ╎   ;-- section..text:
        ╎   ;-- .text:
        ╎   ;-- _start:
        ╎   ;-- rip:
┌ 42: entry0 (int64_t arg3);
│       ╎   ; arg int64_t arg3 @ rdx
│       ╎   0x000006b0      31ed           xor ebp, ebp                ; [14] -r-x section size 802 named .text
│       ╎   0x000006b2      4989d1         mov r9, rdx                 ; arg3
│           0x000006b5      5e             pop rsi
│           0x000006b6      4889e2         mov rdx, rsp
│           0x000006b9      4883e4f0       and rsp, 0xfffffffffffffff0
│           0x000006bd      50             push rax
│           0x000006be      54             push rsp
│           0x000006bf      4c8d050a0300.  lea r8, [sym.__libc_csu_fini] ; 0x9d0
│           0x000006c6      488d0d930200.  lea rcx, [sym.__libc_csu_init] ; 0x960 ; "AWAVI\x89\xd7AUATL\x8d%.\x04 "
│           0x000006cd      488d3de60000.  lea rdi, [main]             ; 0x7ba
└           0x000006d4      ff1506092000   call qword [reloc.__libc_start_main] ; [0x200fe0:8]=0
            0x000006da      f4             hlt
            0x000006db      0f1f440000     nop dword [rax + rax]
            ; CALL XREF from entry.fini0 @ 0x793
┌ 40: sym.deregister_tm_clones ();
│           0x000006e0      488d3d290920.  lea rdi, loc._edata         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x000006e7      55             push rbp
│           0x000006e8      488d05210920.  lea rax, loc._edata         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x000006ef      4839f8         cmp rax, rdi
│           0x000006f2      4889e5         mov rbp, rsp
│           0x000006f5      7419           je 0x710
│           0x000006f7      488b05da0820.  mov rax, qword [reloc._ITM_deregisterTMCloneTable] ; [0x200fd8:8]=0
│           0x000006fe      4885c0         test rax, rax
│           0x00000701      740d           je 0x710
│           0x00000703      5d             pop rbp
│           0x00000704      ffe0           jmp rax
            0x00000706      662e0f1f8400.  nop word cs:[rax + rax]
│       │   ; CODE XREFS from sym.deregister_tm_clones @ 0x6f5, 0x701
│       │   0x00000710      5d             pop rbp
└       │   0x00000711      c3             ret
        │   0x00000712      0f1f4000       nop dword [rax]
        │   0x00000716      662e0f1f8400.  nop word cs:[rax + rax]
       ││   ; CODE XREF from entry.init0 @ 0x7b5
┌ 57: sym.register_tm_clones ();
│      ││   0x00000720      488d3de90820.  lea rdi, loc._edata         ; obj.__TMC_END
│      ││                                                              ; 0x201010
│      ││   0x00000727      488d35e20820.  lea rsi, loc._edata         ; obj.__TMC_END
│      ││                                                              ; 0x201010
│           0x0000072e      55             push rbp
│           0x0000072f      4829fe         sub rsi, rdi
│           0x00000732      4889e5         mov rbp, rsp
│           0x00000735      48c1fe03       sar rsi, 3
│       ╎   0x00000739      4889f0         mov rax, rsi
│       ╎   0x0000073c      48c1e83f       shr rax, 0x3f
│       ╎   0x00000740      4801c6         add rsi, rax
│       ╎   0x00000743      48d1fe         sar rsi, 1
│       ╎   0x00000746      7418           je 0x760
│       ╎   0x00000748      488b05a10820.  mov rax, qword [reloc._ITM_registerTMCloneTable] ; [0x200ff0:8]=0
│       ╎   0x0000074f      4885c0         test rax, rax
│       ╎   0x00000752      740c           je 0x760
│       ╎   0x00000754      5d             pop rbp
│       ╎   0x00000755      ffe0           jmp rax
        ╎   0x00000757      660f1f840000.  nop word [rax + rax]
│      │╎   ; CODE XREFS from sym.register_tm_clones @ 0x746, 0x752
│      │╎   0x00000760      5d             pop rbp
└      │╎   0x00000761      c3             ret
       │╎   0x00000762      0f1f4000       nop dword [rax]
       │╎   0x00000766      662e0f1f8400.  nop word cs:[rax + rax]
      ││╎   ;-- __do_global_dtors_aux:
┌ 51: entry.fini0 ();
│     ││╎   0x00000770      803dd1082000.  cmp byte [obj.completed.7698], 0 ; [0x201048:1]=0
│     ││╎   0x00000777      752f           jne 0x7a8
│       ╎   0x00000779      48833d770820.  cmp qword [reloc.__cxa_finalize], 0 ; [0x200ff8:8]=0
│       ╎   0x00000781      55             push rbp
│       ╎   0x00000782      4889e5         mov rbp, rsp
│       ╎   0x00000785      740c           je 0x793
│       ╎   0x00000787      488b3d7a0820.  mov rdi, qword [obj.__dso_handle] ; [0x201008:8]=0x201008 obj.__dso_handle
│       ╎   0x0000078e      e80dffffff     call sym..plt.got
│      │╎   ; CODE XREF from entry.fini0 @ 0x785
│      │╎   0x00000793      e848ffffff     call sym.deregister_tm_clones
│      │╎   0x00000798      c605a9082000.  mov byte [obj.completed.7698], 1 ; [0x201048:1]=0
│     ││╎   0x0000079f      5d             pop rbp
│     ││╎   0x000007a0      c3             ret
      ││╎   0x000007a1      0f1f80000000.  nop dword [rax]
│     ││╎   ; CODE XREF from entry.fini0 @ 0x777
└     ││╎   0x000007a8      f3c3           ret
      ││╎   0x000007aa      660f1f440000   nop word [rax + rax]
       │╎   ;-- frame_dummy:
┌ 10: entry.init0 ();
│      │╎   0x000007b0      55             push rbp
│      │╎   0x000007b1      4889e5         mov rbp, rsp
│      │╎   0x000007b4      5d             pop rbp
└      │╎   0x000007b5      e966ffffff     jmp sym.register_tm_clones
       │╎   ; DATA XREF from entry0 @ 0x6cd
┌ 419: int main (int argc, char **argv, char **envp);
│      │╎   ; var int64_t var_6ch @ rbp-0x6c
│      │╎   ; var uint32_t var_68h @ rbp-0x68
│      │╎   ; var int64_t var_64h @ rbp-0x64
│      │╎   ; var int64_t var_60h @ rbp-0x60
│      │╎   ; var char *format @ rbp-0x52
│      │╎   ; var int64_t var_51h @ rbp-0x51
│      │╎   ; var char *s @ rbp-0x50
│      │╎   ; var int64_t var_4fh @ rbp-0x4f
│      │╎   ; var int64_t var_4eh @ rbp-0x4e
│      │╎   ; var int64_t var_4dh @ rbp-0x4d
│      │╎   ; var int64_t var_4ch @ rbp-0x4c
│      │╎   ; var int64_t var_4bh @ rbp-0x4b
│      │╎   ; var int64_t var_4ah @ rbp-0x4a
│      │╎   ; var int64_t var_49h @ rbp-0x49
│      │╎   ; var int64_t var_48h @ rbp-0x48
│      │╎   ; var int64_t var_47h @ rbp-0x47
│      │╎   ; var int64_t var_46h @ rbp-0x46
│      │╎   ; var int64_t var_45h @ rbp-0x45
│      │╎   ; var int64_t var_44h @ rbp-0x44
│      │╎   ; var int64_t var_43h @ rbp-0x43
│      │╎   ; var int64_t var_42h @ rbp-0x42
│      │╎   ; var int64_t var_41h @ rbp-0x41
│      │╎   ; var int64_t var_40h @ rbp-0x40
│      │╎   ; var int64_t var_3fh @ rbp-0x3f
│      │╎   ; var int64_t var_3eh @ rbp-0x3e
│      │╎   ; var int64_t var_3dh @ rbp-0x3d
│      │╎   ; var int64_t var_3ch @ rbp-0x3c
│      │╎   ; var int64_t var_3bh @ rbp-0x3b
│      │╎   ; var int64_t var_3ah @ rbp-0x3a
│      │╎   ; var int64_t var_39h @ rbp-0x39
│      │╎   ; var int64_t var_38h @ rbp-0x38
│      │╎   ; var int64_t var_37h @ rbp-0x37
│      │╎   ; var int64_t var_36h @ rbp-0x36
│      │╎   ; var int64_t var_35h @ rbp-0x35
│      │╎   ; var int64_t var_34h @ rbp-0x34
│      │╎   ; var int64_t canary @ rbp-0x18
│      │╎   0x000007ba      55             push rbp
│      │╎   0x000007bb      4889e5         mov rbp, rsp
│      │╎   0x000007be      53             push rbx
│      │╎   0x000007bf      4883ec68       sub rsp, 0x68
│       ╎   0x000007c3      64488b042528.  mov rax, qword fs:[0x28]
│       ╎   0x000007cc      488945e8       mov qword [canary], rax
│           0x000007d0      31c0           xor eax, eax
│           0x000007d2      c7459c000000.  mov dword [var_64h], 0
│           0x000007d9      c645b975       mov byte [var_47h], 0x75    ; 'u'
│           0x000007dd      c645bb68       mov byte [var_45h], 0x68    ; 'h'
│           0x000007e1      c645b46f       mov byte [var_4ch], 0x6f    ; 'o'
│           0x000007e5      c645b26c       mov byte [var_4eh], 0x6c    ; 'l'
│           0x000007e9      c645b779       mov byte [var_49h], 0x79    ; 'y'
│           0x000007ed      c645bd76       mov byte [var_43h], 0x76    ; 'v'
│           0x000007f1      c645bc61       mov byte [var_44h], 0x61    ; 'a'
│           0x000007f5      c645c26c       mov byte [var_3eh], 0x6c    ; 'l'
│           0x000007f9      c645b165       mov byte [var_4fh], 0x65    ; 'e'
│           0x000007fd      c645c465       mov byte [var_3ch], 0x65    ; 'e'
│           0x00000801      c645c376       mov byte [var_3dh], 0x76    ; 'v'
│           0x00000805      c645c774       mov byte [var_39h], 0x74    ; 't'
│           0x00000809      c645c073       mov byte [var_40h], 0x73    ; 's'
│           0x0000080d      c645bf20       mov byte [var_41h], 0x20    ; "@"
│           0x00000811      c645b52c       mov byte [var_4bh], 0x2c    ; ','
│           0x00000815      c645c868       mov byte [var_38h], 0x68    ; 'h'
│           0x00000819      c645c961       mov byte [var_37h], 0x61    ; 'a'
│           0x0000081d      c645ba20       mov byte [var_46h], 0x20    ; "@"
│           0x00000821      c645b86f       mov byte [var_48h], 0x6f    ; 'o'
│           0x00000825      c645b620       mov byte [var_4ah], 0x20    ; "@"
│           0x00000829      c645b36c       mov byte [var_4dh], 0x6c    ; 'l'
│           0x0000082d      c645cb21       mov byte [var_35h], 0x21    ; '!'
│           0x00000831      c645c620       mov byte [var_3ah], 0x20    ; "@"
│           0x00000835      c645ca74       mov byte [var_36h], 0x74    ; 't'
│           0x00000839      c645be65       mov byte [var_42h], 0x65    ; 'e'
│           0x0000083d      c645c564       mov byte [var_3bh], 0x64    ; 'd'
│           0x00000841      c645c16f       mov byte [var_3fh], 0x6f    ; 'o'
│           0x00000845      c645b048       mov byte [s], 0x48          ; 'H'
│           0x00000849      c645cc00       mov byte [var_34h], 0
│           0x0000084d      48c745a00000.  mov qword [var_60h], 0
│           0x00000855      c74594000000.  mov dword [var_6ch], 0
│           0x0000085c      eb28           jmp 0x886
│           ; CODE XREF from main @ 0x89b
│           0x0000085e      8b4594         mov eax, dword [var_6ch]
│           0x00000861      4898           cdqe
│           0x00000863      0fb64405b0     movzx eax, byte [rbp + rax - 0x50]
│           0x00000868      0fbec0         movsx eax, al
│           0x0000086b      89c1           mov ecx, eax
│           0x0000086d      488b55a0       mov rdx, qword [var_60h]
│           0x00000871      4889d0         mov rax, rdx
│       ┌─< 0x00000874      48c1e005       shl rax, 5
│      ╎│   0x00000878      4829d0         sub rax, rdx
│      ╎│   0x0000087b      4801c8         add rax, rcx
│      ╎│   0x0000087e      488945a0       mov qword [var_60h], rax
│      ╎│   0x00000882      83459401       add dword [var_6ch], 1
│      ╎│   ; CODE XREF from main @ 0x85c
│      ╎│   0x00000886      8b4594         mov eax, dword [var_6ch]
│      ╎│   0x00000889      4863d8         movsxd rbx, eax
│      ╎│   0x0000088c      488d45b0       lea rax, [s]
│      ╎│   0x00000890      4889c7         mov rdi, rax                ; const char *s
│      ╎│   0x00000893      e8c8fdffff     call sym.imp.strlen         ; size_t strlen(const char *s)
│      ╎│   0x00000898      4839c3         cmp rbx, rax
│      ╎│   0x0000089b      72c1           jb 0x85e
│      ╎│   0x0000089d      488b059c0720.  mov rax, qword [obj.stderr] ; obj.stderr__GLIBC_2.2.5
│      ╎│                                                              ; [0x201040:8]=0
│      ╎    0x000008a4      488b55a0       mov rdx, qword [var_60h]
│      ╎    0x000008a8      488d35590100.  lea rsi, str.Java_like_hashcode_is_0x_.8X ; 0xa08 ; "Java-like hashcode is 0x%.8X\n" ; const char *format
│      ╎    0x000008af      4889c7         mov rdi, rax                ; FILE *stream
│      ╎    0x000008b2      b800000000     mov eax, 0
│           0x000008b7      e8c4fdffff     call sym.imp.fprintf        ; int fprintf(FILE *stream, const char *format,   ...)
│           0x000008bc      488b057d0720.  mov rax, qword [obj.stderr] ; obj.stderr__GLIBC_2.2.5
│                                                                      ; [0x201040:8]=0
│           0x000008c3      4889c7         mov rdi, rax                ; FILE *stream
│           0x000008c6      e8c5fdffff     call sym.imp.fflush         ; int fflush(FILE *stream)
│           0x000008cb      c645af00       mov byte [var_51h], 0
│           0x000008cf      c74598000000.  mov dword [var_68h], 0
│           0x000008d6      eb50           jmp 0x928
│           ; CODE XREF from main @ 0x93d
│           0x000008d8      8b4598         mov eax, dword [var_68h]
│           0x000008db      4898           cdqe
│           0x000008dd      0fb64405b0     movzx eax, byte [rbp + rax - 0x50]
│           0x000008e2      8845ae         mov byte [format], al
│           0x000008e5      488b05340720.  mov rax, qword [obj.stdout] ; obj.stdout__GLIBC_2.2.5
│                                                                      ; [0x201020:8]=0
│           0x000008ec      488d55ae       lea rdx, [format]           ;   ...
│      ┌──> 0x000008f0      4889d6         mov rsi, rdx                ; const char *format
│      ╎│   0x000008f3      4889c7         mov rdi, rax                ; FILE *stream
│      ╎│   0x000008f6      b800000000     mov eax, 0
│      ╎│   0x000008fb      e880fdffff     call sym.imp.fprintf        ; int fprintf(FILE *stream, const char *format,   ...)
│      ╎│   0x00000900      488b05190720.  mov rax, qword [obj.stdout] ; obj.stdout__GLIBC_2.2.5
│      ╎│                                                              ; [0x201020:8]=0
│      ╎│   0x00000907      4889c7         mov rdi, rax                ; FILE *stream
│      ╎│   0x0000090a      e881fdffff     call sym.imp.fflush         ; int fflush(FILE *stream)
│      ╎│   0x0000090f      837d9809       cmp dword [var_68h], 9
│      ╎│   0x00000913      750f           jne 0x924
│      ╎│   0x00000915      b800000000     mov eax, 0
│      ╎│   0x0000091a      8b00           mov eax, dword [rax]
│      ╎│   0x0000091c      89459c         mov dword [var_64h], eax
│      ╎│   0x0000091f      8b459c         mov eax, dword [var_64h]
│      ╎│   0x00000922      eb1e           jmp 0x942
│      ╎│   ; CODE XREF from main @ 0x913
│      ╎│   0x00000924      83459801       add dword [var_68h], 1
│      ╎│   ; CODE XREF from main @ 0x8d6
│      ╎│   0x00000928      8b4598         mov eax, dword [var_68h]
│     ┌───< 0x0000092b      4863d8         movsxd rbx, eax
│     │╎│   0x0000092e      488d45b0       lea rax, [s]
│     │╎│   0x00000932      4889c7         mov rdi, rax                ; const char *s
│     │╎│   0x00000935      e826fdffff     call sym.imp.strlen         ; size_t strlen(const char *s)
│    ┌────< 0x0000093a      4839c3         cmp rbx, rax
│    │ ╎│   0x0000093d      7299           jb 0x8d8
│    │ ╎│   0x0000093f      8b459c         mov eax, dword [var_64h]
│    │ ╎    ; CODE XREF from main @ 0x922
│    │ ╎    0x00000942      488b4de8       mov rcx, qword [canary]
│    │ ╎    0x00000946      6448330c2528.  xor rcx, qword fs:[0x28]
│    │ ╎    0x0000094f      7405           je 0x956
│    │ ╎    0x00000951      e81afdffff     call sym.imp.__stack_chk_fail ; void __stack_chk_fail(void)
│    │      ; CODE XREF from main @ 0x94f
│    │      0x00000956      4883c468       add rsp, 0x68
│    └────> 0x0000095a      5b             pop rbx
│           0x0000095b      5d             pop rbp
└           0x0000095c      c3             ret
            0x0000095d      0f1f00         nop dword [rax]
            ; DATA XREF from entry0 @ 0x6c6
┌ 101: sym.__libc_csu_init (int64_t arg1, int64_t arg2, int64_t arg3);
│           ; arg int64_t arg1 @ rdi
│           ; arg int64_t arg2 @ rsi
│           ; arg int64_t arg3 @ rdx
│           0x00000960      4157           push r15
│           0x00000962      4156           push r14
│           0x00000964      4989d7         mov r15, rdx                ; arg3
│       ┌─< 0x00000967      4155           push r13
│       │   0x00000969      4154           push r12
│       │   0x0000096b      4c8d252e0420.  lea r12, obj.__frame_dummy_init_array_entry ; loc.__init_array_start
│       │                                                              ; 0x200da0
│           0x00000972      55             push rbp
│           0x00000973      488d2d2e0420.  lea rbp, obj.__do_global_dtors_aux_fini_array_entry ; loc.__init_array_end
│                                                                      ; 0x200da8 ; "p\a"
│           0x0000097a      53             push rbx
│           0x0000097b      4189fd         mov r13d, edi               ; arg1
│           0x0000097e      4989f6         mov r14, rsi                ; arg2
│           0x00000981      4c29e5         sub rbp, r12
│           0x00000984      4883ec08       sub rsp, 8
│           0x00000988      48c1fd03       sar rbp, 3
│           0x0000098c      e8a7fcffff     call sym._init
│           0x00000991      4885ed         test rbp, rbp
│           0x00000994      7420           je 0x9b6
│           0x00000996      31db           xor ebx, ebx
│           0x00000998      0f1f84000000.  nop dword [rax + rax]
│           ; CODE XREF from sym.__libc_csu_init @ 0x9b4
│           0x000009a0      4c89fa         mov rdx, r15
│           0x000009a3      4c89f6         mov rsi, r14
│           0x000009a6      4489ef         mov edi, r13d
│           0x000009a9      41ff14dc       call qword [r12 + rbx*8]
│       │   0x000009ad      4883c301       add rbx, 1
│       │   0x000009b1      4839dd         cmp rbp, rbx
│       │   0x000009b4      75ea           jne 0x9a0
│       │   ; CODE XREF from sym.__libc_csu_init @ 0x994
│       │   0x000009b6      4883c408       add rsp, 8
│      ╎│   0x000009ba      5b             pop rbx
│      ╎│   0x000009bb      5d             pop rbp
│      ╎│   0x000009bc      415c           pop r12
│      ╎│   0x000009be      415d           pop r13
│      ╎│   0x000009c0      415e           pop r14
│      ╎│   0x000009c2      415f           pop r15
└      ╎│   0x000009c4      c3             ret
       ╎│   0x000009c5      90             nop
       ╎│   0x000009c6      662e0f1f8400.  nop word cs:[rax + rax]
            ; DATA XREF from entry0 @ 0x6bf
┌ 2: sym.__libc_csu_fini ();
└           0x000009d0      f3c3           ret
            0x000009d2      0000           add byte [rax], al
            ;-- section..fini:
            ;-- .fini:
┌ 9: sym._fini ();
│           0x000009d4      4883ec08       sub rsp, 8                  ; [15] -r-x section size 9 named .fini
│           0x000009d8      4883c408       add rsp, 8
└           0x000009dc      c3             ret
            0x000009dd      0000           add byte [rax], al
            0x000009df  ~   0001           add byte [rcx], al
            ;-- section..rodata:
            ;-- .rodata:
            ;-- _IO_stdin_used:
            0x000009e0      0100           add dword [rax], eax        ; [16] -r-- section size 70 named .rodata
            0x000009e2      0200           add al, byte [rax]
            0x000009e4      0000           add byte [rax], al
            0x000009e6      0000           add byte [rax], al
            0x000009e8      0000           add byte [rax], al
            0x000009ea      0000           add byte [rax], al
            0x000009ec      0000           add byte [rax], al
            0x000009ee      0000           add byte [rax], al
            ;-- str.Hello__isolated_world:
            ;-- message:
            0x000009f0     .string "Hello, isolated world!\n" ; len=24
            ; DATA XREF from main @ 0x8a8
            ;-- str.Java_like_hashcode_is_0x_.8X:
            0x00000a08     .string "Java-like hashcode is 0x%.8X\n" ; len=30
       ┌──< 0x00000a26      0000           add byte [rax], al
       ││   ;-- section..eh_frame_hdr:
       ││   ;-- segment.GNU_EH_FRAME:
       ││   ;-- .eh_frame_hdr:
       ││   ;-- __GNU_EH_FRAME_HDR:
       ││   0x00000a28      011b           add dword [rbx], ebx        ; [17] -r-- section size 60 named .eh_frame_hdr
       ││   0x00000a2a      033b           add edi, dword [rbx]
       ││   0x00000a2c      3c00           cmp al, 0
       ││   0x00000a2e      0000           add byte [rax], al
      ┌───< 0x00000a30      06             invalid
      │││   0x00000a31      0000           add byte [rax], al
      │││   0x00000a33      0028           add byte [rax], ch
      │││   0x00000a35      fc             cld
      │││   0x00000a36      ff             invalid
      │││   0x00000a37      ff8800000078   dec dword [rax + 0x78000000]
     ││││   0x00000a3d      fc             cld
     ││││   0x00000a3e      ff             invalid
     ││││   0x00000a3f      ffb000000088   push qword [rax - 0x78000000]
     ││││   0x00000a45      fc             cld
     ││││   ; CODE XREF from str.Java_like_hashcode_is_0x_.8X @ +0x17
     ││││   0x00000a46      ff             invalid
     ││││   0x00000a47      ff5800         lcall [rax]
     ││││   0x00000a4a      0000           add byte [rax], al
     ││││   0x00000a4c      92             xchg eax, edx
     ││││   0x00000a4d      fd             std
     ││││   0x00000a4e      ff             invalid
     ││││   0x00000a4f      ffc8           dec eax
     ││││   0x00000a51      0000           add byte [rax], al
     ││││   0x00000a53      0038           add byte [rax], bh
     ││││   0x00000a55      ff             invalid
     ││││   0x00000a56      ff             invalid
     ││││   0x00000a57      fff0           push rax
     ││││   0x00000a59      0000           add byte [rax], al
     ││││   0x00000a5b      00a8ffffff38   add byte [rax + 0x38ffffff], ch
     ││││   0x00000a61      0100           add dword [rax], eax
      │││   0x00000a63      0000           add byte [rax], al
      │││   0x00000a65      0000           add byte [rax], al
      │││   0x00000a67  ~   001400         add byte [rax + rax], dl
      │││   ;-- section..eh_frame:
      │││   ;-- .eh_frame:
      │││   0x00000a68      1400           adc al, 0                   ; [18] -r-- section size 272 named .eh_frame
      │││   0x00000a6a      0000           add byte [rax], al
      │││   0x00000a6c      0000           add byte [rax], al
      │││   0x00000a6e      0000           add byte [rax], al
      │││   ; CODE XREF from str.Hello__isolated_world @ +0x12
      │││   0x00000a70      017a52         add dword [rdx + 0x52], edi
      │││   0x00000a73      0001           add byte [rcx], al
      │││   0x00000a75      7810           js 0xa87
      │││   0x00000a77      011b           add dword [rbx], ebx
      │││   0x00000a79      0c07           or al, 7
      │││   0x00000a7b      089001071014   or byte [rax + 0x14100701], dl
      │││   0x00000a81      0000           add byte [rax], al
      │││   0x00000a83      001c00         add byte [rax + rax], bl
      │││   0x00000a86      0000           add byte [rax], al
      │││   0x00000a88      28fc           sub ah, bh
      │ │   0x00000a8a      ff             invalid
      │ │   0x00000a8b      ff2b           ljmp [rbx]
      │     0x00000a8d      0000           add byte [rax], al
      │     0x00000a8f      0000           add byte [rax], al
      │ ┌─< 0x00000a91      0000           add byte [rax], al
      │ │   0x00000a93      0000           add byte [rax], al
      │ │   0x00000a95      0000           add byte [rax], al
      │ │   0x00000a97      001400         add byte [rax + rax], dl
      └───> 0x00000a9a      0000           add byte [rax], al
        │   0x00000a9c      0000           add byte [rax], al
        │   0x00000a9e      0000           add byte [rax], al
        │   0x00000aa0      017a52         add dword [rdx + 0x52], edi
        └─> 0x00000aa3      0001           add byte [rcx], al
            0x00000aa5      7810           js 0xab7
            0x00000aa7      011b           add dword [rbx], ebx
            0x00000aa9      0c07           or al, 7
            0x00000aab      089001000024   or byte [rax + 0x24000001], dl
            0x00000ab1      0000           add byte [rax], al
            0x00000ab3      001c00         add byte [rax + rax], bl
            0x00000ab6      0000           add byte [rax], al
            0x00000ab8      98             cwde
            0x00000ab9      fb             sti
            0x00000aba      ff             invalid
            0x00000abb      ff5000         call qword [rax]
            0x00000abe      0000           add byte [rax], al
            0x00000ac0      000e           add byte [rsi], cl
        │   0x00000ac2      10460e         adc byte [rsi + 0xe], al
        │   0x00000ac5      184a0f         sbb byte [rdx + 0xf], cl
        │   0x00000ac8      0b7708         or esi, dword [rdi + 8]
        │   0x00000acb      80003f         add byte [rax], 0x3f        ; [0x3f:1]=0
        │   0x00000ace      1a3b           sbb bh, byte [rbx]
        │   0x00000ad0      2a33           sub dh, byte [rbx]
        │   0x00000ad2      2422           and al, 0x22
            0x00000ad4      0000           add byte [rax], al
            0x00000ad6      0000           add byte [rax], al
            0x00000ad8      1400           adc al, 0
            0x00000ada      0000           add byte [rax], al
            0x00000adc      440000         add byte [rax], r8b
            0x00000adf      00c0           add al, al
            0x00000ae1      fb             sti
            0x00000ae2      ff             invalid
            0x00000ae3      ff08           dec dword [rax]
            0x00000ae5      0000           add byte [rax], al
            0x00000ae7      0000           add byte [rax], al
            0x00000ae9      0000           add byte [rax], al
            0x00000aeb      0000           add byte [rax], al
            0x00000aed      0000           add byte [rax], al
            0x00000aef      002400         add byte [rax + rax], ah
            0x00000af2      0000           add byte [rax], al
            0x00000af4      5c             pop rsp
            0x00000af5      0000           add byte [rax], al
            0x00000af7      00c2           add dl, al
            0x00000af9      fc             cld
            0x00000afa      ff             invalid
            0x00000afb      ffa301000000   jmp qword [rbx + 1]
            0x00000b01      41             invalid
            0x00000b02      0e             invalid
            0x00000b03      108602430d06   adc byte [rsi + 0x60d4302], al
            0x00000b09      45830303       add dword [r11], 3
            0x00000b0d      99             cdq
            0x00000b0e      010c07         add dword [rdi + rax], ecx
            0x00000b11      0800           or byte [rax], al
            0x00000b13      0000           add byte [rax], al
            0x00000b15      0000           add byte [rax], al
            0x00000b17      00440000       add byte [rax + rax], al
            0x00000b1b      008400000040.  add byte [rax + rax - 0x1c00000], al
            0x00000b22      ff             invalid
            0x00000b23      ff6500         jmp qword [rbp]
            0x00000b26      0000           add byte [rax], al
            0x00000b28      00420e         add byte [rdx + 0xe], al
            0x00000b2b      108f02420e18   adc byte [rdi + 0x180e4202], cl
            0x00000b31      8e03           mov es, word [rbx]
            0x00000b33      45             invalid
            0x00000b34      0e             invalid
            0x00000b35      208d04420e28   and byte [rbp + 0x280e4204], cl
            0x00000b3b      8c05480e3086   mov word [0xffffffff86301989], es
            0x00000b41      06             invalid
            0x00000b42      48             invalid
            0x00000b43      0e             invalid
            0x00000b44      3883074d0e40   cmp byte [rbx + 0x400e4d07], al
            0x00000b4a      720e           jb 0xb5a
            0x00000b4c      38410e         cmp byte [rcx + 0xe], al
            0x00000b4f      30410e         xor byte [rcx + 0xe], al
            0x00000b52      28420e         sub byte [rdx + 0xe], al
            0x00000b55      20420e         and byte [rdx + 0xe], al
            0x00000b58      18420e         sbb byte [rdx + 0xe], al
            0x00000b5b      10420e         adc byte [rdx + 0xe], al
            0x00000b5e      0800           or byte [rax], al
            0x00000b60      1000           adc byte [rax], al
            0x00000b62      0000           add byte [rax], al
            0x00000b64      cc             int3
            0x00000b65      0000           add byte [rax], al
        │   0x00000b67      0068fe         add byte [rax - 2], ch
        │   0x00000b6a      ff             invalid
        │   0x00000b6b      ff02           inc dword [rdx]
        │   0x00000b6d      0000           add byte [rax], al
        │   0x00000b6f      0000           add byte [rax], al
        │   0x00000b71      0000           add byte [rax], al
        │   0x00000b73  ~   0000           add byte [rax], al
        │   ;-- __FRAME_END__:
        │   0x00000b74      0000           add byte [rax], al
        └─> 0x00000b76      0000           add byte [rax], al
            0x00000b78      ff             invalid
            0x00000b79      ff             invalid
            0x00000b7a      ff             invalid
            0x00000b7b      ff             invalid
            0x00000b7c      ff             invalid
            0x00000b7d      ff             invalid
            0x00000b7e      ff             invalid
            0x00000b7f      ff             invalid
            0x00000b80      ff             invalid
            0x00000b81      ff             invalid
            0x00000b82      ff             invalid
            0x00000b83      ff             invalid
            0x00000b84      ff             invalid
            0x00000b85      ff             invalid
            0x00000b86      ff             invalid
            0x00000b87      ff             invalid
            0x00000b88      ff             invalid
            0x00000b89      ff             invalid
            0x00000b8a      ff             invalid
            0x00000b8b      ff             invalid
            0x00000b8c      ff             invalid
            0x00000b8d      ff             invalid
            0x00000b8e      ff             invalid
            0x00000b8f      ff             invalid
            0x00000b90      ff             invalid
            0x00000b91      ff             invalid
            0x00000b92      ff             invalid
            0x00000b93      ff             invalid
            0x00000b94      ff             invalid
            0x00000b95      ff             invalid
            0x00000b96      ff             invalid
            0x00000b97      ff             invalid
            0x00000b98      ff             invalid
            0x00000b99      ff             invalid
            0x00000b9a      ff             invalid
            0x00000b9b      ff             invalid
            0x00000b9c      ff             invalid
            0x00000b9d      ff             invalid
            0x00000b9e      ff             invalid
            0x00000b9f      ff             invalid
            0x00000ba0      ff             invalid
            0x00000ba1      ff             invalid
            0x00000ba2      ff             invalid
            0x00000ba3      ff             invalid
            0x00000ba4      ff             invalid
            0x00000ba5      ff             invalid
            0x00000ba6      ff             invalid
            0x00000ba7      ff             invalid
            0x00000ba8      ff             invalid
            0x00000ba9      ff             invalid
            0x00000baa      ff             invalid
            0x00000bab      ff             invalid
            0x00000bac      ff             invalid
            0x00000bad      ff             invalid
            0x00000bae      ff             invalid
            0x00000baf      ff             invalid
            0x00000bb0      ff             invalid
            0x00000bb1      ff             invalid
            0x00000bb2      ff             invalid
            0x00000bb3      ff             invalid
            0x00000bb4      ff             invalid
            0x00000bb5      ff             invalid
            0x00000bb6      ff             invalid
            0x00000bb7      ff             invalid
            0x00000bb8      ff             invalid
            0x00000bb9      ff             invalid
            0x00000bba      ff             invalid
            0x00000bbb      ff             invalid
            0x00000bbc      ff             invalid
            0x00000bbd      ff             invalid
            0x00000bbe      ff             invalid
            0x00000bbf      ff             invalid
            0x00000bc0      ff             invalid
            0x00000bc1      ff             invalid
            0x00000bc2      ff             invalid
            0x00000bc3      ff             invalid
            0x00000bc4      ff             invalid
            0x00000bc5      ff             invalid
            0x00000bc6      ff             invalid
            0x00000bc7      ff             invalid
            0x00000bc8      ff             invalid
            0x00000bc9      ff             invalid
            0x00000bca      ff             invalid
            0x00000bcb      ff             invalid
            0x00000bcc      ff             invalid
            0x00000bcd      ff             invalid
            0x00000bce      ff             invalid
            0x00000bcf      ff             invalid
            0x00000bd0      ff             invalid
            0x00000bd1      ff             invalid
            0x00000bd2      ff             invalid
            0x00000bd3      ff             invalid
            0x00000bd4      ff             invalid
            0x00000bd5      ff             invalid
            0x00000bd6      ff             invalid
            0x00000bd7      ff             invalid
            0x00000bd8      ff             invalid
            0x00000bd9      ff             invalid
            0x00000bda      ff             invalid
            0x00000bdb      ff             invalid
            0x00000bdc      ff             invalid
            0x00000bdd      ff             invalid
            0x00000bde      ff             invalid
            0x00000bdf      ff             invalid
            0x00000be0      ff             invalid
            0x00000be1      ff             invalid
            0x00000be2      ff             invalid
            0x00000be3      ff             invalid
            0x00000be4      ff             invalid
            0x00000be5      ff             invalid
            0x00000be6      ff             invalid
            0x00000be7      ff             invalid
            0x00000be8      ff             invalid
            0x00000be9      ff             invalid
            0x00000bea      ff             invalid
            0x00000beb      ff             invalid
            0x00000bec      ff             invalid
            0x00000bed      ff             invalid
            0x00000bee      ff             invalid
            0x00000bef      ff             invalid
            0x00000bf0      ff             invalid
            0x00000bf1      ff             invalid
            0x00000bf2      ff             invalid
            0x00000bf3      ff             invalid
            0x00000bf4      ff             invalid
            0x00000bf5      ff             invalid
            0x00000bf6      ff             invalid
            0x00000bf7      ff             invalid
            0x00000bf8      ff             invalid
            0x00000bf9      ff             invalid
            0x00000bfa      ff             invalid
            0x00000bfb      ff             invalid
            0x00000bfc      ff             invalid
            0x00000bfd      ff             invalid
            0x00000bfe      ff             invalid
            0x00000bff      ff             invalid
            0x00000c00      ff             invalid
            0x00000c01      ff             invalid
            0x00000c02      ff             invalid
            0x00000c03      ff             invalid
            0x00000c04      ff             invalid
            0x00000c05      ff             invalid
            0x00000c06      ff             invalid
            0x00000c07      ff             invalid
            0x00000c08      ff             invalid
            0x00000c09      ff             invalid
            0x00000c0a      ff             invalid
            0x00000c0b      ff             invalid
            0x00000c0c      ff             invalid
            0x00000c0d      ff             invalid
