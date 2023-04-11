#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_for_elf(unsigned char *id);
void print_magic_number(unsigned char *id);
void print_class_elf(unsigned char *id);
void print_elf_data(unsigned char *id);
void print_elf_version(unsigned char *id);
void print_abi(unsigned char *id);
void print_os_abi(unsigned char *id);
void print_elf_type(unsigned int e_type, unsigned char *id);
void print_entry(unsigned long int e_entry, unsigned char *id);
void close_elf(int elf);

/**
 * check_for_elf - Checks for ELF file.
 * @id: Array containing the ELF magic numbers.
 */
void check_for_elf(unsigned char *id)
{
	int index;

	for (index = 0; index < 4; index++){
		if (id[index] != 127 &&
		    id[index] != 'E' &&
		    id[index] != 'L' &&
		    id[index] != 'F'){
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic_number - Prints  magic numbers of ELF header.
 * @id: Array containing the ELF magic numbers.
 */
void print_magic_number(unsigned char *id)
{
	int index;

	printf("  Magic: ");
	for (index = 0; index < EI_NIDENT; index++){
		printf("%02x", id[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class_elf - Prints class of an ELF header.
 * @id: Array containing the ELF class.
 */
void print_class_elf(unsigned char *id)
{
	printf("  Class:                             ");
	switch (id[EI_CLASS]){
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", id[EI_CLASS]);
	}
}

/**
 * print_elf_data - Data of an ELF header.
 * @id: Array containing the ELF class.
 */
void print_elf_data(unsigned char *id)
{
	printf("  Data:    ");
	switch (id[EI_DATA]){
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's Complement, Little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's Complement, Big endian\n");
		break;
	default:
		printf("<Unknown: %x>\n", id[EI_CLASS]);
	}
}

/**
 * print_elf_version - Version of an ELF
 * @id: Array containing the ELF version
 */
void print_elf_version(unsigned char *id)
{
	printf("  Version:                           %d",
	       id[EI_VERSION]);

	switch (id[EI_VERSION]){
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_os_abi - Prints the OS/ABI of an ELF header.
 * @id: Array containing the ELF version.
 */
void print_os_abi(unsigned char *id)
{
	printf("  OS/ABI:                            ");

	switch (id[EI_OSABI]){
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", id[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @id: Array containing the ELF ABI version.
 */
void print_abi(unsigned char *id)
{
	printf("  ABI Version: %d\n",
	       id[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @id: Array containing the ELF class.
 */
void print_elf_type(unsigned int e_type, unsigned char *id)
{
	if (id[EI_DATA] == ELFDATA2MSB){
        e_type >>= 8;
    }
	printf("  Type:                              ");
	switch (e_type){
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @id: Array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *id)
{
	printf("  Entry address: ");
	if (id[EI_DATA] == ELFDATA2MSB){
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF
 * @elf: Descriptor of the ELF
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: Arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1){
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL){
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1){
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_for_elf(header->id);
	printf("ELF Header:\n");
	print_magic_number(header->id);
	print_class_elf(header->id);
	print_elf_data(header->id);
	print_elf_version(header->id);
	print_os_abi(header->id);
	print_abi(header->id);
	print_elf_type(header->e_type, header->id);
	print_entry(header->e_entry, header->id);

	free(header);
	close_elf(o);
	return (0);
}
