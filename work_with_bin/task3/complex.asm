            ; CALL XREF from sym.__libc_csu_init @ 0x829
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
┌ 25: loc.imp._ITM_deregisterTMCloneTable (int64_t arg4);
│           ; arg int64_t arg4 @ rcx
│       ┌─< 0x00000000      7f45           jg 0x47                     ; [28] ---- section size 254 named .shstrtab
│       │   ; DATA XREF from sym.imp.fflush @ +0x6
│       │   0x00000002      4c460201       add r8b, byte [rcx]         ; arg4
│       │   0x00000006      0100           add dword [rax], eax
│       │   0x00000008      0000           add byte [rax], al
│       │   0x0000000a      0000           add byte [rax], al
│       │   0x0000000c      0000           add byte [rax], al
│       │   0x0000000e      0000           add byte [rax], al
│       │   0x00000010      0300           add eax, dword [rax]
│       │   0x00000012      3e0001         add byte ds:[rcx], al       ; arg4
│       │   0x00000015      0000           add byte [rax], al
│       │   ; DATA XREF from main @ 0x7bb
└       │   0x00000017      0030           add byte [rax], dh
        │   0x00000019      06             invalid
        │   0x0000001a      0000           add byte [rax], al
        │   0x0000001c      0000           add byte [rax], al
        │   0x0000001e      0000           add byte [rax], al
        │   ; DATA XREF from str.Hello__isolated_world @ +0x5
        │   0x00000020      400000         add byte [rax], al
        │   0x00000023      0000           add byte [rax], al
        │   0x00000025      0000           add byte [rax], al
        │   0x00000027      00e0           add al, ah
        │   0x00000029      1900           sbb dword [rax], eax
        │   0x0000002b      0000           add byte [rax], al
        │   0x0000002d      0000           add byte [rax], al
        │   0x0000002f      0000           add byte [rax], al
        │   0x00000031      0000           add byte [rax], al
        │   0x00000033      004000         add byte [rax], al
        │   0x00000036      3800           cmp byte [rax], al
        │   0x00000038      0900           or dword [rax], eax
        │   0x0000003a  ~   40001d001c00.  add byte [0x06001c41], bl   ; [0x6001c41:1]=255
        │   ;-- segment.PHDR:
        │   0x00000040      06             invalid
        │   0x00000041      0000           add byte [rax], al
        │   0x00000043      000400         add byte [rax + rax], al
        │   0x00000046      0000           add byte [rax], al
            0x00000048      400000         add byte [rax], al
            0x0000004b      0000           add byte [rax], al
            0x0000004d      0000           add byte [rax], al
            0x0000004f      004000         add byte [rax], al
            0x00000052      0000           add byte [rax], al
            0x00000054      0000           add byte [rax], al
            0x00000056      0000           add byte [rax], al
            0x00000058      400000         add byte [rax], al
            0x0000005b      0000           add byte [rax], al
            0x0000005d      0000           add byte [rax], al
            0x0000005f      00f8           add al, bh
            0x00000061      0100           add dword [rax], eax
            0x00000063      0000           add byte [rax], al
            0x00000065      0000           add byte [rax], al
            0x00000067      00f8           add al, bh
            0x00000069      0100           add dword [rax], eax
            0x0000006b      0000           add byte [rax], al
            0x0000006d      0000           add byte [rax], al
            0x0000006f      0008           add byte [rax], cl
            0x00000071      0000           add byte [rax], al
            0x00000073      0000           add byte [rax], al
            0x00000075      0000           add byte [rax], al
            0x00000077      0003           add byte [rbx], al
            0x00000079      0000           add byte [rax], al
            0x0000007b      000400         add byte [rax + rax], al
            0x0000007e      0000           add byte [rax], al
            0x00000080      3802           cmp byte [rdx], al
            0x00000082      0000           add byte [rax], al
            0x00000084      0000           add byte [rax], al
            0x00000086      0000           add byte [rax], al
            0x00000088      3802           cmp byte [rdx], al
            0x0000008a      0000           add byte [rax], al
            0x0000008c      0000           add byte [rax], al
            0x0000008e      0000           add byte [rax], al
            0x00000090      3802           cmp byte [rdx], al
            0x00000092      0000           add byte [rax], al
            0x00000094      0000           add byte [rax], al
            0x00000096      0000           add byte [rax], al
            0x00000098      1c00           sbb al, 0
            0x0000009a      0000           add byte [rax], al
            0x0000009c      0000           add byte [rax], al
            0x0000009e      0000           add byte [rax], al
            0x000000a0      1c00           sbb al, 0
            0x000000a2      0000           add byte [rax], al
            0x000000a4      0000           add byte [rax], al
            0x000000a6      0000           add byte [rax], al
            0x000000a8      0100           add dword [rax], eax
            0x000000aa      0000           add byte [rax], al
            0x000000ac      0000           add byte [rax], al
            0x000000ae      0000           add byte [rax], al
            0x000000b0      0100           add dword [rax], eax
            0x000000b2      0000           add byte [rax], al
            0x000000b4      0500000000     add eax, 0
            0x000000b9      0000           add byte [rax], al
            0x000000bb      0000           add byte [rax], al
            0x000000bd      0000           add byte [rax], al
            0x000000bf      0000           add byte [rax], al
            0x000000c1      0000           add byte [rax], al
            0x000000c3      0000           add byte [rax], al
            0x000000c5      0000           add byte [rax], al
            0x000000c7      0000           add byte [rax], al
            0x000000c9      0000           add byte [rax], al
            0x000000cb      0000           add byte [rax], al
            0x000000cd      0000           add byte [rax], al
            0x000000cf      00d0           add al, dl
            0x000000d1      0900           or dword [rax], eax
            0x000000d3      0000           add byte [rax], al
            0x000000d5      0000           add byte [rax], al
            0x000000d7      00d0           add al, dl
            0x000000d9      0900           or dword [rax], eax
            0x000000db      0000           add byte [rax], al
            0x000000dd      0000           add byte [rax], al
            0x000000df      0000           add byte [rax], al
            0x000000e1      0020           add byte [rax], ah
            0x000000e3      0000           add byte [rax], al
            0x000000e5      0000           add byte [rax], al
            0x000000e7      0001           add byte [rcx], al
            0x000000e9      0000           add byte [rax], al
            0x000000eb      0006           add byte [rsi], al
            0x000000ed      0000           add byte [rax], al
            0x000000ef      00a80d000000   add byte [rax + 0xd], ch
            0x000000f5      0000           add byte [rax], al
            0x000000f7      00a80d200000   add byte [rax + 0x200d], ch
            0x000000fd      0000           add byte [rax], al
            0x000000ff      00a80d200000   add byte [rax + 0x200d], ch
            0x00000105      0000           add byte [rax], al
            0x00000107      006802         add byte [rax + 2], ch
            0x0000010a      0000           add byte [rax], al
            0x0000010c      0000           add byte [rax], al
            0x0000010e      0000           add byte [rax], al
            0x00000110      7802           js 0x114
            0x00000112      0000           add byte [rax], al
            ; CODE XREF from segment.PHDR @ +0xd0
            0x00000114      0000           add byte [rax], al
            0x00000116      0000           add byte [rax], al
            0x00000118      00             invalid
            0x00000119      0020           add byte [rax], ah
            0x0000011b      0000           add byte [rax], al
            0x0000011d      0000           add byte [rax], al
            0x0000011f      0002           add byte [rdx], al
            0x00000121      0000           add byte [rax], al
            0x00000123      0006           add byte [rsi], al
            0x00000125      0000           add byte [rax], al
            0x00000127      00b80d000000   add byte [rax + 0xd], bh
            0x0000012d      0000           add byte [rax], al
            0x0000012f      00b80d200000   add byte [rax + 0x200d], bh
            0x00000135      0000           add byte [rax], al
            0x00000137      00b80d200000   add byte [rax + 0x200d], bh
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
            0x00000198      8808           mov byte [rax], cl
            0x0000019a      0000           add byte [rax], al
            0x0000019c      0000           add byte [rax], al
            0x0000019e      0000           add byte [rax], al
            0x000001a0      8808           mov byte [rax], cl
            0x000001a2      0000           add byte [rax], al
            0x000001a4      0000           add byte [rax], al
            0x000001a6      0000           add byte [rax], al
            0x000001a8      8808           mov byte [rax], cl
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
            0x00000202      7464           je 0x268
            0x00000204      0400           add al, 0
            0x00000206      0000           add byte [rax], al
            0x00000208      a80d           test al, 0xd
            ; DATA XREF from entry0 @ 0x63f
            0x0000020a      0000           add byte [rax], al
            0x0000020c      0000           add byte [rax], al
            0x0000020e      0000           add byte [rax], al
            0x00000210      a80d           test al, 0xd
            0x00000212      2000           and byte [rax], al
            0x00000214      0000           add byte [rax], al
            0x00000216      0000           add byte [rax], al
            0x00000218      a8             invalid
            0x00000219      0d20000000     or eax, 0x20                ; "@"
            0x0000021e      0000           add byte [rax], al
            0x00000220      58             pop rax
            0x00000221      0200           add al, byte [rax]
            0x00000223      0000           add byte [rax], al
            0x00000225      0000           add byte [rax], al
            0x00000227      005802         add byte [rax + 2], bl
            0x0000022a      0000           add byte [rax], al
            0x0000022c      0000           add byte [rax], al
            0x0000022e      0000           add byte [rax], al
            0x00000230      0100           add dword [rax], eax
            0x00000232      0000           add byte [rax], al
            0x00000234      0000           add byte [rax], al
            0x00000236      0000           add byte [rax], al
            ;-- section..interp:
            ;-- segment.INTERP:
            ;-- .interp:
            0x00000238      2f             invalid                     ; [01] -r-- section size 28 named .interp
            0x00000239      6c             insb byte [rdi], dx
            0x0000023a      696236342f6c.  imul esp, dword [rdx + 0x36], 0x646c2f34
            0x00000241      2d6c696e75     sub eax, 0x756e696c
            0x00000246      782d           js 0x275
            0x00000248      7838           js 0x282
            0x0000024a      362d36342e73   sub eax, 0x732e3436
            0x00000250      6f             outsd dx, dword [rsi]
            0x00000251      2e3200         xor al, byte cs:[rax]
            ;-- section..note.ABI_tag:
            ;-- segment.NOTE:
            ;-- .note.ABI-tag:
            0x00000254      0400           add al, 0                   ; [02] -r-- section size 32 named .note.ABI_tag
            0x00000256      0000           add byte [rax], al
            0x00000258      1000           adc byte [rax], al
            0x0000025a      0000           add byte [rax], al
            0x0000025c      0100           add dword [rax], eax
            0x0000025e      0000           add byte [rax], al
            0x00000260      474e55         push rbp
            0x00000263      0000           add byte [rax], al
            0x00000265      0000           add byte [rax], al
            0x00000267      0003           add byte [rbx], al
            0x00000269      0000           add byte [rax], al
            0x0000026b      0002           add byte [rdx], al
            0x0000026d      0000           add byte [rax], al
            0x0000026f      0000           add byte [rax], al
            0x00000271      0000           add byte [rax], al
            0x00000273  ~   000400         add byte [rax + rax], al
            ;-- section..note.gnu.build_id:
            ;-- .note.gnu.build-id:
            0x00000274      0400           add al, 0                   ; [03] -r-- section size 36 named .note.gnu.build_id
            0x00000276      0000           add byte [rax], al
            0x00000278      1400           adc al, 0
            0x0000027a      0000           add byte [rax], al
            0x0000027c      0300           add eax, dword [rax]
            0x0000027e      0000           add byte [rax], al
            0x00000280      474e55         push rbp
            0x00000283      0068b4         add byte [rax - 0x4c], ch
            0x00000286      0ff4f0         pmuludq mm6, mm0
            0x00000289      a835           test al, 0x35
            0x0000028b      5d             pop rbp
            0x0000028c      a93a73b778     test eax, 0x78b7733a
            0x00000291      52             push rdx
            0x00000292      e545           in eax, 0x45
            0x00000294      36ee           out dx, al
            0x00000296      dbd0           fcmovnbe st(0), st(0)
            ;-- section..gnu.hash:
            ;-- .gnu.hash:
            0x00000298      0200           add al, byte [rax]          ; [04] -r-- section size 36 named .gnu.hash
            0x0000029a      0000           add byte [rax], al
            0x0000029c      0900           or dword [rax], eax
            0x0000029e      0000           add byte [rax], al
            0x000002a0      0100           add dword [rax], eax
            0x000002a2      0000           add byte [rax], al
            0x000002a4      06             invalid
            0x000002a5      0000           add byte [rax], al
            0x000002a7      0000           add byte [rax], al
            0x000002a9      0000           add byte [rax], al
            0x000002ab      0000           add byte [rax], al
            0x000002ad      0110           add dword [rax], edx
            0x000002af      0009           add byte [rcx], cl
            0x000002b1      0000           add byte [rax], al
            0x000002b3      0000           add byte [rax], al
            0x000002b5      0000           add byte [rax], al
            0x000002b7      0029           add byte [rcx], ch
            0x000002b9      1d8c1c0000     sbb eax, 0x1c8c
            0x000002be      0000           add byte [rax], al
            ;-- section..dynsym:
            ;-- .dynsym:
            0x000002c0      0000           add byte [rax], al          ; [05] -r-- section size 240 named .dynsym
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
            0x000002d8      690000002000   imul eax, dword [rax], 0x200000
            0x000002de      0000           add byte [rax], al
            0x000002e0      0000           add byte [rax], al
            0x000002e2      0000           add byte [rax], al
            0x000002e4      0000           add byte [rax], al
            0x000002e6      0000           add byte [rax], al
            0x000002e8      0000           add byte [rax], al
            0x000002ea      0000           add byte [rax], al
            0x000002ec      0000           add byte [rax], al
            0x000002ee      0000           add byte [rax], al
            0x000002f0      1200           adc al, byte [rax]
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
            0x00000308      410000         add byte [r8], al
            0x0000030b      0012           add byte [rdx], dl
            0x0000030d      0000           add byte [rax], al
            0x0000030f      0000           add byte [rax], al
            0x00000311      0000           add byte [rax], al
            0x00000313      0000           add byte [rax], al
            0x00000315      0000           add byte [rax], al
            0x00000317      0000           add byte [rax], al
            0x00000319      0000           add byte [rax], al
            0x0000031b      0000           add byte [rax], al
            0x0000031d      0000           add byte [rax], al
            0x0000031f      002a           add byte [rdx], ch
            0x00000321      0000           add byte [rax], al
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
            0x00000337      008500000020   add byte [rbp + 0x20000000], al
            0x0000033d      0000           add byte [rax], al
            0x0000033f      0000           add byte [rax], al
            0x00000341      0000           add byte [rax], al
            0x00000343      0000           add byte [rax], al
            0x00000345      0000           add byte [rax], al
            0x00000347      0000           add byte [rax], al
            0x00000349      0000           add byte [rax], al
            0x0000034b      0000           add byte [rax], al
            0x0000034d      0000           add byte [rax], al
            0x0000034f      000b           add byte [rbx], cl
            0x00000351      0000           add byte [rax], al
            0x00000353      0012           add byte [rdx], dl
            0x00000355      0000           add byte [rax], al
            0x00000357      0000           add byte [rax], al
            0x00000359      0000           add byte [rax], al
            0x0000035b      0000           add byte [rax], al
            0x0000035d      0000           add byte [rax], al
            0x0000035f      0000           add byte [rax], al
            0x00000361      0000           add byte [rax], al
            0x00000363      0000           add byte [rax], al
            0x00000365      0000           add byte [rax], al
            0x00000367      009400000020.  add byte [rax + rax + 0x200000], dl
            0x0000036e      0000           add byte [rax], al
            0x00000370      0000           add byte [rax], al
            0x00000372      0000           add byte [rax], al
            0x00000374      0000           add byte [rax], al
            0x00000376      0000           add byte [rax], al
            0x00000378      0000           add byte [rax], al
            0x0000037a      0000           add byte [rax], al
            0x0000037c      0000           add byte [rax], al
            0x0000037e      0000           add byte [rax], al
            0x00000380      3200           xor al, byte [rax]
            0x00000382      0000           add byte [rax], al
            0x00000384      2200           and al, byte [rax]
            0x00000386      0000           add byte [rax], al
            0x00000388      0000           add byte [rax], al
            0x0000038a      0000           add byte [rax], al
            0x0000038c      0000           add byte [rax], al
            0x0000038e      0000           add byte [rax], al
            0x00000390      0000           add byte [rax], al
            0x00000392      0000           add byte [rax], al
            0x00000394      0000           add byte [rax], al
            0x00000396      0000           add byte [rax], al
            0x00000398      2300           and eax, dword [rax]
            0x0000039a      0000           add byte [rax], al
            0x0000039c      1100           adc dword [rax], eax
            0x0000039e      1800           sbb byte [rax], al
            0x000003a0      1010           adc byte [rax], dl
            0x000003a2      2000           and byte [rax], al
            0x000003a4      0000           add byte [rax], al
            0x000003a6      0000           add byte [rax], al
            0x000003a8      0800           or byte [rax], al
            0x000003aa      0000           add byte [rax], al
            0x000003ac      0000           add byte [rax], al
            0x000003ae      0000           add byte [rax], al
            ;-- section..dynstr:
            ;-- .dynstr:
            0x000003b0      006c6962       add byte [rcx + rbp*2 + 0x62], ch ; [06] -r-- section size 174 named .dynstr
            0x000003b4      632e           movsxd rbp, dword [rsi]
            0x000003b6      736f           jae 0x427
            0x000003b8      2e36006666     add byte ss:[rsi + 0x66], ah
            0x000003bd      6c             insb byte [rdi], dx
            0x000003be      7573           jne 0x433
            0x000003c0      68005f5f73     push 0x735f5f00
            0x000003c5      7461           je 0x428
            0x000003c7      636b5f         movsxd rbp, dword [rbx + 0x5f]
            0x000003ca      63686b         movsxd rbp, dword [rax + 0x6b]
            0x000003cd      5f             pop rdi
            0x000003ce      66             invalid
            0x000003cf      61             invalid
            0x000003d0      696c00737464.  imul ebp, dword [rax + rax + 0x73], 0x756f6474
            0x000003d8      7400           je 0x3da
            ; CODE XREF from section..dynstr @ +0x28
            0x000003da      667072         jo 0x44f
            0x000003dd      696e7466005f.  imul ebp, dword [rsi + 0x74], 0x5f5f0066
            0x000003e4      637861         movsxd rdi, dword [rax + 0x61]
            0x000003e7      5f             pop rdi
            0x000003e8      66696e616c69   imul bp, word [rsi + 0x61], 0x696c
            0x000003ee      7a65           jp 0x455
            0x000003f0      005f5f         add byte [rdi + 0x5f], bl
            0x000003f3      6c             insb byte [rdi], dx
            0x000003f4      6962635f7374.  imul esp, dword [rdx + 0x63], 0x6174735f
            0x000003fb      7274           jb 0x471
            0x000003fd      5f             pop rdi
            0x000003fe      6d             insd dword [rdi], dx
            0x000003ff      61             invalid
            0x00000400      696e00474c49.  imul ebp, dword [rsi], 0x42494c47
            0x00000407      435f           pop r15
            0x00000409      322e           xor ch, byte [rsi]
            0x0000040b      3400           xor al, 0
            0x0000040d      474c4942435f   pop r15
            0x00000413      322e           xor ch, byte [rsi]
            0x00000415      322e           xor ch, byte [rsi]
            0x00000417      35             invalid
            0x00000418      00             invalid
            0x00000419      5f             pop rdi
            0x0000041a      4954           push r12
            0x0000041c      4d5f           pop r15
            0x0000041e      64657265       jb 0x487
            0x00000422      676973746572.  imul esi, dword [ebx + 0x74], 0x4d547265
            0x0000042a      436c           insb byte [rdi], dx
            0x0000042c      6f             outsd dx, dword [rsi]
            0x0000042d      6e             outsb dx, byte [rsi]
            0x0000042e      6554           push rsp
            0x00000430      61             invalid
            0x00000431      62             invalid
            0x00000432      6c             insb byte [rdi], dx
            ; CODE XREF from section..dynstr @ +0xe
            0x00000433      65005f5f       add byte gs:[rdi + 0x5f], bl
            0x00000437      676d           insd dword [edi], dx
            0x00000439      6f             outsd dx, dword [rsi]
            0x0000043a      6e             outsb dx, byte [rsi]
            0x0000043b      5f             pop rdi
            0x0000043c      7374           jae 0x4b2
            0x0000043e      61             invalid
            0x0000043f      7274           jb 0x4b5
            0x00000441      5f             pop rdi
            0x00000442      5f             pop rdi
            0x00000443      005f49         add byte [rdi + 0x49], bl
            0x00000446      54             push rsp
            0x00000447      4d5f           pop r15
            0x00000449      7265           jb 0x4b0
            0x0000044b      676973746572.  imul esi, dword [ebx + 0x74], 0x4d547265
            0x00000453      436c           insb byte [rdi], dx
            ; CODE XREF from section..dynstr @ +0x3e
            0x00000455      6f             outsd dx, dword [rsi]
            0x00000456      6e             outsb dx, byte [rsi]
            0x00000457      6554           push rsp
            0x00000459      61             invalid
            0x0000045a      62             invalid
            0x0000045b      6c             insb byte [rdi], dx
            0x0000045c  ~   650000         add byte gs:[rax], al
            ;-- section..gnu.version:
            ;-- .gnu.version:
            0x0000045e      0000           add byte [rax], al          ; [07] -r-- section size 20 named .gnu.version
            0x00000460      0000           add byte [rax], al
            0x00000462      0300           add eax, dword [rax]
            0x00000464      0200           add al, byte [rax]
            0x00000466      0200           add al, byte [rax]
            0x00000468      0000           add byte [rax], al
            0x0000046a      0200           add al, byte [rax]
            0x0000046c      0000           add byte [rax], al
            0x0000046e      0200           add al, byte [rax]
            0x00000470      0200           add al, byte [rax]
            0x00000472      0000           add byte [rax], al
            0x00000474      0000           add byte [rax], al
            0x00000476      0000           add byte [rax], al
            ;-- section..gnu.version_r:
            ;-- .gnu.version_r:
            0x00000478      0100           add dword [rax], eax        ; [08] -r-- section size 48 named .gnu.version_r
            0x0000047a      0200           add al, byte [rax]
            0x0000047c      0100           add dword [rax], eax
            0x0000047e      0000           add byte [rax], al
            0x00000480      1000           adc byte [rax], al
            0x00000482      0000           add byte [rax], al
            0x00000484      0000           add byte [rax], al
            0x00000486      0000           add byte [rax], al
            0x00000488      1469           adc al, 0x69
            0x0000048a      690d00000300.  imul ecx, dword [0x00030494], 0x53
            0x00000494      1000           adc byte [rax], al
            0x00000496      0000           add byte [rax], al
            0x00000498      751a           jne 0x4b4
            0x0000049a      690900000200   imul ecx, dword [rcx], 0x20000
            0x000004a0      5d             pop rbp
            0x000004a1      0000           add byte [rax], al
            0x000004a3      0000           add byte [rax], al
            0x000004a5      0000           add byte [rax], al
            0x000004a7  ~   00a80d200000   add byte [rax + 0x200d], ch
            ;-- section..rela.dyn:
            ;-- .rela.dyn:
            0x000004a8      .qword 0x0000000000200da8 ; section..init_array ; segment.LOAD1 ; segment.GNU_RELRO ; sym..init_array ; obj.__frame_dummy_init_array_entry ; loc.__init_array_start ; [09] -r-- section size 216 named .rela.dyn
            ; CODE XREF from section..dynstr @ +0x99
            0x000004b0      .qword 0x0000000000000008
            0x000004b8      .qword 0x0000000000000730 ; entry.init0 ; sym.frame_dummy
            0x000004c0      .qword 0x0000000000200db0 ; section..fini_array ; sym..fini_array ; obj.__do_global_dtors_aux_fini_array_entry ; loc.__init_array_end
            0x000004c8      .qword 0x0000000000000008
            0x000004d0      .qword 0x00000000000006f0 ; entry.fini0 ; sym.__do_global_dtors_aux
            0x000004d8      .qword 0x0000000000201008 ; obj.__dso_handle
            0x000004e0      .qword 0x0000000000000008
            0x000004e8      .qword 0x0000000000201008 ; obj.__dso_handle
            0x000004f0      .qword 0x0000000000200fd8 ; reloc._ITM_deregisterTMCloneTable
            0x000004f8      .qword 0x0000000100000006
            0x00000500      .qword 0x0000000000000000
            0x00000508      .qword 0x0000000000200fe0 ; reloc.__libc_start_main
            0x00000510      .qword 0x0000000300000006
            0x00000518      .byte 0x00
            0x00000520      .qword 0x0000000000200fe8 ; reloc.__gmon_start
            0x00000528      .qword 0x0000000500000006
            ; DATA XREF from section..rela.dyn @ +0x83
            0x00000530      .qword 0x0000000000000000
            0x00000538      .qword 0x0000000000200ff0 ; reloc._ITM_registerTMCloneTable
            0x00000540      .qword 0x0000000700000006
            0x00000548      .qword 0x0000000000000000
            0x00000550      .qword 0x0000000000200ff8 ; reloc.__cxa_finalize
            0x00000558      .qword 0x0000000800000006
            0x00000560      .qword 0x0000000000000000
            0x00000568      .qword 0x0000000000201010 ; section..bss ; reloc.stdout ; obj.stdout ; sym..bss ; obj.stdout__GLIBC_2.2.5 ; loc._edata ; loc.__bss_start ; obj.__TMC_END
            0x00000570      .qword 0x0000000900000005
            0x00000578      .qword 0x0000000000000000
            ;-- section..rela.plt:
            ;-- .rela.plt:
            0x00000580      .qword 0x0000000000200fc0 ; reloc.__stack_chk_fail ; [10] -r-- section size 72 named .rela.plt
            0x00000588      .qword 0x0000000200000007
            0x00000590      .qword 0x0000000000000000
            0x00000598      .qword 0x0000000000200fc8 ; reloc.fprintf
            0x000005a0      .qword 0x0000000400000007
            0x000005a8      .qword 0x0000000000000000
            0x000005b0      .qword 0x0000000000200fd0 ; reloc.fflush
            0x000005b8      .qword 0x0000000600000007
            0x000005c0      .qword 0x0000000000000000
            ; CALL XREF from sym.__libc_csu_init @ 0x80c
            ;-- section..init:
            ;-- .init:
┌ 23: sym._init ();
│           0x000005c8      4883ec08       sub rsp, 8                  ; [11] -r-x section size 23 named .init
│           0x000005cc      488b05150a20.  mov rax, qword [reloc.__gmon_start] ; [0x200fe8:8]=0
│           0x000005d3      4885c0         test rax, rax
│           0x000005d6      7402           je 0x5da
│           0x000005d8      ffd0           call rax
│           ; CODE XREF from sym._init @ 0x5d6
│           0x000005da      4883c408       add rsp, 8
└           0x000005de      c3             ret
            0x000005df  ~   00ff           add bh, bh
            ; CODE XREF from sym.imp.__stack_chk_fail @ +0xb
            ; CODE XREF from sym.imp.fprintf @ +0xb
            ; CODE XREF from sym.imp.fflush @ +0xb
            ;-- section..plt:
            ;-- .plt:
            0x000005e0      ff35ca092000   push qword [0x00200fb0]     ; [12] -r-x section size 64 named .plt
            0x000005e6      ff25cc092000   jmp qword [0x00200fb8]      ; [0x200fb8:8]=0
            0x000005ec      0f1f4000       nop dword [rax]
            ; CALL XREF from main @ 0x7d2
┌ 6: void sym.imp.__stack_chk_fail ();
└           0x000005f0      ff25ca092000   jmp qword [reloc.__stack_chk_fail] ; [0x200fc0:8]=0x5f6
            0x000005f6      6800000000     push 0
            0x000005fb      e9e0ffffff     jmp sym..plt
            ; CALL XREF from main @ 0x78b
┌ 6: int sym.imp.fprintf (FILE *stream, const char *format,   ...);
└           0x00000600      ff25c2092000   jmp qword [reloc.fprintf]   ; [0x200fc8:8]=0x606
            0x00000606      6801000000     push 1
            0x0000060b      e9d0ffffff     jmp sym..plt
            ; CALL XREF from main @ 0x79a
┌ 6: int sym.imp.fflush (FILE *stream);
└           0x00000610      ff25ba092000   jmp qword [reloc.fflush]    ; [0x200fd0:8]=0x616
            0x00000616      6802000000     push 2
            0x0000061b      e9c0ffffff     jmp sym..plt
            ; CALL XREF from entry.fini0 @ 0x70e
            ;-- section..plt.got:
            ;-- .plt.got:
            0x00000620      .qword 0x9066002009d225ff                  ; [13] -r-x section size 8 named .plt.got
            0x00000628      0000           add byte [rax], al
            0x0000062a      0000           add byte [rax], al
            0x0000062c      0000           add byte [rax], al
            0x0000062e      0000           add byte [rax], al
            ;-- section..text:
            ;-- .text:
            ;-- _start:
            ;-- rip:
┌ 42: entry0 (int64_t arg3);
│           ; arg int64_t arg3 @ rdx
│           0x00000630      31ed           xor ebp, ebp                ; [14] -r-x section size 546 named .text
│           0x00000632      4989d1         mov r9, rdx                 ; arg3
│           0x00000635      5e             pop rsi
│           0x00000636      4889e2         mov rdx, rsp
│           0x00000639      4883e4f0       and rsp, 0xfffffffffffffff0
│           0x0000063d      50             push rax
│           0x0000063e      54             push rsp
│           0x0000063f      4c8d050a0200.  lea r8, [sym.__libc_csu_fini] ; 0x850
│           0x00000646      488d0d930100.  lea rcx, [sym.__libc_csu_init] ; 0x7e0 ; "AWAVI\x89\xd7AUATL\x8d%\xb6\x05 "
│           0x0000064d      488d3de60000.  lea rdi, [main]             ; 0x73a
└           0x00000654      ff1586092000   call qword [reloc.__libc_start_main] ; [0x200fe0:8]=0
            0x0000065a      f4             hlt
            0x0000065b      0f1f440000     nop dword [rax + rax]
            ; CALL XREF from entry.fini0 @ 0x713
┌ 40: sym.deregister_tm_clones ();
│           0x00000660      488d3da90920.  lea rdi, obj.stdout         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x00000667      55             push rbp
│           0x00000668      488d05a10920.  lea rax, obj.stdout         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x0000066f      4839f8         cmp rax, rdi
│           0x00000672      4889e5         mov rbp, rsp
│           0x00000675      7419           je 0x690
│           0x00000677      488b055a0920.  mov rax, qword [reloc._ITM_deregisterTMCloneTable] ; [0x200fd8:8]=0
│           0x0000067e      4885c0         test rax, rax
│           0x00000681      740d           je 0x690
│           0x00000683      5d             pop rbp
│           0x00000684      ffe0           jmp rax
            0x00000686      662e0f1f8400.  nop word cs:[rax + rax]
│           ; CODE XREFS from sym.deregister_tm_clones @ 0x675, 0x681
│           0x00000690      5d             pop rbp
└           0x00000691      c3             ret
            0x00000692      0f1f4000       nop dword [rax]
            0x00000696      662e0f1f8400.  nop word cs:[rax + rax]
            ; CODE XREF from entry.init0 @ 0x735
┌ 57: sym.register_tm_clones ();
│           0x000006a0      488d3d690920.  lea rdi, obj.stdout         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x000006a7      488d35620920.  lea rsi, obj.stdout         ; obj.__TMC_END
│                                                                      ; 0x201010
│           0x000006ae      55             push rbp
│           0x000006af      4829fe         sub rsi, rdi
│           0x000006b2      4889e5         mov rbp, rsp
│           0x000006b5      48c1fe03       sar rsi, 3
│           0x000006b9      4889f0         mov rax, rsi
│           0x000006bc      48c1e83f       shr rax, 0x3f
│           0x000006c0      4801c6         add rsi, rax
│           0x000006c3      48d1fe         sar rsi, 1
│           0x000006c6      7418           je 0x6e0
│           0x000006c8      488b05210920.  mov rax, qword [reloc._ITM_registerTMCloneTable] ; [0x200ff0:8]=0
│           0x000006cf      4885c0         test rax, rax
│           0x000006d2      740c           je 0x6e0
│           0x000006d4      5d             pop rbp
│           0x000006d5      ffe0           jmp rax
            0x000006d7      660f1f840000.  nop word [rax + rax]
│           ; CODE XREFS from sym.register_tm_clones @ 0x6c6, 0x6d2
│           0x000006e0      5d             pop rbp
└           0x000006e1      c3             ret
            0x000006e2      0f1f4000       nop dword [rax]
            0x000006e6      662e0f1f8400.  nop word cs:[rax + rax]
            ;-- __do_global_dtors_aux:
┌ 51: entry.fini0 ();
│           0x000006f0      803d21092000.  cmp byte [obj.completed.7698], 0 ; [0x201018:1]=0
│           0x000006f7      752f           jne 0x728
│           0x000006f9      48833df70820.  cmp qword [reloc.__cxa_finalize], 0 ; [0x200ff8:8]=0
│           0x00000701      55             push rbp
│           0x00000702      4889e5         mov rbp, rsp
│           0x00000705      740c           je 0x713
│           0x00000707      488b3dfa0820.  mov rdi, qword [obj.__dso_handle] ; [0x201008:8]=0x201008 obj.__dso_handle
│           0x0000070e      e80dffffff     call sym..plt.got
│           ; CODE XREF from entry.fini0 @ 0x705
│           0x00000713      e848ffffff     call sym.deregister_tm_clones
│           0x00000718      c605f9082000.  mov byte [obj.completed.7698], 1 ; [0x201018:1]=0
│           0x0000071f      5d             pop rbp
│           0x00000720      c3             ret
            0x00000721      0f1f80000000.  nop dword [rax]
│           ; CODE XREF from entry.fini0 @ 0x6f7
└           0x00000728      f3c3           ret
            0x0000072a      660f1f440000   nop word [rax + rax]
            ;-- frame_dummy:
┌ 10: entry.init0 ();
│           0x00000730      55             push rbp
│           0x00000731      4889e5         mov rbp, rsp
│           0x00000734      5d             pop rbp
└           0x00000735      e966ffffff     jmp sym.register_tm_clones
            ; DATA XREF from entry0 @ 0x64d
┌ 159: int main (int argc, char **argv, char **envp);
│           ; var uint32_t var_14h @ rbp-0x14
│           ; var int64_t var_10h @ rbp-0x10
│           ; var char *format @ rbp-0xa
│           ; var int64_t canary @ rbp-0x8
│           0x0000073a      55             push rbp
│           0x0000073b      4889e5         mov rbp, rsp
│           0x0000073e      4883ec20       sub rsp, 0x20
│           0x00000742      64488b042528.  mov rax, qword fs:[0x28]
│           0x0000074b      488945f8       mov qword [canary], rax
│           0x0000074f      31c0           xor eax, eax
│           0x00000751      c745f0000000.  mov dword [var_10h], 0
│           0x00000758      c745ec000000.  mov dword [var_14h], 0
│           0x0000075f      eb57           jmp 0x7b8
│           ; CODE XREF from main @ 0x7be
│           0x00000761      8b45ec         mov eax, dword [var_14h]
│           0x00000764      4863d0         movsxd rdx, eax
│           0x00000767      488d05020100.  lea rax, obj.message        ; 0x870 ; "Hello, isolated world!\n"
│           0x0000076e      0fb60402       movzx eax, byte [rdx + rax]
│           0x00000772      8845f6         mov byte [format], al
│           0x00000775      488b05940820.  mov rax, qword [obj.stdout] ; obj.__TMC_END
│                                                                      ; [0x201010:8]=0
│           0x0000077c      488d55f6       lea rdx, [format]           ;   ...
│           0x00000780      4889d6         mov rsi, rdx                ; const char *format
│           0x00000783      4889c7         mov rdi, rax                ; FILE *stream
│           0x00000786      b800000000     mov eax, 0
│           0x0000078b      e870feffff     call sym.imp.fprintf        ; int fprintf(FILE *stream, const char *format,   ...)
│           0x00000790      488b05790820.  mov rax, qword [obj.stdout] ; obj.__TMC_END
│                                                                      ; [0x201010:8]=0
│           0x00000797      4889c7         mov rdi, rax                ; FILE *stream
│           0x0000079a      e871feffff     call sym.imp.fflush         ; int fflush(FILE *stream)
│           0x0000079f      837dec05       cmp dword [var_14h], 5
│           0x000007a3      750f           jne 0x7b4
│           0x000007a5      b800000000     mov eax, 0
│           0x000007aa      8b00           mov eax, dword [rax]
│           0x000007ac      8945f0         mov dword [var_10h], eax
│           0x000007af      8b45f0         mov eax, dword [var_10h]
│           0x000007b2      eb0f           jmp 0x7c3
│           ; CODE XREF from main @ 0x7a3
│           0x000007b4      8345ec01       add dword [var_14h], 1
│           ; CODE XREF from main @ 0x75f
│           0x000007b8      8b45ec         mov eax, dword [var_14h]
│           0x000007bb      83f817         cmp eax, 0x17
│           0x000007be      76a1           jbe 0x761
│           0x000007c0      8b45f0         mov eax, dword [var_10h]
│           ; CODE XREF from main @ 0x7b2
│           0x000007c3      488b4df8       mov rcx, qword [canary]
│           0x000007c7      6448330c2528.  xor rcx, qword fs:[0x28]
│           0x000007d0      7405           je 0x7d7
│           0x000007d2      e819feffff     call sym.imp.__stack_chk_fail ; void __stack_chk_fail(void)
│           ; CODE XREF from main @ 0x7d0
│           0x000007d7      c9             leave
└           0x000007d8      c3             ret
            0x000007d9      0f1f80000000.  nop dword [rax]
            ; DATA XREF from entry0 @ 0x646
┌ 101: sym.__libc_csu_init (int64_t arg1, int64_t arg2, int64_t arg3);
│           ; arg int64_t arg1 @ rdi
│           ; arg int64_t arg2 @ rsi
│           ; arg int64_t arg3 @ rdx
│           0x000007e0      4157           push r15
│           0x000007e2      4156           push r14
│           0x000007e4      4989d7         mov r15, rdx                ; arg3
│           0x000007e7      4155           push r13
│           0x000007e9      4154           push r12
│           0x000007eb      4c8d25b60520.  lea r12, obj.__frame_dummy_init_array_entry ; loc.__init_array_start
│                                                                      ; 0x200da8 ; "0\a"
│           0x000007f2      55             push rbp
│           0x000007f3      488d2db60520.  lea rbp, obj.__do_global_dtors_aux_fini_array_entry ; loc.__init_array_end
│                                                                      ; 0x200db0
│           0x000007fa      53             push rbx
│           0x000007fb      4189fd         mov r13d, edi               ; arg1
│           0x000007fe      4989f6         mov r14, rsi                ; arg2
│           0x00000801      4c29e5         sub rbp, r12
│           0x00000804      4883ec08       sub rsp, 8
│           0x00000808      48c1fd03       sar rbp, 3
│           0x0000080c      e8b7fdffff     call sym._init
│           0x00000811      4885ed         test rbp, rbp
│           0x00000814      7420           je 0x836
│           0x00000816      31db           xor ebx, ebx
│           0x00000818      0f1f84000000.  nop dword [rax + rax]
│           ; CODE XREF from sym.__libc_csu_init @ 0x834
│           0x00000820      4c89fa         mov rdx, r15
│           0x00000823      4c89f6         mov rsi, r14
│           0x00000826      4489ef         mov edi, r13d
│           0x00000829      41ff14dc       call qword [r12 + rbx*8]
│           0x0000082d      4883c301       add rbx, 1
│           0x00000831      4839dd         cmp rbp, rbx
│           0x00000834      75ea           jne 0x820
│           ; CODE XREF from sym.__libc_csu_init @ 0x814
│           0x00000836      4883c408       add rsp, 8
│           0x0000083a      5b             pop rbx
│           0x0000083b      5d             pop rbp
│           0x0000083c      415c           pop r12
│           0x0000083e      415d           pop r13
│           0x00000840      415e           pop r14
│           0x00000842      415f           pop r15
└           0x00000844      c3             ret
            0x00000845      90             nop
            0x00000846      662e0f1f8400.  nop word cs:[rax + rax]
            ; DATA XREF from entry0 @ 0x63f
┌ 2: sym.__libc_csu_fini ();
└           0x00000850      f3c3           ret
            0x00000852      0000           add byte [rax], al
            ;-- section..fini:
            ;-- .fini:
┌ 9: sym._fini ();
│           0x00000854      4883ec08       sub rsp, 8                  ; [15] -r-x section size 9 named .fini
│           0x00000858      4883c408       add rsp, 8
└           0x0000085c      c3             ret
            0x0000085d      0000           add byte [rax], al
            0x0000085f  ~   0001           add byte [rcx], al
            ;-- section..rodata:
            ;-- .rodata:
            ;-- _IO_stdin_used:
            0x00000860      0100           add dword [rax], eax        ; [16] -r-- section size 40 named .rodata
            0x00000862      0200           add al, byte [rax]
            0x00000864      0000           add byte [rax], al
            0x00000866      0000           add byte [rax], al
            0x00000868      0000           add byte [rax], al
            0x0000086a      0000           add byte [rax], al
            0x0000086c      0000           add byte [rax], al
            0x0000086e      0000           add byte [rax], al
            ; DATA XREF from main @ 0x767
            ;-- str.Hello__isolated_world:
            ;-- message:
            0x00000870     .string "Hello, isolated world!\n" ; len=24
            ;-- section..eh_frame_hdr:
            ;-- segment.GNU_EH_FRAME:
            ;-- .eh_frame_hdr:
            ;-- __GNU_EH_FRAME_HDR:
            0x00000888      011b           add dword [rbx], ebx        ; [17] -r-- section size 60 named .eh_frame_hdr
            0x0000088a      033b           add edi, dword [rbx]
            0x0000088c      3c00           cmp al, 0
            0x0000088e      0000           add byte [rax], al
            0x00000890      06             invalid
            0x00000891      0000           add byte [rax], al
            0x00000893      0058fd         add byte [rax - 3], bl
            0x00000896      ff             invalid
            0x00000897      ff8800000098   dec dword [rax - 0x68000000]
            0x0000089d      fd             std
            0x0000089e      ff             invalid
            0x0000089f      ffb0000000a8   push qword [rax - 0x58000000]
            0x000008a5      fd             std
            0x000008a6      ff             invalid
            0x000008a7      ff5800         lcall [rax]
            0x000008aa      0000           add byte [rax], al
            0x000008ac      b2fe           mov dl, 0xfe
            0x000008ae      ff             invalid
            0x000008af      ffc8           dec eax
            0x000008b1      0000           add byte [rax], al
            0x000008b3      0058ff         add byte [rax - 1], bl
            0x000008b6      ff             invalid
            0x000008b7      ff             invalid
            0x000008b8      e8000000c8     call 0xffffffffc80008bd
            0x000008bd      ff             invalid
            0x000008be      ff             invalid
            0x000008bf      ff30           push qword [rax]
            0x000008c1      0100           add dword [rax], eax
            0x000008c3      0000           add byte [rax], al
            0x000008c5      0000           add byte [rax], al
            0x000008c7  ~   001400         add byte [rax + rax], dl
            ;-- section..eh_frame:
            ;-- .eh_frame:
            0x000008c8      1400           adc al, 0                   ; [18] -r-- section size 264 named .eh_frame
            0x000008ca      0000           add byte [rax], al
            0x000008cc      0000           add byte [rax], al
            0x000008ce      0000           add byte [rax], al
            0x000008d0      017a52         add dword [rdx + 0x52], edi
            0x000008d3      0001           add byte [rcx], al
            0x000008d5      7810           js 0x8e7
            0x000008d7      011b           add dword [rbx], ebx
            0x000008d9      0c07           or al, 7
            0x000008db      089001071014   or byte [rax + 0x14100701], dl
            0x000008e1      0000           add byte [rax], al
            0x000008e3      001c00         add byte [rax + rax], bl
            0x000008e6      0000           add byte [rax], al
            0x000008e8      48fd           std
            0x000008ea      ff             invalid
            0x000008eb      ff2b           ljmp [rbx]
            0x000008ed      0000           add byte [rax], al
            0x000008ef      0000           add byte [rax], al
            0x000008f1      0000           add byte [rax], al
            0x000008f3      0000           add byte [rax], al
            0x000008f5      0000           add byte [rax], al
            0x000008f7      001400         add byte [rax + rax], dl
            0x000008fa      0000           add byte [rax], al
            0x000008fc      0000           add byte [rax], al
            0x000008fe      0000           add byte [rax], al
            0x00000900      017a52         add dword [rdx + 0x52], edi
            0x00000903      0001           add byte [rcx], al
            0x00000905      7810           js 0x917
            0x00000907      011b           add dword [rbx], ebx
            0x00000909      0c07           or al, 7
            0x0000090b      089001000024   or byte [rax + 0x24000001], dl
            0x00000911      0000           add byte [rax], al
            0x00000913      001c00         add byte [rax + rax], bl
            0x00000916      0000           add byte [rax], al
            0x00000918      c8fcffff       enter 0xfffffffffffffffc, 0xffffffffffffffff
            0x0000091c      400000         add byte [rax], al
            0x0000091f      00             invalid
            0x00000920      000e           add byte [rsi], cl
            0x00000922      10460e         adc byte [rsi + 0xe], al
            0x00000925      184a0f         sbb byte [rdx + 0xf], cl
            0x00000928      0b7708         or esi, dword [rdi + 8]
            0x0000092b      80003f         add byte [rax], 0x3f        ; [0x3f:1]=0
            0x0000092e      1a3b           sbb bh, byte [rbx]
            0x00000930      2a33           sub dh, byte [rbx]
            0x00000932      2422           and al, 0x22
            0x00000934      0000           add byte [rax], al
            0x00000936      0000           add byte [rax], al
            0x00000938      1400           adc al, 0
            0x0000093a      0000           add byte [rax], al
            0x0000093c      440000         add byte [rax], r8b
            0x0000093f      00e0           add al, ah
            0x00000941      fc             cld
            0x00000942      ff             invalid
            0x00000943      ff08           dec dword [rax]
            0x00000945      0000           add byte [rax], al
            0x00000947      0000           add byte [rax], al
            0x00000949      0000           add byte [rax], al
            0x0000094b      0000           add byte [rax], al
            0x0000094d      0000           add byte [rax], al
            0x0000094f      001c00         add byte [rax + rax], bl
            0x00000952      0000           add byte [rax], al
            0x00000954      5c             pop rsp
            0x00000955      0000           add byte [rax], al
            0x00000957      00e2           add dl, ah
            0x00000959      fd             std
            0x0000095a      ff             invalid
            0x0000095b      ff9f00000000   lcall [rdi]
            0x00000961      41             invalid
            0x00000962      0e             invalid
            0x00000963      108602430d06   adc byte [rsi + 0x60d4302], al
            0x00000969      029a0c070800   add bl, byte [rdx + 0x8070c]
            0x0000096f      00440000       add byte [rax + rax], al
            0x00000973      007c0000       add byte [rax + rax], bh
            0x00000977      0068fe         add byte [rax - 2], ch
            0x0000097a      ff             invalid
            0x0000097b      ff6500         jmp qword [rbp]
            0x0000097e      0000           add byte [rax], al
            0x00000980      00420e         add byte [rdx + 0xe], al
            0x00000983      108f02420e18   adc byte [rdi + 0x180e4202], cl
            0x00000989      8e03           mov es, word [rbx]
            0x0000098b      45             invalid
            0x0000098c      0e             invalid
            0x0000098d      208d04420e28   and byte [rbp + 0x280e4204], cl
            0x00000993      8c05480e3086   mov word [0xffffffff863017e1], es
            0x00000999      06             invalid
            0x0000099a      48             invalid
            0x0000099b      0e             invalid
            0x0000099c      3883074d0e40   cmp byte [rbx + 0x400e4d07], al
            0x000009a2      720e           jb 0x9b2
            0x000009a4      38410e         cmp byte [rcx + 0xe], al
            0x000009a7      30410e         xor byte [rcx + 0xe], al
            0x000009aa      28420e         sub byte [rdx + 0xe], al
            0x000009ad      20420e         and byte [rdx + 0xe], al
            0x000009b0      18420e         sbb byte [rdx + 0xe], al
            0x000009b3      10420e         adc byte [rdx + 0xe], al
            0x000009b6      0800           or byte [rax], al
            0x000009b8      1000           adc byte [rax], al
            0x000009ba      0000           add byte [rax], al
            0x000009bc      c4             invalid
            0x000009bd      0000           add byte [rax], al
            0x000009bf      0090feffff02   add byte [rax + 0x2fffffe], dl
            0x000009c5      0000           add byte [rax], al
            0x000009c7      0000           add byte [rax], al
            0x000009c9      0000           add byte [rax], al
            0x000009cb  ~   0000           add byte [rax], al
            ;-- __FRAME_END__:
            0x000009cc      0000           add byte [rax], al
            0x000009ce      0000           add byte [rax], al
            0x000009d0      ff             invalid
            0x000009d1      ff             invalid
            0x000009d2      ff             invalid
            0x000009d3      ff             invalid
            0x000009d4      ff             invalid
            0x000009d5      ff             invalid
            0x000009d6      ff             invalid
            0x000009d7      ff             invalid
            0x000009d8      ff             invalid
            0x000009d9      ff             invalid
            0x000009da      ff             invalid
            0x000009db      ff             invalid
            0x000009dc      ff             invalid
            0x000009dd      ff             invalid
            0x000009de      ff             invalid
            0x000009df      ff             invalid
            0x000009e0      ff             invalid
            0x000009e1      ff             invalid
            0x000009e2      ff             invalid
            0x000009e3      ff             invalid
            0x000009e4      ff             invalid
            0x000009e5      ff             invalid
            0x000009e6      ff             invalid
            0x000009e7      ff             invalid
            0x000009e8      ff             invalid
            0x000009e9      ff             invalid
            0x000009ea      ff             invalid
            0x000009eb      ff             invalid
            0x000009ec      ff             invalid
            0x000009ed      ff             invalid
            0x000009ee      ff             invalid
            0x000009ef      ff             invalid
            0x000009f0      ff             invalid
            0x000009f1      ff             invalid
            0x000009f2      ff             invalid
            0x000009f3      ff             invalid
            0x000009f4      ff             invalid
            0x000009f5      ff             invalid
            0x000009f6      ff             invalid
            0x000009f7      ff             invalid
            0x000009f8      ff             invalid
            0x000009f9      ff             invalid
            0x000009fa      ff             invalid
            0x000009fb      ff             invalid
            0x000009fc      ff             invalid
            0x000009fd      ff             invalid
            0x000009fe      ff             invalid
            0x000009ff      ff             invalid
            0x00000a00      ff             invalid
            0x00000a01      ff             invalid
            0x00000a02      ff             invalid
            0x00000a03      ff             invalid
            0x00000a04      ff             invalid
            0x00000a05      ff             invalid
            0x00000a06      ff             invalid
            0x00000a07      ff             invalid
            0x00000a08      ff             invalid
            0x00000a09      ff             invalid
            0x00000a0a      ff             invalid
            0x00000a0b      ff             invalid
            0x00000a0c      ff             invalid
            0x00000a0d      ff             invalid
            0x00000a0e      ff             invalid
            0x00000a0f      ff             invalid
            0x00000a10      ff             invalid
            0x00000a11      ff             invalid
            0x00000a12      ff             invalid
            0x00000a13      ff             invalid
            0x00000a14      ff             invalid
            0x00000a15      ff             invalid
            0x00000a16      ff             invalid
            0x00000a17      ff             invalid
            0x00000a18      ff             invalid
            0x00000a19      ff             invalid
            0x00000a1a      ff             invalid
            0x00000a1b      ff             invalid
            0x00000a1c      ff             invalid
            0x00000a1d      ff             invalid
            0x00000a1e      ff             invalid
            0x00000a1f      ff             invalid
            0x00000a20      ff             invalid
            0x00000a21      ff             invalid
            0x00000a22      ff             invalid
            0x00000a23      ff             invalid
            0x00000a24      ff             invalid
            0x00000a25      ff             invalid
            0x00000a26      ff             invalid
            0x00000a27      ff             invalid
            0x00000a28      ff             invalid
            0x00000a29      ff             invalid
            0x00000a2a      ff             invalid
            0x00000a2b      ff             invalid
            0x00000a2c      ff             invalid
            0x00000a2d      ff             invalid
            0x00000a2e      ff             invalid
            0x00000a2f      ff             invalid
            0x00000a30      ff             invalid
            0x00000a31      ff             invalid
            0x00000a32      ff             invalid
            0x00000a33      ff             invalid
            0x00000a34      ff             invalid
