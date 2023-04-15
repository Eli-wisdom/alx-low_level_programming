#include <stdio.h>
#include <elf.h>

int main(int argc, char **argv)
{
    Elf64_Ehdr header; // for 64-bit ELF files
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // read the ELF header from the file
    fread(&header, sizeof(header), 1, fp);

    // print the information contained in the ELF header
    printf("ELF header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %d-bit\n", header.e_ident[EI_CLASS]*32);
    printf("  Data:                              %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "little endian" : "big endian");
    printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header.e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %d\n", header.e_type);
    printf("  Machine:                           %d\n", header.e_machine);
    printf("  Version:                           %d\n", header.e_version);
    printf("  Entry point address:               0x%lx\n", header.e_entry);
    printf("  Start of program headers:          %lu (bytes into file)\n", header.e_phoff);
    printf("  Start of section headers:          %lu (bytes into file)\n", header.e_shoff);
    printf("  Flags:                             0x%x\n", header.e_flags);
    printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);
    printf("  Size of program headers:           %d (bytes)\n", header.e_phentsize);
    printf("  Number of program headers:         %d\n", header.e_phnum);
    printf("  Size of section headers:           %d (bytes)\n", header.e_shentsize);
    printf("  Number of section headers:         %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);

    fclose(fp);

    return 0;
}

