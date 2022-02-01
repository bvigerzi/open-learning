# Lecture 4 - Bounded Buffers + Locks

## Recap and Introducing Bounded Buffer

- Operating systems enforce modularity using virtualisation
1. Programs should not refer to each other's memory -> virtual memory
2. Programs should be able to communicate -> **bounded buffers** (virtualise communication links)
3. Programs should share a CPU without a program halting anothers -> assume on program per CPU (for now)

Goal: implement bounded buffers so program's can communicate

## Bounded Buffer

- Buffer that stores up to N messages
- When sending information, the buffer will check to see if it has reached capacity (N)
  - If it has not, then more info will be placed into the buffer
- When receiving informatino, the buffer will be read completely until empty
- API:
  - send(m)
  - m <- receive()

## Locks

- Allow only on CPU to be inside a piece of code at a time
- API:
  - acquire(l)
  - release(l)
- Implementing lock:
- 
```
acquire(lock):
    while lock != 0:
        do nothing
    lock = 1

release(lock):
    lock = 0
```

- This is a problem as it is a race condition (need a lock to implement a lock)
- Solution:

```
acquire(lock):
    do:
        r <- 1
        XCHG r,lock
    while r == 1
```

- Sets 1 into `lock` variable with an atomic operation (`XCHG` operand)

## Summary

- Bounded bufers allow programs to communicate
  - Enforces modularity of programs on a single machien
  - Tricky to implement due to concurrency
  - Need an appropriate locking mechanism that prevents deadlocks and other locking problems
- Locks allow the implementation of atomic actions
  - Determining correct locking discipline is tough due to;
    - race conditions
    - deadlocks
    - performance issues (locking too much to solve the race condition or deadlock which reduces performance) 

## Lecture 5 - Threads

## Recap and Introducing Threads

- Operating systems enforce modularity on single machine using virtualisation
1. Prorgams should not refer to each others' memory -> virtual memory
2. Programs should be able to communicate -> bounded buffers
3. Programs should share a CPU without halting another's progress -> threads (virtualise processors)

Goal: Use threads to allow multiple programs to share a CPU

- Thread: virtual processor
- API:
  - suspend(): save state of current thread to memory
  - resume(): restore state from memory

... page 4