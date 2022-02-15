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

## Recap

- Operating systems enforce modularity on single machine using virtualisation

1. Programs should not be able to refer to other's memory -> virtual memory
2. Programs should be able to communicate -> bounded buffers (virtual communication links)
3. Programs should be able to share a CPU without halting another programs process -> threads (virtual processors)

- Virtual machines enforce modularity between OSes running on same physical hardware

- How do we ensure that a system not only works but works well?
- Tackling performance;

1. Measure system to find bottleneck
2. Relax bottleneck

- Few users
  - Low latency
  - Low throughput (few users = few requests)
- Moderate users
  - Low latency (new users consume previously idle resources)
  - High throughput (more users = more requests)
- Many users
  - High latency (requests queue up)
  - Throughput plateaus (cannot serve requests any faster -- hit limit)

- Again,

1. Measure the system, compare it to our system model to find bottleneck
2. Relax the bottleneck

- HDD is made up of platters where each platter has many tracks and inside each track has many sectors
- SDD is made up of many blocks where each block has many pages and inside each page has many cells

- Again,

1. Measure the system to find the bottleneck
2. Relax the bottleneck
   1. Batch requests
   2. Cache data
   3. Exploit concurrency
   4. Exploit parallelism

- How to approach performance problems;
  - Measuring and modeling the system to find the bottleneck and then relaxing the bottleneck
- Techniques to improve performance
  - Four common techniques; batching, caching, concurrency and parallelism
  - All these techniques require understanding of how underlying system works and how it is used
