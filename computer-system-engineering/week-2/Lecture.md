# Lecture 2 - Naming in Systems

## Naming

- Allows modules to interact
- Examples:
  - hostname
  - email
  - username

## Naming Schemes

- Given set of all possible names and map to values
- Look-up algorithm that translates a name into a value (i.e. how the map is traversed)

## DNS

- Given a hostname the DNS will translate (resolve) the hostname into an IP address
- System uses a tree hierarchy where the TLD is the root of the tree (e.g. com) and then it is traversed through
- Query hits the root table, which then looks up com, followed by the next subdomain

# Lecture 3 - OS

- Operating systems enforce modularity on a single machine
- Few rules in an OS to enforce modularity:
  - Programs should not be able to refer to each other's memory
  - Programs should be able to communicate
  - Programs should be able to share a CPU without a single program halting progress of others
- Enforced through **virtualisation**
  - Virtual memory
  - Virtual communication links
  - Virtual processors

## Memory

- Memory is virtualised using a Memory Management Unit (MMU) which translates a virtual address space into the physical memory address of the computer's memory

### Storing Mapping

- Naive method: store every mapping: virtual address acts as index in table
  - Problem: for each address we need to store another address
  - Solution: Use page table where the bottom 12 bits are shared between the MMU and main memory
    - The top 20 bits maps as an index into the page table where the top 20 bits of the physical address are stored

## Page Table Entries

- A page table entry is 32-bits; 20-bit physical page number and 12 bits of additional information
  - Therefore, if a page is 2^12 bits of memory then the total amount of pages is 2^20
    - At 32 bits per entry that is 2^20 * 32 bits ~= 4MB to store the page table
    - Solution is to page the page table
- Present (P) bit: is the page currently in DRAM?
- read/write (R/W) bit: is the program allowed to write to this address?
- user/supervisor (U/S) bit: does the program have access to this address? (this manages virtualisation and protection from corruption)
- The **kernel** manages **page faults** and other **interrupts**

## Summary

- Operating systems enforce modularity on single machine using virtualisation and abstraction
- Virtualising memory ensures programs cannot refer to each other's memory
- MMU translates a virtual memory address to a physical address through page tables
- OS presents abstractions for devices via system calls (implemented as interrupts)
- Kernel directly accesses device via interrupt -- user does not interact directly