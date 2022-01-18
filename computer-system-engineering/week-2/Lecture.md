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

... page 11