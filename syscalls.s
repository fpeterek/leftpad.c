.global fpmmap
.global fpmunmap


.text

# void* fpmmap(size_t size)
fpmmap:
    movq  $9,    %rax   # mmap syscall
    movq  %rdi,  %rsi   # Size - move rdi to rsi before we overwrite rdi        # ARG 1
    xor   %rdi,  %rdi   # NULL address                                          # ARG 0
    movq  $3,    %rdx   # Protection -- read/write                              # ARG 2
    movq  $0x22, %r10   # flags -- private mapping, anonymous (no file - 0x22)  # ARG 3
    movq  $-1,   %r8    # File descriptor -- ignored, but better to set to -1   # ARG 4
    xor   %r9,   %r9    # pgoffset -- should be zero for anonymous mapping      # ARG 5
    syscall             # Perform syscall
    ret

# void fpmunmap(void* addr, size_t size);
#               ^ rdi      ^ rsi
# Arguments should already be in correct registers due to x86 calling conventions
fpmunmap:
    movq  $11,  %rax    # munmap syscall
    syscall             # Perform syscall
    ret
