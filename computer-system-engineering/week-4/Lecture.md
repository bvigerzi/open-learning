# Lecture 6 - Kernels and VMs

## Recap

- Operating systems enforce modularity on single machine via virtualisation
- In order to enforce this modularity, the operating system must;

1. Programs should not refer to each other's memory -> virtual memory
2. Programs should be able to communicate -> bounded buffers (virtualise communication links)
3. Programs should be able to share a CPU without a program halting another -> threads (virtualise processors)

- Running multiple OSes at once

- Virtual machine: running an operating system on-top of another
- Problem: how to safely share access to the physical hardware
- Virtual machine monitor (VMM) runs in kernel-mode on hardware
- The VMM virtualise the hardware so it appears to the VM OS that it has physical hardware, without it being able to impact the other VM running
- The guest virtual address translates into a guest physical address (i.e. the virtualised hardware) which translates into the host physical address (where it actually lies in the physical hardware)
- E.g.
  - If the guest OS needs to access the page table, it will access it on the "virtual hardware" which is interpeted by the VMM and translated into a location on the physical hardware

- Monolithic kernels: no enforced modularity in kernel
  - All kernel functions bundled into single piece of software
- Microkernels: enforce modularity by breaking kernel functions into subsystems in user programs
  - e.g. application IPC, device driver, networking, etc

## Summary

- Virtual machines allow to run multiple isolated OS on single physical machine
- Monolithic kernels do not provide any modularity within the kernel
- Microkernels provide modularity using subsystems but converting a monolithic to micro is challenging

# Lecture 7 - Performance Problems