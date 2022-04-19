# Lecture 12 - In-network resource management, queue management, traffic differentiation

## Recap

- Routing in a scalable way while dealing with policy and economy -> BGP
- Transporting data in a scalable way while dealing with differing application demands -> TCP (in-network resource management)
- How do we adapt new apps/technologies to inflexible architecture?

Problem: TCP deals with drops but packets aren't dropped until the queue is full

### Queue Management

- When should we drop packets from the queue?
- Methods;
  - Droptail: drop packets once queue is full -- leads to delays and flows synchronise
  - RED: drop packets before queue is full -- probability of dropping increases as queue size grows
    - Prevents queue lengths from oscillating, decreases delay, flows don't synchronise

#### RED

- Two options: drop the packet (RED) or mark the packet (ECN) for dropping
- Can be complex and difficult to pick parameters (e.g. minimum and maximum queue size and scale of dropping relative to queue size)

- Another challenge is being sensitive towards certain types of traffic -- e.g. we may want to prioritise traffic that is latency-sensitive

#### Delay-based Scheduling

- Priority queueing
  - Latency-sensitive traffic should go in its own queue and that queue should be served first
  - Can be extended to support multiple traffic types and associated queues
  - It should not prevent the other queues (non latency-sensitive traffic) from being processed -- bandwidth-based scheduling could solve this problem to ensure both queues are being serviced

#### Bandwidth-based Scheduling

- Allocating network bandwidth to certain traffic types
- Types:
  - Round-robin: cannot handle varaible packet sizes -- does not allow for weighting of traffic
  - Weighted round-robin: allows for variable sizes and different weights but must know the mean packet size of the queue
  - Deficit round-robin: Does not require the mean packet size of the queue; near perfect fairness and low packet processing overhead

## Summary

- Queue management
  - Switches signal congestion before queue is full
  - Droptail (drop when queue is full)
  - RED (drop before full)
  - ECN (mark before full)
- Delay-based scheduling
  - Prioritise latency-sensitive traffic
  - Priority queue
- Bandwidth-based scheduling
  - Enforce (weighted) fairness among traffic types
  - Round-robin
  - Weighted round-robin
  - Deficit round-robin

- Queue management systems such as RED or ECN drop/mark packets in an attempt to have TCP senders react earlier to congestion -- difficult to get to work at large Internet scale, but ideas can be useful
- Traffic differentiation requires scheduling discipline (weighted/deficit round-robin) -- goal is to give weighted fairness when faced with variable packet sizes and ensuring low processing overhead
- Both are in-network resource management

# Lecture 13 - New technologies on the internet

## Recap
